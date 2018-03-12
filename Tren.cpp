#include "Tren.h"
#include <iostream>
#include <string>
#include "Escenario.h"
using namespace std;

Tren::Tren(string nombre) : Escenario(nombre)
{
    
}

Tren::~Tren()
{
    cout<<"tren destruido";
}