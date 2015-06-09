#include "stdafx.h"
#include "OperadorMultiplicar.h"


OperadorMultiplicar::OperadorMultiplicar()
{
	s = '*';
}


OperadorMultiplicar::~OperadorMultiplicar()
{
}

Operando * OperadorMultiplicar::operar(Operando * a, Operando * b) {
	return new Operando(a->get() * b->get());
}
void OperadorMultiplicar::imprimir(ostream& out) const {
	out << this->s;
}