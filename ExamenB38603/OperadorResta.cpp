#include "stdafx.h"
#include "OperadorResta.h"


OperadorResta::OperadorResta()
{
}


OperadorResta::~OperadorResta()
{
}
Operando * OperadorResta::operar(Operando * a, Operando * b) {
	return new Operando(a->get() - b->get());
}
