
#include <iostream>
#include <conio.h>

using std::cout;

class Nota
{
public:
	int notaAprobacion;

	//constructor sin parametros
	Nota(void) : valor(0), notaAprobacion(70)
	{
		//this->valor = 0;
	}

	//constructor con parametros
	Nota(int _valor) : valor(_valor), notaAprobacion(70)
	{
		//this->valor = _valor;
	}

	void setValor(int _valor)
	{
		if (_valor < 0 || _valor > 100)
		{
			cout << "Error: Ingreso de Nota incorrecto.\n";
			return;
		}

		this->valor = _valor;
	}

	int getValor()
	{
		return this->valor;
	}

	bool esAprobado() 
	{
		/*if (valor >= notaAprobacion)
			return true;

		return false;*/

		//return valor >= notaAprobacion ? true : false;

		return valor >= notaAprobacion;
	}

	void obtenerCalificacionIngles() 
	{
		int calificacion = valor / 10;

		switch (calificacion) 
		{
			case 10:
			case 9 :
				cout << "A";
				break;
			case 8:
				cout << "B";
				break;
			case 7:
				cout << "C";
				break;
			case 6:
				cout << "D";
				break;
			default:
				cout << "F";
				break;
		}

	}


private:
	int valor;
};


int main() 
{
	Nota n1;
	Nota n2(88);

	n1.setValor(91);
	cout << "Nota 1: " << n1.getValor() << ", ";
	n1.obtenerCalificacionIngles();
	cout << "\n";
	cout << "Nota 2: " << n2.getValor() << ", ";
	n2.obtenerCalificacionIngles();
	cout << "\n";

	cout << "La nota n1 esta " << (n1.esAprobado() ? "aprobado" : "reprobado") << "\n";
	cout << "La nota n2 esta " << (n2.esAprobado() ? "aprobado" : "reprobado") << "\n";


	_getch();
}
