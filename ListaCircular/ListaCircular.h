#pragma once

#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include "Nodo.h"

class ListaCircular
{
public:
	ListaCircular();

	bool estaVacia();

	void agregarElemento(const char*);
	void eliminarElemento(int);

	void imprimir();

private:
	Nodo* primero;
	Nodo* ultimo;

};


#endif // LISTA_CIRCULAR_H



