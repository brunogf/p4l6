#ifndef ICONTROLADORUSUARIO_H
#define	ICONTROLADORUSUARIO_H

#include <string>
#include <vector>

#include "TipoSexo.h"
#include "Fecha.h"
#include "Rol.h"


class Usuario;

class IControladorUsuario
{

protected:
	vector<Usuario*> usuarios;

public:
	virtual ~IControladorUsuario(){};
	virtual void testControlador()=0;

	virtual Usuario* crearMaster(string ci, string pass, string nombre)=0;

	virtual Usuario* altaUsuario(string ci, string nombre, string apellido,
	                             TipoSexo, Fecha, vector<Rol>)=0;
	virtual Usuario* findUsuario(string ci)=0;

};

#endif	/* ICONTROLADORUSUARIO_H */

