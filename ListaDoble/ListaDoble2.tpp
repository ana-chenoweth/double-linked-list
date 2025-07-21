
//****************************************************************************************
template <typename T>
ListaDoble2<T>::ListaDoble2(): tam(0), primero(nullptr), ultimo(nullptr)
{

}
//****************************************************************************************
template <typename T>
ListaDoble2<T>::~ListaDoble2()
{
    Vaciar();
}

//****************************************************************************************
template <typename T>
ListaDoble2<T>::ListaDoble2(const ListaDoble2<T> &l): tam(0), primero(nullptr), ultimo(nullptr)
{
    this = l;
}

//****************************************************************************************
template <typename T>
void ListaDoble2<T>::AgregarInicio(T valor) {
    Elemento *nuevo = new Elemento(valor, primero, nullptr);
    if (primero != nullptr) {
        primero->anterior = nuevo;
    } else {
        ultimo = nuevo;
    }
    primero = nuevo;
    ++tam;
}
//****************************************************************************************
template <typename T>
void ListaDoble2<T>::AgregarFinal(T valor) {
    Elemento* nuevo;
    if (EstaVacia()) {
        nuevo = new Elemento(valor, nullptr, nullptr);
        primero = nuevo;
    } else {
        nuevo = new Elemento(valor, nullptr, ultimo);
        ultimo->siguiente = nuevo;
    }
    ultimo = nuevo;
    ++tam;
}
//****************************************************************************************
template <typename T>
void ListaDoble2<T>::AgregarPos(T valor, int pos) {
    if (pos < 0 || pos > tam) throw FueraRango();

    if (pos == 0)
        AgregarInicio(valor);
    else if (pos == tam)
        AgregarFinal(valor);
    else {
        Elemento *ant = primero;
        for (int i = 1; i < pos; ++i) ant = ant->siguiente;
        Elemento *nuevo = new Elemento(valor, ant->siguiente, ant);

        ant->siguiente = nuevo;
        nuevo->siguiente->anterior = nuevo;

        ++tam;
    }
}
//************************************************************************************
template <typename T>
void  ListaDoble2<T>::EliminarInicio()
{
    if(EstaVacia()) throw ListaVacia();
    Elemento *porBorrar = primero;
    primero = primero->siguiente;
    primero->siguiente->anterior = nullptr;
    delete porBorrar;
    --tam;
    if(EstaVacia()) ultimo = nullptr;
}
//************************************************************************************
template <typename T>
void  ListaDoble2<T>::EliminarFinal()
{
    if(EstaVacia()) throw ListaVacia();
    Elemento *porBorrar = ultimo;
    ultimo->anterior->siguiente = nullptr;
    ultimo = ultimo->anterior;
    delete porBorrar;
    --tam;
    if(EstaVacia()) primero = nullptr;
}