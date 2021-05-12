#include "Cheque.h"

#include <iostream>
using namespace std;

Cheque::Cheque(double _saldoInicial, double _cuotaTransaccion)
	: Cuenta(_saldoInicial), cuotaTransaccion(_cuotaTransaccion)
{
	if (_cuotaTransaccion >= 0)
		cuotaTransaccion = _cuotaTransaccion;
	else
		throw invalid_argument("+Cuota de Transaccion debe ser mayor a cero!\n");
}

void Cheque::abonar(double _cantidad)
{
	Cuenta::abonar(_cantidad);
	cargarCuotaTransaccion();
}

bool Cheque::cargar(double _cantidad)
{
	bool resultado = Cuenta::cargar(_cantidad);

	if (resultado)
	{
		cargarCuotaTransaccion();
		return true;
	}

	return false;

}

void Cheque::cargarCuotaTransaccion()
{
	setSaldo( getSaldo() - cuotaTransaccion );
	cout << "L" << cuotaTransaccion << " cuota de transaccion cargada.\n";
}


