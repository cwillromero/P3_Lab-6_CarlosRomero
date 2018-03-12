#include "Bombas.h"
#include <iostream>
#include <string>

using namespace std;

Bombas::Bombas(int tipo, int x, int y, int contador) : Item(tipo, x, y)
{
    this->contador = contador;
}
Bombas::Bombas()
{
}

int Bombas::getContador()
{
    return contador;
}

void Bombas::setContador(int contador)
{

    this->contador = contador;
}

Bombas::~Bombas()
{
}

string Bombas::toString()
{
    return "X";
}
