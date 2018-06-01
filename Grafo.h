#ifndef __GRAFO__H__
#define __GRAFO__H__
#include "NodoGrafo.h"
#include <stack>
#include <queue>

template <typename T>
class Grafo{
    typedef pair<NodoGrafo<T>*,double> par;
	private:
		list<NodoGrafo<T>*> vertices;
	public:
		Grafo();
		~Grafo();
		void setVertices(list<NodoGrafo<T>*>);
		list<NodoGrafo<T>*> getVertices();
		bool insertarAristaDirigida(T de,T a, double costo);
		bool insertarAristaNoDirigida(T de,T a, double costo);
		bool insertarVertice(T val);
		NodoGrafo<T>* existeVertice(T val);
		bool existeVertice2(T val);
		void recorridoPlano();
		bool eliminarVerticeNoDirigido(T val);
		void recorridoDFS(NodoGrafo<T>*);
		void recorridoBFS(NodoGrafo<T>* val);
		bool eliminarAristaNoDirigida(T val,T val2);
		int tam();

};

#include "Grafo.hxx"
#endif

