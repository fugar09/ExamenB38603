#pragma once
#include "Elemento.h"
#include "Operacion.h"
#include "Operador.h"
#include "OperadorDividir.h"
#include "OperadorMultiplicar.h"
#include "OperadorResta.h"
#include "OperadorSuma.h"
#include "Operando.h"
class ArbolBinario
{
private:
	Elemento * raiz;
public:
	ArbolBinario(Elemento* );
	void construirArbol(Elemento*,Elemento*);
	int buscarMenorPrecedencia(Elemento*);
	bool isDigit(char ch);
	bool isOperator(char ch);
	int toDigit(char ch);
	virtual ~ArbolBinario();
};

