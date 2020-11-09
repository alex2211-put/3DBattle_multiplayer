//
// Created by alik on 13.05.2020.
//

#ifndef INC_3DSEEBUTTLE_FORENTER3_H
#define INC_3DSEEBUTTLE_FORENTER3_H

void forEnter3Function()
{
    if (forTwoPlayers == 2)
    {
        if (isPlayer1)
        {
            movement = true;
            /*for (auto &i : Player1)
                for (auto &j : i)
                    for (auto &k : j)
                        if (k.getHit() <= 2)
                        {
                            k.setRed(false);
                            if (k.getHit() <= 2)
                            {
                                k.setColor(0.5, 0.5, 0.8);
                                k.setTransparency(0.1);
                            }
                            if (k.getHit() == 3)
                            {
                                k.setColor(0, 0, 1);
                                k.setTransparency(0.15);
                            }
                            if (k.getHit() == 4)
                            {
                                k.setColor(1, 0, 0);
                                k.setTransparency(0.35);
                            }
                        }

            if (firstSide)
            {
                for (auto &i : Player1)
                {
                    if (i[yf][z1].getHit() == 3)
                    {
                        i[yf][z1].setColor(0, 0, 1);
                        i[yf][z1].setTransparency(0.15);
                    }
                    else if (i[yf][z1].getHit() == 4)
                    {
                        i[yf][z1].setColor(1, 0, 0);
                        i[yf][z1].setTransparency(0.35);
                    }
                    else
                        i[yf][z1].setColor(1, 1, 0);
                }
                Player1[0][yf][z1].setTransparency(0.7);
            } else if (secondSide)
            {
                for (int j = 0; j < LengthBigCube; j++)
                {
                    if(Player1[x2][j][z2].getHit() == 3)
                    {
                        Player1[x2][j][z2].setColor(0, 0, 1);
                        Player1[x2][j][z2].setTransparency(0.15);
                    } else if(Player1[x2][j][z2].getHit() == 4)
                    {
                        Player1[x2][j][z2].setColor(1, 0, 0);
                        Player1[x2][j][z2].setTransparency(0.35);
                    }
                    Player1[x2][j][z2].setColor(1, 1, 0);
                }
                Player1[x2][0][z2].setTransparency(0.7);
                r_rotate_x = 325;
                r_rotate_y = 135;
            } else if (thirdSide)
            {
                for (int k = 0; k < LengthBigCube; k++)
                {
                    if(Player1[x3][y3][k].getHit() == 3)
                    {
                        Player1[x3][y3][k].setColor(0, 0, 1);
                        Player1[x3][y3][k].setTransparency(0.15);
                    } else if(Player1[x3][y3][k].getHit() == 4)
                    {
                        Player1[x3][y3][k].setColor(1, 0, 0);
                        Player1[x2][y3][k].setTransparency(0.35);
                    }
                    Player1[x3][y3][k].setColor(1, 1, 0);
                }
                Player1[x3][y3][0].setTransparency(0.7);
                r_rotate_x = 325;
                r_rotate_y = 135;
            }*/
        } else
        {
            movement = true;
            for (auto &i : Player2)
                for (auto &j : i)
                    for (auto &k : j)
                        if (k.getHit() <= 2)
                        {
                            k.setRed(false);
                            if (k.getHit() <= 2)
                            {
                                k.setColor(0.5, 0.5, 0.8);
                                k.setTransparency(0.1);
                            }
                            if (k.getHit() == 3)
                            {
                                k.setColor(255 / 255., 105 / 255., 60 / 255.);
                                k.setTransparency(0.15);
                            }
                            if (k.getHit() == 4)
                            {
                                k.setColor(255 / 255., 105 / 255., 60 / 255.);
                                k.setTransparency(0.15);
                            }
                        }

            if (firstSide)
            {
                for (auto &i : Player2)
                {
                    if (i[yf][z1].getHit() == 3)
                    {
                        i[yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        i[yf][z1].setTransparency(0.15);
                    } else if (i[yf][z1].getHit() == 4)
                    {
                        i[yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        i[yf][z1].setTransparency(0.15);
                    } else
                        i[yf][z1].setColor(1, 1, 0);
                }
                Player2[0][yf][z1].setTransparency(0.7);
            } else if (secondSide)
            {
                for (int j = 0; j < LengthBigCube; j++)
                {
                    if(Player2[x2][j][z2].getHit() == 3)
                    {
                        Player2[x2][j][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        Player2[x2][j][z2].setTransparency(0.15);
                    } else if(Player2[x2][j][z2].getHit() == 4)
                    {
                        Player2[x2][j][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        Player2[x2][j][z2].setTransparency(0.15);
                    } else
                    Player2[x2][j][z2].setColor(1, 1, 0);
                }
                Player2[x2][0][z2].setTransparency(0.7);
                r_rotate_x = 325;
                r_rotate_y = 135;
            } else if (thirdSide)
            {
                for (int k = 0; k < LengthBigCube; k++)
                {
                    if(Player2[x3][y3][k].getHit() == 3)
                    {
                        Player2[x3][y3][k].setColor(255 / 255., 105 / 255., 60 / 255.);
                        Player2[x3][y3][k].setTransparency(0.15);
                    } else if(Player2[x3][y3][k].getHit() == 4)
                    {
                        Player2[x3][y3][k].setColor(255 / 255., 105 / 255., 60 / 255.);
                        Player2[x3][y3][k].setTransparency(0.15);
                    } else
                    Player2[x3][y3][k].setColor(1, 1, 0);
                }
                Player2[x3][y3][0].setTransparency(0.7);
                r_rotate_x = 325;
                r_rotate_y = 135;
            }
        }
    } else
    {
        movement = true;
        for (auto &i : a)
            for (auto &j : i)
                for (auto &k : j)
                {
                    k.setColor(0.5, 0.5, 0.8);
                    k.setTransparency(0.1);
                }

        if (firstSide)
        {
            for (auto &i : a)
                i[yf][z1].setColor(1, 1, 0);
            for (int i = 0; i < ship; i++)
            {
                a[i][yf][z1].setTransparency(0.7);
            }
            r_rotate_x = 325;
            r_rotate_y = 135;
        } else if (secondSide)
        {
            for (int j = 0; j < LengthBigCube; j++)
                a[x2][j][z2].setColor(1, 1, 0);
            for (int j = 0; j < ship; j++)
                a[x2][j][z2].setTransparency(0.7);
            r_rotate_x = 325;
            r_rotate_y = 135;
        } else if (thirdSide)
        {
            for (int k = 0; k < LengthBigCube; k++)
                a[x3][y3][k].setColor(1, 1, 0);
            for (int k = 0; k < ship; k++)
                a[x3][y3][k].setTransparency(0.7);
            r_rotate_x = 325;
            r_rotate_y = 135;
        }
    }
    forEnter = 5;
}

#endif //INC_3DSEEBUTTLE_FORENTER3_H
