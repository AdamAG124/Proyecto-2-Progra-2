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

	void setVuelos(Vuelos v) {   // Este Metodo se encarga de crear el set de vueos
		this->vue = v;
	}

	void setSiguiente(NodoVuelos* s) {    // Este Metodo se encarga de crear el set de siguiente 
		this->siguiente = s;
	}

	Vuelos getVuelos() {    // Este Metodo se encarga de crear el get de vueos
		return this->vue;
	}

	NodoVuelos* getSiguiente() {     // Este Metodo se encarga de crear el get de siguiente
		return this->siguiente;
	}

};
