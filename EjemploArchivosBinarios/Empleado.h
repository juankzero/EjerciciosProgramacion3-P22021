#pragma once

#ifndef EMPLEADO_H
#define EMPLEADO_H

class Empleado
{
public:
	Empleado();

	int getCodigo();
	char* getNombre();
	char getGenero();
	float getSalario();
	bool getEstado();

	void setCodigo(int);
	void setNombre(char[]);
	void setGenero(char);
	void setSalario(float);
	void setEstado(bool);

private:
	int codigo; //4 bytes
	char nombre[20]; //20 bytes
	char genero; // 1 byte
	float salario; //4 bytes
	bool estado; //1 byte
};

#endif // !EMPLEADO_H

