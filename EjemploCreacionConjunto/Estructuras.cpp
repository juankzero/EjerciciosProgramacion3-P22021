#include "Estructuras.h"

#include <fstream>
#include <iostream>

//using std::ofstream;
//using std::cout;
//using std::cin;

#include <vector>

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

	vector<InformacionCampo> listaCampos;

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

		listaCampos.push_back(infoCampo);
	}

	for (int i = 0; i < cantidadRegistros; i++) 
	{
		cout << "Registro " << (i + 1) << ":\n";
		for (int j = 0; j < listaCampos.size(); j++) 
		{
			switch (listaCampos[j].tipo) 
			{
				case TipoCampo::t_Entero:
					cout << "Ingrese valor entero: ";
					RegistroEntero re;
					cin >> re.valor;
					archivoConjunto.write(reinterpret_cast<const char*>(&re), sizeof(RegistroEntero));
					break;
				case TipoCampo::t_Decimal:
					cout << "Ingrese valor decimal: ";
					RegistroDecimal rd;
					cin >> rd.valor;
					archivoConjunto.write(reinterpret_cast<const char*>(&rd), sizeof(RegistroDecimal));
					break;
				case TipoCampo::t_Cadena:
					cout << "Ingrese valor cadena: ";
					RegistroCadena rc;
					cin >> rc.valor;
					archivoConjunto.write(reinterpret_cast<const char*>(&rc), sizeof(RegistroCadena));
					break;
				case TipoCampo::t_Caracter:
					cout << "Ingrese valor caracter: ";
					RegistroCaracter rch;
					cin >> rch.valor;
					archivoConjunto.write(reinterpret_cast<const char*>(&rch), sizeof(RegistroCaracter));
					break;
				case TipoCampo::t_Logico:
					cout << "Ingrese valor logico (1 -> True | 0 -> False): ";
					RegistroLogico rl;
					int valorLogico;
					cin >> valorLogico;

					valorLogico == 1 ? rl.valor = true : rl.valor = false;

					archivoConjunto.write(reinterpret_cast<const char*>(&rl), sizeof(RegistroLogico));
					break;
			}


		}

	}

	cout << "Conjunto/Tabla creada correctamente!\n";
	archivoConjunto.close();
}

void leerConjunto() 
{
	cout << "*** L E C T U R A  D E  C O N J U N T O ***\n\n";

	cout << "Ingrese nombre de conjunto a leer: ";
	char nombreConjunto[20];
	cin >> nombreConjunto;

	ifstream archivoConjunto(nombreConjunto, ios::in | ios::binary);

	if (!archivoConjunto)
	{
		cout << "Error: Imposible abrir/leer archivo " << nombreConjunto << "\n";
		return;
	}

	InformacionTabla infoTabla;
	archivoConjunto.seekg(0, ios::beg);
	archivoConjunto.read(reinterpret_cast<char*>(&infoTabla), sizeof(InformacionTabla));

	InformacionCampo infoCampo;
	vector<InformacionCampo> listaCampos;
	for (int i = 0; i < infoTabla.cantidadCampos; i++) 
	{
		archivoConjunto.read(reinterpret_cast<char*>(&infoCampo), sizeof(InformacionCampo));
		cout << infoCampo.nombreCampo << "\t";
		listaCampos.push_back(infoCampo);
	}

	cout << "\n";

	for (int i = 0; i < infoTabla.cantidadRegistros; i++) 
	{
		for (int j = 0; j < infoTabla.cantidadCampos; j++) 
		{

			switch (listaCampos[j].tipo) 
			{
				case TipoCampo::t_Entero:
					RegistroEntero re;
					archivoConjunto.read(reinterpret_cast<char*>(&re), sizeof(RegistroEntero));
					cout << re.valor << "\t";
					break;
				case TipoCampo::t_Decimal:
					RegistroDecimal rd;
					archivoConjunto.read(reinterpret_cast<char*>(&rd), sizeof(RegistroDecimal));
					cout << rd.valor << "\t";
					break;
				case TipoCampo::t_Cadena:
					RegistroCadena rc;
					archivoConjunto.read(reinterpret_cast<char*>(&rc), sizeof(RegistroCadena));
					cout << rc.valor << "\t";
					break;
				case TipoCampo::t_Caracter:
					RegistroCaracter rch;
					archivoConjunto.read(reinterpret_cast<char*>(&rch), sizeof(RegistroCaracter));
					cout << rch.valor << "\t";
					break;
				case TipoCampo::t_Logico:
					RegistroLogico rl;
					archivoConjunto.read(reinterpret_cast<char*>(&rl), sizeof(RegistroLogico));
					cout << rl.valor << "\t";
					break;
			}

		}

		cout << "\n";

	}

	
}

