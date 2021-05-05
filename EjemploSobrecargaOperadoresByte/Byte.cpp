#include "Byte.h"

Byte::Byte()
{
	//inicializar todas las posiciones del byte en 0
	for (int i = 0; i < 8; i++) 
	{
		this->bits[i] = 0;
	}

}

Byte::Byte(const char* _byte)
{
	for (int i = 0; i < 8; i++) 
	{
		this->bits[i] = _byte[i] - 48;
	}

}

Byte::~Byte()
{
}

std::ostream& operator<<(std::ostream& cout, const Byte& b1)
{
	cout << "{ ";
	for (int i = 0; i < 8; i++) 
	{
		cout << b1.bits[i];
	}
	cout << " }\n";

	return cout;
}
