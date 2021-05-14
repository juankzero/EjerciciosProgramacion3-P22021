#include "TrianguloRectangulo.h"

#include <iostream>

using std::cout;
#include <cmath>

TrianguloRectangulo::TrianguloRectangulo() : Rectangulo(), hipotenusa(0)
{
	setHipotenusa();
}

TrianguloRectangulo::TrianguloRectangulo(int _base, int _altura)
	: Rectangulo(_base, _altura), hipotenusa(0)
{
	setHipotenusa();
}

float TrianguloRectangulo::getArea() 
{
	return (this->base * this->altura) / 2;
}

void TrianguloRectangulo::setHipotenusa() 
{
	hipotenusa = sqrt(pow(base, 2) + pow(altura, 2));
}

float TrianguloRectangulo::getPerimetro() 
{
	return this->base + this->altura + this->hipotenusa;
}

void TrianguloRectangulo::imprimirFigura() 
{
	cout << "TrianguloRectangulo { base: " << this->base << ", altura: "
		<< this->altura << ", hipotenusa: " << this->hipotenusa
		<< ", area: " << getArea() << ", perimetro: " << getPerimetro() << " }\n";

}

TipoFigura TrianguloRectangulo::obtenerInstancia()
{
	return TipoFigura::tTrianguloRectangulo;
}
