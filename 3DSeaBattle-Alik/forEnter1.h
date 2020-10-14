//
// Created by alik on 13.05.2020.
//

#ifndef INC_3DSEEBUTTLE_FORENTER1_H
#define INC_3DSEEBUTTLE_FORENTER1_H

#include "TwoPlayersEnter1.h"

void forEnter1Function()
{
    if (firstSide)
    {
        if (forTwoPlayers == 2)
        {
            twoForEnter1First();
        } else
        {
            choose_first_side(r_rotate_x, r_rotate_y);
            if (a[i_first_side][j_first_side][k_first_side].getHit() == 0)
                a[i_first_side][j_first_side][k_first_side].setColor(1, 1, 0);
            else
            {
                a[i_first_side][j_first_side][k_first_side].setColor(255 / 255., 105 / 255., 60 / 255.);
                a[i_first_side][j_first_side][k_first_side].setRed(true);
            }
            a[i_first_side][j_first_side][k_first_side].setPaint(true);
            a[i_first_side][j_first_side][k_first_side].setTransparency(0.5);
            for (int i = 0; i < LengthBigCube - 1; i++)
            {
                if (a[i][yf][z1].getHit() == 0)
                    a[i][yf][z1].setColor(1, 1, 0);
                else
                {
                    a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[i][yf][z1].setPaint(true);
                    a[i][yf][z1].setRed(true);
                }
                a[i][yf][z1].setTransparency(0.3);
            }
        }
    } else if (secondSide)
    {
        if (forTwoPlayers == 2)
        {
            twoForEnter1Second();
        } else
        {
            choose_second_side(r_rotate_x, r_rotate_y);
            if (a[i_second_side][j_second_side][k_second_side].getHit() == 0)
                a[i_second_side][j_second_side][k_second_side].setColor(1, 1, 0);
            else
            {
                a[i_second_side][j_second_side][k_second_side].setColor(255 / 255., 105 / 255., 60 / 255.);
                a[i_second_side][j_second_side][k_second_side].setRed(true);
            }
            a[i_second_side][j_second_side][k_second_side].setPaint(true);
            a[i_second_side][j_second_side][k_second_side].setTransparency(0.5);
            for (int i = 0; i < LengthBigCube - 1; i++)
            {
                if (a[x2][i][z2].getHit() == 0)
                    a[x2][i][z2].setColor(1, 1, 0);
                else
                {
                    a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[x2][i][z2].setPaint(true);
                    a[x2][i][z2].setRed(true);
                }
                a[x2][i][z2].setTransparency(0.3);
            }
        }
    } else if (thirdSide)
    {
        if (forTwoPlayers == 2)
        {
            twoForEnter1Third();
        } else
        {
            choose_third_side(r_rotate_x, r_rotate_y);
            if (a[i_third_side][j_third_side][k_third_side].getHit() == 0)
                a[i_third_side][j_third_side][k_third_side].setColor(1, 1, 0);
            else
            {
                a[i_third_side][j_third_side][k_third_side].setColor(255 / 255., 105 / 255., 60 / 255.);
                a[i_third_side][j_third_side][k_third_side].setRed(true);
            }
            a[i_third_side][j_third_side][k_third_side].setPaint(true);
            a[i_third_side][j_third_side][k_third_side].setTransparency(0.5);
            for (int i = 0; i < LengthBigCube - 1; i++)
            {
                if (a[x3][y3][i].getHit() == 0)
                    a[x3][y3][i].setColor(1, 1, 0);
                else
                {
                    a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[x3][y3][i].setPaint(true);
                    a[x3][y3][i].setRed(true);
                }
                a[x3][y3][i].setTransparency(0.3);
            }
        }
    }
    forEnter = 2;
    movement = false;
}

#endif //INC_3DSEEBUTTLE_FORENTER1_H
