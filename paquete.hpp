#ifndef __PAQUETE__HPP__
#define __PAQUETE__HPP__

#include <iostream>
#include "paquete.h"
#include <string>
#include <list>
#include "persona.h"

using namespace std;

void Paquete::setRemitente(Persona* remitenteIn){
    remitente = remitenteIn;
}
void Paquete::setDestinatario(Persona* destinatarioIn){
    destinatario = destinatarioIn;
}
void Paquete::setPeso(int pesoIn){
    peso = pesoIn;
}
void Paquete::setTipo(string tipoIn){
    tipo = tipoIn;
}
void Paquete::setNumGuia(string numGuiaIn){
    numGuia = numGuiaIn;
}

Persona* Paquete::getRemitente( ){
    return remitente;
}
Persona* Paquete::getDestinatario( ){
    return destinatario;
}
int Paquete::getPeso( ){
    return peso;
}
string Paquete::getTipo( ){
    return tipo;
}
string Paquete::getNumGuia(){
    return numGuia;
}
#endif
