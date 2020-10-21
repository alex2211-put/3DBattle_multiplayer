
#include <GL/glut.h>  //библиотека GLUT
#include <fstream>
#include <filesystem>
#include "Painting.h"  //подключаем файлы заголовочные
#include "WorkWithKeys.h"  //работа с клавиатурой
#include "client.h"
//много всего и всё служебное
void Rotate(int value)
{
    if(waiting_window)
    {
        isPlayer1 = true;
        std::string t;
        sendServ(s, "when");
        t = readServ(s);
        if(t == "started\n")
        {
            isPlayer1 = readServ(s) == "0";  //расставляет слева. Если приходит 1, то начинает стрелять наш игрок
            waiting_window = false;
            glutPostRedisplay();
        }
        //glutPostRedisplay();
    }
    else if(forTwoPlayers == 2)   ///стреляем мы, в кубик справа, при этом это выражение false
    {
        std::string t;
        if (!end1 && !end2 && !end3)
        {
            sendServ(s, "?");
            t = readServ(s);
        }
        if (t == "yes")   // можно стрелять, спрашивает куда попали
        {
            isPlayer1 = false;
            sendServ(s, "hurt");
            std::string t2 = readServ(s);
            std::stringstream ss(t2);
            int i, j, k;
            ss >> i >> j >> k;
            Player1[i][j][k].setIsHitten(3);
            glutPostRedisplay();
        }
        else if (t == "yes_st")   // можно стрелять, спрашивает куда попали
        {
            isPlayer1 = false;
            glutPostRedisplay();
        }
        else if (t == "hurt")   // в нас попали, спрашиваем - куда?
        {
            int i, j, k;
            sendServ(s, "x");
            std::string t3 = readServ(s);
            std::stringstream ss(t3);
            std::string time_str;
            ss >> i >> j >> k;
            Player1[i][j][k].setIsHitten(4);
            glutPostRedisplay();
        }
        else if (t == "kill")
        {
            sendServ(s, "kill_sec");
            std::string t3 = readServ(s);
            std::stringstream ss(t3);
            int i, j, k;
            ss >> i >> j >> k;
            Player1[i][j][k].setIsHitten(4);
            p1 = i;
            yf = j;
            z1 = k;
            hitFirstSide1();
            p1 = 0;
            yf = 0;
            z1 = 0;
            glutPostRedisplay();
        }
        else if (t == "fail")
        {
            end1 = true;
            glutPostRedisplay();
        }
        else if (t == "win")   //по причине выхода другого игрока
        {
            end3 = true;
            glutPostRedisplay();
        }
    }

    glutTimerFunc(1, Rotate, 1);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  //параметры окна(двойная буферизация и всё такое)
    glutInitWindowSize(1200, 800);  //это размеры окна
    glutCreateWindow("Awesome Cube");  //это название создающегося окна
    glEnable(GL_DEPTH_TEST);  //тест глубины или что-то такое

    std::ifstream file;
    file.open(filename);
    file.close();
    if (file)   // если файл с хэшом существует
    {
        std::ifstream fin(filename); // открыли файл для чтения
        std::string word;
        fin >> word;   // считаем файл
        if (word.empty()) {   // если пустой файл
            s = init_sock(); // подключаем сокет
            hash = readServ(s);  // получаем хэш
            std::ofstream fout(
                    filename); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
            fout << hash; // запись строки в файл
            fout.close();
        }
        else hash = word;   /// если файл не пустой, то считываем хэш и ... реализовываем))) потом..
    }
    else   // если не существует
    {
        s = init_sock(); // подключаем сокет
        hash = readServ(s);  // получаем хэш
        std::ofstream fout(filename); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
        fout << hash; // запись строки в файл
        fout.close();
    }

    glutDisplayFunc(displayCell);  //вызвываем функцию, которая рисует кубы
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(specialKeys);  //вызываем функцию для поворотов кубиков
    glutReshapeFunc(changeSize);
    glutTimerFunc(1, Rotate, 2);

    glutMainLoop();  //а это бесконечный цикл
    return 0;

}