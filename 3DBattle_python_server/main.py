import asyncio
from random import randint


'''
1) Написать окончание игры, удаляя игроков из пар (удаляя пары).
2) Написать окончание игры, когда один из игроков решил выйти из игры по своему желанию.
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
    where = [0, 0, 0]

    def connection_made(self, transport):
        self.transport = transport
        answer = str(transport.__hash__()) + '\n'   # записываем хэш пришедшего подключения
        self.everything[str(transport.__hash__())] = [transport]   # создаем ключ с таким хэшом и кидаем связь
        self.transport.write(answer.encode())   # отпраляем хэш обратно

    def data_received(self, data):
        data = (data.decode('utf-8')).split()
        if data[0] in self.everything:
            if data[1] == 'ready':
                self.ready_func(data)

            elif data[1] == 'fire':   # клиент стреляет по противнику
                self.fire_func(data)

            elif data[1] == '?':   # стучимся в сервер в ожидании начала стрельбы (когда игра идет)
                self.waiting_func(data)

            elif data[1] == "x" or data[1] == 'kill_sec':   # клиент ждет координат своего подбитого корабля
                self.everything[data[0]][0].write(
                    (str(self.where[0]) + ' ' + str(self.where[1]) + ' ' + str(self.where[2])).encode())
                self.everything[data[0]][1] = 'wait'

            elif data[1] == 'hurt':   # клиент ждет координат своего промазанного поля (какой закрасить синим)
                self.everything[data[0]][0].write((str(self.where[0]) + ' ' + str(self.where[1]) + ' ' + str(self.where[2])).encode())

            elif data[1] == 'when':   # клиент в ожидании начала боя
                if self.everything[data[0]][1] == 'fire':
                    self.everything[data[0]][0].write("started\n".encode())
                    # print('написал started')
                    self.everything[data[0]][0].write(str(1).encode())
                elif self.everything[data[0]][1] == 'wait':
                    self.everything[data[0]][0].write("started\n".encode())
                    # print('написал started')
                    self.everything[data[0]][0].write(str(0).encode())
                else:
                    self.everything[data[0]][0].write("no\n".encode())

        else:
            print('Такого ключа нет в словаре!!!')

    def ready_func(self, data):
        to_pair = False  # смотрим, дополнилось ли к паре
        count = -1  # номер пары
        self.everything[data[0]].append(data[1])  # ready в словарь
        # сделан трехмерный массив для карты...
        length_cube = int(data[len(data) - 1])
        count_map = 2
        battle_map = [[[0 for _ in range(length_cube)] for _ in range(length_cube)] for _ in range(length_cube)]
        for i in range(length_cube):
            for j in range(length_cube):
                for k in range(length_cube):
                    battle_map[i][j][k] = data[count_map]
                    count_map += 1
        self.everything[data[0]].append(battle_map)  # карта в словарь

        self.everything[data[0]].append(length_cube)  # размер поля в словарь

        for i in self.pairs:
            count += 1
            if not len(i) == 2:
                if self.everything[i[0]][3] == length_cube:  # сверяем размер карты
                    i.append(data[0])
                    to_pair = True
                    self.everything[data[0]].append((count, 1))  # добавляем в словарь тапл с парой
                    who = randint(0, 1)
                    self.everything[data[0]][0].write(str(who).encode())  # отправляем ходит он первый или нет
                    if who == 1:
                        self.everything[data[0]][1] = 'fire'  # ставим статус что он стреляет
                        self.everything[i[0]][1] = 'wait'  # ставим статус что он ждет
                    else:
                        self.everything[data[0]][1] = 'wait'
                        self.everything[i[0]][1] = 'fire'
                    self.everything[i[0]][0].write(str(1 - who).encode())  # отпраляем ходит он первый или нет

        if not to_pair:
            self.pairs.append([data[0]])
            self.everything[data[0]].append((len(self.pairs) - 1, 0))
            self.everything[data[0]][1] = 'ready'
        ships = (1 + length_cube - 2) * (
                    length_cube - 2) / 2  # подсчитаем арифметической прогрессией число кораблей
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

            """<---написать локально жадный алгоритм !!!!!!!!!!!! проверка УБИЛИ  или ПОДБИЛИ !!!!!!!!!!!--->"""

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
        if self.everything[data[0]][1] == 'fire':  # если можно стрелять
            self.everything[data[0]][0].write("yes".encode())
        elif self.everything[data[0]][1] == 'hurt':  # если попали
            self.everything[data[0]][0].write("hurt".encode())
        elif self.everything[data[0]][1] == 'fail':
            self.everything[data[0]][0].write("fail".encode())
        elif self.everything[data[0]][1] == 'kill':
            self.everything[data[0]][0].write('kill'.encode())
        else:
            self.everything[data[0]][0].write("no".encode())


if __name__ == '__main__':
    run_server('127.0.0.1', 5000)
