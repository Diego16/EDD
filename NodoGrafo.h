#ifndef __NODOGRAFO__H__
#define __NODOGRAFO__H__
#include <list>
#include <iterator>
#include <utility>


using namespace std;

template <typename T>
class NodoGrafo{
	typedef pair<NodoGrafo<T>*,double> par;
	private:
		T dato;
		bool visitado;
		list<par> vecinos;
	public:
		NodoGrafo<T>();
		NodoGrafo<T>(T);
		NodoGrafo<T>(T,list<par>);
		~NodoGrafo<T>();
		void setDato(T);
		T getDato();
		void setVecinos(list<par>);
		bool agregarVecino(NodoGrafo<T>*,double);
		list<par> getVecinos();
		par buscarVecino(T);
		void setVisitado(bool);
		bool getVisitado();
		bool eliminarConexion(T);
		bool buscarVecino2(T val);
		double getPesoVecino(T val);
};



#include "NodoGrafo.hxx"
#endif
