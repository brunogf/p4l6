#include <iostream>
using namespace std;

#include "FabricaControladores.h"

/*
 * 
 */
int main(int argc, char** argv)
{
	// Creo f�brica general de controladores
	FabricaControladores* Fabrica = FabricaControladores::instancia();

	// No hay ninguna acci�n posible para invitados; es requisito loguearse
	IControladorSesion* cSesion = Fabrica->getControladorSesion();

	// Permitir intentos ilimitados hasta que ponga ci correcta
	while (!cSesion->iniciarSesion());

	IControladorUsuario* cUsuario = Fabrica->getControladorUsuario();
//cUsuario->testControlador(); // Debug
	IControladorConsulta* cConsulta = Fabrica->getControladorConsulta();
//cConsulta->testControlador(); // Debug
	IControladorDiagnostico* cDiagnostico = Fabrica->getControladorDiagnostico();
//cDiagnostico->testControlador(); // Debug

	return 0;
}

