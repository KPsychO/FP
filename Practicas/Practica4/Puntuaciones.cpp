#include "Puntuaciones.h"
#include "checkML.h"

using namespace std;

bool cargarPuntuaciones(tPuntuaciones &clasificacion) {

	string nombre;
	int puntuacion;
	bool carga = true;
	ifstream file;

	file.open("puntuaciones.txt");

	if (file.is_open()) {

		while (file.eof() == false) {

			if (clasificacion.num_jugadores == clasificacion.capacidadActual)
				redimensionar(clasificacion);

			clasificacion.puntuaciones[clasificacion.num_jugadores] = new tPuntuacionJugador;

			file >> nombre;
			clasificacion.puntuaciones[clasificacion.num_jugadores]->nombre = nombre;
			file >> puntuacion;
			clasificacion.puntuaciones[clasificacion.num_jugadores]->puntuacion = puntuacion;
			clasificacion.num_jugadores++;
	
		}


	}

	else {

		carga = false;

	}

	return carga;
}

bool guardarPuntuaciones(const tPuntuaciones &clasificacion) {

	ofstream file;
	bool save = true;
	string archivo;
	size_t x;

	cout << "Introduzca el nombre del archivo de guardado (con terminacion .txt)" << endl;
	cin >> archivo;

	file.open(archivo);

	if (file.is_open()) {

		for (size_t i = 0; i < clasificacion.num_jugadores - 1; i++) {

			file << clasificacion.puntuaciones[i]->nombre;
			file << " ";
			file << clasificacion.puntuaciones[i]->puntuacion;
			file << endl;
			x = i;

		}

		// Necesitamos evitar que quede un endl vacio al final de l archivo puntuaciones, ya que provoca doble lecturas al cargar y jugadores duplicados.

		file << clasificacion.puntuaciones[x + 1]->nombre;
		file << " ";
		file << clasificacion.puntuaciones[x + 1]->puntuacion;

	}

	else
		save = false;

	return save;
}

void mostrarPuntuaciones(tPuntuaciones &clasificacion) {

	int opc;

	cout << "1 - Ordenar por puntuaciones" << endl;
	cout << "2 - Ordenar alfabeticamente" << endl;
	cout << "Elija su opcion: " ;

	cin >> opc;

	switch (opc) {
	case 1:
		ordenarPuntuacion(clasificacion);
		break;
		
	case 2:
		ordenarPuntuacionAlfabetico(clasificacion);
		break;
	}

	for (size_t i = 0; i < clasificacion.num_jugadores; i++) {

		cout << clasificacion.puntuaciones[i]->nombre << " : " << clasificacion.puntuaciones[i]->puntuacion << endl;

	}

}

bool actualizarPuntuacion(tPuntuaciones &clasificacion, const string &nombre, int puntosNuevos) {

	bool update = true, jug_encontrado = false;
	size_t x, pos;

	x = 0;
	while ((!jug_encontrado) && (x < clasificacion.num_jugadores)) {

		if (clasificacion.puntuaciones[x]->nombre == nombre) {

			jug_encontrado = true;
			pos = x;

		}

		x++;

	}

	if (jug_encontrado) {

		clasificacion.puntuaciones[pos]->puntuacion = clasificacion.puntuaciones[pos]->puntuacion + puntosNuevos;

	}

	else {

		if ((clasificacion.num_jugadores) == clasificacion.capacidadActual) {

			redimensionar(clasificacion);
			clasificacion.puntuaciones[clasificacion.num_jugadores] = new tPuntuacionJugador;
			clasificacion.puntuaciones[clasificacion.num_jugadores]->nombre = nombre;
			clasificacion.puntuaciones[clasificacion.num_jugadores]->puntuacion = puntosNuevos;
			clasificacion.num_jugadores++;

		}

		else {

			clasificacion.puntuaciones[clasificacion.num_jugadores] = new tPuntuacionJugador;
			clasificacion.puntuaciones[clasificacion.num_jugadores]->nombre = nombre;
			clasificacion.puntuaciones[clasificacion.num_jugadores]->puntuacion = puntosNuevos;
			clasificacion.num_jugadores++;

		}

	}

	ordenarPuntuacion(clasificacion);

	return update;
}

void inicializar(tPuntuaciones &clasificacion) {

	clasificacion.puntuaciones = new tPtrPuntuacionJugador[4];
	clasificacion.capacidadActual = 4;
	clasificacion.num_jugadores = 0;

}

void redimensionar(tPuntuaciones &clasificacion) {
	
	tArrayDinamico resize_puntuaciones = new tPtrPuntuacionJugador[clasificacion.capacidadActual + 4];

	for (size_t i = 0; i < clasificacion.num_jugadores; i++) {

		resize_puntuaciones[i] = clasificacion.puntuaciones[i];

	}

	delete [] clasificacion.puntuaciones;
	
	clasificacion.puntuaciones = resize_puntuaciones;
	
	clasificacion.capacidadActual = clasificacion.capacidadActual + 4;

}

void ordenarPuntuacion(tPuntuaciones &clasificacion) {

	// Ordenar -> Buuble sort (quick sort mas eficiente pero requiere recursión)

	for (size_t i = 0; i < (clasificacion.num_jugadores - 1); i++) {

		for (size_t j = 0; j < (clasificacion.num_jugadores - 1 - i); j++) {

			if (clasificacion.puntuaciones[j]->puntuacion == clasificacion.puntuaciones[j + 1]->puntuacion) {

				if (clasificacion.puntuaciones[j]->nombre > clasificacion.puntuaciones[j + 1]->nombre)
					swap(clasificacion.puntuaciones[j], clasificacion.puntuaciones[j + 1]);

			}

			else if (clasificacion.puntuaciones[j]->puntuacion < clasificacion.puntuaciones[j + 1]->puntuacion) {

				swap(clasificacion.puntuaciones[j], clasificacion.puntuaciones[j + 1]);

			}

		}

	}

}

void ordenarPuntuacionAlfabetico(tPuntuaciones &clasificacion) {

	// Ordenar -> Buuble sort (quick sort mas eficiente pero requiere recursión)

	for (size_t i = 0; i < (clasificacion.num_jugadores); i++) {

		for (size_t j = 0; j < (clasificacion.num_jugadores - i - 1); j++) {

			if (clasificacion.puntuaciones[j]->nombre > clasificacion.puntuaciones[j + 1]->nombre) {

				swap(clasificacion.puntuaciones[j], clasificacion.puntuaciones[j + 1]);

			}

		}

	}

}

void liberar(tPuntuaciones &clasificacion) {

	delete[] clasificacion.puntuaciones;
	clasificacion.num_jugadores = 0;
	clasificacion.capacidadActual = 0;

}