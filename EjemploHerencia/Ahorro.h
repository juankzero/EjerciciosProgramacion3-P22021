#pragma once

#ifndef AHORRO_H
#define AHORRO_H

#include "Cuenta.h"

//Clase ahorro hereda atributos y metodos publicos
//de clase cuenta
class Ahorro : public Cuenta
{
public:
	Ahorro(double, double);

	double calcularIntereses();

private:
	double tasaInteres;
};

#endif // !AHORRO_H
