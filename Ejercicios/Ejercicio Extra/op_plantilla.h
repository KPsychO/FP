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

//Iniciaiza la plantilla a 0 empleados
void inicializa(tPlantilla &plantilla);
//Carga una plantilla de un fichero y los añade a la lista, aumentando el contador
bool cargarEmpleadosFichero(tPlantilla &plantilla);
//Inserta un empleado en la ultima posicion dela lista (si se puede)
bool insertarUltimo(tPlantilla &plantilla, tEmpleado empleado);
//Inserta un empleado en la primera posicion dela lista (si se puede)
bool insertarPrimero(tPlantilla &plantilla, tEmpleado empleado);
//Inserta un empleado en la posicion x de la lista(si se puede)
bool insertarEni(tPlantilla &plantilla, tEmpleado empleado, int x);
//Muestra el contenido de la lista
void mostrar(const tPlantilla &plantilla);
//Destruye todos los punteros y pone el numero de empleados a 0
void eliminarTodos(tPlantilla &plantilla);
//Destruye todos los empleados de la lista
void destruir(tPlantilla &plantilla);
//Elimina el ultimo empleado de la lista
void eliminarUltimo(tPlantilla &plantilla);
//Elimina el primer empleado de a lista
void eliminarPrimero(tPlantilla &plantilla);
//Elimina el empleado de la posicion x de la lista
void eliminarDei(tPlantilla &plantilla, int x);
//Guarda el contenido de la plantilla en un archivo de texto
void guardar(tPlantilla &plantilla);

#endif