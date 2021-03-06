#ifndef ICONTROLADORCONSULTA_H
#define	ICONTROLADORCONSULTA_H

#include <vector>
#include <string>

//#include "Consulta.h"
//#include "ConsultaAsistida.h"
//#include "Diagnostico.h"
//#include "Fecha.h"
//#include "FechaHora.h"
//#include "Usuario.h"
//#include "Historial.h"


class IControladorConsulta
{

public:
	virtual ~IControladorConsulta(){};
	virtual void testControlador()=0;

//	vector<Consulta*> getConsultas();
//	vector<Diagnostico*> getDiagnosticos();
//	vector<ConsultaAsistida> getConsultasAsistidas();
//	Consulta getConsultaSeleccionada();
//	setConsultas(vector<Consulta*> consultas);
//	setDiagnosticos(vector<Diagnostico*> diagnosticos);
//	setConsultasAsistidas(vector<ConsultaAsistida> consultasAsistidas);
//	setConsultaSeleccionada(Consulta consultaSeleccionada);
//
//	vector<string> listarCiPacientesConsultasPorFecha(Fecha dia);
//	seleccionarConsulta(string ci);
//	aceptarDiagnostico();
//	guardarDiagnosticosAceptados();
//	cancelarDiagnosticosConsulta();
//	cancelarEdicionConsulta();
//	vector<Consulta*> listarConsultasActivas(vector<Consulta,> FechaHora fecha);
//	borrarReserva(FechaHora fecha);
//	vector<string> obtenerListaCiPacientes(vector<Consulta*> consultas);
//	Historial crearHistorial(Usuario paciente, vector<Consulta*> consultas);
//	ingresarPacienteMedico(string ciPaciente, string ciMedico);
//	registrarConsultaComun(FechaHora fechaReserva, FechaHora fechaConsulta);
//	registrarConsultaEmergencia(string motivo, FechaHora fechaConsulta);

private:
//	vector<Consulta*> consultas;
//	vector<Diagnostico*> diagnosticos;
//	vector<ConsultaAsistida> consultasAsistidas;
//	Consulta consultaSeleccionada;

};

#endif	/* ICONTROLADORCONSULTA_H */