
#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

Item::Item(int tipo, int x, int y)
{
    this->tipo = tipo;
    this->x = x;
    this->y = y;
}

Item::Item()
{
}

int Item::getX()
{
    return x;
}

void Item::setX(int x)
{

    this->x = x;
}

int Item::getY()
{
    return y;
}

int Item::getTipo()
{
    return tipo;
}

void Item::setTipo(int y)
{

    this->tipo = tipo;
}

void Item::setY(int y)
{

    this->y = y;
}

Item::~Item()
{
}

string Item::toString()
{
    if (tipo == 1)
        return "O";
    else
        return " ";
}
