#pragma once

#ifndef NODO_H
#define NODO_H

class Nodo
{
public:
	Nodo();
	Nodo(const char*, Nodo*, Nodo*);

	void setNombre(const char*);
	void setSiguiente(Nodo*);
	void setAnterior(Nodo*);

	char* getNombre();
	Nodo* getSiguiente();
	Nodo* getAnterior();

private:
	char* nombre;
	Nodo* siguiente;
	Nodo* anterior;
};

#endif // !NODO_H




