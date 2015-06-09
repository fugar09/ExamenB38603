#include "stdafx.h"
#include "Operacion.h"



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
char*Operacion::getExpresion() {
	int size = this->expresion.length() + 1;
	char *cstr = new char[size];
	strcpy_s(cstr,size, this->expresion.c_str());
	return cstr;
}
