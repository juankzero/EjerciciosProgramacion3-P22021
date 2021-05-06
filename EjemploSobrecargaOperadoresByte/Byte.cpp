#include "Byte.h"

#include <cmath>

Byte::Byte()
{
	//inicializar todas las posiciones del byte en 0
	for (int i = 0; i < 8; i++) 
	{
		this->bits[i] = 0;
	}

}

// '0' -> 48
// '1' -> 49
Byte::Byte(const char* _byte)
{
	for (int i = 0; i < 8; i++) 
	{
		this->bits[i] = _byte[i] - 48;
	}

}

Byte::~Byte()
{
}

//Obtener el valor decimal del numero representado en el Byte
int Byte::obtenerDecimal()
{
	int resultado = 0;

	for (int i = 8 -1, pos = 0; i >= 0; i--, pos++) 
	{
		if (this->bits[i] == 1)
			resultado += pow(2, pos);
	}

	return resultado;

}

std::ostream& operator<<(std::ostream& cout, const Byte& b1)
{
	cout << "{ ";
	for (int i = 0; i < 8; i++) 
	{
		cout << b1.bits[i];
	}
	cout << " }\n";

	return cout;
}

Byte& operator+(const Byte& b1, const Byte& b2)
{
	Byte resultado;
	int acarreo = 0;

	for (int i = 8 - 1; i >= 0; i--) 
	{
		if (acarreo == 0)
		{
			if (b1.bits[i] == 1 && b2.bits[i] == 1)
			{
				resultado.bits[i] = 0;
				acarreo = 1;
			}
			else if (b1.bits[i] == 0 && b2.bits[i] == 0)
			{
				resultado.bits[i] = 0;
				acarreo = 0;
			}
			else // 1 + 0 || 0 + 1
			{
				resultado.bits[i] = 1;
				acarreo = 0;
			}
		}
		else //caso cuando exista acarreo
		{
			int resultadoAcarreo = 0;

			if (b1.bits[i] == 0)  // 1 + 0
			{
				resultadoAcarreo = 1;
				acarreo = 0;
			}
			else // 1 + 1
			{
				resultadoAcarreo = 0;
				acarreo = 1;
			}

			if (resultadoAcarreo == 1 && b2.bits[i] == 1)
			{
				resultado.bits[i] = 0;
				acarreo = 1;
			}
			else if (resultadoAcarreo == 0 && b2.bits[i] == 1)
				resultado.bits[i] = 1;
			else if (resultadoAcarreo == 0 && b2.bits[i] == 0)
				resultado.bits[i] = 0;
			else if (resultadoAcarreo == 1 && b2.bits[i] == 0)
			{
				resultado.bits[i] = 1;
				acarreo = 0;
			}
			else if (resultadoAcarreo == 1 && b2.bits[i] == 1)
			{
				resultado.bits[i] = 0;
				acarreo = 1;
			}

		}

	}

	return resultado;

}
