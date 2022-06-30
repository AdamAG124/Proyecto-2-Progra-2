#pragma once
#include <iostream>
#include "Pilotos.h"

using namespace std;

class NodoPilotos {

private:
	Pilotos pil;
	NodoPilotos* siguiente;

public:
	NodoPilotos(Pilotos p) {
		pil.setNombre(p.getNombre());
		siguiente = NULL;
	}

	void setPiltos(Pilotos p) {     // Este Metodo se encarga de crea un set de piltos.
		this->pil = p;
	}

	void setSiguiente(NodoPilotos* s) {   // Este Metodo se encarga de crea un set de siguiente.
		this->siguiente = s;
	}

	Pilotos getPiltos() {     // Este Metodo se encarga de crear el get de piltos
		return this->pil;
	}

	NodoPilotos* getSiguiente() {    // Este Metodo se encarga de crear el get de siguiente
		return this->siguiente;
	}

};
