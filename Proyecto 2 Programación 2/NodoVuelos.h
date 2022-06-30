#pragma once
#include <iostream>
#include "Vuelos.h"

using namespace std;

class NodoVuelos {

private:
	Vuelos vue;
	NodoVuelos* siguiente;

public:
	NodoVuelos(Vuelos v) {
		vue.setLugarOrigen(v.getLugarOrigen());
		vue.setLugarDestino(v.getLugarDestino());
		vue.setTiempoTrayectoria(v.getTiempoTrayectoria());
		vue.setCostoVuelos(v.getCostoVuelos());
		vue.setIdVuelos(v.getIdVuelos());

		siguiente = NULL;
	}

	void setVuelos(Vuelos v) {
		this->vue = v;
	}

	void setSiguiente(NodoVuelos* s) {
		this->siguiente = s;
	}

	Vuelos getVuelos() {
		return this->vue;
	}

	NodoVuelos* getSiguiente() {
		return this->siguiente;
	}

};