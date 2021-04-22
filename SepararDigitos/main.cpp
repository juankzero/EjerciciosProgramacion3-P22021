#include <iostream>
#include <conio.h>

using std::cout;
using std::cin;

int main() 
{
	cout << "***  S E P A R A R  D I G I T O S ***\n\n";

	int numero = 0;
	cout << "Ingrese un numero de 5 digitos: ";
	cin >> numero;

	int divisor = 10000;

	cout << "Digitos { ";

	int tmp = numero;

	for (int i = 0; i < 5; i++) 
	{
		cout << tmp / divisor << "  ";
		tmp %= divisor;
		divisor /= 10;
	}

	cout << "}\n";

	_getch();
}

