#pragma once
#include "Operador.h"
class OperadorMultiplicar :
	public Operador
{
public:
	OperadorMultiplicar();
	Operando * operar(Operando *, Operando *);
	virtual ~OperadorMultiplicar();
};

