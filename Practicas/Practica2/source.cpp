
// Diego Atance Sanz && Yao  - 1º C Ing. Informática - FP - Pablo Gervás

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const int TAM_CODIGO = 4, LONG_COLOR = 6, NUM_INTENTOS = 15;

typedef enum {Rojo, Azul, Verde, Amarillo, Marron, Blanco} tColor;
typedef tColor tCodigo[TAM_CODIGO];

char color2char(tColor color);
tColor char2color(char let);
void codigoAleatorio(tCodigo codigo, bool admiteRepetidos);
void compararCodigos(const tCodigo codigo, const tCodigo hipotesis, int& colocados, int& descolocados);

int main() {

	tCodigo codigo, hipotesis;
	bool admiteRepetidos, error;
	string hip;
	char let, color;
	tColor col;
	int menu = 1, colocados, descolocados, intentos, x;

	cout << "MASTERMIND" << endl;
	cout << "==========" << endl << endl;
	cout << "Descubre el codigo secreto! En cada partida, pensare un codigo de colores que tendras que adivinar. En cada intento que hagas te dare pistas, diciendote cuantos colores de los que has dicho estan bien colocados, y cuantos no." << endl << endl;
	cout << "Averigua el codigo secreto en el menor numero posible de intentos!" << endl << endl;
	
	while (menu != 0) {

		cout << "   " << "1. Jugar con un codigo sin colores repetidos" << endl;
		cout << "   " << "2. Jugar con un codigo con colores repetidos" << endl << endl;
		cout << "   " << "0. Salir" << endl << endl;
		cout << "      " << "Elige una opcion: ";

		cin >> menu;

		while ((menu < 0) || (menu > 2)) {
			cout << "      " << "Opcion incorrecta. Prueba otra vez: ";
			cin >> menu;
		}

		cout << endl;

		intentos = 0;
		colocados = 0;
		descolocados = 0;

		switch (menu){
		case 1: {

			admiteRepetidos = false; 
			codigoAleatorio(codigo, admiteRepetidos);

			while ((intentos < NUM_INTENTOS) && colocados < TAM_CODIGO) {

				cout << "Introduce el codigo (palabra de 4 letras con alguna de R, Z, V, A, M o B): ";
				cin >> hip;

				error = true;
				while (error) {

					error = false;

					if ((hip.size()) != TAM_CODIGO) {

						cout << "ERROR DE TAMANO" << endl;
						cout << "Introduce el codigo (palabra de 4 letras con alguna de R, Z, V, A, M o B): ";
						cin >> hip;
						error = true;
					}

					if (!error) {

						x = 0;

						while (x < TAM_CODIGO && !error) {

							let = toupper(hip[x]);

							if ((let != 'R') && (let != 'Z') && (let != 'V') && (let != 'A') && (let != 'M') && (let != 'B')) {

								cout << "ERROR DE CARACTER" << endl;
								cout << "Introduce el codigo (palabra de 4 letras con alguna de R, Z, V, A, M o B): ";
								cin >> hip;
								x = 0;
								error = true;
							}

							else {
								x++;
							}
						}
					}
				}

				for (int i = 0; i < TAM_CODIGO; i++) {

					let = toupper(hip[i]);
					col = char2color(let);
					hipotesis[i] = col;

				}

				compararCodigos(codigo, hipotesis, colocados, descolocados);

				intentos++;

			}

			if (intentos < NUM_INTENTOS) {

				cout << "Enhorabuena, te ha costado: " << intentos << " intento(s)." << endl << endl;

			}

			else {

				cout << "No encontraste el codigo en " << NUM_INTENTOS << " intentos..." << endl << "El codigo era: ";

				for (int j = 0; j < TAM_CODIGO; j++) {

					color = color2char(tColor(codigo[j]));
					cout << color << " ";

				}

				cout << endl << endl;
			}

			break;
		}
			
		case 2: {
			admiteRepetidos = true;
			codigoAleatorio(codigo, admiteRepetidos);

			while ((intentos < NUM_INTENTOS) && colocados < TAM_CODIGO) {

				cout << "Introduce el codigo (palabra de 4 letras con alguna de R, Z, V, A, M o B): ";
				cin >> hip;

				error = true;
				while (error) {

					error = false;

					if ((hip.size()) != TAM_CODIGO) {

						cout << "ERROR DE TAMANO" << endl;
						cout << "Introduce el codigo (palabra de 4 letras con alguna de R, Z, V, A, M o B): ";
						cin >> hip;
						error = true;
					}

					if (!error) {

						x = 0;

						while (x < TAM_CODIGO && !error) {

							let = toupper(hip[x]);

							if ((let != 'R') && (let != 'Z') && (let != 'V') && (let != 'A') && (let != 'M') && (let != 'B')) {

								cout << "ERROR DE CARACTER" << endl;
								cout << "Introduce el codigo (palabra de 4 letras con alguna de R, Z, V, A, M o B): ";
								cin >> hip;
								x = 0;
								error = true;
							}

							else {
								x++;
							}
						}
					}
				}

				for (int i = 0; i < TAM_CODIGO; i++) {

					let = toupper(hip[i]);
					col = char2color(let);
					hipotesis[i] = col;

				}

				compararCodigos(codigo, hipotesis, colocados, descolocados);

				intentos++;

			}

			if (intentos < NUM_INTENTOS) {

				cout << "Enhorabuena, te ha costado: " << intentos << " intento(s)." << endl << endl;

			}

			else {

				cout << "No encontraste el codigo en " << NUM_INTENTOS << " intentos..." << endl << "El codigo era: ";

				for (int j = 0; j < TAM_CODIGO; j++) {

					color = color2char(tColor(codigo[j]));
					cout << color << " ";

				}

				cout << endl << endl;
			}

			break;
		}

		case 0:
			break;
		}
	}

	return 0;
}

