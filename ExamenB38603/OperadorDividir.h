#pragma once
#include "Operador.h"
class OperadorDividir :
	public Operador,public Elemento
{
private:
	char s;
public:
	OperadorDividir();
	Operando * operar(Operando *, Operando *);
	void imprimir(ostream &) const;
	virtual ~OperadorDividir();
};

