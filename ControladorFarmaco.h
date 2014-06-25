#ifndef CONTROLADORFARMACO_H
#define	CONTROLADORFARMACO_H

#include <string>
#include <vector>

#include "IControladorFarmaco.h"

using namespace std;

class Farmaco;

class ControladorFarmaco : public IControladorFarmaco
{
    
public:
        static ControladorFarmaco* instancia();
        bool darDeAltaFarmaco(std::string nombre); // public o private? 
        vector<Farmaco*> farmacos; // protected?? 
       
private:
	static ControladorFarmaco* _instancia;
	ControladorFarmaco();     
	~ControladorFarmaco(){};
        
        bool memberFarmaco(std::string nombre);
           
};
