/**
 * \file ListaDoble2.hpp
 * \brief Implementaci&oacute;n de una lista doblemente enlazada
 * \author Ana Laura Chenoweth Galaz, Geogina Salcido Valenzuela
 * \date 22/03/2024
 */
#ifndef LISTADOBLE2_HPP_INCLUDED
#define LISTADOBLE2_HPP_INCLUDED

#include <iostream>
#define NO_ENCONTRADO -1
/** \class ListaDoble2
 *
 * Permite manipular una lista doblemente enlazada con una serie de operaciones como agregar elementos,
 * eliminar elementos, buscar elementos, entre otras.
 *
 * \tparam T Tipo de dato de los elementos almacenados en la lista.
 *
 * \code Ejemplo.cpp
#include <iostream>
#include "ListaDoble2.hpp"

bool EsPar(int valor) {
    return valor % 2 == 0;
}

int main() {
    ListaDoble2<int> lista;

    std::cout << "Lista vacia? " << (lista.EstaVacia() ? "Si" : "No") << std::endl;

    std::cout << "Agregaremos elementos\n";
    lista.AgregarFinal(10);
    lista.AgregarFinal(20);
    lista.AgregarFinal(30);
    lista.AgregarInicio(5);
    lista.AgregarInicio(2);

    std::cout << "Elementos de la lista: ";
    lista.Imprimir();
    std::cout << std::endl;

    std::cout << "Elementos de la lista (reversa): ";
    lista.ImprimirReversa();
    std::cout << std::endl;

    // Modificar un elemento en la posición 2
    lista.ModificarPos(15, 2);
    std::cout << "Elementos de la lista despues de modificar el valor en la posicion 2: ";
    lista.Imprimir();
    std::cout << std::endl;

    // Buscar un valor
    int valorABuscar = 15;
    std::cout << "¿El valor " << valorABuscar << " está en la lista? " << (lista.BuscarValor(valorABuscar) ? "Si" : "No") << std::endl;

    // Obtener el primer elemento
    std::cout << "Primer elemento de la lista: " << lista.ObtenerPrimero() << std::endl;

    // Obtener el último elemento
    std::cout << "Ultimo elemento de la lista: " << lista.ObtenerUltimo() << std::endl;

    // Eliminar un elemento en la posición 3
    lista.EliminarPos(3);
    std::cout << "Elementos de la lista despues de eliminar el valor en la posicion 3: ";
    lista.Imprimir();
    std::cout << std::endl;

    // Transferir elementos desde otra lista
    ListaDoble2<int> otraLista;
    otraLista.AgregarFinal(100);
    otraLista.AgregarFinal(200);
    otraLista.AgregarFinal(200);
    otraLista.AgregarFinal(400);
    otraLista.AgregarFinal(100);
    otraLista.AgregarFinal(200);
    otraLista.AgregarFinal(300);
    otraLista.AgregarFinal(400);
    lista.TransferirTodos(otraLista);
    std::cout << "Elementos de la lista despues de transferir desde otra lista: ";
    lista.Imprimir();
    std::cout << std::endl;

    // Eliminar todas las ocurrencias de un valor
    lista.EliminarTodasOcurrencias(100);
    std::cout << "Elementos de la lista despues de eliminar todas las ocurrencias de 100: ";
    lista.Imprimir();
    std::cout << std::endl;

    // Ordenar la lista en orden ascendente
    lista.OrdenarAscendente();
    std::cout << "Elementos de la lista despues de ordenar en orden ascendente: ";
    lista.Imprimir();
    std::cout << std::endl;

    // Eliminar elementos repetidos
    lista.EliminarRepetidos();
    std::cout << "Elementos de la lista despues de eliminar elementos repetidos: ";
    lista.Imprimir();
    std::cout << std::endl;

    // Eliminar elementos según una condición
    lista.EliminarConCondicion(EsPar);
    std::cout << "Elementos de la lista despues de eliminar elementos pares: ";
    lista.Imprimir();
    std::cout << std::endl;

    return 0;
}


 * \endcode
 *
 \verbatim Salida:
Lista vacia? Si
Agregaremos elementos
Elementos de la lista: 2, 5, 10, 20, 30,
Elementos de la lista (reversa): 30, 20, 10, 5, 2,
Elementos de la lista despues de modificar el valor en la posicion 2: 2, 5, 15, 20, 30,
┐El valor 15 estß en la lista? Si
Primer elemento de la lista: 2
Ultimo elemento de la lista: 30
Elementos de la lista despues de eliminar el valor en la posicion 3: 2, 5, 20, 30,
Elementos de la lista despues de transferir desde otra lista: 2, 5, 20, 30, 100, 200, 200, 400, 100, 200, 300, 400,
Elementos de la lista despues de eliminar todas las ocurrencias de 100: 2, 5, 20, 30, 100, 200, 200, 400, 200, 300, 400,
Elementos de la lista despues de ordenar en orden ascendente: 2, 5, 20, 30, 100, 200, 200, 200, 300, 400, 400,
Elementos de la lista despues de eliminar elementos repetidos: 2, 5, 20, 30, 100, 200, 300, 400,
Elementos de la lista despues de eliminar elementos pares: 5,
  \endverbatim
 *
 */
