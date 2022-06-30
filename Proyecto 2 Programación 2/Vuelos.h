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

	Vuelos() {  //Constructor
		lugarOrigen = "";
		lugarDestino = "";
		tiempoTrayectoria = "";
		costoVuelos = "";
		idVuelo = "";

	}

	Vuelos(string nLugarOrigen, string nLugarDestino, string nTiempoTrayectoria, string nCostoVuelos, string nIdVuelo) {   //contructor con parametros.
		setLugarOrigen(nLugarOrigen);
		setLugarDestino(nLugarDestino);
		setTiempoTrayectoria(nTiempoTrayectoria);
		setCostoVuelos(nCostoVuelos);
		setIdVuelos(nIdVuelo);
	}

	




	void setLugarOrigen(string nLugarOrigen) {   // Este Metodo se encarga de crea el set lugarOrigen.
		this->lugarOrigen = nLugarOrigen;
	}

	string getLugarOrigen() {   // Este Metodo se encarga de crear el get de lugarOrigen.
		return this->lugarOrigen;
	}


	void setLugarDestino(string nLugarDestino) {   // Este Metodo se encarga de crea el set lugarDestino
		this->lugarDestino = nLugarDestino;
	}

	string getLugarDestino() {   // Este Metodo se encarga de crear el get de lugarDestino
		return this->lugarDestino;
	}


	void setTiempoTrayectoria(string nTiempoTrayectoria) {  // Este Metodo se encarga de crea el set de tiepotrayectoria
		this->tiempoTrayectoria = nTiempoTrayectoria;
	}

	string getTiempoTrayectoria() {   // Este Metodo se encarga de crear el get de tiempotrayectoria
		return this->tiempoTrayectoria;
	}



	void setCostoVuelos(string nCostoVuelos) {   // Este Metodo se encarga de crea el set costoVuelos
		this->costoVuelos = nCostoVuelos;
	}

	string getCostoVuelos() {   // Este Metodo se encarga de crear el get de vuelos
		return this->costoVuelos;
	}


	void setIdVuelos(string nIdVuelos) {   // Este Metodo se encarga de crea el set de Idvuelos
		this->idVuelo = nIdVuelos;
	}

	string getIdVuelos() {   //Este Metodo se encarga de crear el get de idvuelos
		return this->idVuelo;
	}


	void mostrarDatosVuelos() {     // Metodo para mostrar la informacion.
		cout << "Lugar de Origen: " << getLugarOrigen() << "	Lugar de Destino: " << getLugarDestino() << "	Tiempo de Trayectoria: " << getTiempoTrayectoria() << "	  Costo de Vuelo: " << getCostoVuelos() << "	Id de los vuelo: " << getIdVuelos() << endl << endl;
	}



	~Vuelos() {}   //destructor
};
