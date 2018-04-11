
// Diego Atance | Yaojiajing
// 1º C Ing. Informática UCM

// Parte opcional: Funcionamiento de laser avanzado


#include "Juego.h"
#include "Puntuaciones.h"

using namespace std;

int main() {

	srand(time(NULL));

	bool cargaJuego = false, cargaPuntuaciones = false, finJuego = false, partidaActiva = false;
	tJuego juego;
	int menu;
	tPuntuaciones puntos;

	cout << "	Bienvenidos a 'Tortugas roboticas'" << endl;
	cout << "|==============================================|" << endl;

	getchar();

	cargaPuntuaciones = cargarPuntuaciones(puntos);

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
							getchar();
							getchar();
							actualizarPuntuacion(puntos, juego.jugadores[juego.turnoActual].nombre, juego.num_jugadores);
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
				mostrarPuntuaciones(puntos);
				getchar();
				getchar();

				break;

			case 0:

				finJuego = true;
				guardarPuntuaciones(puntos);
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