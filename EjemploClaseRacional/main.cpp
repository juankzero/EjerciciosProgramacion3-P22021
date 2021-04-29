#include <iostream>
#include <conio.h>


#include "Racional.h"

int main() 
{
	Racional r1;
	Racional r2(1, 2);
	Racional r3(8, 5);

	r1.imprimirRacional();
	r1.imprimirDecimal();

	r2.imprimirRacional();
	r2.imprimirDecimal();

	r3.imprimirRacional();
	r3.imprimirDecimal();



	_getch();
}
