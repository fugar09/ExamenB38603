#pragma once
#include "Operador.h"
class OperadorResta :
	public Operador
{
public:
	OperadorResta();
	Operando * operar(Operando *, Operando *);
	virtual ~OperadorResta();
};

