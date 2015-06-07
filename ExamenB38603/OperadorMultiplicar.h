#pragma once
#include "Operador.h"
class OperadorMultiplicar :
	public Operador
{
public:
	OperadorMultiplicar();
	Operando * operar(Operando *, Operando *);
	void imprimir(ostream &) const = 0;
	virtual ~OperadorMultiplicar();
};

