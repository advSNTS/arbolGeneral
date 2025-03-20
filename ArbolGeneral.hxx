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
    if(altura()==-1){
        NodoGeneral<T>* nodo = new NodoGeneral<T>;
        nodo->fijarDato(n);
        this->raiz = nodo;
        return true;
        //se crea una raiz.
    }
    else {
        //si no está vacio, buscamos el nodo comenzando desde la raíz
        NodoGeneral<T>* nodoPadre = buscarNodo(this->raiz, padre);
        if (nodoPadre == nullptr) {
            return false;
            //si no se encontró, paila
        }
    
        //agregar el nuevo nodo como hijo del nodo padre
        nodoPadre->adicionarDesc(n);
    
        return true; // exito
    }
    
}

template<class T>
NodoGeneral<T>* ArbolGeneral<T>::buscarNodo(NodoGeneral<T>* nodo, T valor) {
    if (nodo == nullptr) {
        return nullptr;
    }

    // primer caso, si el nodo actual tiene los valores se retorna
    if (nodo->obtenerDato() == valor) {
        return nodo;
    }

    // buscar en hijos
    for (typename std::vector<NodoGeneral<T>* >::const_iterator it = nodo->obtenerDesc().begin(); it != nodo->obtenerDesc().end(); it++) {
        NodoGeneral<T>* resultado = buscarNodo(*it, valor); //la recursividad y la física cuantica son las dos cosas incomprendidas del universo
        if (resultado != nullptr) {
            return resultado; //si se encuentra, retornar el puntero
            //por alguna razon esto funciona???
        }
    }

    return nullptr; // Si no se encuentra, retornar nullptr
}

template <class T>
bool ArbolGeneral<T>::eliminarNodo(T n){
    
}

template <class T>
bool ArbolGeneral<T>::buscar(T n){
    if(altura() ==-1){
        return false;
    }
    else if(altura() == 0){
        if(raiz->obtenerDato()==n){
            std::cout<<"Dato encontrado en el nodo raíz.";
            return true;
        }
    }
    else if(buscarRecursivo(this->raiz, n)){
        return true;
    }
    return false;
}


template <class T>
bool ArbolGeneral<T>::buscarRecursivo(NodoGeneral<T>* nodo, T n){
    if (nodo == nullptr) {
        return false;
    }
    if(nodo->obtenerDato()==n){
        return true;
    }
    for (typename std::vector<NodoGeneral<T>* >::const_iterator it = nodo->obtenerDesc().begin(); it != nodo->obtenerDesc().end(); it++){
        if(buscarRecursivo(*it, n)){
            return true;
        }
    }
    return false;
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
        typename std::vector<NodoGeneral<T>*>::const_iterator it;
        for(it = nodo->obtenerDesc().begin(); it != nodo->obtenerDesc().end(); it++){
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
        this->preOrden(this->raiz);
    }
}

template <class T>
void ArbolGeneral<T>::preOrden(NodoGeneral<T>* nodo){
    std::cout<< nodo->obtenerDato() <<" ";
    
    typename std::vector<NodoGeneral<T>* >::const_iterator it;
    for(it = nodo->obtenerDesc().begin(); it!= nodo->obtenerDesc().end(); it++){
        this->preOrden(*it);
    }
}

template <class T>
void ArbolGeneral<T>::posOrden(){
    
}

template <class T>
void ArbolGeneral<T>::nivelOrden(){
    
}