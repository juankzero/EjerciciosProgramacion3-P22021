#pragma once

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct InformacionTabla 
{
	int cantidadCampos;
	int cantidadRegistros;
};

enum TipoCampo 
{
	t_Entero,
	t_Cadena,
	t_Caracter,
	t_Decimal,
	t_Logico
};

struct InformacionCampo 
{
	char nombreCampo[20];
	TipoCampo tipo;
};


struct RegistroEntero 
{
	int valor;
};

struct RegistroCadena 
{
	char valor[100];
};

struct RegistroDecimal 
{
	float valor;
};

struct RegistroCaracter 
{
	char valor;
};

struct RegistroLogico 
{
	bool valor;
};

void crearConjunto();
void leerConjunto();
void agregarRegistro();

#endif // !ESTRUCTURAS_H
