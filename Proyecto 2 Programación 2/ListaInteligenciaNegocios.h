#pragma once
#include "NodoInteligenciaNegocios.h"
#include <iostream>

using namespace std;

class ListaInteligenciaNegocios {

private:
	NodoInteligenciaNegocios* primero;
	NodoInteligenciaNegocios* actual;

public:

	ListaInteligenciaNegocios() {
		primero = actual = NULL;
	}

	void insertar(InteligenciaNegocios l) {
		actual = primero;
		if (primero == NULL) {
			primero = new NodoInteligenciaNegocios(l);
		}
		else {
			primero = new NodoInteligenciaNegocios(l);
			primero->setSiguiente(actual);
		}
	}

	void imprimeListaInteligenciaNegocios() {
		actual = primero;
		cout << "Estos son todos los vuelos que se encuentran disponibles segun el lugar de origen y lugar de destino que usted digito: " << endl << endl;
		while (actual != NULL) {
			actual->getInteligenciaNegocios().mostrarInformacion();
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

	~ListaInteligenciaNegocios() {
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