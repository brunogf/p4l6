#include <iostream>
using namespace std;

#include "ControladorFarmaco.h"

ControladorFarmaco* ControladorFarmaco::_instancia = 0;

ControladorFarmaco* ControladorFarmaco::instancia()
{   
    if (_instancia == 0)
	{
		_instancia = new ControladorFarmaco();
	}
	
	return _instancia;   
    
}

bool ControladorFarmaco::darDeAltaFarmaco(std::string nombre)
{
    if (!ControladorFarmaco::memberFarmaco(nombre)) 
    {
        Farmaco f = Farmaco(nombre);
        farmacos.insert(f);
        return true; // el farmaco se dio de alta correctamente. 
        
    }
    else
    {
        return false; // en el main hay que pedirle que ingrese otro nombre o que cancele.        
    }
}

bool ControladorFarmaco::memberFarmaco(string nombre)
{
    for(vector<Farmaco*>::iterator it = farmacos.begin(); it != farmacos.end(); ++it)
    {
        if ((*it)->getNombre() == nombre)
        {
            return true;
        }
    }
    
    return false;
}
