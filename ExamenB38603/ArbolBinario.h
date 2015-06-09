#pragma once
#include "Elemento.h"
#include "Operacion.h"
#include "Operador.h"
#include "OperadorDividir.h"
#include "OperadorMultiplicar.h"
#include "OperadorResta.h"
#include "OperadorSuma.h"
#include "Operando.h"
#include "Lista.h"


class ArbolBinario
{
private:
	Elemento * raiz;
public:
	ArbolBinario(Elemento*);
	void construirArbol();
	int buscarMenorPrecedencia();
	bool isDigit(char ch);
	bool isOperator(char ch);
	double toDigit(char ch);

	virtual ~ArbolBinario();
};