void codigoAleatorio(tCodigo codigo, bool admiteRepetidos) {

	int aux, cont = 0, x;
	char color;
	bool igual = false;
	srand(time(NULL));

	if (admiteRepetidos) {

		cout << "[INFO DEPURACION] Codigo secreto: ";

		for (int i = 0; i < TAM_CODIGO; i++) {

			aux = rand() % LONG_COLOR;
			codigo[i] = tColor(aux);
			color = color2char(tColor(aux));
			cout << color << " ";
		}

		cout << endl;

	}

	else {

		cout << "[INFO DEPURACION] Codigo secreto: ";

		for (int cont = 0; cont < TAM_CODIGO; cont++) {

			aux = rand() % LONG_COLOR;

			x = 0;
			while (x < cont) {

				if (codigo[x] == aux) {

					aux = rand() % LONG_COLOR;
					x = 0;

				}

				else
					x++;

			}

			codigo[cont] = tColor(aux);
			color = color2char(tColor(aux));
			cout << color << " ";
		}

		cout << endl;
	}
}

void compararCodigos(const tCodigo codigo, const tCodigo hipotesis, int& colocados, int& descolocados) {

	colocados = 0;
	descolocados = 0;

	int i, j;
	bool found, desc;

	j = 0;
	while ((j < TAM_CODIGO)) {

		found = false;
		desc = false;
		i = 0;

		while ((!found) && (i < TAM_CODIGO)) {

			if (codigo[j] == hipotesis[i]) {

				if (i == j) {
					colocados++;
					if (desc)
						descolocados--;
					found = true;
				}

				else if (!desc) {
					descolocados++;
					desc = true;
				}
			}
			i++;
		}
		j++;
	}

	cout << "COLOCADOS: " << colocados << "; MAL COLOCADOS: " << descolocados << endl << endl;
}

char color2char(tColor color) {

	char aux;

	switch (color){
	case Rojo:
		aux = 'R'; break;
	case Azul:
		aux = 'Z'; break;
	case Verde:
		aux = 'V'; break;
	case Amarillo:
		aux = 'A'; break;
	case Marron:
		aux = 'M'; break;
	case Blanco:
		aux = 'B'; break;
	}

	return aux;

}

tColor char2color(char let) {

	tColor aux;

	switch (let){
	case 'R':
		aux = Rojo; break;
	case 'Z':
		aux = Azul; break;
	case 'V':
		aux = Verde; break;
	case 'A':
		aux = Amarillo; break;
	case 'M':
		aux = Marron; break;
	case 'B':
		aux = Blanco; break;
	}

	return aux;
}
