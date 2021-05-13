#pragma once

#ifndef TRIANGULORECTANGULO_H
#define TRIANGULORECTANGULO_H

#include "Rectangulo.h"

class TrianguloRectangulo : public Rectangulo 
{
public:
	TrianguloRectangulo();
	TrianguloRectangulo(int, int);

	float getArea();
	float getPerimetro();
	void imprimirFigura();

private:
	float hipotenusa;

	void setHipotenusa();
};

#endif // !TRIANGULORECTANGULO_H




