#include "Juego.h"
#include "checkML.h"

using namespace std;

bool cargarJuego(tJuego &juego) {

	bool carga = true;
	tCarta carta;

	cargarTablero(juego, carga);

	if (carga) {

		juego.turnoActual = 0;
		juego.hayGanador = false;

		for (size_t i = 0; i < juego.num_jugadores; i++) {

			cout << "Introduzca el nombre del jugador: ";
			cin >> juego.jugadores[i].nombre;

			juego.jugadores[i].num_jugador = i;

			crearMazoAleatorio(juego.jugadores[i].mazo);

			for (size_t j = 0; j < 3; j++) {

				carga = sacar(juego.jugadores[i].mazo, carta);

				switch (carta) {
				case AVANZAR: juego.jugadores[i].jugada.cartas_avanza++; break;
				case GIRODERECHA: juego.jugadores[i].jugada.cartas_giro_derecha++; break;
				case GIROIZQUIERDA: juego.jugadores[i].jugada.cartas_giro_izq++; break;
				case LASER: juego.jugadores[i].jugada.cartas_laser++; break;
				}

			}

		}

	}

	return carga;
}

void cargarTablero(tJuego &juego, bool &carga) {

	bool encontrado = false;
	string tablero, trash;
	int num_jug = 0;
	ifstream file;
	int jug, num_tortuga = 0;
	char let_casilla;
	tEstadoCasilla objeto;
	tTortuga tortuga;

	cout << "Introduzca el nombre del archivo desde donde desea cargar los tableros (con terminacion .txt): ";
	cin >> tablero;

	cout << "Introduzca el numero de jugadores de la partida: ";
	cin >> num_jug;

	while ((num_jug > 4) || (num_jug < 1)) {
		
		cout << "Introduzca el numero de jugadores de la partida: ";
		cin >> num_jug;

	}

	juego.num_jugadores = num_jug;

	file.open(tablero);

	if (file.is_open()) {

		while (!encontrado) {

			file >> jug;

			getline(file, trash);

			if (jug != num_jug) {

				for (size_t i = 0; i < NUM_FILAS; i++) {

					getline(file, trash);

				}

			}
			else {

				carga = true;
				encontrado = true;

			}

			if (encontrado) {

				for (size_t i = 0; i < NUM_FILAS; i++) {

					for (size_t j = 0; j < NUM_COLUMNAS; j++) {

						file.get(let_casilla);

						if ((let_casilla == 'D') || (let_casilla == 'U') || (let_casilla == 'R') || (let_casilla == 'L')) {

							tortuga = convertirTortuga(let_casilla);
							juego.tablero[i][j].estado = TORTUGA;
							juego.tablero[i][j].tortuga = tortuga;
							juego.tablero[i][j].tortuga.numero = num_tortuga + 1;
							juego.jugadores[num_tortuga].jugada.cartas_avanza = 0;
							juego.jugadores[num_tortuga].jugada.cartas_giro_derecha = 0;
							juego.jugadores[num_tortuga].jugada.cartas_giro_izq = 0;
							juego.jugadores[num_tortuga].jugada.cartas_laser = 0;
							juego.jugadores[num_tortuga].posicionActual.x = i;
							juego.jugadores[num_tortuga].posicionInicial.x = i;
							juego.jugadores[num_tortuga].posicionActual.y = j;
							juego.jugadores[num_tortuga].posicionInicial.y = j;
							juego.jugadores[num_tortuga].direccionActual = juego.tablero[i][j].tortuga.direccion;
							juego.jugadores[num_tortuga].direccionInicial = juego.tablero[i][j].tortuga.direccion;
							num_tortuga++;

						}
						else {

							objeto = convertirObjeto(let_casilla);
							juego.tablero[i][j].estado = objeto;
							juego.tablero[i][j].tortuga.numero = 0;

						}

					}

					getline(file, trash);

				}

			}

			else {

				carga = false;

			}

		}

	}

	else {

		carga = false;

	}

}

