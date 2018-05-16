#include "peliculas.h"

using namespace std;

void cargar_peliculas(tPelicula &pelicula, ifstream &file) {

	string trash;

	getline(file, pelicula.titulo);
	getline(file, pelicula.director);
	getline(file, pelicula.genero);
	file >> pelicula.valoracion;
	getline(file, trash);
	cargar_reparto(pelicula.reparto, file);

}

bool interviene(tPelicula pelicula, std::string nombre_actor) {

	bool interviene = false;
	int i = 0;

	while ((!interviene) || (i < pelicula.reparto.num_actores)) {

		if (pelicula.reparto.actores[i] == nombre_actor)
			interviene = true;

		i++;

	}

	return interviene;
}


void mostrar(tPelicula pelicula) {

	cout << "Titulo:		" << pelicula.titulo << endl;
	cout << "Director:	" << pelicula.director << endl;
	cout << "Genero:		" << pelicula.genero << endl;
	cout << "Valoracion:	" << pelicula.valoracion << endl;
	cout << "Reparto:		" << endl;

	for (size_t i = 0; i < pelicula.reparto.num_actores; i++) {

		cout << "	" << pelicula.reparto.actores[i] << endl;

	}

	cout << "- - - - - - - - - - -" << endl << endl;

}