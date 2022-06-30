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
		for (int i = 0; i < 61; i++) {
			for (int j = 0; j < 10; j++) {
				asientos[i][j] = "";
			}
		}
	}

	Aviones(string nNombreAerolinea, string nNumeroAsientos) {
		setNombreAerolinea(nNombreAerolinea);
		setNumeroAsientos(nNumeroAsientos);
	}

	void setNombreAerolinea(string nNombreAerolinea) {
		this->nombreAerolinea = nNombreAerolinea;
	}

	string getNombreAerolinea() {
		return this->nombreAerolinea;
	}

	void setNumeroAsientos(string nNumeroAsientos) {
		this->numeroAsientos = nNumeroAsientos;
	}

	string getNumeroAsientos() {
		return this->numeroAsientos;
	}

	void mostrarDatosAviones() {
		cout << "Nombre de Aerolinea: " << getNombreAerolinea() << "	Numero de Asientos: " << getNumeroAsientos() << endl << endl;
	}

	string toString() {
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


	~Aviones() {}
};
