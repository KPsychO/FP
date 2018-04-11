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

typedef tPuntuacionJugador tArrayPuntuacion[MAX_JUGADORES_HISTORIAL];

typedef struct {

	tArrayPuntuacion puntuaciones;
	int num_jugadores;

}tPuntuaciones;

bool cargarPuntuaciones(tPuntuaciones &puntos);
bool guardarPuntuaciones(const tPuntuaciones &puntos);
void mostrarPuntuaciones(const tPuntuaciones &puntos);
bool actualizarPuntuacion(tPuntuaciones &puntos, const std::string &nombre, int puntosNuevos);
void ordenarPuntuacion(tPuntuaciones &puntos);

#endif