
#include <conio.h>
#include <iostream>

using std::cout;

int cuboPorValor(int);
void cuboPorReferencia(int*);

int main() 
{
	/*
	int x = 5;
	int* xPtr = nullptr;

	
	cout << "Direccion de memoria de x: " << & x << "\n";
	cout << "Direccion de memoria de xPtr: " << xPtr << "\n";
	cout << "Contenido de x: " << x << "\n";
	
	xPtr = &x;

	cout << "Direccion de memoria de x: " << &x << "\n";
	cout << "Direccion de memoria de xPtr: " << xPtr << "\n";
	cout << "Contenido de x: " << x << "\n";
	cout << "Contenido de xPtr: " << *xPtr << "\n";

	*xPtr = 8;

	cout << "Contenido de x: " << x << "\n";
	cout << "Contenido de xPtr: " << *xPtr << "\n";

	*xPtr = 20;

	cout << "Contenido de x: " << x << "\n";
	cout << "Contenido de xPtr: " << *xPtr << "\n";

	x = 13;

	cout << "Contenido de x: " << x << "\n";
	cout << "Contenido de xPtr: " << *xPtr << "\n";
	*/

	
	int base = 3;

	int* basePTr = &base;


	cout << "Direccion de memoria de base: " << &base << "\n";


	int resultado = cuboPorValor(base);

	cout << "Contenido de base: " << base << "\n";
	cout << "Contenido de resultado: " << resultado << "\n";


	int baseRef = 5;

	cout << "Contenido de baseRef: " << baseRef << "\n";
	cout << "Direccion de memoria de baseRef: " << &baseRef << "\n";

	cuboPorReferencia( &baseRef );

	cout << "Contenido de baseRef: " << baseRef << "\n";
	cout << "Direccion de memoria de baseRef: " << &baseRef << "\n";


	char nombre;

	basePTr = &baseRef;

	_getch();
}

int cuboPorValor(int base) 
{
	cout << "Direccion de memoria de base en funcion: " << &base << "\n";
	return base * base * base;
}

void cuboPorReferencia(int* base)
{
	cout << "Direccion de memoria de baseRef en funcion: " << base << "\n";
	*base = *base * *base * *base;
}