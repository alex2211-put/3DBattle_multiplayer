//
// Created by alik on 13.05.2020.
//

#ifndef INC_3DSEEBUTTLE_FORENTER5_ONECUBE_H
#define INC_3DSEEBUTTLE_FORENTER5_ONECUBE_H

#include "client.h"

bool correct = true; // переменная, отвечающая за честность расстановки
int saveLengthBigCube = 1; // переменная, необходимая для цикла расстановки кораблей

int shipsLifeFirst = 0;
int shipsLifeSecond = 0;
bool one = true;

void isCorrectYes()
{
    if (firstSide)
    {
        for (auto &i : a)
        {
            i[yf][z1].setColor(0.5, 0.5, 0.8);
            i[yf][z1].setTransparency(0.1);
        }
        for (int i1 = p1; i1 < p1 + ship; i1++)
        {
            a[i1][yf][z1].setColor(0, 1, 0);
            a[i1][yf][z1].setTransparency(0.5);
            a[i1][yf][z1].setIsHitten(1);
            if (isPlayer1)
                Player1[i1][yf][z1].setIsHitten(1);
            else Player2[i1][yf][z1].setIsHitten(1);
            a[i1][yf][z1].setPaint(true);
        }
        for (int i = p1 - 1; i <= p1 + ship; i++)
            for (int j = yf - 1; j <= yf + 1; j++)
                for (int k = z1 - 1; k <= z1 + 1; k++)
                    if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                        k < LengthBigCube)
                    {
                        if (a[i][j][k].getHit() != 1)
                        {
                            a[i][j][k].setPaint(false);
                            a[i][j][k].setIsHitten(2);
                            if (isPlayer1)
                                Player1[i][j][k].setIsHitten(2);
                            else Player2[i][j][k].setIsHitten(2);
                        }
                    }
        p1 = 0;
        yf = 0;
        z1 = 0;


    } else if (secondSide)
    {
        for (int j = 0; j < LengthBigCube; j++)
        {
            a[x2][j][z2].setColor(0.5, 0.5, 0.8);
            a[x2][j][z2].setTransparency(0.1);
        }
        for (int j2 = p2; j2 < p2 + ship; j2++)
        {
            a[x2][j2][z2].setColor(0, 1, 0);
            a[x2][j2][z2].setTransparency(0.5);
            a[x2][j2][z2].setIsHitten(1);
            if (isPlayer1)
                Player1[x2][j2][z2].setIsHitten(1);
            else Player2[x2][j2][z2].setIsHitten(1);
            a[x2][j2][z2].setPaint(true);
        }
        for (int i = x2 - 1; i <= x2 + 1; i++)
            for (int j = p2 - 1; j <= p2 + ship; j++)
                for (int k = z2 - 1; k <= z2 + 1; k++)
                    if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                        k < LengthBigCube)
                    {
                        if (a[i][j][k].getHit() != 1)
                        {
                            a[i][j][k].setPaint(false);
                            a[i][j][k].setIsHitten(2);
                            if (isPlayer1)
                                Player1[i][j][k].setIsHitten(2);
                            else Player2[i][j][k].setIsHitten(2);
                        }
                    }
        x2 = LengthBigCube - 1;
        p2 = 0;
        z2 = LengthBigCube - 1;

    } else if (thirdSide)
    {
        for (int k = 0; k < LengthBigCube; k++)
        {
            a[x3][y3][k].setColor(0.5, 0.5, 0.8);
            a[x3][y3][k].setTransparency(0.1);
        }
        for (int k3 = p3; k3 < p3 + ship; k3++)
        {
            a[x3][y3][k3].setColor(0, 1, 0);
            a[x3][y3][k3].setTransparency(0.5);
            a[x3][y3][k3].setIsHitten(1);
            if (isPlayer1)
                Player1[x3][y3][k3].setIsHitten(1);
            else Player2[x3][y3][k3].setIsHitten(1);
            a[x3][y3][k3].setPaint(true);
        }
        for (int i = x3 - 1; i <= x3 + 1; i++)
            for (int j = y3 - 1; j <= y3 + 1; j++)
                for (int k = p3 - 1; k <= p3 + ship; k++)
                    if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                        k < LengthBigCube)
                    {
                        if (a[i][j][k].getHit() != 1)
                        {
                            a[i][j][k].setPaint(false);
                            a[i][j][k].setIsHitten(2);
                            if (isPlayer1)
                                Player1[i][j][k].setIsHitten(2);
                            else Player2[i][j][k].setIsHitten(2);
                        }
                    }
        x3 = LengthBigCube - 1;
        y3 = 0;
        p3 = 0;
    }
    forEnter = 0;
    number_of_ships--;
    if (isPlayer1)
        shipsLifeFirst++;
    else shipsLifeSecond++;
    if (number_of_ships == 0)
    {
        saveLengthBigCube++;
        ship -= 1;
        number_of_ships = saveLengthBigCube;
    }
    if (ship == 0)
    {
        forCubeA = true;
        if (isPlayer1)
        {
            isPlayer1 = false;
            for (auto &i : Player1)
                for (auto &j : i)
                    for (auto &k : j)
                        k.setColor(0.5, 0.5, 0.8);
        } else
        {
            isPlayer1 = true;
            for (auto &i : Player2)
                for (auto &j : i)
                    for (auto &k : j)
                        k.setColor(0.5, 0.5, 0.8);
        }
        ship = LengthBigCube - 2;
        number_of_ships = 1; // счетчик числа кораблей с определенным кол-вом палуб (самый большой корабль всегда один)
        correct = true; // переменная, отвечающая за честность расстановки
        saveLengthBigCube = 1;
        forTwoPlayers = 2;
        if (forTwoPlayers == 2 && one)
        {
            std::string m;
            for (int i = 0; i < LengthBigCube; i++)
                for (int j = 0; j < LengthBigCube; j++)
                    for (int k = 0; k < LengthBigCube; k++)
                        m += std::to_string(Player1[i][j][k].getHit()) + " ";
            one = false;
            forOnePaint = 0;
            forEnter = 0;
            movement = true;
            sendServ(s, "ready " + m + " " + std::to_string(LengthBigCube));   ///отправляем ready, карту и размер поля
            readServ(s);
            waiting_window = true;
            return;
        }
    }
}

void forEnter5FunctionOne()
{
    correct = true;
    if (firstSide)
        for (int i1 = p1; i1 < p1 + ship; i1++)
        {
            if (a[i1][yf][z1].getHit() == 2 || a[i1][yf][z1].getHit() == 1)
                correct = false;
        }
    else if (secondSide)
        for (int j2 = p2; j2 < p2 + ship; j2++)
        {
            if (a[x2][j2][z2].getHit() == 2 || a[x2][j2][z2].getHit() == 1)
                correct = false;
        }
    else if (thirdSide)
        for (int k3 = p3; k3 < p3 + ship; k3++)
        {
            if (a[x3][y3][k3].getHit() == 2 || a[x3][y3][k3].getHit() == 1)
                correct = false;
        }

    if (correct)
    {
        isCorrectYes();
    } else
    {
        forEnter = 0;
        for (auto &i : a)
            for (auto &j : i)
                for (auto &k : j)
                {
                    if (k.getHit() != 2 && k.getHit() != 1)
                        k.setTransparency(0.1);
                    k.setColor(0.5, 0.5, 0.8);
                }
    }
    correct = true;
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
                k.setTransparency(0.11);
}

#endif //INC_3DSEEBUTTLE_FORENTER5_ONECUBE_H
