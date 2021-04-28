
//incluir archivo de definicion de clase
#include "Rectangulo.h"
#include <iostream>

using std::cout;

//implementacion de constructores
Rectangulo::Rectangulo() : base(0), altura(0)
{
	//codigo c++ adicional
}

Rectangulo::Rectangulo(int _base, int _altura) : base(_base), altura(_altura)
{}


//implementacion de metodos sets y gets
void Rectangulo::setBase(int _base) 
{
	this->base = _base;
}

void Rectangulo::setAltura(int _altura) 
{
	this->altura = _altura;
}

int Rectangulo::getBase() 
{
	return this->base;
}


int Rectangulo::getAltura() 
{
	return this->altura;
}

int Rectangulo::getArea() 
{
	return this->base * this->altura;
}

int Rectangulo::getPerimetro() 
{
	return 2 * (this->base + this->altura);
}

void Rectangulo::imprimir() 
{
	cout << "Rectangulo: { base: " << getBase() << ", altura: " << getAltura()
		<< ", area: " << getArea() << ", perimetro: " << getPerimetro() << " }\n";
}