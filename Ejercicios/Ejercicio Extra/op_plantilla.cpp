#include "op_plantilla.h"

using namespace std;

void inicializa(tPlantilla &plantilla) {
	plantilla.numEmpleados = 0;
}

bool cargarEmpleadosFichero(tPlantilla &plantilla) {
	ifstream archivo;
	bool ok = true;
	char c;
	int estudiosAux;
	int contratoAux;
	tEmpleado empleado;
	string nombre;
	int edad;
	char aux;
	tEstudios estudios;
	tTipoContrato contrato;

	inicializa(plantilla);
	archivo.open("plantilla.txt");

	if (!archivo.is_open())
		ok = false;
	else {
		getline(archivo, nombre);
		while (plantilla.numEmpleados < MAX_EMPLEADOS && nombre != "XXX") {
			archivo >> edad;
			archivo >> estudiosAux;
			estudios = tEstudios(estudiosAux);
			archivo >> contratoAux;
			contrato = tTipoContrato(contratoAux);
			construir(nombre, edad, estudios, contrato, empleado);
			insertarUltimo(plantilla, empleado);
			archivo.get(aux);
			getline(archivo, nombre);
		}
		archivo.close();
	}

	return ok;
}

bool insertarUltimo(tPlantilla &plantilla, tEmpleado empleado) {
	bool ok = true;
	if (plantilla.numEmpleados < MAX_EMPLEADOS) {
		tPtrEmp p = new tEmpleado(empleado);
		plantilla.empleados[plantilla.numEmpleados] = p;
		plantilla.numEmpleados++;
	}
	else
		ok = false;
	return ok;
}

bool insertarPrimero(tPlantilla &plantilla, tEmpleado empleado) {
	bool ok = true;
	tEmpleado empleadoc;
	if (plantilla.numEmpleados < MAX_EMPLEADOS - 1) {
		
		for (size_t i = plantilla.numEmpleados; i > 0; i--) {
			
			construir(plantilla.empleados[i - 1]->nombre, plantilla.empleados[i - 1]->edad, plantilla.empleados[i - 1]->estudios, plantilla.empleados[i - 1]->contrato, empleadoc);

			tPtrEmp emp = new tEmpleado(empleadoc);
			plantilla.empleados[i] = emp;
		}

		plantilla.numEmpleados++;
		tPtrEmp p = new tEmpleado(empleado);
		plantilla.empleados[0] = p;
	}
	else
		ok = false;
	return ok;
}

bool insertarEni(tPlantilla &plantilla, tEmpleado empleado, int x) {
	bool ok = true;
	tEmpleado empleadoc;
	if (plantilla.numEmpleados < MAX_EMPLEADOS - 1) {

		for (size_t i = plantilla.numEmpleados; i > x; i--) {

			construir(plantilla.empleados[i - 1]->nombre, plantilla.empleados[i - 1]->edad, plantilla.empleados[i - 1]->estudios, plantilla.empleados[i - 1]->contrato, empleadoc);

			tPtrEmp emp = new tEmpleado(empleadoc);
			plantilla.empleados[i] = emp;
		}

		plantilla.numEmpleados++;
		tPtrEmp p = new tEmpleado(empleado);
		plantilla.empleados[x] = p;
	}
	else
		ok = false;
	return ok;
}

void mostrar(const tPlantilla &plantilla) {
	cout << "Plantilla:" << endl;
	for (int i = 0; i < plantilla.numEmpleados; i++)
		mostrar(*plantilla.empleados[i]);
}

void eliminarTodos(tPlantilla &plantilla) {
	destruir(plantilla);
	plantilla.numEmpleados = 0;
}

void destruir(tPlantilla &plantilla) {
	for (int i = 0; i < plantilla.numEmpleados; i++)
		delete plantilla.empleados[i];
}

void eliminarUltimo(tPlantilla &plantilla) {

	delete plantilla.empleados[plantilla.numEmpleados - 1];
	plantilla.numEmpleados--;

}

void eliminarPrimero(tPlantilla &plantilla) {

	delete plantilla.empleados[0];

	for (size_t i = 0; i < plantilla.numEmpleados - 1; i++) {

		plantilla.empleados[i] = plantilla.empleados[i + 1];

	}

	plantilla.numEmpleados--;

}

void eliminarDei(tPlantilla &plantilla, int x) {

	delete plantilla.empleados[x];

	for (size_t i = x; i < plantilla.numEmpleados - 1; i++) {

		plantilla.empleados[i] = plantilla.empleados[i + 1];

	}

	plantilla.numEmpleados--;

}

void guardar(tPlantilla &plantilla) {

	ofstream file;
	string nombre_archivo;

	cout << "Introduzca el archivo de guardado (termianción .txt): ";
	cin >> nombre_archivo;

	file.open(nombre_archivo);

	if (file.is_open()) {

		for (size_t i = 0; i < plantilla.numEmpleados; i++) {

			file << plantilla.empleados[i]->nombre;
			file << endl;
			file << plantilla.empleados[i]->edad;
			file << endl;
			file << plantilla.empleados[i]->estudios;
			file << endl;
			file << plantilla.empleados[i]->contrato;
			file << endl;

		}

		file << "XXX";

	}
	else
		cout << "[ERROR]: No se abrir el archivo." << endl;

	file.close();

}