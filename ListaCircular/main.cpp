
#include <conio.h>

#include "ListaCircular.h"

int main() 
{
	ListaCircular lc;

	lc.agregarOrden("Juan");
	lc.agregarOrden("Eduardo");
	lc.agregarOrden("Francisco");
	lc.agregarOrden("Luis");
	lc.agregarOrden("Ana");


	lc.imprimir();
	lc.imprimirReversa();

	
	_getch();
}