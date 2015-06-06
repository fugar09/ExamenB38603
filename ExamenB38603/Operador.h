#pragma once
#include "Elemento.h"
#include "Operando.h"
class Operador :
	protected Elemento
{
public:
	Operador();
	virtual Operando * operar(Operando *, Operando *) = 0;
	virtual ~Operador();
};

