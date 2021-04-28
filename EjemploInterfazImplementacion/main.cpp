
#include <iostream>
#include <conio.h>

#include "Rectangulo.h"


int main() 
{
	Rectangulo r1;
	Rectangulo r2(5, 3);

	r1.imprimir();
	r2.imprimir();

	r1.setBase(8);
	r1.setAltura(2);

	r1.imprimir();

	_getch();
}