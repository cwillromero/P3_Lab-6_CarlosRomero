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
int e;
Jugador *jugador;
void EscenarioInvisible();
void EscenarioDeJuego();
int tipobomba;
void Juego();
void crearBomba();
int vida = 4;
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
            e = 1;
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
            e = 2;
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
    escenario = new Invisible(nombre, tipobomba);
}

void Juego()
{
    //Crear Jugadores bot
    Jugador *botplayer1 = new Jugador(2, "Carlos", 1, 2, 10, 0);
    Jugador *botplayer2 = new Jugador(2, "Wilfredo", 1, 2, 0, 12);
    Jugador *botplayer3 = new Jugador(2, "Will", 1, 2, 10, 12);
    Jugador *botplayer4 = new Jugador(2, "Fredo", 1, 2, 5, 6);
    //Crear Jugador
    escenario->getMatrix()[0][0] = jugador;
    //Meterlos en la Matriz
    escenario->setMatrix(botplayer1, 10, 0);
    escenario->setMatrix(botplayer2, 0, 12);
    escenario->setMatrix(botplayer3, 10, 12);
    escenario->setMatrix(botplayer4, 5, 6);
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
        move(21, 8);
        printw("%i", vida);
        if (vida == 0)
        {
            break;
        }
        noecho();
        int cont = 0;
        if ((cx >= 0 && cy >= 0) && (cx <= 10 && cy <= 12))
        {
            for (int i = 0; i < 11; i++)
            {
                for (int j = 0; j < 13; j++)
                {
                    char it = escenario->getMatrix()[i][j]->toString().at(0);
                    if (escenario->getMatrix()[i][j]->toString() == "Q")
                    {
                        Normal *bomba;
                        bomba = dynamic_cast<Normal *>(escenario->getMatrix()[i][j]);
                        bomba->setContador(bomba->getContador() - 1);
                        escenario->getMatrix()[i][j]->toString();
                        int alcance = bomba->getAlcance();
                        refresh();
                        if (bomba->getContador() == 0)
                        {
                            if (i - alcance >= 0)
                                for (int k = 1; k <= alcance; k++)
                                {
                                    if (escenario->getMatrix()[i - k][j]->toString() != "O")
                                        escenario->setMatrix(new Item(0, i - k, j), i - k, j);
                                    else
                                        k = 100;
                                }
                            if (i + alcance <= 10)
                                for (int k = 1; k <= alcance; k++)
                                {
                                    if (escenario->getMatrix()[i + k][j]->toString() != "O")
                                        escenario->setMatrix(new Item(0, i + k, j), i + k, j);
                                    else
                                        k = 100;
                                }

                            if (j - alcance >= 0)
                                for (int k = 1; k <= alcance; k++)
                                {
                                    if (escenario->getMatrix()[i][j - k]->toString() != "O")
                                        escenario->setMatrix(new Item(0, i, j - k), i, j - k);
                                    else
                                        k = 100;
                                }

                            if (j + alcance <= 12)
                                for (int k = 1; k <= alcance; k++)
                                {
                                    if (escenario->getMatrix()[i][j + k]->toString() != "O")
                                        escenario->setMatrix(new Item(0, i, j + k), i, j + k);
                                    else
                                        k = 100;
                                }
                            escenario->setMatrix(new Item(0, i, j), i, j);
                        }
                    }
                    move(i + 1, j + 1);
                    printw("%c", it);
                    if (escenario->getMatrix()[i][j]->toString() == "8")
                    {
                        cont = cont + 1;
                    }
                }
            }
            if (cont == 0)
            {
                vida = vida - 1;
                escenario->getMatrix()[cx][cy] = jugador;
            }
            refresh();
            tecla = getch();
            //ARRIBA
            if (tecla == 119)
            {
                direccion = 1;
            }
            //IZQUIERDA
            else if (tecla == 97)
            {
                direccion = 2;
            }
            //DERECHA
            else if (tecla == 100)
            {
                direccion = 3;
            }
            //ABAJO
            else if (tecla == 115)
            {
                direccion = 4;
            }
            //Crear Bomba
            else if (tecla == 109)
            {
                direccion = 5;
            }
            else
            {
                direccion = 0;
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
            if (direccion == 5)
            {
                crearBomba();
            }
        }
    }
    attroff(COLOR_PAIR(2));
    move(y / 2, (x / 2 - 4));
    printw("Perdió!!");
    refresh();
    usleep(1000000 / 2);
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
    printw("w,a,s,d,m");
    move(21, 0);
    printw("Vidas: ");
    if (escenario->getNombre() == "Invisible")
    {
        move(21, 8);
        Invisible *ev = dynamic_cast<Invisible *>(escenario);
        vida = ev->getAleatorio();
        printw("%i", vida);
    }
    else
    {
        vida = 0;
        move(21, 8);
        printw("%i", vida);
    }
}

void crearBomba()
{

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (escenario->getMatrix()[i][j]->toString() == "8")
            {
                if (j + 1 <= 12)
                {
                    if (escenario->getMatrix()[i][j + 1]->toString() == " ")
                    {
                        if (tipobomba == 1)
                        {
                            escenario->setMatrix(new Normal(1, i, j + 1, 4), i, j + 1);
                        }
                        if (tipobomba == 2)
                        {
                            escenario->setMatrix(new Espina(1, i, j + 1, 4, 0), i, j + 1);
                        }
                        if (tipobomba == 3)
                        {
                            escenario->setMatrix(new V(1, i, j + 1, 4), i, j + 1);
                        }
                        break;
                    }
                }
                if (i + 1 <= 10)
                {
                    if (escenario->getMatrix()[i + 1][j]->toString() == " ")
                    {
                        if (tipobomba == 1)
                        {
                            escenario->setMatrix(new Normal(1, i + 1, j, 4), i + 1, j);
                        }
                        if (tipobomba == 2)
                        {
                            escenario->setMatrix(new Espina(1, i + 1, j, 4, 0), i + 1, j);
                        }
                        if (tipobomba == 3)
                        {
                            escenario->setMatrix(new V(1, i + 1, j, 4), i + 1, j);
                        }
                        break;
                    }
                }
                if (j - 1 >= 0)
                {
                    if (escenario->getMatrix()[i][j - 1]->toString() == " ")
                    {
                        if (tipobomba == 1)
                        {
                            escenario->setMatrix(new Normal(1, i, j - 1, 4), i, j - 1);
                        }
                        if (tipobomba == 2)
                        {
                            escenario->setMatrix(new Espina(1, i, j - 1, 4, 0), i, j - 1);
                        }
                        if (tipobomba == 3)
                        {
                            escenario->setMatrix(new V(1, i, j - 1, 4), i, j - 1);
                        }
                        break;
                    }
                }
                if (i - 1 >= 0)
                {
                    if (escenario->getMatrix()[i - 1][j]->toString() == " ")
                    {
                        if (tipobomba == 1)
                        {
                            escenario->setMatrix(new Normal(1, i - 1, j, 4), i - 1, j);
                        }
                        if (tipobomba == 2)
                        {
                            escenario->setMatrix(new Espina(1, i - 1, j, 4, 0), i - 1, j);
                        }
                        if (tipobomba == 3)
                        {
                            escenario->setMatrix(new V(1, i - 1, j, 4), i - 1, j);
                        }
                        break;
                    }
                }
            }
        }
    }
}
