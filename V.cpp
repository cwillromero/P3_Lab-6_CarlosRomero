#include "V.h"
#include <iostream>
#include <string>

using namespace std;

V::V(int tipo, int x, int y, int contador) : Bombas(tipo, x, y, contador)
{
}

V::V()
{
}

string V::getSimbolo()
{
    return simbolo;
}

V::~V()
{
}

string V::toString()
{
    simbolo="0";
    return simbolo;
}
