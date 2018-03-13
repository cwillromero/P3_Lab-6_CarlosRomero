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
   Tren(string, int);
   int getY(string);
   int getX(string);
   int parseInt(char);
   Item ***TrenRun(Item ***);
   vector<string> getListaxy();
   vector<int> getInicioTren();
   ~Tren();
};
#endif
