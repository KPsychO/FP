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