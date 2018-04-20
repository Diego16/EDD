
#ifndef __REGION__H__
#define __REGION__H__
//#include "oficina.h"
#include <stack>
#include <queue>
#include "paquete.h"

class Oficina;

using namespace std;

class Region{

	private:
		string codigo;
		string nombre;
		list<Paquete*> listaPaquetes;
		Oficina* oficinaDirecta;

	public:
		//Region();
		//~Region();
        void setCodigo(string codigoIn);
        void setNombre(string nombreIn);
        void setListaPaquetes(list<Paquete*> listaPaquetesIn);
        void setOficinaDirecta(Oficina* oficinaIn);

        string getCodigo( );
        string getNombre( );
        list<Paquete*>& getListaPaquetes();
        bool agregarPaquete(Paquete* paqueteIn);
        Oficina* getOficinaDirecta();

};

#include "region.hpp"
#endif
