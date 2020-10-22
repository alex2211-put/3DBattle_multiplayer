import asyncio
from random import randint
# написать постановление троек при убийстве кораблей. На сервер
'''
3) Написать повторное подключение игрока к серверу по причине локального вылета из игры.
4) Написать восстановление сервера при его неожиданном падении (файл, где хранятся действующие игры).
5) Написать историю игр (*)
6) Запретить стрельбу повторную по тем же кубикам
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
    pairs = []
    new_pair_num = [0]
    where = [-1, -1, -1]

    def connection_made(self, transport):
        self.transport = transport
        answer = str(transport.__hash__()) + '\n'  # записываем хэш пришедшего подключения
        self.everything[str(transport.__hash__())] = [transport]  # создаем ключ с таким хэшом и кидаем связь
        self.transport.write(answer.encode())  # отпраляем хэш обратно

    def data_received(self, data):
        data = (data.decode('utf-8')).split()
        if data[0] in self.everything:
            if data[1] == 'ready':
                self.ready_func(data)

            elif data[1] == 'fire':  # клиент стреляет по противнику
                self.fire_func(data)

            elif data[1] == '?':  # стучимся в сервер в ожидании начала стрельбы (когда игра идет)
                self.waiting_func(data)

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
                if data[2] in self.everything:
                    print('back')
                    self.everything[data[2]][0] = self.everything[data[0]][0]
                    del self.everything[data[0]]
                    if len(self.everything[data[2]]) > 1:
                        map = ''
                        for i in range(self.everything[data[2]][3]):
                            for j in range(self.everything[data[2]][3]):
                                for k in range(self.everything[data[2]][3]):
                                    map += str(self.everything[data[2]][2][i][j][k])
                        if self.everything[data[2]][1] == 'ready':   # если он ожидал противника
                            self.everything[data[2]][0].write('ready\n'.encode())
                            self.everything[data[2]][0].write(map.encode())
                        elif self.everything[data[2]][1] == 'wait':
                            hash_with_who = self.pairs[self.everything[data[2]][4][0]][
                                1 - self.everything[data[2]][4][1]]
                            self.everything[data[2]][0].write('wait\n'.encode())
                            self.everything[data[2]][0].write(map.encode())
                            map2 = ''
                            for i in range(self.everything[hash_with_who][3]):
                                for j in range(self.everything[hash_with_who][3]):
                                    for k in range(self.everything[hash_with_who][3]):
                                        if self.everything[hash_with_who][2][i][j][k] == 1:
                                            map2 += str(2)
                                        else:
                                            map2 += str(self.everything[hash_with_who][2][i][j][k])
                            self.everything[data[2]][0].write(map2.encode())
                        elif self.everything[data[2]][1] == 'shoots' or self.everything[data[2]][1] == 'fire_st':
                            hash_with_who = self.pairs[self.everything[data[2]][4][0]][
                                1 - self.everything[data[2]][4][1]]
                            self.everything[data[2]][0].write('fire\n'.encode())
                            self.everything[data[2]][0].write(map.encode())
                            map2 = ''
                            for i in range(self.everything[hash_with_who][3]):
                                for j in range(self.everything[hash_with_who][3]):
                                    for k in range(self.everything[hash_with_who][3]):
                                        if self.everything[hash_with_who][2][i][j][k] == 1:
                                            map2 += str(2)
                                        else:
                                            map2 += str(self.everything[hash_with_who][2][i][j][k])
                            self.everything[data[2]][0].write(map2.encode())
                    else:
                        print('not_ready')
                        self.everything[data[2]][0].write('not_ready\n'.encode())

            elif data[1] == 'end':  # окончание игры клиентом
                try:
                    hash_with_who = self.pairs[self.everything[data[0]][4][0]][1 - self.everything[data[0]][4][1]]
                    self.everything[hash_with_who][1] = 'win'
                except:
                    pass

        else:
            print(data)
            print('Такого ключа нет в словаре!!!')

    def ready_func(self, data):
        to_pair = False  # смотрим, дополнилось ли к паре
        empty = False  # смотрим на наличие просто пустых мест
        count = -1  # номер пары
        self.everything[data[0]].append(data[1])  # ready в словарь
        # сделан трехмерный массив для карты...
        LengthBigCube = int(data[len(data) - 1])
        count_map = 2
        battle_map = [[[0 for _ in range(LengthBigCube)] for _ in range(LengthBigCube)] for _ in range(LengthBigCube)]
        for i in range(LengthBigCube):
            for j in range(LengthBigCube):
                for k in range(LengthBigCube):
                    battle_map[i][j][k] = data[count_map]
                    count_map += 1
        self.everything[data[0]].append(battle_map)  # карта в словарь

        self.everything[data[0]].append(LengthBigCube)  # размер поля в словарь

        for i in self.pairs:
            count += 1
            if len(i) == 0:
                i.append(data[0])
                self.everything[data[0]].append((count, 0))
                self.everything[data[0]][1] = 'ready'
                empty = True
            elif not len(i) == 2:
                if self.everything[i[0]][3] == LengthBigCube:  # сверяем размер карты
                    i.append(data[0])
                    to_pair = True
                    self.everything[data[0]].append((count, 1))  # добавляем в словарь тапл с парой
                    who = randint(0, 1)
                    self.everything[data[0]][0].write(str(who).encode())  # отправляем ходит он первый или нет
                    if who == 1:
                        self.everything[data[0]][1] = 'fire_st'  # ставим статус что он стреляет
                        self.everything[i[0]][1] = 'wait'  # ставим статус что он ждет
                    else:
                        self.everything[data[0]][1] = 'wait'
                        self.everything[i[0]][1] = 'fire_st'
                    self.everything[i[0]][0].write(str(1 - who).encode())  # отпраляем ходит он первый или нет

        if not to_pair and not empty:
            self.pairs.append([data[0]])
            self.everything[data[0]].append((len(self.pairs) - 1, 0))
            self.everything[data[0]][1] = 'ready'
        ships = (1 + LengthBigCube - 2) * (
                LengthBigCube - 2) / 2  # подсчитаем арифметической прогрессией число кораблей
        self.everything[data[0]].append(ships)  # число кораблей в словарь
        self.everything[data[0]][0].write('ok'.encode())

    def fire_func(self, data):
        self.where[0] = int(data[2])
        self.where[1] = int(data[3])
        self.where[2] = int(data[4])
        LengthBigCube = self.everything[data[0]][3]
        hash_with_who = self.pairs[self.everything[data[0]][4][0]][1 - self.everything[data[0]][4][1]]
        if int(self.everything[hash_with_who][2][self.where[0]][self.where[1]][self.where[2]]) == 1:  # если попали
            self.everything[hash_with_who][2][self.where[0]][self.where[1]][self.where[2]] = 4
            self.everything[hash_with_who][1] = 'hurt'  # меняем статус на "попали"

            hit = True  # проверяем, жив корабль или убит
            where_ = [int(data[2]), int(data[3]), int(data[4])]
            while where_[0] - 1 >= 0 and \
                    int(self.everything[hash_with_who][2][where_[0]][where_[1]][where_[2]]) == 4:
                if int(self.everything[hash_with_who][2][where_[0] - 1][where_[1]][where_[2]]) == 1:
                    hit = False
                where_[0] -= 1
            where_ = [int(data[2]), int(data[3]), int(data[4])]
            while where_[0] + 1 < LengthBigCube and \
                    int(self.everything[hash_with_who][2][where_[0]][where_[1]][where_[2]]) == 4:
                if int(self.everything[hash_with_who][2][where_[0] + 1][where_[1]][where_[2]]) == 1:
                    hit = False
                where_[0] += 1
            where_ = [int(data[2]), int(data[3]), int(data[4])]
            while where_[1] - 1 >= 0 and \
                    int(self.everything[hash_with_who][2][where_[0]][where_[1]][where_[2]]) == 4:
                if int(self.everything[hash_with_who][2][where_[0]][where_[1] - 1][where_[2]]) == 1:
                    hit = False
                where_[1] -= 1
            where_ = [int(data[2]), int(data[3]), int(data[4])]
            while where_[1] + 1 < LengthBigCube and \
                    int(self.everything[hash_with_who][2][where_[0]][where_[1]][where_[2]]) == 4:
                if int(self.everything[hash_with_who][2][where_[0]][where_[1] + 1][where_[2]]) == 1:
                    hit = False
                where_[1] += 1
            where_ = [int(data[2]), int(data[3]), int(data[4])]
            while where_[2] - 1 >= 0 and \
                    int(self.everything[hash_with_who][2][where_[0]][where_[1]][where_[2]]) == 4:
                if int(self.everything[hash_with_who][2][where_[0]][where_[1]][where_[2] - 1]) == 1:
                    hit = False
                where_[2] -= 1
            where_ = [int(data[2]), int(data[3]), int(data[4])]
            while where_[2] + 1 < LengthBigCube and \
                    int(self.everything[hash_with_who][2][where_[0]][where_[1]][where_[2]]) == 4:
                if int(self.everything[hash_with_who][2][where_[0]][where_[1]][where_[2] + 1]) == 1:
                    hit = False
                where_[2] += 1

            if hit:  # если корабль убит
                self.everything[hash_with_who][5] -= 1
                if self.everything[hash_with_who][5] == 0:  # если у противника закончились корабли
                    self.everything[data[0]][0].write("win".encode())  # отправляем - ты выиграл
                    self.everything[hash_with_who][1] = 'fail'
                else:
                    self.everything[data[0]][0].write("kill".encode())  # убит, но еще есть корабли другие
                    self.everything[hash_with_who][1] = 'kill'
            else:  # если корабль не убит
                self.everything[data[0]][0].write("yes".encode())  # кидаем да, ты попал, но не убил

        else:
            self.everything[data[0]][0].write("no".encode())  # кидаем нет
            self.everything[data[0]][1] = 'wait'  # меняем статус
            self.everything[hash_with_who][1] = 'fire'  # меняем статус
            self.everything[hash_with_who][2][self.where[0]][self.where[1]][self.where[2]] = 3

    def waiting_func(self, data):
        if self.everything[data[0]][1] == 'fire_st':  # если можно стрелять
            self.everything[data[0]][0].write("yes_st".encode())
            self.everything[data[0]][1] = 'shoots'
        elif self.everything[data[0]][1] == 'fire':  # если можно стрелять
            self.everything[data[0]][0].write("yes".encode())
            self.everything[data[0]][1] = 'shoots'
        elif self.everything[data[0]][1] == 'hurt':  # если попали
            self.everything[data[0]][0].write("hurt".encode())
        elif self.everything[data[0]][1] == 'fail' or self.everything[data[0]][1] == 'win':
            self.everything[data[0]][0].write((self.everything[data[0]][1]).encode())
            hash_with_who = self.pairs[self.everything[data[0]][4][0]][1 - self.everything[data[0]][4][1]]
            del self.everything[hash_with_who]
            self.pairs[self.everything[data[0]][4][0]] = []
            del self.everything[data[0]]

        elif self.everything[data[0]][1] == 'kill':
            self.everything[data[0]][0].write('kill'.encode())
        else:
            self.everything[data[0]][0].write("no".encode())


if __name__ == '__main__':
    run_server('127.0.0.1', 5000)
