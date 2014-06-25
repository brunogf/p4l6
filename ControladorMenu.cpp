#include <iostream>
using namespace std;

#include "ControladorMenu.h"
#include "FabricaControladores.h"
#include "Usuario.h"


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

/**
 * Precondici�n: no hay una sesi�n activa en el sistema
 * Postcondici�n: se inici� una sesi�n (y se asign� a this->cSesion)
 * 
 * Nota: aborta ejecuci�n si ocurre una falla inesperada en el inicio de sesi�n
 */
void ControladorMenu::login()
{
	// Antes de iniciar sesi�n, cerarr sesi�n anterior si la hubiera
	this->cSesion->cerrarSesion();

	// Permitir intentos ilimitados de login, hasta que ponga datos correctos
	while (!this->cSesion->sesionIniciada())
	{
		try
		{
			this->cSesion->iniciarSesion();
		}
		catch (int e)
		{
			// e == 1: ci incorrecta | e == 0: usuario cancel�
			// Por el momento, manejamos la excepci�n indistintamente
		}
	}

	// Verificar que la sesi�n fue creada, y dar la bienvenida al usuario
	try
	{
		Usuario* usuario = this->cSesion->usuarioActivo();
		cout << "Bienvenido, " << usuario->getNombre() << "\n\n";
	}
	catch (...)
	{
		cout << "Error irrecuperable: fallo desconocido en inicio de sesi�n";
	}
}

void ControladorMenu::logout()
{
	this->cSesion->cerrarSesion();
}


void ControladorMenu::menuDeOpciones()
{
	cout << "Y �ste es el men�!";
}
