#include "ListaSimple.h"

#include <iostream>

using std::cout;

ListaSimple::ListaSimple() : primero(nullptr)
{}

bool ListaSimple::estaVacia() 
{
	return primero == nullptr;
}

void ListaSimple::agregarElemento(int _valor) 
{
	Nodo* nuevo = new Nodo(_valor, nullptr);

	if (estaVacia())
	{
		primero = nuevo;
		cout << "Nodo agregado!\n";
	}
	else
	{
		//recorrer la lista ubicando en el ultimo elemento

		Nodo* actual = primero;

		while ( actual->getSiguiente() != nullptr ) 
		{
			actual = actual->getSiguiente();
		}

		actual->setSiguiente(nuevo);
		cout << "Nodo agregado!\n";
	}
}

void ListaSimple::eliminaElemento(int _valor)
{
	if (estaVacia())
		return;

	Nodo* actual = primero;
	Nodo* anterior = nullptr;

	while (actual != nullptr) 
	{
		if (actual->getValor() == _valor)
		{
			if (actual == primero)
			{
				primero = actual->getSiguiente();
				delete actual;
			}
			else 
			{
				anterior->setSiguiente(actual->getSiguiente());
				delete actual;
			}
			cout << "Nodo eliminado!\n";
			return;
		}
		else
		{
			anterior = actual;
			actual = actual->getSiguiente();
		}

	}


}

void ListaSimple::imprimir() 
{
	if (estaVacia())
		return;

	Nodo* actual = primero;

	cout << "Elementos:\n";
	while (actual != nullptr) 
	{
		cout << "[ " << actual->getValor() << " ] ";
		actual = actual->getSiguiente();
	}

}