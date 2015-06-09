#pragma once
#include "Elemento.h"
class Operando :
	public Elemento
{
private:
	int i;

public:
	Operando(int);
	void imprimir(ostream &) const;
	int get();
	~Operando();
};

