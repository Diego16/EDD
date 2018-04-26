
#ifndef __OFICINA__H__
#define __OFICINA__H__
#include <stack>
#include <queue>
#include <string.h>
#include "region.h"
#include "paquete.h"

using namespace std;


class Oficina{

	private:
		string codigo;
		string nombre;
		string direccion;
		string ciudad;
		list<Region*> listaRegiones;
        list<Paquete*> listaPaquetes;
	public:
		//Oficina();
		//~Oficina();
        void setCodigo(string codigoIn);
        void setNombre(string nombreIn);
        void setDireccion(string DireccionIn);
        void setCiudad(string ciudadIn);
        void setListaRegiones(list<Region*> listaRegionesIn);
        void setListaPaquetes(list<Paquete*> listaPaquetesIn);

        string getCodigo( );
        string getNombre( );
        string getDireccion( );
        string getCiudad( );
        list<Region*>& getListaRegiones();
        list<Paquete*>& getListaPaquetes();
        bool agregarPaquete(Paquete* paqueteIn, string codigoRegionIn);
        void agregarRegion(Region* regionIn);

};

#include "oficina.hpp"
#endif
