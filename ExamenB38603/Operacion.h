#pragma once
#include "stdafx.h"
#include "Elemento.h"
class Operacion :
	public Elemento
{
friend class ArbolBinario;

private:
	string expresion;
public:
	Operacion(string);
	virtual ~Operacion();
	void imprimir(ostream &) const;
	char* getExpresion();
};

