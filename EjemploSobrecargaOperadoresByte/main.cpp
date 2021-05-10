
#include <conio.h>

#include <iostream>
#include "Byte.h"


using std::cout;
using std::cin;

int main() 
{
	/*
	Byte b1("01101100"); //
	Byte b2("00101100"); //

	cout << "b1: " << b1;
	cout << "b2: " << b2;

	Byte b3 = b1 + b2;

	cout << "b3: " << b3; //
	cout << "b3 decimal: " << b3.obtenerDecimal(); // 
	*/

	Byte b4;
	Byte b5;

	cout << "Ingrese un valor binario 1: ";
	cin >> b4;

	cout << "Ingrese un valor binario 2: ";
	cin >> b5;

	Byte b6 = b4 + b5;

	cout << "Resultado de suma: " << b6;
	cout << "Valor Decimal de suma: " << b6.obtenerDecimal() << "\n";

	//negacion
	~b6;

	//corrimiento de bits a la izquierda
	b6 << 2;

	//corrimiento de bits a la derecha
	b6 >> 2;


	cout << "Negacion de Byte: " << b6;


	_getch();
}