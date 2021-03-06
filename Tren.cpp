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
    listaxy.push_back("2-4");
    listaxy.push_back("2-5");
    listaxy.push_back("2-6");
    listaxy.push_back("2-7");
    listaxy.push_back("2-8");
    listaxy.push_back("3-8");
    listaxy.push_back("4-8");
    listaxy.push_back("5-8");
    listaxy.push_back("6-8");
    listaxy.push_back("7-8");
    listaxy.push_back("8-8");
    listaxy.push_back("8-7");
    listaxy.push_back("8-6");
    listaxy.push_back("8-5");
    listaxy.push_back("8-4");
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

int Tren::getY(char Y)
{
    int y = 0;
    y = parseInt(Y);
    return y;
}

int Tren::getX(char X)
{
    int x;
    x = parseInt(X);
    return x;
}

vector<string> Tren::getListaxy()
{
    return listaxy;
}

Tren::~Tren()
{
}