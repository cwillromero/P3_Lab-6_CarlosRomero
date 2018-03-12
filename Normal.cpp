#include "Normal.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

Normal::Normal(int tipo, int x, int y, int contador, int alcance): Bombas(tipo, x, y, contador)
{
    this->alcance = alcance;
}
Normal::Normal()
{
}

int Normal::getAlcance()
{
    alcance == 1 + rand() % (4);
    return alcance;
}

void Normal::setAlcance(int alcance)
{
    this->alcance = alcance;
}

Normal::~Normal()
{
}

string Normal::toString()
{
    simbolo = "*";
    return simbolo;
}
