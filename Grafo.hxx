#include "Grafo.h"
		template<typename T>
Grafo<T>::Grafo(){

};
		template<typename T>
Grafo<T>::~Grafo(){

};
	 	template<typename T>
void Grafo<T>::setVertices(list<NodoGrafo<T>*> val){
 vertices=val;
};
		template<typename T>
list<NodoGrafo<T>*> Grafo<T>::getVertices(){
 return vertices;
};
		template<typename T>
bool Grafo<T>::insertarAristaDirigida(T de,T a, float costo){
    NodoGrafo<T>* primero= existeVertice(de);
    if (primero==NULL){
        primero=new NodoGrafo<T>(de);
        vertices.push_back(primero);
    }
    NodoGrafo<T>* segundo= existeVertice (a);
    if (segundo==NULL){
       segundo=new NodoGrafo<T>(a);
       vertices.push_back(segundo);
   }
   primero->agregarVecino(segundo,costo);
};
		template<typename T>
bool Grafo<T>::insertarAristaNoDirigida(T de,T a, float costo){
 NodoGrafo<T>* primero= existeVertice(de);
 if (primero==NULL){
    primero=new NodoGrafo<T>(de);
    vertices.push_back(primero);
}
NodoGrafo<T>* segundo= existeVertice (a);
if (segundo==NULL){
   segundo=new NodoGrafo<T>(a);
   vertices.push_back(segundo);
}
primero->agregarVecino(segundo,costo);
if (primero!=segundo){
    segundo->agregarVecino(primero,costo);
}
return true;
};
		template<typename T>
bool Grafo<T>::insertarVertice(T val){
    NodoGrafo<T>* aux=existeVertice(val);
    if (aux==NULL){
        aux=new NodoGrafo<T>(val);
        vertices.push_back(aux);
        return true;
    }
    return false;
};
		template<typename T>
NodoGrafo<T>* Grafo<T>::existeVertice(T val){
 typename list< NodoGrafo<T>* >::iterator it;
 for (it=vertices.begin();it!=vertices.end();it++){
    if ((*it)->getDato()==val){
        return *it;
    }
}
return NULL;

};
		template <typename T>
void Grafo<T>::recorridoPlano(){
    typename list< NodoGrafo<T>* >::iterator it=vertices.begin();
    for (it;it!=vertices.end();it++){
        cout << (*it)->getDato()<<" ";
    }
    cout << endl;
};
		template<typename T>
void Grafo<T>::recorridoDFS(NodoGrafo<T>* val){
  stack < NodoGrafo<T>* >pila;
  NodoGrafo<T>* aux=val;
  pila.push(aux);
  while (!pila.empty()){
    aux=pila.top();
    pila.pop();
    if (!aux->getVisitado()){
        cout << aux->getDato()<< " ";
        aux->setVisitado(true);
        list <par> lista= aux->getVecinos();
        typename list <par>::reverse_iterator it= lista.rbegin();
        for (it;it!=lista.rend();it++){
            pila.push((*it).first);
        }
    }
}
cout << endl;
typename list <NodoGrafo<T>*>::iterator it= vertices.begin();
for (it;it!=vertices.end();it++){
    (*it)->setVisitado(false);
}
};
		    template<typename T>
void Grafo<T>::recorridoBFS(NodoGrafo<T>* val){
  queue < NodoGrafo<T>* >pila;
  NodoGrafo<T>* aux=val;
  pila.push(aux);
  while (!pila.empty()){
    aux=pila.front();
    pila.pop();
    if (!aux->getVisitado()){
        cout << aux->getDato()<< " ";
        aux->setVisitado(true);
        list <par> lista= aux->getVecinos();
        typename list <par>::iterator it= lista.begin();
        for (it;it!=lista.end();it++){
            pila.push((*it).first);
        }
    }
}
cout<< endl;
typename list <NodoGrafo<T>*>::iterator it= vertices.begin();
for (it;it!=vertices.end();it++){
    (*it)->setVisitado(false);
}
};
		template<typename T>
bool Grafo<T>::eliminarVerticeNoDirigido(T val){
    NodoGrafo<T>* aux=existeVertice(val);
    if (aux!=NULL){
        list<par> lista=aux->getVecinos();
        typename list<par>::iterator it=lista.begin();
        for (it;it!=lista.end();it++){
            NodoGrafo<T>* temp=(*it).second;
            temp->eliminarConexion(val);
        }
        vertices.remove(aux);
        return true;
    }else{
        return false;
    }
};
		template<typename T>
bool Grafo<T>::eliminarAristaNoDirigida(T val,T val2){
    NodoGrafo<T>* aux=existeVertice(val);
    NodoGrafo<T>* aux2=existeVertice(val2);
    if (aux!=NULL){
        aux->eliminarConexion(val2);
        aux2->eliminarConexion(val);
        return true;
    }else{
        return false;
    }
};

