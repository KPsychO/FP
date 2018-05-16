#ifndef lista_h
#define lista_f

#include "peliculas.h"

const int MAX_PELICULAS = 50;

typedef tPelicula *tPtrPelicula;
typedef tPtrPelicula tArrayPelicula[MAX_PELICULAS];

//typedef tPelicula tArrayPelicula [MAX_PELICULAS];

typedef struct {

	tArrayPelicula lista_peliculas;
	int num_peliculas;

} tListaPeliculas;

void cargar(tListaPeliculas &lista);
tListaPeliculas filtrarPorActor(tListaPeliculas &lista, std::string actor);
void mostrar(tListaPeliculas lista);
void ordenarPorGenero(tListaPeliculas &lista);
void ordenarPorValoracion(tListaPeliculas &lista);
void destruir(tListaPeliculas &lista);

#endif