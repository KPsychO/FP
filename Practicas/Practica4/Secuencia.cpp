#include "Secuencia.h"

using namespace std;

void crearVacia(tMazo &mazo) {

	mazo.num_cartas_mazo = 0;

}

bool sacar(tMazo &mazo, tCarta &carta) {

	bool sacar = true;

	if (mazo.num_cartas_mazo > 0) {

		carta = *(mazo.cartasmazo[0]);

		delete  mazo.cartasmazo[0];

		for (size_t i = 0; i < mazo.num_cartas_mazo; i++) {

			mazo.cartasmazo[i] = mazo.cartasmazo[i + 1];

		}

		mazo.num_cartas_mazo--;

	}

	else {

		sacar = false;

	}

	return sacar;

}

void insertar(tMazo &mazo, tCarta &carta) {

	mazo.cartasmazo[mazo.num_cartas_mazo] = new tCarta(carta);
	mazo.num_cartas_mazo++;

}

void crearMazoAleatorio(tMazo &mazo) {

	for (size_t i = 0; i < NUM_CARTAS; i++) {

		if (i < MAX_AVANZAR) {

			mazo.cartasmazo[i] = new tCarta(AVANZAR);

		}

		else if (i < (MAX_AVANZAR + MAX_DERECHA)) {

			mazo.cartasmazo[i] = new tCarta(GIRODERECHA);

		}

		else if (i < (MAX_AVANZAR + MAX_DERECHA + MAX_IZQUIERDA)) {

			mazo.cartasmazo[i] = new tCarta(GIROIZQUIERDA);

		}

		else {

			mazo.cartasmazo[i] = new tCarta(LASER);

		}

	}

	mazo.num_cartas_mazo = NUM_CARTAS;

	random_shuffle(&mazo.cartasmazo[0], &mazo.cartasmazo[NUM_CARTAS]);

}

void liberar(tMazo &mazo) {

	delete[] mazo.cartasmazo;

}