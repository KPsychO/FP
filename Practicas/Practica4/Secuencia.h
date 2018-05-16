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

typedef tCarta *tCartaPtr;

typedef tCartaPtr tArrayPtr[NUM_CARTAS];

typedef struct {

	tArrayPtr cartasmazo;
	int num_cartas_mazo;

} tMazo;

typedef struct {

	int cartas_avanza;
	int cartas_giro_derecha;
	int cartas_giro_izq;
	int cartas_laser;

}tMano;

void crearVacia(tMazo &mazo);				// inicializa la lista a 0 elementos
bool sacar(tMazo &mazo, tCarta &carta);		// saca una carta del principio del mazo
void insertar(tMazo &mazo, tCarta &carta);	// inserta una carta al final del mazo
void crearMazoAleatorio(tMazo &mazo);		// mete las 38 carta en el mazo y las desordena	
void liberar(tMazo &mazo);					// elimina todos los punteros del array para liberar espacio en memoria

#endif