#pragma once
#include "Interfaz.h"

//#include "ListaVuelos.h"
#include "Usuarios.h"
#include "Archivos.h"

class Controladora {
 
public:

	Controladora(){}

	Interfaz in;
	Usuarios us;
	Archivos ar;

	void iniciarPrograma() {
		int opcion = 0, opcion1 = 0, opcion2 = 0, cantidad = 0, contador = 0;

		do {
			in.limpiarPantalla();
			opcion1 = in.recibirValor("1.Administracion General\n\n2.Reservas\n\n3.Inteligencia de negocios\n\n4.Salir\n"); //Menu principal de opciones de opciones
			in.limpiarPantalla();
			switch (opcion1) { //Se evalua la opcion que digito el usuario en el menu principal.
				case 1:
					do {
						opcion = in.recibirValor("1.Ingresar pilotos/aviones/vuelos\n\n2.Reportes\n\n3.Regresar al menu principal\n"); //Menu secundario de opciones
						in.limpiarPantalla();
						switch (opcion) { //Se evalua la opcion que selecciono el usuario en el menu secundario de opciones
							case 1:
								do {
									in.limpiarPantalla();
									opcion2 = in.recibirValor("1.Ingresar Pilotos\n\n2.Ingresar Aviones\n\n3.Ingresar Vuelos\n\n4.Regresar\n"); //Otro menu secundario
									in.limpiarPantalla();
									switch (opcion2) { //Otra evaluacion secundaria de opciones
										case 1:
											cantidad = in.recibirValor("Digite la cantidad de Pilotos que desea ingresar: "); //Se le solicita ina cantidad de pilotos para la lista al usuario.
											for (int i = 0; i < cantidad; i++){ //El bucle acaba hasta que se hayan registrado todos los pilotos que el usuario especifico el usuario arriba.
												ar.p.setNombre(in.recibirDato("Digite el nombre del piloto: ")); //Se setea el nombre del piloto a la variable de su clase
												ar.escribirArchivoPilotos(ar.p.getNombre());//Se regista la informacion del piloto en un archivo de texro
												ar.leerArchivoPilotos();//Se lee la informacion registrada en el archivo de los pilotos y en el mismo metodo se introduce dicha informacion a la lista.
											}
										break;

										case 2:
											cantidad = in.recibirValor("Digite la cantidad de aviones que desea ingresar: ");//Se hacen todos lo mismos pasos que en pilotos pero con la informacion de los aviones
											for (int i = 0; i < cantidad; i++) {
												in.limpiarPantalla();
												ar.a.setNombreAerolinea(in.recibirDato("Digite el nombre de la aerolinea: "));
												ar.a.setNumeroAsientos(in.recibirDato("Digite el numero de asientos del avion: "));
												ar.escribirArchivoAviones(ar.a.getNombreAerolinea(), ar.a.getNumeroAsientos());
												ar.leerArchivoAviones();
											}
										break;

										case 3:
											cantidad = in.recibirValor("Digite la cantidad de vuelos que desea ingresar: "); //Lo mismo que con pilotos y aviones pero para los vuelos.
											for (int i = 0; i < cantidad; i++) {
												in.limpiarPantalla();
												ar.v.setLugarOrigen(in.recibirDato("Digite el nombre del lugar de origen: "));
												ar.v.setLugarDestino(in.recibirDato("Digite el nombre del lugar de destino: "));
												ar.v.setTiempoTrayectoria(in.recibirDato("Digite la duración del viaje: "));
												ar.v.setCostoVuelos(in.recibirDato("Digite el costo del vuelo: "));
												ar.v.setIdVuelos(in.recibirDato("Digite el numero del vuelo: "));
												ar.escribirArchivoVuelos(ar.v.getLugarOrigen(), ar.v.getLugarDestino(), ar.v.getTiempoTrayectoria(), ar.v.getCostoVuelos(), ar.v.getIdVuelos());
												ar.leerArchivoVuelos();
										 }
										break;
									}
								} while (opcion2 != 4);
								in.limpiarPantalla();
							break;

							case 2:
								do {
									in.limpiarPantalla();
									opcion2 = in.recibirValor("1.Imprimir Pilotos\n\n2.Imprimir Aviones\n\n3.Imprimir Vuelos\n\n4.Regresar\n");//Otro menu secundario 
									switch (opcion2) {//Se evalua la opcion seleccionada
										case 1:
											ar.leerArchivoPilotos(); //Se lee el archivo de los pilotos y si hay informacion se extrae y se introduce en la lista de los pilotos.
											do {
												in.limpiarPantalla();//Se limpia la pantalla 
												ar.listaP.imprimeListaPilotos(); //Se imprime la lista de los pilotos.
											} while (in.recibirValor("Si desea regresar digite 1, si no digite cualquier otro numero: ") != 1);//Se le solicita al usario si desea regresar al menu secundario o si desea volver a imprimir la lista.
										break;

										case 2:
											//Se hace exactamente lo mismo que con la impresion de la lista de los pilotos.
											ar.leerArchivoAviones();
											do {
												in.limpiarPantalla();
												ar.listaA.imprimeListaAviones();
											} while (in.recibirValor("Si desea regresar digite 1, si no digite cualquier otro numero: ") != 1);
										break;

										case 3:
											//Se hace exactamente lo mismo que con la impresion de la lista de los pilotos y aviones
											ar.leerArchivoVuelos();
											do {
												in.limpiarPantalla();
												ar.listaVuelos.imprimeListaVuelos();
											} while (in.recibirValor("Si desea regresar digite 1, si no digite cualquier otro numero: ") != 1);
										break;
									}
								} while (opcion2 != 4);
								
								in.limpiarPantalla();
							break;
						}
					} while (opcion != 3);
					system("cls");
				break;

				case 2:
					in.limpiarPantalla();
					opcion= in.recibirValor("\nIniciar secion digite 1.\n\nRegistrarse digite 2.\n\nSalir al menu principal digite 3.\n"); //Menu secundario del area de reservas
					switch (opcion) { //Se evalua la opcion digitada por el usuario.
						case 1://en el caso 1 se inicia la secion con usuario previamente creado
							do {
								in.limpiarPantalla();//se limpia la pantalla.
								us.setNombre(in.recibirDato("\nDigite su nombre de usuario: "));//Se solicita l nombre de usuario y se setea en la variable de su clase
								us.setContrasenia(in.recibirDato("\nDigite su contrasenia: "));//se solicita la contraseña y se seta en la variable de su clase
								in.limpiarPantalla();//Se limpia lapnatalla
								if (ar.buscarEnTXT(us.getNombre(), ar.leerArchivoUsuarios(us.getNombre())) == true) { //Se busca el el nombre de usuario en el archio que contiene la informacion de los usuarios
									if (ar.validarAcceso(ar.leerArchivoUsuarios(us.getNombre()), us.getNombre(), us.getContrasenia()) == true) {//Si el nombre de usuario existe se valida que la contraseña pertenezca a dicho nombre.
										in.imprimirMensaje("\nAcceso Permitido.\n");//De estar correctos el nombre de usuario y la contraseña se le informa al usuario que tiene el acceso permitido.
										do {
											contador++;//Un contador que solo servira para saber si es la segunda o mayor corrida del bucle do while
											if (contador > 1) {//Dicho contador solo se uss para limpiar la pantalla siempre y cuando no sea la primera corrida del bucle.
												in.limpiarPantalla();
											}

											switch (in.recibirValor("\n1.Reservar\n\n2.Modificar")) {//Menu de opciones del area de usuarios
												case 1:
													ar.listaVuelos.imprimeListaVuelos();//Se imprime la lista de los vuelos disponibles
													in.imprimirMensaje(ar.a.toString());//se imprime la matriz que representa los asientos del avion.

													/*Inserte logica para la reserva de los vuelos*/
												break;

												case 2:
													/*Inserte logica para la modificacion de los vuelos.*/
												break;
											}
										}while(in.recibirValor("\nSi desea seguir usando el sistema de reservas digite 1, si no digite cualquier otro numero\n") == 1);//Se solicita al usuario de que digite si quiere continuar en el area de reservas o en si quiere regresar al menu secundario.
									}
									else {
										in.imprimirMensaje("Acceso denegado.");//Si la contraseña no coincide con el nombe del usuario se le indica que tiene el acceso denegado.
									}
								}
								else {
									in.imprimirMensaje("\n\nUsuario no existe.\n");//De no encontrar el nombre del usuario en el archivo que guarda la informacion de los usuarios se le indica que el usuario no existe.
								}
							} while (ar.buscarEnTXT(us.getNombre(), ar.leerArchivoUsuarios(us.getNombre())) == false || ar.validarAcceso(ar.leerArchivoUsuarios(us.getNombre()), us.getNombre(), us.getContrasenia()) == false);//El bucle se repite si se cumple que el usuario no existe o que el acceso fue denegado.
						break;

						case 2:
							//En esta area se hace la creación de un nuevo usuario.
							in.limpiarPantalla();//Se limpia la pantalla.
							us.setNombre(in.recibirDato("\nDigite su nombre: "));//Se solicita el nombre del nuevo usuaio y se setea en su respectiva variable de su respectiva clase.
							us.setEdad(in.recibirDato("\nDigite su edad: "));//Se solicita la edad del nuevo usuaio y se setea en su respectiva variable de su respectiva clase.
							us.setNumero(in.recibirDato("\nDigite su numero telefonico: "));//Se solicita el numero de telefono del nuevo usuaio y se setea en su respectiva variable de su respectiva clase.
							us.setNombreUsuario(in.recibirDato("\nDigite un nombre de usuario: "));//Se solicita el nombre de usuario del nuevo usuaio y se setea en su respectiva variable de su respectiva clase.
							us.setContrasenia(in.recibirDato("Digite una contrasenia: "));//Se solicita la contraseña del nuevo usuaio y se setea en su respectiva variable de su respectiva clase.
							if (ar.buscarEnTXT(us.getNombre(), ar.leerArchivoUsuarios(us.getNombre())) == true) { //Se busca en el archivo de usuarios si ya existe el nombre de usuario ingresado
								in.limpiarPantalla();
								in.imprimirMensaje("El nombre de usuario ya exixtes, porfavor digite otro\n\n");//De existir el nombre de usuario se imprime por pantalla que ya existe y que porfavor digite otro.
							}
							else {
								ar.escribirArchivoUsuarios(us.getNombre(), us.getEdad(), us.getNumero(), us.getContrasenia(), us.getNombreUsuario());//De no existor el nombre del usuario se registra toda su información en un archivo de texto.
								in.limpiarPantalla();
								in.imprimirMensaje("Datos del nuevo usuario almacenados correctamente.\n\n");
							}
						break;
					}
				break;

				case 3:
					
					do {
						//Inteligencia de negocios
						in.limpiarPantalla();
						ar.v.setLugarOrigen(in.recibirDato("Digite el nombre del lugar de origen: "));	//Se le solicita al usuario que digite el lugar de origen del los vuelos que quiere ver.
						ar.v.setLugarDestino(in.recibirDato("Digite el nombre del lugar de destino: "));//Se le solicita al usuario que digite el lugar de destino del los vuelos que quiere ver.
						ar.informacionVuelosInteligenciaNegocios(ar.v.getLugarOrigen(), ar.v.getLugarDestino());//Se pasa dicha informacion a este metodo el cual busca si existen los vuelos con el lugar de origen y destino digitado por el usuario, y si si existen los iserta en una lista
						ar.listaI.imprimeListaInteligenciaNegocios(); //Se imprime la lista de los vuelos especificos solicitados por el usuario.
						ar.listaI.~ListaInteligenciaNegocios();//Se destruye la lista.
					}while(in.recibirValor("\n\nSi desea consultar otra lista de vuelos especificos digite 1, sino digite cualquier otro numero.") == 1);//Se le solicita al usuario si desea seguir buscando vuelos especificos o si desea volver al menu principal.
				break;
			}
		} while (opcion1 != 4);
	}
};
