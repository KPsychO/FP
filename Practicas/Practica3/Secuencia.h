#ifndef Secuencia_h
#define Secuencia_h

#include <algorithm>
#include <ctime>
#include <stdlib.h>

const int NUM_CARTAS = 38;
const int MAX_AVANZAR = 18;
const int MAX_DERECHA = 8;
const int MAX_IZQUIERDA = 8;

typedef enum { AVANZAR, GIROIZQUIERDA, GIRODERECHA, LASER } tCarta;

typedef struct {

	tCarta cartasmazo[NUM_CARTAS];
	int num_cartas_mazo;

}tMazo;

typedef struct {

	int cartas_avanza;
	int cartas_giro_derecha;
	int cartas_giro_izq;
	int cartas_laser;

}tMano;

void crearVacia(tMazo &mazo);
bool sacar(tMazo &mazo, tCarta &carta);
void insertar(tMazo &mazo, tCarta carta);
void crearMazoAleatorio(tMazo &mazo);

#endif