from random import randint
from bot import Bot
from time import sleep


def ready_func(data, everything, pairs):
    """
    Append all data about client in dict
    :param data: list
    :param everything: dict
    :param pairs: list
    :return: None
    """
    to_pair, empty = False, False
    everything[data[0]][1] = 'ready'
    # making map
    len_big_cube = int(data[len(data) - 2])
    count_map = 2
    battle_map = [[[0 for _ in range(len_big_cube)] for _ in range(len_big_cube)] for _ in range(len_big_cube)]
    for i in range(len_big_cube):
        for j in range(len_big_cube):
            for k in range(len_big_cube):
                battle_map[i][j][k] = data[count_map]
                count_map += 1
    everything[data[0]][2], everything[data[0]][3] = battle_map, len_big_cube

    if int(data[int(len(data)) - 1]) == 0:  # if wants to play with player
        for i in pairs:
            if len(i) == 0:
                i.append(data[0])
                everything[data[0]][4] = (pairs.index(i), 0)
                everything[data[0]][1] = 'ready'
                empty = True
            elif len(i) == 1:
                if everything[i[0]][3] == len_big_cube:  # maps must be the same length
                    i.append(data[0])
                    to_pair = True
                    everything[data[0]][4] = (pairs.index(i), 1)
                    who_starts = randint(0, 1)
                    everything[data[0]][1] = 'fire_st' if who_starts == 1 else 'wait'
                    everything[i[0]][1] = 'wait' if who_starts == 1 else 'fire_st'
                    everything[data[0]][0].write(str(who_starts).encode())
                    everything[i[0]][0].write(str(1 - who_starts).encode())

        if not to_pair and not empty:
            pairs.append([data[0]])
            everything[data[0]][4] = (len(pairs) - 1, 0)
            everything[data[0]][1] = 'ready'
    else:  # if wants to play with bot
        assert int(data[int(len(data)) - 1]) == 1
        everything[data[0]][4] = (0, 0)
        who = randint(0, 1)
        everything[data[0]][0].write(str(who).encode())
        everything[data[0]][1] = 'fire_st' if who == 1 else 'wait'
        everything[data[0]][6] = Bot(len_big_cube)
    everything[data[0]][5] = (1 + len_big_cube - 2) * (len_big_cube - 2) / 2  # count ships
    everything[data[0]][0].write('ok'.encode())


def for_bot_fire(data, bot, everything, where):
    """
    The bot shoots
    :param where: list
    :param data: list
    :param bot: class Bot
    :param everything: dict
    :return: None
    """
    sleep(0.5)
    if not bot.fire:
        cells = [int(i) for i in bot.fire_func()]
    else:
        cells = [int(i) for i in bot.after_hit()]
    map_enemy = everything[data[0]][2]
    len_big_cube = everything[data[0]][3]
    for i in range(len(where)):
        where[i] = cells[i]
    if int(map_enemy[where[0]][where[1]][where[2]]) == 1:  # if a ship is hit
        map_enemy[where[0]][where[1]][where[2]] = 4
        everything[data[0]][1] = 'hurt'

        hit = True  # checking whether the ship is alive or not
        for i in range(3):
            where_ = [where[0], where[1], where[2]]
            while where_[i] - 1 >= 0 and \
                    int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
                where_[i] -= 1
                if int(map_enemy[where_[0]][where_[1]][where_[2]]) == 1:
                    hit = False
        for i in range(3):
            where_ = [where[0], where[1], where[2]]
            while where_[i] + 1 < len_big_cube and \
                    int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
                where_[i] += 1
                if int(map_enemy[where_[0]][where_[1]][where_[2]]) == 1:
                    hit = False

        if hit:  # if the ship is killed
            everything[data[0]][5] -= 1
            if everything[data[0]][5] > 0:
                bot.kill_enemy()
                bot.fire = False
            everything[data[0]][1] = 'fail' if everything[data[0]][5] == 0 else 'kill'
        else:  # if the ship is alive
            bot.fire = True
    else:
        bot.fire = False
        everything[data[0]][1] = 'fire'
        map_enemy[where[0]][where[1]][where[2]] = 3


