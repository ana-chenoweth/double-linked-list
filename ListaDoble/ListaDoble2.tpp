
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
//************************************************************************************
template <typename T>
void  ListaDoble2<T>::EliminarPos(int pos)
{
    if(EstaVacia()) throw  ListaVacia();
    if(pos<0 || pos >= tam) throw  FueraRango();
    if(pos==0) EliminarInicio();
    else if(pos==tam-1) EliminarFinal();
    else{
        Elemento *porBorrar = primero;
        for(int i = 1; i<pos; ++i) porBorrar = porBorrar->siguiente;
        porBorrar->anterior->siguiente = porBorrar->siguiente;
        porBorrar->siguiente->anterior = porBorrar->anterior;
        delete porBorrar;
        --tam;
    }
}
//*********************************************************************************************
template <typename T>
bool ListaDoble2<T>::BuscarValor(T valor) const
{
    Elemento *actual = primero;
    while(actual != nullptr){
        if(actual->valor == valor){
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}
//*********************************************************************************************
template <typename T>
int ListaDoble2<T>::BuscarPos(T valor) const
{
    Elemento *actual = primero;
    int pos;
    for(pos = 0; actual!= nullptr && actual->valor != valor; ++pos)
        actual = actual->siguiente;
    if(actual!= nullptr) return pos;
    else NO_ENCONTRADO;
}
//*********************************************************************************************
template <typename T>
bool ListaDoble2<T>::EstaVacia() const
{
    return tam==0;
}
//*********************************************************************************************
template <typename T>
T ListaDoble2<T>::ObtenerPrimero() const
{
    return primero->valor;
}
//*********************************************************************************************
template <typename T>
T ListaDoble2<T>::ObtenerUltimo() const
{
    return ultimo->valor;
}
//*********************************************************************************************
template <typename T>
T ListaDoble2<T>::ObtenerPorPos(int pos) const
{
    Elemento *actual = primero;
    for(int i = 0; actual!= nullptr && i<pos; ++i)
        actual = actual->siguiente;
    if(actual!= nullptr) return actual->valor;
    else throw "No se encuentra ese valor";
}
//*********************************************************************************************
template <typename T>
void ListaDoble2<T>::ModificarPos(T valor, int pos)
{
    if(EstaVacia()) throw ListaVacia();
    if(pos<0 || pos >= tam) throw FueraRango();
    Elemento *actual = primero;
    for(int i = 0; actual!= nullptr && i<pos; ++i)
        actual = actual->siguiente;
    if(actual!= nullptr) actual->valor = valor;
    else throw "Ocurrio un error al encontrar la posicion";
}
//*********************************************************************************************
template <typename T>
int ListaDoble2<T>::NumElementos() const
{
    return tam;
}
//*********************************************************************************************
template <typename T>
void ListaDoble2<T>::Vaciar()
{
    while(!EstaVacia()){
        EliminarFinal();
    }
}