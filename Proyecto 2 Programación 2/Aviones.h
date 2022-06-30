#pragma once
#include <iostream>
#include <sstream>

using namespace std;


class Aviones {

private:
	string nombreAerolinea;
	string numeroAsientos;
	string asientos[61][10];  

public:

	Aviones() {
		nombreAerolinea = "";
		numeroAsientos = "";
		for (int i = 0; i < 61; i++) {   // se crea la matriz
			for (int j = 0; j < 10; j++) {
				asientos[i][j] = "";
			}
		}
	}

	Aviones(string nNombreAerolinea, string nNumeroAsientos) {  
		setNombreAerolinea(nNombreAerolinea);
		setNumeroAsientos(nNumeroAsientos);
	}

	void setNombreAerolinea(string nNombreAerolinea) {  //Este Metodo se encarga de crea el set de nombreAerolinea
		this->nombreAerolinea = nNombreAerolinea;
	}

	string getNombreAerolinea() {   //Este Metodo se encarga de crear el get de nombreAerolinea
		return this->nombreAerolinea;
	}

	void setNumeroAsientos(string nNumeroAsientos) {    // Este Metodo se encarga de crea el set de numeroAsientos
		this->numeroAsientos = nNumeroAsientos; 
	}

	string getNumeroAsientos() {   // Este Metodo se encarga de crear el get de numeroAsientos
		return this->numeroAsientos;
	}

	void mostrarDatosAviones() {    // Metodo para mostrar la informacion de nombre aerolinea y numero de asientos
		cout << "Nombre de Aerolinea: " << getNombreAerolinea() << "	Numero de Asientos: " << getNumeroAsientos() << endl << endl;
	}

	string toString() {    // Este metodo es el de to string para crear los asientos
		stringstream s;
		for (int i = 0; i < 61; i++) {
			for (int j = 0; j < 10; j++) {
				s << "[" << asientos[i][j] << "] ";
			}
			s << endl;
		}
		s << endl;
		return s.str();
	}


	~Aviones() {}   // destructor
};
