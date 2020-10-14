//
// Created by alik on 13.05.2020.
//

#ifndef INC_3DSEEBUTTLE_CHOOSECOLUMN_H
#define INC_3DSEEBUTTLE_CHOOSECOLUMN_H

void forFirstSideTwoPlayers(int arrow)
{
    if (isPlayer1)
    {/*
        Player1[LengthBigCube - 1][yf][z1].setTransparency(0.11);
        Player1[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
        if (Player1[LengthBigCube - 1][yf][z1].getHit() == 3)
        {
            Player1[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
            Player1[LengthBigCube - 1][yf][z1].setTransparency(0.35);
        }
        if (Player1[LengthBigCube - 1][yf][z1].getHit() == 4)
        {
            Player1[LengthBigCube - 1][yf][z1].setColor(1, 0, 0);
            Player1[LengthBigCube - 1][yf][z1].setTransparency(0.35);
        }
        for (int i = 0; i < LengthBigCube - 1; i++)
        {
            if (Player1[i][yf][z1].getHit() == 3)
            {
                Player1[i][yf][z1].setColor(0, 0, 1);
                Player1[i][yf][z1].setTransparency(0.35);
            } else if (Player1[i][yf][z1].getHit() == 4)
            {
                Player1[i][yf][z1].setColor(1, 0, 0);
                Player1[i][yf][z1].setTransparency(0.35);
            } else
            {
                Player1[i][yf][z1].setColor(0.5, 0.5, 0.8);
                Player1[i][yf][z1].setTransparency(0.11);
            }
            Player1[i][yf][z1].setRed(false);
        }
        switch (arrow)
        {
            case 4:
            {
                z1++;
                if (z1 > LengthBigCube - 1)
                    z1 = 0;
                break;
            }
            case 2:
            {
                yf++;
                if (yf > LengthBigCube - 1)
                    yf = 0;
                break;
            }
            case 1:
            {
                z1--;
                if (z1 < 0)
                    z1 = LengthBigCube - 1;
                break;
            }
            case 3:
            {
                yf--;
                if (yf < 0)
                    yf = LengthBigCube - 1;
                break;
            }
        }
        for (int i = 0; i < LengthBigCube - 1; i++)
        {
            if (Player1[i][yf][z1].getHit() <= 2)
            {
                Player1[i][yf][z1].setColor(1, 1, 0);
                Player1[i][yf][z1].setTransparency(0.35);
            } else
            {
                Player1[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                if (Player1[i][yf][z1].getHit() == 3)
                    Player1[i][yf][z1].setRed(true);
                Player1[i][yf][z1].setTransparency(1);
            }

        }
        if (Player1[LengthBigCube - 1][yf][z1].getHit() >= 3)
        {
            Player1[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
            Player1[LengthBigCube - 1][yf][z1].setTransparency(1);
            Player1[LengthBigCube - 1][yf][z1].setRed(true);
        } else
        {
            Player1[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
            Player1[LengthBigCube - 1][yf][z1].setTransparency(0.7);
        }*/
    } else
    {
        Player2[LengthBigCube - 1][yf][z1].setTransparency(0.11);
        Player2[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
        if (Player2[LengthBigCube - 1][yf][z1].getHit() == 3)
        {
            Player2[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
            Player2[LengthBigCube - 1][yf][z1].setTransparency(0.35);
        }
        if (Player2[LengthBigCube - 1][yf][z1].getHit() == 4)
        {
            Player2[LengthBigCube - 1][yf][z1].setColor(1, 0, 0);
            Player2[LengthBigCube - 1][yf][z1].setTransparency(0.35);
        }
        for (int i = 0; i < LengthBigCube - 1; i++)
        {
            if (Player2[i][yf][z1].getHit() == 3)
            {
                Player2[i][yf][z1].setColor(0, 0, 1);
                Player2[i][yf][z1].setTransparency(0.35);
            } else if (Player2[i][yf][z1].getHit() == 4)
            {
                Player2[i][yf][z1].setColor(1, 0, 0);
                Player2[i][yf][z1].setTransparency(0.35);
            } else
            {
                Player2[i][yf][z1].setColor(0.5, 0.5, 0.8);
                Player2[i][yf][z1].setTransparency(0.11);
            }
            Player2[i][yf][z1].setRed(false);
        }
        switch (arrow)
        {
            case 4:
            {
                z1++;
                if (z1 > LengthBigCube - 1)
                    z1 = 0;
                break;
            }
            case 2:
            {
                yf++;
                if (yf > LengthBigCube - 1)
                    yf = 0;
                break;
            }
            case 1:
            {
                z1--;
                if (z1 < 0)
                    z1 = LengthBigCube - 1;
                break;
            }
            case 3:
            {
                yf--;
                if (yf < 0)
                    yf = LengthBigCube - 1;
                break;
            }
        }

        for (int i = 0; i < LengthBigCube - 1; i++)
        {
            if (Player2[i][yf][z1].getHit() <= 2)
            {
                Player2[i][yf][z1].setColor(1, 1, 0);
                Player2[i][yf][z1].setTransparency(0.35);
            } else
            {
                Player2[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                if (Player2[i][yf][z1].getHit() == 3)
                    Player2[i][yf][z1].setRed(true);
                Player2[i][yf][z1].setTransparency(1);
            }

        }
        if (Player2[LengthBigCube - 1][yf][z1].getHit() >= 3)
        {
            Player2[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
            Player2[LengthBigCube - 1][yf][z1].setTransparency(1);
            Player2[LengthBigCube - 1][yf][z1].setRed(true);
        } else
        {
            Player2[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
            Player2[LengthBigCube - 1][yf][z1].setTransparency(0.7);
        }
    }
}

void forSecondTwoPlayers(int arrow)
{
    if (isPlayer1)
    {/*
        Player1[x2][LengthBigCube - 1][z2].setTransparency(0.11);
        Player1[x2][LengthBigCube - 1][z2].setColor(0, 0, 1);
        if (Player1[x2][LengthBigCube - 1][z2].getHit() == 3)
        {
            Player1[x2][LengthBigCube - 1][z2].setColor(0, 0, 1);
            Player1[x2][LengthBigCube - 1][z2].setTransparency(0.35);
        }
        if (Player1[x2][LengthBigCube - 1][z2].getHit() == 4)
        {
            Player1[x2][LengthBigCube - 1][z2].setColor(1, 0, 0);
            Player1[x2][LengthBigCube - 1][z2].setTransparency(0.35);
        }
        for (int i = 0; i < LengthBigCube - 1; i++)
        {
            if (Player1[x2][i][z2].getHit() == 3)
            {
                Player1[x2][i][z2].setColor(0, 0, 1);
                Player1[x2][i][z2].setTransparency(0.35);
            } else if (Player1[x2][i][z2].getHit() == 4)
            {
                Player1[x2][i][z2].setColor(1, 0, 0);
                Player1[x2][i][z2].setTransparency(0.35);
            } else
            {
                Player1[x2][i][z2].setColor(0.5, 0.5, 0.8);
                Player1[x2][i][z2].setTransparency(0.11);
            }
            Player1[x2][i][z2].setRed(false);
        }
        switch (arrow)
        {
            case 4:
            {
                x2--;
                if (x2 < 0)
                    x2 = LengthBigCube - 1;
                break;
            }
            case 2:
            {
                z2--;
                if (z2 < 0)
                    z2 = LengthBigCube - 1;
                break;
            }
            case 1:
            {
                x2++;
                if (x2 > LengthBigCube - 1)
                    x2 = 0;
                break;
            }
            case 3:
            {
                z2++;
                if (z2 > LengthBigCube - 1)
                    z2 = 0;
                break;
            }
        }
        for (int i = 0; i < LengthBigCube - 1; i++)
        {
            if (Player1[x2][i][z2].getHit() <= 2)
            {
                Player1[x2][i][z2].setColor(1, 1, 0);
                Player1[x2][i][z2].setTransparency(0.35);
            } else
            {
                Player1[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                if (Player1[x2][i][z2].getHit() == 3)
                    Player1[x2][i][z2].setRed(true);
                Player1[x2][i][z2].setTransparency(1);
            }

        }
        if (Player1[x2][LengthBigCube - 1][z2].getHit() >= 3)
        {
            Player1[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
            Player1[x2][LengthBigCube - 1][z2].setTransparency(1);
            Player1[x2][LengthBigCube - 1][z2].setRed(true);
        } else
        {
            Player1[x2][LengthBigCube - 1][z2].setColor(1, 1, 0);
            Player1[x2][LengthBigCube - 1][z2].setTransparency(0.7);
        }*/

    } else
    {
        Player2[x2][LengthBigCube - 1][z2].setTransparency(0.11);
        Player2[x2][LengthBigCube - 1][z2].setColor(0, 0, 1);
        if (Player2[x2][LengthBigCube - 1][z2].getHit() == 3)
        {
            Player2[x2][LengthBigCube - 1][z2].setColor(0, 0, 1);
            Player2[x2][LengthBigCube - 1][z2].setTransparency(0.35);
        }
        if (Player2[x2][LengthBigCube - 1][z2].getHit() == 4)
        {
            Player2[x2][LengthBigCube - 1][z2].setColor(1, 0, 0);
            Player2[x2][LengthBigCube - 1][z2].setTransparency(0.35);
        }
        for (int i = 0; i < LengthBigCube - 1; i++)
        {
            if (Player2[x2][i][z2].getHit() == 3)
            {
                Player2[x2][i][z2].setColor(0, 0, 1);
                Player2[x2][i][z2].setTransparency(0.35);
            } else if (Player2[x2][i][z2].getHit() == 4)
            {
                Player2[x2][i][z2].setColor(1, 0, 0);
                Player2[x2][i][z2].setTransparency(0.35);
            } else
            {
                Player2[x2][i][z2].setColor(0.5, 0.5, 0.8);
                Player2[x2][i][z2].setTransparency(0.11);
            }
            Player2[x2][i][z2].setRed(false);
        }
        switch (arrow)
        {
            case 4:
            {
                x2--;
                if (x2 < 0)
                    x2 = LengthBigCube - 1;
                break;
            }
            case 2:
            {
                z2--;
                if (z2 < 0)
                    z2 = LengthBigCube - 1;
                break;
            }
            case 1:
            {
                x2++;
                if (x2 > LengthBigCube - 1)
                    x2 = 0;
                break;
            }
            case 3:
            {
                z2++;
                if (z2 > LengthBigCube - 1)
                    z2 = 0;
                break;
            }
        }
        for (int i = 0; i < LengthBigCube - 1; i++)
        {
            if (Player2[x2][i][z2].getHit() <= 2)
            {
                Player2[x2][i][z2].setColor(1, 1, 0);
                Player2[x2][i][z2].setTransparency(0.35);
            } else
            {
                Player2[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                if (Player2[x2][i][z2].getHit() == 3)
                    Player2[x2][i][z2].setRed(true);
                Player2[x2][i][z2].setTransparency(1);
            }

        }
        if (Player2[x2][LengthBigCube - 1][z2].getHit() >= 3)
        {
            Player2[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
            Player2[x2][LengthBigCube - 1][z2].setTransparency(1);
            Player2[x2][LengthBigCube - 1][z2].setRed(true);
        } else
        {
            Player2[x2][LengthBigCube - 1][z2].setColor(1, 1, 0);
            Player2[x2][LengthBigCube - 1][z2].setTransparency(0.7);
        }
    }
}

void forThirdTwoPlayers(int arrow)
{
    if (isPlayer1)
    {/*
        Player1[x3][y3][LengthBigCube - 1].setTransparency(0.11);
        Player1[x3][y3][LengthBigCube - 1].setColor(0, 0, 1);
        if (Player1[x3][y3][LengthBigCube - 1].getHit() == 3)
        {
            Player1[x3][y3][LengthBigCube - 1].setColor(0, 0, 1);
            Player1[x3][y3][LengthBigCube - 1].setTransparency(0.35);
        }
        if (Player1[x3][y3][LengthBigCube - 1].getHit() == 4)
        {
            Player1[x3][y3][LengthBigCube - 1].setColor(1, 0, 0);
            Player1[x3][y3][LengthBigCube - 1].setTransparency(0.35);
        }
        for (int i = 0; i < LengthBigCube - 1; i++)
        {
            if (Player1[x3][y3][i].getHit() == 3)
            {
                Player1[x3][y3][i].setColor(0, 0, 1);
                Player1[x3][y3][i].setTransparency(0.35);
            } else if (Player1[x3][y3][i].getHit() == 4)
            {
                Player1[x3][y3][i].setColor(1, 0, 0);
                Player1[x3][y3][i].setTransparency(0.35);
            } else
            {
                Player1[x3][y3][i].setColor(0.5, 0.5, 0.8);
                Player1[x3][y3][i].setTransparency(0.11);
            }
            Player1[x3][y3][i].setRed(false);
        }
        switch (arrow)
        {
            case 4:
            {
                x3--;
                if (x3 < 0)
                    x3 = LengthBigCube - 1;
                break;
            }
            case 2:
            {
                y3++;
                if (y3 > LengthBigCube - 1)
                    y3 = 0;
                break;
            }
            case 1:
            {
                x3++;
                if (x3 > LengthBigCube - 1)
                    x3 = 0;
                break;
            }
            case 3:
            {
                y3--;
                if (y3 < 0)
                    y3 = LengthBigCube - 1;
                break;
            }
        }
        for (int i = 0; i < LengthBigCube - 1; i++)
        {
            if (Player1[x3][y3][i].getHit() <= 2)
            {
                Player1[x3][y3][i].setColor(1, 1, 0);
                Player1[x3][y3][i].setTransparency(0.35);
            } else
            {
                Player1[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                if (Player1[x3][y3][i].getHit() == 3)
                    Player1[x3][y3][i].setRed(true);
                Player1[x3][y3][i].setTransparency(1);
            }

        }
        if (Player1[x3][y3][LengthBigCube - 1].getHit() >= 3)
        {
            Player1[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
            Player1[x3][y3][LengthBigCube - 1].setTransparency(1);
            Player1[x3][y3][LengthBigCube - 1].setRed(true);
        } else
        {
            Player1[x3][y3][LengthBigCube - 1].setColor(1, 1, 0);
            Player1[x3][y3][LengthBigCube - 1].setTransparency(0.7);
        }*/

    } else
    {
        Player2[x3][y3][LengthBigCube - 1].setTransparency(0.11);
        Player2[x3][y3][LengthBigCube - 1].setColor(0, 0, 1);
        if (Player2[x3][y3][LengthBigCube - 1].getHit() == 3)
        {
            Player2[x3][y3][LengthBigCube - 1].setColor(0, 0, 1);
            Player2[x3][y3][LengthBigCube - 1].setTransparency(0.35);
        }
        if (Player2[x3][y3][LengthBigCube - 1].getHit() == 4)
        {
            Player2[x3][y3][LengthBigCube - 1].setColor(1, 0, 0);
            Player2[x3][y3][LengthBigCube - 1].setTransparency(0.35);
        }
        for (int i = 0; i < LengthBigCube - 1; i++)
        {
            if (Player2[x3][y3][i].getHit() == 3)
            {
                Player2[x3][y3][i].setColor(0, 0, 1);
                Player2[x3][y3][i].setTransparency(0.35);
            } else if (Player2[x3][y3][i].getHit() == 4)
            {
                Player2[x3][y3][i].setColor(1, 0, 0);
                Player2[x3][y3][i].setTransparency(0.35);
            } else
            {
                Player2[x3][y3][i].setColor(0.5, 0.5, 0.8);
                Player2[x3][y3][i].setTransparency(0.11);
            }
            Player2[x3][y3][i].setRed(false);
        }
        switch (arrow)
        {
            case 4:
            {
                x3--;
                if (x3 < 0)
                    x3 = LengthBigCube - 1;
                break;
            }
            case 2:
            {
                y3++;
                if (y3 > LengthBigCube - 1)
                    y3 = 0;
                break;
            }
            case 1:
            {
                x3++;
                if (x3 > LengthBigCube - 1)
                    x3 = 0;
                break;
            }
            case 3:
            {
                y3--;
                if (y3 < 0)
                    y3 = LengthBigCube - 1;
                break;
            }
        }
        for (int i = 0; i < LengthBigCube - 1; i++)
        {
            if (Player2[x3][y3][i].getHit() <= 2)
            {
                Player2[x3][y3][i].setColor(1, 1, 0);
                Player2[x3][y3][i].setTransparency(0.35);
            } else
            {
                Player2[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                if (Player2[x3][y3][i].getHit() == 3)
                    Player2[x3][y3][i].setRed(true);
                Player2[x3][y3][i].setTransparency(1);
            }

        }
        if (Player2[x3][y3][LengthBigCube - 1].getHit() >= 3)
        {
            Player2[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
            Player2[x3][y3][LengthBigCube - 1].setTransparency(1);
            Player2[x3][y3][LengthBigCube - 1].setRed(true);
        } else
        {
            Player2[x3][y3][LengthBigCube - 1].setColor(1, 1, 0);
            Player2[x3][y3][LengthBigCube - 1].setTransparency(0.7);
        }
    }
}

void ChooseColumn(int arrow)
{
    if (firstSide)// && forEnter >= 2)
    {
        if (forTwoPlayers == 2)
        {
            forFirstSideTwoPlayers(arrow);
        } else
        {
            a[LengthBigCube - 1][yf][z1].setTransparency(0.11);
            a[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
            if (a[LengthBigCube - 1][yf][z1].getHit() == 2)
                a[LengthBigCube - 1][yf][z1].setPaint(false);
            if (a[LengthBigCube - 1][yf][z1].getHit() == 1)
                a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
            for (int i = 0; i < LengthBigCube - 1; i++)
            {
                a[i][yf][z1].setColor(0.5, 0.5, 0.8);
                a[i][yf][z1].setTransparency(0.11);
                if (a[i][yf][z1].getHit() == 2)
                    a[i][yf][z1].setPaint(false);
                a[i][yf][z1].setRed(false);
            }
            switch (arrow)
            {
                case 4:
                {
                    z1++;
                    if (z1 > LengthBigCube - 1)
                        z1 = 0;
                    break;
                }
                case 2:
                {
                    yf++;
                    if (yf > LengthBigCube - 1)
                        yf = 0;
                    break;
                }
                case 1:
                {
                    z1--;
                    if (z1 < 0)
                        z1 = LengthBigCube - 1;
                    break;
                }
                case 3:
                {
                    yf--;
                    if (yf < 0)
                        yf = LengthBigCube - 1;
                    break;
                }
            }
            for (int i = 0; i < LengthBigCube - 1; i++)
            {
                if (a[i][yf][z1].getHit() == 0)
                    a[i][yf][z1].setColor(1, 1, 0);
                else
                {
                    a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[i][yf][z1].setPaint(true);
                    if (a[i][yf][z1].getHit() == 1)
                        a[i][yf][z1].setRed(true);
                }
                a[i][yf][z1].setTransparency(0.3);
            }
            if (a[LengthBigCube - 1][yf][z1].getHit() != 0)
            {
                a[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                a[LengthBigCube - 1][yf][z1].setPaint(true);
                a[LengthBigCube - 1][yf][z1].setRed(true);
            } else a[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
            a[LengthBigCube - 1][yf][z1].setTransparency(0.7);
        }
    } else if (secondSide)// && forEnter >= 2)
    {
        if (forTwoPlayers == 2)
        {
            forSecondTwoPlayers(arrow);
        } else
        {
            a[x2][LengthBigCube - 1][z2].setTransparency(0.11);
            a[x2][LengthBigCube - 1][z2].setColor(0.0, 0, 1);
            if (a[x2][LengthBigCube - 1][z2].getHit() == 1)
                a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
            if (a[x2][LengthBigCube - 1][z2].getHit() == 2)
                a[x2][LengthBigCube - 1][z2].setPaint(false);

            for (int i = 0; i < LengthBigCube - 1; i++)
            {
                a[x2][i][z2].setTransparency(0.11);
                a[x2][i][z2].setColor(0.5, 0.5, 0.8);
                if (a[x2][i][z2].getHit() == 2)
                    a[x2][i][z2].setPaint(false);
                a[x2][i][z2].setRed(false);
            }
            switch (arrow)
            {
                case 4:
                {
                    x2--;
                    if (x2 < 0)
                        x2 = LengthBigCube - 1;
                    break;
                }
                case 2:
                {
                    z2--;
                    if (z2 < 0)
                        z2 = LengthBigCube - 1;
                    break;
                }
                case 1:
                {
                    x2++;
                    if (x2 > LengthBigCube - 1)
                        x2 = 0;
                    break;
                }
                case 3:
                {
                    z2++;
                    if (z2 > LengthBigCube - 1)
                        z2 = 0;
                    break;
                }
            }
            for (int i = 0; i < LengthBigCube - 1; i++)
            {
                a[x2][i][z2].setTransparency(0.3);
                if (a[x2][i][z2].getHit() == 0)
                    a[x2][i][z2].setColor(1, 1, 0);
                else
                {
                    a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[x2][i][z2].setPaint(true);
                    if (a[x2][i][z2].getHit() == 1)
                        a[x2][i][z2].setRed(true);
                }
            }
            if (a[x2][LengthBigCube - 1][z2].getHit() != 0)
            {
                a[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                a[x2][LengthBigCube - 1][z2].setPaint(true);
                a[x2][LengthBigCube - 1][z2].setRed(true);
            } else a[x2][LengthBigCube - 1][z2].setColor(1, 1, 0.0);
            a[x2][LengthBigCube - 1][z2].setTransparency(0.7);
        }
    } else if (thirdSide)// && forEnter >= 2)
    {
            if (forTwoPlayers == 2)
            {
                forThirdTwoPlayers(arrow);
            } else
            {
                a[x3][y3][LengthBigCube - 1].setTransparency(0.11);
                a[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 1);
                if (a[x3][y3][LengthBigCube - 1].getHit() == 2)
                    a[x3][y3][LengthBigCube - 1].setPaint(false);
                if (a[x3][y3][LengthBigCube - 1].getHit() == 1)
                    a[x3][y3][LengthBigCube - 1].setColor(0, 1, 0);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x3][y3][i].setTransparency(0.11);
                    a[x3][y3][i].setColor(0.5, 0.5, 0.8);
                    if (a[x3][y3][i].getHit() == 2)
                        a[x3][y3][i].setPaint(false);
                    a[x3][y3][i].setRed(false);
                }
                switch (arrow)
                {
                    case 4:
                    {
                        x3--;
                        if (x3 < 0)
                            x3 = LengthBigCube - 1;
                        break;
                    }
                    case 2:
                    {
                        y3++;
                        if (y3 > LengthBigCube - 1)
                            y3 = 0;
                        break;
                    }
                    case 1:
                    {
                        x3++;
                        if (x3 > LengthBigCube - 1)
                            x3 = 0;
                        break;
                    }
                    case 3:
                    {
                        y3--;
                        if (y3 < 0)
                            y3 = LengthBigCube - 1;
                        break;
                    }
                }
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x3][y3][i].setTransparency(0.3);
                    if (a[x3][y3][i].getHit() == 0)
                        a[x3][y3][i].setColor(1, 1, 0);
                    else
                    {
                        a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x3][y3][i].setPaint(true);
                        if (a[x3][y3][i].getHit() == 1)
                            a[x3][y3][i].setRed(true);
                    }
                }
                if (a[x3][y3][LengthBigCube - 1].getHit() != 0)
                {
                    a[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[x3][y3][LengthBigCube - 1].setPaint(true);
                    a[x3][y3][LengthBigCube - 1].setRed(true);
                } else a[x3][y3][LengthBigCube - 1].setColor(1, 1, 0.0);
                a[x3][y3][LengthBigCube - 1].setTransparency(0.7);
            }
        }
    forEnter = 3;
}

#endif //INC_3DSEEBUTTLE_CHOOSECOLUMN_H
