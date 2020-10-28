//
// Created by alik on 13.05.2020.
//

#ifndef INC_3DSEEBUTTLE_DISPLAYCUBES_H
#define INC_3DSEEBUTTLE_DISPLAYCUBES_H
#include "Cube.h"
#include "client.h"

double rotate_y = 135;  //начальный поворот куба по у
double rotate_x = -35; //начальный поворот куба по х

bool forCubeA = true;
bool help = false;          // Help доступна всегда нажатием F1. Но информация для каждого случая своя:

Cube a[10][10][10];
Cube Player1[10][10][10];
Cube Player2[10][10][10];

void twoBigCubes()
{
    if (forOnePaint == 0 && (forEnter == 0 && forTwoPlayers != 2))
    {
        for (int i = 0; i < LengthBigCube; i++)
            for (int j = 0; j < LengthBigCube; j++)
                for (int k = 0; k < LengthBigCube; k++)
                {
                    Player1[i][j][k] = Cube(1.1 / (LengthBigCube),
                                            i * 1.1 / LengthBigCube -
                                            LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube,
                                            j * 1.1 / LengthBigCube -
                                            LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube,
                                            k * 1.1 / LengthBigCube -
                                            LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube, 0.11);

                    Player1[i][j][k].setColor(135 / 256., 206 / 256., 250 / 256.);
                    Player2[i][j][k] = Cube(1.1 / (LengthBigCube),
                                            i * 1.1 / LengthBigCube -
                                            LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube,
                                            j * 1.1 / LengthBigCube -
                                            LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube,
                                            k * 1.1 / LengthBigCube -
                                            LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube, 0.11);

                    Player2[i][j][k].setColor(10 / 256., 254 / 256., 189 / 256.);
                    forOnePaint = 1;
                    forCubeA = true;
                }
    }

    if (forOnePaint == 0 && (forEnter == -1 || forTwoPlayers == 2))
    {
        for (int i = 0; i < LengthBigCube; i++)
            for (int j = 0; j < LengthBigCube; j++)
                for (int k = 0; k < LengthBigCube; k++)
                {
                    Player1[i][j][k].changeCube(1.1 / (LengthBigCube * 1.4),
                                                i * 1.1 / (LengthBigCube * 1.4) - 0.55 +
                                                0.55 / (LengthBigCube * 1.4) +
                                                0.6,
                                                j * 1.1 / (LengthBigCube * 1.4) - 0.55 +
                                                0.55 / (LengthBigCube * 1.4) +
                                                0.15,
                                                k * 1.1 / (LengthBigCube * 1.4) - 0.55 +
                                                0.55 / (LengthBigCube * 1.4) -
                                                0.35,
                                                0.11);

                    Player2[i][j][k].changeCube(1.1 / (LengthBigCube * 1.4),
                                                i * 1.1 / (LengthBigCube * 1.4) - 0.55 +
                                                0.55 / (LengthBigCube * 1.4) -
                                                0.25,
                                                j * 1.1 / (LengthBigCube * 1.4) - 0.55 +
                                                0.55 / (LengthBigCube * 1.4) +
                                                0.28,
                                                k * 1.1 / (LengthBigCube * 1.4) - 0.55 +
                                                0.55 / (LengthBigCube * 1.4) +
                                                0.785,
                                                0.11);
                    if (forTwoPlayers == 2 || forTwoPlayers == 0)
                    {
                        Player1[i][j][k].setColor(135 / 256., 206 / 256., 250 / 256.);
                        Player2[i][j][k].setColor(10 / 256., 254 / 256., 189 / 256.);
                    }
                    forOnePaint = 1;
                }
    }
    if (forEnter == -1 || forTwoPlayers == 2)
        for (auto &i : Player2)
            for (auto &j : i)
                for (auto &k : j)
                {
                    if (space && k.getHit() == 3)
                    {
                        k.setPaint(false);
                    } else if (!space && k.getHit() == 3)
                        k.setPaint(true);
                    if (k.getHit() == 3 && !k.getRed())
                    {
                        k.setColor(0, 0, 1);
                        k.setTransparency(0.15);
                    }
                    if (k.getHit() == 4 && !k.getRed())
                    {
                        k.setColor(1, 0, 0);
                        k.setTransparency(0.35);
                    }
                    if (k.getPaint())
                    {
                        k.paintCube();
                        k.setTransparancyNothing();
                    }
                }

    if (forEnter == -1 || forTwoPlayers == 2)
        for (auto &i : Player1)
            for (auto &j : i)
                for (auto &k : j)
                {
                    if (space && k.getHit() == 3)
                    {
                        k.setPaint(false);
                    } else if (!space && k.getHit() == 3)
                        k.setPaint(true);

                    if (k.getHit() == 3 && !k.getRed())
                    {
                        k.setColor(0, 0, 1);
                        k.setTransparency(0.15);
                    }
                    if (k.getHit() == 4 && !k.getRed())
                    {
                        k.setColor(1, 0, 0);
                        k.setTransparency(0.4);
                    }
                    if (k.getPaint())
                    {
                        k.paintCube();
                        k.setTransparancyNothing();
                    }
                }


    if (isPlayer1 && forTwoPlayers == 2)
    {
        glBegin(GL_TRIANGLES);
        glColor4f(1,0,0, 0.7);// Сделали боковую сторону фиолетовой

        glVertex3f( 0.05, -0.05,-0.01);
        glVertex3f(-0.1, 0.05,0.1);
        glVertex3f(-0.1, -0.1, 0.1);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor4f(1,0,0, 0.7); // Сделали боковую сторону желтой

        glVertex3f( 0.05, -0.05,-0.01);
        glVertex3f(-0.1, 0.05,0.1);
        glVertex3f(0.1,-0.05,0.2);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor4f(1,0,0, 0.7);// Сделали сторону  розовой

        glVertex3f(0.05, -0.05,-0.01);
        glVertex3f(0.1,-0.05,0.2);
        glVertex3f(-0.1, -0.1, 0.1);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor4f(1,0,0, 0.7);  // Сделали сторону  светло зеленой

        glVertex3f(-0.1, -0.1, 0.1);
        glVertex3f(0.1,-0.05,0.2);
        glVertex3f(-0.1, 0.05,0.1);
        glEnd();
    } else if (!isPlayer1 && forTwoPlayers == 2)
    {
        glBegin(GL_TRIANGLES);
        glColor4f(0,1,0, 0.7);// Сделали боковую сторону фиолетовой

        glVertex3f( 0, -0.05,0.2);
        glVertex3f(0.05, 0.05,0.05);
        glVertex3f(0.1, -0.1, 0.05);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor4f(0, 1, 0, 0.7); // Сделали боковую сторону желтой

        glVertex3f( 0, -0.05,0.2);
        glVertex3f(0.05, 0.05,0.05);
        glVertex3f(-0.08, -0.11,0.05);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor4f(0, 1, 0, 0.7);// Сделали сторону  розовой

        glVertex3f(0.1, -0.1, 0.05);
        glVertex3f(0, -0.05,0.2);
        glVertex3f(-0.08, -0.11,0.05);
        glEnd();
    }

}

void oneBigCube()
{
    if (forCubeA && forTwoPlayers < 2)
    {
        for (int i = 0; i < LengthBigCube; i++)
            for (int j = 0; j < LengthBigCube; j++)
                for (int k = 0; k < LengthBigCube; k++)
                {
                    if (isPlayer1)
                        a[i][j][k] = &Player1[i][j][k];
                    else a[i][j][k] = &Player2[i][j][k];
                    forCubeA = false;
                }
    }
    if (forTwoPlayers < 2)
        for (auto &i : a)
            for (auto &j : i)
                for (auto &k : j)
                {
                    if (forEnter > 3 && k.getHit() == 2)
                        k.setPaint(false);
                    if (k.getHit() == 1 && !k.getRed())
                    {
                        k.setColor(0, 1, 0); // выбранные корабли закрашиваем зеленым
                    }

                    if (k.getPaint() && !help)
                    {
                        k.paintCube();
                        if (forEnter != -1 && k.getHit() != 1)
                            k.setTransparancyNothing();
                    }

                }
}

#endif //INC_3DSEEBUTTLE_DISPLAYCUBES_H
