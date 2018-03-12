#include <string>
#include <iostream>
#include "Item.h"
#include "Escenario.h"
#include "Bombas.h"
#include <vector>
using namespace std;

#ifndef INVISIBLE_H
#define INVISIBLE_H

class Invisible : public Escenario
{
  private:
    int aleatorio;
    int tipobomba;

  public:
    Invisible(string,int); 
    Invisible();
    int getAleatorio();
    ~Invisible();
};
#endif
