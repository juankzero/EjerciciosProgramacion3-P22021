#include "Estructuras.h"

#include <fstream>
#include <iostream>

//using std::ofstream;
//using std::cout;
//using std::cin;

using namespace std;

void crearConjunto() 
{
	cout << "*** C R E A R  C O N J U N T O ***\n\n";

	cout << "Ingrese nombre de conjunto/tabla: ";
	char nombreConjunto[20];
	cin >> nombreConjunto;

	ofstream archivoConjunto(nombreConjunto, ios::out | ios::binary | ios::app);

	if (!archivoConjunto)
	{
		cout << "Error: Imposible abrir/leer archivo " << nombreConjunto << "\n";
		return;
	}

	int cantidadCampos = 0;
	cout << "Indique cantidad de campos a crear: ";
	cin >> cantidadCampos;

	int cantidadRegistros = 0;
	cout << "Indique cantidad de registros a crear: ";
	cin >> cantidadRegistros;

	InformacionTabla infoTabla;
	infoTabla.cantidadCampos = cantidadCampos;
	infoTabla.cantidadRegistros = cantidadRegistros;

	archivoConjunto.write(reinterpret_cast<const char*>(&infoTabla), sizeof(InformacionTabla));

	InformacionCampo infoCampo;
	for (int i = 0; i < cantidadCampos; i++) 
	{
		cout << "Ingrese nombre de campo " << (i + 1) << ": ";
		cin >> infoCampo.nombreCampo;

		cout << "Seleccione el tipo de campo:\n";
		cout << "1. Entero\n2. Decimal\n3. Cadena\n4. Caracter\n5. Logico\n";
		int tipoCampo = 0;
		cin >> tipoCampo;

		switch (tipoCampo) 
		{
			case 1:
				infoCampo.tipo = TipoCampo::t_Entero;
				break;
			case 2:
				infoCampo.tipo = TipoCampo::t_Decimal;
				break;
			case 3:
				infoCampo.tipo = TipoCampo::t_Cadena;
				break;
			case 4:
				infoCampo.tipo = TipoCampo::t_Caracter;
				break;
			case 5:
				infoCampo.tipo = TipoCampo::t_Logico;
				break;
			default:
				cout << "Error en seleccion de tipo de datos en campo!\n";
				break;
		}

		archivoConjunto.write(reinterpret_cast<const char*>(&infoCampo), sizeof(InformacionCampo));

	}

}