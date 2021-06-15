#pragma once

#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

class Universidad
{
public:
	static void agregarAlumnos();
	static void consultarAlumnos();
	static void agregarMaterias();
	static void consultarMaterias();

	static bool existeAlumno(int);
	static bool existeMateria(int);

	static void agregarNotas();
};


#endif // !UNIVERSIDAD_H


