#include <conio.h>

#include <iostream>

using namespace std;

//#include "Cuenta.h"
#include "Cheque.h"
#include "Ahorro.h"

int main() 
{

	Cuenta c1(100);
	Ahorro a1(100, 0.03); //3% de tasa de interes
	Cheque ch1(100, 20);

	cout << "c1 saldo: " << c1.getSaldo() << "\n";
	cout << "h1 saldo: " << a1.getSaldo() << "\n";
	cout << "ch1 saldo: " << ch1.getSaldo() << "\n";

	cout << "Intentando abonar  desde c1\n";
	c1.abonar(700);
	cout << "Intentando abonar  desde a1\n";
	a1.abonar(300);
	cout << "Intentando abonar  desde ch1\n";
	ch1.abonar(1200);

	cout << "c1 saldo: " << c1.getSaldo() << "\n";
	cout << "h1 saldo: " << a1.getSaldo() << "\n";
	cout << "ch1 saldo: " << ch1.getSaldo() << "\n";

	cout << "Intentando cargar desde c1\n";
	c1.cargar(1000);
	cout << "Intentando cargar desde a1\n";
	a1.cargar(200);
	cout << "Intentando cargar desde ch1\n";
	ch1.cargar(600);

	cout << "c1 saldo: " << c1.getSaldo() << "\n";
	cout << "h1 saldo: " << a1.getSaldo() << "\n";
	cout << "ch1 saldo: " << ch1.getSaldo() << "\n";

	//Calculo de intereses

	double intereses = a1.calcularIntereses();
	cout << "Agregando L" << intereses << " interes a a1\n";
	a1.abonar(intereses);

	cout << "Nuevo saldo de cuenta a1: " << a1.getSaldo() << "\n";

	_getch();
}