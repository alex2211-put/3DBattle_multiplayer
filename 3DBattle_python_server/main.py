import asyncio
import json
from time import time
import copy
from funcs import *

'''
4) Написать восстановление сервера при его неожиданном падении (файл, где хранятся действующие игры).
5) Написать историю игр (*)
'''


def run_server(host, port):
    loop = asyncio.get_event_loop()

    coro = loop.create_server(
        ClientServerProtocol,
        host, port
    )
    server = loop.run_until_complete(coro)
    try:
        loop.run_forever()
    except KeyboardInterrupt:
        pass


class ClientServerProtocol(asyncio.Protocol):
    everything = {}
    # 1 число - транспорт
    # 2 число - статус (ready, started, end)
    # 3 число - положение карты
    # 4 число - размер карты
    # 5 число - номер пары(0) и полож. в ней(1)
    # 6 число - число оставшихся кораблей
    # 7 число - комплект бота
    pairs = []
    new_pair_num = [0]
    where = [-2, -2, -2]
    pairs_bots = []
    time = time()

    def connection_made(self, transport):
        '''
        if not self.everything:
            with open('.all_data.json', 'r') as f:
                if not f:
                    self.everything = json.load(f)
                    '''
        self.transport = transport
        answer = str(transport.__hash__()) + '\n'  # записываем хэш пришедшего подключения
        self.everything[str(transport.__hash__())] = [transport]  # создаем ключ с таким хэшом и кидаем связь
        self.transport.write(answer.encode())  # отпраляем хэш обратно

    def data_received(self, data):
        data = (data.decode('utf-8')).split()
        if data[0] in self.everything:
            if data[1] == 'ready':
                ready_func(data, self.everything, self.pairs)

            elif data[1] == 'fire':  # клиент стреляет по противнику
                fire_func(data, self.everything, self.pairs, self.where)

            elif data[1] == '?':  # стучимся в сервер в ожидании начала стрельбы (когда игра идет)
                waiting_func(data, self.everything, self.where, self.pairs)

            elif data[1] == "x" or data[1] == 'kill_sec':  # клиент
                # ждет координат своего подбитого корабля
                self.everything[data[0]][0].write(
                    (str(self.where[0]) + ' ' + str(self.where[1]) + ' ' + str(self.where[2])).encode())
                self.everything[data[0]][1] = 'wait'

            elif data[1] == 'after_kill':
                LengthBigCube = int(data[len(data) - 1])
                count_map = 2
                battle_map = [[[0 for _ in range(LengthBigCube)] for _ in range(LengthBigCube)] for _ in
                              range(LengthBigCube)]
                for i in range(LengthBigCube):
                    for j in range(LengthBigCube):
                        for k in range(LengthBigCube):
                            battle_map[i][j][k] = data[count_map]
                            count_map += 1
                self.everything[data[0]][2] = battle_map

            elif data[1] == 'hurt':  # клиент ждет
                # координат своего промазанного поля (какой закрасить синим)
                self.everything[data[0]][0].write(
                    (str(self.where[0]) + ' ' + str(self.where[1]) + ' ' + str(self.where[2])).encode())

            elif data[1] == 'when':  # клиент в ожидании начала боя
                if self.everything[data[0]][1] == 'fire_st':
                    self.everything[data[0]][0].write("started\n".encode())
                    self.everything[data[0]][0].write(str(1).encode())
                elif self.everything[data[0]][1] == 'wait':
                    self.everything[data[0]][0].write("started\n".encode())
                    self.everything[data[0]][0].write(str(0).encode())
                else:
                    self.everything[data[0]][0].write("no\n".encode())

            elif data[1] == 'back':
                back_func(data, self.everything, self.pairs)

            elif data[1] == 'end':  # окончание игры клиентом
                try:
                    hash_with_who = self.pairs[self.everything[data[0]][4][0]][1 - self.everything[data[0]][4][1]]
                    self.everything[hash_with_who][1] = 'win'
                except:
                    pass

        else:
            print(data)
            print('Такого ключа нет в словаре!!!')

    '''if time() - self.time > 10:
                self.time = time()
                with open('.all_data.json', 'w') as f:
                    new_everything = copy.deepcopy(self.everything.copy())
                    print(new_everything)
                    for keys in new_everything:
                        new_everything[keys][0] = 0
                    print(new_everything)
                    print(self.everything)
                    json.dump(new_everything, f)'''

if __name__ == '__main__':
    run_server('127.0.0.1', 5000)
