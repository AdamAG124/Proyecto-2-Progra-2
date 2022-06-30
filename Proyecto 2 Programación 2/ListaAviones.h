#pragma once
#include "NodoAviones.h"
#include <iostream>

using namespace std;

class ListaAviones {

private:
	NodoAviones* primero;
	NodoAviones* actual;

public:

	ListaAviones() {
		primero = actual = NULL;
	}

	void insertarAviones(Aviones a) {  // Este metodo lo que hace es que se guarda la informacion para la lista
		actual = primero;
		if (primero == NULL) {
			primero = new NodoAviones(a);
		}
		else {
			primero = new NodoAviones(a);
			primero->setSiguiente(actual);
		}
	}

	void imprimeListaAviones() {   // Este metodo se encarga de imprimir los datos actuales que tiene.
		actual = primero;
		cout << "Lista de aviones: " << endl << endl;
		while (actual != NULL) {
			actual->getAvines().mostrarDatosAviones();
			actual = actual->getSiguiente();
		}
		cout << endl;
	}


	/*/void buscarElementoListaAviones(string nombreAerolinea) {
		//actual = new Nodo(numero);
		actual = primero;
		bool band = false;

		while ((actual != NULL) && (actual->getAvines().getNombreAerolinea() != nombreAerolinea)) {
			if (actual->getAvines().getNombreAerolinea() == nombreAerolinea) {
				band = true;
			}
			actual = actual->getSiguiente();
		}

		if (band == true) {
			cout << "El nombre de la Aerolinea " << nombreAerolinea << " si se encuentra en la lista." << endl;
		}
		else {
			cout << "El nombre de la Aerolinea " << nombreAerolinea << " no se encuentra en la lista." << endl;
		}
	}*/

	~ListaAviones() {   //Destructor de la listaAviones
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
