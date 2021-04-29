#pragma once

#ifndef RACIONAL_H
#define RACIONAL_H

class Racional 
{
public:
	Racional();
	Racional(int, int);

	void imprimirRacional();	// 1/2
	void imprimirDecimal();		// 0.5

	Racional suma(Racional);
	Racional resta(Racional);
	Racional multiplicacion(Racional);
	Racional division(Racional);
	Racional potencia(int);

private:
	int numerador, denominador;
	void simplificar();
};

#endif