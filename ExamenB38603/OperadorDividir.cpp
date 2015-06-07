#include "stdafx.h"
#include "OperadorDividir.h"


OperadorDividir::OperadorDividir()
{
}


OperadorDividir::~OperadorDividir()
{
}

Operando * OperadorDividir::operar(Operando * a, Operando * b) {
	return new Operando(a->get() / b->get());
}
void OperadorDividir::imprimir(ostream& out) const {
	out << "/";
}
