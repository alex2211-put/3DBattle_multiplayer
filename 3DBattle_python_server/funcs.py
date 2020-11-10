from random import randint
from bot import Bot
from time import sleep


def ready_func(data, everything, pairs):
    to_pair = False  # смотрим, дополнилось ли к паре
    empty = False  # смотрим на наличие просто пустых мест
    count = -1  # номер пары
    everything[data[0]].append(data[1])  # ready в словарь
    # сделан трехмерный массив для карты...
    LengthBigCube = int(data[len(data) - 2])
    count_map = 2
    battle_map = [[[0 for _ in range(LengthBigCube)] for _ in range(LengthBigCube)] for _ in range(LengthBigCube)]
    for i in range(LengthBigCube):
        for j in range(LengthBigCube):
            for k in range(LengthBigCube):
                battle_map[i][j][k] = data[count_map]
                count_map += 1
    everything[data[0]].append(battle_map)  # карта в словарь

    everything[data[0]].append(LengthBigCube)  # размер поля в словарь

    if int(data[int(len(data)) - 1]) == 0:  # если хочет играть с человеком
        for i in pairs:
            count += 1
            if len(i) == 0:
                i.append(data[0])
                everything[data[0]].append((count, 0))
                everything[data[0]][1] = 'ready'
                empty = True
            elif not len(i) == 2:
                if everything[i[0]][3] == LengthBigCube:  # сверяем размер карты
                    i.append(data[0])
                    to_pair = True
                    everything[data[0]].append((count, 1))  # добавляем в словарь тапл с парой
                    who = randint(0, 1)
                    everything[data[0]][0].write(str(who).encode())  # отправляем ходит он первый или нет
                    if who == 1:
                        everything[data[0]][1] = 'fire_st'  # ставим статус что он стреляет
                        everything[i[0]][1] = 'wait'  # ставим статус что он ждет
                    else:
                        everything[data[0]][1] = 'wait'
                        everything[i[0]][1] = 'fire_st'
                    everything[i[0]][0].write(str(1 - who).encode())  # отпраляем ходит он первый или нет

        if not to_pair and not empty:
            pairs.append([data[0]])
            everything[data[0]].append((len(pairs) - 1, 0))
            everything[data[0]][1] = 'ready'
        ships = (1 + LengthBigCube - 2) * (
                LengthBigCube - 2) / 2  # подсчитаем арифметической прогрессией число кораблей
        everything[data[0]].append(ships)  # число кораблей в словарь
    else:  # если играем с ботом
        '''Создать комплект бота и добавить в тапл'''
        bot = Bot(LengthBigCube)
        everything[data[0]].append((0, 0))
        who = randint(0, 1)
        everything[data[0]][0].write(str(who).encode())
        if who == 1:
            everything[data[0]][1] = 'fire_st'  # ставим статус что он стреляет
        else:
            everything[data[0]][1] = 'wait'
        ships = (1 + LengthBigCube - 2) * (
                LengthBigCube - 2) / 2  # подсчитаем арифметической прогрессией число кораблей
        everything[data[0]].append(ships)  # число кораблей в словарь
        everything[data[0]].append(bot)  # добавляем комплект бота
    everything[data[0]][0].write('ok'.encode())


def for_bot_fire(data, bot, everything, where):
    sleep(0.5)
    map_enemy = None
    if not bot.fire:
        where[0], where[1], where[2] = [int(i) for i in bot.fire_func()]
    else:
        where[0], where[1], where[2] = [int(i) for i in bot.after_hit()]
    map_enemy = everything[data[0]][2]
    LengthBigCube = everything[data[0]][3]

    if int(map_enemy[where[0]][where[1]][where[2]]) == 1:  # если попали
        map_enemy[where[0]][where[1]][where[2]] = 4
        everything[data[0]][1] = 'hurt'  # меняем статус на "попали"

        hit = True  # проверяем, жив корабль или убит
        where_ = [where[0], where[1], where[2]]
        while where_[0] - 1 >= 0 and \
                int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
            if int(map_enemy[where_[0] - 1][where_[1]][where_[2]]) == 1:
                hit = False
            where_[0] -= 1
        where_ = [where[0], where[1], where[2]]
        while where_[0] + 1 < LengthBigCube and \
                int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
            if int(map_enemy[where_[0] + 1][where_[1]][where_[2]]) == 1:
                hit = False
            where_[0] += 1
        where_ = [where[0], where[1], where[2]]
        while where_[1] - 1 >= 0 and \
                int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
            if int(map_enemy[where_[0]][where_[1] - 1][where_[2]]) == 1:
                hit = False
            where_[1] -= 1
        where_ = [where[0], where[1], where[2]]
        while where_[1] + 1 < LengthBigCube and \
                int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
            if int(map_enemy[where_[0]][where_[1] + 1][where_[2]]) == 1:
                hit = False
            where_[1] += 1
        where_ = [where[0], where[1], where[2]]
        while where_[2] - 1 >= 0 and \
                int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
            if int(map_enemy[where_[0]][where_[1]][where_[2] - 1]) == 1:
                hit = False
            where_[2] -= 1
        where_ = [where[0], where[1], where[2]]
        while where_[2] + 1 < LengthBigCube and \
                int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
            if int(map_enemy[where_[0]][where_[1]][where_[2] + 1]) == 1:
                hit = False
            where_[2] += 1

        if hit:  # если корабль убит
            everything[data[0]][5] -= 1
            if everything[data[0]][5] == 0:  # если у противника закончились корабли
                everything[data[0]][1] = 'fail'
            else:
                everything[data[0]][1] = 'kill'
                bot.kill_enemy()
                bot.fire = False
        else:  # если корабль не убит
            bot.fire = True
    else:
        bot.fire = False
        everything[data[0]][1] = 'fire'  # меняем статус
        map_enemy[where[0]][where[1]][where[2]] = 3