tEstadoCasilla convertirObjeto(char let_casilla) {

	tEstadoCasilla objeto;

	switch (let_casilla) {

	case 'C': objeto = CAJA;
		break;
	case '#': objeto = MURO;
		break;
	case '@': objeto = HIELO;
		break;
	case '$': objeto = JOYA;
		break;
	case ' ': objeto = VACIA;

	}


	return objeto;

}

tTortuga convertirTortuga(char let_casilla) {

	tTortuga tortuga;

	switch (let_casilla) {

	case 'U': tortuga.direccion = NORTE;
		break;
	case 'D': tortuga.direccion = SUR;
		break;
	case 'L': tortuga.direccion = OESTE;
		break;
	case 'R': tortuga.direccion = ESTE;
		break;

	}

	return tortuga;
}

void mostrarJuego(const tJuego &juego) {

	string aux;
	int color;

	system("cls");

	cout << endl;

	for (size_t i = 0; i < NUM_COLUMNAS; i++) {

		cout << "	";

		for (size_t j = 0; j < NUM_FILAS; j++) {

			switch (juego.tablero[i][j].estado) {
			case VACIA: color = 1; colorFondo(color); aux = " "; break;
			case CAJA: color = 4;  colorFondo(color); aux = "[]"; break;
			case MURO: color = 7;  colorFondo(color); aux = "||"; break;
			case HIELO: color = 11;  colorFondo(color); aux = "*"; break;
			case JOYA: color = 12;  colorFondo(color); aux = "00"; break;
			case TORTUGA:

				switch (juego.tablero[i][j].tortuga.numero) {

				case 1: color = 5; break;
				case 2: color = 13; break;
				case 3: color = 9; break;
				case 4: color = 2; break;

				}

				switch (juego.tablero[i][j].tortuga.direccion) {
				case NORTE: colorFondo(color); aux = "^^"; break;
				case SUR: colorFondo(color); aux = "vv"; break;
				case ESTE: colorFondo(color); aux = ">>"; break;
				case OESTE: colorFondo(color); aux = "<<"; break;
				}
			}

			cout << setw(2) << aux;
			color = 1;
			colorFondo(color);
		}

		cout << endl;

	}

	color = 0;
	colorFondo(color);

	cout << endl << "JUGADORES:" << endl;

	for (size_t i = 0; i < juego.num_jugadores; i++) {

		if ((juego.turnoActual) == juego.jugadores[i].num_jugador) {

			cout << " >> ";

		}

		switch (juego.jugadores[i].num_jugador) {

		case 0: color = 5; break;
		case 1: color = 13; break;
		case 2: color = 9; break;
		case 3: color = 2; break;

		}

		colorFondo(color);

		cout << "	" << i + 1 << ". " << setw(10) << juego.jugadores[i].nombre << ":";
		color = 0;
		colorFondo(color);
		cout << " " << juego.jugadores[i].jugada.cartas_avanza << " ";
		color = 3;
		colorFondo(color);
		cout << "^";
		color = 0;
		colorFondo(color); 
		cout << " " << juego.jugadores[i].jugada.cartas_giro_izq << " ";
		color = 3;
		colorFondo(color);
		cout << "<";
		color = 0;
		colorFondo(color);
		cout << " " << juego.jugadores[i].jugada.cartas_giro_derecha << " ";
		color = 3;
		colorFondo(color);
		cout << ">";
		color = 0;
		colorFondo(color);
		cout << " " << juego.jugadores[i].jugada.cartas_laser << " ";
		color = 3;
		colorFondo(color); 
		cout << "~";
		color = 0;
		colorFondo(color);

		cout << endl << endl;

	}

}

void colorFondo(int color) {

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));

}

