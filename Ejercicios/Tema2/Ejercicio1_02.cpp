#include <iostream>

using namespace std;

int main()
{	//definimos la variable volumen, que almacenará el resultado
	double volumen;

	//realizamos el cáculo y asignamos a volumen el resultado
	volumen = ((3.14159265359 * (14.5*14.5) * 26.79) / 3);
	cout << "El volumen de un cono con el radio de la base de 14,5u y una altura de 26.79u, es : " << volumen <<endl;
	return 0;
}
