#ifndef peliculas_h
#define peliculas_h

#include "reparto.h"
#include <string>
#include <fstream>
#include <Windows.h>

typedef struct {

	std::string titulo;
	std::string director;
	std::string genero;
	double valoracion;
	tReparto reparto;

} tPelicula;

void cargar_peliculas(tPelicula &pelicula, std::ifstream &file);
bool interviene(tPelicula pelicula, std::string nombre_actor);
void mostrar(tPelicula pelicula);

#endif 