void agregarRegistro()
{

	cout << "*** A G R E G A R  R E G I S T R O S ***\n\n";

	cout << "Indique Tabla/Conjunto a agregar datos: ";
	char nombreConjunto[20];
	cin >> nombreConjunto;

	fstream archivoConjunto(nombreConjunto, ios::in | ios::out | ios::binary);

	if (!archivoConjunto)
	{
		cout << "Error: Imposible abrir/leer archivo " << nombreConjunto << "\n";
		return;
	}

	cout << "Indique cantidad de registros a agregar: ";
	int cantidadAgregar;
	cin >> cantidadAgregar;

	archivoConjunto.seekg(0, ios::beg);
	InformacionTabla it;
	archivoConjunto.read(reinterpret_cast<char*>(&it), sizeof(InformacionTabla));

	vector<InformacionCampo> listaCampos;
	InformacionCampo lecturaCampo;

	for (int i = 0; i < it.cantidadCampos; i++) 
	{
		archivoConjunto.read(reinterpret_cast<char*>(&lecturaCampo), sizeof(InformacionCampo));
		listaCampos.push_back(lecturaCampo);
	}

	//posionarse al final del archivo para escritura
	archivoConjunto.seekp(0, ios::end);

	for (int i = 0; i < cantidadAgregar; i++)
	{
		cout << "Registro " << (i + 1) << ":\n";
		for (int j = 0; j < listaCampos.size(); j++)
		{
			switch (listaCampos[j].tipo)
			{
			case TipoCampo::t_Entero:
				cout << "Ingrese " << listaCampos[j].nombreCampo << ": ";
				RegistroEntero re;
				cin >> re.valor;
				archivoConjunto.write(reinterpret_cast<const char*>(&re), sizeof(RegistroEntero));
				break;
			case TipoCampo::t_Decimal:
				cout << "Ingrese " << listaCampos[j].nombreCampo << ": ";
				RegistroDecimal rd;
				cin >> rd.valor;
				archivoConjunto.write(reinterpret_cast<const char*>(&rd), sizeof(RegistroDecimal));
				break;
			case TipoCampo::t_Cadena:
				cout << "Ingrese " << listaCampos[j].nombreCampo << ": ";
				RegistroCadena rc;
				cin >> rc.valor;
				archivoConjunto.write(reinterpret_cast<const char*>(&rc), sizeof(RegistroCadena));
				break;
			case TipoCampo::t_Caracter:
				cout << "Ingrese " << listaCampos[j].nombreCampo << ": ";
				RegistroCaracter rch;
				cin >> rch.valor;
				archivoConjunto.write(reinterpret_cast<const char*>(&rch), sizeof(RegistroCaracter));
				break;
			case TipoCampo::t_Logico:
				cout << "Ingrese " << listaCampos[j].nombreCampo << ": ";
				RegistroLogico rl;
				int valorLogico;
				cin >> valorLogico;

				valorLogico == 1 ? rl.valor = true : rl.valor = false;

				archivoConjunto.write(reinterpret_cast<const char*>(&rl), sizeof(RegistroLogico));
				break;
			}


		}

	}

	//posicionar al inicio del archivo para escritura
	archivoConjunto.seekp(0, ios::beg);
	it.cantidadRegistros += cantidadAgregar;
	archivoConjunto.write(reinterpret_cast<const char*>(&it), sizeof(InformacionTabla));

	archivoConjunto.close();

}
