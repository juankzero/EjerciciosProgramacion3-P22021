#include <iostream>
#include <conio.h>


#include "Racional.h"

int main() 
{
	Racional r1(1, 2);
	Racional r2(2, 3);

	Racional r3 = r1.multiplicacion(r2).potencia(3);

	r3.imprimirRacional();
	r3.imprimirDecimal();

	

	_getch();
}
