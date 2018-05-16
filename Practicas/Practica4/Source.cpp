// Diego Atance | Yaojiajing
// 1º C Ing. Informática UCM

// Parte opcional: Funcionamiento de laser avanzado


#include "Juego.h"
#include "Puntuaciones.h"

using namespace std;

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(NULL));

	bool cargaJuego = false, cargaPuntuaciones = false, finJuego = false, partidaActiva = false;
	tJuego juego;
	int menu;

	tPuntuaciones clasificacion;
		
	inicializar(clasificacion);

	cout << "	Bienvenidos a 'Tortugas roboticas'" << endl;
	cout << "|==============================================|" << endl;
		
	getchar();

	cargaPuntuaciones = cargarPuntuaciones(clasificacion);

	if (cargaPuntuaciones == true) {

		while (!finJuego) {

			system("cls");
			cout << "Elija que desea hacer:" << endl;
			cout << "	- 1: Jugar una partida" << endl;
			cout << "	- 2: Mostrar puntuaciones" << endl;
			cout << "	- 0: Salir" << endl << endl;
			cout << "Opcion: ";
			cin >> menu;

			while ((menu < 0) || (menu > 2)) {

				system("cls");
				cout << "Introduzca una opcion valida: ";
				cin >> menu;

			}

			switch (menu) {
				
			case 1:

				cargaJuego = cargarJuego(juego);

				if (cargaJuego) {

					partidaActiva = true;

					while (partidaActiva) {

						mostrarJuego(juego);
						ejecutarTurno(juego);

						if (juego.hayGanador == true) {

							system("cls");
							cout << juego.jugadores[juego.turnoActual].nombre << " ha ganado la partida!" << endl;
							cout << "Gana " << juego.num_jugadores << " puntos." << endl;

							for (size_t i = 0; i < juego.num_jugadores; i++) {
								for (size_t j = 0; j < juego.jugadores[i].mazo.num_cartas_mazo; j++)
									delete juego.jugadores[i].mazo.cartasmazo[j];
							}

							getchar();
							getchar();
							actualizarPuntuacion(clasificacion, juego.jugadores[juego.turnoActual].nombre, juego.num_jugadores);
							partidaActiva = false;

						}

						else {

							cambiarTurno(juego);

						}

					}

				}

				else {

					cout << " [ERROR]: No se ha podido cargar el archivo" << endl;
					getchar();
					getchar();

				}

				break;

			case 2:

				system("cls");
				mostrarPuntuaciones(clasificacion);
				getchar();
				getchar();

				break;

			case 0:

				finJuego = true;
				guardarPuntuaciones(clasificacion);
				liberar(clasificacion);
				system("cls");
				cout << "Gracias por jugar!";

				break;

			}

		}

	}

	getchar();
	getchar();

	return 0;
}