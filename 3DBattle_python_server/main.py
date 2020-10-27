import asyncio
from random import randint
import json

'''
3) Написать повторное подключение игрока к серверу по причине локального вылета из игры.
4) Написать восстановление сервера при его неожиданном падении (файл, где хранятся действующие игры).
5) Написать историю игр (*)
6) Запретить стрельбу повторную по тем же кубикам
7) Написать бота со стороны сервера
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
    pairs_bots = []

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
                        if self.everything[data[2]][1] == 'ready':  # если он ожидал противника
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

                else:  # если такого ключа не нашлось
                    self.everything[data[0]][0].write("no".encode())

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
        LengthBigCube = int(data[len(data) - 2])
        count_map = 2
        battle_map = [[[0 for _ in range(LengthBigCube)] for _ in range(LengthBigCube)] for _ in range(LengthBigCube)]
        for i in range(LengthBigCube):
            for j in range(LengthBigCube):
                for k in range(LengthBigCube):
                    battle_map[i][j][k] = data[count_map]
                    count_map += 1
        self.everything[data[0]].append(battle_map)  # карта в словарь

        self.everything[data[0]].append(LengthBigCube)  # размер поля в словарь

        if int(data[int(len(data)) - 1]) == 1:  # если играем с ботом
            '''Создать комплект бота и добавить в тапл'''
            for i in self.pairs_bots:
                if len(i) == 0:
                    i.append((data[0]))
                    to_pair = True
            if not to_pair:
                self.pairs_bots.append((data[0]))

        else:  # если хочет играть с человеком
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
        self.everything[data[0]].append(data[int(len(data)) - 1])
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


class Bot:
    def __init__(self, len_cube):
        self.map_enemy = [[[0 for _ in range(len_cube)] for _ in range(len_cube)] for _ in range(len_cube)]
        with open(".maps.json", 'r') as f:
            data = json.load(f)
            map_str = data[str(len_cube)][randint(0, len(data[len_cube]) - 1)]
            battle_map = [[[0 for _ in range(len_cube)] for _ in range(len_cube)] for _ in range(len_cube)]
            count_map = 0
            for i in range(len_cube):
                for j in range(len_cube):
                    for k in range(len_cube):
                        battle_map[i][j][k] = int(map_str[count_map])
                        count_map += 1
            self.my_map = battle_map
        self.cells_empty = [[i, j, k] for k in range(len_cube) for j in range(len_cube) for i in range(len_cube)]
        self.len_cube = len_cube
        self.hit = []  # в какие клетки попали (еще не убив корабля)
        self.i, self.j, self.k = None, None, None
        self.can_fire_hit = []

    def fire_func(self):  # стреляет бот
        r = None
        if len(self.hit) == 1:
            r = self.can_fire_hit[randint(0, len(self.can_fire_hit))]
            self.can_fire_hit.remove(r)
        elif len(self.hit) > 1:
            t1, t2 = self.hit[len(self.hit) - 1], self.hit[len(self.hit) - 2]
            r = []
            if t1[0] == t2[0]:
                if t1[1] == t2[1]:
                    o = [max([y[2] + 1 if y[2] + 1 < self.len_cube and self.map_enemy[y[0]][y[1]][y[2] + 1] == 0 else
                              None for y in self.hit]),
                         min([y[2] - 1 if y[2] - 1 >= 0 and self.map_enemy[y[0]][y[1]][y[2] - 1] == 0 else
                              None for y in self.hit])]
                    r3 = o[0] if o[1] is None else o[1] if o[0] is None else o[randint(0, 1)]
                    r = [t1[0], t1[1], r3]
                else:
                    o = [max([y[1] + 1 if y[1] + 1 < self.len_cube and self.map_enemy[y[0]][y[1] + 1][y[2]] == 0 else
                              None for y in self.hit]),
                         min([y[1] - 1 if y[1] - 1 >= 0 and self.map_enemy[y[0]][y[1] - 1][y[2]] == 0 else
                              None for y in self.hit])]
                    r3 = o[0] if o[1] is None else o[1] if o[0] is None else o[randint(0, 1)]
                    r = [t1[1], r3, t1[2]]
            else:
                o = [max([y[0] + 1 if y[0] + 1 < self.len_cube and self.map_enemy[y[0] + 1][y[1]][y[2]] == 0 else
                          None for y in self.hit]),
                     min([y[0] - 1 if y[0] - 1 >= 0 and self.map_enemy[y[0] - 1][y[1]][y[2]] == 0 else
                          None for y in self.hit])]
                r3 = o[0] if o[1] is None else o[1] if o[0] is None else o[randint(0, 1)]
                r = [r3, t1[1], t1[2]]
        else:
            r = self.cells_empty[randint(0, self.len_cube ** 3 - 1)]
        i, j, k = [int(p) for p in r]
        self.cells_empty.remove(r)
        self.map_enemy[i][j][k] = 3  # промахнулись
        self.i, self.j, self.k = i, j, k  # запоминаем координаты последнего выстрела
        return r

    def after_hit(self):
        self.map_enemy[self.i][self.j][self.k] = 4  # попали
        self.hit.append([self.i, self.j, self.k])
        if not self.can_fire_hit:
            self.can_fire_hit = [[i, j, k] for i in range(self.i - 1, self.i + 1, 2) if 0 <= i < self.len_cube
                                 for j in range(self.j - 1, self.j + 1, 2) if 0 <= j < self.len_cube
                                 for k in range(self.k - 1, self.k + 1, 2) if 0 <= k < self.len_cube]
        self.fire_func()

    def bot_hit_func(self, cells):  # когда стреляли в бота
        i, j, k = [int(p) for p in cells]
        if self.my_map[i][j][k] == 1:
            self.my_map[i][j][k] = 4
            return 1  # попадание
        elif self.my_map[i][j][k] == 3 or self.my_map[i][j][k] == 4:
            return 2  # повторный выстрел
        else:
            self.my_map[i][j][k] = 3
            return 0  # промах

    def kill_enemy(self):  # бот убил корабль противника
        self.can_fire_hit = []
        self.map_enemy[self.i][self.j][self.k] = 4
        if len(self.hit) == 1:
            c = [[i, j, k] for i in range(self.i - 1, self.i + 1, 2) if 0 <= i < self.len_cube
                 for j in range(self.j - 1, self.j + 1, 2) if 0 <= j < self.len_cube
                 for k in range(self.k - 1, self.k + 1, 2) if 0 <= k < self.len_cube]
            for i in c:
                self.map_enemy[i[0]][i[1]][i[2]] = 3
        else:
            t1, t2 = self.hit[0], self.hit[1]
            o = None
            if t1[0] == t2[0]:
                if t1[1] == t2[1]:
                    o = max([y[2] for y in self.hit])
                    while o >= 0 and self.map_enemy[t1[0]][t1[1]][o] == 4:
                        c = [[i, j, k] for i in range(t1[0] - 1, t1[0] + 1, 2) if 0 <= i < self.len_cube
                             for j in range(t1[1] - 1, t1[1] + 1, 2) if 0 <= j < self.len_cube
                             for k in range(o - 1, o + 1, 2) if 0 <= k < self.len_cube]
                        for i in c:
                            if self.map_enemy[i[0]][i[1]][i[2]] == 0:
                                self.map_enemy[i[0]][i[1]][i[2]] = 3
                        o -= 1
                else:
                    o = max([y[1] for y in self.hit])
                    while o >= 0 and self.map_enemy[t1[0]][o][t1[2]] == 4:
                        c = [[i, j, k] for i in range(t1[0] - 1, t1[0] + 1, 2) if 0 <= i < self.len_cube
                             for j in range(o - 1, o + 1, 2) if 0 <= j < self.len_cube
                             for k in range(t1[2] - 1, t1[2] + 1, 2) if 0 <= k < self.len_cube]
                        for i in c:
                            if self.map_enemy[i[0]][i[1]][i[2]] == 0:
                                self.map_enemy[i[0]][i[1]][i[2]] = 3
                        o -= 1
            else:
                o = max([y[0] for y in self.hit])
                while o >= 0 and self.map_enemy[o][t1[1]][t1[2]] == 4:
                    c = [[i, j, k] for i in range(o - 1, o + 1, 2) if 0 <= i < self.len_cube
                         for j in range(t1[1] - 1, t1[1] + 1, 2) if 0 <= j < self.len_cube
                         for k in range(t1[2] - 1, t1[2] + 1, 2) if 0 <= k < self.len_cube]
                    for i in c:
                        if self.map_enemy[i[0]][i[1]][i[2]] == 0:
                            self.map_enemy[i[0]][i[1]][i[2]] = 3
                    o -= 1
        self.hit = []

    def kill_func(self, cells):  # когда убили корабль бота
        pass


if __name__ == '__main__':
    run_server('127.0.0.1', 5000)
