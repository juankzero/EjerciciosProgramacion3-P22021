
#include "Racional.h"
#include <iostream>

#include <cmath>

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

	cout << "Forma Decimal: { " << float(this->numerador) / float(this->denominador) << " }\n";
}

void Racional::simplificar() 
{
	int mayor = this->numerador > this->denominador ? this->numerador : this->denominador;

	for (int i = 2; i <= mayor; i++) 
	{
		if (this->numerador % i == 0 && this->denominador % i == 0)
		{
			this->numerador = this->numerador / i;
			this->denominador = this->denominador / i;

			i = 1;
		}
	}

}

Racional Racional::suma(Racional r2) 
{
	//cuando ambos denominadores sean iguales
	if (this->denominador == r2.denominador)
		return Racional(this->numerador + r2.numerador, this->denominador);
	else
		return Racional((this->numerador * r2.denominador) + (r2.numerador * this->denominador),
			this->denominador * r2.denominador);
}

Racional Racional::resta(Racional r2) 
{
	//cuando ambos denominadores sean iguales
	if (this->denominador == r2.denominador)
		return Racional(this->numerador - r2.numerador, this->denominador);
	else
		return Racional((this->numerador * r2.denominador) - (r2.numerador * this->denominador),
			this->denominador * r2.denominador);

}

Racional Racional::multiplicacion(Racional r2)
{
	return Racional(this->numerador * r2.numerador, this->denominador * r2.denominador);
}

Racional Racional::division(Racional r2)
{
	return Racional(this->numerador * r2.denominador, r2.numerador * this->denominador);
}

Racional Racional::potencia(int exponente) 
{	
	return Racional( pow(this->numerador, exponente), pow(this->denominador, exponente) );
}

std::ostream& operator<<(std::ostream& cout, const Racional& r)
{
	cout << "{ " << r.numerador << "/" << r.denominador << ", " << float(r.numerador) / float(r.denominador) << " }\n";
	return cout;
}

Racional& operator+(const Racional& r1, const Racional& r2)
{
	Racional resultado;

	if (r1.denominador == r2.denominador)
	{
		resultado.numerador = r1.numerador + r2.numerador;
		resultado.denominador = r2.denominador;
	}
	else
	{
		resultado.numerador = (r1.numerador * r2.denominador) 
								+ (r2.numerador * r1.denominador);
		resultado.denominador = r1.denominador * r2.denominador;
	}

	return resultado;

}
