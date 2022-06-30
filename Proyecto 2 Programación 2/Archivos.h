#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "ListaVuelos.h"
#include "ListaAviones.h"
#include "ListaPilotos.h"
#include "ListaInteligenciaNegocios.h"

// Esta clase se encarga unicamente del control de los archivos de texto.

using namespace std;

struct Archivos {
	Vuelos v;
	Pilotos p;
	Aviones a;
	InteligenciaNegocios in;
	ListaVuelos listaVuelos;
	ListaPilotos listaP;
	ListaAviones listaA;
	ListaInteligenciaNegocios listaI;
	//Este metodo se encarga de registrar los datos del usuario al
	void escribirArchivoUsuarios(string nombre, string edad, string numero, string contrasenia, string nombreUsuario) {

		std::ofstream of("Usuarios.txt", std::ios::app);

		of << "\nUsuario:" + nombreUsuario + ", " + "Nombre:" + nombre + "% " + "Edad:" + edad + "# " + "Numero:" + numero + "$ " + "Contra:" + contrasenia;
		of.close();
	}

	void escribirArchivoVuelos(string lugarOrigen, string lugarDestino, string tiempoTrayectoria, string costoVuelos, string idVuelo) {
		std::ofstream of("Vuelos.txt", std::ios::app);

		of << "\nOrigen:" + lugarOrigen + ", " + "Destino:" + lugarDestino + "% " + "Duracion:" + tiempoTrayectoria + "# " + "Precio:" + costoVuelos + "$ " + "ID:" + idVuelo;
		of.close();
	}

	void escribirArchivoPilotos(string nombre) {
		std::ofstream of("Pilotos.txt", std::ios::app);

		of << "\nNombre:" + nombre + ".";
		of.close();
	}

	void escribirArchivoAviones(string nombreAerolinea, string numeroAsientos) {
		std::ofstream of("Aviones.txt", std::ios::app);

		of << "\nAerolinea:" + nombreAerolinea + ", " << "Numero de asientos:" << numeroAsientos;
		of.close();
	}

	void leerArchivoPilotos() {
		string txt = "";
		ifstream fs;
		fs.open("Pilotos.txt", ios::in);

		if (fs.fail()) {
			cout << "Error al abrir el archivo.";
		}

		while (!fs.eof()) {
			getline(fs, txt);
			p.setNombre(txt.substr(7, txt.find(".") - 7));
			Pilotos pi(p.getNombre());
			listaP.insertar(pi);
		}
		fs.close();
	}

	void leerArchivoAviones() {
		string txt = "";
		ifstream fs;
		fs.open("Aviones.txt", ios::in);

		if (fs.fail()) {
			cout << "Error al abrir el archivo.";
		}

		while (!fs.eof()) {
			getline(fs, txt);
			a.setNombreAerolinea(txt.substr(10, txt.find(",") - 10));
			a.setNumeroAsientos(txt.substr(txt.find(",") + 21, txt.length()));
			Aviones av(a.getNombreAerolinea(), a.getNumeroAsientos());
			listaA.insertarAviones(av);
		}
		fs.close();
	}

	string leerArchivoUsuarios(string usuario) {
		string txt = "";
		string texto = "";
		ifstream fs;
		fs.open("Usuarios.txt", std::ios::in);

		if (fs.fail()) {
			cout << "Error al abrir el archivo.";
		}

		while (!fs.eof()) {
			getline(fs, txt);
			if (txt.find(usuario) != string::npos) {
				texto = txt;
			}
		}
		fs.close();
		return texto;
	}

	void leerArchivoVuelos() {
		string txt = "";
		ifstream fs;
		fs.open("Vuelos.txt", std::ios::in);

		if (fs.fail()) {
			cout << "Error al abrir el archivo.";
		}

		while (!fs.eof()) {
			getline(fs, txt);
			v.setLugarOrigen(txt.substr(7, txt.find(",") - 7));
			v.setLugarDestino(txt.substr(txt.find(",") + 10, txt.find("%") - 20));
			v.setTiempoTrayectoria(txt.substr(txt.find("%") + 11, txt.find("#") - 34));
			v.setCostoVuelos(txt.substr(txt.find("#") + 9, txt.find("$") - 48));
			v.setIdVuelos(txt.substr(txt.find("$") + 5, txt.length()));
			Vuelos v1(v.getLugarOrigen(), v.getLugarDestino(), v.getTiempoTrayectoria(), v.getCostoVuelos(), v.getIdVuelos());
			listaVuelos.insertarVuelos(v1);
		}
		fs.close();
	}

	bool buscarEnTXT(string dato, string texto) {
		if (texto.find(dato) != std::string::npos) {
			return true;
		}
		else {
			return false;
		}
	}

	bool validarAcceso(std::string texto, std::string nombre, std::string contrasenia) {
		string usuario = texto.substr(8, texto.find(",") - 8);
		string contra = texto.substr(texto.find("$") + 9, texto.length());

		if (usuario == nombre && contra == contrasenia) {
			return true;
		}
		else {
			return false;
		}
	}

	void informacionVuelosInteligenciaNegocios(string vueloOrigen, string vueloDestino) {
		string txt = "";
		string texto = "";
		ifstream fs;
		fs.open("Vuelos.txt", std::ios::in);

		if (fs.fail()) {
			cout << "Error al abrir el archivo.";
		}

		while (!fs.eof()) {
			getline(fs, txt);
			if(txt.find(vueloOrigen) != string::npos && txt.find(vueloDestino) != string::npos){
				texto = txt + "\n";
				InteligenciaNegocios inT(texto);
				listaI.insertar(inT);
			}
		}
		fs.close();
	}
};