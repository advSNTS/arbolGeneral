#include "NodoGeneral.h"

template <class T>
NodoGeneral<T>::NodoGeneral(){
    this->desc.clear();
}

template <class T>
NodoGeneral<T>::~NodoGeneral(){
    for(typename std::vector<NodoGeneral<T>*>::iterator it = this->desc.begin(); it != this->desc.end(); it++){
        delete *it;
    }
    this->desc.clear();
}

//como desc es protegido, entonces hacemos un getter
template <class T>
const std::vector<NodoGeneral<T>*>& NodoGeneral<T>::obtenerDesc() const {
    return desc;
}

template <class T>
T& NodoGeneral<T>::obtenerDato(){
    return this->dato;
}

template <class T>
void NodoGeneral<T>::fijarDato(T& val){
    this->dato = val;
}

template <class T>
void NodoGeneral<T>::limpiarLista(){
    this->desc.clear();
}

template <class T>
void NodoGeneral<T>::adicionarDesc(T& nval){
    NodoGeneral<T> *nodo = new NodoGeneral<T>;
    nodo->fijarDato(nval);
    this->desc.push_back(nodo);
}

template <class T>
bool NodoGeneral<T>::eliminarDesc(T& val){
    NodoGeneral<T> *aux;
    typename std::vector<NodoGeneral<T>*>::iterator it;
    bool eliminado = false;
    for( it = this->desc.begin(); it != this->desc.end(); it++){
        aux = *it;
        if(aux->obtenerDato()==val){
            break;
        }

    }
    if(it!=this->desc.end()){
        delete *it;
        this->desc.erase(it);
        eliminado = true;
    }
    return eliminado;
}

template <class T>
bool NodoGeneral<T>::esHoja(){
    return this->desc.size()==0;
}