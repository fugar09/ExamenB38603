#include "stdafx.h"
#include "Operando.h"


Operando::Operando(int i)
{
	this->i = i;
}


Operando::~Operando()
{
}

int Operando::get() {
	return i;
}
void Operando::imprimir(ostream& out) const {
	out << i;
}