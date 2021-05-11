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
