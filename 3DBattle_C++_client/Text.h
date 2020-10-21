//
// Created by alik on 13.05.2020.
//

#ifndef INC_3DSEEBUTTLE_TEXT_H
#define INC_3DSEEBUTTLE_TEXT_H

bool menupuncts[5] = {false};   // Подсвечивает жёлтым курсор в главном меню
bool tileschange = true;        // Устанавливает размер поля от 4 до 9 (только в начале игры)
char textLast[25];
bool one_time = true;
double finish;
double start = 0;
bool placing_ships = false; // Help во время расстановки кораблей

char text[25] = "Current ship's length = ";  // Сюда также числа будут переводиться в символы
char text3[9] = "Tiles:  ";  // И сюда)
char text2[18] = "Such ships left: ";        // И сюда тоже

int ship = LengthBigCube - 2; // счетчик для расстановки кораблей
bool isPlayer1 = true;
int number_of_ships = 1; // счетчик числа кораблей с определенным кол-вом палуб (самый большой корабль всегда один)


double get_time()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count() / 1e6;
}

void renderBitmapString(float x, float y, void *font, char *string)
{                        // Помещает строку в указанном месте с указанным шрифтом и содержимым
    char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void mainMenuFunction()
{
    if (menupuncts[0])
    {
        glColor3d(1, 1, 0);
    } else
    {
        glColor3d(1, 1, 1);
    }
    if (tileschange)
    {
        renderBitmapString(-0.05, 0.3, GLUT_BITMAP_TIMES_ROMAN_24, "Start game");
    } else
    {
        renderBitmapString(-0.08, 0.3, GLUT_BITMAP_TIMES_ROMAN_24, "Resume game");
    }
    if (menupuncts[1])
    {
        glColor3d(1, 1, 0);
    } else
    {
        glColor3d(1, 1, 1);
    }
    if (tileschange)
    {
        glBegin(GL_POLYGON);
        glVertex2d(0.12, 0.15);
        glVertex2d(0.12, 0.09);
        glVertex2d(0.17, 0.12);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2d(-0.08, 0.15);
        glVertex2d(-0.08, 0.09);
        glVertex2d(-0.13, 0.12);
        glEnd();
    }
    renderBitmapString(-0.03, 0.1, GLUT_BITMAP_TIMES_ROMAN_24, text3);
    if (menupuncts[2])
    {
        glColor3d(1, 1, 0);
    } else
    {
        glColor3d(1, 1, 1);
    }
    renderBitmapString(-0.02, -0.1, GLUT_BITMAP_TIMES_ROMAN_24, "Rules");
    if (menupuncts[3])
    {
        glColor3d(1, 1, 0);
    } else
    {
        glColor3d(1, 1, 1);
    }
    renderBitmapString(-0.03, -0.3, GLUT_BITMAP_TIMES_ROMAN_24, "Credits");
    if (menupuncts[4])
    {
        glColor3d(1, 1, 0);
    } else
    {
        glColor3d(1, 1, 1);
    }
    renderBitmapString(-0.015, -0.5, GLUT_BITMAP_TIMES_ROMAN_24, "Exit");
}

void end1Function()
{
    if (one_time) {
        finish = get_time();
        one_time = false;
    }
    sprintf(&textLast[0], "%f", finish - start);
    glColor3d(1, 1, 1);
    renderBitmapString(-0.05, 0.8, GLUT_BITMAP_TIMES_ROMAN_24, "The end");
    renderBitmapString(-0.25, 0.6, GLUT_BITMAP_TIMES_ROMAN_24, "Thank you for choose 3D Sea Battle!");
    renderBitmapString(-0.01, 0.4, GLUT_BITMAP_TIMES_ROMAN_24,
                       "You lose...");

    renderBitmapString(-0.1, 0.2, GLUT_BITMAP_TIMES_ROMAN_24,
                       "You have spent:");
    glColor3d(0, 1, 0);
    renderBitmapString(-0.05, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,
                       textLast);
    glColor3d(1, 1, 1);
    renderBitmapString(-0.11, -0.2, GLUT_BITMAP_TIMES_ROMAN_24,
                       "seconds in a game");
    glColor3d(1, 1, 0);
    renderBitmapString(-0.12, -0.6, GLUT_BITMAP_TIMES_ROMAN_24, "Press Enter to exit");
}

void end2Function()
{
    if (one_time) {
        finish = get_time();
        one_time = false;
    }
    sprintf(&textLast[0], "%f", finish - start);
    glColor3d(1, 1, 1);
    renderBitmapString(-0.05, 0.8, GLUT_BITMAP_TIMES_ROMAN_24, "The end");
    renderBitmapString(-0.25, 0.6, GLUT_BITMAP_TIMES_ROMAN_24, "Thank you to choose 3D Sea Battle!");
    renderBitmapString(-0.2, 0.4, GLUT_BITMAP_TIMES_ROMAN_24,
                       "You win! Congratulations!");
    renderBitmapString(-0.1, 0.2, GLUT_BITMAP_TIMES_ROMAN_24,
                       "You have spent:");
    glColor3d(0, 1, 0);
    renderBitmapString(-0.05, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,
                       textLast);
    glColor3d(1, 1, 1);
    renderBitmapString(-0.11, -0.2, GLUT_BITMAP_TIMES_ROMAN_24,
                       "seconds in a game");
    glColor3d(1, 1, 0);
    renderBitmapString(-0.12, -0.6, GLUT_BITMAP_TIMES_ROMAN_24, "Press Enter to exit");
}

void end3Function()
{
    if (one_time) {
        finish = get_time();
        one_time = false;
    }
    sprintf(&textLast[0], "%f", finish - start);
    glColor3d(1, 1, 1);
    renderBitmapString(-0.05, 0.8, GLUT_BITMAP_TIMES_ROMAN_24, "The end");
    renderBitmapString(-0.25, 0.6, GLUT_BITMAP_TIMES_ROMAN_24, "Thank you to choose 3D Sea Battle!");
    renderBitmapString(-0.4, 0.4, GLUT_BITMAP_TIMES_ROMAN_24,
                       "Your opponent is out of the game. You win! Congratulations!");
    renderBitmapString(-0.1, 0.2, GLUT_BITMAP_TIMES_ROMAN_24,
                       "You have spent:");
    glColor3d(0, 1, 0);
    renderBitmapString(-0.05, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,
                       textLast);
    glColor3d(1, 1, 1);
    renderBitmapString(-0.11, -0.2, GLUT_BITMAP_TIMES_ROMAN_24,
                       "seconds in a game");
    glColor3d(1, 1, 0);
    renderBitmapString(-0.12, -0.6, GLUT_BITMAP_TIMES_ROMAN_24, "Press Enter to exit");
}

void rulesFunction()
{
    glColor3d(1, 1, 1);
    renderBitmapString(-0.05, 0.8, GLUT_BITMAP_TIMES_ROMAN_24, "Rules");
    renderBitmapString(-0.2, 0.6, GLUT_BITMAP_TIMES_ROMAN_24, "Welcome to 3D Sea Battle!");
    renderBitmapString(-0.35, 0.4, GLUT_BITMAP_TIMES_ROMAN_24,
                       "It is actually a usual Sea Battle game, but in 3D");
    renderBitmapString(-0.35, 0.2, GLUT_BITMAP_TIMES_ROMAN_24,
                       "Press F1 to get tips and statistics while playing");
    renderBitmapString(-0.27, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Press Esc to return to the main menu");
}

void authorsFunction()
{
    glColor3d(1, 1, 1);
    renderBitmapString(-0.06, 0.8, GLUT_BITMAP_TIMES_ROMAN_24, "Credits");
    renderBitmapString(-0.1, 0.3, GLUT_BITMAP_TIMES_ROMAN_24, "3D Sea Battle");
    renderBitmapString(-0.15, 0.1, GLUT_BITMAP_TIMES_ROMAN_24, "By Alexander Putin,");
    renderBitmapString(-0.12, -0.1, GLUT_BITMAP_TIMES_ROMAN_24, "Roman Mikhailov");
    renderBitmapString(-0.11, -0.3, GLUT_BITMAP_TIMES_ROMAN_24, "and David Kim");
    renderBitmapString(-0.09, -0.8, GLUT_BITMAP_TIMES_ROMAN_24, "MIPT 2020");
}

void helpFunction()
{
    glColor3d(1, 1, 1);
    if (placing_ships)
    {
        if (isPlayer1)
        {
            renderBitmapString(-0.05, 0.9, GLUT_BITMAP_TIMES_ROMAN_24, "Player 1");
        } else
        {
            renderBitmapString(-0.05, 0.9, GLUT_BITMAP_TIMES_ROMAN_24, "Player 2");
        }
        renderBitmapString(-0.055, 0.6, GLUT_BITMAP_TIMES_ROMAN_24, "Controls:");
        renderBitmapString(-0.3, 0.4, GLUT_BITMAP_TIMES_ROMAN_24,
                           "Press Left/Right/Up/Down to rotate the cube");
        renderBitmapString(-0.21, 0.2, GLUT_BITMAP_TIMES_ROMAN_24, "Press F7/F8/F9 to choose face");
        renderBitmapString(-0.14, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Press Enter to confirm");
        renderBitmapString(-0.06, -0.4, GLUT_BITMAP_TIMES_ROMAN_24, "Statistics:");
        sprintf(&text[24], "%u", ship);
        renderBitmapString(-0.17, -0.6, GLUT_BITMAP_TIMES_ROMAN_24, text);
        sprintf(&text2[17], "%u", number_of_ships);
        renderBitmapString(-0.11, -0.8, GLUT_BITMAP_TIMES_ROMAN_24, text2);
    } else
    {
        renderBitmapString(0, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Not ready yet");
    }
}

#endif //INC_3DSEEBUTTLE_TEXT_H
