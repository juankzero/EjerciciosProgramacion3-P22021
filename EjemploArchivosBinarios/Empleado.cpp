#include "Empleado.h"

#include <iostream>

Empleado::Empleado() 
	: codigo(0), nombre("ND"), genero('N'), salario(0), estado(false)
{
}

int Empleado::getCodigo()
{
	return codigo;
}

char* Empleado::getNombre()
{
	return nombre;
}

char Empleado::getGenero()
{
	return genero;
}

float Empleado::getSalario()
{
	return salario;
}

bool Empleado::getEstado()
{
	return estado;
}

void Empleado::setCodigo(int _c)
{
	codigo = _c;
}

void Empleado::setNombre(char _n[])
{
	strcpy_s(nombre, strlen(_n) + 1, _n);
}

void Empleado::setGenero(char _g)
{
	genero = _g;
}

void Empleado::setSalario(float _s)
{
	salario = _s;
}

void Empleado::setEstado(bool _e)
{
	estado = _e;
}
