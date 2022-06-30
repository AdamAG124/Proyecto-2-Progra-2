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

	void setPiltos(Pilotos p) {
		this->pil = p;
	}

	void setSiguiente(NodoPilotos* s) {
		this->siguiente = s;
	}

	Pilotos getPiltos() {
		return this->pil;
	}

	NodoPilotos* getSiguiente() {
		return this->siguiente;
	}

};