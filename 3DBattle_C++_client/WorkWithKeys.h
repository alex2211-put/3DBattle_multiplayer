//
// Created by xaero on 17.03.2020.
//

#ifndef INC_3DSEEBUTTLE_WORKWITHKEYS_H
#define INC_3DSEEBUTTLE_WORKWITHKEYS_H

#include "ChooseSide.h"
#include "forEnter1.h"
#include "forEnter3.h"
#include "forEnter5_OneCube.h"
#include "forEnter5_TwoCubes.h"
#include "ChooseCube.h"
#include "ChooseColumn.h"
namespace fs = std::filesystem;
std::string filename = ".source.txt";

//функция взаимодействия с клавиатурой
void Keyboard(unsigned char key, int x, int y)
{
    if ((key == 13) && (mainmenu))
    {
        mainmenu = false;
        if (menupuncts[0])
        {
            menupuncts[0] = false;
            if (tileschange)
                bot_player_window = true;
            tileschange = false;
        } else
        {
            if (menupuncts[1])
            {
                mainmenu = true;
            } else {
            if (menupuncts[2])
            {
                rules = true;
                menupuncts[2] = false;
            } else {
                if (menupuncts[3]) {
                    authors = true;
                    menupuncts[3] = false;
                } else {
                    sendServ(s, "end");
                    close(s);
                    fs::remove_all(filename);
                    exit(0);
                }
            }
            }
        }
    }
    else if (key == 13 && bot_player_window)
    {
        bot_player_window = false;
        placing_ships = true;
        if (pot_player_puncts[0])
            bot = false;
        else bot = true;
    }
    if(key == 13 && (end1 || end2 || end3))
    {
        close(s);
        fs::remove_all(filename);
        exit(0);
    }

    if (key == 27)
    {
        mainmenu = true;
        rules = false;
        authors = false;
        help = false;
        placing_ships = false;
        forEnter = 0;
    }

    if (key == 13 && forEnter == -1)
    {
        forEnter = 0;
        forOnePaint = 0;
    }

    if (key == 32)
        space = !space;

    if (key == 13 && forEnter == 1)
    {
        forEnter1Function();
    }

    else if (key == 13 && forEnter == 3)
    {
        forEnter3Function();
    }

    else if (key == 13 && forEnter == 5 && forTwoPlayers < 2)
    {//FIRE!!! (типа пыжь пыжь и все покраснело)
        forEnter5FunctionOne();
    }

    else if (key == 13 && forEnter == 5 && forTwoPlayers == 2)
    {//FIRE!!! (типа пыжь пыжь и все покраснело)
        forEnter5FunctionTwo();
    }

    if (key == 27)
    {
        movement = true;
        forEnter--;
        if (forEnter < 0)
            forEnter = 0;
        default_position(r_rotate_x, r_rotate_y
        );
        firstSide = false;
        secondSide = false;
        thirdSide = false;
    }

    glutPostRedisplay(); //а это просто обязательная функция
}

