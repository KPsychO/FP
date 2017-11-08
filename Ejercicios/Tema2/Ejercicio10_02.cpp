#include <iostream>
#include <cmath>

using namespace std;

int main()
{	

	double lado1;
	double lado2;
	double angulo;
	double area;
	
	cout << "Introduzca el primer lado del triángulo." << endl;
	cin >> lado1;
	
	cout << "Introduzca el segundo lado del triángulo." << endl;
	cin >> lado2;
	
	cout << "Introduzca el angulo en grados." << endl;
	cin >> angulo;
	
	angulo = angulo * ( 3.14159265359 / 180);
	
	area = 0.5 * lado1 * lado2 * sin(angulo);
	cout << "El área del triángulo introducido es: " << area << " u." << endl;
	
	
	return 0;
}
