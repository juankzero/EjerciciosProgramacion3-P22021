#include <conio.h>

#include "Rectangulo.h"
#include "Circulo.h"
#include "TrianguloRectangulo.h"

#include "Figura2D.h"

int main() 
{
	Rectangulo r1(6, 3);
	Circulo c1(6.3);
	TrianguloRectangulo tr1(8, 2);


	r1.imprimirFigura();
	c1.imprimirFigura();
	tr1.imprimirFigura();

	/*
	Figura2D array[5];
	Figura2D f1;*/

	_getch();
}