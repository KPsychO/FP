#include "op_empleados.h"

using namespace std;

void mostrar(tEmpleado empleado) {
	cout << empleado.nombre << " (" << empleado.edad << ") - "
		<< "Estudios: " << cad_estudios(empleado.estudios) << " - "
		<< cad_contrato(empleado.contrato) << endl;
}

void construir(string nombre, int edad, tEstudios est, tTipoContrato cont, tEmpleado &empleado) {

	empleado.nombre = nombre;
	empleado.edad = edad;
	empleado.estudios = est;
	empleado.contrato = cont;
}

void generarEmpleado(string &nombre, int &edad, tEstudios &est, tTipoContrato &cont) {

	int estudios, contrato;

	cout << "Introduzca el nombre del nuevo empleado: ";
	cin >> nombre;
	cout << "Introduzca la edad del nuevo empleado: ";
	cin >> edad;
	cout << "Introduzca el nivel de estudios del nuevo empleado (0- ESO, 1- Bachillerato, 2- FP_Medio, 3- FP_Superior, 4- Grado, 5- Master, 6- Doctor): ";
	cin >> estudios;
	est = tEstudios(estudios);
	cout << "Introduzca el tipo de contratacion del nuevo empleado (0- Fijo, 1- Practicas, 2- Eventual, 3- Becario): ";
	cin >> contrato;
	cont = tTipoContrato(contrato);

}