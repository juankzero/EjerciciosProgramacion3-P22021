
#include <conio.h>

#include <iostream>
#include "Byte.h"


using std::cout;

int main() 
{
	Byte b1("01101100"); //
	Byte b2("00101100"); //

	cout << "b1: " << b1;
	cout << "b2: " << b2;

	Byte b3 = b1 + b2;

	cout << "b3: " << b3; //
	cout << "b3 decimal: " << b3.obtenerDecimal(); // 

	_getch();
}