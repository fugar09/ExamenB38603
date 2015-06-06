#pragma once
#include "Operador.h"
class OperadorDividir :
	public Operador
{
public:
	OperadorDividir();
	Operando * operar(Operando *, Operando *);
	virtual ~OperadorDividir();
};

