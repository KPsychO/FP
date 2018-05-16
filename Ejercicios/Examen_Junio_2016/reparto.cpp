#include "reparto.h"

using namespace std;

void cargar_reparto(tReparto &reparto, ifstream &file) {

	string trash;

	file >> reparto.num_actores;
	getline(file, trash);

	for (size_t i = 0; i < reparto.num_actores; i++) {

		getline(file, reparto.actores[i]);

	}

}

bool aparece(tReparto reparto, string nombre, int posicion) {

	bool encontrado = false;

	if (!encontrado && (posicion <= reparto.num_actores)) {

		if (reparto.actores[posicion] == nombre)
			encontrado = true;

		else {

			posicion++;
			aparece(reparto, nombre, posicion);

		}
	}

	return encontrado;

}