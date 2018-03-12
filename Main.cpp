using namespace std;
#include <ncurses.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include "Jugador.h"
#include "Bombas.h"
#include "Espina.h"
#include "V.h"
#include "Normal.h"
#include "Escenario.h"
#include "Invisible.h"
#include "Tren.h"
#include <typeinfo>
#include <stdlib.h>
Escenario *escenario = NULL;
void salir();
int menu();
void registro();
int tipoBomba();
void Cargando();
Jugador *jugador;
void EscenarioInvisible();
void EscenarioDeJuego();
int tipobomba;
void Juego();

int main(void)
{
    int z;
    int escenario;
    while (z != 4)
    {
        erase();
        z = menu();
        switch (z)
        {
        case 1:
        {
            //curs_set(0);
            move(5, 21);
            printw("Invisible");
            refresh();
            usleep(1000000);
            registro();
            tipobomba = tipoBomba();
            EscenarioInvisible();
            Cargando();
            erase();
            EscenarioDeJuego();
            Juego();
            //curs_set(1);
            break;
        }
        case 2:
        {
            curs_set(0);
            move(5, 21);
            printw("Tren");
            refresh();
            usleep(1000000);
            registro();
            tipobomba = tipoBomba();
            Cargando();
            erase();
            EscenarioDeJuego();
            Juego();
            curs_set(1);
            break;
        }
        case 3:
        {
            salir();
        }
        }
    }
}

int menu()
{
    initscr();
    int x, y;
    getmaxyx(stdscr, y, x);
    move(0, (x / 2 - 18));
    if (has_colors())
    {
        start_color();
        init_pair(1, COLOR_CYAN, COLOR_WHITE);
        attron(COLOR_PAIR(1));
        printw("<< Laboratorio#6  -  Carlos Romero >>");
        attroff(COLOR_PAIR(1));
        init_pair(2, COLOR_BLUE, COLOR_BLACK);
        attron(COLOR_PAIR(2));
        move(1, 0);
        printw("Escoja una Escenario [Presione Enter]:\n");
        move(2, 1);
        printw("1) Invisible \n");
        move(3, 1);
        printw("2) Tren \n");
        move(4, 1);
        printw("3) Salir \n");
        move(5, 0);
        printw("Escenario escogido: ");
        attroff(COLOR_PAIR(2));
    }
    int cx = 0;
    int cy = 2;
    int tecla;
    move(cy, cx);
    refresh();
    while (true)
    {
        noecho();
        tecla = getch();
        if (tecla == 10)
        {
            if (cy == 2)
            {
                return 1;
            }
            if (cy == 3)
            {
                return 2;
            }
            if (cy == 4)
            {
                return 3;
            }
        }
        else
        {
            //printw("%i",tecla);
            if (tecla == 65 && cy > 2)
            {
                //printw(" arriba");
                cy = cy - 1;
                move(cy, cx);
            }
            else if (tecla == 66 && cy < 4)
            {
                //printw(" abajo");
                cy = cy + 1;
                move(cy, cx);
            }
            else
            {
                //No hará nada
            }
        }
        refresh();
    }
    echo();
    return 0;
}

void salir()
{
    int x, y;
    getmaxyx(stdscr, y, x);
    erase();
    if (has_colors)
    {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(y / 2, (x / 2 - 6));
        printw("Saliendo");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        attroff(COLOR_PAIR(1));
    }
    endwin();
    exit(0);
}

void registro()
{
    erase();
    refresh();
    int x, y;
    getmaxyx(stdscr, y, x);
    move(0, (x / 2 - 12));
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    printw("<<Registro de Jugador>>");
    attroff(COLOR_PAIR(1));

    start_color();
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    move(y - 1, 0);
    printw("Presione Enter Para Continuar");
    attroff(COLOR_PAIR(4));

    char nombre[100];
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    move(1, 0);
    attron(COLOR_PAIR(2));
    printw("Ingrese su Nombre:");
    attroff(COLOR_PAIR(2));
    move(1, 20);
    echo();
    scanw("%s", nombre);
    string name = nombre;
    int estado = 1;
    int tipo = 1;
    jugador = new Jugador(2, name, estado, tipo, 0, 0);
}

