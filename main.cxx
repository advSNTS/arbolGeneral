#include <iostream>
#include "ArbolGeneral.h"
int main(){
    ArbolGeneral<int> arbol;

    // Crear un árbol con raíz 1
    NodoGeneral<int>* raiz = new NodoGeneral<int>();
    int valor = 1;
    raiz->fijarDato(valor);
    arbol.fijarRaiz(raiz);

    arbol.insertarNodo(1, 2); // Insertar 2 como hijo de 1
    arbol.insertarNodo(1, 3); // Insertar 3 como hijo de 1
    arbol.insertarNodo(2, 4); // Insertar 4 como hijo de 2
    arbol.insertarNodo(2, 5); // Insertar 5 como hijo de 2
    arbol.insertarNodo(3, 6); // Insertar 6 como hijo de 3
    // Recorrer el árbol en preorden
    std::cout << "Recorrido en Preorden: ";
    arbol.preOrden(); // Salida esperada: 1 2 4 5 3 6
    std::cout<<std::endl;
    std::cout<<arbol.buscar(1); //true
    std::cout<<std::endl;
    std::cout<<arbol.buscar(8); //falso

    std::cout << std::endl;
    return 0;
}