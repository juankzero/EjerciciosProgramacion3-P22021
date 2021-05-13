#include "Circulo.h"

#include <iostream>
using namespace std;

#define PI 3.14159265358979323846264


Circulo::Circulo() : radio(1)
{
}

Circulo::Circulo(float _radio) : radio(_radio)
{
	if (_radio <= 0)
	{
		radio = 1;
		throw invalid_argument("Radio de Circulo debe ser > 0\n");
	}
}

float Circulo::getArea()
{
	return PI * pow(radio, 2);
}

float Circulo::getPerimetro() 
{
	return 2 * PI * radio;
}

void Circulo::imprimirFigura()
{
	cout << "Circulo { radio: " << this->radio << ", area: "
		<< getArea() << ", perimetro: " << getPerimetro() << " }\n";
}
