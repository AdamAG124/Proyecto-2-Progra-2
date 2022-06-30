#pragma once
#include <iostream>
#include "Aviones.h"

using namespace std;

class NodoAviones {

private:
	Aviones avi;
	NodoAviones* siguiente;

public:
	NodoAviones(Aviones a) {
		avi.setNombreAerolinea(a.getNombreAerolinea());
		avi.setNumeroAsientos(a.getNumeroAsientos());
		siguiente = NULL;
	}

	void setAvines(Aviones a) {   // Este Metodo se encarga de crea un set de avines.
		this->avi = a;
	}

	void setSiguiente(NodoAviones* s) {   // Este Metodo se encarga de crea un set de siguiente.
		this->siguiente = s;
	}

	Aviones getAvines() {    // Este Metodo se encarga de crear el get de avines
		return this->avi;
	}

	NodoAviones* getSiguiente() {     // Este Metodo se encarga de crear el get de siguiente
		return this->siguiente;
	}

};
