#pragma once
#include "Elemento.h"
class Operando :
	protected Elemento
{
private:
	double i;

public:
	Operando(double);
	double get();
	~Operando();
};