def fire_func(data, everything, pairs, where):
    """
    The client shoots
    :param where: list
    :param data: list
    :param everything: dict
    :param pairs: list
    :return: None
    """
    bot = False
    bot_pack = None
    hash_with_who = None
    if everything[data[0]][6] != 0:
        map_enemy = everything[data[0]][6].my_map
        bot = True
        bot_pack = everything[data[0]][6]
    else:
        hash_with_who = pairs[everything[data[0]][4][0]][1 - everything[data[0]][4][1]]
        map_enemy = everything[hash_with_who][2]
    cells = [int(data[i]) for i in range(2, 5)]
    for i in range(len(where)):
        where[i] = cells[i]
    len_big_cube = everything[data[0]][3]

    if int(map_enemy[where[0]][where[1]][where[2]]) == 1:  # if a ship is hit
        map_enemy[where[0]][where[1]][where[2]] = 4
        if not bot:
            everything[hash_with_who][1] = 'hurt'

        hit = True  # checking whether the ship is alive or not
        for i in range(3):
            where_ = [where[0], where[1], where[2]]
            while where_[i] - 1 >= 0 and \
                    int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
                where_[i] -= 1
                if int(map_enemy[where_[0]][where_[1]][where_[2]]) == 1:
                    hit = False
        for i in range(3):
            where_ = [where[0], where[1], where[2]]
            while where_[i] + 1 < len_big_cube and \
                    int(map_enemy[where_[0]][where_[1]][where_[2]]) == 4:
                where_[i] += 1
                if int(map_enemy[where_[0]][where_[1]][where_[2]]) == 1:
                    hit = False

        if hit:  # if the ship is killed
            if not bot:
                everything[hash_with_who][5] -= 1
                everything[data[0]][0].write("win".encode() if everything[hash_with_who][5] == 0 else "kill".encode())
                everything[hash_with_who][1] = 'fail' if everything[hash_with_who][5] == 0 else 'kill'
            elif bot:
                bot_pack.ships -= 1
                if bot_pack.ships == 0:
                    everything[data[0]][1] = 'win'
                else:
                    bot_pack.kill_func(where)
                everything[data[0]][0].write("win".encode() if bot_pack.ships == 0 else "kill".encode())
        else:  # if the ship is alive
            everything[data[0]][0].write("yes".encode())

    elif int(map_enemy[where[0]][where[1]][where[2]]) == 3 or int(map_enemy[where[0]][where[1]][where[2]]) == 4:
        everything[data[0]][0].write("again".encode())

    else:
        everything[data[0]][0].write("no".encode())
        everything[data[0]][1] = 'wait'
        if not bot:
            everything[hash_with_who][1] = 'fire'
        map_enemy[where[0]][where[1]][where[2]] = 3


def waiting_func(data, everything, pairs, where):
    """
    The client is waiting for his turn
    :param where: list
    :param data: list
    :param everything: dict
    :param pairs: list
    :return: None
    """
    if everything[data[0]][1] == 'fire_st':
        everything[data[0]][0].write("yes_st".encode())
        everything[data[0]][1] = 'shoots'
    elif everything[data[0]][1] == 'fire':
        everything[data[0]][0].write("yes".encode())
        everything[data[0]][1] = 'shoots'
    elif everything[data[0]][1] == 'hurt':
        everything[data[0]][0].write("hurt".encode())
    elif everything[data[0]][1] == 'fail' or everything[data[0]][1] == 'win':
        everything[data[0]][0].write((everything[data[0]][1]).encode())
        if everything[data[0]][6] == 0:
            hash_with_who = pairs[everything[data[0]][4][0]][1 - everything[data[0]][4][1]]
            del everything[hash_with_who]
            pairs[everything[data[0]][4][0]] = []
        del everything[data[0]]

    elif everything[data[0]][1] == 'kill':
        everything[data[0]][0].write('kill'.encode())
    else:
        if everything[data[0]][6] != 0 and everything[data[0]][1] == 'wait':
            everything[data[0]][0].write("no".encode())
            for_bot_fire(data, everything[data[0]][6], everything, where)
        else:
            everything[data[0]][0].write("no".encode())


