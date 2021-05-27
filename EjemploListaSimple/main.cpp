#include <conio.h>

#include "ListaSimple.h"

int main() 
{
	ListaSimple ls;

	ls.agregarElemento(7);
	ls.agregarElemento(3);
	ls.agregarElemento(9);
	ls.agregarElemento(2);
	ls.agregarElemento(1);
	ls.agregarElemento(4);

	ls.imprimir();

	ls.eliminaElemento(7);

	ls.imprimir();

	ls.eliminaElemento(4);

	ls.imprimir();

	ls.eliminaElemento(9);
	
	ls.imprimir();


	_getch();
}