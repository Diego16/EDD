
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

	public:
		//Paquete();
		//~Paquete();
        void setRemitente(Persona* remitenteIn);
        void setDestinatario(Persona* destinararioIn);
        void setPeso(int pesoIn);
        void setNumGuia(string numGuiaIn);
        void setTipo(string tipoIn);

        Persona* getRemitente( );
        Persona* getDestinatario( );
        int getPeso( );
        string getTipo( );
        string getNumGuia();


};

#include "paquete.hpp"
#endif

