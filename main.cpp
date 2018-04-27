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

using namespace std;

bool cargarPersonas(string nombreArchivo, list<Persona*> &personasMemoria);
vector<string> tokenizador(string stringIn, char token);
bool buscarPersona(string cedulaIn, list<Persona*> &personasMemoria);
bool registrarPersona(string nombre, string apellido, string cedula, string direccion, string ciudad, string telefono, list<Persona*> &personasMemoria);
bool cargarPaquetes(string nombreArchivo, list<Paquete*> &paquetesMemoria,  list<Persona*> &personasMemoria,list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria);
bool cargarOficinas(string nombreArchivo, list<Oficina*> &oficinasMemoria);
bool cargarRegiones(string nombreArchivo, list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria);
bool registrarPaquete(string cedulaRemitenteIn, string cedulaDestinatarioIn, string pesoIn, string tipoContenidoIn, string numGuiaIn,
																						string codigoOficinaIn, string nombreOficinaIn, string direccionOficinaIn
																						,string ciudadOficinaIn, string codigoRegionIn, string nombreRegionstringIn,
																						list<Paquete*> &paquetesMemoria, list<Persona*> &personasMemoria,list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria);
bool registrarOficina(string codigo, string nombre, string direccion, string ciudad,list<Oficina*> &oficinasMemoria);
bool registrarRegion(string codigo, string nombre, string codigoOficinaPadre,list<Oficina*> &oficinasMemoria,list<Region*> &regionesMemoria);
bool registrarPaqueteUnico(string cedulaRemitenteIn, string cedulaDestinatarioIn, string pesoIn, string tipoContenidoIn, string numGuiaIn,list<Paquete*> &paquetesMemoria, list<Persona*> &personasMemoria);
bool buscarPaquete(string numGuiaIn, list<Paquete*> &paquetesMemoria);
Persona* buscarPersona2(string cedulaIn, list<Persona*> &personasMemoria);
bool buscarOficina(string codigo, list<Oficina*> &oficinasMemoria);
bool buscarRegion(string codigo, list<Region*> &regionesMemoria);
Oficina* buscarOficina2(string codigo, list<Oficina*> &oficinasMemoria);
Region* buscarRegion2(string codigo, list<Region*> &regionesMemoria);
void imprimirRegiones(list<Region*> &regionesMemoria);
void imprimirOficinas(list<Oficina*> &oficinasMemoria);
void imprimirPaquetesXRegion2(list<Oficina*> &oficinasMemoria);
void imprimirPaquetesXRegion(list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria, list<Paquete*> &paquetesMemoria);
vector<string> tokenizador2(string stringIn, char token);
void contarPaquetes(list<Oficina*> &oficinasMemoria);
int contarPaquetesXRegion(list<Region*> &regionesMemoria);
void imprimirOficinasYReguiones(list<Oficina*> &oficinasMemoria,list<Region*> &regionesMemoria);

