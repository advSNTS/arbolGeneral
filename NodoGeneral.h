#ifndef NODOGENERAL_H
#define NODOGENERAL_H
#include<vector>

template< class T>

class NodoGeneral
{
protected:
    T dato;
    std::vector<NodoGeneral<T>* > desc;
public:
    NodoGeneral();
    ~NodoGeneral();
    T& obtenerDato();
    void fijarDato(T& val);
    void limpiarLista();
    void adicionarDesc(T& nval);
    bool eliminarDesc(T& val);
    bool esHoja();
    const std::vector<NodoGeneral<T>*>& obtenerDesc() const;
};

#include "NodoGeneral.hxx"

#endif