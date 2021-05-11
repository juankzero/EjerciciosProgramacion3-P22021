#include "Cuenta.h"

#include <iostream>

using namespace std;

Cuenta::Cuenta(double _saldoInicial) :
	saldo(0)
{
	if (_saldoInicial > 0)
		saldo = _saldoInicial;
	else
		throw invalid_argument("+Saldo inicial no puede ser negativo!");
}

void Cuenta::abonar(double _cantidad)
{
	//deposito a la cuenta
	saldo += _cantidad;
}

bool Cuenta::cargar(double _cantidad)
{
	//retiro a la cuenta

	if (_cantidad > saldo)
	{
		cout << "+Cargo a la cuenta excede el saldo actual!\n";
		return false;
	}

	saldo -= _cantidad;
	return true;

}

void Cuenta::setSaldo(double _saldoActualizado)
{
	saldo = _saldoActualizado;
}

double Cuenta::getSaldo()
{
	return saldo;
}

void Cuenta::setNumeroCuenta(string _numeroCuenta)
{
	numeroCuenta = _numeroCuenta;
}

string Cuenta::getNumeroCuenta()
{
	return numeroCuenta;
}






