#pragma once

#ifndef BYTE_H
#define BYTE_H

#include <iostream>

class Byte 
{
	//funciones no miembro sobrecargadas de la clase
	friend std::ostream& operator<<(std::ostream&, const Byte&);
	friend std::istream& operator>>(std::istream&, Byte&);

	friend Byte& operator+(const Byte&, const Byte&);
	friend Byte& operator-(const Byte&, const Byte&);

public:
	Byte();

	//se envia un arreglo de caracteres
	Byte(const char*);

	//destructor de clase
	~Byte();

	int obtenerDecimal();

	//sobrecarga de funciones miembro de la clase
	//operador negacion
	void operator~(void);

	//corrimiento de bits a la izquiersa 
	void operator<<(const int&);
	void operator>>(const int&);

private:
	int bits[8];
};


#endif // !BYTE_H
