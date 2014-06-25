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
	this->Fabrica = FabricaControladores::instancia();

	this->cUsuario = this->Fabrica->controladorUsuario();
	this->cSesion  = this->Fabrica->controladorSesion();
}

/**
 * Inicia el sistema:
 * 
 * � exige autenticaci�n al iniciar
 * � ofrece en todo momento posterior la posibilidad de cerrar sesi�n
 * � una vez autenticado, presenta opciones de acuerdo al perfil del usuario
 * 
 * Nota: aborta ejecuci�n si ocurre una falla inesperada en el inicio de sesi�n.
 */
void ControladorMenu::iniciar()
{
	// Todas las acciones son actualmente reservadas a usuarios autenticados
	this->login();

	// Verificar que la sesi�n fue creada, y dar la bienvenida al usuario ...
	try
	{
		Usuario* usuario = this->cSesion->usuarioActivo();
		cout << "Bienvenido, " << usuario->getNombre() << "\n\n";
	}
	// ... o abortar si fall� el login
	catch (...)
	{
		cout << "Error irrecuperable: fallo desconocido en inicio de sesi�n";
		throw 1;
	}

	this->menuDeOpciones();
}

/**
 * Precondici�n: no hay una sesi�n activa en el sistema
 * Postcondici�n: se inici� una sesi�n (y se asign� a this->cSesion)
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
}

void ControladorMenu::logout()
{
	this->cSesion->cerrarSesion();
}


void ControladorMenu::menuDeOpciones()
{
	cout << "Elija una opci�n para continuar:\n\n";

	// Listar acciones espec�ficas dependientes del estado y/o tipo de usuario
	vector<string> acciones = this->cUsuario->getAccionesHabilitadas();
	vector<string>::iterator it = acciones.begin();

	for (int i=1; i<=acciones.size(); i++, it++)
	{
		cout << i << ". " << (*it) << "\n";
	}

	cout << "\nq. Cerrar sesi�n:\n";
}
