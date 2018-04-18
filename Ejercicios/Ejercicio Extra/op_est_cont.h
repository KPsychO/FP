#ifndef op_est_cont_h
#define op_est_cont_h
#include <string>

typedef enum {
	ESO, Bachillerato, FP_Medio, FP_Superior, Grado, Master, Doctor
} tEstudios;

typedef enum {
	Fijo, Practicas, Eventual, Becario
} tTipoContrato;

// prototipos de operaciones para estudios y contratos

//Trasforma valores de tipo tEstudios en strings para poder imprimirlas
std::string cad_estudios(tEstudios est);
//Trasforma valores de tipo tContrato en strings para poder imprimirlas
std::string cad_contrato(tTipoContrato cont);

#endif