def back_func(data, everything, pairs):
    """
    Client returns on server
    :param data: list
    :param everything: dict
    :param pairs: list
    :return: None
    """
    if data[2] in everything:
        print(everything[data[2]][1])
        if everything[data[2]][1] == 'win' or everything[data[2]][1] == 'fail':
            everything[data[0]][0].write("no".encode())
        else:
            everything[data[2]][0] = everything[data[0]][0]
            del everything[data[0]]
            if len(everything[data[2]]) > 1:
                map = ''
                for i in range(everything[data[2]][3]):
                    for j in range(everything[data[2]][3]):
                        for k in range(everything[data[2]][3]):
                            map += str(everything[data[2]][2][i][j][k])

                if everything[data[2]][1] == 'ready':
                    everything[data[2]][0].write('ready\n'.encode())
                    everything[data[2]][0].write(map.encode())
                elif everything[data[2]][1] == 'wait':
                    map2 = ''
                    if everything[data[2]][6] == 0:
                        hash_with_who = pairs[everything[data[2]][4][0]][
                            1 - everything[data[2]][4][1]]
                        if everything[data[2]][6] == 0:
                            for i in range(everything[hash_with_who][3]):
                                for j in range(everything[hash_with_who][3]):
                                    for k in range(everything[hash_with_who][3]):
                                        if everything[hash_with_who][2][i][j][k] == 1:
                                            map2 += str(2)
                                        else:
                                            map2 += str(everything[hash_with_who][2][i][j][k])
                    else:
                        for i in range(everything[data[2]][3]):
                            for j in range(everything[data[2]][3]):
                                for k in range(everything[data[2]][3]):
                                    if everything[data[0]][6].my_map[i][j][k] == 1:
                                        map2 += str(2)
                                    else:
                                        map2 += str(everything[data[0]][6].my_map[i][j][k])
                    everything[data[2]][0].write('wait\n'.encode())
                    everything[data[2]][0].write(map.encode())
                    everything[data[2]][0].write(map2.encode())
                elif everything[data[2]][1] == 'shoots' or everything[data[2]][1] == 'fire_st':
                    map2 = ''
                    if everything[data[2]][6] == 0:
                        hash_with_who = pairs[everything[data[2]][4][0]][
                            1 - everything[data[2]][4][1]]
                        if everything[data[2]][6] == 0:
                            for i in range(everything[hash_with_who][3]):
                                for j in range(everything[hash_with_who][3]):
                                    for k in range(everything[hash_with_who][3]):
                                        if everything[hash_with_who][2][i][j][k] == 1:
                                            map2 += str(2)
                                        else:
                                            map2 += str(everything[hash_with_who][2][i][j][k])
                    else:
                        for i in range(everything[data[2]][3]):
                            for j in range(everything[data[2]][3]):
                                for k in range(everything[data[2]][3]):
                                    if everything[data[2]][6].my_map[i][j][k] == 1:
                                        map2 += str(2)
                                    else:
                                        map2 += str(everything[data[2]][6].my_map[i][j][k])
                    everything[data[2]][0].write('fire\n'.encode())
                    everything[data[2]][0].write(map.encode())
                    sleep(0.3)
                    everything[data[2]][0].write(map2.encode())
                    sleep(0.3)
            else:
                everything[data[2]][0].write('not_ready\n'.encode())

    else:  # no such key in dict
        everything[data[0]][0].write("no".encode())