bool accionRobar(tJuego &juego) {

	bool robar;
	tCarta carta;

		robar = sacar(juego.jugadores[juego.turnoActual].mazo, carta);

		incluirCarta(juego.jugadores[juego.turnoActual].jugada, carta);

	if (!robar){

		cout << "[ERROR]: No se pudo robar ninguna carta del mazo." << endl;

	}

	return robar;
}

bool accionSecuencia(tJuego &juego, tMazo &mazo) {

	bool hayGanador = false, sacarCarta = false;
	tCarta carta;

	while ((!hayGanador) && (mazo.num_cartas_mazo > 0)) {

		sacarCarta = sacar(mazo, carta);

		if (sacarCarta) {

			switch (carta) {
			case AVANZAR: 
				if ( juego.jugadores[juego.turnoActual].jugada.cartas_avanza > 0)
				avanzarTortuga(juego);
				break;
			case GIRODERECHA: 
				if (juego.jugadores[juego.turnoActual].jugada.cartas_giro_derecha > 0)
				girarDerecha(juego);
				break;
			case GIROIZQUIERDA: 
				if (juego.jugadores[juego.turnoActual].jugada.cartas_giro_izq > 0)
				girarIzquierda(juego);
				break;
			case LASER: 
				if (juego.jugadores[juego.turnoActual].jugada.cartas_laser > 0)
				lanzarLaser(juego);
				break;
			}
		}

	}

	return hayGanador;

}

void avanzarTortuga(tJuego &juego) {

	int x = juego.jugadores[juego.turnoActual].posicionActual.x;
	int y = juego.jugadores[juego.turnoActual].posicionActual.y;

	bool aux = true;

	int newx = x, newy = y;

	switch (juego.jugadores[juego.turnoActual].direccionActual) {

	case OESTE:
		newy = y - 1;
		break;

	case ESTE:
		newy = y + 1;
		break;

	case SUR:
		newx = x + 1;
		break;

	case NORTE:
		newx = x - 1;
		break;

	}


	if ((newx < NUM_COLUMNAS) || (newx > 0) || (newy < NUM_FILAS) || (newy > 0)) {

		switch (juego.tablero[newx][newy].estado) {

		case VACIA:
			juego.tablero[newx][newy].estado = TORTUGA;
			juego.tablero[newx][newy].tortuga = juego.tablero[x][y].tortuga;
			juego.tablero[x][y].estado = VACIA;
			juego.tablero[x][y].tortuga.numero = 0;
			juego.jugadores[juego.turnoActual].posicionActual.x = newx;
			juego.jugadores[juego.turnoActual].posicionActual.y = newy;
			break;

		case CAJA:

			if ((newx + 1 < 8) || (newx - 1 > 0) || (newy + 1 < 8) || (newy - 1 > 0)) {

				switch (juego.jugadores[juego.turnoActual].direccionActual) {

				case OESTE:
					if (juego.tablero[newx][newy - 1].estado == VACIA) {
						juego.tablero[newx][newy - 1].estado = CAJA;
						juego.tablero[newx][newy].estado = TORTUGA;
						juego.tablero[newx][newy].tortuga = juego.tablero[x][y].tortuga;
						juego.tablero[x][y].estado = VACIA;
						juego.tablero[x][y].tortuga.numero = 0;
						juego.jugadores[juego.turnoActual].posicionActual.x = newx;
						juego.jugadores[juego.turnoActual].posicionActual.y = newy;
					}

					break;

				case ESTE:
					if (juego.tablero[newx][newy + 1].estado == VACIA) {
						juego.tablero[newx][newy + 1].estado = CAJA;
						juego.tablero[newx][newy].estado = TORTUGA;
						juego.tablero[newx][newy].tortuga = juego.tablero[x][y].tortuga;
						juego.tablero[x][y].estado = VACIA;
						juego.tablero[x][y].tortuga.numero = 0;
						juego.jugadores[juego.turnoActual].posicionActual.x = newx;
						juego.jugadores[juego.turnoActual].posicionActual.y = newy;
					}

					break;

				case SUR:
					if (juego.tablero[newx + 1][newy].estado == VACIA) {
						juego.tablero[newx + 1][newy].estado = CAJA;
						juego.tablero[newx][newy].estado = TORTUGA;
						juego.tablero[newx][newy].tortuga = juego.tablero[x][y].tortuga;
						juego.tablero[x][y].estado = VACIA;
						juego.tablero[x][y].tortuga.numero = 0;
						juego.jugadores[juego.turnoActual].posicionActual.x = newx;
						juego.jugadores[juego.turnoActual].posicionActual.y = newy;
					}

					break;

				case NORTE:
					if (juego.tablero[newx - 1][newy].estado == VACIA) {
						juego.tablero[newx - 1][newy].estado = CAJA;
						juego.tablero[newx][newy].estado = TORTUGA;
						juego.tablero[newx][newy].tortuga = juego.tablero[x][y].tortuga;
						juego.tablero[x][y].estado = VACIA;
						juego.tablero[x][y].tortuga.numero = 0;
						juego.jugadores[juego.turnoActual].posicionActual.x = newx;
						juego.jugadores[juego.turnoActual].posicionActual.y = newy;
					}

					break;

				}

			}

			break;

		case JOYA:

			juego.tablero[newx][newy].estado = TORTUGA;
			juego.tablero[newx][newy].tortuga = juego.tablero[x][y].tortuga;
			juego.tablero[x][y].estado = VACIA;
			juego.tablero[x][y].tortuga.numero = 0;
			juego.jugadores[juego.turnoActual].posicionActual.x = newx;
			juego.jugadores[juego.turnoActual].posicionActual.y = newy;
			juego.hayGanador = true;
			break;

		default:
			break;

		}

	}

	juego.jugadores[juego.turnoActual].jugada.cartas_avanza--;

}

