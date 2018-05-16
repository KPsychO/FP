#ifndef reparto_h
#define reparto_h
#include <string>
#include <fstream>
#include <iostream>

const int MAX_ACTORES = 10;

typedef std::string tActores[MAX_ACTORES];

typedef struct {

	tActores actores;
	int num_actores;

} tReparto;

void cargar_reparto(tReparto &reparto, std::ifstream &file);
bool aparece(tReparto reparto, std::string nombre, int posicion);

#endif