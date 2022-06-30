#pragma 
#include <iostream>
using namespace std;

class InteligenciaNegocios {

private:
	string informacion;

public:
	InteligenciaNegocios(){
		informacion = "";
	}

	InteligenciaNegocios(string nInformacion) {
		setInformacion(nInformacion);
	}

	void setInformacion(string nInformacion) {
		this->informacion = nInformacion;
	}

	string getInformacion() {
		return this->informacion;
	}

	void mostrarInformacion() {
		cout << getInformacion();
	}

};