#include <iostream>

using namespace std;

int main()
{
	int secs1;	
	double secs; //definimos las variables
	double mins;
	double horas;
	double n;

	cout << "Introduzca un tiempo en segundos ";	//solicitamos el tiempo en segundos
	cin >> secs1;	

	horas = (secs1 / 3600.00);	//calculamos el valor decimal de las horas
	n = horas;
	horas = 0;
	while (n > 1) { //obtenemos el valor entero de las horas en la variable horas y el decimal en n
		--n;
		horas++;
	}
	
	mins = (n * 60.00);
	n = mins;
	mins = 0;
	while (n > 1) {
		--n;
		mins++;
	}
	
	secs = (n * 60.00);
	
	cout << secs1 << " segundos expresado en H:M:S, es: " << horas << " horas " << mins << " minutos " << secs << " segundos." << endl;	//sacmos la respuesta en pantalla

	return 0;
}
