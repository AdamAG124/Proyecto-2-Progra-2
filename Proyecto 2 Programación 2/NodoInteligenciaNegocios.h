#pragma once
#include <iostream>
#include "InteligenciaNegocios.h"

using namespace std;

class NodoInteligenciaNegocios {

private:
	InteligenciaNegocios in;
	NodoInteligenciaNegocios* siguiente;

public:
	NodoInteligenciaNegocios(InteligenciaNegocios i) {
		in.setInformacion(i.getInformacion());
		siguiente = NULL;
	}

	void setInteligenciaNegocios(InteligenciaNegocios a) {
		this->in = a;
	}

	void setSiguiente(NodoInteligenciaNegocios* s) {
		this->siguiente = s;
	}

	InteligenciaNegocios getInteligenciaNegocios() {
		return this->in;
	}

	NodoInteligenciaNegocios* getSiguiente() {
		return this->siguiente;
	}

};