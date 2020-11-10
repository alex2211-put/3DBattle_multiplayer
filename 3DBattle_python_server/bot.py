import json
from random import randint


class Bot:
    def __init__(self, len_cube):
        self.map_enemy = [[[0 for _ in range(len_cube)] for _ in range(len_cube)] for _ in range(len_cube)]
        with open(".maps.json", 'r') as f:
            data = json.load(f)
            map_str = data[str(len_cube)][randint(0, len(data[str(len_cube)]) - 1)]
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
        self.ships = (1 + len_cube - 2) * (
                len_cube - 2) / 2  # подсчитаем арифметической прогрессией число кораблей
        self.fire = False

    def fire_func(self):  # стреляет бот
        if len(self.hit) == 1:
            r = self.can_fire_hit[randint(0, len(self.can_fire_hit) - 1)]
            self.can_fire_hit.remove(r)
        elif len(self.hit) > 1:
            t1, t2 = self.hit[len(self.hit) - 1], self.hit[len(self.hit) - 2]
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
            r = self.cells_empty[randint(0, len(self.cells_empty) - 1)]
        i, j, k = [int(p) for p in r]
        try:
            self.cells_empty.remove(r)
        except:
            r = self.fire_func()
        self.map_enemy[i][j][k] = 3  # промахнулись
        self.i, self.j, self.k = i, j, k  # запоминаем координаты последнего выстрела
        return r

    def after_hit(self):
        self.map_enemy[self.i][self.j][self.k] = 4  # попали
        self.hit.append([self.i, self.j, self.k])
        if not self.can_fire_hit:
            if self.i - 1 >= 0:
                self.can_fire_hit.append([self.i - 1, self.j, self.k])
            if self.i + 1 < self.len_cube:
                self.can_fire_hit.append([self.i + 1, self.j, self.k])
            if self.j - 1 >= 0:
                self.can_fire_hit.append([self.i, self.j - 1, self.k])
            if self.j + 1 < self.len_cube:
                self.can_fire_hit.append([self.i, self.j + 1, self.k])
            if self.k - 1 >= 0:
                self.can_fire_hit.append([self.i, self.j, self.k - 1])
            if self.k + 1 < self.len_cube:
                self.can_fire_hit.append([self.i, self.j, self.k + 1])
            try:
                counts = self.can_fire_hit.count([-1, -1, -1])
                for _ in range(counts):
                    self.can_fire_hit.remove([-1, -1, -1])
            except:
                pass
        return self.fire_func()

    def kill_enemy(self):  # бот убил корабль противника
        self.can_fire_hit = []
        self.map_enemy[self.i][self.j][self.k] = 4
        self.hit.append([self.i, self.j, self.k])
        if len(self.hit) == 1:
            c = [[i, j, k] if [i, j, k] in self.cells_empty else [-1, -1, -1]
                 for i in range(self.i - 1, self.i + 2, 2) if 0 <= i < self.len_cube
                 for j in range(self.j - 1, self.j + 2, 2) if 0 <= j < self.len_cube
                 for k in range(self.k - 1, self.k + 2, 2) if 0 <= k < self.len_cube]
            try:
                counts = self.can_fire_hit.count([-1, -1, -1])
                for _ in range(counts):
                    self.can_fire_hit.remove([-1, -1, -1])
            except:
                pass
            for i in c:
                try:
                    self.map_enemy[i[0]][i[1]][i[2]] = 3
                    self.cells_empty.remove([i[0], i[1], i[2]])
                except:
                    pass
        else:
            t1, t2 = self.hit[0], self.hit[1]
            o = None
            if t1[0] == t2[0]:
                if t1[1] == t2[1]:
                    o = max([y[2] for y in self.hit])
                    while o >= 0 and self.map_enemy[t1[0]][t1[1]][o] == 4:
                        c = [[i, j, k] for i in range(t1[0] - 1, t1[0] + 2, 2) if 0 <= i < self.len_cube
                             for j in range(t1[1] - 1, t1[1] + 2, 2) if 0 <= j < self.len_cube
                             for k in range(o - 1, o + 2, 2) if 0 <= k < self.len_cube]
                        for i in c:
                            if self.map_enemy[i[0]][i[1]][i[2]] == 0:
                                self.map_enemy[i[0]][i[1]][i[2]] = 3
                                self.cells_empty.remove([i[0], i[1], i[2]])
                        o -= 1
                else:
                    o = max([y[1] for y in self.hit])
                    while o >= 0 and self.map_enemy[t1[0]][o][t1[2]] == 4:
                        c = [[i, j, k] for i in range(t1[0] - 1, t1[0] + 2, 2) if 0 <= i < self.len_cube
                             for j in range(o - 1, o + 2, 2) if 0 <= j < self.len_cube
                             for k in range(t1[2] - 1, t1[2] + 2, 2) if 0 <= k < self.len_cube]
                        for i in c:
                            if self.map_enemy[i[0]][i[1]][i[2]] == 0:
                                self.map_enemy[i[0]][i[1]][i[2]] = 3
                                self.cells_empty.remove([i[0], i[1], i[2]])
                        o -= 1
            else:
                o = max([y[0] for y in self.hit])
                while o >= 0 and self.map_enemy[o][t1[1]][t1[2]] == 4:
                    c = [[i, j, k] for i in range(o - 1, o + 2, 2) if 0 <= i < self.len_cube
                         for j in range(t1[1] - 1, t1[1] + 2, 2) if 0 <= j < self.len_cube
                         for k in range(t1[2] - 1, t1[2] + 2, 2) if 0 <= k < self.len_cube]
                    for i in c:
                        if self.map_enemy[i[0]][i[1]][i[2]] == 0:
                            self.map_enemy[i[0]][i[1]][i[2]] = 3
                            self.cells_empty.remove([i[0], i[1], i[2]])
                    o -= 1
        self.hit = []

    def kill_func(self, cells):  # когда убили корабль бота
        self.my_map[cells[0]][cells[1]][cells[2]] = 4
        t1 = [int(p) for p in cells]
        t2 = None
        c = [[i, j, k] for i in range(t1[0] - 1, t1[0] + 2) if 0 <= i < self.len_cube
             for j in range(t1[1] - 1, t1[1] + 2) if 0 <= j < self.len_cube
             for k in range(t1[2] - 1, t1[2] + 2) if 0 <= k < self.len_cube]
        for i in c:
            if self.my_map[i[0]][i[1]][i[2]] == 4 and (i[0] != t1[0] or i[1] != t1[1] or i[2] != t1[2]):
                t2 = [i[0], i[1], i[2]]
        o = None

        if t2 is not None:

            if t1[0] == t2[0]:

                if t1[1] == t2[1]:
                    o = t1[2]
                    while self.my_map[t1[0]][t1[1]][o] == 4 and o < self.len_cube:
                        o += 1
                    o -= 1
                    while o >= 0 and self.my_map[t1[0]][t1[1]][o] == 4:
                        c = [[i, j, k] for i in range(t1[0] - 1, t1[0] + 2) if 0 <= i < self.len_cube
                             for j in range(t1[1] - 1, t1[1] + 2) if 0 <= j < self.len_cube
                             for k in range(o - 1, o + 2) if 0 <= k < self.len_cube]
                        for i in c:
                            if self.my_map[i[0]][i[1]][i[2]] == 0 or self.my_map[i[0]][i[1]][i[2]] == 2:
                                self.my_map[i[0]][i[1]][i[2]] = 3
                        o -= 1
                else:
                    o = t1[1]
                    while self.my_map[t1[0]][o][t1[2]] == 4 and o < self.len_cube:
                        o += 1

                    o -= 1
                    while o >= 0 and self.my_map[t1[0]][o][t1[2]] == 4:
                        c = [[i, j, k] for i in range(t1[0] - 1, t1[0] + 2) if 0 <= i < self.len_cube
                             for j in range(o - 1, o + 2) if 0 <= j < self.len_cube
                             for k in range(t1[2] - 1, t1[2] + 2) if 0 <= k < self.len_cube]
                        for i in c:
                            if self.my_map[i[0]][i[1]][i[2]] == 0 or self.my_map[i[0]][i[1]][i[2]] == 2:
                                self.my_map[i[0]][i[1]][i[2]] = 3
                        o -= 1
            else:
                o = t1[0]
                while self.my_map[o][t1[1]][t1[2]] == 4 and o < self.len_cube:
                    o += 1

                o -= 1
                while o >= 0 and self.my_map[o][t1[1]][t1[2]] == 4:
                    c = [[i, j, k] for i in range(o - 1, o + 2) if 0 <= i < self.len_cube
                         for j in range(t1[1] - 1, t1[1] + 2) if 0 <= j < self.len_cube
                         for k in range(t1[2] - 1, t1[2] + 2) if 0 <= k < self.len_cube]
                    for i in c:
                        if self.my_map[i[0]][i[1]][i[2]] == 0 or self.my_map[i[0]][i[1]][i[2]] == 2:
                            self.my_map[i[0]][i[1]][i[2]] = 3
                    o -= 1
        else:
            for i in c:
                if self.my_map[i[0]][i[1]][i[2]] == 0 or self.my_map[i[0]][i[1]][i[2]] == 2:
                    self.my_map[i[0]][i[1]][i[2]] = 3
