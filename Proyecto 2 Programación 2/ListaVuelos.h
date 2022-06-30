#pragma once
#include "NodoVuelos.h"

using namespace std;

class ListaVuelos {

private:
	NodoVuelos* primero;
	NodoVuelos* actual;

public:

	ListaVuelos() {
		primero = actual = NULL;
	}

	void insertarVuelos(Vuelos v) {    // Este metodo lo que hace es que se guarda la informacion para la lista
		actual = primero;
		if (primero == NULL) {
			primero = new NodoVuelos(v);
		}
		else {
			primero = new NodoVuelos(v);
			primero->setSiguiente(actual);
		}
	}

	void imprimeListaVuelos() {    // Este metodo se encarga de imprimir los datos actuales que tiene.
		actual = primero;
		cout << "Lista de vuelos disponibles: " << endl;
		while (actual != NULL) {
			actual->getVuelos().mostrarDatosVuelos();
			actual = actual->getSiguiente();
		}
		cout << endl;
	}

	Vuelos valorActual() {
		return actual->getVuelos();
	}

	/*void buscarElementoListaVuelos(string lugarOrigen) {
		//actual = new Nodo(numero);
		actual = primero;
		bool band = false;

		while ((actual != NULL) && (actual->getVuelos().getLugarOrigen() <= lugarOrigen)) {
			if (actual->getVuelos().getLugarOrigen() == lugarOrigen) {
				band = true;
			}
			actual = actual->getSiguiente();
		}

		if (band == true) {
			cout << "El lugar Origen " << lugarOrigen << " si se encuentra en la lista." << endl;
		}
		else {
			cout << "El Lugar Origen " << lugarOrigen << " no se encuentra en la lista." << endl;
		}
	}*/

	~ListaVuelos() {   //Destructor de la listaVuelos
		actual = primero;
		while (primero != NULL) {
			actual = primero;
			primero = primero->getSiguiente();
			delete actual;
		}
		actual = NULL;
		primero = NULL;
	}

};