void girarIzquierda(tJuego &juego) {

	switch (juego.jugadores[juego.turnoActual].direccionActual) {

	case NORTE: juego.jugadores[juego.turnoActual].direccionActual = OESTE;
		juego.tablero[juego.jugadores[juego.turnoActual].posicionActual.x][juego.jugadores[juego.turnoActual].posicionActual.y].tortuga.direccion = OESTE;
		break;
	case SUR: juego.jugadores[juego.turnoActual].direccionActual = ESTE;
		juego.tablero[juego.jugadores[juego.turnoActual].posicionActual.x][juego.jugadores[juego.turnoActual].posicionActual.y].tortuga.direccion = ESTE;
		break;
	case ESTE: juego.jugadores[juego.turnoActual].direccionActual = NORTE;
		juego.tablero[juego.jugadores[juego.turnoActual].posicionActual.x][juego.jugadores[juego.turnoActual].posicionActual.y].tortuga.direccion = NORTE;
		break;
	case OESTE: juego.jugadores[juego.turnoActual].direccionActual = SUR;
		juego.tablero[juego.jugadores[juego.turnoActual].posicionActual.x][juego.jugadores[juego.turnoActual].posicionActual.y].tortuga.direccion = SUR;
		break;
	}

	juego.jugadores[juego.turnoActual].jugada.cartas_giro_izq--;

}

