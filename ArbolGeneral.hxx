#include "ArbolGeneral.h"

template <class T>
ArbolGeneral<T>::ArbolGeneral(){
    this->raiz = NULL;
}

template <class T>
ArbolGeneral<T>::ArbolGeneral(T val){
    NodoGeneral<T>* nodo = new NodoGeneral<T>;
    nodo->fijarDato(val);
    this->raiz = nodo;
}

template <class T>
ArbolGeneral<T>::~ArbolGeneral(){
    delete this->raiz;
    this->raiz = NULL;
}

template <class T>
bool ArbolGeneral<T>::esVacio(){
    return this->raiz == NULL;
}

template <class T>
NodoGeneral<T>* ArbolGeneral<T>::obtenerRaiz(){
    return this->raiz;
}

template <class T>
void ArbolGeneral<T>::fijarRaiz(NodoGeneral<T>* nraiz){
    this->raiz = nraiz;
}

template <class T>
bool ArbolGeneral<T>::insertarNodo(T padre, T n){
    //si el arbol es vacio...
    
}

template <class T>
bool ArbolGeneral<T>::eliminarNodo(T n){
    
}

template <class T>
bool ArbolGeneral<T>::buscar(T n){
    
}

template <class T>
int ArbolGeneral<T>::altura(){
    if(this->esVacio()){
        return -1;
    }else{
        return this->altura(this->raiz);
    }
}

template <class T>
int ArbolGeneral<T>::altura(NodoGeneral<T>* nodo){
    int alt = -1;

    if(nodo->esHoja()){
        alt=0;
    } else{
        int alth;
        std::vector<NodoGeneral<T>*>::iterator it;
        for(it = nodo->desc.begin(); it != nodo->desc.end(); it++){
            alth = this->altura(*it);
            if(alt<alth+1){
                alt = alth+1;
            }
        }
    }

    return alt;
}


template <class T>
unsigned int ArbolGeneral<T>::tamano(){
    
}

template <class T>
void ArbolGeneral<T>::preOrden(){
    if(!this->esVacio()){
        this->preOrden(this->raiz())
    }
}

template <class T>
void ArbolGeneral<T>::preOrden(NodoGeneral<T>* nodo){
    std::cout<< nodo->obtenerDato() <<" ";
    
    std::vector<NodoGeneral<T>* >::iterator it;
    for(it = nodo->desc.begin(); it!= nodo->desc.end(); it++){
        this->preOrden(*it);
    }
}

template <class T>
void ArbolGeneral<T>::posOrden(){
    
}

template <class T>
void ArbolGeneral<T>::nivelOrden(){
    
}