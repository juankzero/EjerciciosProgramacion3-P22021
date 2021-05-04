#pragma once

#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>

class Racional 
{
	//definicion de funciones no miembro de clase
	friend std::ostream& operator<<(std::ostream&, const Racional&);
	friend Racional& operator+(const Racional&, const Racional&);

	friend Racional& operator-(const Racional&, const Racional&);
	friend Racional& operator*(const Racional&, const Racional&);
	friend Racional& operator/(const Racional&, const Racional&);
	friend Racional& operator^(const Racional&, const int&);

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