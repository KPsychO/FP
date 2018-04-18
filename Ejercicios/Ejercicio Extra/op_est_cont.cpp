#include "op_est_cont.h"

using namespace std;

string cad_estudios(tEstudios est) {
	string cad;
	switch (est) {
	case (ESO): cad = "ESO"; break;
	case (Bachillerato): cad = "Bachillerato"; break;
	case (FP_Medio): cad = "F.P. de grado medio"; break;
	case (FP_Superior): cad = "F.P. de grado superior"; break;
	case (Grado): cad = "Grado"; break;
	case (Master): cad = "Master"; break;
	case (Doctor): cad = "Doctorado"; break;
	}
	return cad;
}

string cad_contrato(tTipoContrato cont) {
	string cad;
	switch (cont) {
	case (Fijo): cad = "Contrato fijo"; break;
	case (Practicas): cad = "Contrato en practicas"; break;
	case (Eventual): cad = "Contrato eventual"; break;
	case (Becario): cad = "Becario"; break;
	}
	return cad;
}