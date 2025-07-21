
#ifndef LISTADOBLE2_HPP_INCLUDED
#define LISTADOBLE2_HPP_INCLUDED

#include <iostream>
#define NO_ENCONTRADO -1

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
    T ObtenerPorPos(int pos) const;
    void ModificarPos(T valor, int pos);
    int NumElementos() const;
    void Vaciar();
    void Imprimir() const;
    void ImprimirReversa() const;
    T& operator[](int pos);
    const T& operator[](int pos) const;
    void Intercambiar(ListaDoble2<T> &lista);
    void TransferirRango(ListaDoble2<T>& otraLista, int posInicio, int posFin);
    void TransferirTodos(ListaDoble2<T>& otraLista);
    void TransferirDesde(ListaDoble2<T>& otraLista, int posInicio);
    void EliminarRepetidos();
    void EliminarTodasOcurrencias(T valor);
    void EliminarConCondicion(bool (*condicion)(T));

  class ListaVacia : public std::exception
  {
  public:
    virtual const char *what() const throw();
  };
  class FueraRango : public std::exception
  {
  public:
    virtual const char *what() const throw();
  };
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

