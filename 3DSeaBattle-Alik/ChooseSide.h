//
// Created by xaero on 17.03.2020.
//

#ifndef INC_3DSEEBUTTLE_CHOOSESIDE_H
#define INC_3DSEEBUTTLE_CHOOSESIDE_H

#include "Cube.h"
#include "Painting.h"

void choose_first_side(double &rotateX, double &rotateY)
{

    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (int k = 0; k < LengthBigCube; k++)
        {
            if (a[LengthBigCube - 1][j][k].getHit() == 1)
            {
                a[LengthBigCube - 1][j][k].setColor(0, 1, 0);
            }

            a[LengthBigCube - 1][j][k].setColor(0, 0, 1);
            a[LengthBigCube - 1][j][k].setTransparency(0.11);

        }

    rotateX = 325;
    rotateY = 135;
}

void choose_first_side_Player1(double &rotateX, double &rotateY)
{

    for (auto &i : Player1)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (int k = 0; k < LengthBigCube; k++)
        {
            Player1[LengthBigCube - 1][j][k].setColor(0, 0, 1);
            Player1[LengthBigCube - 1][j][k].setTransparency(0.11);

        }
}

void choose_first_side_Player2(double &rotateX, double &rotateY)
{

    for (auto &i : Player2)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (int k = 0; k < LengthBigCube; k++)
        {
            Player2[LengthBigCube - 1][j][k].setColor(0, 0, 1);
            Player2[LengthBigCube - 1][j][k].setTransparency(0.11);

        }
}

void choose_second_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (auto &j : a)
        for (int k = 0; k < LengthBigCube; k++)
        {
            if (j[LengthBigCube - 1][k].getHit() == 1)
            {
                j[LengthBigCube - 1][k].setColor(0, 1, 0);
            }

            j[LengthBigCube - 1][k].setColor(0, 0, 1);
            j[LengthBigCube - 1][k].setTransparency(0.11);
        }
    rotateX = 325;
    rotateY = 135;
}

void choose_second_side_Player1(double &rotateX, double &rotateY)
{
    for (auto &i : Player1)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (auto &j : Player1)
        for (int k = 0; k < LengthBigCube; k++)
        {
            j[LengthBigCube - 1][k].setColor(0, 0, 1);
            j[LengthBigCube - 1][k].setTransparency(0.11);
        }
}

void choose_second_side_Player2(double &rotateX, double &rotateY)
{
    for (auto &i : Player2)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (auto &j : Player2)
        for (int k = 0; k < LengthBigCube; k++)
        {
            j[LengthBigCube - 1][k].setColor(0, 0, 1);
            j[LengthBigCube - 1][k].setTransparency(0.11);
        }
}

void choose_third_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (auto &k : a)
        {
            k[j][LengthBigCube - 1].setColor(0, 0, 1);
            k[j][LengthBigCube - 1].setTransparency(0.11);
        }

    rotateX = 325;
    rotateY = 135;
}

void choose_third_side_Player1(double &rotateX, double &rotateY)
{
    for (auto &i : Player1)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (auto &k : Player1)
        {
            k[j][LengthBigCube - 1].setColor(0, 0, 1);
            k[j][LengthBigCube - 1].setTransparency(0.11);
        }
}

void choose_third_side_Player2(double &rotateX, double &rotateY)
{
    for (auto &i : Player2)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (auto &k : Player2)
        {
            k[j][LengthBigCube - 1].setColor(0, 0, 1);
            k[j][LengthBigCube - 1].setTransparency(0.11);
        }
}

void default_position(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
                k.setColor(0.5, 0.5, 0.8);
                k.setTransparency(0.11);
            }

    rotateX = 325;
    rotateY = 135;
}

void view_first_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (int k = 0; k < LengthBigCube; k++)
        {
            a[LengthBigCube - 1][j][k].setColor(0, 0, 1);
        }

    rotateX = 325;
    rotateY = 135;
}

void view_first_side_Player1(double &rotateX, double &rotateY)
{
    for (auto &i : Player1)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (int k = 0; k < LengthBigCube; k++)
        {
            Player1[LengthBigCube - 1][j][k].setColor(0, 0, 1);
        }

    rotateX = 325;
    rotateY = 135;
}

void view_first_side_Player2(double &rotateX, double &rotateY)
{
    for (auto &i : Player2)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (int k = 0; k < LengthBigCube; k++)
        {
            Player2[LengthBigCube - 1][j][k].setColor(0, 0, 1);
        }

    rotateX = 325;
    rotateY = 135;
}

void view_second_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (auto &j : a)
        for (int k = 0; k < LengthBigCube; k++)
        {
            j[LengthBigCube - 1][k].setColor(0, 0, 1);
        }

    rotateX = 325;
    rotateY = 135;
}

void view_second_side_Player1(double &rotateX, double &rotateY)
{
    for (auto &i : Player1)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (auto &j : Player1)
        for (int k = 0; k < LengthBigCube; k++)
        {
            j[LengthBigCube - 1][k].setColor(0, 0, 1);
        }

    rotateX = 325;
    rotateY = 135;
}

void view_second_side_Player2(double &rotateX, double &rotateY)
{
    for (auto &i : Player2)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (auto &j : Player2)
        for (int k = 0; k < LengthBigCube; k++)
        {
            j[LengthBigCube - 1][k].setColor(0, 0, 1);
        }

    rotateX = 325;
    rotateY = 135;
}

void view_third_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (auto &k : a)
        {
            k[j][LengthBigCube - 1].setColor(0, 0, 1);
        }

    rotateX = 325;
    rotateY = 135;
}

void view_third_side_Player1(double &rotateX, double &rotateY)
{
    for (auto &i : Player1)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (auto &k : Player1)
        {
            k[j][LengthBigCube - 1].setColor(0, 0, 1);
        }

    rotateX = 325;
    rotateY = 135;
}

void view_third_side_Player2(double &rotateX, double &rotateY)
{
    for (auto &i : Player2)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }

    for (int j = 0; j < LengthBigCube; j++)
        for (auto &k : Player2)
        {
            k[j][LengthBigCube - 1].setColor(0, 0, 1);
        }

    rotateX = 325;
    rotateY = 135;
}

#endif //INC_3DSEEBUTTLE_CHOOSESIDE_H

