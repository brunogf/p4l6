#ifndef ICONTROLADORFARMACO_H
#define	ICONTROLADORFARMACO_H

#include <string>

class Farmaco;

class IControladorFarmaco
{

public: 
        virtual bool darDeAltaFarmaco(std::string nombre)=0;
    
};
