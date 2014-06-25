#include <iostream>
using namespace std;

#include "ControladorMenu.h"
#include "FabricaControladores.h"


/**
 * Testea la creaci�n de la instancia del controlador
 */
void ControladorMenu::testControlador()
{
	cout << "test";
}


/**
 * Instanciaci�n de singleton
 */
ControladorMenu* ControladorMenu::_instancia = 0;

ControladorMenu* ControladorMenu::instancia()
{
	if (_instancia == 0)
	{
		_instancia = new ControladorMenu();
	}
	
	return _instancia;
}

ControladorMenu::ControladorMenu()
{
	this->Fabrica  = FabricaControladores::instancia();
	this->cUsuario = Fabrica->controladorUsuario();
	this->cSesion  = Fabrica->controladorSesion();
}


void ControladorMenu::iniciar()
{
//	bool salir; // Flag para terminar el programa
//
//	// Cargar el controlador de Men� (interfaz del programa) e iniciar programa
//	while (!salir)
//	{
//		try
//		{
//			bool salir = Menu->iniciar();
//		}
//		catch (int e)
//		{
//			salir = false;
//		}
//	}

	// No es posible continuar sin iniciar sesi�n
	this->login();
	
	this->menuDeOpciones();
}

void ControladorMenu::login()
{
	// Permitir intentos ilimitados de login, hasta que ponga datos correctos
	while (!this->cSesion->iniciarSesion());
}

void ControladorMenu::logout()
{
	this->cSesion->cerrarSesion();
}


void ControladorMenu::menuDeOpciones()
{
	cout << "Y �ste es el men�!";
}
