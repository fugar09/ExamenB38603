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

#define OPERANDO 0
#define OPERACION 1
#define OPERADOR_SUMA 2
#define OPERADOR_RESTA 3
#define OPERADOR_MULTI 4
#define OPERADOR_DIV 5

class ArbolBinario
{
	friend ostream & operator<<(ostream &, ArbolBinario &);

private:
	Elemento * raiz;
	void imprimir(Elemento *, ostream &, int);
	static const int NUM_OPERADORES = 4;
	static const char OPERADORES[NUM_OPERADORES];
	static const char LEFT_PARENTHESIS = '(';
	static const char RIGHT_PARENTHESIS = ')';
public:
	ArbolBinario();
	ArbolBinario(Operacion*);
	
	Elemento* armarRec(string);

	int buscarPrecedencia(string);
	int profundidad(int,string);
	int tipoExpresion(string);
	bool isOnlyDouble(string);
	double convertToDouble(string);
	double resolver();
	Operando* getValue(Elemento*);
	bool isOperator(Elemento*);
	void eliminarParentesisInnecesarios(string &);


	
	
	


	virtual ~ArbolBinario();
};
ostream & operator<<(ostream &, ArbolBinario &);
