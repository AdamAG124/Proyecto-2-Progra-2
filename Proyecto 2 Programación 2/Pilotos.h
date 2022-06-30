#pragma once
#include <iostream>

using namespace std;


class Pilotos {

private:
	string nombre;

public:

	Pilotos() {
		nombre = "";
	}

	Pilotos(string nNombre) {
		setNombre(nNombre);
	}

	void setNombre(string nNombre) {
		this->nombre = nNombre;
	}

	string getNombre() {
		return this->nombre;
	}

	void mostrarNombrePilotos() {
		cout << "Nombre: " << getNombre() << endl << endl;
	}



	~Pilotos() {}
};