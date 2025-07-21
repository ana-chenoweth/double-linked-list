
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