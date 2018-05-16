#include "lista.h"
#include "checkML.h"

using namespace std;

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	tListaPeliculas lista, lista_filtrada;
	string nombre;

	cargar(lista);

	cout << "Introduzca el nombre de un actor: ";
	getline(cin, nombre);

	lista_filtrada = filtrarPorActor(lista, nombre);

	if (lista_filtrada.num_peliculas > 0) {

		ordenarPorGenero(lista_filtrada);

		mostrar(lista_filtrada);

	}

	destruir(lista);

	getchar();
	return 0;
}
