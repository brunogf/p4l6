#include "Farmaco.h"

Farmaco::Farmaco(string nombre)
{
    this->nombre = nombre;
}

Farmaco::~Farmaco()
{
    // TODO
}


string Farmaco::getNombre()
{
    return this->nombre;
}

Farmaco::setNombre(string nombre)
{
    this->nombre = nombre;
}
