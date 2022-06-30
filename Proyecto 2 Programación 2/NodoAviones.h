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

	void setAvines(Aviones a) {
		this->avi = a;
	}

	void setSiguiente(NodoAviones* s) {
		this->siguiente = s;
	}

	Aviones getAvines() {
		return this->avi;
	}

	NodoAviones* getSiguiente() {
		return this->siguiente;
	}

};