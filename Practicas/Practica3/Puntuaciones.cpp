#include "Puntuaciones.h"

using namespace std;

bool cargarPuntuaciones(tPuntuaciones &puntos) {

	bool carga = true;
	ifstream file;
	int i;

	file.open("puntuaciones.txt");

	if (file.is_open()) {

		i = 0;

		while ((file.eof() == false) && (i < 50)) {

			file >> puntos.puntuaciones[i].nombre;
			file >> puntos.puntuaciones[i].puntuacion;
			i++;

		}

		puntos.num_jugadores = i;
	}

	else {

		carga = false;

	}

	ordenarPuntuacion(puntos);

	return carga;
}

bool guardarPuntuaciones(const tPuntuaciones &puntos) {

	ofstream file;
	bool save = true;
	string archivo;

	cout << "Introduzca el nombre del archivo de guardado (con terminacion .txt)" << endl;
	cin >> archivo;

	file.open(archivo);

	if (file.is_open()) {

		for (size_t i = 0; i < puntos.num_jugadores; i++) {

			file << puntos.puntuaciones[i].nombre;
			file << " ";
			file << puntos.puntuaciones[i].puntuacion;
			file << endl;

		}

	}

	else
		save = false;

	return save;
}

void mostrarPuntuaciones(const tPuntuaciones &puntos) {

	for (size_t i = 0; i < puntos.num_jugadores; i++) {

		cout << puntos.puntuaciones[i].nombre << " : " << puntos.puntuaciones[i].puntuacion << endl;

	}

}

bool actualizarPuntuacion(tPuntuaciones &puntos, const string &nombre, int puntosNuevos) {

	bool update = true, jug_encontrado = false;
	size_t x, pos;

	x = 0;
	while ((!jug_encontrado) && (x < puntos.num_jugadores)) {

		if (puntos.puntuaciones[x].nombre == nombre) {

			jug_encontrado = true;
			pos = x;

		}

		x++;

	}

	if (jug_encontrado) {

		puntos.puntuaciones[pos].puntuacion = puntos.puntuaciones[pos].puntuacion + puntosNuevos;

	}

	else {

		if ((puntos.num_jugadores) == MAX_JUGADORES_HISTORIAL) {

			if (puntos.puntuaciones[puntos.num_jugadores - 1].puntuacion <= puntosNuevos) {

				puntos.puntuaciones[puntos.num_jugadores - 1].nombre = nombre;
				puntos.puntuaciones[puntos.num_jugadores - 1].puntuacion = puntosNuevos;

			}

			else {

				bool update = false;

			}

		}

		else {

			puntos.num_jugadores++;
			puntos.puntuaciones[puntos.num_jugadores - 1].nombre = nombre;
			puntos.puntuaciones[puntos.num_jugadores - 1].puntuacion = puntosNuevos;

		}

	}

	ordenarPuntuacion(puntos);

	return update;
}

void ordenarPuntuacion(tPuntuaciones &puntos) {

	// Ordenar -> Buuble sort (quick sort mas eficiente pero requiere recursión)

	for (size_t i = 0; i < (puntos.num_jugadores); i++) {

		for (size_t j = 0; j < (puntos.num_jugadores - i); j++) {

			if (puntos.puntuaciones[j].puntuacion < puntos.puntuaciones[j + 1].puntuacion) {

				swap(puntos.puntuaciones[j], puntos.puntuaciones[j + 1]);

			}

		}

	}

}