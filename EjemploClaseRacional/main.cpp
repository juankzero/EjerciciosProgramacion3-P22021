#include <iostream>
#include <conio.h>


#include "Racional.h"

int main() 
{
	Racional r1(1, 2);
	Racional r2(3, 4);
	Racional r3(5, 2);

	Racional r4 = r1.resta(r2).suma(r3);

	r4.imprimirRacional();
	r4.imprimirDecimal();


	_getch();
}
