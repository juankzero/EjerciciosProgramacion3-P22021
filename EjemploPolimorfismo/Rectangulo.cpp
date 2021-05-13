#include "Rectangulo.h"

#include <iostream>

using namespace std;

Rectangulo::Rectangulo() : base(1), altura(1)
{}

Rectangulo::Rectangulo(int _base, int _altura) 
	: base(_base), altura(_altura)
{
	if (_base <= 0 || _altura <= 0)
	{
		base = altura = 1;
		throw invalid_argument("Base y altura deben ser > 0\n");
	}
}

float Rectangulo::getArea() 
{
	return this->base * this->altura;
}

float Rectangulo::getPerimetro() 
{
	return 2 * (this->base + this->altura);
}

void Rectangulo::imprimirFigura() 
{
	cout << "Rectangulo { base: " << this->base << ", altura: "
		<< this->altura << ", area: " << getArea() << ", perimetro: "
		<< getPerimetro() << " }\n";
}