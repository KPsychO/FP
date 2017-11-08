#include <iostream>

using namespace std;

int main() 
{
	double practicas;
	double exam1;
	double exam2;
	double examFinal;
	double actividad;
	double notaFinal;
	
	cout << "Introduzca su nota de practicas. ";
	cin >> practicas;
	while (practicas < 0) {
		cout << "Introduzca su nota de practicas. ";
		cin >> practicas;
	}
	
	cout << "Introduzca su nota del primer parcial. ";
	cin >> exam1;
	while (exam1 < 0) {
		cout << "Introduzca su nota del primer parcial. ";
		cin >> exam1;
	}
	
	cout << "Introduzca su nota del segundo parcial. ";
	cin >> exam2;
	while (exam2 < 0) {
		cout << "Introduzca su nota del segundo parcial. ";
		cin >> exam2;
	}
	
	cout << "Introduzca su nota del examen final. ";
	cin >> examFinal;
	while (examFinal < 0) {
		cout << "Introduzca su nota del examen final. ";
		cin >> examFinal;
	}
	cout << "Introduzca su nota de la actividad adicional. ";
	cin >> actividad;
	while (actividad < 0) {
		cout << "Introduzca su nota de la actividad adicional. ";
		cin >> actividad;
	}
	
	notaFinal = ((0.2 * practicas) + (0.05 * exam1) + (0.1 * exam2) + (0.5 * examFinal) + (0.15 * actividad));
	cout << "Su nota final es: " << notaFinal << endl;
	
	return 0;
}
