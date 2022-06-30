#pragma once
#include <iostream>
using namespace std;

class Usuarios {

private:
	string nombre;
	string edad;
	string numero_telefonico;
	string contrasenia;
	string nombre_usuario;

public:

	Usuarios() {
		nombre = "";
		edad = "";
		numero_telefonico = "";
		contrasenia = "";
		nombre_usuario = "";
	}

	Usuarios(string nNombre, string nEdad, string nNumero, string nContrasenia, string nNombreUsuario) {  // Contructor con parametros
		setNombre(nNombre);
		setEdad(nEdad);
		setNumero(nNumero);
		setContrasenia(nContrasenia);
		setNombreUsuario(nNombreUsuario);
	}

	void setNombre(string nNombre) {     // Este Metodo se encarga de crea el set de nombre.
		this->nombre = nNombre;
	}

	void setEdad(string nEdad) {    // Este Metodo se encarga de crea el set de edad.
		this->edad = nEdad;
	}

	void setNumero(string nNumero) {   // Este Metodo se encarga de crea el set de numero.
		this->numero_telefonico = nNumero;
	}

	void setContrasenia(string nContrasenia) {    // Este Metodo se encarga de crea el set de contrasenia.
		this->contrasenia = nContrasenia;
	}

	void setNombreUsuario(string nNombreUsuario) {     // Este Metodo se encarga de crea el set de nombre usuario.
		this->nombre_usuario = nNombreUsuario;
	}

	string getNombre() {    // Este Metodo se encarga de crea el get de nombre.
		return this->nombre;
	}

	string getEdad() {      // Este Metodo se encarga de crea el get de edad.
		return this->edad;
	}

	string getNumero() {    // Este Metodo se encarga de crea de get de numero.
		return this->numero_telefonico;
	}

	string getContrasenia() {    // Este Metodo se encarga de crea el get de contrasenia.
		return this->contrasenia;
	}

	string getNombreUsuario() {    // Este Metodo se encarga de crea el get de nombre usuario.
		return this->nombre_usuario;
	}

};
