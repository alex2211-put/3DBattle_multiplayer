//
// Created by alik on 13.05.2020.
//

#ifndef INC_3DSEEBUTTLE_HITSIDE_PLAYER2_H
#define INC_3DSEEBUTTLE_HITSIDE_PLAYER2_H

void hitFirstSide2()

{
    shipsLifeSecond--;
    if (p1 - 1 >= 0 && Player2[p1 - 1][yf][z1].getHit() == 4)
    {
        {
            int length = 1;
            int _x = p1;
            while (_x >= 0 && Player2[_x][yf][z1].getHit() == 4)
            {
                _x--;
            }
            _x++;
            while (_x < LengthBigCube && Player2[_x][yf][z1].getHit() == 4)
            {
                _x++;
                length++;
            }
            for (int i = _x - length - 1; i <= _x; i++)
                for (int j = yf - 1; j <= yf + 1; j++)
                    for (int k = z1 - 1; k <= z1 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (p1 + 1 < LengthBigCube && Player2[p1 + 1][yf][z1].getHit() == 4)
    {
        {
            int length = 1;
            int _x = p1;
            while (_x < LengthBigCube && Player2[_x][yf][z1].getHit() == 4)
            {
                _x++;
                length++;
            }
            _x--;
            while (_x >= 0 && Player2[_x][yf][z1].getHit() == 4)
            {
                _x--;
            }

            for (int i = _x; i <= _x + length + 1; i++)
                for (int j = yf - 1; j <= yf + 1; j++)
                    for (int k = z1 - 1; k <= z1 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (yf - 1 >= 0 && Player2[p1][yf - 1][z1].getHit() == 4)
    {
        {
            int length = 1;
            int _x = yf;
            while (_x >= 0 && Player2[p1][_x][z1].getHit() == 4)
            {
                _x--;
            }
            _x++;
            while (_x < LengthBigCube && Player2[p1][_x][z1].getHit() == 4)
            {
                _x++;
                length++;
            }
            for (int i = p1 - 1; i <= p1 + 1; i++)
                for (int j = _x - length - 1; j <= _x; j++)
                    for (int k = z1 - 1; k <= z1 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (yf + 1 < LengthBigCube && Player2[p1][yf + 1][z1].getHit() == 4)
    {
        {
            int length = 1;
            int _x = yf;
            while (_x < LengthBigCube && Player2[p1][_x][z1].getHit() == 4)
            {
                _x++;
                length++;
            }
            _x--;
            while (_x >= 0 && Player2[p1][_x][z1].getHit() == 4)
            {
                _x--;
            }

            for (int i = p1 - 1; i <= p1 + 1; i++)
                for (int j = _x; j <= _x + length + 1; j++)
                    for (int k = z1 - 1; k <= z1 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (z1 - 1 >= 0 && Player2[p1][yf][z1 - 1].getHit() == 4)
    {
        {
            int length = 1;
            int _x = z1;
            while (_x >= 0 && Player2[p1][yf][_x].getHit() == 4)
            {
                _x--;
            }
            _x++;
            while (_x < LengthBigCube && Player2[p1][yf][_x].getHit() == 4)
            {
                _x++;
                length++;
            }
            for (int i = p1 - 1; i <= p1 + 1; i++)
                for (int j = yf - 1; j <= yf + 1; j++)
                    for (int k = _x - length - 1; k <= _x; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (z1 + 1 < LengthBigCube && Player2[p1][yf][z1 + 1].getHit() == 4)
    {
        {
            int length = 1;
            int _x = z1;
            while (_x < LengthBigCube && Player2[p1][yf][_x].getHit() == 4)
            {
                _x++;
                length++;
            }
            _x--;
            while (_x >= 0 && Player2[p1][yf][_x].getHit() == 4)
            {
                _x--;
            }

            for (int i = p1 - 1; i <= p1 + 1; i++)
                for (int j = yf - 1; j <= yf + 1; j++)
                    for (int k = _x; k <= _x + length + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else
    {
        for (int i = p1 - 1; i <= p1 + 1; i++)
            for (int j = yf - 1; j <= yf + 1; j++)
                for (int k = z1 - 1; k <= z1 + 1; k++)
                    if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                        k < LengthBigCube)
                        if (Player2[i][j][k].getHit() != 4)
                        {
                            Player2[i][j][k].setIsHitten(3);
                            Player2[i][j][k].setColor(0, 0, 1);
                        }
    }
}

void hitSecondSide2()

{
    shipsLifeSecond--;
    if (x2 - 1 >= 0 && Player2[x2 - 1][p2][z2].getHit() == 4)
    {
        {
            int length = 1;
            int _x = x2;
            while (_x >= 0 && Player2[_x][p2][z2].getHit() == 4)
            {
                _x--;
            }
            _x++;
            while (_x < LengthBigCube && Player2[_x][p2][z2].getHit() == 4)
            {
                _x++;
                length++;
            }
            for (int i = _x - length - 1; i <= _x; i++)
                for (int j = p2 - 1; j <= p2 + 1; j++)
                    for (int k = z2 - 1; k <= z2 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (x2 + 1 < LengthBigCube && Player2[x2 + 1][p2][z2].getHit() == 4)
    {
        {
            int length = 1;
            int _x = x2;
            while (_x < LengthBigCube && Player2[_x][p2][z2].getHit() == 4)
            {
                _x++;
                length++;
            }
            _x--;
            while (_x >= 0 && Player2[_x][p2][z2].getHit() == 4)
            {
                _x--;
            }

            for (int i = _x; i <= _x + length + 1; i++)
                for (int j = p2 - 1; j <= p2 + 1; j++)
                    for (int k = z2 - 1; k <= z2 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (p2 - 1 >= 0 && Player2[x2][p2 - 1][z2].getHit() == 4)
    {
        {
            int length = 1;
            int _x = p2;
            while (_x >= 0 && Player2[x2][_x][z2].getHit() == 4)
            {
                _x--;
            }
            _x++;
            while (_x < LengthBigCube && Player2[x2][_x][z2].getHit() == 4)
            {
                _x++;
                length++;
            }
            for (int i = x2 - 1; i <= x2 + 1; i++)
                for (int j = _x - length - 1; j <= _x; j++)
                    for (int k = z2 - 1; k <= z2 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (p2 + 1 < LengthBigCube && Player2[x2][p2 + 1][z2].getHit() == 4)
    {
        {
            int length = 1;
            int _x = p2;
            while (_x < LengthBigCube && Player2[x2][_x][z2].getHit() == 4)
            {
                _x++;
                length++;
            }
            _x--;
            while (_x >= 0 && Player2[x2][_x][z2].getHit() == 4)
            {
                _x--;
            }

            for (int i = x2 - 1; i <= x2 + 1; i++)
                for (int j = _x; j <= _x + length + 1; j++)
                    for (int k = z2 - 1; k <= z2 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (z2 - 1 >= 0 && Player2[x2][p2][z2 - 1].getHit() == 4)
    {
        {
            int length = 1;
            int _x = z2;
            while (_x >= 0 && Player2[x2][p2][_x].getHit() == 4)
            {
                _x--;
            }
            _x++;
            while (_x < LengthBigCube && Player2[x2][p2][_x].getHit() == 4)
            {
                _x++;
                length++;
            }
            for (int i = x2 - 1; i <= x2 + 1; i++)
                for (int j = p2 - 1; j <= p2 + 1; j++)
                    for (int k = _x - length - 1; k <= _x; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (z2 + 1 < LengthBigCube && Player2[x2][p2][z2 + 1].getHit() == 4)
    {
        {
            int length = 1;
            int _x = z2;
            while (_x < LengthBigCube && Player2[x2][p2][_x].getHit() == 4)
            {
                _x++;
                length++;
            }
            _x--;
            while (_x >= 0 && Player2[x2][p2][_x].getHit() == 4)
            {
                _x--;
            }

            for (int i = x2 - 1; i <= x2 + 1; i++)
                for (int j = p2 - 1; j <= p2 + 1; j++)
                    for (int k = _x; k <= _x + length + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else
    {
        for (int i = x2 - 1; i <= x2 + 1; i++)
            for (int j = p2 - 1; j <= p2 + 1; j++)
                for (int k = z2 - 1; k <= z2 + 1; k++)
                    if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                        k < LengthBigCube)
                        if (Player2[i][j][k].getHit() != 4)
                        {
                            Player2[i][j][k].setIsHitten(3);
                            Player2[i][j][k].setColor(0, 0, 1);
                        }
    }
}

void hitThirdSide2()

{
    shipsLifeSecond--;
    if (x3 - 1 >= 0 && Player2[x3 - 1][y3][p3].getHit() == 4)
    {
        {
            int length = 1;
            int _x = x3;
            while (_x >= 0 && Player2[_x][y3][p3].getHit() == 4)
            {
                _x--;
            }
            _x++;
            while (_x < LengthBigCube && Player2[_x][y3][p3].getHit() == 4)
            {
                _x++;
                length++;
            }
            for (int i = _x - length - 1; i <= _x; i++)
                for (int j = y3 - 1; j <= y3 + 1; j++)
                    for (int k = p3 - 1; k <= p3 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (x3 + 1 < LengthBigCube && Player2[x3 + 1][y3][p3].getHit() == 4)
    {
        {
            int length = 1;
            int _x = x3;
            while (_x < LengthBigCube && Player2[_x][y3][p3].getHit() == 4)
            {
                _x++;
                length++;
            }
            _x--;
            while (_x >= 0 && Player2[_x][y3][p3].getHit() == 4)
            {
                _x--;
            }

            for (int i = _x; i <= _x + length + 1; i++)
                for (int j = y3 - 1; j <= y3 + 1; j++)
                    for (int k = p3 - 1; k <= p3 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (y3 - 1 >= 0 && Player2[x3][y3 - 1][p3].getHit() == 4)
    {
        {
            int length = 1;
            int _x = y3;
            while (_x >= 0 && Player2[x3][_x][p3].getHit() == 4)
            {
                _x--;
            }
            _x++;
            while (_x < LengthBigCube && Player2[x3][_x][p3].getHit() == 4)
            {
                _x++;
                length++;
            }
            for (int i = x3 - 1; i <= x3 + 1; i++)
                for (int j = _x - length - 1; j <= _x; j++)
                    for (int k = p3 - 1; k <= p3 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (y3 + 1 < LengthBigCube && Player2[x3][y3 + 1][p3].getHit() == 4)
    {
        {
            int length = 1;
            int _x = y3;
            while (_x < LengthBigCube && Player2[x3][_x][p3].getHit() == 4)
            {
                _x++;
                length++;
            }
            _x--;
            while (_x >= 0 && Player2[x3][_x][p3].getHit() == 4)
            {
                _x--;
            }

            for (int i = x3 - 1; i <= x3 + 1; i++)
                for (int j = _x; j <= _x + length + 1; j++)
                    for (int k = p3 - 1; k <= p3 + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (p3 - 1 >= 0 && Player2[x3][y3][p3 - 1].getHit() == 4)
    {
        {
            int length = 1;
            int _x = p3;
            while (_x >= 0 && Player2[x3][y3][_x].getHit() == 4)
            {
                _x--;
            }
            _x++;
            while (_x < LengthBigCube && Player2[x3][y3][_x].getHit() == 4)
            {
                _x++;
                length++;
            }
            for (int i = x3 - 1; i <= x3 + 1; i++)
                for (int j = y3 - 1; j <= y3 + 1; j++)
                    for (int k = _x - length - 1; k <= _x; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else if (p3 + 1 < LengthBigCube && Player2[x3][y3][p3 + 1].getHit() == 4)
    {
        {
            int length = 1;
            int _x = p3;
            while (_x < LengthBigCube && Player2[x3][y3][_x].getHit() == 4)
            {
                _x++;
                length++;
            }
            _x--;
            while (_x >= 0 && Player2[x3][y3][_x].getHit() == 4)
            {
                _x--;
            }

            for (int i = x3 - 1; i <= x3 + 1; i++)
                for (int j = y3 - 1; j <= y3 + 1; j++)
                    for (int k = _x; k <= _x + length + 1; k++)
                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                            k < LengthBigCube)
                            if (Player2[i][j][k].getHit() != 4)
                                Player2[i][j][k].setIsHitten(3);
        }
    } else
    {
        for (int i = x3 - 1; i <= x3 + 1; i++)
            for (int j = y3 - 1; j <= y3 + 1; j++)
                for (int k = p3 - 1; k <= p3 + 1; k++)
                    if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                        k < LengthBigCube)
                        if (Player2[i][j][k].getHit() != 4)
                        {
                            Player2[i][j][k].setIsHitten(3);
                            Player2[i][j][k].setColor(0, 0, 1);
                        }
    }
}

#endif //INC_3DSEEBUTTLE_HITSIDE_PLAYER2_H
