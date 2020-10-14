//
// Created by alik on 18.03.2020.
//

#ifndef INC_3DSEEBUTTLE_CUBE_H
#define INC_3DSEEBUTTLE_CUBE_H

#include <cmath>

bool end1 = false;
bool end2 = false;
bool space = false;

int forTwoPlayers = 0;
int LengthBigCube = 4;
int forEnter = -1;
bool firstSide = false, secondSide = false, thirdSide = false;

int forOnePaint = 0;

class Cube
{
private:
    double transparency;  //прозрачность
    double length;  //длина стороны
    int forHit;  //для ударов и выбора кубика  Если 1 - выбрали. Если 2 - стоит рядом с кубиком, который выбрали. Если 3 - в него выстрелили и промахнулись. 4 - выстрелили и попали
    bool isPaint;
    //для переключений между режимами игры (выбор, стрельба)
    bool isRed{};

    double red = 0.5;
    double blue = 0.5;
    double green = 0.8;

    double x;
    double y;
    double z;

public:
    int forTransparancy;

    void changeCube(double _length, double _x, double _y, double _z, double _transparency)
    {
        this->length = _length;
        this->x = _x;
        this->y = _y;
        this->z = _z;
        this->transparency = _transparency;
    }

    Cube()
    {
        transparency = 0;
        length = 0;
        forHit = 0;
        forTransparancy = 0;
        isPaint = true;
        isRed = false;

        red = 0.5;
        blue = 0.8;
        green = 0.5;

        x = 0;
        y = 0;
        z = 0;
    }

    Cube(double length, double x, double y, double z, double transparency)
    {
        this->length = length;
        this->transparency = transparency;
        forHit = 0;
        forTransparancy = 0;
        isPaint = true;
        isRed = false;

        this->x = x;
        this->y = y;
        this->z = z;
    }


    void setColor(double Red, double Green, double Blue)
    {
        this->red = Red;
        this->blue = Blue;
        this->green = Green;
    }

    void setRed(bool _isRed)
    {
        this->isRed = _isRed;
    }

    [[nodiscard]] bool getRed() const
    {
        return isRed;
    }

    void setPaint(bool isPainted)
    {
        this->isPaint = isPainted;
    }

    [[nodiscard]] bool getPaint() const
    {
        return isPaint;
    }

    void setTransparency(double transparancy)
    {
        this->transparency = transparancy;
        forTransparancy = 1;
    }

    void setTransparancyNothing()
    {
        if (forTransparancy == 0)
        {
            transparency = 0.11;
            setColor(0.5, 0.5, 0.8);
        }
    }

    [[maybe_unused]] void paintForRotate(double angle) const;

    void paintCube() const;

    void setIsHitten(int hit)
    {
        this->forHit = hit;
    }

    [[nodiscard]] int getHit() const
    {
        return forHit;
    }

    Cube(Cube *pCube)
    {
        this->x = pCube->x;
        this->y = pCube->y;
        this->z = pCube->z;

        this->length = pCube->length;

        this->blue = pCube->blue;
        this->red = pCube->red;
        this->green = pCube->green;

        this->transparency = pCube->transparency;

        this->forHit = pCube->forHit;
        this->forTransparancy = pCube->forTransparancy;

        this->isPaint = pCube->isPaint;
        this->isRed = false;
    }
};

#endif //INC_3DSEEBUTTLE_CUBE_H
