import asyncio
from time import time
from funcs import *

'''
4) Make a server restore after it crashes
5) Make a game history
'''


def run_server(host, port):
    """
    Starting server on host & port
    """
    loop = asyncio.get_event_loop()

    core = loop.create_server(
        ClientServerProtocol,
        host, port
    )
    server = loop.run_until_complete(core)
    try:
        loop.run_forever()
    except KeyboardInterrupt:
        pass


class ClientServerProtocol(asyncio.Protocol):
    """
    Class with all data about clients, that processes requests
    """
    all_clients_data = {}
    # 1 number - transport
    # 2 number - status (ready, started, end)
    # 3 число - map of ships
    # 4 number - map's size
    # 5 number - couple's number(0) and place in it(1)
    # 6 number - number of remaining ships
    # 7 number - bot
    pairs = []
    new_pair_num = [0]
    where = [-2, -2, -2]
    pairs_bots = []
    time = time()

    def connection_made(self, transport):
        """
        Establishes a connection to a new client,
        stores it in the database by hash & send hash to the client
        """

        # if not self.all_clients_data:
        #     with open('.all_data.json', 'r') as f:
        #         if not f:
        #             self.all_clients_data = json.load(f)

        answer = str(transport.__hash__()) + '\n'
        self.all_clients_data[str(transport.__hash__())] = [transport, '', 0, 0, 0, 0, 0]  # making new entry
        transport.write(answer.encode())

    def data_received(self, data):
        """
        Processing of data received from the client
        """
        data = (data.decode('utf-8')).split()
        if data[0] in self.all_clients_data:
            if data[1] == 'ready':
                ready_func(data, self.all_clients_data, self.pairs)

            elif data[1] == 'fire':
                fire_func(data, self.all_clients_data, self.pairs, self.where)

            elif data[1] == '?':
                waiting_func(data, self.all_clients_data, self.pairs, self.where)

            elif data[1] == "x" or data[1] == 'kill_sec':
                self.all_clients_data[data[0]][0].write(("".join([str(i) + ' ' for i in self.where])).encode())
                self.all_clients_data[data[0]][1] = 'wait'

            elif data[1] == 'after_kill':
                len_big_cube = int(data[len(data) - 1])
                count_map = 2
                battle_map = [[[0 for _ in range(len_big_cube)] for _ in range(len_big_cube)] for _ in
                              range(len_big_cube)]
                for i in range(len_big_cube):
                    for j in range(len_big_cube):
                        for k in range(len_big_cube):
                            battle_map[i][j][k] = data[count_map]
                            count_map += 1
                self.all_clients_data[data[0]][2] = battle_map

            elif data[1] == 'hurt':  # client is waiting for coordinates of his missed ship (make it blue)
                self.all_clients_data[data[0]][0].write(("".join([str(i) + ' ' for i in self.where])).encode())

            elif data[1] == 'when':  # client is waiting for start
                if self.all_clients_data[data[0]][1] == 'fire_st':
                    self.all_clients_data[data[0]][0].write("started\n".encode())
                    self.all_clients_data[data[0]][0].write(str(1).encode())
                elif self.all_clients_data[data[0]][1] == 'wait':
                    self.all_clients_data[data[0]][0].write("started\n".encode())
                    self.all_clients_data[data[0]][0].write(str(0).encode())
                else:
                    self.all_clients_data[data[0]][0].write("no\n".encode())

            elif data[1] == 'end':  # client is out of the game
                try:
                    hash_with_who = self.pairs[self.all_clients_data[data[0]][4][0]][1 -
                                                                                     self.all_clients_data[data[0]][4][
                                                                                         1]]
                    self.all_clients_data[hash_with_who][1] = 'win'
                except:
                    pass
            elif data[1] == 'back':
                back_func(data, self.all_clients_data, self.pairs)
            elif list(data[1])[0] == '?':
                waiting_func(data, self.all_clients_data, self.pairs, self.where)

        else:
            raise ValueError('No such key in dict')


if __name__ == '__main__':
    run_server('127.0.0.1', 5000)
