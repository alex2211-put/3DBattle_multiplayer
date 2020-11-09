//
// Created by alikp on 06.10.2020.
//

#ifndef INC_3DSEEBUTTLE_CLIENT_H
#define INC_3DSEEBUTTLE_CLIENT_H
#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>


int s;
std::string hash;
bool waiting_window = false;
bool bot_player_window = false;
bool red_window = false;
double red_time = 0;
bool bot = false;
bool server_window = false;
unsigned int carrier_bot = 0;


int init_sock() {
    int len;
    sockaddr_in address{};
    int result;
    int s1;
    s1 = socket(AF_INET, SOCK_STREAM,0);
    address.sin_family = AF_INET;   // интернет домен
    address.sin_addr.s_addr = inet_addr("127.0.0.1");   ///соединяемся с 127.0.0.1
    address.sin_port = htons(5000);    /// 5000 порт
    len = sizeof(address);
    result = connect(s1, (sockaddr *)&address, len);   ///установка соединения
    if (result == -1) {
        perror("oops: client");
        return -1;
    }
    server_window = false;
    glutPostRedisplay();
    return s1;
}

std::string readServ(int s) {
    fd_set fdr;
    FD_ZERO(&fdr);
    FD_SET(s,&fdr);
    timeval timeout;
    timeout.tv_sec = 0;   ///зададим  структуру времени со значением 1 сек
    timeout.tv_usec = 1;
    std::string d;
    char buff2[512] ={' '};
    recv(s,&buff2,512,0);   /// получаем данные из потока
    d = buff2; /// записываем результат
    return d;
}

void sendServ(int s, std::string str) {
    int rc;
    fd_set fdr;
    FD_ZERO(&fdr);
    FD_SET(s, &fdr);
    std::string d;
    char buff[512] = {' '};
    std::string hash_ = hash + " " + str;
    for (int i = 0; i < hash_.length(); i++)
        buff[i] = hash_[i];
    send(s, &buff[0], strlen(&buff[0]), 0);
}
#endif //INC_3DSEEBUTTLE_CLIENT_H
