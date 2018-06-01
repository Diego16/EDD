#include "NodoGrafo.h"

		template <typename T>
NodoGrafo<T>::NodoGrafo(){
	visitado=false;
};
		template <typename T>
NodoGrafo<T>::NodoGrafo(T val){
	dato=val;
	visitado=false;
};
		template <typename T>
NodoGrafo<T>::NodoGrafo(T val,list<par> val2){
	dato=val;
	vecinos=val2;
	visitado=false;
};
		template <typename T>
NodoGrafo<T>::~NodoGrafo(){

};
		template <typename T>
void NodoGrafo<T>::setDato(T val){
	dato=val;
};
		template <typename T>
T NodoGrafo<T>::getDato(){
	return dato;
};
		template <typename T>
void NodoGrafo<T>::setVecinos(list<par> val){
	vecinos=val;
};
		template <typename T>
bool NodoGrafo<T>::agregarVecino(NodoGrafo<T>* val1,double val2){
	par a (val1,val2);
	vecinos.push_back(a);
	return true;
};
		template <typename T>
list< pair<NodoGrafo<T>*,double> > NodoGrafo<T>::getVecinos(){
	return vecinos;
};
		template <typename T>
std::pair<NodoGrafo<T>*,double> NodoGrafo<T>::buscarVecino(T val){
	typename list< pair<NodoGrafo<T>*,double> >::iterator it=vecinos.begin();
	for (it;it!=vecinos.end();it++){
		if ((*it).first==val ){
			return *it;
		}
	}
};
		template <typename T>
void NodoGrafo<T>::setVisitado(bool val){
	visitado=val;
};
        template <typename T>
bool NodoGrafo<T>::getVisitado(){
	return visitado;
};
		template <typename T>
bool NodoGrafo<T>::eliminarConexion(T val){
	typename list< pair<NodoGrafo<T>*,double> >::iterator it=vecinos.begin();
	typename list< pair<NodoGrafo<T>*,double> >::iterator it2=NULL;
	for (it;it!=vecinos.end();it++){
		if ((*it).first==val ){
			it2=it;
		}
	}
	if (it2!=NULL){
		vecinos.erase(it2);
		return true;
	}
	return false;
};
