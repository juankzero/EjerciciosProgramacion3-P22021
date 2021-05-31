#include "ListaCircular.h"

ListaCircular::ListaCircular() : primero(nullptr), ultimo(nullptr)
{
}


bool ListaCircular::estaVacia()
{
    return primero == nullptr;
}

void ListaCircular::agregarElemento(const char* _nombre)
{
    Nodo* nuevo = new Nodo(_nombre, nullptr, nullptr);

    if (estaVacia())
    {
        primero = nuevo;
        ultimo = nuevo;
        //primero = ultimo = nuevo;
        primero->setAnterior(ultimo);
        ultimo->setSiguiente(primero);
    }
    else 
    {
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);

        ultimo = nuevo;

        ultimo->setSiguiente(primero);
        primero->setAnterior(ultimo);
    }


}
