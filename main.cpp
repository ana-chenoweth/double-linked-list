#include <iostream>
#include "ListaDoble/ListaDoble2.hpp"

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

    // Modificar un elemento en la posici�n 2
    lista.ModificarPos(15, 2);
    std::cout << "Elementos de la lista despues de modificar el valor en la posicion 2: ";
    lista.Imprimir();
    std::cout << std::endl;

    // Buscar un valor
    int valorABuscar = 15;
    std::cout << "�El valor " << valorABuscar << " est� en la lista? " << (lista.BuscarValor(valorABuscar) ? "Si" : "No") << std::endl;

    // Obtener el primer elemento
    std::cout << "Primer elemento de la lista: " << lista.ObtenerPrimero() << std::endl;

    // Obtener el �ltimo elemento
    std::cout << "Ultimo elemento de la lista: " << lista.ObtenerUltimo() << std::endl;

    // Eliminar un elemento en la posici�n 3
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

    // Eliminar elementos seg�n una condici�n
    lista.EliminarConCondicion(EsPar);
    std::cout << "Elementos de la lista despues de eliminar elementos pares: ";
    lista.Imprimir();
    std::cout << std::endl;

    return 0;
}
