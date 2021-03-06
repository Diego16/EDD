#include <iostream>
#include "oficina.h"
#include "oficina.hpp"
#include "paquete.h"
#include "paquete.hpp"
#include "region.h"
#include "region.hpp"
#include "persona.h"
#include "persona.hpp"
#include <list>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <limits.h>
#include <cmath>
#include <cstring>
#include <vector>
#include "Grafo.h"

using namespace std;

bool cargarPersonas(string nombreArchivo, list<Persona*> &personasMemoria);
bool buscarPersona(string cedulaIn, list<Persona*> &personasMemoria);
bool registrarPersona(string nombre, string apellido, string cedula, string direccion, string ciudad, string telefono, list<Persona*> &personasMemoria);
bool cargarPaquetes(string nombreArchivo, list<Paquete*> &paquetesMemoria, list<Persona*> &personasMemoria,list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria);
bool cargarOficinas(string nombreArchivo, list<Oficina*> &oficinasMemoria, Grafo<Oficina*> &grafo);
bool cargarRegiones(string nombreArchivo, list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria,Grafo<Oficina*> &grafo);
bool cargarConexiones(string nombreArchivo, Grafo<Oficina*> &grafo,list<Oficina*> &oficinasMemoria);
bool registrarPaquete(string cedulaRemitenteIn, string cedulaDestinatarioIn, string pesoIn, string tipoContenidoIn, string numGuiaIn,
					  string codigoOficinaIn, string nombreOficinaIn, string direccionOficinaIn
					  ,string ciudadOficinaIn, string codigoRegionIn, string nombreRegionIn,
					  list<Paquete*> &paquetesMemoria, list<Persona*> &personasMemoria,list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria);
bool registrarOficina(string codigo, string nombre, string direccion, string ciudad,list<Oficina*> &oficinasMemoria, Grafo<Oficina*> &grafo);
bool registrarRegion(string codigo, string nombre, string codigoOficinaPadre,list<Oficina*> &oficinasMemoria,list<Region*> &regionesMemoria, Grafo<Oficina*> &grafo,double distanciaOficinaPadre);
bool registrarPaquete2(string cedulaRemitenteIn, string cedulaDestinatarioIn, string pesoIn, string tipoContenidoIn, string numGuiaIn,string codigoOficinaIn,string codigoRegionIn,list<Paquete*> &paquetesMemoria, list<Persona*> &personasMemoria,list<Oficina*> &oficinasMemoria);
bool buscarPaquete(string numGuiaIn, list<Paquete*> &paquetesMemoria);
Persona* buscarPersona2(string cedulaIn, list<Persona*> &personasMemoria);
bool buscarOficina(string codigo, list<Oficina*> &oficinasMemoria);
bool buscarRegion(string codigo, list<Region*> &regionesMemoria);
Oficina* buscarOficina2(string codigo, list<Oficina*> &oficinasMemoria);
Region* buscarRegion2(string codigo, list<Region*> &regionesMemoria);
void distribuirPaquetes(string codigoOficina,list<Oficina*> &oficinasMemoria,list<Region*> &regionesMemoria);
void imprimirRegiones(list<Region*> &regionesMemoria);
void imprimirOficinas(list<Oficina*> &oficinasMemoria);
void imprimirPaquetesXRegion2(list<Oficina*> &oficinasMemoria);
void encontrarPrincipal(list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria);
void imprimirPaquetesXRegion(list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria, list<Paquete*> &paquetesMemoria);
vector<string> tokenizador(string stringIn, char token);
void contarPaquetes(list<Oficina*> &oficinasMemoria);
int contarPaquetesXRegion(list<Region*> &regionesMemoria);
void imprimirOficinasYReguiones(list<Oficina*> &oficinasMemoria,list<Region*> &regionesMemoria);
int sacarIndice(string codigoOficina,Grafo<Oficina*> &grafo);
NodoGrafo<Oficina*>* buscarVertice2( string codigoOficina,Grafo<Oficina*> &grafo);
NodoGrafo<Oficina*>* buscarVertice( int vertice,Grafo<Oficina*> &grafo);
int minimo(double distancia[], int cantidad);
bool vistosTodos(bool vistos[], int cantidad);
bool siConecta(string oficinaOrigen, string oficinaDestino, Grafo<Oficina*> &grafo,list<Oficina*> &oficinasMemoria);
void rutaMasCorta(string oficinaOrigen, string oficinaDestino,  Grafo<Oficina*> &grafo,list<Oficina*> &oficinasMemoria);

typedef pair<NodoGrafo<Oficina*>*,double> par;

