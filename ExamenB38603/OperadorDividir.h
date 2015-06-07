#pragma once
#include "Operador.h"
class OperadorDividir :
	public Operador
{
public:
	OperadorDividir();
	Operando * operar(Operando *, Operando *);
	void imprimir(ostream &) const;
	virtual ~OperadorDividir();
};

