#include "op_plantilla.h"
#include "op_est_cont.h"

using namespace std;

int main() {

	tPlantilla  plantilla;
	bool insertar = true;
	tEmpleado empleado;
	size_t menu = -1;
	string nombre;
	int edad, x;
	tEstudios est;
	tTipoContrato cont;

	while (menu != 0) {

		system("cls");
		cout << "1 - Anadir un nuevo empleado al final de la plantilla." << endl;
		cout << "2 - Anadir un nuevo empleado al principio de la plantilla." << endl;
		cout << "3 - Anadir un nuevo empleado en la posicion i de la plantilla." << endl;
		cout << "4 - Eliminar el ultimo empleado de la plantilla." << endl;
		cout << "5 - Eliminar el primer empleado de la plantilla." << endl;
		cout << "6 - Eliminar el empleado en la posicion i de la plantilla." << endl;
		cout << "7 - Eliminar todos los empleados de la plantilla." << endl;
		cout << "8 - Cargar el contenido de la plantilla de un fichero de texto." << endl;
		cout << "9 - Guardar el contenido de la plantilla en un fichero de texto." << endl;
		cout << "0 - SALIR" << endl;
		cout << " [SI ES LA PRIMERA OPERACIÓN QUE REALIZA, DEBE CARGAR EL ARCHIVO PLANTILLA.TXT]" << endl << endl;
		cout << "Introduzca la opcion que desea realizar: ";

		cin >> menu;

		while ((menu < 0) || (menu > 9)) {

			cout << "[ERROR]: Opcion no valida." << endl << endl;
			cout << "Introduzca la opcion que desea realizar: ";

		}

		switch (menu){

		case 0: system("cls"); cout << "Adios!" << endl << endl;
			break;

		case 1:
			system("cls");
			generarEmpleado(nombre, edad, est, cont);
			construir(nombre, edad, est, cont, empleado);
			insertar = insertarUltimo(plantilla, empleado);

			break;

		case 2:
			system("cls");
			generarEmpleado(nombre, edad, est, cont);
			construir(nombre, edad, est, cont, empleado);
			insertar = insertarPrimero(plantilla, empleado);

			break;
		case 3:
			system("cls");
			generarEmpleado(nombre, edad, est, cont);

			cout << "Introduzca en que posicion de la lista desea introducir al nuevo empleado: ";
			cin >> x;

			x--;

			construir(nombre, edad, est, cont, empleado);
			insertar = insertarEni(plantilla, empleado, x);

			break;
		case 4:
			eliminarUltimo(plantilla);
			break;
		case 5:
			eliminarPrimero(plantilla);
			break;
		case 6:
			cout << "Introduzca la posición de la lista del empleado que desea eliminar: ";
			cin >> x;
			x--;
			eliminarDei(plantilla, x);
			break;
		case 7:
			eliminarTodos(plantilla);
			break;
		case 8:
			cargarEmpleadosFichero(plantilla);
			break;
		case 9:
			guardar(plantilla);
			break;
		}

		if (insertar)
			mostrar(plantilla);
		
		else 
			cout << "[ERROR]: No se ha podido anadir el empleado." << endl;

		system("pause");

	}

	destruir(plantilla);

	return 0;
}