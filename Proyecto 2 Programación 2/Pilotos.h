#pragma once
#include <iostream>

using namespace std;


class Pilotos {

private:
	string nombre;

public:

	Pilotos() {   //Contructor
		nombre = "";
	}

	Pilotos(string nNombre) {   
		setNombre(nNombre);
	}

	void setNombre(string nNombre) {    //Este Metodo se encarga de crea el set de nombre
		this->nombre = nNombre;
	}

	string getNombre() {    // Este Metodo se encarga de crear el get de nombre
		return this->nombre;
	}

	void mostrarNombrePilotos() {   // Metodo para mostrar la informacion del nombre.
		cout << "Nombre: " << getNombre() << endl << endl;
	}



	~Pilotos() {}  // destructor
};
