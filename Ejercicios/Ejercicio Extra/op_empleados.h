#ifndef op_empleados_h
#define op_empleados_h

#include <string>
#include <iostream>

#include "op_est_cont.h"

typedef struct {
	std::string nombre;
	int edad;
	tEstudios estudios;
	tTipoContrato contrato;
} tEmpleado;

// prototipos de operaciones para empleados

//Muestra la información de los empleados individualmente
void mostrar(tEmpleado empleado);
//Asigna los valores a el estructurado empleado para trabajar con él
void construir(std::string nombre, int edad, tEstudios est, tTipoContrato cont, tEmpleado &empleado);
//Pide los datos de un mepleado para poder construirlo
void generarEmpleado(std::string &nombre, int &edad, tEstudios &est, tTipoContrato &cont);

#endif