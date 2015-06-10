#pragma once
#include "Operador.h"
class OperadorMultiplicar :
	public Operador, public Elemento
{
private:
	char s;
public:
	OperadorMultiplicar();
	Operando * operar(Operando *, Operando *);
	char getSymbol();
	void imprimir(ostream &) const;
	virtual ~OperadorMultiplicar();
};

