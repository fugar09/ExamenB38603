#include "stdafx.h"
#include "OperadorMultiplicar.h"


OperadorMultiplicar::OperadorMultiplicar()
{
}


OperadorMultiplicar::~OperadorMultiplicar()
{
}

Operando * OperadorMultiplicar::operar(Operando * a, Operando * b) {
	return new Operando(a->get() * b->get());
}