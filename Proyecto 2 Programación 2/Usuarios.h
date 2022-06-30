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

	Usuarios(string nNombre, string nEdad, string nNumero, string nContrasenia, string nNombreUsuario) {
		setNombre(nNombre);
		setEdad(nEdad);
		setNumero(nNumero);
		setContrasenia(nContrasenia);
		setNombreUsuario(nNombreUsuario);
	}

	void setNombre(string nNombre) {
		this->nombre = nNombre;
	}

	void setEdad(string nEdad) {
		this->edad = nEdad;
	}

	void setNumero(string nNumero) {
		this->numero_telefonico = nNumero;
	}

	void setContrasenia(string nContrasenia) {
		this->contrasenia = nContrasenia;
	}

	void setNombreUsuario(string nNombreUsuario) {
		this->nombre_usuario = nNombreUsuario;
	}

	string getNombre() {
		return this->nombre;
	}

	string getEdad() {
		return this->edad;
	}

	string getNumero() {
		return this->numero_telefonico;
	}

	string getContrasenia() {
		return this->contrasenia;
	}

	string getNombreUsuario() {
		return this->nombre_usuario;
	}

};