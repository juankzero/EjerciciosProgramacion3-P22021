
#include <iostream>
#include <conio.h>

int main() 
{
	std::cout << "***  S U M A  D E  N U M E R O S ***\n\n";

	//declaracion de variables
	int numero1, numero2, suma;
	
	//inicializar variables
	numero1 = numero2 = suma = 0;

	std::cout << "Ingrese numero 1: ";
	std::cin >> numero1;

	std::cout << "Ingrese numero 2: ";
	std::cin >> numero2;

	suma = numero1 + numero2;

	std::cout << "La suma es: " << suma << std::endl;

	_getch();
}