int tipoBomba()
{
    erase();
    refresh();
    int x, y;
    getmaxyx(stdscr, y, x);
    move(0, (x / 2 - 10));
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    printw("<<Tipos de Bombas>>");
    attroff(COLOR_PAIR(1));
    start_color();
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    move(y - 1, 0);
    printw("Presione Enter Para Continuar");
    attroff(COLOR_PAIR(4));
    curs_set(1);
    start_color();
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    move(1, 0);
    printw("Escoja un Tipo de Bomba [Presione Enter]:\n");
    move(2, 1);
    printw("1) Normal \n");
    move(3, 1);
    printw("2) Espina \n");
    move(4, 1);
    printw("3) V \n");
    attroff(COLOR_PAIR(2));
    int cx = 0;
    int cy = 2;
    int tecla;
    move(cy, cx);
    refresh();
    while (true)
    {
        noecho();
        tecla = getch();
        if (tecla == 10)
        {
            if (cy == 2)
            {
                return 1;
            }
            if (cy == 3)
            {
                return 2;
            }
            if (cy == 4)
            {
                return 3;
            }
        }
        else
        {
            //printw("%i",tecla);
            if (tecla == 65 && cy > 2)
            {
                //printw(" arriba");
                cy = cy - 1;
                move(cy, cx);
            }
            else if (tecla == 66 && cy < 4)
            {
                //printw(" abajo");
                cy = cy + 1;
                move(cy, cx);
            }
            else
            {
                //No hará nada
            }
        }
        refresh();
    }
    curs_set(0);
    echo();
}

void Cargando()
{
    int x, y;
    getmaxyx(stdscr, y, x);
    erase();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    move(y / 2, (x / 2 - 7));
    printw("Cargando Juego");
    refresh();
    usleep(1000000 / 4);
    printw(".");
    refresh();
    usleep(1000000 / 4);
    printw(".");
    refresh();
    usleep(1000000 / 4);
    printw(".");
    refresh();
    usleep(1000000 / 4);
    attroff(COLOR_PAIR(1));
}

void EscenarioInvisible()
{

    string nombre = "Invisible";
    int ram;
    Bombas *bomba;
    ram = (1 + rand() % 4);
    //if (tipobomba == 1)
    //{
    //    bomba = new Normal(ram);
    //}
    erase();
    echo();
    if (tipobomba == 2)
    {
        move(0, 0);
        printw("Ingrese el número de bombas a equipar:");
        move(1, 0);
        refresh();
        char numb[10];
        scanw("%s", numb);
        int num_b = atoi(numb);
        bomba = new Espina(num_b);
    }
    if (tipobomba == 3)
    {
        bomba = new V();
    }
    escenario = new Invisible(nombre, tipobomba);
}