int main()
{
								bool on = true;
								bool encontrado=false;
								string lineIn=" ";
								char comando[300]={' '};
								list<Persona*> listIn;
								list<Paquete*> listInP;
								list<Oficina*> listInO;
								list<Region*> listInR;
								while(on)
								{
																cout<<"$ ";
																cin.getline(comando,300);
																char* pch;
																char* miLista[10];
																int cantCmd=0;
																pch = strtok (comando," ");
																while (pch != NULL)
																{
																								miLista[cantCmd]=pch;
																								cantCmd++;
																								pch = strtok (NULL, " ");
																}
																if (strcmp(miLista[0],"cargarPersonas")==0)
																{
																								if (cantCmd==2)
																								{
																																lineIn=miLista[1];
																																if(cargarPersonas(lineIn,listIn))
																																{
																																								cout<<"La información desde el archivo "<<lineIn<<" ha sido cargada exitosamente"<<endl;
																																}
																																else
																																{
																																								cout<<"El archivo "<<lineIn<<" no existe o contiene información inválida"<<endl;
																																}
																								}
																								else
																								{
																																cout<< "Parametros invalidos"<<endl;
																								}
																}
																else if(strcmp(miLista[0],"cargarPaquetes")==0)
																{
																								if (cantCmd==2)
																								{
																																lineIn=miLista[1];
																																if(cargarPaquetes(lineIn,listInP, listIn, listInO, listInR))
																																{
																																								cout<<"La información desde el archivo "<<lineIn<<" ha sido cargada exitosamente"<<endl;
																																}
																																else
																																{
																																								cout<<"El archivo "<<lineIn<<" no existe o contiene información inválida"<<endl;
																																}
																								}
																								else
																								{
																																cout<< "Parametros invalidos"<<endl;
																								}
																}
																else if(strcmp(miLista[0],"cargarRegiones")==0)
																{
																								if (cantCmd==2)
																								{
																																lineIn=miLista[1];
																																if(cargarRegiones(lineIn,listInO,listInR))                                                                                                                                                                                                                                                //cargarRegiones())
																																{
																																								cout<<"La información desde el archivo "<<lineIn<<" ha sido cargada exitosamente"<<endl;
																																}
																																else
																																{
																																								cout<<"El archivo "<<lineIn<<" no existe o contiene información inválida"<<endl;
																																}
																								}
																								else
																								{
																																cout<< "Parametros invalidos"<<endl;
																								}
																}
																else if(strcmp(miLista[0],"cargarOficinas")==0)
																{
																								if (cantCmd==2)
																								{
																																lineIn=miLista[1];
																																if(cargarOficinas(lineIn,listInO))                                                                                                                                                                                                                                                //cargarOficinas())
																																{
																																								cout<<"La información desde el archivo "<<lineIn<<" ha sido cargada exitosamente"<<endl;
																																}
																																else
																																{
																																								cout<<"El archivo "<<lineIn<<" no existe o contiene información inválida"<<endl;
																																}
																								}
																								else
																								{
																																cout<< "Parametros invalidos"<<endl;
																								}
																}

																else if(strcmp(miLista[0],"registrarPersona")==0)
																{

																								if (cantCmd==1)
																								{
																																string nombre,apellido,cedula,direccion,ciudad,telefono;
																																cout<<"Nombre: ";
																																cin>>nombre;
																																cout<<"Apellido: ";
																																cin>>apellido;
																																cout<<"Cedula: ";
																																cin>>cedula;
																																cout<<"Direccion: ";
																																cin>>direccion;
																																cout<<"Telefono: ";
																																cin>>telefono;
																																if(registrarPersona(nombre,apellido,cedula,direccion,ciudad,telefono,listIn))
																																								cout<<"La persona con identificación "<<cedula<<" ha sido registrado exitosamente"<<endl;
																																else
																																								cout<<"La persona con identificación "<<cedula<<" ya se encuntra registrada en el sistema"<<endl;
																								}
																								else
																								{
																																cout<< "Parametros invalidos"<<endl;
																								}
																}
																else if(strcmp(miLista[0],"registrarPaquete")==0)
																{
																								if (cantCmd==1)
																								{
																																string cedulaRemitente,cedulaDestinatario,peso,tipoContenido,numGuia;
																																cout<<"Cedula remitente: ";
																																cin>>cedulaRemitente;
																																cout<<"Cedula destinatario: ";
																																cin>>cedulaDestinatario;
																																cout<<"Peso: ";
																																cin>>peso;
																																cout<<"Tipo de contenido: ";
																																cin>>tipoContenido;
																																cout<<"Numero de guia: ";
																																cin>>numGuia;
																																if(registrarPaqueteUnico(cedulaRemitente,cedulaDestinatario,peso,tipoContenido,numGuia,listInP,listIn))
																																								cout<<"El paquete con numero de guia "<<numGuia<<" ha sido registrado exitosamente"<<endl;
																																else
																																								cout<<"El paquete con numero de guia "<<numGuia<<" ya se encuentra registrado en el sistema"<<endl;
																								}
																								else
																								{
																																cout<< "Parametros invalidos"<<endl;
																								}
																}
																else if(strcmp(miLista[0],"registrarRegion")==0)
																{
																								if (cantCmd==1)
																								{
																																string codReg, nombre, codigoOficinaPadre;
																																cout<<"Codigo de la region: ";
																																cin>>codReg;
																																cout<<"Nombre de la region: ";
																																cin>>nombre;
																																cout<<"Codigo oficina: ";
																																cin>>codigoOficinaPadre;
																																if(registrarRegion(codReg, nombre, codigoOficinaPadre,listInO,listInR))
																																								cout<<"La region identificada con el codigo "<<codReg<<" ha sido registrada exitosamente"<<endl;
																																else
																																								cout<<"La region identificada con el codigo "<<codReg<<" ya se encuentra registrado en el sistema"<<endl;
																								}
																								else
																								{
																																cout<< "Parametros invalidos"<<endl;
																								}
																}
																else if(strcmp(miLista[0],"registrarOficina")==0)
																{
																								if (cantCmd==1)
																								{
																																string codOfi,nombre,direccion,ciudad;
																																cout<<"Codigo oficina: ";
																																cin>>codOfi;
																																cout<<"Nombre oficina: ";
																																cin>>nombre;
																																cout<<"Direccion: ";
																																cin>>direccion;
																																cout<<"Ciudad: ";
																																cin>>ciudad;
																																if(registrarOficina(codOfi,nombre,direccion,ciudad,listInO))
																																								cout<<"La oficina identificada con el codigo "<<codOfi<<" ha sido registrada exitosamente"<<endl;
																																else
																																								cout<<"La oficina identificada con el codigo "<<codOfi<<" ya se encuentra registrada en el sistema"<<endl;
																								}
																								else
																								{
																																cout<< "Parametros invalidos"<<endl;
																								}
																}
																else if(strcmp(miLista[0],"conteoPaquetes")==0)
																{
																								if (cantCmd==1)
																								{
																																imprimirPaquetesXRegion(listInO,listInR,listInP);
																								}
																								else
																																cout<< "Parametros invalidos"<<endl;
																}
																else if(strcmp(miLista[0],"ayuda")==0)
																{
																								if (cantCmd==1)
																								{
																																cout<<endl<<"Comandos disponibles: "<<endl<<"   cargarPersonas"<<endl<<"   cargarPaquetes"<<endl<<"   cargarRegiones"<<endl<<"   cargarOficinas"<<endl<<"   registrarPersona"<<endl<<"   registrarPaquete"<<endl<<"   registrarOficina"<<endl<<"   registrarRegion"<<endl<<"   conteoPaquetes"<<endl<<"   salir"<<endl;
																								}
																								else if (cantCmd==2) {
																																lineIn=miLista[1];
																																if(lineIn=="cargarPersonas")
																																								cout<<"===cargarPersonas <nombre_archivo>"<<endl<<"====Carga en memoria la información de las personas contenida en el archivo identificado por nombre_archivo"<<endl;
																																if(lineIn=="cargarPaquetes")
																																								cout<<"===cargarPaquetes <nombre_archivo>"<<endl<<"====Carga en memoria la información de los paquetes contenida en el archivo identificado por nombre_archivo"<<endl;
																																if(lineIn=="cargarPaquetes")
																																								cout<<"===cargarOficinas <nombre_archivo>"<<endl<<"====Carga en memoria la información de las oficinas contenida en el archivo identificado por nombre_archivo"<<endl;
																																if(lineIn=="cargarRegiones")
																																								cout<<"===cargarRegiones <nombre_archivo>"<<endl<<"====Carga en memoria la información de las regiones contenida en el archivo identificado por nombre_archivo"<<endl;
																																if(lineIn=="registrarPersona")
																																								cout<<"===registrarPersona"<<endl<<"====Permite insertar en el sistema la información asociada de una persona."<<endl;
																																if(lineIn=="registrarPaquete")
																																								cout<<"===registrarPaquete"<<endl<<"====Permite insertar en el sistema un paquete a entregar con toda su información asociada"<<endl;
																																if(lineIn=="registrarOficina")
																																								cout<<"===registrarOficina"<<endl<<"====Permite insertar en el sistema una oficina con toda su información asociada"<<endl;
																																if(lineIn=="registrarRegion")
																																								cout<<"===registrarRegion"<<endl<<"====Permite insertar en el sistema una region con toda su información asociada"<<endl;
																																if(lineIn=="conteoPaquetes")
																																								cout<<"===conteoPaquetes"<<endl<<"====Realiza el conteo de los paquetes registrados en que se encuentran pendientes por entregar"<<endl;
																																if(lineIn=="salir")
																																								cout<<"===salir"<<endl<<"====Termina la ejecucion de la aplicacion."<<endl;
																								}
																}
																else if(strcmp(miLista[0],"salir")==0)
																								on = false;
																else
																								cout<<"===Comando no valido"<<endl;
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
																								vtoken = tokenizador2(line, ',');
																								if(registrarPersona(vtoken[5], vtoken[4], vtoken[3], vtoken[2], vtoken[1], vtoken[0], personasMemoria))
																								{
																																exitos++;
																																res=res;
																								}
																								else
																								{
																																res= 1;
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
																cout<<"Se encontraron datos repetidos, estos no fueron tenidos en cuenta"<<endl;
								}
								if(exitos==0)
								{
																cout<<"No se cargo ningun elemento"<<endl;
																return false;
								}
								else if(exitos>0)
								{
																cout<<"Se cargaron exitosamente "<<exitos<<" de "<<fracasos + exitos<<" elementos."<<endl;
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
																								vtoken = tokenizador2(line, ',');
																								if(registrarPaquete(vtoken[10],vtoken[9],vtoken[8],vtoken[7],vtoken[6],vtoken[5], vtoken[4], vtoken[3], vtoken[2], vtoken[1], vtoken[0], paquetesMemoria, personasMemoria, oficinasMemoria, regionesMemoria))
																								{
																																res=res;
																																exitos++;
																								}
																								else
																								{
																																res=1;
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
																cout<<"No se cargo ningun elemento"<<endl;
																return false;
								}
								if(res==1)
								{
																cout<<"Se encontraron datos repetidos, estos no fueron tenidos en cuenta"<<endl;
								}
								else if(exitos>0)
								{
																cout<<"Se cargaron exitosamente "<<exitos<<" de "<<fracasos + exitos<<" elementos."<<endl;
																return true;
								}
								return false;
}
vector<string> tokenizador(string stringIn, char token)
{
								vector<string> listOut;
								string aux;
								int i = 1;
								while( i <= stringIn.size())
								{
																if(stringIn[i] == token)
																{
																								i++;
																								listOut.insert(listOut.begin(), aux );
																								aux.clear();
																								i++;
																								i++;
																}
																if(i <= stringIn.size())
																{
																								aux += stringIn[i];
																}
																i++;
								}
								return listOut;
}
vector<string> tokenizador2(string stringIn, char token)
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
								aux.resize(aux.size()-1);
								listOut.insert(listOut.begin(), aux );
								return listOut;
}

bool registrarPersona(string nombre, string apellido, string cedula, string direccion, string ciudad, string telefono, list<Persona*> &personasMemoria)
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
																personasMemoria.push_front(personaAux);
																return true;
								}
								else
																return false;
}
bool buscarPersona(string cedulaIn, list<Persona*> &personasMemoria)
{
								for (list<Persona*>::iterator itB=personasMemoria.begin(); itB != personasMemoria.end(); ++itB)
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
								for (list<Persona*>::iterator itB=personasMemoria.begin(); itB != personasMemoria.end(); ++itB)
								{
																if((*itB)->getCedula() == cedulaIn)
																{
																								return (*itB);
																}
								}
								return personaOu;
}
bool registrarPaquete(string cedulaRemitenteIn, string cedulaDestinatarioIn, string pesoIn, string tipoContenidoIn, string numGuiaIn,
																						string codigoOficinaIn, string nombreOficinaIn, string direccionOficinaIn
																						,string ciudadOficinaIn, string codigoRegionIn,string nombreRegionstringIn,
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
																																paquetesMemoria.insert(paquetesMemoria.begin(), paqueteAux);
																																buscarRegion2(codigoRegionIn,buscarOficina2(codigoOficinaIn, oficinasMemoria)->getListaRegiones())->getListaPaquetes().push_back(paqueteAux);
																																return true;
																								}
																}
								}
								return false;
}
bool registrarPaqueteUnico(string cedulaRemitenteIn, string cedulaDestinatarioIn, string pesoIn, string tipoContenidoIn, string numGuiaIn,list<Paquete*> &paquetesMemoria, list<Persona*> &personasMemoria)
{
								Paquete* paqueteAux;
								if(!buscarPaquete(numGuiaIn, paquetesMemoria))
								{
																paqueteAux->setRemitente(buscarPersona2(cedulaRemitenteIn, personasMemoria));
																paqueteAux->setDestinatario(buscarPersona2(cedulaDestinatarioIn, personasMemoria));
																paqueteAux->setPeso(1);
																paqueteAux->setNumGuia(numGuiaIn);
																paquetesMemoria.insert(paquetesMemoria.begin(), paqueteAux);
																return true;
								}
								else
								{
																return false;
								}
}
bool buscarPaquete(string numGuiaIn, list<Paquete*> &paquetesMemoria)
{
								for (list<Paquete*>::iterator itB=paquetesMemoria.begin(); itB != paquetesMemoria.end(); ++itB)
								{
																if((*itB)->getNumGuia() == numGuiaIn)
																{
																								return true;
																}
								}
								return false;
}
bool buscarOficina(string codigo, list<Oficina*> &oficinasMemoria)
{
								for (list<Oficina*>::iterator itB=oficinasMemoria.begin(); itB != oficinasMemoria.end(); ++itB)
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
								for (list<Region*>::iterator itB=regionesMemoria.begin(); itB != regionesMemoria.end(); ++itB)
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
								for (list<Oficina*>::iterator itB=oficinasMemoria.begin(); itB != oficinasMemoria.end(); ++itB)
								{
																if((*itB)->getCodigo() == codigo)
																								return (*itB);
								}
								return o;
}
Region* buscarRegion2(string codigo, list<Region*> &regionesMemoria)
{
								Region* r = new Region();
								for (list<Region*>::iterator itB=regionesMemoria.begin(); itB != regionesMemoria.end(); ++itB)
								{
																if((*itB)->getCodigo() == codigo)
																								return (*itB);
								}
								return r;
}
void imprimirRegiones(list<Region*> &regionesMemoria)
{
								for (list<Region*>::iterator itB=regionesMemoria.begin(); itB != regionesMemoria.end(); ++itB)
																cout<<"Region: "<<(*itB)->getNombre()<<endl;
}
void imprimirOficinas(list<Oficina*> &oficinasMemoria)
{
								for (list<Oficina*>::iterator itB=oficinasMemoria.begin(); itB != oficinasMemoria.end(); ++itB)
																cout<<"Oficina: "<<(*itB)->getNombre()<<endl;
}
void imprimirRegionesXoficina(list<Oficina*> &oficinasMemoria)
{
								for (list<Oficina*>::iterator itO = oficinasMemoria.begin(); itO != oficinasMemoria.end(); ++itO)
																cout<<"oficina "<<(*itO)->getNombre()<<" y su region "<<(*itO)->getListaRegiones().front()->getNombre()<<endl;
}
void imprimirPaquetesXRegion2(list<Oficina*> &oficinasMemoria)
{
								for (list<Oficina*>::iterator itO = oficinasMemoria.begin(); itO != oficinasMemoria.end(); ++itO)
								{
																cout<<(*itO)->getNombre()<< " con "<<(*itO)->getListaRegiones().size() <<" regiones y su region cabeza"<<(*itO)->getListaRegiones().front()->getNombre()
																				<<" y sus paquetes "<<"n = "<<(*itO)->getListaRegiones().front()->getListaPaquetes().size()<<
																(*itO)->getListaRegiones().front()->getListaPaquetes().front()->getRemitente()->getNombre()<<endl;
								}
}
void imprimirPaquetesXRegion(list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria, list<Paquete*> &paquetesMemoria)
{
								int cantidadAcum = 0;
								list<Region*> LRAux;
								for (list<Region*>::iterator itR1=regionesMemoria.begin(); itR1 != regionesMemoria.end(); ++itR1)
								{
																for (list<Oficina*>::iterator itO = oficinasMemoria.begin(); itO != oficinasMemoria.end(); ++itO)
																{
																								LRAux=(*itO)->getListaRegiones();
																								for (list<Region*>::iterator itR=LRAux.begin(); itR != LRAux.end(); ++itR)
																								{
																																if((*itR1)->getNombre() == (*itR)->getNombre())
																																{
																																								cantidadAcum += (*itR)->getListaPaquetes().size();
																																}
																								}
																}
																cout<<cantidadAcum<<" paquetes en la region de reparto "<<(*itR1)->getNombre()<<endl;
																cantidadAcum=0;
								}
								cout<<" Para un total de "<<paquetesMemoria.size()<<" paquetes en el sistema"<<endl;
}

