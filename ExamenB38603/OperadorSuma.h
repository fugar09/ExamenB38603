#pragma once
#include "Operador.h"
class OperadorSuma :
	public Operador
{
public:
	OperadorSuma();
	Operando * operar(Operando *, Operando *);
	virtual ~OperadorSuma();
};

