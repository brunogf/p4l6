#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

#include "ControladorSesion.h"
#include "FabricaControladores.h"

#include "TipoSexo.h"
#include "Fecha.h"
#include "Rol.h"
#include "Usuario.h"


/**
 * Testea la creaci�n de la instancia del controlador
 */
void ControladorSesion::testControlador()
{
	cout << "test";
}


/**
 * Instanciaci�n de singleton
 */
ControladorSesion* ControladorSesion::_instancia = 0;

ControladorSesion* ControladorSesion::instancia()
{
	if (_instancia == 0)
	{
		_instancia = new ControladorSesion();
	}
	
	return _instancia;
}

ControladorSesion::ControladorSesion()
{
	// Referencia (por practicidad) al Controlador de Usuarios del sistema
	FabricaControladores* Fabrica = FabricaControladores::instancia();
	this->cUsuario = Fabrica->controladorUsuario();
}


/******************************************************************************/
/********************************* P U B L I C ********************************/
/******************************************************************************/


bool ControladorSesion::iniciarSesion()
{
	// Pido al usuario que se identifique (n�mero de c�dula)
	Usuario* usuario = this->pedirIdentificacion();

	// Si el usuario no existe, no hay m�s que hacer ac�
	if (usuario == NULL)
	{
		return false;
	}

	// Pido al usuario que verifique que es �l (contrase�a)
	
	cout << "Usuario encontrado: " << usuario->getNombre();

	// Mantener puntero al usuario activo (sesi�n activa)
	this->usuario = usuario;

	return true;
}

void ControladorSesion::cerrarSesion()
{
	this->usuario = NULL;
}


/******************************************************************************/
/******************************** P R I V A T E *******************************/
/******************************************************************************/

Usuario* ControladorSesion::pedirIdentificacion()
{
	string ci;

	cout << "Ingrese su CI (hasta 7 n�meros, sin d�gito de verificaci�n) ";
	cout << "(o presione Enter para volver atr�s):\n";
	cin >> ci;

	// Mientras la c�dula ingresada no sea un entero, que vuelva a intentar
	while ((ci != "") && !this->esValidaCi(ci))
	{
		cout << "La c�dula ingresada no es v�lida. Int�ntelo nuevamente ";
		cout << "(o presione Enter para volver atr�s):\n";
		cin >> ci;
	}

	if (ci == "")
	{
		return NULL;
	}

	Usuario* usuario = this->cUsuario->findUsuario(ci);

	if (usuario == NULL)
	{
		cout << "No hay usuarios con esa c�dula de identidad en el sistema.\n";
	}

	return usuario;
}

bool ControladorSesion::pedirAutenticacion(Usuario* usuario)
{
	string pass;

	// Primer pedido (texto explicativo diferenciado)
	if (usuario->esNuevo())
	{
		cout << "Usted ingresa por primera vez al sistema. ";
		cout << "Escriba una contrase�a alfanum�rica de hasta 10 caracteres ";
		cout << "(o presione Enter para volver atr�s):\n";
	}
	else if (usuario->esUn(Rol::master))
	{
		cout << "Ingrese la contrase�a maestra, por favor ";
		cout << "(o presione Enter para volver atr�s):\n";
	}
	else
	{
		cout << "Ingrese su contrase�a, por favor ";
		cout << "(o presione Enter para volver atr�s):\n";
	}

	cin >> pass;

	// Validar contrase�a, o pedirla nuevamente hasta que ingresa una v�lida
	while ((pass != "") && (usuario->esNuevo() || !usuario->validarPass(pass)))
	{
		if (!this->esValidoPass(pass))  // Formato incorrecto
		{
			cout << "La contrase�a ingresada es inv�lida. Int�ntelo nuevamente ";
			cout << "(o presione Enter para volver atr�s):\n";
			cin >> pass;
		}
		else if (usuario->esNuevo())    // Primera vez: actualizar y activar
		{
			cout << "Bienvenido! Su nueva contrase�a ha sido guardada.\n";
			usuario->cambiarPass(pass); // Guardar nueva pass
			usuario->activar();         // Activar la cuenta
		}
		else // pass != usuario->pass   // La contrase�a ingresada no coincide
		{
			cout << "La contrase�a ingresada no es correcta. Int�ntelo nuevamente ";
			cout << "(o presione Enter para volver atr�s):\n";
			cin >> pass;
		}
	}

	return (pass != "");
}

bool ControladorSesion::esValidaCi(string ci)
{
	char ci_limpia[ci.length()+1]; // M�x: 9999999
	int ci_numeros;

	istringstream(ci) >> ci_numeros;       // Filtro solo n�meros del input
	sprintf(ci_limpia, "%d", ci_numeros);  // Casteo a string el n�mero solo

	return (ci == ci_limpia && ci.length() <= 7);
}

bool ControladorSesion::esValidoPass(string pass)
{
	return true; // TODO
}