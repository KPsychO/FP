
/* 	 --------------------------------------------
	| Piedra - Papel - Tijeras - Lagarto - Spock |
	 --------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

const int ELEMENTN = 5;
typedef enum { Piedra, Papel, Tijeras, Lagarto, Spock } tElemento;
typedef enum { empate, ganaHumano, ganaMaquina } tResultado;

bool localizacionJugador(string apodo, string contra);

int menu();

bool mostrarReglas();

tElemento eleccionHumano();

string elementoAstring(tElemento elemento);

tResultado quienGana(tElemento maquina, tElemento humano);

int main() {
	int var_menu = 1, aux, cont_partidas = 0, cont_empates = 0, cont_ganadas = 0, cont_perdidas = 0;
	string apodo, maq, usuario, contra;
	bool reg, reglas;
	tElemento opc_usuario, opc_maquina;
	tResultado res;
	
	cout << "Introduce tu apodo: ";
	cin >> apodo;
	
	while (apodo == "XXX"){
		
		cout << "Apodo no disponible." << endl << "Introduce tu apodo: ";
		cin >> apodo;
	}
	
	cout << "Introduce tu contraseña: ";
	cin >> contra;
	
	while (contra == "XXX"){
		
	cout << "Contraseña no valida" << endl << "Introduce tu contraseña: ";
	cin >> contra;
		
	}

	reg = localizacionJugador(apodo, contra);

	if (reg) {

		while (var_menu != 0) {

			var_menu = menu();
			
			switch (var_menu) {

			case 0: break;
			case 1:
				cont_partidas++;
				opc_usuario = eleccionHumano();

				srand(time(NULL));
				aux = rand() % ELEMENTN;

				opc_maquina = tElemento(aux);
				maq = elementoAstring(opc_maquina);

				cout << "Eleccion computadora: " << maq << endl;

				usuario = elementoAstring(opc_usuario);
				cout << "Tu eleccion: " << usuario << endl;
				cout << "........." << endl;

				res = quienGana(opc_maquina, opc_usuario);

				switch (res) {

				case empate:
					cout << "Se ha producido un empate" << endl << endl;
					cont_empates++;
					break;
				case ganaHumano:
					cout << "Has ganado" << endl << endl;
					cont_ganadas++;
					break;
				case ganaMaquina:
					cout << "Has perdido" << endl << endl;
					cont_perdidas++;
					break;
				}
				break;

			case 2:
				reglas = mostrarReglas();
				if (!reglas)
					cout << "No se han podido mostrar las reglas, archivo no encontrado." << endl;
				break;
			}
		}
		cout << "Ronda de " << cont_partidas << " partida(s)" << endl;
		cout << "Partidas ganadas: " << cont_ganadas << endl;
		cout << "Partidas empatadas: " << cont_empates << endl;
		cout << "Partidas perdidas: " << cont_perdidas << endl;
	}

	else
		cout << "Jugador no registrado o archivo registro inexsistente. Imposible jugar";

	system("PAUSE");

	return 0;
}

bool localizacionJugador(string apodo, string contra) {	//	Comprobamos que el apodo proporcionado se encuentre en el archivo de registro y devolvemos un valor bool en cada uno de los casos

	ifstream inputFile;
	string registro, contras;
	bool aut = false;

	inputFile.open("Registro.txt");			//	Abrimos el archivo registro.txt

	if (inputFile.is_open()) {
		
		getline(inputFile, registro);		//	Leemos cada una de las lineas del archivo y lo guardamos en la variabel registro para despues imprimirlo
		getline(inputFile, contras);
		
		while ((registro != "XXX") && (aut == false)){
			
			if ((apodo == registro) && (contra == contras))
				aut = true;
			
			getline(inputFile, registro);
			getline(inputFile, contras);
		}

		inputFile.close();
	}
	return aut;
}

int menu() {								//	

	int opc = 5;

	while ((opc < 0) || (opc > 2)) {

		cout << "1 = Jugar una partida" << endl;
		cout << "2 = Ver instrucciones" << endl;
		cout << "0 = Salir" << endl;
		cout << "Opcion: " << endl;

		cin >> opc;
		cout << endl << endl;
	}

	return opc;

}

bool mostrarReglas() {

	ifstream inputFile;
	string rules;
	bool comp;

	inputFile.open("Reglas.txt");

	if (inputFile.is_open()) {

		getline(inputFile, rules);

		while (rules != "XXX")
		{
			cout << rules << endl;
			getline(inputFile, rules);
		}
		inputFile.close();
		cout << endl;
		comp = true;
	}
	else
		comp = false;

	return comp;

}

tElemento eleccionHumano() {

	tElemento jug;
	int opc = 0;

	while ((opc < 1) || (opc > 5)) {

		cout << "Elige elemento (1-Piedra, 2-Papel, 3-Tijeras, 4-Lagarto, 5-Spock): ";
		cin >> opc;
		cout << endl;
	}

	opc = opc - 1;

	jug = tElemento(opc);

	return jug;
}

string elementoAstring(tElemento elemento) {

	string aux;

	switch (elemento) {

	case Piedra:	aux = "Piedra"; break;
	case Papel:		aux = "Papel"; break;
	case Tijeras: 	aux = "Tijeras"; break;
	case Lagarto: 	aux = "Lagarto"; break;
	case Spock: 	aux = "Spock"; break;

	}

	return aux;
}

tResultado quienGana(tElemento maquina, tElemento humano) {

	tResultado res;

	if ((maquina == humano)){
		res = empate;
		cout << endl;
	}
	else if (((maquina == Piedra) && (humano == Tijeras)) || ((maquina == Piedra) && (humano == Lagarto)) || ((maquina == Papel) && (humano == Lagarto)) || ((maquina == Papel) && (humano == Spock)) || ((maquina == Tijeras) && (humano == Lagarto)) || ((maquina == Tijeras) && (humano == Papel)) || ((maquina == Lagarto) && (humano == Spock)) || ((maquina == Lagarto) && (humano == Papel)) || ((maquina == Spock) && (humano == Piedra)) || ((maquina == Spock) && (humano == Tijeras))){
		res = ganaMaquina;
		cout << endl;
	}
	else{
		res = ganaHumano;
		cout << endl;
	}
	return res;
}


