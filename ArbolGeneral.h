#ifndef ARBOL_GENERAL_H
#define ARBOL_GENERAL_H
#include "NodoGeneral.h"
#include <queue>
template<class T>
class ArbolGeneral
{
protected:
    NodoGeneral<T>* raiz;
public:
    ArbolGeneral();
    ArbolGeneral(T val);
    ~ArbolGeneral();
    bool esVacio();
    NodoGeneral<T>* obtenerRaiz();
    void fijarRaiz(NodoGeneral<T>* nraiz);
    bool insertarNodo(T padre, T n);
    bool eliminarNodo(T n);
    bool buscar(T n);
    int altura();
    int altura(NodoGeneral<T>* nodo);
    unsigned int tamano();
    void preOrden();
    void preOrden(NodoGeneral<T>* nodo);
    void posOrden();
    void nivelOrden();
    NodoGeneral<T>* buscarNodo(NodoGeneral<T>* nodo, T valor);
    bool buscarRecursivo(NodoGeneral<T>* nodo, T n);
    void posOrden(NodoGeneral<T>* nodo);
};

#include "ArbolGeneral.hxx"

#endif