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

bool cargarJuego(tJuego &juego);						// Realiza la carga del juego, llama a CargarTablero
void cargarTablero(tJuego &juego, bool &carga);			// Carga el tablero desde un archivo de texto
tEstadoCasilla convertirObjeto(char let_casilla);		// Convierte los caracteres del txt a tEstadoCasilla para poder trabajar con ellos
tTortuga convertirTortuga(char let_casilla);			// convierte los caracteres de las tortugas a tTortuga para poder trabajar con ellos
void mostrarJuego(const tJuego &juego);					// imprime el estado del juego desde la matriz tablero
void colorFondo(int color);								// usa librerias del sistema para poner el color de fondo
bool ejecutarTurno(tJuego &juego);						// Pide la accion a realizar en el turno y realiza las llamadas correspondientes
bool accionRobar(tJuego &juego);						// llama a "sacar" y roba una carta del mazo
bool accionSecuencia(tJuego &juego, tMazo &cartas);		// lee una secuencua de cartas y la ejecuta, llamando a las funciones correspondientes
void avanzarTortuga(tJuego &juego);						// realiza las modificaciones necesarias en el tablero y cambia la posicion de la tortuga si es posible
void girarIzquierda(tJuego &juego);						// cambia la direccion de la tortuga hacia la izquierda
void girarDerecha(tJuego &juego);						// cambia la direccion de la tortuga hacia la derecha
void lanzarLaser(tJuego &juego);						// dispara el laser, realizando los cambios necesarios en el tablero
tTecla leerTecla();										// lee las teclas al generar una secuencia
void cambiarTurno(tJuego &juego);						// juego.turnoActual++; juego.turnoActual = juego.turnoActual % juego.num_jugadores;
//bool esFinDePartida(tJuego &juego);
void incluirCarta(tMano &mano, tCarta carta);			// añade una carta a la mano del jugador

#endif