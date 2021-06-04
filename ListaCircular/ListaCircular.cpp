#include "ListaCircular.h"

#include <iostream>

using std::cout;

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

void ListaCircular::agregarOrden(const char* _nombre)
{
    Nodo* nuevo = new Nodo(_nombre, nullptr, nullptr);

    if (estaVacia())
    {
        primero = ultimo = nuevo;
        ultimo->setSiguiente(primero);
        primero->setAnterior(ultimo);
    }
    else
    {
        Nodo* actual = primero;

        do 
        {
            if (strcmp(_nombre, actual->getNombre()) < 0 && actual == primero)
            {
                nuevo->setSiguiente(primero);
                primero->setAnterior(nuevo);

                primero = nuevo;

                ultimo->setSiguiente(primero);
                primero->setAnterior(ultimo);

                cout << "Nodo insertado de forma ordenada!\n";
                return;
            }
            //insertar a la derecha y este seria el nuevo ultimo
            else if (strcmp(_nombre, actual->getNombre()) > 0 && actual == ultimo)
            {
                ultimo->setSiguiente(nuevo);
                nuevo->setAnterior(ultimo);

                ultimo = nuevo;

                ultimo->setSiguiente(primero);
                primero->setAnterior(ultimo);
                
                cout << "Nodo insertado de forma ordenada!\n";
                return;
            } //insertar en medio de la lista
            else if (strcmp(_nombre, actual->getNombre()) < 0)
            {
                actual->getAnterior()->setSiguiente(nuevo);
                nuevo->setAnterior(actual->getAnterior());

                nuevo->setSiguiente(actual);
                actual->setAnterior(nuevo);

                cout << "Nodo insertado de forma ordenada!\n";
                return;
            }

            actual = actual->getSiguiente();
                
        } while (actual != primero);


    }

}

void ListaCircular::eliminarElemento(int _posicion)
{
    if (estaVacia())
        return;

    Nodo* actual = primero;
    int posicionActual = 0;

    do 
    {
        if (posicionActual == _posicion)
        {
            if (actual == primero)
            {
                primero = actual->getSiguiente();
                primero->setAnterior(ultimo);
                ultimo->setSiguiente(primero);

                //delete actual;
            }
            else if (actual == ultimo)
            {
                ultimo = actual->getAnterior();
                ultimo->setSiguiente(primero);
                primero->setAnterior(ultimo);

                //delete actual;
            }
            else
            {
                actual->getAnterior()->setSiguiente(actual->getSiguiente());
                actual->getSiguiente()->setAnterior(actual->getAnterior());

                //delete actual;
            }

            delete actual;
            cout << "Nodo eliminado!\n";
            return;

        }

        actual = actual->getSiguiente();
        posicionActual++;


    } while (actual != primero);


}

void ListaCircular::imprimir()
{
    if (estaVacia())
        return;

    Nodo* actual = primero;

    cout << "Elementos:\n";
    do 
    {
        cout << "[ " << actual->getNombre() << " ] ";
        actual = actual->getSiguiente();

    } while (actual != primero);

    cout << std::endl;

}

void ListaCircular::imprimirReversa()
{
    if (estaVacia())
        return;

    Nodo* actual = ultimo;

    cout << "Elementos en Reversa:\n";
    do
    {
        cout << "[ " << actual->getNombre() << " ] ";
        actual = actual->getAnterior();

    } while (actual != ultimo);

    cout << std::endl;
}