int main()
{
		bool on = true;
		bool encontrado = false;
		string lineIn = " ";
		char comando[300] = {' '};
		list<Persona*> listIn;
		list<Paquete*> listInP;
		list<Oficina*> listInO;
		list<Region*> listInR;
		Grafo<Oficina*> grafoOficina;
		while(on)
		{
				cout << "$ ";
				cin.getline(comando,300);
				char* pch;
				char* miLista[10];
				int cantCmd = 0;
				pch = strtok (comando," ");
				while (pch != NULL)
				{
						miLista[cantCmd] = pch;
						cantCmd++;
						pch = strtok (NULL, " ");
				}
				if (strcmp(miLista[0],"cargarPersonas")==0)
				{
						if (cantCmd==2)
						{
								lineIn = miLista[1];
								if(cargarPersonas(lineIn,listIn))
								{
										cout << "La información desde el archivo " << lineIn << " ha sido cargada exitosamente" << endl;
								}
								else
								{
										cout << "El archivo " << lineIn << " no existe o contiene información inválida" << endl;
								}
						}
						else
						{
								cout << "Parametros invalidos" << endl;
						}
				}
				else if(strcmp(miLista[0],"cargarPaquetes")==0)
				{
						if (cantCmd==2)
						{
								lineIn = miLista[1];
								if(cargarPaquetes(lineIn,listInP, listIn, listInO, listInR))
								{
										cout << "La información desde el archivo " << lineIn << " ha sido cargada exitosamente" << endl;
								}
								else
								{
										cout << "El archivo " << lineIn << " no existe o contiene información inválida" << endl;
								}
						}
						else
						{
								cout << "Parametros invalidos" << endl;
						}
				}
				else if(strcmp(miLista[0],"cargarRegiones")==0)
				{
						if (cantCmd==2)
						{
								lineIn = miLista[1];
								if(cargarRegiones(lineIn,listInO,listInR,grafoOficina))
								{
										cout << "La información desde el archivo " << lineIn << " ha sido cargada exitosamente" << endl;
										encontrarPrincipal(listInO,listInR);
								}
								else
								{
										cout << "El archivo " << lineIn << " no existe o contiene información inválida" << endl;
								}
						}
						else
						{
								cout << "Parametros invalidos" << endl;
						}
				}
				else if(strcmp(miLista[0],"cargarOficinas")==0)
				{
						if (cantCmd==2)
						{
								lineIn = miLista[1];
								if(cargarOficinas(lineIn,listInO,grafoOficina))
								{
										cout << "La información desde el archivo " << lineIn << " ha sido cargada exitosamente" << endl;
								}
								else
								{
										cout << "El archivo " << lineIn << " no existe o contiene información inválida" << endl;
								}
						}
						else
						{
								cout << "Parametros invalidos" << endl;
						}
				}
				else if(strcmp(miLista[0],"cargarConexiones")==0)
				{
						if (cantCmd==2)
						{
								lineIn = miLista[1];
								if(cargarConexiones(lineIn,grafoOficina,listInO))
								{
										cout << "La información desde el archivo " << lineIn << " ha sido cargada exitosamente" << endl;
								}
								else
								{
										cout << "El archivo " << lineIn << " no existe o contiene información inválida" << endl;
								}
						}
						else
						{
								cout << "Parametros invalidos" << endl;
						}
				}
				else if(strcmp(miLista[0],"registrarPersona")==0)
				{
						if (cantCmd==1)
						{
								string nombre,apellido,cedula,direccion,ciudad,telefono;
								cout << "Nombre: ";
								cin.ignore();
								getline(cin,nombre);
								cout << "Apellido: ";
								cin.ignore();
								getline(cin,apellido);
								cout << "Cedula: ";
								cin >> cedula;
								cout << "Direccion: ";
								cin.ignore();
								getline(cin,direccion);
								cout << "Telefono: ";
								cin >> telefono;
								if(registrarPersona(nombre,apellido,cedula,direccion,ciudad,telefono,listIn))
										cout << "La persona con identificación " << cedula << " ha sido registrado exitosamente" << endl;
								else
										cout << "La persona con identificación " << cedula << " ya se encuntra registrada en el sistema" << endl;
						}
						else
						{
								cout << "Parametros invalidos" << endl;
						}
				}
				else if(strcmp(miLista[0],"registrarPaquete")==0)
				{
						if (cantCmd==1)
						{
								string cedulaRemitente,cedulaDestinatario,peso,tipoContenido,numGuia,codigoOficina,codigoRegion;
								cout << "Cedula remitente: ";
								cin >> cedulaRemitente;
								cout << "Cedula destinatario: ";
								cin >> cedulaDestinatario;
								cout << "Peso: ";
								cin >> peso;
								cout << "Tipo de contenido: ";
								cin.ignore();
								getline(cin,tipoContenido);
								cout << "Numero de guia: ";
								cin >> numGuia;
								cout << "Codigo Oficina: ";
								cin >> codigoOficina;
								cout << "Codigo Region: ";
								cin >> codigoRegion;
								if(registrarPaquete2(cedulaRemitente,cedulaDestinatario,peso,tipoContenido,numGuia,codigoOficina,codigoRegion,listInP,listIn,listInO))
										// string cedulaRemitenteIn, string cedulaDestinatarioIn, string pesoIn, string tipoContenidoIn, string numGuiaIn,string codigoOficinaIn,list<Paquete*> &paquetesMemoria, list<Persona*> &personasMemoria,list<Oficina*> &oficinasMemoria);
										cout << "El paquete con numero de guia " << numGuia << " ha sido registrado exitosamente" << endl;
								else
										cout << "El paquete con numero de guia " << numGuia << " ya se encuentra registrado en el sistema" << endl;
						}
						else
						{
								cout << "Parametros invalidos" << endl;
						}
				}
				else if(strcmp(miLista[0],"registrarRegion")==0)
				{
						if (cantCmd==1)
						{
								string codReg, nombre, codigoOficinaPadre;
								double distanciaOficina;
								cout << "Codigo de la region: ";
								cin >> codReg;
								cout << "Nombre de la region: ";
								cin.ignore();
								getline(cin,nombre);
								cout << "Codigo oficina: ";
								cin >> codigoOficinaPadre;
								cout << "Distacia a oficina padre: ";
								cin >> distanciaOficina;
								if(registrarRegion(codReg, nombre, codigoOficinaPadre,listInO,listInR,grafoOficina,distanciaOficina))
										cout << "La region identificada con el codigo " << codReg << " ha sido registrada exitosamente" << endl;
								else
										cout << "La region identificada con el codigo " << codReg << " ya se encuentra registrado en el sistema" << endl;
						}
						else
						{
								cout << "Parametros invalidos" << endl;
						}
				}
				else if(strcmp(miLista[0],"registrarOficina")==0)
				{
						if (cantCmd==1)
						{
								string codOfi,nombre,direccion,ciudad;
								cout << "Codigo oficina: ";
								cin >> codOfi;
								cout << "Nombre oficina: ";
								cin.ignore();
								getline(cin,nombre);
								cout << "Direccion: ";
								cin.ignore();
								getline(cin,direccion);
								cout << "Ciudad: ";
								cin.ignore();
								getline(cin,ciudad);
								if(registrarOficina(codOfi,nombre,direccion,ciudad,listInO, grafoOficina))
										cout << "La oficina identificada con el codigo " << codOfi << " ha sido registrada exitosamente" << endl;
								else
										cout << "La oficina identificada con el codigo " << codOfi << " ya se encuentra registrada en el sistema" << endl;
						}
						else
						{
								cout << "Parametros invalidos" << endl;
						}
				}
				else if(strcmp(miLista[0],"conteoPaquetes")==0)
				{
						if (cantCmd==1)
						{
								contarPaquetes(listInO);
						}
						else
								cout << "Parametros invalidos" << endl;
				}
				else if(strcmp(miLista[0],"repartirPaquetes")==0)
				{
						if (cantCmd==2)
						{
								lineIn = miLista[1];
								distribuirPaquetes(lineIn,listInO,listInR);
						}
						else
								cout << "Parametros invalidos" << endl;
				}
				else if(strcmp(miLista[0],"ayuda")==0)
				{
						if (cantCmd==1)
						{
								cout << endl << "Comandos disponibles: " << endl << "   cargarPersonas" << endl << "   cargarPaquetes" << endl << "   cargarRegiones" << endl << "   cargarOficinas" << endl << "   registrarPersona" << endl << "   registrarPaquete" << endl << "   registrarOficina" << endl << "   registrarRegion" << endl << "   conteoPaquetes" << endl << "   repartirPaquetes" << endl << "   salir" << endl;
						}
						else if (cantCmd==2) {
								lineIn = miLista[1];
								if(lineIn=="cargarPersonas")
										cout << "===cargarPersonas <nombre_archivo>" << endl << "====Carga en memoria la información de las personas contenida en el archivo identificado por nombre_archivo" << endl;
								if(lineIn=="cargarPaquetes")
										cout << "===cargarPaquetes <nombre_archivo>" << endl << "====Carga en memoria la información de los paquetes contenida en el archivo identificado por nombre_archivo" << endl;
								if(lineIn=="cargarPaquetes")
										cout << "===cargarOficinas <nombre_archivo>" << endl << "====Carga en memoria la información de las oficinas contenida en el archivo identificado por nombre_archivo" << endl;
								if(lineIn=="cargarRegiones")
										cout << "===cargarRegiones <nombre_archivo>" << endl << "====Carga en memoria la información de las regiones contenida en el archivo identificado por nombre_archivo" << endl;
								if(lineIn=="registrarPersona")
										cout << "===registrarPersona" << endl << "====Permite insertar en el sistema la información asociada de una persona." << endl;
								if(lineIn=="registrarPaquete")
										cout << "===registrarPaquete" << endl << "====Permite insertar en el sistema un paquete a entregar con toda su información asociada" << endl;
								if(lineIn=="registrarOficina")
										cout << "===registrarOficina" << endl << "====Permite insertar en el sistema una oficina con toda su información asociada" << endl;
								if(lineIn=="registrarRegion")
										cout << "===registrarRegion" << endl << "====Permite insertar en el sistema una region con toda su información asociada" << endl;
								if(lineIn=="conteoPaquetes")
										cout << "===conteoPaquetes" << endl << "====Realiza el conteo de los paquetes registrados en que se encuentran pendientes por entregar" << endl;
								if(lineIn=="repartirPaquetes")
										cout << "===repartirPaquetes <codigo_oficina>" << endl << "====Utilizando la información de la jerarquía de oficinas, el comando distribuye los paquetes almacenados en las regiones de reparto de la oficina dada y los ubica en las oficinas respectivas, distribuyéndolos de forma equitativa en las regiones de reparto de las oficinas dependientes." << endl;
								if(lineIn=="salir")
										cout << "===salir" << endl << "====Termina la ejecucion de la aplicacion." << endl;
						}
				}
				else if(strcmp(miLista[0],"ayuda")==0)
				{
						if (cantCmd==1)
						{
								cout << endl << "Comandos disponibles: " << endl << "   cargarPersonas" << endl << "   cargarPaquetes" << endl << "   cargarRegiones" << endl << "   cargarOficinas" << endl << "   cargarConexiones" << endl << "   registrarPersona" << endl << "   registrarPaquete" << endl << "   registrarOficina" << endl << "   registrarRegion" << endl << "   conteoPaquetes" << endl << "   salir" << endl;
						}
						else if (cantCmd==2)
						{
								lineIn = miLista[1];
								if(lineIn=="cargarPersonas")
										cout << "===cargarPersonas <nombre_archivo>" << endl << "====Carga en memoria la información de las personas contenida en el archivo identificado por nombre_archivo" << endl;
								if(lineIn=="cargarPaquetes")
										cout << "===cargarPaquetes <nombre_archivo>" << endl << "====Carga en memoria la información de los paquetes contenida en el archivo identificado por nombre_archivo" << endl;
								if(lineIn=="cargarPaquetes")
										cout << "===cargarOficinas <nombre_archivo>" << endl << "====Carga en memoria la información de las oficinas contenida en el archivo identificado por nombre_archivo" << endl;
								if(lineIn=="cargarRegiones")
										cout << "===cargarRegiones <nombre_archivo>" << endl << "====Carga en memoria la información de las regiones contenida en el archivo identificado por nombre_archivo" << endl;
								if(lineIn=="cargarConexiones")
										cout << "===cargarConexiones <nombre_archivo>" << endl << "====Carga en memoria la información de las conexiones entre ciudades contenida en el archivo identificado por nombre_archivo" << endl;
								if(lineIn=="registrarPersona")
										cout << "===registrarPersona" << endl << "====Permite insertar en el sistema la información asociada de una persona." << endl;
								if(lineIn=="registrarPaquete")
										cout << "===registrarPaquete" << endl << "====Permite insertar en el sistema un paquete a entregar con toda su información asociada" << endl;
								if(lineIn=="registrarOficina")
										cout << "===registrarOficina" << endl << "====Permite insertar en el sistema una oficina con toda su información asociada" << endl;
								if(lineIn=="registrarRegion")
										cout << "===registrarRegion" << endl << "====Permite insertar en el sistema una region con toda su información asociada" << endl;
								if(lineIn=="conteoPaquetes")
										cout << "===conteoPaquetes" << endl << "====Realiza el conteo de los paquetes registrados en que se encuentran pendientes por entregar" << endl;
								if(lineIn=="salir")
										cout << "===salir" << endl << "====Termina la ejecucion de la aplicacion." << endl;
						}
				}
				else if(strcmp(miLista[0],"salir")==0)
						on = false;
				else
						cout << "*****Comando no valido****" << endl;
		}
		return 0;
}
bool cargarPersonas(string nombreArchivo, list<Persona*> &personasMemoria)
{
		string line;
		ifstream myfile(nombreArchivo.c_str());
		vector<string> vtoken;
		int res = 0;
		int exitos = 0;
		int fracasos = 0;
		if (myfile.is_open())
		{
				getline (myfile,line);
				int i = 0;
				while((myfile.peek()!=EOF))
				{
						getline (myfile,line);
						vtoken = tokenizador(line, ',');
						if(registrarPersona(vtoken[5], vtoken[4], vtoken[3], vtoken[2], vtoken[1], vtoken[0], personasMemoria))
						{
								exitos++;
								res = res;
						}
						else
						{
								res = 1;
								fracasos++;
						}
						i++;
				}
		}
		else
				return false;
		myfile.close();
		if(res==1)
		{
				cout << "Se encontraron datos repetidos, estos no fueron tenidos en cuenta" << endl;
		}
		if(exitos==0)
		{
				cout << "No se cargo ningun elemento" << endl;
				return false;
		}
		else if(exitos>0)
		{
				cout << "Se cargaron exitosamente " << exitos << " de " << fracasos + exitos << " elementos." << endl;
				return true;
		}
		return false;
}
bool cargarPaquetes(string nombreArchivo, list<Paquete*> &paquetesMemoria, list<Persona*> &personasMemoria,list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria)
{
		string line;
		ifstream myfile(nombreArchivo.c_str());
		vector<string> vtoken;
		int res = 0;
		int exitos = 0;
		int fracasos = 0;
		if (myfile.is_open())
		{
				getline (myfile,line);
				int i = 0;
				while((myfile.peek()!=EOF))
				{
						getline (myfile,line);
						vtoken = tokenizador(line, ',');
						if(registrarPaquete(vtoken[10],vtoken[9],vtoken[8],vtoken[7],vtoken[6],vtoken[5], vtoken[4], vtoken[3], vtoken[2], vtoken[1], vtoken[0], paquetesMemoria, personasMemoria, oficinasMemoria, regionesMemoria))
						{
								res = res;
								exitos++;
						}
						else
						{
								res = 1;
								fracasos++;
						}
						i++;
				}
		}
		else
		{
				return false;
		}
		myfile.close();
		if(exitos==0)
		{
				cout << "No se cargo ningun elemento" << endl;
				return false;
		}
		if(res==1)
		{
				cout << "Se encontraron datos repetidos, estos no fueron tenidos en cuenta" << endl;
		}
		else if(exitos>0)
		{
				cout << "Se cargaron exitosamente " << exitos << " de " << fracasos + exitos << " elementos." << endl;
				return true;
		}
		return false;
}
bool cargarOficinas(string nombreArchivo, list<Oficina*> &oficinasMemoria,Grafo<Oficina*> &grafo)
{
		string line;
		ifstream myfile(nombreArchivo.c_str());
		vector<string> vtoken;
		int res = 0;
		int exitos = 0;
		int fracasos = 0;
		if (myfile.is_open())
		{
				getline (myfile,line);
				int i = 0;
				while((myfile.peek()!=EOF))
				{
						getline (myfile,line);
						vtoken = tokenizador(line, ',');
						if(registrarOficina(vtoken[3],vtoken[2],vtoken[1],vtoken[0],oficinasMemoria,grafo))
								exitos++;
						else
								fracasos++;
				}
		}
		else
				return false;
		myfile.close();
		if(res==1)
		{
				cout << "Se encontraron datos repetidos, estos no fueron tenidos en cuenta" << endl;
		}
		if(exitos==0)
		{
				cout << "No se cargo ningun elemento" << endl;
				return false;
		}
		else if(exitos>0)
		{
				cout << "Se cargaron exitosamente " << exitos << " de " << fracasos + exitos << " elementos." << endl;
				return true;
		}
		return false;
}
bool cargarRegiones(string nombreArchivo, list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria,Grafo<Oficina*> &grafo)
{
		string line;
		ifstream myfile(nombreArchivo.c_str());
		vector<string> vtoken;
		int res = 0;
		int exitos = 0;
		int fracasos = 0;
		if (myfile.is_open())
		{
				getline (myfile,line);
				int i = 0;
				while((myfile.peek()!=EOF))
				{
						getline (myfile,line);
						vtoken = tokenizador(line, ',');
						if(registrarRegion(vtoken[3],vtoken[2],vtoken[1],oficinasMemoria,regionesMemoria,grafo,atof(vtoken[0].c_str())))
								exitos++;
						else
								fracasos++;
				}
		}
		else
				return false;
		myfile.close();
		cout << "Se cargaron exitosamente " << exitos << " de " << fracasos + exitos << " elementos." << endl;
		if(res==1)
				cout << "Se encontraron datos repetidos, estos no fueron tenidos en cuenta" << endl;
		return true;
}
bool cargarConexiones(string nombreArchivo, Grafo<Oficina*> &grafo,list<Oficina*> &oficinasMemoria)
{
		string line;
		ifstream myfile(nombreArchivo.c_str());
		vector<string> vtoken;
		int res = 0;
		int exitos = 0;
		int fracasos = 0;
		if (myfile.is_open())
		{
				getline (myfile,line);
				int i = 0;
				while((myfile.peek()!=EOF))
				{
						getline (myfile,line);
						vtoken = tokenizador(line, ',');
						if(buscarOficina(vtoken[2],oficinasMemoria) && buscarOficina(vtoken[1],oficinasMemoria))
						{
								grafo.insertarAristaNoDirigida(buscarOficina2(vtoken[2],oficinasMemoria),buscarOficina2(vtoken[1],oficinasMemoria), atof(vtoken[0].c_str()));
								exitos++;
								res = res;
						}
						else
						{
								res = 1;
								fracasos++;
						}
						i++;
				}
		}
		else
				return false;
		myfile.close();
		if(res==1)
		{
				cout << "Se encontraron datos repetidos, estos no fueron tenidos en cuenta" << endl;
		}
		if(exitos==0)
		{
				cout << "No se conecto ningun elemento" << endl;
				return false;
		}
		else if(exitos>0)
		{
				cout << "Se conecto exitosamente " << exitos << " de " << fracasos + exitos << " elementos." << endl;
				return true;
		}
		return false;
}
bool registrarPersona(string nombre, string apellido, string cedula, string direccion,
					  string ciudad, string telefono, list<Persona*> &personasMemoria)
{

		if(!buscarPersona(cedula, personasMemoria))
		{
				Persona* personaAux = new Persona();
				personaAux->setNombre(nombre);
				personaAux->setApellido(apellido);
				personaAux->setCedula(cedula);
				personaAux->setDireccion(direccion);
				personaAux->setCiudad(ciudad);
				personaAux->setTelefono(telefono);
				personasMemoria.push_back(personaAux);
				return true;
		}
		else
				return false;
}
bool registrarOficina(string codigo, string nombre, string direccion, string ciudad,
					  list<Oficina*> &oficinasMemoria, Grafo<Oficina*> &grafo)
{
		Oficina* oficinaAux = new Oficina();
		if(!buscarOficina(codigo, oficinasMemoria))
		{
				oficinaAux->setCodigo(codigo);
				oficinaAux->setNombre(nombre);
				oficinaAux->setDireccion(direccion);
				oficinaAux->setCiudad(ciudad);
				oficinaAux->setPrincipal(false);
				oficinasMemoria.push_back(oficinaAux);
				grafo.insertarVertice(oficinaAux);
				return true;
		}
		return false;
}
bool registrarRegion(string codigo, string nombre, string codigoOficinaPadre,
					 list<Oficina*> &oficinasMemoria,list<Region*> &regionesMemoria,
					 Grafo<Oficina*> &grafo,double distanciaOficinaPadre)
{
		Region* regionAux = new Region();
		Oficina* oficinaAuxOrigen;
		Oficina* oficinaAuxDestino;
		if(buscarOficina(codigoOficinaPadre,oficinasMemoria))
		{
				if(!buscarRegion(codigo,regionesMemoria))
				{
						regionAux->setCodigo(codigo);
						regionAux->setNombre(nombre);
						oficinaAuxOrigen = buscarOficina2(codigoOficinaPadre,oficinasMemoria);
						registrarOficina(codigo, nombre, oficinaAuxOrigen->getDireccion(),oficinaAuxOrigen->getCiudad(),oficinasMemoria, grafo);
						oficinaAuxDestino = buscarOficina2(codigo,oficinasMemoria);
						grafo.insertarVertice(oficinaAuxDestino);
						regionAux->setOficinaDirecta(oficinaAuxDestino);
						regionesMemoria.push_back(regionAux);
						oficinaAuxDestino->getListaRegiones().push_back(regionAux);
						oficinaAuxOrigen->getListaRegiones().push_back(regionAux);
						grafo.insertarAristaNoDirigida(oficinaAuxOrigen,oficinaAuxDestino,distanciaOficinaPadre);
						return true;
				}
				else
						return false;
		}
		return false;
}
bool registrarPaquete(string cedulaRemitenteIn, string cedulaDestinatarioIn, string pesoIn, string tipoContenidoIn, string numGuiaIn,
					  string codigoOficinaIn, string nombreOficinaIn, string direccionOficinaIn
					  ,string ciudadOficinaIn, string codigoRegionIn,string nombreRegionIn,
					  list<Paquete*> &paquetesMemoria, list<Persona*> &personasMemoria, list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria)
{
		Paquete* paqueteAux = new Paquete();
		Region* auxR = new Region();
		Oficina* oAux = new Oficina();
		if(!buscarPaquete(numGuiaIn, paquetesMemoria))
		{
				if(buscarOficina(codigoOficinaIn, oficinasMemoria))
				{
						oAux = buscarOficina2(codigoOficinaIn, oficinasMemoria);
						if(buscarRegion(codigoRegionIn,oAux->getListaRegiones()))
						{
								paqueteAux->setRemitente(buscarPersona2(cedulaRemitenteIn, personasMemoria));
								paqueteAux->setDestinatario(buscarPersona2(cedulaDestinatarioIn, personasMemoria));
								paqueteAux->setPeso(stoi(pesoIn));
								paqueteAux->setNumGuia(numGuiaIn);
								paqueteAux->setRegionDestino(codigoRegionIn);
								paquetesMemoria.push_back(paqueteAux);
								buscarRegion2(codigoOficinaIn,buscarOficina2(codigoOficinaIn, oficinasMemoria)->getListaRegiones())->getListaPaquetes().push_back(paqueteAux);
								buscarOficina2(codigoOficinaIn, oficinasMemoria)->getListaPaquetes().push_back(paqueteAux);
								return true;
						}
				}
		}
		return false;
}
bool registrarPaquete2(string cedulaRemitenteIn, string cedulaDestinatarioIn, string pesoIn,
					   string tipoContenidoIn, string numGuiaIn,string codigoOficinaIn,string codigoRegionIn,
					   list<Paquete*> &paquetesMemoria, list<Persona*> &personasMemoria,list<Oficina*> &oficinasMemoria)
{
		Paquete* paqueteAux = new Paquete();
		Oficina* oAux = new Oficina();
		if(!buscarPaquete(numGuiaIn, paquetesMemoria))
		{
				if(buscarOficina(codigoOficinaIn, oficinasMemoria))
				{
						oAux = buscarOficina2(codigoOficinaIn, oficinasMemoria);
						paqueteAux->setRemitente(buscarPersona2(cedulaRemitenteIn, personasMemoria));
						paqueteAux->setDestinatario(buscarPersona2(cedulaDestinatarioIn, personasMemoria));
						paqueteAux->setPeso(stoi(pesoIn));
						paqueteAux->setNumGuia(numGuiaIn);
						paqueteAux->setRegionDestino(codigoRegionIn);
						paquetesMemoria.push_back(paqueteAux);
						buscarOficina2(codigoOficinaIn, oficinasMemoria)->getListaPaquetes().push_back(paqueteAux);
						return true;
				}
		}
		return false;
}
void contarPaquetes(list<Oficina*> &oficinasMemoria)
{

		int suma = 0, acum = 0;
		if(oficinasMemoria.size()==0)
		{
				cout << "No hay ninguna oficina registrada en el sistema" << endl;
		}
		else
		{
				cout << "==========================================" << endl;
				for (list<Oficina*>::iterator itB = oficinasMemoria.begin(); itB != oficinasMemoria.end(); ++itB)
				{
						if((*itB)->getPrincipal())
						{
								cout << (*itB)->getListaPaquetes().size() << " paquetes en la oficina " << (*itB)->getCodigo() << ", Oficina principal" << endl;
								suma += (*itB)->getListaPaquetes().size();
								cout << "------------------------------------------" << endl;
						}
						for (list<Region*>::iterator itC = (*itB)->getListaRegiones().begin(); itC != (*itB)->getListaRegiones().end(); ++itC)
						{
								if ((*itB)->getNombre()==(*itC)->getNombre())
								{
										cout << (*itC)->getListaPaquetes().size() << " paquetes en la oficina " << (*itB)->getCodigo() << ", region de reparto " << (*itC)->getNombre() << endl;
										suma += (*itC)->getListaPaquetes().size();
										cout << "------------------------------------------" << endl;
								}
						}
						acum += suma;
						suma = 0;
				}
				cout << "==========================================" << endl;
				cout << "Total paquetes en el sistema: " << acum << endl;
		}
}
void encontrarPrincipal(list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria)
{
		bool tieneRegion = false;
		for (list<Oficina*>::iterator itB = oficinasMemoria.begin(); itB != oficinasMemoria.end(); ++itB)
		{
				tieneRegion = false;
				for (list<Region*>::iterator itC = regionesMemoria.begin(); itC != regionesMemoria.end(); ++itC)
				{
						if((*itB)->getCodigo()==(*itC)->getCodigo())
						{
								tieneRegion = true;
						}
				}
				if(!tieneRegion)
				{
						(*itB)->setPrincipal(true);
				}
		}
}
bool buscarPersona(string cedulaIn, list<Persona*> &personasMemoria)
{
		for (list<Persona*>::iterator itB = personasMemoria.begin(); itB != personasMemoria.end(); ++itB)
		{
				if((*itB)->getCedula() == cedulaIn)
				{
						return true;
				}
		}
		return false;
}
Persona* buscarPersona2(string cedulaIn, list<Persona*> &personasMemoria)
{
		Persona* personaOu = new Persona();
		for (list<Persona*>::iterator itB = personasMemoria.begin(); itB != personasMemoria.end(); ++itB)
		{
				if((*itB)->getCedula() == cedulaIn)
				{
						return (*itB);
				}
		}
		return personaOu;
}
bool buscarOficina(string codigo, list<Oficina*> &oficinasMemoria)
{
		for (list<Oficina*>::iterator itB = oficinasMemoria.begin(); itB != oficinasMemoria.end(); ++itB)
		{
				if((*itB)->getCodigo() == codigo)
				{
						return true;
				}
		}
		return false;
}
bool buscarRegion(string codigo, list<Region*> &regionesMemoria)
{
		for (list<Region*>::iterator itB = regionesMemoria.begin(); itB != regionesMemoria.end(); ++itB)
		{
				if((*itB)->getCodigo() == codigo)
				{
						return true;
				}
		}
		return false;
}
Oficina* buscarOficina2(string codigo, list<Oficina*> &oficinasMemoria)
{
		Oficina* o = new Oficina();
		for (list<Oficina*>::iterator itB = oficinasMemoria.begin(); itB != oficinasMemoria.end(); ++itB)
		{
				if((*itB)->getCodigo() == codigo)
						return (*itB);
		}
		return o;
}
Region* buscarRegion2(string codigo, list<Region*> &regionesMemoria)
{
		Region* r = new Region();
		for (list<Region*>::iterator itB = regionesMemoria.begin(); itB != regionesMemoria.end(); ++itB)
		{
				if((*itB)->getCodigo() == codigo)
						return (*itB);
		}
		return r;
}
bool buscarPaquete(string numGuiaIn, list<Paquete*> &paquetesMemoria)
{
		if(paquetesMemoria.size()==0)
				return false;
		for (list<Paquete*>::iterator itB = paquetesMemoria.begin(); itB != paquetesMemoria.end(); ++itB)
		{
				if((*itB)->getNumGuia() == numGuiaIn)
				{
						return true;
				}
		}
		return false;
}
void imprimirOficinasYReguiones(list<Oficina*> &oficinasMemoria,list<Region*> &regionesMemoria)
{
		for (list<Oficina*>::iterator itB = oficinasMemoria.begin(); itB != oficinasMemoria.end(); ++itB)
		{
				cout << "La oficina " << (*itB)->getNombre() << " con influencia en las regiones: " << endl;
				for (list<Region*>::iterator itC = (*itB)->getListaRegiones().begin(); itC != (*itB)->getListaRegiones().end(); ++itC)
				{
						cout << (*itC)->getNombre() << " con " << (*itC)->getListaPaquetes().size() << " paquetes." << endl;
				}
				cout << "--------------" << endl;
		}
}
void imprimirRegiones(list<Region*> &regionesMemoria)
{
		for (list<Region*>::iterator itB = regionesMemoria.begin(); itB != regionesMemoria.end(); ++itB)
				cout << "Region: " << (*itB)->getNombre() << " Codigo: " << (*itB)->getCodigo() << endl;
}
void imprimirOficinas(list<Oficina*> &oficinasMemoria)
{
		for (list<Oficina*>::iterator itB = oficinasMemoria.begin(); itB != oficinasMemoria.end(); ++itB)
		{
				cout << "Oficina: " << (*itB)->getNombre() << " Codigo: " << (*itB)->getCodigo();
				if((*itB)->getPrincipal())
						cout << " Oficina principal" << endl;
				else
						cout << endl;
		}
}
void imprimirRegionesXoficina(list<Oficina*> &oficinasMemoria)
{
		for (list<Oficina*>::iterator itO = oficinasMemoria.begin(); itO != oficinasMemoria.end(); ++itO)
				cout << "oficina " << (*itO)->getNombre() << " y su region " << (*itO)->getListaRegiones().front()->getNombre() << endl;
}
void imprimirPaquetesXRegion2(list<Oficina*> &oficinasMemoria)
{
		for (list<Oficina*>::iterator itO = oficinasMemoria.begin(); itO != oficinasMemoria.end(); ++itO)
		{
				cout << (*itO)->getNombre() << " con " << (*itO)->getListaRegiones().size() << " regiones y su region cabeza" << (*itO)->getListaRegiones().front()->getNombre()
					 << " y sus paquetes " << "n = " << (*itO)->getListaRegiones().front()->getListaPaquetes().size() <<
				(*itO)->getListaRegiones().front()->getListaPaquetes().front()->getRemitente()->getNombre() << endl;
		}
}
vector<string> tokenizador(string stringIn, char token)
{
		vector<string> listOut;
		string aux;
		int i = 0;
		while( i <= stringIn.size())
		{
				if(stringIn[i] == token)
				{
						i++;
						listOut.insert(listOut.begin(), aux );
						aux.clear();
				}
				aux += stringIn[i];
				i++;
		}
		aux.resize(aux.size() - 1);
		listOut.insert(listOut.begin(), aux );
		return listOut;
}
int contarPaquetesXRegion(list<Region*> &regionesMemoria)
{
		int cantidad = 0;
		if(!regionesMemoria.empty()) {
				for (list<Region*>::iterator itB = regionesMemoria.begin(); itB != regionesMemoria.end(); ++itB)
				{
						cantidad = cantidad + (*itB)->getListaPaquetes().size() + contarPaquetesXRegion((*itB)->getOficinaDirecta()->getListaRegiones());
				}
		}
		return cantidad;
}
void distribuirPaquetes(string codigoOficina,list<Oficina*> &oficinasMemoria,list<Region*> &regionesMemoria)
{
		int cant_paquetes = 0, cant_oficinas = 0;
		if(buscarOficina(codigoOficina,oficinasMemoria))
		{
				while(!buscarOficina2(codigoOficina,oficinasMemoria)->getListaPaquetes().empty())
				{
						for (list<Region*>::iterator itB = buscarOficina2(codigoOficina,oficinasMemoria)->getListaRegiones().begin(); itB != buscarOficina2(codigoOficina,oficinasMemoria)->getListaRegiones().end(); ++itB)
						{
								if(!buscarOficina2(codigoOficina,oficinasMemoria)->getListaPaquetes().empty()&&((*itB)->getCodigo()==(buscarOficina2(codigoOficina,oficinasMemoria)->getListaPaquetes().back()->getRegionDestino())))
								{
										(*itB)->getOficinaDirecta()->getListaPaquetes().push_back(buscarOficina2(codigoOficina,oficinasMemoria)->getListaPaquetes().back());
										buscarOficina2(codigoOficina,oficinasMemoria)->getListaPaquetes().pop_back();
										cant_paquetes++;
								}
								if(!buscarRegion2(codigoOficina,regionesMemoria)->getListaPaquetes().empty()&&((*itB)->getCodigo()==(buscarRegion2(codigoOficina,regionesMemoria)->getListaPaquetes().back()->getRegionDestino())))
								{
										(*itB)->getListaPaquetes().push_back(buscarOficina2(codigoOficina,oficinasMemoria)->getListaPaquetes().back());
										buscarRegion2(codigoOficina,regionesMemoria)->getListaPaquetes().pop_back();
										cant_oficinas++;
								}
						}
				}
				if(cant_oficinas!=0&&cant_paquetes!=0)
						cout << "Se han repartido exitosamente " << cant_paquetes << " paquetes en " << cant_oficinas << " oficinas de las regiones de reparto de la oficina " << codigoOficina << endl;
				else
						cout << "La oficina " << codigoOficina << " no tiene regiones de reparto asociadas" << endl;
		}
}
void rutaMasCorta(string oficinaOrigen, string oficinaDestino,  Grafo<Oficina*> &grafo,list<Oficina*> &oficinasMemoria)
{
		double distancia[grafo.tam()];
		bool visto[grafo.tam()];
		list<NodoGrafo<Oficina*>*> listaAux = grafo.getVertices();
		NodoGrafo<Oficina*>* verticeOficinaNodo;
		list<par> listaVecinosVerticeOficinaNodo;
		int i = 0;
		for(list<NodoGrafo<Oficina*>*>::iterator it = listaAux.begin(); it != listaAux.end(); ++it ) {
				if(!siConecta(oficinaOrigen,(*it)->getDato()->getCodigo(),grafo, oficinasMemoria)) {

						distancia[i] = 60000;

				}else{
						distancia[i] = buscarVertice2( oficinaOrigen,grafo)->getPesoVecino((*it)->getDato());
				}
				i++;
		}
		i = 0;
		for(list<NodoGrafo<Oficina*>*>::iterator it = listaAux.begin(); it != listaAux.end(); ++it) {
				if((*it)->getDato()->getCodigo() == oficinaOrigen) {
						distancia[i] = 0;
						visto[i] = true;
				}else{
						visto[i] = false;
				}
				i++;
		}
		for(int j = 0; j < grafo.tam(); j++)
				cout << distancia[j] << " " << endl;
		i = 0;
		int vertice = 0;
		while(!vistosTodos(visto, grafo.tam()))
		{
				for( i = 0; i < grafo.tam(); i++)
				{
						if(!visto[i])
						{
								vertice = minimo(distancia, grafo.tam());
								visto[vertice] = true;
								break;
						}
				}
				i = 0;
				verticeOficinaNodo = buscarVertice(vertice, grafo);
				listaVecinosVerticeOficinaNodo = verticeOficinaNodo->getVecinos();
				for(list<par>::iterator it = listaVecinosVerticeOficinaNodo.begin(); it != listaVecinosVerticeOficinaNodo.end(); ++it)
				{
						verticeOficinaNodo->getPesoVecino((*it).first->getDato());
						if((*it).first != NULL )
						{
								if(distancia[sacarIndice((*it).first->getDato()->getCodigo(),grafo)] > (distancia[vertice] +
																										verticeOficinaNodo->getPesoVecino((*it).first->getDato()))) {

										distancia[sacarIndice((*it).first->getDato()->getCodigo(),grafo)] = distancia[vertice] +
																											verticeOficinaNodo->getPesoVecino((*it).first->getDato());
								}
						}
						i++;

				}
		}
}
bool siConecta(string oficinaOrigen, string oficinaDestino, Grafo<Oficina*> &grafo,list<Oficina*> &oficinasMemoria)
{
		return grafo.existeVertice(buscarOficina2(oficinaOrigen,oficinasMemoria))->buscarVecino2(buscarOficina2(oficinaDestino,oficinasMemoria));
}
bool vistosTodos(bool vistos[], int cantidad)
{
		int cuenta = 0;
		for(int i = 0; i< cantidad; i++)
		{
				if(vistos[i])
						cuenta++;
		}
		if(cuenta == cantidad)
				return true;
		else return false;
}
int minimo(double distancia[], int cantidad)
{
		double minimo = 60999;
		int salida = 0;
		for(int i = 0; i< cantidad; i++)
		{
				if(distancia[i] <= minimo && distancia[i] != -1)
				{
						minimo =  distancia[i];
						salida = i;
				}
		}
		return salida;
}
NodoGrafo<Oficina*>* buscarVertice( int vertice,Grafo<Oficina*> &grafo)
{
		list<NodoGrafo<Oficina*>*> listaAux = grafo.getVertices();
		int i = 0;
		for(list<NodoGrafo<Oficina*>*>::iterator it = listaAux.begin(); it != listaAux.end(); ++it ) {
				if(i == vertice)
						return (*it);
		}
		return nullptr;
}
NodoGrafo<Oficina*>* buscarVertice2( string codigoOficina,Grafo<Oficina*> &grafo)
{
		list<NodoGrafo<Oficina*>*> listaAux = grafo.getVertices();
		int i = 0;
		for(list<NodoGrafo<Oficina*>*>::iterator it = listaAux.begin(); it != listaAux.end(); ++it) {
				if((*it)->getDato()->getCodigo() ==  codigoOficina)
						return (*it);
				i++;
		}
		return nullptr;
}
int sacarIndice(string codigoOficina,Grafo<Oficina*> &grafo)
{
		list<NodoGrafo<Oficina*>*> lista = grafo.getVertices();
		int i = 0;
		for(list<NodoGrafo<Oficina*>*>::iterator it = lista.begin(); it != lista.end(); ++it)
		{
				if((*it)->getDato()->getCodigo() ==  codigoOficina)
						return i;
				i++;
		}
		return -1;
}
