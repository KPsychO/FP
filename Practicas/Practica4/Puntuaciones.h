#ifndef Puntuaciones_h
#define Puntuaciones_h

#include <string>;
#include <fstream>;
#include <iostream>;

const int MAX_JUGADORES_HISTORIAL = 50;

typedef struct {

	std::string nombre;
	int puntuacion;

}tPuntuacionJugador;

typedef tPuntuacionJugador *tPtrPuntuacionJugador;

/*
typedef struct {

	tPuntuacionJugadorPtr puntuaciones;
	int capacidadActual;
	int num_jugadores;

} tPuntuaciones;
*/

typedef tPtrPuntuacionJugador *tArrayDinamico;

typedef struct {

	tArrayDinamico puntuaciones;
	int capacidadActual;
	int num_jugadores;

}tPuntuaciones;


bool cargarPuntuaciones(tPuntuaciones &clasificacion);													// carga las puntuaciones desde un archivo de texto
bool guardarPuntuaciones(const tPuntuaciones &clasificacion);											// guarda las puntuaciones en un archivo de texto
void mostrarPuntuaciones(tPuntuaciones &clasificacion);													// imprime las puntuaciones
bool actualizarPuntuacion(tPuntuaciones &clasificacion, const std::string &nombre, int puntosNuevos);	// actualiza las puntuaciones de los jugadores
void inicializar(tPuntuaciones &clasificacion);															// crea el array dinamico a 4 de capacidad y 0 jugadores
void redimensionar(tPuntuaciones &clasificacion);														// añade 4 posiciones al array
void ordenarPuntuacion(tPuntuaciones &clasificacion);													// ordena por puntos el array
void ordenarPuntuacionAlfabetico(tPuntuaciones &clasificacion);											// ordena alfabeticamente el array (nombre del jugador)
void liberar(tPuntuaciones &clasificacion);																// elimina el array dinamico para liberar espacio en memoria

#endif