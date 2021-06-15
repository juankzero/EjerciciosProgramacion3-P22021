#include "Universidad.h"

#include <iostream>
#include <fstream>

using namespace std;

void Universidad::agregarAlumnos() 
{
	cout << "***  I N G R E S O  A L U M N O S ***\n\n";

	ofstream archivoAlumnos("alumnos.dat", ios::app);

	if (!archivoAlumnos)
	{
		cout << "Error al intentar abrir el archivo alumnos.dat\n";
		return;
	}

	cout << "Indica la cantidad de alumnos a agregar: ";
	int cantidadAlumnos;
	cin >> cantidadAlumnos;

	int codigoAlumno;
	char nombreAlumno[20];
	float promedioAlumno;

	for (int i = 0; i < cantidadAlumnos; i++) 
	{
		cout << "Alumno " << (i + 1) << ": ";

		cout << "Ingrese codigo de alumno: ";
		cin >> codigoAlumno;

		cout << "Ingrese nombre de alumno: ";
		cin >> nombreAlumno;

		promedioAlumno = 0;

		archivoAlumnos << codigoAlumno << ' ' << nombreAlumno << ' ' << promedioAlumno << '\n';

		cout << "Alumno agregado!\n";
	}

	archivoAlumnos.close();

}

void Universidad::consultarAlumnos()
{
	cout << "*** C O N S U L T A  D E  A L U M N O S ***\n\n";

	ifstream archivoAlumnos("alumnos.dat", ios::in);

	if (!archivoAlumnos)
	{
		cout << "Error al intentar abrir el archivo alumnos.dat\n";
		return;
	}

	int codigoAlumno;
	char nombreAlumno[20];
	float promedioAlumno;

	while (archivoAlumnos >> codigoAlumno >> nombreAlumno >> promedioAlumno) 
	{
		cout << "Alumno { cuenta: " << codigoAlumno << ", nombre: " << nombreAlumno
			<< ", promedio: " << promedioAlumno << " }\n";
	}

	archivoAlumnos.close();

}

void Universidad::agregarMaterias()
{

	cout << "*** A G R E G A R  M A T E R I A S ***\n\n";

	ofstream archivoMaterias("materias.dat", ios::out | ios::app);

	if (!archivoMaterias)
	{
		cout << "Error al intentar abrir el archivo materias.dat\n";
		return;
	}

	int codigoMateria, uvsMateria;
	char nombreMateria[20];

	cout << "Indicar cantidad de materias a agregar: ";
	int cantidadMaterias;
	cin >> cantidadMaterias;

	for (int i = 0; i < cantidadMaterias; i++) 
	{
		cout << "Materia " << (i + 1) << ": \n";

		cout << "Ingrese codigo de Materia: ";
		cin >> codigoMateria;

		cout << "Ingrese nombre de Materia: ";
		cin >> nombreMateria;

		cout << "Ingrese uvs de Materia: ";
		cin >> uvsMateria;

		archivoMaterias << codigoMateria << ' ' << nombreMateria << ' ' << uvsMateria << '\n';
	}

	archivoMaterias.close();
}

void Universidad::consultarMaterias()
{

	cout << "*** C O N S U L T A  D E  M A T E R I A S ***\n\n";

	ifstream archivoMaterias("materias.dat", ios::in);

	if (!archivoMaterias)
	{
		cout << "Error al intentar abrir el archivo materias.dat\n";
		return;
	}

	int codigoMateria, uvsMateria;
	char nombreMateria[20];

	while (archivoMaterias >> codigoMateria >> nombreMateria >> uvsMateria) 
	{
		cout << "Materia { codigo: " << codigoMateria << ", nombre: " << nombreMateria
			<< ", uvs: " << uvsMateria << " }\n";
	}

	archivoMaterias.close();

}

bool Universidad::existeAlumno(int _codigo)
{
	ifstream archivoAlumnos("alumnos.dat", ios::in);

	if (!archivoAlumnos)
	{
		cout << "Error al intentar abrir el archivo alumnos.dat\n";
		return false;
	}

	int codigoAlumno;
	char nombreAlumno[20];
	float promedio;

	while (archivoAlumnos >> codigoAlumno >> nombreAlumno >> promedio) 
	{
		if (codigoAlumno == _codigo)
		{
			archivoAlumnos.close();
			return true;
		}
	}

	archivoAlumnos.close();
	return false;

}

bool Universidad::existeMateria(int _codigo)
{
	ifstream archivoMaterias("materias.dat", ios::in);

	if (!archivoMaterias)
	{
		cout << "Error al intentar abrir el archivo materias.dat\n";
		return false;
	}

	int codigoMateria, uvsMateria;
	char nombreMateria[20];

	while (archivoMaterias >> codigoMateria >> nombreMateria >> uvsMateria)
	{
		if (codigoMateria == _codigo)
		{
			archivoMaterias.close();
			return true;
		}
	}

	archivoMaterias.close();
	return false;
}

void Universidad::agregarNotas()
{

	cout << "***  A G R E G A R  N O T A S ***\n\n";

	ofstream archivoNotas("notas.dat", ios::out | ios::app);

	if (!archivoNotas)
	{
		cout << "Error al intentar abrir el archivo notas.dat\n";
		return;
	}

	int opcion = 0;
	int codigoAlumno;
	int codigoMateria;
	float notaMateria;

	do 
	{
		cout << "Desea agregar una nota (-1 para salir)\n";
		cin >> opcion;

		if (opcion == -1)
			break;

		do 
		{
			cout << "Ingrese codigo de alumno (existente): ";
			cin >> codigoAlumno;
		} while (!existeAlumno(codigoAlumno));

		do
		{
			cout << "Ingrese codigo de materia (existente): ";
			cin >> codigoMateria;
		} while (!existeMateria(codigoMateria));

		do 
		{
			cout << "Ingrese nota de materia: ";
			cin >> notaMateria;
		} while (notaMateria < 0 || notaMateria > 100);

		archivoNotas << codigoAlumno << ' ' << codigoMateria << ' ' << notaMateria << '\n';
		
		cout << "Nota agregada correctamente!\n";
	
	} while (opcion != -1);

	archivoNotas.close();

}
