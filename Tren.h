#include <string>
#include <iostream>
#include "Escenario.h"
#include <vector>
using namespace std;

#ifndef TREN_H
#define TREN_H

class Tren : public Escenario
{
  private:
    vector <int> trenxy;
    vector<string>listaxy;
  public:
   Tren(string);
   int getY(char);
   int getX(char);
   int parseInt(char);
   vector<string> getListaxy();
   ~Tren();
};
#endif
