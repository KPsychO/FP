#include <iostream>

using namespace std;

int main() 
{	//definimos las variables
	double radioBase = 14.5;
	double altura = 26.79;
	double pi = 3.14159265359;
	double volumen;

	//realizamos el cáculo y asignamos a volumen el resultado
	volumen = ((pi * (radioBase*radioBase) * altura) / 3);
	cout << "El volumen de un cono con el radio de la base de 14,5u y una altura de 26.79u, es : " << volumen <<endl;
	return 0;
}
