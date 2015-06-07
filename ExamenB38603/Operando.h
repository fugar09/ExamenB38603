#pragma once
#include "Elemento.h"
class Operando :
	public Elemento
{
private:
	double i;

public:
	Operando(double);
	void imprimir(ostream &) const;
	double get();
	~Operando();
};