void girarDerecha(tJuego &juego) {

	switch (juego.jugadores[juego.turnoActual].direccionActual) {

	case NORTE: juego.jugadores[juego.turnoActual].direccionActual = ESTE;
		juego.tablero[juego.jugadores[juego.turnoActual].posicionActual.x][juego.jugadores[juego.turnoActual].posicionActual.y].tortuga.direccion = ESTE;
		break;
	case SUR: juego.jugadores[juego.turnoActual].direccionActual = OESTE;

		juego.tablero[juego.jugadores[juego.turnoActual].posicionActual.x][juego.jugadores[juego.turnoActual].posicionActual.y].tortuga.direccion = OESTE;
		break;
	case ESTE: juego.jugadores[juego.turnoActual].direccionActual = SUR;
		juego.tablero[juego.jugadores[juego.turnoActual].posicionActual.x][juego.jugadores[juego.turnoActual].posicionActual.y].tortuga.direccion = SUR;
		break;
	case OESTE: juego.jugadores[juego.turnoActual].direccionActual = NORTE;
		juego.tablero[juego.jugadores[juego.turnoActual].posicionActual.x][juego.jugadores[juego.turnoActual].posicionActual.y].tortuga.direccion = NORTE;
		break;
	}

	juego.jugadores[juego.turnoActual].jugada.cartas_giro_derecha--;

}

void lanzarLaser(tJuego &juego) {

	tDir dir = juego.jugadores[juego.turnoActual].direccionActual;
	int x = juego.jugadores[juego.turnoActual].posicionActual.x;
	int y = juego.jugadores[juego.turnoActual].posicionActual.y;

	int newx = x, newy = y;

	bool buscarObstaculo = true, pararDisparo = false;

	while (buscarObstaculo == true) {

		switch (dir) {

		case NORTE:
			newx = newx - 1;
			break;

		case SUR:
			newx = newx + 1;
			break;

		case ESTE:
			newy = newy + 1;
			break;

		case OESTE:
			newy = newy - 1;
			break;

		}

		if ((newx > 8) || (newx < 0) || (newy > 8) || (newy < 0)) {

			buscarObstaculo = false;

		}

		else if ((juego.tablero[newx][newy].estado == MURO) || (juego.tablero[newx][newy].estado == CAJA)) {

			buscarObstaculo = false;

		}

		else if (juego.tablero[newx][newy].estado == HIELO) {

			juego.tablero[newx][newy].estado = VACIA;
			buscarObstaculo = false;

		}

		else if (juego.tablero[newx][newy].estado == TORTUGA) {

			while (!pararDisparo) {

				switch (dir) {

				case OESTE:
					newy = newy - 1;
					break;

				case ESTE:
					newy = newy + 1;
					break;

				case SUR:
					newx = newx + 1;
					break;

				case NORTE:
					newx = newx - 1;
					break;

				}

				if ((newx > 8) || (newx < 0) || (newy > 8) || (newy < 0) || ((juego.tablero[newx][newy].estado != VACIA) && (juego.tablero[newx][newy].estado != JOYA)))
					pararDisparo = true;

				if (juego.tablero[newx][newy].estado == VACIA) {

					juego.tablero[newx][newy].estado = TORTUGA;
					juego.tablero[newx][newy].tortuga = juego.tablero[x][y].tortuga;
					juego.tablero[x][y].estado = VACIA;
					juego.tablero[x][y].tortuga.numero = 0;
					juego.jugadores[juego.turnoActual].posicionActual.x = newx;
					juego.jugadores[juego.turnoActual].posicionActual.y = newy;

				}
				else if (juego.tablero[newx][newy].estado == JOYA) {

					juego.hayGanador = true;

				}

			}

			buscarObstaculo = false;

		}

		else if (juego.tablero[newx][newy].estado == JOYA) {

			if (juego.tablero[juego.jugadores[juego.turnoActual].posicionInicial.x][juego.jugadores[juego.turnoActual].posicionInicial.y].estado == VACIA) {

				juego.tablero[juego.jugadores[juego.turnoActual].posicionInicial.x][juego.jugadores[juego.turnoActual].posicionInicial.y].estado = TORTUGA;
				juego.tablero[juego.jugadores[juego.turnoActual].posicionInicial.x][juego.jugadores[juego.turnoActual].posicionInicial.y].tortuga.numero = juego.tablero[x][y].tortuga.numero;
				juego.tablero[juego.jugadores[juego.turnoActual].posicionInicial.x][juego.jugadores[juego.turnoActual].posicionInicial.y].tortuga.direccion = juego.jugadores[juego.turnoActual].direccionInicial;
				juego.tablero[x][y].estado = VACIA;
				juego.tablero[x][y].tortuga.numero = 0;
				juego.jugadores[juego.turnoActual].posicionActual.x = juego.jugadores[juego.turnoActual].posicionInicial.x;
				juego.jugadores[juego.turnoActual].posicionActual.y = juego.jugadores[juego.turnoActual].posicionInicial.y;

			}

			buscarObstaculo = false;
		}

	}

	juego.jugadores[juego.turnoActual].jugada.cartas_laser--;

}

