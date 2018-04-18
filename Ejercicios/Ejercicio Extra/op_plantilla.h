#ifndef op_plantilla_h
#define op_plantilla_h

#include <fstream>

#include "op_empleados.h";

const int MAX_EMPLEADOS = 10;

typedef tEmpleado *tPtrEmp;

typedef struct {
	int numEmpleados;
	tPtrEmp empleados[MAX_EMPLEADOS];
} tPlantilla;

// prototipos de operaciones para plantilla
void inicializa(tPlantilla &plantilla);
bool cargarEmpleadosFichero(tPlantilla &plantilla);
bool insertarUltimo(tPlantilla &plantilla, tEmpleado empleado);
bool insertarPrimero(tPlantilla &plantilla, tEmpleado empleado);
bool insertarEni(tPlantilla &plantilla, tEmpleado empleado, int x);
void mostrar(const tPlantilla &plantilla);
void eliminarTodos(tPlantilla &plantilla);
void destruir(tPlantilla &plantilla);
void eliminarUltimo(tPlantilla &plantilla);
void eliminarPrimero(tPlantilla &plantilla);
void eliminarDei(tPlantilla &plantilla, int x);
void guardar(tPlantilla &plantilla);

#endif