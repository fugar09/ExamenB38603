#include "stdafx.h"
#include "OperadorSuma.h"


OperadorSuma::OperadorSuma()
{
}


OperadorSuma::~OperadorSuma()
{
}

Operando * OperadorSuma::operar(Operando * a, Operando * b) {
	return new Operando(a->get() + b->get());
}
void OperadorSuma::imprimir(ostream& out) const {
	out << "+";
}