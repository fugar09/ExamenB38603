#pragma once
#include "Elemento.h"
#include "Operando.h"
class Operador :
	public Elemento
{
public:
	Operador();
	virtual Operando * operar(Operando *, Operando *) = 0;
	virtual char getSymbol()=0;
	virtual ~Operador();
};

