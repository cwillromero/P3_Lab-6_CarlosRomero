#include "Invisible.h"
#include <iostream>
#include <string>
#include "Escenario.h"
#include<stdlib.h>

using namespace std;

Invisible::Invisible(string nombre, int tipobomba) : Escenario(nombre)
{
    this->tipobomba=tipobomba;
}

int Invisible::getAleatorio(){
      aleatorio=1 + (rand() % 3);
      return aleatorio;
}

Invisible::~Invisible()
{
}

