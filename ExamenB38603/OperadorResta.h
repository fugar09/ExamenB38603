#pragma once
#include "Operador.h"
class OperadorResta :
	public Operador, public Elemento
{
private:
	char s;
public:
	OperadorResta();
	Operando * operar(Operando *, Operando *);
	void imprimir(ostream &) const;
	virtual ~OperadorResta();
};

