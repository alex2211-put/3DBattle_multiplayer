//
// Created by alik on 13.05.2020.
//

#ifndef INC_3DSEEBUTTLE_CHOOSECUBE_H
#define INC_3DSEEBUTTLE_CHOOSECUBE_H

void ChooseCube(int page)
{
    if (firstSide)
    {
        if (p1 > 0)
            for (int i = p1; i <= ship; i++)
                a[i][yf][z1].setTransparency(0.7);

        if (page == 1 && p1 < LengthBigCube - ship)
        {
            for (int i = 0; i <= p1; i++)
                a[i][yf][z1].setTransparency(0.2);
            p1++;
            for (int i = p1; i < p1 + ship; i++)
                a[i][yf][z1].setTransparency(0.7);

        } else if (page == 2 && p1 > 0)
        {
            p1--;
            for (int i = p1 + ship - 1; i > p1 - 1; i--)
                a[i][yf][z1].setTransparency(0.7);

            for (int i = LengthBigCube - 1; i > p1 + ship - 1; i--)
                a[i][yf][z1].setTransparency(0.2);
        }

    } else if (secondSide)
    {
        if (p2 > 0)
            for (int j = p2; j <= ship; j++)
                a[x2][j][z2].setTransparency(0.7);

        if (page == 1 && p2 < LengthBigCube - ship)
        {
            for (int j = 0; j <= p2; j++)
                a[x2][j][z2].setTransparency(0.2);
            p2++;
            for (int j = p2; j < p2 + ship; j++)
                a[x2][j][z2].setTransparency(0.7);

        } else if (page == 2 && p2 > 0)
        {
            p2--;
            for (int j = p2 + ship - 1; j > p2 - 1; j--)
                a[x2][j][z2].setTransparency(0.7);

            for (int j = LengthBigCube - 1; j > p2 + ship - 1; j--)
                a[x2][j][z2].setTransparency(0.2);
        }

    } else if (thirdSide)
    {
        if (p3 > 0)
            for (int k = p3; k <= ship; k++)
                a[x3][y3][k].setTransparency(0.7);

        if (page == 1 && p3 < LengthBigCube - ship)
        {
            for (int k = 0; k <= p3; k++)
                a[x3][y3][k].setTransparency(0.2);
            p3++;
            for (int k = p3; k < p3 + ship; k++)
                a[x3][y3][k].setTransparency(0.7);

        } else if (page == 2 && p3 > 0)
        {
            p3--;
            for (int k = p3 + ship - 1; k > p3 - 1; k--)
                a[x3][y3][k].setTransparency(0.7);

            for (int k = LengthBigCube - 1; k > p3 + ship - 1; k--)
                a[x3][y3][k].setTransparency(0.2);
        }
    }
}

