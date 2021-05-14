#pragma once

#ifndef FIGURA2D_H
#define FIGURA2D_H

enum TipoFigura {
	tCirculo,
	tRectangulo,
	tTrianguloRectangulo
};

class Figura2D 
{
public:
	//funcion virtual hace que la clase sea abstracta
	// = 0, obloga que la implementacion de esta funcion se haga
	// en las clases que heredan (hijas)
	virtual float getArea() = 0;
	virtual float getPerimetro() = 0;
	virtual void imprimirFigura() = 0;
	virtual TipoFigura obtenerInstancia() = 0;
};

#endif // !FIGURA2D_H
