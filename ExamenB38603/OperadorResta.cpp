#include "stdafx.h"
#include "OperadorResta.h"


OperadorResta::OperadorResta()
{
	s = '-';
}


OperadorResta::~OperadorResta()
{
}
Operando * OperadorResta::operar(Operando * a, Operando * b) {
	return new Operando(a->get() - b->get());
}
void OperadorResta::imprimir(ostream& out) const {
	out << this->s;
}