def fire_func(data, everything, pairs, where):
    map_enemy = None
    bot = False
    bot_pack = None
    hash_with_who = None
    if len(everything[data[0]]) == 7:
        map_enemy = everything[data[0]][6].my_map
        bot = True
        bot_pack = everything[data[0]][6]
    else:
        hash_with_who = pairs[everything[data[0]][4][0]][1 - everything[data[0]][4][1]]
        map_enemy = everything[hash_with_who][2]
    where[0] = int(data[2])
    where[1] = int(data[3])
    where[2] = int(data[4])
    LengthBigCube = everything[data[0]][3]

    if int(map_enemy[where[0]][where[1]][where[2]]) == 1:  # если попали
        map_enemy[where[0]][where[1]][where[2]] = 4
        if not bot:
            everything[hash_with_who][1] = 'hurt'  # меняем статус на "попали"

        hit = True  # проверяем, жив корабль или убит
        where_ = [int(data[2]), int(data[3]), int(data[4])]
        while where_[0] - 1 >= 0 and \
                int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
            if int(map_enemy[where_[0] - 1][where_[1]][where_[2]]) == 1:
                hit = False
            where_[0] -= 1
        where_ = [int(data[2]), int(data[3]), int(data[4])]
        while where_[0] + 1 < LengthBigCube and \
                int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
            if int(map_enemy[where_[0] + 1][where_[1]][where_[2]]) == 1:
                hit = False
            where_[0] += 1
        where_ = [int(data[2]), int(data[3]), int(data[4])]
        while where_[1] - 1 >= 0 and \
                int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
            if int(map_enemy[where_[0]][where_[1] - 1][where_[2]]) == 1:
                hit = False
            where_[1] -= 1
        where_ = [int(data[2]), int(data[3]), int(data[4])]
        while where_[1] + 1 < LengthBigCube and \
                int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
            if int(map_enemy[where_[0]][where_[1] + 1][where_[2]]) == 1:
                hit = False
            where_[1] += 1
        where_ = [int(data[2]), int(data[3]), int(data[4])]
        while where_[2] - 1 >= 0 and \
                int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
            if int(map_enemy[where_[0]][where_[1]][where_[2] - 1]) == 1:
                hit = False
            where_[2] -= 1
        where_ = [int(data[2]), int(data[3]), int(data[4])]
        while where_[2] + 1 < LengthBigCube and \
                int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
            if int(map_enemy[where_[0]][where_[1]][where_[2] + 1]) == 1:
                hit = False
            where_[2] += 1

        if hit:  # если корабль убит
            if not bot:
                everything[hash_with_who][5] -= 1
                if everything[hash_with_who][5] == 0:  # если у противника закончились корабли
                    everything[data[0]][0].write("win".encode())  # отправляем - ты выиграл
                    everything[hash_with_who][1] = 'fail'
                else:
                    everything[data[0]][0].write("kill".encode())  # убит, но еще есть корабли другие
                    everything[hash_with_who][1] = 'kill'
            elif bot:
                bot_pack.ships -= 1
                if bot_pack.ships == 0:
                    everything[data[0]][0].write("win".encode())
                    everything[data[0]][1] = 'win'
                else:
                    bot_pack.kill_func([where[0], where[1], where[2]])
                    everything[data[0]][0].write("kill".encode())
        else:  # если корабль не убит
            everything[data[0]][0].write("yes".encode())  # кидаем да, ты попал, но не убил

    elif int(map_enemy[where[0]][where[1]][where[2]]) == 3 or int(map_enemy[where[0]][where[1]][where[2]]) == 4:
        everything[data[0]][0].write("again".encode())

    else:
        everything[data[0]][0].write("no".encode())  # кидаем нет
        everything[data[0]][1] = 'wait'  # меняем статус
        if not bot:
            everything[hash_with_who][1] = 'fire'  # меняем статус у соперника
        map_enemy[where[0]][where[1]][where[2]] = 3


def waiting_func(data, everything, where, pairs):
    if everything[data[0]][1] == 'fire_st':  # если можно стрелять
        everything[data[0]][0].write("yes_st".encode())
        everything[data[0]][1] = 'shoots'
    elif everything[data[0]][1] == 'fire':  # если можно стрелять
        everything[data[0]][0].write("yes".encode())
        everything[data[0]][1] = 'shoots'
    elif everything[data[0]][1] == 'hurt':  # если попали
        everything[data[0]][0].write("hurt".encode())
    elif everything[data[0]][1] == 'fail' or everything[data[0]][1] == 'win':
        everything[data[0]][0].write((everything[data[0]][1]).encode())
        if not len(everything[data[0]]) == 7:
            hash_with_who = pairs[everything[data[0]][4][0]][1 - everything[data[0]][4][1]]
        if len(everything[data[0]]) != 7:
            del everything[hash_with_who]
            pairs[everything[data[0]][4][0]] = []
        del everything[data[0]]

    elif everything[data[0]][1] == 'kill':
        everything[data[0]][0].write('kill'.encode())
    else:
        if len(everything[data[0]]) == 7 and everything[data[0]][1] == 'wait':
            everything[data[0]][0].write("no".encode())
            for_bot_fire(data, everything[data[0]][6], everything, where)
        else:
            everything[data[0]][0].write("no".encode())