bool cargarOficinas(string nombreArchivo, list<Oficina*> &oficinasMemoria)
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
																								vtoken = tokenizador2(line, ',');
																								if(registrarOficina(vtoken[3],vtoken[2],vtoken[1],vtoken[0],oficinasMemoria))
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
																cout<<"Se encontraron datos repetidos, estos no fueron tenidos en cuenta"<<endl;
								}
								if(exitos==0)
								{
																cout<<"No se cargo ningun elemento"<<endl;
																return false;
								}
								else if(exitos>0)
								{
																cout<<"Se cargaron exitosamente "<<exitos<<" de "<<fracasos + exitos<<" elementos."<<endl;
																return true;
								}
								return false;
}
bool cargarRegiones(string nombreArchivo, list<Oficina*> &oficinasMemoria, list<Region*> &regionesMemoria)
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
																								vtoken = tokenizador2(line, ',');
																								if(registrarRegion(vtoken[2],vtoken[1],vtoken[0],oficinasMemoria,regionesMemoria))
																																exitos++;
																								else
																																fracasos++;
																}
								}
								else
																return false;
								myfile.close();
								cout<<"Se cargaron exitosamente "<<exitos<<" de "<<fracasos + exitos<<" elementos."<<endl;
								if(res==1)
																cout<<"Se encontraron datos repetidos, estos no fueron tenidos en cuenta"<<endl;
								return true;
}
bool registrarOficina(string codigo, string nombre, string direccion, string ciudad,list<Oficina*> &oficinasMemoria)
{
								Oficina* oficinaAux = new Oficina();
								if(!buscarOficina( codigo, oficinasMemoria))
								{
																oficinaAux->setCodigo(codigo);
																oficinaAux->setNombre(nombre);
																oficinaAux->setDireccion(direccion);
																oficinaAux->setCiudad(ciudad);
																oficinasMemoria.push_front(oficinaAux);
																return true;
								}
								return false;
}
bool registrarRegion(string codigo, string nombre, string codigoOficinaPadre,list<Oficina*> &oficinasMemoria,list<Region*> &regionesMemoria)
{
								Region* regionAux = new Region();
								Oficina* oficinaAux;
								if(buscarOficina(codigoOficinaPadre,oficinasMemoria))
								{
																if(!buscarRegion( codigo, regionesMemoria))
																{
																								regionAux->setCodigo(codigo);
																								regionAux->setNombre(nombre);
																								oficinaAux = buscarOficina2(codigoOficinaPadre,oficinasMemoria);
																								regionesMemoria.push_front(regionAux);
																								oficinaAux->getListaRegiones().push_front(regionAux);
																								registrarOficina(codigo, nombre, oficinaAux->getDireccion(),oficinaAux->getCiudad(),oficinasMemoria);
																								oficinaAux = buscarOficina2(codigo,oficinasMemoria);
																								oficinaAux->getListaRegiones().push_front(regionAux);
																								return true;
																}
																else
																								return false;
								}
								return false;
}
void contarPaquetes(list<Oficina*> &oficinasMemoria){

								int suma = 0;
								for (list<Oficina*>::iterator itB=oficinasMemoria.begin(); itB != oficinasMemoria.end(); ++itB)
								{
																cout<<"Oficina "<<(*itB)->getNombre()<<" cantidad de regiones: "<<(*itB)->getListaRegiones().size()<<endl;

																for (list<Region*>::iterator itC=(*itB)->getListaRegiones().begin(); itC != (*itB)->getListaRegiones().end(); ++itC)
																{

																								cout<<"Region: "<<(*itC)->getNombre() <<" con "<<(*itC)->getListaPaquetes().size()<<" paquetes."<<endl;
																								suma += (*itC)->getListaPaquetes().size();
																}
																cout<< "para un total de "<< suma<< " en la oficina."<<endl;
																cout<<"--------------"<<endl;
																suma = 0;
																if(!(*itB)->getListaRegiones().empty())
																{

																}
								}
}

int contarPaquetesXRegion(list<Region*> &regionesMemoria)
{
								int cantidad = 0;
								if(!regionesMemoria.empty()) {
																for (list<Region*>::iterator itB=regionesMemoria.begin(); itB != regionesMemoria.end(); ++itB)
																{
																								cantidad = cantidad + (*itB)->getListaPaquetes().size() + contarPaquetesXRegion((*itB)->getOficinaDirecta()->getListaRegiones());
																}
								}
								return cantidad;
}

void imprimirOficinasYReguiones(list<Oficina*> &oficinasMemoria,list<Region*> &regionesMemoria)
{
								for (list<Oficina*>::iterator itB=oficinasMemoria.begin(); itB != oficinasMemoria.end(); ++itB)
								{
																cout<< "La oficina "<<(*itB)->getNombre()<<" con influencia en las regiones: "<<endl;
																for (list<Region*>::iterator itC=(*itB)->getListaRegiones().begin(); itC != (*itB)->getListaRegiones().end(); ++itC)
																{
																								cout<<(*itC)->getNombre() <<" con "<<(*itC)->getListaPaquetes().size()<<" paquetes."<<endl;
																}
																cout<<"--------------"<<endl;
								}
}
