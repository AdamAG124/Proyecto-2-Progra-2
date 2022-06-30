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
	//Este metodo se encarga de registrar los datos del usuario al archivo de los usuarios.
	void escribirArchivoUsuarios(string nombre, string edad, string numero, string contrasenia, string nombreUsuario) { //Recibe por parametros la informacion que va a registrar dentro del archivo de texto

		std::ofstream of("Usuarios.txt", std::ios::app);

		of << "\nUsuario:" + nombreUsuario + ", " + "Nombre:" + nombre + "% " + "Edad:" + edad + "# " + "Numero:" + numero + "$ " + "Contra:" + contrasenia; //Se escribe dentro de la variable of toda la informacion que se quiere registrar dentro del archivo de texto
		of.close();
	}
	//Este metodo se encarga de registrar los datos de los vuelos al archivo de los vuelos.
	void escribirArchivoVuelos(string lugarOrigen, string lugarDestino, string tiempoTrayectoria, string costoVuelos, string idVuelo) { //Recibe por parametros la informacion que va a registrar dentro del archivo de texto
		std::ofstream of("Vuelos.txt", std::ios::app);
		
		of << "\nOrigen:" + lugarOrigen + ", " + "Destino:" + lugarDestino + "% " + "Duracion:" + tiempoTrayectoria + "# " + "Precio:" + costoVuelos + "$ " + "ID:" + idVuelo; //Se escribe dentro de la variable of toda la informacion que se quiere registrar dentro del archivo de texto
		of.close(); //Se cierra el archivo
	}
	//Este metodo se encarga de registrar los datos del pilotos al archivo de los pilotos.
	void escribirArchivoPilotos(string nombre) {  //Recibe por parametros la informacion que va a registrar dentro del archivo de texto
		std::ofstream of("Pilotos.txt", std::ios::app);

		of << "\nNombre:" + nombre + ".";
		of.close();
	}
	//Este metodo se encarga de registrar los datos del aviones al archivo de los aviones.
	void escribirArchivoAviones(string nombreAerolinea, string numeroAsientos) {
		std::ofstream of("Aviones.txt", std::ios::app);

		of << "\nAerolinea:" + nombreAerolinea + ", " << "Numero de asientos:" << numeroAsientos;
		of.close();
	}

	void leerArchivoPilotos() {  //Este metodo se encarga de leer el archivo de los pilotos
		string txt = "";
		ifstream fs;
		fs.open("Pilotos.txt", ios::in); //se abre el archivo en modo de lectura

		if (fs.fail()) { //si hay un error al abrir el archivo se imprime el error que esta abajo
			cout << "Error al abrir el archivo.";
		}

		while (!fs.eof()) {  // mientras no sea el final del archivo 
			getline(fs, txt);  //se obtiene de lo que esta en la variable fs y se almacena en la variable txt
			p.setNombre(txt.substr(7, txt.find(".") - 7)); //se sustrae de la variable txt el nombre del piloto y se le setea a la variable nombre de la clase piloto
			Pilotos pi(p.getNombre());  //se crea un objeto de tipo pilotos al cual se le pasa por parametro la informacion de piloto
			listaP.insertar(pi);  //se inserta en la lista de pilotos el objeto de tipo piloto que posee la informacion de los pilotos
		}
		fs.close(); // se cierra el archivo
	}

	void leerArchivoAviones() {  //Este metodo se encarga de leer el archivo de los aviones
		string txt = "";
		ifstream fs; 
		fs.open("Aviones.txt", ios::in); // se abre el archivo de aviones en modo de lectura

		if (fs.fail()) {  //si hay un error al abrir el archivo se imprime el error que esta abajo
			cout << "Error al abrir el archivo.";
		}

		while (!fs.eof()) { // mientras no sea el final del archivo 
			getline(fs, txt); //se obtiene de lo que esta en la variable fs y se almacena en la variable txt
			a.setNombreAerolinea(txt.substr(10, txt.find(",") - 10)); //se sustrae de la variable txt el nombre de la aerolinea y se le setea a la variable nombre aereolinea de la clase aviones
			a.setNumeroAsientos(txt.substr(txt.find(",") + 21, txt.length())); //se sustrae de la variable txt el numero de asientos y se le setea a la variable numero de asientos de la clase aviones
			Aviones av(a.getNombreAerolinea(), a.getNumeroAsientos());  //se crea un objeto de tipo aviones al cual se le pasa por parametro la informacion de aviones
			listaA.insertarAviones(av);  //se inserta en la lista de aviones el objeto de tipo aviones que posee la informacion de los aviones
		}
		fs.close(); //se cierra el archivo
	}

	string leerArchivoUsuarios(string usuario) { //Este metodo se encarga de leer el archivo usuario
		string txt = "";
		string texto = "";
		ifstream fs;
		fs.open("Usuarios.txt", std::ios::in); // se abre el archivo de usuarios en modo de lectura

		if (fs.fail()) {  //si hay un error al abrir el archivo se imprime el error que esta abajo
			cout << "Error al abrir el archivo.";
		}

		while (!fs.eof()) { // mientras no sea el final del archivo
			getline(fs, txt);  //se obtiene de lo que esta en la variable fs y se almacena en la variable txt
			if (txt.find(usuario) != string::npos) {
				texto = txt;
			}
		}
		fs.close();  // se cierra el archivo
		return texto;
	}

	void leerArchivoVuelos() {  //Este metodo se encarga de leer el archivo vuelos
		string txt = "";
		ifstream fs;
		fs.open("Vuelos.txt", std::ios::in);  // se abre el archivo de usuarios en modo de lectura

		if (fs.fail()) {  //si hay un error al abrir el archivo se imprime el error que esta abajo
			cout << "Error al abrir el archivo.";
		}

		while (!fs.eof()) { // mientras no sea el final del archivo
			getline(fs, txt); //se obtiene de lo que esta en la variable fs y se almacena en la variable txt
			v.setLugarOrigen(txt.substr(7, txt.find(",") - 7)); //se sustrae de la variable txt el lugar de origen y se le setea a la variable lugar origen de la clase vuelos
			v.setLugarDestino(txt.substr(txt.find(",") + 10, txt.find("%") - 20));  //se sustrae de la variable txt el lugar destino y se le setea a la varible lugar destino de la clase vuelos
			v.setTiempoTrayectoria(txt.substr(txt.find("%") + 11, txt.find("#") - 34));  //se sustrae de la variable txt el tiempo trayectoria y se le setea a la variable tiempo trayectoria de la clase vuelos
			v.setCostoVuelos(txt.substr(txt.find("#") + 9, txt.find("$") - 48));  //se sustrae de la variable txt el costo vuelos y se le setea a la variable costo vuelos de la clase vuelos
			v.setIdVuelos(txt.substr(txt.find("$") + 5, txt.length()));  //se sustrae de la variable txt el id vuelo y se le setea a la variable id vuelo de la clase vuelos
			Vuelos v1(v.getLugarOrigen(), v.getLugarDestino(), v.getTiempoTrayectoria(), v.getCostoVuelos(), v.getIdVuelos());
			listaVuelos.insertarVuelos(v1);
		}
		fs.close();   // se cierra el archivo
	}

	bool buscarEnTXT(string dato, string texto) { //este metodo se encarga de buscar algo en un txt cualquiera
		if (texto.find(dato) != std::string::npos) { //si dentro del txt que se paso por parametro se encuentra el dato ingresado por el usuario retorna true
			return true;
		}
		else {  //sino se encuentra retorna false
			return false;
		}
	}

	bool validarAcceso(std::string texto, std::string nombre, std::string contrasenia) { // este metodo se encarga de validar el acceso al usuario en el inicio de seccion
		string usuario = texto.substr(8, texto.find(",") - 8); //se sustrae del archivo de texto de los usuarios que se paso por parametros el nombre del usuario y se almacena en la variable usuario
		string contra = texto.substr(texto.find("$") + 9, texto.length()); //se sustrae del archivo de texto de los usuarios que se paso por parametrosla contraseña y se almacena en la variable contra

		if (usuario == nombre && contra == contrasenia) {  //si lo que se sustrajo en el archivo de texto que se almaceno en la variable usuario es igual al nombre que el usuario digito y lo que se sustrajo en el archivo de texto que se almaceno en la variable contra es igual a la contraseña que el usuario digito retorna true
			return true;
		}
		else { // sino retorna false
			return false;
		}
	}

	void informacionVuelosInteligenciaNegocios(string vueloOrigen, string vueloDestino) { ////Este metodo se encarga de leer el archivo de informacion vuelos inteligencia negocios
		string txt = "";
		string texto = "";
		ifstream fs;
		fs.open("Vuelos.txt", std::ios::in);  // se abre el archivo de vuelos en modo de lectura

		if (fs.fail()) {  //si hay un error al abrir el archivo se imprime el error que esta abajo
			cout << "Error al abrir el archivo.";
		}

		while (!fs.eof()) { // mientras no sea el final del archivo
			getline(fs, txt);  //se obtiene de lo que esta en la variable fs y se almacena en la variable txt
			if(txt.find(vueloOrigen) != string::npos && txt.find(vueloDestino) != string::npos){
				texto = txt + "\n";
				InteligenciaNegocios inT(texto);
				listaI.insertar(inT);
			}
		}
		fs.close(); // se cierra el archivo
	}
};