bool ejecutarTurno(tJuego &juego) {

	bool jugadaValida = false, haGanado = false, secuenciaValida = true;
	char accion;
	tMazo mazo;
	tCarta carta;
	tTecla tecla;
	size_t i = 0;

	while (!jugadaValida) {

		cout << "Introuzca la jugada a realizar:" << endl;
		cout << "	- [R] = Robar carta" << endl;
		cout << "	- [E] = Ejecutar una secuencia de cartas" << endl;
		cout << "Jugada: ";

		cin >> accion;
		accion = toupper(accion);

		while ((accion != 'R') && (accion != 'E')) {

			cout << "Introduzca una accion valida (R o E): ";
			cin >> accion;
			accion = toupper(accion);

		}

		switch (accion) {

		case 'R':
			jugadaValida = accionRobar(juego);
			break;

		case 'E':

			crearVacia(mazo);

			do {

				tecla = leerTecla();

				if ((tecla != SALIR) && (tecla != NADA)) {

					switch (tecla) {
						// NEW
					case AVANZA:
						carta = AVANZAR;
						insertar(mazo, carta);
						break;

					case DERECHA:
						carta = GIRODERECHA;
						insertar(mazo, carta);
						break;

					case IZQUIERDA:
						carta = GIROIZQUIERDA;
						insertar(mazo, carta);
						break;

					case PLASER:
						carta = LASER;
						insertar(mazo, carta);
						break;

					}

					i++;

				}

			}

			while ((tecla != SALIR) && (tecla != NADA) && (secuenciaValida == true));

			mazo.num_cartas_mazo = i;

			if ((tecla == NADA) || (!secuenciaValida)) {

				jugadaValida = false;

			}

			else {

				jugadaValida = true;
				haGanado = accionSecuencia(juego, mazo);

			}

			break;

		}

	}

	return haGanado;

}

tTecla leerTecla() {

	int dir;
	tTecla tecla;

	cin.sync();

	dir = _getch();

	if (dir == 0xe0) {

		dir = _getch();

		if (dir == 72) { tecla = AVANZA; cout << "	^" << endl; }

		else if (dir == 77) { tecla = DERECHA;  cout << "	>" << endl; }

		else if (dir == 75) { tecla = IZQUIERDA;  cout << "	<" << endl; }

		else tecla = NADA;

	}

	else if (dir == 32) {
		tecla = PLASER;
		cout << "	~" << endl;
	}

	else if (dir == 13)
		tecla = SALIR;

	else
		tecla = NADA;

	return tecla;

}

void cambiarTurno(tJuego &juego) {

	juego.turnoActual++;
	juego.turnoActual = juego.turnoActual % juego.num_jugadores;

}
/*
bool esFinDePartida(tJuego &juego) {

	bool finPartida = false;

	if (juego.hayGanador == true)
		finPartida = true;

	return finPartida;

}
*/
void incluirCarta(tMano &mano, tCarta carta) {

	switch (carta) {
		case AVANZAR: mano.cartas_avanza++; break;
		case GIRODERECHA: mano.cartas_giro_derecha++; break;
		case GIROIZQUIERDA: mano.cartas_giro_izq++; break;
		case LASER: mano.cartas_laser++; break;
		}

}