// 1 == left, 2 == up, 3 == down, 4 == right
void specialKeys(int key, int x, int y)
{
    if (mainmenu) {
        if (key == GLUT_KEY_DOWN) {
            menupuncts[carrier] = false;
            if (carrier < 4) {
                carrier++;
                menupuncts[carrier] = true;
            } else {
                carrier = 0;
                menupuncts[carrier] = true;
            }
        }
        if (key == GLUT_KEY_UP) {
            menupuncts[carrier] = false;
            if (carrier > 0) {
                carrier--;
                menupuncts[carrier] = true;
            } else {
                carrier = 4;
                menupuncts[carrier] = true;
            }
        }
        if ((key == GLUT_KEY_LEFT) && (tileschange)) {
            if (LengthBigCube > 4) {
                --LengthBigCube;
                --ship;
                i_first_side--;
                i_second_side--;
                j_second_side--;
                k_second_side--;
                i_third_side--;
                k_third_side--;
                yf = j_first_side;
                z1 = k_first_side;
                x2 = i_second_side;
                z2 = k_second_side;
                x3 = i_third_side;
                y3 = j_third_side;
            } else {
                LengthBigCube = 9;
                ship = 7;
                i_first_side = 8;
                i_second_side = 8;
                j_second_side = 8;
                k_second_side = 8;
                i_third_side = 8;
                k_third_side = 8;
                yf = j_first_side;
                z1 = k_first_side;
                x2 = i_second_side;
                z2 = k_second_side;
                x3 = i_third_side;
                y3 = j_third_side;
            }
        }
        if ((key == GLUT_KEY_RIGHT) && (tileschange)) {
            if (LengthBigCube < 9) {
                ++LengthBigCube;
                ++ship;
                i_first_side++;
                i_second_side++;
                j_second_side++;
                k_second_side++;
                i_third_side++;
                k_third_side++;
                yf = j_first_side;
                z1 = k_first_side;
                x2 = i_second_side;
                z2 = k_second_side;
                x3 = i_third_side;
                y3 = j_third_side;
            } else {
                LengthBigCube = 4;
                ship = 2;
                i_first_side = 3;
                i_second_side = 3;
                j_second_side = 3;
                k_second_side = 3;
                i_third_side = 3;
                k_third_side = 3;
                yf = j_first_side;
                z1 = k_first_side;
                x2 = i_second_side;
                z2 = k_second_side;
                x3 = i_third_side;
                y3 = j_third_side;
            }
        }
    } else if (bot_player_window)
    {
        if (key == GLUT_KEY_DOWN) {
            pot_player_puncts[carrier_bot] = false;
            if (carrier_bot < 1) {
                carrier_bot++;
                pot_player_puncts[carrier_bot] = true;
            } else {
                carrier_bot = 0;
                pot_player_puncts[carrier_bot] = true;
            }
        }
        if (key == GLUT_KEY_UP) {
            pot_player_puncts[carrier_bot] = false;
            if (carrier_bot > 0) {
                carrier_bot--;
                pot_player_puncts[carrier_bot] = true;
            } else {
                carrier_bot = 1;
                pot_player_puncts[carrier_bot] = true;
            }
        }
    }
    else {

        if (key == GLUT_KEY_F1) {
            help = (!help);
            //movement = (!movement);
        }

        if (key == GLUT_KEY_RIGHT) {
            if (forEnter == -1) {
                if (isPlayer1) {
                    isPlayer1 = false;
                    for (auto &i : Player1)
                        for (auto &j : i)
                            for (auto &k : j)
                                k.setColor(135 / 256., 206 / 256., 250 / 256.);
                    for (auto &i : Player2)
                        for (auto &j : i)
                            for (auto &k : j)
                                k.setColor(1, 0, 0);
                } else {
                    isPlayer1 = true;
                    for (auto &i : Player2)
                        for (auto &j : i)
                            for (auto &k : j)
                                k.setColor(10 / 256., 254 / 256., 189 / 256.);
                    for (auto &i : Player1)
                        for (auto &j : i)
                            for (auto &k : j)
                                k.setColor(1, 0, 0);
                }
            } else if (movement && forEnter != -1) {
                rotate_y += 5;
            } else
                ChooseColumn(4);
        }//если нажата клавиша "вправо", то поворачиваем

        else if (key == GLUT_KEY_LEFT) {
            if (forEnter == -1) {
                if (isPlayer1) {
                    isPlayer1 = false;
                    for (auto &i : Player1)
                        for (auto &j : i)
                            for (auto &k : j)
                                k.setColor(135 / 256., 206 / 256., 250 / 256.);
                    for (auto &i : Player2)
                        for (auto &j : i)
                            for (auto &k : j)
                                k.setColor(1, 0, 0);
                } else {
                    isPlayer1 = true;
                    for (auto &i : Player2)
                        for (auto &j : i)
                            for (auto &k : j)
                                k.setColor(10 / 256., 254 / 256., 189 / 256.);
                    for (auto &i : Player1)
                        for (auto &j : i)
                            for (auto &k : j)
                                k.setColor(1, 0, 0);
                }
            } else if (movement && forEnter != -1) {
                rotate_y -= 5;
            } else
                ChooseColumn(1);
        }//аналогично для левой клавиши

        else if (key == GLUT_KEY_UP) {
            if (forEnter == -1) {

            } else if (movement && forEnter != -1) {
                //if (rotate_x <= -5)
                rotate_x += 5;
            } else
                ChooseColumn(2);
        } //это уже повороты  вверх и вниз

        else if (key == GLUT_KEY_DOWN) {
            if (forEnter == -1) {
                //
            } else if (movement && forEnter != -1) {
                //if (rotate_x >= -85)
                rotate_x -= 5;
            } else
                ChooseColumn(3);
        } else if (key == GLUT_KEY_HOME && forEnter <= 1) {
            default_position(r_rotate_x, r_rotate_y);
        } else if (key == GLUT_KEY_PAGE_UP && (forEnter == 4 || forEnter == 5)) {
            if (forTwoPlayers < 2)
                ChooseCube(1);
            else ChooseCube2(1);
        } else if (key == GLUT_KEY_PAGE_DOWN && (forEnter == 4 || forEnter == 5)) {
            if (forTwoPlayers < 2)
                ChooseCube(2);
            else ChooseCube2(2);
        }


        if (key == GLUT_KEY_F7 && (forEnter == 0 || forEnter == 1)) {
            //std::cout << "123    ";
            if (forTwoPlayers == 2) {
                if (isPlayer1)
                    //view_first_side_Player1(r_rotate_x, r_rotate_y);
                    int i;
                else view_first_side_Player2(r_rotate_x, r_rotate_y);
            } else
                view_first_side(r_rotate_x, r_rotate_y);
            forEnter = 1;
            //movement = false;
            firstSide = true;
            thirdSide = false;
            secondSide = false;
        } else if (key == GLUT_KEY_F8 && (forEnter == 0 || forEnter == 1)) {
            if (forTwoPlayers == 2) {
                if (isPlayer1)
                    //view_second_side_Player1(r_rotate_x, r_rotate_y);
                    int i;
                else view_second_side_Player2(r_rotate_x, r_rotate_y);
            } else
                view_second_side(r_rotate_x, r_rotate_y);
            forEnter = 1;
            secondSide = true;
            firstSide = false;
            thirdSide = false;
        } else if (key == GLUT_KEY_F9 && (forEnter == 0 || forEnter == 1)) {
            if (forTwoPlayers == 2) {
                if (isPlayer1)
                    //view_third_side_Player1(r_rotate_x, r_rotate_y);
                    int i;
                else view_third_side_Player2(r_rotate_x, r_rotate_y);
            } else
                view_third_side(r_rotate_x, r_rotate_y);
            forEnter = 1;
            thirdSide = true;
            firstSide = false;
            secondSide = false;
        }
    }

    glutPostRedisplay(); //а это просто обязательная функция
}


#endif //INC_3DSEEBUTTLE_WORKWITHKEYS_H