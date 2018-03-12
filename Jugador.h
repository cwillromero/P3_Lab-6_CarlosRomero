#include <string>
#include <iostream>
#include "Item.h"

using namespace std;

#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador: public Item{

    private:
        string nombre;
        int estado;
        int tipo;
	string simbolo;

    public:
        Jugador();
        Jugador(int,string,int,int, int, int);
        string getNombre();
        void setNombre(string);
        int getEstado();
        void setEstado(int);
        int getTipo();
        void setTipo(int);
	string toString();
    ~Jugador();
};


#endif
