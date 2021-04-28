#pragma once

#ifndef RECTANGULO_H
#define RECTANGULO_H

//definicion de clase
class Rectangulo 
{
public:
	//prototipos de contructores
	Rectangulo();
	Rectangulo(int, int);

	void setBase(int);
	void setAltura(int);

	int getBase();
	int getAltura();

	int getPerimetro();
	int getArea();

	void imprimir();


private:
	int base, altura;
};

#endif // !RECTANGULO_H

