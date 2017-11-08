#include <iostream>

using namespace std;

int main() 
{
	int far;	//definimos variables
	double cel;
	//pedimos al usuario que introduzca la temp. en farenheit
	cout << "Introduzca una temperatura en grados Fahrenheit.";
	cin >> far;
	//devolvemos al usuario la temp. en calsius
	cout << far << " grados Farenheit, equivale a " << (5 / 9 * (far - 32)) << " grados celsius";
	return 0;
}
	
