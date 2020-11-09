//
// Created by alik on 13.05.2020.
//

#ifndef INC_3DSEEBUTTLE_FORENTER5_TWOCUBES_H
#define INC_3DSEEBUTTLE_FORENTER5_TWOCUBES_H

#include "hitSide_Player1.h"
#include "hitSide_Player2.h"
#include <chrono>


void forEnter5FunctionTwo()
{
    if (isPlayer1)
    {
        /*if (firstSide && (Player1[p1][yf][z1].getHit() == 0 || Player1[p1][yf][z1].getHit() == 2))
        {

            for (auto &i : Player1)
            {
                i[yf][z1].setColor(0.5, 0.5, 0.8);
                i[yf][z1].setTransparency(0.11);
            }

            Player1[p1][yf][z1].setColor(0, 0, 1);
            Player1[p1][yf][z1].setTransparency(0.35);
            Player1[p1][yf][z1].setIsHitten(3);
            isPlayer1 = false;

        } else if (firstSide && Player1[p1][yf][z1].getHit() == 1)
        {
            for (auto &i : Player1)
            {
                i[yf][z1].setColor(0.5, 0.5, 0.8);
                i[yf][z1].setTransparency(0.11);
            }

            Player1[p1][yf][z1].setColor(1, 0, 0);
            Player1[p1][yf][z1].setTransparency(0.35);
            Player1[p1][yf][z1].setIsHitten(4);

            bool hit = true;
            if (p1 - 1 >= 0)
                if (Player1[p1 - 1][yf][z1].getHit() == 1)
                    hit = false;
            if (p1 + 1 < LengthBigCube)
                if (Player1[p1 + 1][yf][z1].getHit() == 1)
                    hit = false;
            if (yf - 1 >= 0)
                if (Player1[p1][yf - 1][z1].getHit() == 1)
                    hit = false;
            if (yf + 1 < LengthBigCube)
                if (Player1[p1][yf + 1][z1].getHit() == 1)
                    hit = false;
            if (z1 - 1 >= 0)
                if (Player1[p1][yf][z1 - 1].getHit() == 1)
                    hit = false;
            if (z1 + 1 < LengthBigCube)
                if (Player1[p1][yf][z1 + 1].getHit() == 1)
                    hit = false;

            if (hit)
            {
                hitFirstSide1();
            }
            if (shipsLifeFirst == 0)
                end1 = true;
        } else if (secondSide && (Player1[x2][p2][z2].getHit() == 0 || Player1[x2][p2][z2].getHit() == 2))
        {
            for (int j = 0; j < LengthBigCube; j++)
            {
                Player1[x2][j][z2].setColor(0.5, 0.5, 0.8);
                Player1[x2][j][z2].setTransparency(0.11);
            }
            Player1[x2][p2][z2].setColor(0, 0, 1);
            Player1[x2][p2][z2].setTransparency(0.35);
            Player1[x2][p2][z2].setIsHitten(3);
            isPlayer1 = false;

        } else if (secondSide && Player1[x2][p2][z2].getHit() == 1)
        {
            for (int j = 0; j < LengthBigCube; j++)
            {
                Player1[x2][j][z2].setColor(0.5, 0.5, 0.8);
                Player1[x2][j][z2].setTransparency(0.11);
            }

            Player1[x2][p2][z2].setColor(1, 0, 0);
            Player1[x2][p2][z2].setTransparency(0.35);
            Player1[x2][p2][z2].setIsHitten(4);

            bool hit = true;
            if (x2 - 1 >= 0)
                if (Player1[x2 - 1][p2][z2].getHit() == 1)
                    hit = false;
            if (x2 + 1 < LengthBigCube)
                if (Player1[x2 + 1][p2][z2].getHit() == 1)
                    hit = false;
            if (p2 - 1 >= 0)
                if (Player1[x2][p2 - 1][z2].getHit() == 1)
                    hit = false;
            if (p2 + 1 < LengthBigCube)
                if (Player1[x2][p2 + 1][z2].getHit() == 1)
                    hit = false;
            if (z2 - 1 >= 0)
                if (Player1[x2][p2][z2 - 1].getHit() == 1)
                    hit = false;
            if (z2 + 1 < LengthBigCube)
                if (Player1[x2][p2][z2 + 1].getHit() == 1)
                    hit = false;

            if (hit)
            {
                hitSecondSide1();
            }
            if (shipsLifeFirst == 0)
                end1 = true;
        } else if (thirdSide && (Player1[x3][y3][p3].getHit() == 0 || Player1[x3][y3][p3].getHit() == 2))
        {
            for (int k = 0; k < LengthBigCube; k++)
            {
                Player1[x3][y3][k].setColor(0.5, 0.5, 0.8);
                Player1[x3][y3][k].setTransparency(0.11);
            }
            Player1[x3][y3][p3].setColor(0, 0, 1);
            Player1[x3][y3][p3].setTransparency(0.35);
            Player1[x3][y3][p3].setIsHitten(3);
            isPlayer1 = false;
        } else if (thirdSide && Player1[x3][y3][p3].getHit() == 1)
        {
            for (int j = 0; j < LengthBigCube; j++)
            {
                Player1[x3][j][p3].setColor(0.5, 0.5, 0.8);
                Player1[x3][j][p3].setTransparency(0.11);
            }

            Player1[x3][y3][p3].setColor(1, 0, 0);
            Player1[x3][y3][p3].setTransparency(0.35);
            Player1[x3][y3][p3].setIsHitten(4);

            bool hit = true;
            if (x3 - 1 >= 0)
                if (Player1[x3 - 1][y3][p3].getHit() == 1)
                    hit = false;
            if (x3 + 1 < LengthBigCube)
                if (Player1[x3 + 1][y3][p3].getHit() == 1)
                    hit = false;
            if (y3 - 1 >= 0)
                if (Player1[x3][y3 - 1][p3].getHit() == 1)
                    hit = false;
            if (y3 + 1 < LengthBigCube)
                if (Player1[x3][y3 + 1][p3].getHit() == 1)
                    hit = false;
            if (p3 - 1 >= 0)
                if (Player1[x3][y3][p3 - 1].getHit() == 1)
                    hit = false;
            if (p3 + 1 < LengthBigCube)
                if (Player1[x3][y3][p3 + 1].getHit() == 1)
                    hit = false;

            if (hit)
            {
                hitThirdSide1();
            }
            if (shipsLifeFirst == 0)
                end1 = true;
        }*/
        forEnter = 0;

    } else
    {
        if (firstSide)
        {
            std::cout << "отсылаем на сервер (1Side) " << std::to_string(p1) + " " + std::to_string(yf) + " " + std::to_string(z1) << std::endl;
            sendServ(s, "fire " + std::to_string(p1) + " " + std::to_string(yf) + " " + std::to_string(z1));
            std::string answer = readServ(s);
            //std::cout << std::endl << "данные от сервера начальные: " << answer;
            if (answer != "yes" && answer != "no" && answer != "kill" && answer != "win" && answer != "again")
            {
                answer = readServ(s);
                std::cout << "Переполучение данных\n";
            }
            if (answer == "yes")   // если попали, но не убили
            {
                for (auto &i : Player2)
                {
                    i[yf][z1].setColor(0.5, 0.5, 0.8);
                    i[yf][z1].setTransparency(0.11);
                }

                Player2[p1][yf][z1].setColor(1, 0, 0);
                Player2[p1][yf][z1].setTransparency(0.35);
                Player2[p1][yf][z1].setIsHitten(4);

            }
            else if (answer == "no")   // если промахнулись
            {
                for (auto &i : Player2)
                {
                    i[yf][z1].setColor(0.5, 0.5, 0.8);
                    i[yf][z1].setTransparency(0.11);
                }

                Player2[p1][yf][z1].setColor(0, 0, 1);
                Player2[p1][yf][z1].setTransparency(0.35);
                Player2[p1][yf][z1].setIsHitten(3);
                isPlayer1 = true;
            }
            else if (answer == "kill")   // если попали, но не убили
            {
                for (auto &i : Player2)
                {
                    i[yf][z1].setColor(0.5, 0.5, 0.8);
                    i[yf][z1].setTransparency(0.11);
                }

                Player2[p1][yf][z1].setColor(1, 0, 0);
                Player2[p1][yf][z1].setTransparency(0.35);
                Player2[p1][yf][z1].setIsHitten(4);
                hitFirstSide2();
            }
            else if (answer == "win")   // если попали, но не убили
            {
               end2 = true;
            }
            else if (answer == "again")   // если стреляли по той же клетке
            {
                glClearColor(0.5, 0, 0, 0.f);
                red_time = get_time();
                for (auto &i : Player2)
                {
                    i[yf][z1].setColor(0.5, 0.5, 0.8);
                    i[yf][z1].setTransparency(0.11);
                }
                if (Player2[p1][yf][z1].getHit() == 3)
                {
                    Player2[p1][yf][z1].setColor(0, 0, 1);
                    Player2[p1][yf][z1].setTransparency(0.35);
                }
                else
                {
                    Player2[p1][yf][z1].setColor(1, 0, 0);
                    Player2[p1][yf][z1].setTransparency(0.35);
                }
            }
            else
            {
                std::cout << "Неверные данные при получение ответа на выстрел (сторона 1)" << std::endl << answer;
                answer = readServ(s);
                std::cout << std::endl << "новые данные: " << answer;
            }


        } /*else if (firstSide && Player2[p1][yf][z1].getHit() == 1)
        {

            bool hit = true;
            if (p1 - 1 >= 0)
                if (Player2[p1 - 1][yf][z1].getHit() == 1)
                    hit = false;
            if (p1 + 1 < LengthBigCube)
                if (Player2[p1 + 1][yf][z1].getHit() == 1)
                    hit = false;
            if (yf - 1 >= 0)
                if (Player2[p1][yf - 1][z1].getHit() == 1)
                    hit = false;
            if (yf + 1 < LengthBigCube)
                if (Player2[p1][yf + 1][z1].getHit() == 1)
                    hit = false;
            if (z1 - 1 >= 0)
                if (Player2[p1][yf][z1 - 1].getHit() == 1)
                    hit = false;
            if (z1 + 1 < LengthBigCube)
                if (Player2[p1][yf][z1 + 1].getHit() == 1)
                    hit = false;

            if (hit)
            {
                hitFirstSide2();
            }
            if (shipsLifeSecond == 0)
                end2 = true;*/
        else if (secondSide)
        {
            std::cout << "отсылаем на сервер(2Side) " << std::to_string(x2) + " " + std::to_string(p2) + " " + std::to_string(z2) << std::endl;
            sendServ(s, "fire " + std::to_string(x2) + " " + std::to_string(p2) + " " + std::to_string(z2));
            std::string answer = readServ(s);
            std::cout << "получили от сервера (2Side) "  << answer << std::endl;
            //std::cout << std::endl << "данные от сервера начальные: " << answer;

            if (answer != "yes" && answer != "no" && answer != "kill" && answer != "win" && answer != "again")
            {
                answer = readServ(s);
                std::cout << "Переполучение данных\n";
            } else
            if (answer == "yes")   // если попали, но не убили
            {
                for (int j = 0; j < LengthBigCube; j++)
                {
                    Player2[x2][j][z2].setColor(0.5, 0.5, 0.8);
                    Player2[x2][j][z2].setTransparency(0.11);
                }

                Player2[x2][p2][z2].setColor(1, 0, 0);
                Player2[x2][p2][z2].setTransparency(0.35);
                Player2[x2][p2][z2].setIsHitten(4);
            }
            else if (answer == "no")   // если промахнулись
            {
                for (int j = 0; j < LengthBigCube; j++)
                {
                    Player2[x2][j][z2].setColor(0.5, 0.5, 0.8);
                    Player2[x2][j][z2].setTransparency(0.11);
                }
                Player2[x2][p2][z2].setColor(0, 0, 1);
                Player2[x2][p2][z2].setTransparency(0.35);
                Player2[x2][p2][z2].setIsHitten(3);
                isPlayer1 = true;
            } else
            if (answer == "kill")   // если попали, но не убили
            {
                for (int j = 0; j < LengthBigCube; j++)
                {
                    Player2[x2][j][z2].setColor(0.5, 0.5, 0.8);
                    Player2[x2][j][z2].setTransparency(0.11);
                }

                Player2[x2][p2][z2].setColor(1, 0, 0);
                Player2[x2][p2][z2].setTransparency(0.35);
                Player2[x2][p2][z2].setIsHitten(4);
                hitSecondSide2();
            } else
            if (answer == "win")   // если попали, но не убили
            {
                end2 = true;
            }
            else if (answer == "again")   // если стреляли по той же клетке
            {
                glClearColor(0.5, 0, 0, 0.f);
                red_time = get_time();
                for (int j = 0; j < LengthBigCube; j++)
                {
                    Player2[x2][j][z2].setColor(0.5, 0.5, 0.8);
                    Player2[x2][j][z2].setTransparency(0.11);
                }
                if (Player2[x2][p2][z2].getHit() == 3)
                {
                    Player2[x2][p2][z2].setColor(0, 0, 1);
                    Player2[x2][p2][z2].setTransparency(0.35);
                }
                else
                {
                    Player2[x2][p2][z2].setColor(1, 0, 0);
                    Player2[x2][p2][z2].setTransparency(0.35);
                }
            }
            else
                std::cout << "Неверные данные при получение ответа на выстрел (сторона 2) " << answer << std::endl;

        /*} else if (secondSide && Player2[x2][p2][z2].getHit() == 1)
        {


            bool hit = true;
            if (x2 - 1 >= 0)
                if (Player2[x2 - 1][p2][z2].getHit() == 1)
                    hit = false;
            if (x2 + 1 < LengthBigCube)
                if (Player2[x2 + 1][p2][z2].getHit() == 1)
                    hit = false;
            if (p2 - 1 >= 0)
                if (Player2[x2][p2 - 1][z2].getHit() == 1)
                    hit = false;
            if (p2 + 1 < LengthBigCube)
                if (Player2[x2][p2 + 1][z2].getHit() == 1)
                    hit = false;
            if (z2 - 1 >= 0)
                if (Player2[x2][p2][z2 - 1].getHit() == 1)
                    hit = false;
            if (z2 + 1 < LengthBigCube)
                if (Player2[x2][p2][z2 + 1].getHit() == 1)
                    hit = false;

            if (hit)
            {
                hitSecondSide2();
            }
            if (shipsLifeSecond == 0)
                end2 = true;
                */
        } else if (thirdSide)
        {
            std::cout << "отсылаем на сервер(3Side) " <<  std::to_string(x3) + " " + std::to_string(y3) + " " + std::to_string(p3) << std::endl;
            sendServ(s, "fire " + std::to_string(x3) + " " + std::to_string(y3) + " " + std::to_string(p3));
            std::string answer = readServ(s);
            std::cout << "получили от сервера (3Side) "  << answer << std::endl;
            //std::cout << std::endl << "данные от сервера начальные: " << answer;

            if (answer != "yes" && answer != "no" && answer != "kill" && answer != "win" && answer != "again")
            {
                answer = readServ(s);
                std::cout << "Переполучение данных\n";
            } else
            if (answer == "yes")   // если попали, но не убили
            {
                for (int k = 0; k < LengthBigCube; k++) {
                    Player2[x3][y3][k].setColor(0.5, 0.5, 0.8);
                    Player2[x3][y3][k].setTransparency(0.11);
                }

                Player2[x3][y3][p3].setColor(1, 0, 0);
                Player2[x3][y3][p3].setTransparency(0.35);
                Player2[x3][y3][p3].setIsHitten(4);
            } else if (answer == "no")   // если промахнулись
            {
                for (int k = 0; k < LengthBigCube; k++) {
                    Player2[x3][y3][k].setColor(0.5, 0.5, 0.8);
                    Player2[x3][y3][k].setTransparency(0.11);
                }
                Player2[x3][y3][p3].setColor(0, 0, 1);
                Player2[x3][y3][p3].setTransparency(0.35);
                Player2[x3][y3][p3].setIsHitten(3);
                isPlayer1 = true;
            } else
            if (answer == "kill")   // если попали, но не убили
            {
                for (int k = 0; k < LengthBigCube; k++) {
                    Player2[x3][y3][k].setColor(0.5, 0.5, 0.8);
                    Player2[x3][y3][k].setTransparency(0.11);
                }

                Player2[x3][y3][p3].setColor(1, 0, 0);
                Player2[x3][y3][p3].setTransparency(0.35);
                Player2[x3][y3][p3].setIsHitten(4);
                hitThirdSide2();
            } else
            if (answer == "win")   // если попали, но не убили
            {
                end2 = true;
            }
            else if (answer == "again")   // если стреляли по той же клетке
            {
                glClearColor(0.5, 0, 0, 0.f);
                red_time = get_time();
                for (int k = 0; k < LengthBigCube; k++) {
                    Player2[x3][y3][k].setColor(0.5, 0.5, 0.8);
                    Player2[x3][y3][k].setTransparency(0.11);
                }
                if (Player2[x3][y3][p3].getHit() == 3)
                {
                    Player2[x3][y3][p3].setColor(0, 0, 1);
                    Player2[x3][y3][p3].setTransparency(0.35);
                }
                else
                {
                    Player2[x3][y3][p3].setColor(1, 0, 0);
                    Player2[x3][y3][p3].setTransparency(0.35);
                }
            }
            else
                std::cout << "Неверные данные при получение ответа на выстрел (сторона 3)";
            /*} else if (thirdSide && Player2[x3][y3][p3].getHit() == 1)
            {


                bool hit = true;
                if (x3 - 1 >= 0)
                    if (Player2[x3 - 1][y3][p3].getHit() == 1)
                        hit = false;
                if (x3 + 1 < LengthBigCube)
                    if (Player2[x3 + 1][y3][p3].getHit() == 1)
                        hit = false;
                if (y3 - 1 >= 0)
                    if (Player2[x3][y3 - 1][p3].getHit() == 1)
                        hit = false;
                if (y3 + 1 < LengthBigCube)
                    if (Player2[x3][y3 + 1][p3].getHit() == 1)
                        hit = false;
                if (p3 - 1 >= 0)
                    if (Player2[x3][y3][p3 - 1].getHit() == 1)
                        hit = false;
                if (p3 + 1 < LengthBigCube)
                    if (Player2[x3][y3][p3 + 1].getHit() == 1)
                        hit = false;

                if (hit)
                {
                    hitThirdSide2();
                }

                if (shipsLifeSecond == 0)
                    end2 = true;
            }*/
        }
            ///тут мы отсылаем данные на свервер с выстрелом, и окрашиваем кубики
            ///написать отправку данных на сервер

    }

    for (auto &i : Player1)
        for (auto &t : i)
            for (auto &k : t)
                k.setRed(false);

    for (auto &i : Player2)
        for (auto &t : i)
            for (auto &k : t)
                k.setRed(false);

    forEnter = 0;
    p1 = 0;
    yf = 0;
    z1 = 0;
    x2 = LengthBigCube - 1;
    p2 = 0;
    z2 = LengthBigCube - 1;
    x3 = LengthBigCube - 1;
    y3 = 0;
    p3 = 0;

}

#endif //INC_3DSEEBUTTLE_FORENTER5_TWOCUBES_H
