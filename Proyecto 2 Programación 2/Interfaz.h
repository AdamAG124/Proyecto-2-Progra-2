#pragma once
#include <iostream>
#include <string>

using namespace std;

class Interfaz {

public:

	Interfaz(){}

	void imprimirMensaje(string txt) { //Metodo general para la impresion de mensajes por pantalla.
		cout << txt;
	}

	string recibirDato(string txt) { //Metodo general para recibir datos de tipo string del usuario.
		string dato = "";
		cin.ignore();
		cout << txt;
		getline(cin, dato);
		return dato;
	}

	int recibirValor(string txt) { //Metodo general para recibir datos de tipo int del usuario.
		int valor = 0;
		cout << txt;
		cin >> valor;
		return valor;
	}

	void limpiarPantalla() {
		system("cls");
	}
};