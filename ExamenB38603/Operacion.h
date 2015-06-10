#pragma once
#include "stdafx.h"
#include "Elemento.h"
#include "Operador.h"
#include "OperadorDividir.h"
#include "OperadorMultiplicar.h"
#include "OperadorResta.h"
#include "OperadorSuma.h"
#include "Operando.h"
#include "Lista.h"

#define OPERANDO 0
#define OPERACION 1
#define OPERADOR_SUMA 2
#define OPERADOR_RESTA 3
#define OPERADOR_MULTI 4
#define OPERADOR_DIV 5

class Operacion :
	public Elemento
{
//friend class ArbolBinario;

private:
	string expresion;
public:
	Operacion(string);
	virtual ~Operacion();
	void imprimir(ostream &) const;
	string getExpresion();
};

