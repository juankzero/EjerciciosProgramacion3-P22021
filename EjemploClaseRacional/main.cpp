#include <iostream>
#include <conio.h>

using std::cout;

#include "Racional.h"

int main() 
{
	Racional r1(1, 3);
	Racional r2(2, 5);

	cout << r1;
	cout << r2;

	Racional r3 = r1 + r2;

	Racional r4 = r3 - r1;
	Racional r5 = r4 * r2;
	Racional r6 = r5 ^ 3;
	Racional r7 = r1 / r2;

	cout << r3;

	

	_getch();
}