void Juego()
{
    //Crear Jugadores bot
    Jugador *botplayer1 = new Jugador(2, "Carlos", 1, 2, 10, 0);
    Jugador *botplayer2 = new Jugador(2, "Wilfredo", 1, 2, 0, 12);
    Jugador *botplayer3 = new Jugador(2, "Will", 1, 2, 10, 12);
    Jugador *botplayer4 = new Jugador(2, "Fredo", 1, 2, 5, 6);
    escenario->getMatrix()[0][0] = jugador;
    escenario->getMatrix()[botplayer1->getX()][botplayer1->getY()] = botplayer1;
    escenario->getMatrix()[botplayer2->getX()][botplayer2->getY()] = botplayer2;
    escenario->getMatrix()[botplayer3->getX()][botplayer3->getY()] = botplayer3;
    escenario->getMatrix()[botplayer4->getX()][botplayer4->getY()] = botplayer4;
    int x, y;
    int cx = 0;
    int cy = 0;
    getmaxyx(stdscr, y, x);
    move(y / 2, x / 2 - 18);
    int tecla;
    int direccion;
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    refresh();
    curs_set(0);
    while (true)
    {
        noecho();
        if ((cx >= 0 && cy >= 0) && (cx <= 10 && cy <= 12))
        {
            for (int i = 0; i < 11; i++)
            {
                for (int j = 0; j < 13; j++)
                {
                    char it = escenario->getMatrix()[i][j]->toString().at(0);
                    move(i + 1, j + 1);
                    printw("%c", it);
                }
            }

            refresh();
            tecla = getch();
            //ARRIBA
            if (tecla == 119)
            {
                direccion = 1;
            }
            //IZQUIERDA
            if (tecla == 97)
            {
                direccion = 2;
            }
            //DERECHA
            if (tecla == 100)
            {
                direccion = 3;
            }
            //ABAJO
            if (tecla == 115)
            {
                direccion = 4;
            }
            echo();
            if (direccion == 1)
            {
                if (cx - 1 >= 0)
                {
                    if (escenario->getMatrix()[cx - 1][cy]->toString() == " ")
                    {
                        Item *temp = escenario->getMatrix()[cx][cy];
                        Item *temp2 = escenario->getMatrix()[cx - 1][cy];
                        escenario->setMatrix(temp2, cx, cy);
                        escenario->setMatrix(temp, cx - 1, cy);
                        cx = cx - 1;
                    }
                }
            }
            if (direccion == 2)
            {
                if (cy - 1 >= 0)
                {
                    if (escenario->getMatrix()[cx][cy - 1]->toString() == " ")
                    {
                        Item *temp = escenario->getMatrix()[cx][cy];
                        Item *temp2 = escenario->getMatrix()[cx][cy - 1];
                        escenario->setMatrix(temp2, cx, cy);
                        escenario->setMatrix(temp, cx, cy - 1);
                        cy = cy - 1;
                    }
                }
            }
            if (direccion == 3)
            {
                if (cy + 1 <= 12)
                {
                    if (escenario->getMatrix()[cx][cy + 1]->toString() == " ")
                    {
                        Item *temp = escenario->getMatrix()[cx][cy];
                        Item *temp2 = escenario->getMatrix()[cx][cy + 1];
                        escenario->setMatrix(temp2, cx, cy);
                        escenario->setMatrix(temp, cx, cy + 1);
                        cy = cy + 1;
                    }
                }
            }
            if (direccion == 4)
            {
                if (cx + 1 <= 10)
                {
                    if (escenario->getMatrix()[cx + 1][cy]->toString() == " ")
                    {
                        Item *temp = escenario->getMatrix()[cx][cy];
                        Item *temp2 = escenario->getMatrix()[cx + 1][cy];
                        escenario->setMatrix(temp2, cx, cy);
                        escenario->setMatrix(temp, cx + 1, cy);
                        cx = cx + 1;
                    }
                }
            }
            direccion=0;
        }
    }
    attroff(COLOR_PAIR(2));
    move(y / 2, (x / 2 - 4));
    //printw("Perdió!!");
    refresh();
    //usleep(1000000 / 2);
    curs_set(1);
}

void EscenarioDeJuego()
{
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    move(14, 1);
    printw("BOMBERMAN!!!!");
    move(15, 1);
    printw("Carlos Romero");
    attroff(COLOR_PAIR(1));
    refresh();
    init_pair(22, COLOR_RED, COLOR_WHITE);
    attron(COLOR_PAIR(22));
    for (int i = 0; i < 15; i++)
    {
        move(0, i);
        printw(" ");
        move(12, i);
        printw(" ");
    }
    for (int i = 0; i < 12; i++)
    {
        move(i, 0);
        printw(" ");
        move(i, 14);
        printw(" ");
    }
    attroff(COLOR_PAIR(3));
    refresh();
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    attron(COLOR_PAIR(3));
    move(17, 0);
    printw("Nombre de Jugador: ");
    move(18, 0);
    printw("Bombas Escogidas: ");
    move(19, 0);
    printw("Escenario Escogido:  ");
    move(20, 0);
    printw("Controles:  ");
    attroff(COLOR_PAIR(3));
    refresh();
    string nombre = jugador->getNombre();
    char name[nombre.size()];
    for (int i = 0; i < nombre.size(); i++)
    {
        name[i] = nombre.at(i);
    }
    move(17, 20);
    printw("%s", name);
    move(18, 19);
    if (tipobomba == 1)
        printw("Normales");
    if (tipobomba == 2)
        printw("Espina");
    if (tipobomba == 3)
        printw("V");
    move(19, 21);
    if (escenario->getNombre() == "Invisible")
        printw("Invisible");
    else
        printw("Tren");
    move(20, 11);
    printw("w,a,s,d,x");
    if (escenario->getNombre() == "Invisible")
    {
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
        attron(COLOR_PAIR(5));
        move(21, 0);
        printw("Vidas: ");
        move(21, 8);
        attroff(COLOR_PAIR(5));
        Invisible *ev = NULL;
        ev = dynamic_cast<Invisible *>(escenario);
        printw("%i", ev->getAleatorio());
    }
    else
    {
    }
}
