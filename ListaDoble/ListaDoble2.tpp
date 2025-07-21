
//****************************************************************************************
template <typename T>
ListaDoble2<T>::ListaDoble2(): tam(0), primero(nullptr), ultimo(nullptr)
{

}
//****************************************************************************************
template <typename T>
ListaDoble2<T>& ListaDoble2<T>::operator=(const ListaDoble2& l) {
    if (this == &l)
        return *this;

    Vaciar();

    Elemento* actual = l.primero;
    while (actual != nullptr) {
        AgregarFinal(actual->valor);
        actual = actual->siguiente;
    }

    return *this;
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
//*********************************************************************************************
template <typename T>
void ListaDoble2<T>::Imprimir() const
{
    Elemento *actual = primero;
    while(actual != nullptr){
        std::cout << actual->valor << ", ";
        actual = actual->siguiente;
    }
}
//*********************************************************************************************
template <typename T>
void ListaDoble2<T>::ImprimirReversa() const
{
    Elemento *actual = ultimo;
    while(actual != nullptr){
        std::cout << actual->valor << ", ";
        actual = actual->anterior;
    }
}
//***********************************************************************************************
template <typename T>
T& ListaDoble2<T>::operator[](int pos)
{
    if (pos < 0 || pos >= tam)
        throw  FueraRango();

    Elemento* actual = primero;
    for (int i = 0; i < pos; ++i)
        actual = actual->siguiente;

    return actual->valor;
}
//***********************************************************************************************
template <typename T>
const T& ListaDoble2<T>::operator[](int pos) const
{
    if (pos < 0 || pos >= tam)
        throw  FueraRango();

    Elemento* actual = primero;
    for (int i = 0; i < pos; ++i)
        actual = actual->siguiente;

    return actual->valor;
}
//*********************************************************************************************
template <typename T>
void ListaDoble2<T>::Intercambiar(ListaDoble2<T> &lista) {
    Elemento* tempPrimero = primero;
    primero = lista.primero;
    lista.primero = tempPrimero;

    Elemento* tempUltimo = ultimo;
    ultimo = lista.ultimo;
    lista.ultimo = tempUltimo;

    int tempTam = tam;
    tam = lista.tam;
    lista.tam = tempTam;
}
//*********************************************************************************************
template <typename T>
void ListaDoble2<T>::TransferirRango(ListaDoble2<T>& l, int posInicio, int posFin)
{
    if (posInicio < 0 || posFin >= l.NumElementos() || posInicio > posFin) {
        throw FueraRango();
    }

    // Encuontramos el inicio del rango en la lista original
    Elemento* inicio = l.primero;
    for (int i = 0; i < posInicio; ++i) {
        inicio = inicio->siguiente;
    }

    // Encuontramos el fin del rango en la lista original
    Elemento* fin = inicio;
    for (int i = posInicio; i < posFin; ++i) {
        fin = fin->siguiente;
    }

    // Transferimos los elementos del rango a esta lista
    for (Elemento* actual = inicio; actual != fin->siguiente; actual = actual->siguiente) {
        AgregarFinal(actual->valor);
    }

    // Actualizamos los punteros de la lista original si se transfieren todos los elementos
    if (posInicio == 0) {
        l.primero = fin->siguiente;
    }
    if (posFin == l.NumElementos() - 1) {
        l.ultimo = inicio->anterior;
    }

    // Eliminamos los elementos transferidos de la lista original
    inicio->anterior->siguiente = fin->siguiente;
    fin->siguiente->anterior = inicio->anterior;
    for (Elemento* actual = inicio; actual != fin->siguiente;) {
        Elemento* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}
//*********************************************************************************************
template <typename T>
void ListaDoble2<T>::TransferirTodos(ListaDoble2<T>& l) {
    Elemento* actual = l.primero;
    while (actual != nullptr) {
        AgregarFinal(actual->valor);
        Elemento* temp = actual;
        actual = actual->siguiente;
        delete temp; // Eliminamos el elemento transferido de la lista original
    }
    l.primero = nullptr; // La lista original queda vac�a
    l.ultimo = nullptr;
    l.tam = 0;
}
//*********************************************************************************************************
template <typename T>
void ListaDoble2<T>::TransferirDesde(ListaDoble2<T>& l, int posInicio) {
    if (posInicio < 0) {
        throw FueraRango();
    }

    Elemento* inicio = l.primero;
    for (int i = 0; i < posInicio; ++i) {
        if (inicio == nullptr) {
            throw FueraRango();
        }
        inicio = inicio->siguiente;
    }

    Elemento* actual = inicio;
    while (actual != nullptr) {
        AgregarFinal(actual->valor);
        Elemento* temp = actual;
        actual = actual->siguiente;
        delete temp; // Eliminamos el elemento transferido de la lista original
    }
    l.primero = nullptr; // La lista original queda vac�a
    l.ultimo = nullptr;
    l.tam = 0;
}
//****************************************************************************************
template <typename T>
void ListaDoble2<T>::EliminarRepetidos() {
    if (tam <= 1) return;
    Elemento* actual = primero;

    while (actual != nullptr) {
        T valorActual = actual->valor;

        Elemento* siguiente = actual->siguiente;
        while (siguiente != nullptr) {
            if (siguiente->valor == valorActual) {
                Elemento* porEliminar = siguiente;
                siguiente = siguiente->siguiente;

                if (porEliminar->anterior != nullptr) {
                    porEliminar->anterior->siguiente = porEliminar->siguiente;
                }
                if (porEliminar->siguiente != nullptr) {
                    porEliminar->siguiente->anterior = porEliminar->anterior;
                }

                if (porEliminar == ultimo) {
                    ultimo = porEliminar->anterior;
                }

                delete porEliminar;
                --tam;
            } else {
                siguiente = siguiente->siguiente;
            }
        }

        actual = actual->siguiente;
    }
}
//***************************************************************************************************************
template <typename T>
void ListaDoble2<T>::EliminarTodasOcurrencias(T valor)
{
    Elemento* actual = primero;

    // Buscamos la primera ocurrencia del valor
    while (actual != nullptr && actual->valor != valor) {
        actual = actual->siguiente;
    }

    // Si se encontr� el valor, eliminamos las ocurrencias adicionales
    if (actual != nullptr) {
        Elemento* porEliminar = actual->siguiente;

        while (porEliminar != nullptr) {
            if (porEliminar->valor == valor) {
                Elemento* temp = porEliminar;
                porEliminar = porEliminar->siguiente;

                // Actualizamos punteros de los elementos adyacentes
                if (temp->anterior != nullptr) {
                    temp->anterior->siguiente = temp->siguiente;
                }
                if (temp->siguiente != nullptr) {
                    temp->siguiente->anterior = temp->anterior;
                }

                // Actualizamos punteros 'primero' y 'ultimo' si se elimin� el primer o �ltimo elemento
                if (temp == primero) {
                    primero = temp->siguiente;
                }
                if (temp == ultimo) {
                    ultimo = temp->anterior;
                }

                delete temp;
                --tam;
            } else {
                porEliminar = porEliminar->siguiente;
            }
        }
    }
}
//***************************************************************************************************************
template <typename T>
void ListaDoble2<T>::EliminarConCondicion(bool (*condicion)(T)) {
    Elemento* actual = primero;

    while (actual != nullptr) {
        Elemento* porEliminar = actual;
        actual = actual->siguiente;

        if (condicion(porEliminar->valor)) {
            // Actualizar punteros de los elementos adyacentes
            if (porEliminar->anterior != nullptr) {
                porEliminar->anterior->siguiente = porEliminar->siguiente;
            }
            if (porEliminar->siguiente != nullptr) {
                porEliminar->siguiente->anterior = porEliminar->anterior;
            }

            // Actualizar punteros 'primero' y 'ultimo' si se elimin� el primer o �ltimo elemento
            if (porEliminar == primero) {
                primero = porEliminar->siguiente;
            }
            if (porEliminar == ultimo) {
                ultimo = porEliminar->anterior;
            }

            delete porEliminar;
            --tam;
        }
    }
}
//****************************************************************************************************************
template <typename T>
void ListaDoble2<T>::OrdenarAscendente()
{
    if (tam <= 1) return;  // No es necesario ordenar si la lista tiene 0 o 1 elemento

    bool intercambio = true;
    while (intercambio) {
        intercambio = false;
        Elemento* actual = primero;
        while (actual->siguiente != nullptr) {
            if (actual->valor > actual->siguiente->valor) {
                // Intercambiamos los valores de los elementos
                T temp = actual->valor;
                actual->valor = actual->siguiente->valor;
                actual->siguiente->valor = temp;
                intercambio = true;
            }
            actual = actual->siguiente;
        }
    }
}
//****************************************************************************************************************
template <typename T>
const char *ListaDoble2<T>::ListaVacia::what() const throw() {
  return "Lista vac\241a";
}
//****************************************************************************************************************
template <typename T>
const char *ListaDoble2<T>::FueraRango::what() const throw() {
  return "Fuera de rango";
}
