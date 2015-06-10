#include "stdafx.h"
#include "Operacion.h"
#include "Elemento.h"
#include "Elemento.h"
#include "Operador.h"
#include "OperadorDividir.h"
#include "OperadorMultiplicar.h"
#include "OperadorResta.h"
#include "OperadorSuma.h"
#include "Operando.h"
#include "Lista.h"



Operacion::Operacion(string expresion)
{
	this->expresion = expresion;
}


Operacion::~Operacion()
{
}
void Operacion::imprimir(ostream& out) const{
	out <<expresion;
}
string Operacion::getExpresion() {
	return this->expresion;
}

