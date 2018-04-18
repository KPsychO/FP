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
void mostrar(tEmpleado empleado);
void construir(std::string nombre, int edad, tEstudios est, tTipoContrato cont, tEmpleado &empleado);

#endif