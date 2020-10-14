//
// Created by alik on 13.05.2020.
//

#ifndef INC_3DSEEBUTTLE_TWOPLAYERSENTER1_H
#define INC_3DSEEBUTTLE_TWOPLAYERSENTER1_H

#include "Cube.h"
#include "DisplayCubes.h"
#include "ChooseSide.h"

double &r_rotate_x = rotate_x;
double &r_rotate_y = rotate_y;

int i_first_side = LengthBigCube - 1, j_first_side = 0, k_first_side = 0;
int i_second_side = LengthBigCube - 1, j_second_side = LengthBigCube - 1, k_second_side = LengthBigCube - 1;
int i_third_side = LengthBigCube - 1, j_third_side = 0, k_third_side = LengthBigCube - 1;

int yf = j_first_side, z1 = k_first_side;
int x2 = i_second_side, z2 = k_second_side;
int x3 = i_third_side, y3 = j_third_side;

int p1 = 0, p2 = 0, p3 = 0;

void twoForEnter1First()
{
    if (isPlayer1)
    {
        /*choose_first_side_Player1(r_rotate_x, r_rotate_y);
        for (int i = 0; i <= LengthBigCube - 1; i++)
        {
            if (Player1[i][yf][z1].getHit() <= 2)
                Player1[i][yf][z1].setColor(1, 1, 0);
            else
            {
                Player1[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                Player1[i][yf][z1].setRed(true);
                Player1[i][yf][z1].setTransparency(1);
            }
            Player1[i][yf][z1].setTransparency(0.3);
        }
        Player1[i_first_side][j_first_side][k_first_side].setTransparency(0.5);
        if (Player1[i_first_side][j_first_side][k_first_side].getHit() == 3)
            Player1[i_first_side][j_first_side][k_first_side].setColor(255 / 255., 105 / 255., 60 / 255.);
        else if (Player1[i_first_side][j_first_side][k_first_side].getHit() == 4)
            Player1[i_first_side][j_first_side][k_first_side].setColor(1, 0, 0);
        else Player1[i_first_side][j_first_side][k_first_side].setColor(1, 1, 0);*/
    } else
    {
        choose_first_side_Player2(r_rotate_x, r_rotate_y);
        for (int i = 0; i <= LengthBigCube - 1; i++)
        {
            if (Player2[i][yf][z1].getHit() <= 2)
                Player2[i][yf][z1].setColor(1, 1, 0);
            else
            {
                Player2[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                Player2[i][yf][z1].setRed(true);
                Player2[i][yf][z1].setTransparency(1);
            }
            Player2[i][yf][z1].setTransparency(0.3);
        }
        Player2[i_first_side][j_first_side][k_first_side].setTransparency(0.5);
        if (Player2[i_first_side][j_first_side][k_first_side].getHit() == 3)
            Player2[i_first_side][j_first_side][k_first_side].setColor(255 / 255., 105 / 255., 60 / 255.);
        else if (Player2[i_first_side][j_first_side][k_first_side].getHit() == 4)
            Player2[i_first_side][j_first_side][k_first_side].setColor(1, 0, 0);
        else Player2[i_first_side][j_first_side][k_first_side].setColor(1, 1, 0);
    }
}

void twoForEnter1Second()
{
    if (isPlayer1)
    {
        /*choose_second_side_Player1(r_rotate_x, r_rotate_y);
        for (int i = 0; i <= LengthBigCube - 1; i++)
        {
            if (Player1[x2][i][z2].getHit() <= 2)
                Player1[x2][i][z2].setColor(1, 1, 0);
            else
            {
                Player1[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                Player1[x2][i][z2].setRed(true);
                Player1[x2][i][z2].setTransparency(1);
            }
            Player1[x2][i][z2].setTransparency(0.3);
        }
        Player1[i_second_side][j_second_side][k_second_side].setTransparency(0.5);
        if (Player1[i_second_side][j_second_side][k_second_side].getHit() == 3)
            Player1[i_second_side][j_second_side][k_second_side].setColor(255 / 255., 105 / 255.,
                                                                          60 / 255.);
        else if (Player1[i_second_side][j_second_side][k_second_side].getHit() == 4)
            Player1[i_second_side][j_second_side][k_second_side].setColor(1, 0, 0);
        else Player1[i_second_side][j_second_side][k_second_side].setColor(1, 1, 0);*/
    } else
    {
        choose_second_side_Player2(r_rotate_x, r_rotate_y);
        for (int i = 0; i <= LengthBigCube - 1; i++)
        {
            if (Player2[x2][i][z2].getHit() <= 2)
                Player2[x2][i][z2].setColor(1, 1, 0);
            else
            {
                Player2[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                Player2[x2][i][z2].setRed(true);
                Player2[x2][i][z2].setTransparency(1);
            }
            Player2[x2][i][z2].setTransparency(0.3);
        }
        Player2[i_second_side][j_second_side][k_second_side].setTransparency(0.5);
        if (Player2[i_second_side][j_second_side][k_second_side].getHit() == 3)
            Player2[i_second_side][j_second_side][k_second_side].setColor(255 / 255., 105 / 255.,
                                                                          60 / 255.);
        else if (Player2[i_second_side][j_second_side][k_second_side].getHit() == 4)
            Player2[i_second_side][j_second_side][k_second_side].setColor(1, 0, 0);
        else Player2[i_second_side][j_second_side][k_second_side].setColor(1, 1, 0);
    }
}

void twoForEnter1Third()
{
    if (isPlayer1)
    {
        /*choose_third_side_Player1(r_rotate_x, r_rotate_y);
        for (int i = 0; i <= LengthBigCube - 1; i++)
        {
            if (Player1[x3][y3][i].getHit() <= 2)
                Player1[x3][y3][i].setColor(1, 1, 0);
            else
            {
                Player1[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                Player1[x3][y3][i].setRed(true);
                Player1[x3][y3][i].setTransparency(1);
            }
            Player1[x2][y3][i].setTransparency(0.3);
        }
        Player1[i_third_side][j_third_side][k_third_side].setTransparency(0.5);
        if (Player1[i_third_side][j_third_side][k_third_side].getHit() == 3)
            Player1[i_third_side][j_third_side][k_third_side].setColor(255 / 255., 105 / 255., 60 / 255.);
        else if (Player1[i_third_side][j_third_side][k_third_side].getHit() == 4)
            Player1[i_third_side][j_third_side][k_third_side].setColor(1, 0, 0);
        else Player1[i_third_side][j_third_side][k_third_side].setColor(1, 1, 0);*/
    } else
    {
        choose_third_side_Player2(r_rotate_x, r_rotate_y);
        for (int i = 0; i <= LengthBigCube - 1; i++)
        {
            if (Player2[x3][y3][i].getHit() <= 2)
                Player2[x3][y3][i].setColor(1, 1, 0);
            else
            {
                Player2[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                Player2[x3][y3][i].setRed(true);
                Player2[x3][y3][i].setTransparency(1);
            }
            Player2[x2][y3][i].setTransparency(0.3);
        }
        Player2[i_third_side][j_third_side][k_third_side].setTransparency(0.5);
        if (Player2[i_third_side][j_third_side][k_third_side].getHit() == 3)
            Player2[i_third_side][j_third_side][k_third_side].setColor(255 / 255., 105 / 255., 60 / 255.);
        else if (Player2[i_third_side][j_third_side][k_third_side].getHit() == 4)
            Player2[i_third_side][j_third_side][k_third_side].setColor(1, 0, 0);
        else Player2[i_third_side][j_third_side][k_third_side].setColor(1, 1, 0);
    }
}

#endif //INC_3DSEEBUTTLE_TWOPLAYERSENTER1_H
