#pragma once

#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Figura2D.h"

class Rectangulo : public Figura2D
{
public:
	Rectangulo();
	Rectangulo(int, int);

	//implementar las funciones abstractas de la clase padre
	float getArea();
	float getPerimetro();
	void imprimirFigura();

private:
	int base, altura;

};


#endif // !RECTANGULO_H



