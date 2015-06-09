#pragma once
#include "Operador.h"
class OperadorSuma :
	public Operador, public Elemento
{
private:
	char s;
public:
	OperadorSuma();
	Operando * operar(Operando *, Operando *);
	void imprimir(ostream &) const;
	virtual ~OperadorSuma();
};

