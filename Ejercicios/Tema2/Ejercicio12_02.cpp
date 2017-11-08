#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double capital;
	double interesAnual;
	double anosDuracion;
	double cuota;
	double ratio;
	double plazo;

	cout << "Introduzca el capital prestado." << endl;
	cin >> capital;

	cout << "Introduzca el interes anual." << endl;
	cin >> interesAnual;

	cout << "Introduzca la duración del préstamo." << endl;
	cin >> anosDuracion;

	ratio = ( interesAnual / 12 );
	plazo = ( anosDuracion * 12);

	cuota =  ( ( capital * ratio ) / ( 100 * ( 1- ( pow ( ( 1 +  ( ratio / 100 ) ) , ( - plazo) ) ) ) ) );

	cout << "La cuota mensual a pagar es de: " << cuota << " €" << endl;
	cout << "La cantidad de amortización de de: " << capital << " €" << endl;
	cout << "Debe pagar usted " << ( cuota * plazo - capital ) << " € de intereses." << endl;

	return 0;
}