template <typename T>
class ListaDoble2 {
public:
    /** \brief Constructor por defecto.
     *
     * Crea una lista doblemente enlazada vac&iacute;a.
     */
    ListaDoble2();
    /** \brief Destructor.
     *
     * Libera la memoria ocupada por la lista.
     */
    ~ListaDoble2();
    /** \brief Constructor de copia.
     *
     * \param l Lista a copiar.
     */
    ListaDoble2(const ListaDoble2<T> &l);
    
    /** \brief Operador de asignaci&oacute;n.
     *
     * Asigna el contenido de una lista a otra.
     *
     * \param l Lista a asignar.
     * \return Referencia a la lista actual.
     */
    ListaDoble2<T> & operator=(const ListaDoble2 &l);
    /** \brief Agrega un elemento al inicio de la lista.
     *
     * \param valor Valor del elemento a agregar.
     */
    void AgregarInicio(T valor);
    /** \brief Agrega un elemento al final de la lista.
     *
     * \param valor Valor del elemento a agregar.
     */
    void AgregarFinal(T valor);
    /** \brief Agrega un elemento en una posici&oacute;n espec&iacute;fica de la lista.
     *
     * \param valor Valor del elemento a agregar.
     * \param pos Posici&oacute;n en la que se agregar&aacute; el elemento.
     * \throw FueraRango si la posici&oacute;n est&aacute; fuera del rango de la lista.
     */
    void AgregarPos(T valor, int pos);
    /** \brief Elimina el primer elemento de la lista.
     *
     * \throw ListaVacia si la lista est&aacute; vac&iacute;a.
     */
    void EliminarInicio();
    /** \brief Elimina el &uacute;ltimo elemento de la lista.
     *
     * \throw ListaVacia si la lista est&aacute; vac&iacute;a.
     */
    void EliminarFinal();
    /** \brief Elimina el elemento en una posici&oacute;n espec&iacute;fica de la lista.
     *
     * \param pos Posici&oacute;n del elemento a eliminar.
     * \throw FueraRango si la posici&oacute;n est&aacute; fuera del rango de la lista.
     */
    void EliminarPos(int pos);
    /** \brief Busca un valor en la lista.
     *
     * \param valor Valor a buscar.
     * \return true si el valor se encuentra en la lista, false en caso contrario.
     */
    bool BuscarValor(T valor) const;
    /** \brief Busca la posici&oacute;n de un valor en la lista.
     *
     * \param valor Valor a buscar.
     * \return Posici&oacute;n del valor en la lista o NO_ENCONTRADO si no se encuentra.
     */
    int BuscarPos(T valor) const;
    /** \brief Verifica si la lista est&aacute; vac&iacute;a.
     *
     * \return true si la lista est&aacute; vac&iacute;a, false en caso contrario.
     */
    bool EstaVacia() const;
    /** \brief Obtiene el primer elemento de la lista.
     *
     * \return Valor del primer elemento.
     * \throw ListaVacia si la lista est&aacute; vac&iacute;a.
     */
    T ObtenerPrimero() const;
    /** \brief Obtiene el &uacute;ltimo elemento de la lista.
     *
     * \return Valor del &uacute;ltimo elemento.
     * \throw ListaVacia si la lista est&aacute; vac&iacute;a.
     */
    T ObtenerUltimo() const;
    /** \brief Obtiene el elemento en una posici&oacute;n espec&iacute;fica de la lista.
     *
     * \param pos Posici&oacute;n del elemento a obtener.
     * \return Valor del elemento en la posici&oacute;n indicada.
     * \throw FueraRango si la posici&oacute;n est&aacute; fuera del rango de la lista.
     */
    T ObtenerPorPos(int pos) const;
    /** \brief Modifica el valor del elemento en una posici&oacute;n espec&iacute;fica de la lista.
     *
     * \param valor Nuevo valor a asignar al elemento.
     * \param pos Posici&oacute;n del elemento a modificar.
     * \throw FueraRango si la posici&oacute;n est&aacute; fuera del rango de la lista.
     */
    void ModificarPos(T valor, int pos);
    /** \brief Obtiene el n&uacute;mero de elementos en la lista.
     *
     * \return N&uacute;mero de elementos en la lista.
     */
    int NumElementos() const;
    /** \brief Vac&iacute;a la lista, eliminando todos los elementos.
     */
    void Vaciar();
    /** \brief Imprime los elementos de la lista en orden.
     */
    void Imprimir() const;
    /** \brief Imprime los elementos de la lista en orden inverso.
     */
    void ImprimirReversa() const;
    /** \brief Sobrecarga del operador [] para acceder a los elementos de la lista.
     *
     * \param pos Posici&oacute;n del elemento a acceder.
     * \return Referencia al elemento en la posici&oacute;n indicada.
     * \throw FueraRango si la posici&oacute;n est&aacute; fuera del rango de la lista.
     */
    T& operator[](int pos);
    /** \brief Sobrecarga del operador [] constante para acceder a los elementos de la lista.
     *
     * \param pos Posici&oacute;n del elemento a acceder.
     * \return Referencia constante al elemento en la posici&oacute;n indicada.
     * \throw FueraRango si la posici&oacute;n est&aacute; fuera del rango de la lista.
     */
    const T& operator[](int pos) const;
    /** \brief Intercambia el contenido de la lista con otra lista.
     *
     * \param lista Lista con la que se intercambiar&aacute; el contenido.
     */
    void Intercambiar(ListaDoble2<T> &lista);
    /** \brief Transfiere un rango de elementos desde otra lista a esta lista.
     *
     * \param otraLista Lista desde la cual se transferir&aacute;n los elementos.
     * \param posInicio Posici&oacute;n de inicio del rango de elementos a transferir.
     * \param posFin Posici&oacute;n final del rango de elementos a transferir.
     * \throw FueraRango si las posiciones est&aacute;n fuera del rango de la lista original.
     */
    void TransferirRango(ListaDoble2<T>& otraLista, int posInicio, int posFin);
    /** \brief Transfiere todos los elementos desde otra lista a esta lista.
     *
     *
      * \param otraLista Lista desde la cual se transferir&aacute;n los elementos.
     */
    void TransferirTodos(ListaDoble2<T>& otraLista);
    /** \brief Transfiere los elementos de otra lista a partir de una posici&oacute;n especificada.
     *
     * Este m&eacute;todo transfiere todos los elementos de otra lista a partir de una posici&oacute;n especificada,
     * insert&aacute;ndolos al final de esta lista. La lista original se vac&iacute;a despu&eacute;s de la transferencia.
     * Si la posici&oacute;n especificada est&aacute; fuera de rango en la lista original, se lanzar&aacute; una excepci&oacute;n.
     *
     * \param otraLista La lista desde la cual se transferir&aacute;n los elementos.
     * \param posInicio La posici&oacute;n desde la cual se comenzar&aacute;n a transferir los elementos en la lista original.
     *
     * \throw FueraRango Si la posici&oacute;n especificada est&aacute; fuera de rango en la lista original.
     */
        /** \brief Transfiere los elementos de otra lista a partir de una posici&oacute;n especificada.
     *
     * Este m&eacute;todo transfiere todos los elementos de otra lista a partir de una posici&oacute;n especificada,
     * insert&aacute;ndolos al final de esta lista. La lista original se vac&iacute;a despu&eacute;s de la transferencia.
     * Si la posici&oacute;n especificada est&aacute; fuera de rango en la lista original, se lanzar&aacute; una excepci&oacute;n.
     *
     * \param otraLista La lista desde la cual se transferir&aacute;n los elementos.
     * \param posInicio La posici&oacute;n desde la cual se comenzar&aacute;n a transferir los elementos en la lista original.
     *
     * \throw FueraRango Si la posici&oacute;n especificada est&aacute; fuera de rango en la lista original.
     */
    void TransferirDesde(ListaDoble2<T>& otraLista, int posInicio);
    /** \brief Elimina todas las ocurrencias repetidas de elementos en la lista.
     *
     * Este m&eacute;todo elimina todas las ocurrencias repetidas de elementos en la lista,
     * manteniendo solo la primera ocurrencia de cada elemento y eliminando las
     * ocurrencias adicionales. El orden de los elementos se conserva.
     */
    void EliminarRepetidos();
    /** \brief Elimina todas las ocurrencias de un valor espec&iacute;fico en la lista.
     *
     * Este m&eacute;todo elimina todas las ocurrencias de un valor espec&iacute;fico en la lista.
     * Despu&eacute;s de la eliminaci&oacute;n, los elementos restantes mantienen su orden original en la lista.
     *
     * \param valor El valor que se eliminar&aacute; de la lista.
     */
    void EliminarTodasOcurrencias(T valor);
    /** \brief Elimina los elementos que cumplen con una condici&oacute;n dada.
     *
     * Este m&eacute;todo elimina los elementos de la lista que cumplen con una condici&oacute;n dada,
     * representada por una funci&oacute;n de condici&oacute;n proporcionada como argumento.
     * Los elementos restantes mantienen su orden original en la lista.
     *
     * \param condicion Puntero a una funci&oacute;n que define la condici&oacute;n de eliminaci&oacute;n.
     * La funci&oacute;n debe aceptar un valor de tipo T como argumento y devolver un valor booleano
     * que indique si el elemento debe ser eliminado (true) o no (false).
     */
    void EliminarConCondicion(bool (*condicion)(T));
    /** \brief Ordena los elementos de la lista en orden ascendente.
     *
     * Este m&eacute;todo ordena los elementos de la lista en orden ascendente utilizando un algoritmo de ordenamiento adecuado.
     */
    void OrdenarAscendente();

  /** \class ListaVacia
   *  \brief Excepci&oacute;n lanzada cuando se realiza una operaci&oacute;n en una lista vac&iacute;a.
   */
  class ListaVacia : public std::exception
  {
  public:
    virtual const char *what() const throw();
  };
  /** \class FueraRango
   *  \brief Excepci&oacute;n lanzada cuando se intenta acceder a una posici&oacute;n fuera del rango de la lista.
   */
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

