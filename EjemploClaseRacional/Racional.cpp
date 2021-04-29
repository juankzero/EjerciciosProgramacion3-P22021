
#include "Racional.h"
#include <iostream>

using std::cout;

Racional::Racional() : numerador(1), denominador(1)
{}

Racional::Racional(int _numerador, int _denominador) 
	:  numerador(_numerador), denominador(_denominador)
{
	simplificar();
}

//imprimir de la forma Racional 1/2
void Racional::imprimirRacional() 
{
	if (this->numerador == 0 && this->denominador == 0)
	{
		cout << "Resultado indefinido.\n";
		return;
	}

	if (this->denominador == 0)
	{
		cout << "No se puede dividir por cero\n";
		return;
	}

	cout << "Forma Racional: { " << this->numerador << "/" << this->denominador << " }\n";
}

//imprimir de la forma Decimal 1/2 = 0.5
void Racional::imprimirDecimal() 
{
	if (this->numerador == 0 && this->denominador == 0)
	{
		cout << "Resultado indefinido.\n";
		return;
	}

	if (this->denominador == 0)
	{
		cout << "No se puede dividir por cero\n";
		return;
	}

	cout << "Forma Decimal: { " << float(this->numerador) / float(this->denominador) << "}\n";
}

void Racional::simplificar() 
{}