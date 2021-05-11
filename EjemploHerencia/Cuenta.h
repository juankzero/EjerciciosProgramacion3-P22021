#pragma once

#ifndef CUENTA_H
#define CUENTA_H

#include <string>
#include <iostream>

using std::string;

class Cuenta 
{
public:
	Cuenta(double);

	void abonar(double);
	bool cargar(double);

	
	void setSaldo(double);
	double getSaldo();

	void setNumeroCuenta(string);
	string getNumeroCuenta();

private:
	string numeroCuenta;
	double saldo;
};

#endif // !CUENTA_H
