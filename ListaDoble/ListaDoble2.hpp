
#ifndef LISTADOBLE2_HPP_INCLUDED
#define LISTADOBLE2_HPP_INCLUDED

#include <iostream>

template <typename T>
class ListaDoble2 {
public:
    ListaDoble2();
    ~ListaDoble2();
    ListaDoble2(const ListaDoble2<T> &l);
    void AgregarInicio(T valor);
    void AgregarFinal(T valor);
    void AgregarPos(T valor, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool BuscarValor(T valor) const;
    int BuscarPos(T valor) const;
    bool EstaVacia() const;
    T ObtenerPrimero() const;
    T ObtenerUltimo() const;
private:
    int tam, pos;
    struct Elemento
    {
        T valor;
        Elemento *siguiente, *anterior;
        Elemento(T val, Elemento *sig, Elemento *ant) : valor(val), siguiente(sig), anterior(ant) {}
    };
    Elemento *primero, *ultimo;
};

#include "ListaDoble2.tpp"
#endif // LISTADOBLE2_HPP_INCLUDED

