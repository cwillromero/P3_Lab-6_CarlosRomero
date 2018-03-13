#include "Tren.h"
#include <iostream>
#include <string>
#include "Escenario.h"
using namespace std;

Tren::Tren(string nombre) : Escenario(nombre)
{
    trenxy.push_back(2);
    trenxy.push_back(4);
    //POSICIONES DEL TREN
    listaxy.push_back("2-5");
    listaxy.push_back("2-6");
    listaxy.push_back("2-7");
    listaxy.push_back("2-8");
    listaxy.push_back("3-8");
    listaxy.push_back("4-8");
    listaxy.push_back("5-8");
    listaxy.push_back("6-8");
    listaxy.push_back("7-8");
    listaxy.push_back("7-7");
    listaxy.push_back("7-6");
    listaxy.push_back("7-5");
    listaxy.push_back("7-4");
}

int Tren::parseInt(char caracter)
{
    int num = 0;

    if (caracter == '1')
    {
        num = 1;
    }
    else if (caracter == '2')
    {
        num = 2;
    }
    else if (caracter == '3')
    {
        num = 3;
    }
    else if (caracter == '4')
    {
        num = 4;
    }
    else if (caracter == '5')
    {
        num = 5;
    }
    else if (caracter == '6')
    {
        num = 6;
    }
    else if (caracter == '7')
    {
        num = 7;
    }
    if (caracter == '8')
    {
        num = 8;
    }
    else if (caracter == '9')
    {
        num = 9;
    }
    return num;
}

Item ***Tren::TrenRun(Item ***Matriz)
{
    int x, y;
    for (int i = 0; i < listaxy.size(); i++)
    {
        x = getX(listaxy[i]);
        y = getY(listaxy[i]);
    }
}

int Tren::getY(string palabra)
{
    int y = 0;
    y = parseInt(palabra[2]);
    return y;
}

int Tren::getX(string palabra)
{
    int x;
    x = parseInt(palabra[0]);
    return x;
}

vector<int> Tren::getInicioTren()
{
    return trenxy;
}

vector<string> Tren::getListaxy()
{
    return listaxy;
}

Tren::~Tren()
{
}