#include "stdafx.h"
#include "OperadorSuma.h"


OperadorSuma::OperadorSuma()
{
	s = '+';
}


OperadorSuma::~OperadorSuma()
{
}

Operando * OperadorSuma::operar(Operando * a, Operando * b) {
	return new Operando(a->get() + b->get());
}
void OperadorSuma::imprimir(ostream& out) const {
	out << this->s;
}
char OperadorSuma::getSymbol() {
	return s;
}