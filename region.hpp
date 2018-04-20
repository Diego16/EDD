#ifndef __REGION__HPP__
#define __REGION__HPP__

#include <iostream>
#include "region.h"
#include "paquete.h"
#include <string>
#include <list>
#include "oficina.h"
using namespace std;

void Region::setCodigo(string codigoIn){
    codigo = codigoIn;
}
void Region::setNombre(string nombreIn){
    nombre = nombreIn;
}


string Region::getCodigo( ){
    return codigo;
}
string Region::getNombre( ){
    return nombre;
}
void Region::setListaPaquetes(list<Paquete*> listaPaquetesIn){
    listaPaquetes = listaPaquetesIn;
}
list<Paquete*>& Region::getListaPaquetes(){
    return listaPaquetes;
}
bool Region::agregarPaquete(Paquete* paqueteIn){
    listaPaquetes.insert(listaPaquetes.begin(), paqueteIn);
    return true;
}
void Region::setOficinaDirecta(Oficina* oficinaIn){
    oficinaDirecta = oficinaIn;
}
Oficina* Region::getOficinaDirecta(){
    return oficinaDirecta;
}
#endif // __REGION__HPP__
