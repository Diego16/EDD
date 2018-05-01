
#ifndef __PAQUETE__H__
#define __PAQUETE__H__
#include <stack>
#include <queue>
#include "persona.h"
using namespace std;

class Paquete{

	private:
		Persona* remitente;
		Persona* destinatario;
		int peso;
		string tipo;
		string numGuia;
		string regionDestino;

	public:
		//Paquete();
		//~Paquete();
        void setRemitente(Persona* remitenteIn);
        void setDestinatario(Persona* destinararioIn);
        void setPeso(int pesoIn);
        void setNumGuia(string numGuiaIn);
        void setTipo(string tipoIn);
				void setRegionDestino(string codigoRegionIn);
        Persona* getRemitente( );
        Persona* getDestinatario( );
        int getPeso( );
        string getTipo( );
        string getNumGuia();
				string getRegionDestino();


};

#include "paquete.hpp"
#endif
