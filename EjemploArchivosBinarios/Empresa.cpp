#include "Empresa.h"

#include <fstream>
#include <iostream>

using std::ifstream; //lectura
using std::ofstream; //escritura
using std::ios;
using std::cout;
using std::cin;

#include "Empleado.h"

//using namespace std;

void Empresa::agregarEmpleados()
{
	ofstream empleadosFile("empleados.bin", ios::out | ios::binary | ios::app);
	
	//out -> escritura
	//binary -> forma de escritura
	//app -> agregar bytes al final del archivo (append)

	if (!empleadosFile)
	{
		cout << "Error: Imposible abrir archivo empleados.bin\n";
		return;
	}

	cout << " *** A G R E G A R  E M P L E A D O S ***\n\n";

	cout << "Indique cantidad de empleados a agregar: ";
	int cantidad;
	cin >> cantidad;

	int codigo;
	char nombre[20];
	char genero;
	float salario;

	Empleado nuevo;

	for (int i = 0; i < cantidad; i++) 
	{
		cout << "Empleado " << (i + 1) << ":\n";
		
		cout << "Ingrese codigo: ";
		cin >> codigo;
		nuevo.setCodigo(codigo);

		cout << "Ingrese nombre: ";
		cin >> nombre;
		nuevo.setNombre(nombre);

		cout << "Ingrese genero (F-> Femenino | M-> Masculino): ";
		cin >> genero;
		nuevo.setGenero(genero);

		cout << "Ingrese salario: ";
		cin >> salario;
		nuevo.setSalario(salario);

		nuevo.setEstado(true);

		empleadosFile.write(reinterpret_cast<const char*>(&nuevo), sizeof(Empleado));
		cout << "Empleado agregado!\n\n";

	}

	empleadosFile.close();
}

void Empresa::consultarEmpleados()
{
	ifstream empleadosFile("empleados.bin", ios::in | ios::binary);

	if (!empleadosFile)
	{
		cout << "Error: Imposible abrir archivo empleados.bin\n";
		return;
	}
		
	cout << " *** C O N S U L T A  D E  E M P L E A D O S ***\n\n";

	Empleado lectura;

	//posicionarse al inicio del archivo
	empleadosFile.seekg(0, ios::beg);

	//tellg -> devuelva la direccion de memoria en que se encuenta el cursor de 
	//lectura del archivo
	cout << "Posicion actual: " << empleadosFile.tellg() << "\n";

	empleadosFile.read(reinterpret_cast<char*>(&lectura), sizeof(Empleado));

	while (!empleadosFile.eof()) 
	{
		cout << "Posicion actual: " << empleadosFile.tellg() << "\n";

		cout << "Empleado { codigo: " << lectura.getCodigo()
			<< ", nombre: " << lectura.getNombre()
			<< ", genero: " << lectura.getGenero()
			<< ", salario: " << lectura.getSalario()
			<< ", estado: " << lectura.getEstado() << " }\n";
		empleadosFile.read(reinterpret_cast<char*>(&lectura), sizeof(Empleado));
	}
	
	cout << "Posicion actual: " << empleadosFile.tellg() << "\n";

	empleadosFile.close();

}

void Empresa::consultarEmpleado(int posicion) 
{
	ifstream empleadosFile("empleados.bin", ios::in | ios::binary);

	if (!empleadosFile)
	{
		cout << "Error: Imposible abrir archivo empleados.bin\n";
		return;
	}

	//posicionar en byte para lectura
	empleadosFile.seekg((posicion - 1)* sizeof(Empleado), ios::beg);

	Empleado lectura;
	empleadosFile.read(reinterpret_cast<char*>(&lectura), sizeof(Empleado));

	cout << "Empleado { codigo: " << lectura.getCodigo()
		<< ", nombre: " << lectura.getNombre()
		<< ", genero: " << lectura.getGenero()
		<< ", salario: " << lectura.getSalario()
		<< ", estado: " << lectura.getEstado() << " }\n";

	empleadosFile.close();

}


