#include <string>
#include <iostream>
#include "Item.h"
#include "Bombas.h"
#include "Normal.h"
#include "V.h"
#include "Espina.h"

using namespace std;

#ifndef ESCENARIO_H
#define ESCENARIO_H

class Escenario
{
  private:
    string nombre;
    Item*** Matriz;
  public:
    Escenario(string);
    virtual string getNombre();
    void setMatrix(Item*, int, int);
    Item*** getMatrix();
    ~Escenario();
};
#endif
