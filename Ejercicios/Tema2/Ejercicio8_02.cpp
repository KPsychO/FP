#include <iostream>

using namespace std;

int main() 
{	
	double sueldoBase;
	double complementoDestino;
	double cargoAcademico;
	int horasExtras;
	int hijos;
	int mayores;
	double sueldoBruto;
	double porcentajeIRPF = 24;
	double retencionIRPF;
	double sueldoNeto;
	double precioHorasExtra = 23;
	
	cout << "Sueldo base: ";												//El usuario introduce los daatos en cada una de las variables
	cin >> sueldoBase;
	
	cout << "Complemento de destino: ";
	cin >> complementoDestino;
	
	cout << "Complemento de cargo académico: ";
	cin >> cargoAcademico;
	
	cout << "Horas extras realizadas: ";
	cin >> horasExtras;
	
	cout << "Hijos a su cargo: ";
	cin >> hijos;
	
	cout << "Mayores a su cargo: ";
	cin >> mayores;
	
	sueldoBruto = sueldoBase + complementoDestino + cargoAcademico + (horasExtras * precioHorasExtra);		//calculamos el sueldo bruto
	cout << "Sueldo bruto: " << sueldoBruto << " €" << endl;
	
	porcentajeIRPF = 24 - ((2 * hijos) + (1 * mayores));									//calculamos el porcentajeIRPF y lo mostramos en pantalla
	cout << "Porcentaje IRPF: " << porcentajeIRPF << " %" << endl;
	
	retencionIRPF = sueldoBruto * (porcentajeIRPF / 100);										//calculamos la retenciónIRPF y lo mostramos en pantalla
	cout << "Retención IRPF: " << retencionIRPF << " €" << endl;
	
	sueldoNeto = sueldoBruto - retencionIRPF;												//calculamos el sueldoNeto y lo mostramos en pantalla
	cout << "Sueldo neto: " << sueldoNeto << " €" << endl;
	
	return 0;
}
