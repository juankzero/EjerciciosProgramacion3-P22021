#include "Ahorro.h"

#include <iostream>
using namespace std;

Ahorro::Ahorro(double _saldoInicial, double _tasaInteres)
	: Cuenta(_saldoInicial), tasaInteres(_tasaInteres)
{
	if (_tasaInteres >= 0)
		tasaInteres = _tasaInteres;
	else
		throw invalid_argument("+Tasa de interes debe ser mayor a cero!\n");

}

double Ahorro::calcularIntereses()
{
	return getSaldo() * tasaInteres;
}
