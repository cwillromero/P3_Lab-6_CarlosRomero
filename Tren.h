#include <string>
#include <iostream>
//#include "Item.h"
#include "Escenario.h"
//#include "Bombas.h"
#include <vector>
using namespace std;

#ifndef TREN_H
#define TREN_H

class Tren : public Escenario
{
  private:
    vector <int> postren;
    vector<string>listapos;
  public:
    Tren(string); /*ale,valor,tipo bomba,string*/
  //  Tren();
   ~Tren();
};
#endif
