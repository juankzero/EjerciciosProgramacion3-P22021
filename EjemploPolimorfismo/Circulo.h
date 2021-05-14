#pragma once

#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura2D.h"

class Circulo : public Figura2D
{
public:
	Circulo();
	Circulo(float);

	//implementar las funciones abstractas de Figura2D
	float getArea();
	float getPerimetro();
	void imprimirFigura();

	TipoFigura obtenerInstancia();

private:
	float radio;
};


#endif // !CIRCULO_H



