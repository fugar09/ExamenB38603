#pragma once
#include "stdafx.h"
#include "Elemento.h"
class Operacion :
	protected Elemento
{
protected:
	string expresion;
public:
	Operacion(string);
	virtual ~Operacion();
};

