#include <conio.h>

#include "Rectangulo.h"
#include "Circulo.h"
#include "TrianguloRectangulo.h"

#include "Figura2D.h"

#include <iostream>
#include <vector>


using std::cout;
using std::vector;

int main() 
{
	/*Rectangulo r1(6, 3);
	Circulo c1(6.3);
	TrianguloRectangulo tr1(8, 2);


	r1.imprimirFigura();
	c1.imprimirFigura();
	tr1.imprimirFigura();*/

	//una variable de tipo apuntador hacia Figura2D
	//estas varibles almacenan direcciones de memoria
	/*Figura2D* f1;

	Rectangulo* rPtr = new Rectangulo(4, 3);

	cout << "f1 address: " << f1 << "\n";
	cout << "rPtr address: " << rPtr << "\n";

	f1 = rPtr;

	cout << "f1 address: " << f1 << "\n";
	cout << "rPtr address: " << rPtr << "\n";

	int arreglo[5];*/
	
	//Arreglo de apuntadores de tamaño fijo
	/*Figura2D* figurasArray[5];

	figurasArray[0] = new Rectangulo(4, 3);
	figurasArray[1] = new Circulo(3.5);
	figurasArray[2] = new TrianguloRectangulo(6, 2);
	figurasArray[3] = new Circulo(12);
	figurasArray[4] = new Rectangulo(8, 3);*/

	//arreglo dinamico de apuntadores

	vector<Figura2D*> figurasVector;

	figurasVector.push_back(new Rectangulo(5, 3));
	figurasVector.push_back(new TrianguloRectangulo(4, 7));
	figurasVector.push_back(new Circulo(8));
	figurasVector.push_back(new Rectangulo(2, 5));
	figurasVector.push_back(new Circulo(3));
	figurasVector.push_back(new Rectangulo(7, 2));

	cout << "Cantidad de elementos en vector: "
		<< figurasVector.size() << "\n";

	for (int i = 0; i < figurasVector.size(); i++)
		figurasVector[i]->imprimirFigura();
	

	int cantRectangulo = 0;
	int cantCirculo = 0;
	int cantTrianguloRectangulo = 0;

	for (int i = 0; i < figurasVector.size(); i++)
	{
		if (figurasVector[i]->obtenerInstancia() == TipoFigura::tCirculo)
			cantCirculo++;
		else if (figurasVector[i]->obtenerInstancia() == TipoFigura::tRectangulo)
			cantRectangulo++;
		else if (figurasVector[i]->obtenerInstancia() == TipoFigura::tTrianguloRectangulo)
			cantTrianguloRectangulo++;
	}

	cout << "Cantidad de Circulos: " << cantCirculo << "\n";
	cout << "Cantidad de Rectangulos: " << cantRectangulo << "\n";
	cout << "Cantidad de TriangulosRectangulos: " << cantTrianguloRectangulo << "\n";

	//casteo con tipos de datos compatibles
	Rectangulo rCast;
	TrianguloRectangulo tr(4, 5);
	rCast = (Rectangulo)tr;

	rCast.imprimirFigura();

	_getch();
}