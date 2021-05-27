#pragma once

#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include "Nodo.h"

class ListaSimple
{
public:
	ListaSimple();

	bool estaVacia();

	void agregarElemento(int);
	void eliminaElemento(int);

	void imprimir();

private:
	Nodo* primero;

};

#endif // !LISTA_SIMPLE_H




