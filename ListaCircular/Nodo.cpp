#include "Nodo.h"

#include <iostream>

Nodo::Nodo() : nombre(nullptr), siguiente(nullptr), anterior(nullptr)
{
}

Nodo::Nodo(const char* _nombre, Nodo* _anterior, Nodo* _siguiente)
	: anterior(_anterior), siguiente(_siguiente)
{
	//reservar el espacio de memoria de nombre con la cantidad
	//de caracteres a insertar
	nombre = new char[strlen(_nombre)];
	
	//asignar el bloque de caracteres a la cadena
	strcpy_s(nombre, strlen(_nombre) + 1, _nombre);

}

void Nodo::setNombre(const char* _nombre)
{
	//liberar la memoria asignada a nombre
	delete nombre;

	nombre = new char[strlen(_nombre)];
	strcpy_s(nombre, strlen(_nombre) + 1, _nombre);
}

void Nodo::setSiguiente(Nodo* _siguiente)
{
	this->siguiente = _siguiente;
}

void Nodo::setAnterior(Nodo* _anterior) 
{
	this->anterior = _anterior;
}

char* Nodo::getNombre()
{
	return this->nombre;
}

Nodo* Nodo::getSiguiente()
{
	return this->siguiente;
}

Nodo* Nodo::getAnterior() 
{
	return this->anterior;
}