void ChooseCube2(int page)
{
    if (isPlayer1)
    {
        if (firstSide)
        {
            if (page == 1)
            {
                Player1[p1][yf][z1].setTransparency(0.11);
                p1++;
                if (p1 > LengthBigCube - 1)
                    p1 = 0;
                if (Player1[p1][yf][z1].getHit() == 4 || Player1[p1][yf][z1].getHit() == 3)
                {
                    Player1[p1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    Player1[p1][yf][z1].setTransparency(0.15);
                }
                if (Player1[p1][yf][z1].getHit() != 4 && Player1[p1][yf][z1].getHit() != 3)
                    Player1[p1][yf][z1].setTransparency(0.7);
            } else if (page == 2)
            {
                Player1[p1][yf][z1].setTransparency(0.11);
                p1--;
                if (p1 < 0)
                    p1 = LengthBigCube - 1;
                if (Player1[p1][yf][z1].getHit() == 4 || Player1[p1][yf][z1].getHit() == 3)
                {
                    Player1[p1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    Player1[p1][yf][z1].setTransparency(0.15);
                }
                if (Player1[p1][yf][z1].getHit() != 4 || Player1[p1][yf][z1].getHit() != 3)
                    Player1[p1][yf][z1].setTransparency(0.7);
            }
        } else if (secondSide)
        {
            if (page == 1)
            {
                Player1[x2][p2][z2].setTransparency(0.11);
                p2++;
                if (p2 > LengthBigCube - 1)
                    p2 = 0;
                if (Player1[x2][p2][z2].getHit() == 4 || Player1[x2][p2][z2].getHit() == 3)
                {
                    Player1[x2][p2][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                    Player1[x2][p2][z2].setTransparency(0.15);
                }
                if (Player1[x2][p2][z2].getHit() != 4 || Player1[x2][p2][z2].getHit() != 3)
                    Player1[x2][p2][z2].setTransparency(0.7);
            } else if (page == 2)
            {
                Player1[x2][p2][z2].setTransparency(0.11);
                p2--;
                if (p2 < 0)
                    p2 = LengthBigCube - 1;
                if (Player1[x2][p2][z2].getHit() == 4 || Player1[x2][p2][z2].getHit() == 3)
                {
                    Player1[x2][p2][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                    Player1[x2][p2][z2].setTransparency(0.15);
                }
                if (Player1[x2][p2][z2].getHit() != 4 && Player1[x2][p2][z2].getHit() != 3)
                    Player1[x2][p2][z2].setTransparency(0.7);
            }
        } else if (thirdSide)
        {
            if (page == 1)
            {
                Player1[x3][y3][p3].setTransparency(0.11);
                p3++;
                if (p3 > LengthBigCube - 1)
                    p3 = 0;
                if (Player1[x3][y3][p3].getHit() == 4 || Player1[x3][y3][p3].getHit() == 3)
                {
                    Player1[x3][y3][p3].setColor(255 / 255., 105 / 255., 60 / 255.);
                    Player1[x3][y3][p3].setTransparency(0.15);
                }
                if (Player1[x3][y3][p3].getHit() != 4 && Player1[x3][y3][p3].getHit() != 3)
                    Player1[x3][y3][p3].setTransparency(0.7);
            } else if (page == 2)
            {
                Player1[x3][y3][p3].setTransparency(0.11);
                p3--;
                if (p3 < 0)
                    p3 = LengthBigCube - 1;
                if (Player1[x3][y3][p3].getHit() == 4 || Player1[x3][y3][p3].getHit() == 3)
                {
                    Player1[x3][y3][p3].setColor(255 / 255., 105 / 255., 60 / 255.);
                    Player1[x3][y3][p3].setTransparency(0.15);
                }
                if (Player1[x3][y3][p3].getHit() != 4 && Player1[x3][y3][p3].getHit() != 3)
                    Player1[x3][y3][p3].setTransparency(0.7);
            }
        }
    } else
    {
        if (firstSide)
        {
            if (page == 1)
            {
                Player2[p1][yf][z1].setTransparency(0.11);
                p1++;
                if (p1 > LengthBigCube - 1)
                    p1 = 0;
                if (Player2[p1][yf][z1].getHit() == 4 || Player2[p1][yf][z1].getHit() == 3)
                {
                    Player2[p1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    Player2[p1][yf][z1].setTransparency(0.15);
                }
                if (Player2[p1][yf][z1].getHit() != 4 && Player2[p1][yf][z1].getHit() != 3)
                    Player2[p1][yf][z1].setTransparency(0.7);
            } else if (page == 2)
            {
                Player2[p1][yf][z1].setTransparency(0.11);
                p1--;
                if (p1 < 0)
                    p1 = LengthBigCube - 1;
                if (Player2[p1][yf][z1].getHit() == 4 || Player2[p1][yf][z1].getHit() == 3)
                {
                    Player2[p1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    Player2[p1][yf][z1].setTransparency(0.15);
                }
                if (Player2[p1][yf][z1].getHit() != 4 && Player2[p1][yf][z1].getHit() != 3)
                    Player2[p1][yf][z1].setTransparency(0.7);
            }
        } else if (secondSide)
        {
            if (page == 1)
            {
                Player2[x2][p2][z2].setTransparency(0.11);
                p2++;
                if (p2 > LengthBigCube - 1)
                    p2 = 0;
                if (Player2[x2][p2][z2].getHit() == 4 || Player2[x2][p2][z2].getHit() == 3)
                {
                    Player2[x2][p2][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                    Player2[x2][p2][z2].setTransparency(0.15);
                }
                if (Player2[x2][p2][z2].getHit() != 4 && Player2[x2][p2][z2].getHit() != 3)
                    Player2[x2][p2][z2].setTransparency(0.7);
            } else if (page == 2)
            {
                Player2[x2][p2][z2].setTransparency(0.11);
                p2--;
                if (p2 < 0)
                    p2 = LengthBigCube - 1;
                if (Player2[x2][p2][z2].getHit() == 4 || Player2[x2][p2][z2].getHit() == 3)
                {
                    Player2[x2][p2][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                    Player2[x2][p2][z2].setTransparency(0.15);
                }
                if (Player2[x2][p2][z2].getHit() != 4 && Player2[x2][p2][z2].getHit() != 3)
                    Player2[x2][p2][z2].setTransparency(0.7);
            }
        } else if (thirdSide)
        {
            if (page == 1)
            {
                Player2[x3][y3][p3].setTransparency(0.11);
                p3++;
                if (p3 > LengthBigCube - 1)
                    p3 = 0;
                if (Player2[x3][y3][p3].getHit() == 4 || Player2[x3][y3][p3].getHit() == 3)
                {
                    Player2[x3][y3][p3].setColor(255 / 255., 105 / 255., 60 / 255.);
                    Player2[x3][y3][p3].setTransparency(0.15);
                }
                if (Player2[x3][y3][p3].getHit() != 4 && Player2[x3][y3][p3].getHit() != 3)
                    Player2[x3][y3][p3].setTransparency(0.7);
            } else if (page == 2)
            {
                Player2[x3][y3][p3].setTransparency(0.11);
                p3--;
                if (p3 < 0)
                    p3 = LengthBigCube - 1;
                if (Player2[x3][y3][p3].getHit() == 4 || Player2[x3][y3][p3].getHit() == 3)
                {
                    Player2[x3][y3][p3].setColor(255 / 255., 105 / 255., 60 / 255.);
                    Player2[x3][y3][p3].setTransparency(0.15);
                }
                if (Player2[x3][y3][p3].getHit() != 4 && Player2[x3][y3][p3].getHit() != 3)
                    Player2[x3][y3][p3].setTransparency(0.7);
            }

        }
    }

}

#endif //INC_3DSEEBUTTLE_CHOOSECUBE_H
