#ifndef Juego_h
#define Juego_h

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>

#include "Secuencia.h"

const int MAX_JUGADORES = 4;
const int NUM_FILAS = 8;
const int NUM_COLUMNAS = 8;
const int MAX_HIELOS = 12;
const int MAX_MUROS = 20;
const int MAX_CAJAS = 8;
const int MAX_TIPOS_CASILLAS = 6;
const int NUM_COLORES = MAX_TIPOS_CASILLAS + MAX_JUGADORES;

typedef enum { AVANZA, DERECHA, IZQUIERDA, PLASER, SALIR, NADA } tTecla;
typedef enum { NORTE, SUR, ESTE, OESTE } tDir;
typedef enum { VACIA, HIELO, MURO, CAJA, JOYA, TORTUGA } tEstadoCasilla;
//typedef enum { EJECUTAR_JUGADA, ROBAR_CARTA, NINGUNA } tAccion;
//const int PALETA[NUM_COLORES] = { 1, 11, 7, 4, 12, 5, 13, 9, 10, 3 };

typedef struct {

	int numero;
	tDir direccion;

} tTortuga;

typedef struct {

	tEstadoCasilla estado;
	tTortuga tortuga;

} tCasilla;

typedef tCasilla tTablero[NUM_FILAS][NUM_COLUMNAS];


typedef struct {

	int x;
	int y;

} tCoordenada;

typedef struct {

	int num_jugador;
	std::string nombre;
	tMazo mazo;
	tMano jugada;
	tDir direccionActual;
	tDir direccionInicial;
	tCoordenada posicionActual;
	tCoordenada posicionInicial;

} tJugador;

typedef struct {

	bool hayGanador;
	int num_jugadores;
	int turnoActual;
	tJugador jugadores[MAX_JUGADORES];
	tTablero tablero;

} tJuego;

bool cargarJuego(tJuego &juego);
void cargarTablero(tJuego &juego, bool &carga);
tEstadoCasilla convertirObjeto(char let_casilla);
tTortuga convertirTortuga(char let_casilla);
void mostrarJuego(const tJuego &juego);
void colorFondo(int color);
bool ejecutarTurno(tJuego &juego);
bool accionRobar(tJuego &juego);
bool accionSecuencia(tJuego &juego, tMazo &cartas);
void avanzarTortuga(tJuego &juego);
void girarIzquierda(tJuego &juego);
void girarDerecha(tJuego &juego);
void lanzarLaser(tJuego &juego);
bool ejecutarTurno(tJuego &juego);
tTecla leerTecla();
void cambiarTurno(tJuego &juego);
//bool esFinDePartida(tJuego &juego);
void incluirCarta(tMano &mano, tCarta carta);

#endif