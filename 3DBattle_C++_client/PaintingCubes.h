//
// Created by alik on 03.04.2020.
//

#ifndef INC_3DSEEBUTTLE_PAINTINGCUBES_H
#define INC_3DSEEBUTTLE_PAINTINGCUBES_H

#include "Cube.h"

[[maybe_unused]] void Cube::paintForRotate(double angle) const
{
    angle -= 135;
    angle = angle * 3.14 / 180;
    glBegin(GL_POLYGON);  //начинаем рисовать грань
    glColor4f(red, green, blue, transparency);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));  //здесь и далее сначала цвет
    glColor4f(red, green, blue, transparency);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) +
               (z - length / 2) * cos(angle));  //(красный, зеленый, синий, прозрачность)
    glColor4f(red, green, blue, transparency);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));  //потом идет положение точки
    glColor4f(red, green, blue, transparency);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));  //4 точки - 1 грань
    glEnd();  //закончили рисовать одну грань

    glBegin(GL_POLYGON);
    glColor4f(red, green, blue, transparency);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(red, green, blue, transparency);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(red, green, blue, transparency);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(red, green, blue, transparency);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(red, green, blue, transparency);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();

    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor4f(red, green, blue, transparency);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glEnd();

    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();

    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();

    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();

    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z - length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z - length / 2) * cos(angle));
    glEnd();

    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x + length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x + length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y - length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glColor3f(red, green, blue);
    glVertex3f((x - length / 2) * cos(angle) - (z + length / 2) * sin(angle), y + length / 2,
               (x - length / 2) * sin(angle) + (z + length / 2) * cos(angle));
    glEnd();
}

void Cube::paintCube() const
{
    glBegin(GL_POLYGON);  //начинаем рисовать грань
    glColor4f(red, green, blue, transparency);
    glVertex3f(x - length / 2, y - length / 2, z - length / 2);  //здесь и далее сначала цвет
    glColor4f(red, green, blue, transparency);
    glVertex3f(x + length / 2, y - length / 2, z - length / 2);  //(красный, зеленый, синий, прозрачность)
    glColor4f(red, green, blue, transparency);
    glVertex3f(x + length / 2, y + length / 2, z - length / 2);  //потом идет положение точки
    glColor4f(red, green, blue, transparency);
    glVertex3f(x - length / 2, y + length / 2, z - length / 2);  //4 точки - 1 грань
    glEnd();  //закончили рисовать одну грань

    glBegin(GL_POLYGON);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x - length / 2, y - length / 2, z - length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x + length / 2, y - length / 2, z - length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x + length / 2, y - length / 2, z + length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x - length / 2, y - length / 2, z + length / 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x + length / 2, y - length / 2, z - length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x + length / 2, y + length / 2, z - length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x + length / 2, y + length / 2, z + length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x + length / 2, y - length / 2, z + length / 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x + length / 2, y + length / 2, z - length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x - length / 2, y + length / 2, z - length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x - length / 2, y + length / 2, z + length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x + length / 2, y + length / 2, z + length / 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x - length / 2, y - length / 2, z - length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x - length / 2, y - length / 2, z + length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x - length / 2, y + length / 2, z + length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x - length / 2, y + length / 2, z - length / 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x - length / 2, y - length / 2, z + length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x + length / 2, y - length / 2, z + length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x + length / 2, y + length / 2, z + length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x - length / 2, y + length / 2, z + length / 2);
    glEnd();

    //пошли ребра
    //пошли ребра
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y - length / 2, z - length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y - length / 2, z - length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y - length / 2, z - length / 2);
    glColor4f(red, green, blue, transparency);
    glVertex3f(x + length / 2, y + length / 2, z - length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y + length / 2, z - length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y + length / 2, z - length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y - length / 2, z - length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y + length / 2, z - length / 2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y - length / 2, z - length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y - length / 2, z - length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y - length / 2, z - length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y - length / 2, z + length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y - length / 2, z + length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y - length / 2, z + length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y - length / 2, z - length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y - length / 2, z + length / 2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y - length / 2, z - length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y + length / 2, z - length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y + length / 2, z - length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y + length / 2, z + length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y + length / 2, z + length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y - length / 2, z + length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y - length / 2, z - length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y - length / 2, z + length / 2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y + length / 2, z - length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y + length / 2, z - length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y + length / 2, z - length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y + length / 2, z + length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y + length / 2, z + length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y + length / 2, z + length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y + length / 2, z - length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y + length / 2, z + length / 2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y - length / 2, z - length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y - length / 2, z + length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y - length / 2, z + length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y + length / 2, z + length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y + length / 2, z + length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y + length / 2, z - length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y - length / 2, z - length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y + length / 2, z - length / 2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y - length / 2, z + length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y - length / 2, z + length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y - length / 2, z + length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y + length / 2, z + length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x + length / 2, y + length / 2, z + length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y + length / 2, z + length / 2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y - length / 2, z + length / 2);
    glColor3f(red, green, blue);
    glVertex3f(x - length / 2, y + length / 2, z + length / 2);
    glEnd();
}


#endif //INC_3DSEEBUTTLE_PAINTINGCUBES_H
