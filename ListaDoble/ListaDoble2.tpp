
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
