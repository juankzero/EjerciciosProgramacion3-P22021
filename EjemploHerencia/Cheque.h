#pragma once

#ifndef CHEQUES_H
#define CHEQUES_H

#include "Cuenta.h"

class Cheque : public Cuenta
{
public:
	Cheque(double, double);

	//redefinir las funciones abonar y cargar
	void abonar(double);
	bool cargar(double);

private:
	double cuotaTransaccion;

	void cargarCuotaTransaccion();

};

#endif // !CHEQUES_H
