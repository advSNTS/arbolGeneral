#include "NodoGeneral.h"

template <class T>
NodoGeneral<T>::NodoGeneral(){
    this->desc.clear();
}

template <class T>
NodoGeneral<T>::~NodoGeneral(){
    for(std::vector<NodoGeneral<T>>::iterator it = this->desc.begin(); it != this->desc.end(); it++){
        delete *it;
    }
    this->desc.clear();
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
    std::vector<NodoGeneral<T>*>::iterator it;
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