#pragma once

#ifndef BYTE_H
#define BYTE_H

#include <iostream>

class Byte 
{
	friend std::ostream& operator<<(std::ostream&, const Byte&);
	friend Byte& operator+(const Byte&, const Byte&);
	friend Byte& operator-(const Byte&, const Byte&);

public:
	Byte();

	//se envia un arreglo de caracteres
	Byte(const char*);

	//destructor de clase
	~Byte();

	int obtenerDecimal();

private:
	int bits[8];
};


#endif // !BYTE_H
