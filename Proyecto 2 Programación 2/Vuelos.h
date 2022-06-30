#include <iostream>

using namespace std;


class Vuelos {

private:
	string lugarOrigen;
	string lugarDestino;
	string tiempoTrayectoria;
	string costoVuelos;
	string idVuelo;

public:

	Vuelos() {
		lugarOrigen = "";
		lugarDestino = "";
		tiempoTrayectoria = "";
		costoVuelos = "";
		idVuelo = "";

	}

	Vuelos(string nLugarOrigen, string nLugarDestino, string nTiempoTrayectoria, string nCostoVuelos, string nIdVuelo) {
		setLugarOrigen(nLugarOrigen);
		setLugarDestino(nLugarDestino);
		setTiempoTrayectoria(nTiempoTrayectoria);
		setCostoVuelos(nCostoVuelos);
		setIdVuelos(nIdVuelo);
	}

	




	void setLugarOrigen(string nLugarOrigen) {
		this->lugarOrigen = nLugarOrigen;
	}

	string getLugarOrigen() {
		return this->lugarOrigen;
	}


	void setLugarDestino(string nLugarDestino) {
		this->lugarDestino = nLugarDestino;
	}

	string getLugarDestino() {
		return this->lugarDestino;
	}


	void setTiempoTrayectoria(string nTiempoTrayectoria) {
		this->tiempoTrayectoria = nTiempoTrayectoria;
	}

	string getTiempoTrayectoria() {
		return this->tiempoTrayectoria;
	}



	void setCostoVuelos(string nCostoVuelos) {
		this->costoVuelos = nCostoVuelos;
	}

	string getCostoVuelos() {
		return this->costoVuelos;
	}


	void setIdVuelos(string nIdVuelos) {
		this->idVuelo = nIdVuelos;
	}

	string getIdVuelos() {
		return this->idVuelo;
	}


	void mostrarDatosVuelos() {
		cout << "Lugar de Origen: " << getLugarOrigen() << "	Lugar de Destino: " << getLugarDestino() << "	Tiempo de Trayectoria: " << getTiempoTrayectoria() << "	  Costo de Vuelo: " << getCostoVuelos() << "	Id de los vuelo: " << getIdVuelos() << endl << endl;
	}



	~Vuelos() {}
};