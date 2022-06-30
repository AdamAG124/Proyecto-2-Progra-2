#pragma once
#include "NodoPilotos.h"

using namespace std;

class ListaPilotos {

private:
	NodoPilotos* primero;
	NodoPilotos* actual;

public:

	ListaPilotos() {
		primero = actual = NULL;
	}

	void insertar(Pilotos p) {    // Este metodo lo que hace es que se guarda la informacion para la lista
		actual = primero;
		if (primero == NULL) {
			primero = new NodoPilotos(p);
		}
		else {
			primero = new NodoPilotos(p);
			primero->setSiguiente(actual);
		}
	}

	void imprimeListaPilotos() {    // Este metodo se encarga de imprimir los datos actuales que tiene.
		actual = primero;
		cout << "Lista de pilotos: " << endl << endl;
		while (actual != NULL) {
			actual->getPiltos().mostrarNombrePilotos();
			actual = actual->getSiguiente();
		}
		cout << endl;
	}

	/*void buscarElementoListaPilotos(string nombre) {
		//actual = new Nodo(numero);
		actual = primero;
		bool band = false;

		while ((actual != NULL) && (actual->getPiltos().getNombre() <= nombre)) {
			if (actual->getPiltos().getNombre() == nombre) {
				band = true;
			}
			actual = actual->getSiguiente();
		}

		if (band == true) {
			cout << "El nombre " << nombre << " si se encuentra en la lista." << endl;
		}
		else {
			cout << "El nombre " << nombre << " no se encuentra en la lista." << endl;
		}
	*/

	~ListaPilotos() {   //Destructor de la listaPilotos
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
