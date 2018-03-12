#include "Escenario.h"
#include <string>
#include <iostream>
#include "Item.h"
#include "Bombas.h"
#include "Normal.h"
#include "V.h"
#include "Espina.h"
#include <vector>
using namespace std;

Escenario::Escenario(string nombre)
{
    this->nombre = nombre;
    Matriz = new Item **[11];
    for (int i = 0; i < 11; i++)
    {
        Matriz[i] = new Item *[13];
    }

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            Matriz[i][j] = new Item(0, i, j);
        }
    }

    //Crear los obstaculos
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (i % 2 != 0 && j % 2 != 0)
            {
                Matriz[i][j] = new Item(1, i, j);
            }
        }
    }
}

Item ***Escenario::getMatrix()
{
    return Matriz;
}

string Escenario::getNombre()
{
    return nombre;
}

void Escenario::setMatrix(Item *elemento, int i, int j)
{
    Matriz[i][j] = elemento;
}

Escenario::~Escenario()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            delete Matriz[i][j];
            Matriz[i][j] = NULL;
        }
        delete Matriz[i];
        Matriz[i] = NULL;
    }
    delete[] Matriz;
    Matriz = NULL;
}
