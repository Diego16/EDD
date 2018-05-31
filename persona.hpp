#ifndef __PERSONA__HPP__
#define __PERSONA__HPP__
#include <iostream>
#include "persona.h"
#include <string>
#include <list>

using namespace std;

void Persona::setCedula(string cedulaIn){
	cedula = cedulaIn;
}
void Persona::setDireccion(string direccionIn){
	direccion = direccionIn;
}
void Persona::setCiudad(string ciudadIn){
	ciudad = ciudadIn;
}
void Persona::setTelefono( string telefonoIn){
	telefono =  telefonoIn;
}
void Persona::setNombre(string nombreIn){
	nombre = nombreIn;
}
void Persona::setApellido(string apellidoIn){
	apellido = apellidoIn;
}
string Persona::getDireccion( ){
	return direccion;
}
string Persona::getCiudad( ){
	return ciudad;
}
string Persona::getTelefono (){
	return telefono;
}
string Persona::getNombre( ){
	return nombre;
}
string Persona::getApellido(){
	return apellido;
}
string Persona::getCedula( ){
	return cedula;
}

#endif
