#include <conio.h>

#include "Empresa.h"
#include <iostream>
#include "Empleado.h"

using std::cout;

int main() 
{
	//cout << "Tamanio de Empleado: " << sizeof(Empleado);


	//Empresa::agregarEmpleados();
	//Empresa::consultarEmpleados();

	Empresa::consultarEmpleado(4);

	_getch();
}