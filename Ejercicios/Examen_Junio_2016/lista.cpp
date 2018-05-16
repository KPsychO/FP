#include "lista.h"

using namespace std;

void cargar(tListaPeliculas &lista) {

	ifstream file;
	string trash;

	file.open("peliculas.txt");

	if (file.is_open()) {

		file >> lista.num_peliculas;
		getline(file, trash);

		for (size_t i = 0; i < lista.num_peliculas; i++) {

			lista.lista_peliculas[i] = new tPelicula();
			cargar_peliculas(*lista.lista_peliculas[i], file);

		}

		file.close();

	}

	else
		cout << "[ERROR]: Archivo no encontrado" << endl;

}

tListaPeliculas filtrarPorActor(tListaPeliculas &lista, std::string actor){

	tListaPeliculas lista_filtrada;
	bool encontrado = false;
	size_t j = 0;

	lista_filtrada.num_peliculas = 0;
	
	for (size_t i = 0; i < lista.num_peliculas; i++) {

		while ((j < lista.lista_peliculas[i]->reparto.num_actores) && (!encontrado)) {

			if (lista.lista_peliculas[i]->reparto.actores[j] == actor) {

				encontrado = true;
				lista_filtrada.lista_peliculas[lista_filtrada.num_peliculas] = lista.lista_peliculas[i];
				lista_filtrada.num_peliculas++;

			}

			j++;

		}

		encontrado = false;
		j = 0;

	}

	return lista_filtrada;

}


void mostrar(tListaPeliculas lista){

	system("cls");

	for (size_t i = 0; i < lista.num_peliculas; i++) {
		
		mostrar(*lista.lista_peliculas[i]);

	}

}


void ordenarPorGenero(tListaPeliculas &lista){

	for (size_t i = 0; i < lista.num_peliculas - 1; i++) {

		for (size_t j = 0; j < lista.num_peliculas - i - 1; j++) {

			if (lista.lista_peliculas[j]->genero == lista.lista_peliculas[j + 1]->genero) {

				if (lista.lista_peliculas[j]->valoracion < lista.lista_peliculas[j + 1]->valoracion) {

					swap(lista.lista_peliculas[j], lista.lista_peliculas[j + 1]);

				}

			}

			else if (lista.lista_peliculas[j]->genero > lista.lista_peliculas[j + 1]->genero) {

				swap(lista.lista_peliculas[j], lista.lista_peliculas[j + 1]);

			}

		}

	}

}


void ordenarPorValoracion(tListaPeliculas &lista){

//Ordenar por insercion

}


void destruir(tListaPeliculas &lista){

	for (size_t i = 0; i < lista.num_peliculas; i++) {

		delete lista.lista_peliculas[i];

	}

}