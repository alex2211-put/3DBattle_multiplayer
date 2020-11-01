
#include <GL/glut.h>  //библиотека GLUT
#include <fstream>
#include <filesystem>
#include "Painting.h"  //подключаем файлы заголовочные
#include "WorkWithKeys.h"  //работа с клавиатурой
#include "client.h"
//много всего и всё служебное
double time_serv = 0;

void socket_starting_work()
{
    std::ifstream file;
    file.open(filename);
    file.close();
    if (file)   // если файл с хэшом существует
    {
        std::ifstream fin(filename); // открыли файл для чтения
        std::string word;
        fin >> word;   // считаем файл
        if (word.empty()) {   // если пустой файл
            if (s != -1)
            {
                hash = readServ(s);  // получаем хэш
                std::ofstream fout(
                        filename); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
                fout << hash; // запись строки в файл
                fout.close();
            }
        }
        else {
            if (s != -1) {
                hash = readServ(s);   /// если файл не пустой, то считываем хэш и ... реализовываем))) потом..
                sendServ(s, "back " + word);   // отправляем что мы вернулись назад после поломки локальной
                std::string t = readServ(s);
                if (t == "no") {
                    fs::remove_all(filename);
                    std::ofstream fout(filename); // создаём ofstream для записи и связываем его с файлом
                    fout << hash; // запись строки в файл
                    fout.close();
                } else {
                    hash = word;
                    if (t == "ready\n") {
                        t = readServ(s);
                        int count_map = 0;
                        int len = int(pow(t.length(), 1. / 3));
                        for (int i = 0; i <= len; i++)
                            for (int j = 0; j <= len; j++)
                                for (int k = 0; k <= len; k++) {
                                    Player1[i][j][k].setIsHitten(int(t[count_map]) - 48);
                                    count_map++;
                                }
                        one = false;
                        forOnePaint = 0;
                        forEnter = 0;
                        movement = true;
                        glClearColor(0.07, 0.07, 0.25, 0.f);
                        waiting_window = true;
                        mainmenu = false;
                        forTwoPlayers = 2;
                    } else if (t == "not_ready") {}
                    else if (t == "wait\n") {
                        std::cout << "wait";
                        t = readServ(s);
                        int count_map = 0;
                        int len = int(pow(t.length(), 1. / 3));
                        for (int i = 0; i <= len; i++)
                            for (int j = 0; j <= len; j++)
                                for (int k = 0; k <= len; k++) {
                                    Player1[i][j][k].setIsHitten(int(t[count_map]) - 48);
                                    count_map++;
                                }
                        one = false;
                        forOnePaint = 0;
                        forEnter = 0;
                        movement = true;
                        glClearColor(0.07, 0.07, 0.25, 0.f);
                        waiting_window = true;
                        mainmenu = false;
                        forTwoPlayers = 2;
                        isPlayer1 = true;
                        t = readServ(s);
                        count_map = 0;
                        len = int(pow(t.length(), 1. / 3));
                        for (int i = 0; i <= len; i++)
                            for (int j = 0; j <= len; j++)
                                for (int k = 0; k <= len; k++) {
                                    Player2[i][j][k].setIsHitten(int(t[count_map]) - 48);
                                    count_map++;
                                }
                    } else if (t == "fire\n") {
                        std::cout << "fire" << std::endl;
                        t = readServ(s);
                        std::cout << t << std::endl;
                        std::cout << std::endl;
                        int count_map = 0;
                        int len = int(pow(t.length(), 1. / 3));
                        for (int i = 0; i <= len; i++)
                            for (int j = 0; j <= len; j++)
                                for (int k = 0; k <= len; k++) {
                                    std::cout << int(t[count_map]) - 48;
                                    Player1[i][j][k].setIsHitten(int(t[count_map]) - 48);
                                    count_map++;
                                }
                        one = false;
                        forOnePaint = 0;
                        forEnter = 0;
                        movement = true;
                        glClearColor(0.07, 0.07, 0.25, 0.f);
                        waiting_window = false;
                        mainmenu = false;
                        forTwoPlayers = 2;
                        isPlayer1 = false;
                        t = readServ(s);
                        count_map = 0;
                        len = int(pow(t.length(), 1. / 3));
                        for (int i = 0; i <= len; i++)
                            for (int j = 0; j <= len; j++)
                                for (int k = 0; k <= len; k++) {
                                    Player2[i][j][k].setIsHitten(int(t[count_map]) - 48);
                                    count_map++;
                                }
                    }
                }
            }
        }
    }
    else   // если не существует
    {
        if (s != -1) {
            hash = readServ(s);  // получаем хэш
            std::ofstream fout(
                    filename); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
            fout << hash; // запись строки в файл
            fout.close();
        }
    }
}

void Rotate(int value)
{
    if (s == -1) {
        if (time_serv == 0) {
            time_serv = get_time();
            server_window = true;
        } else if (get_time() - time_serv > 1)
        {
            time_serv = get_time();
            server_window = true;
            glutPostRedisplay();
            try {
                s = init_sock();
                if (s != -1)
                    socket_starting_work();
            }
            catch (...) {
                s = -1;
            }

        }
    }
    else if(waiting_window)
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
    else if(forTwoPlayers == 2)   //стреляем мы, в кубик справа, при этом это выражение false
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
            std::string m;
            for (int r = 0; r < LengthBigCube; r++)
                for (int u = 0; u < LengthBigCube; u++)
                    for (int y = 0; y < LengthBigCube; y++)
                        m += std::to_string(Player1[r][u][y].getHit()) + " ";
            sendServ(s, "after_kill " + m + " " + std::to_string(LengthBigCube));
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

    s = init_sock();
    socket_starting_work();


    glutDisplayFunc(displayCell);  //вызвываем функцию, которая рисует кубы
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(specialKeys);  //вызываем функцию для поворотов кубиков
    glutReshapeFunc(changeSize);
    glutTimerFunc(1, Rotate, 2);

    glutMainLoop();  //а это бесконечный цикл
    return 0;

}