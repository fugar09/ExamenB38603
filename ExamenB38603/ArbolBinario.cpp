#include "stdafx.h"

#include "ArbolBinario.h"
#include "Elemento.h"
#include "Operacion.h"
#include "Operador.h"
#include "OperadorDividir.h"
#include "OperadorMultiplicar.h"
#include "OperadorResta.h"
#include "OperadorSuma.h"
#include "Operando.h"

using namespace std;

ArbolBinario::ArbolBinario(Elemento* elemento)
{
	if (raiz == NULL){
		raiz = elemento;
	}
	else {
		construirArbol(raiz, elemento);
	}
}


ArbolBinario::~ArbolBinario()
{
}

void ArbolBinario::construirArbol(Elemento* nodoActual, Elemento* elemento) {
	/*if (buscarMenorPrecedencia( elemento)!=-1) {
		nodoActual
	}*/
	
}
int ArbolBinario::buscarMenorPrecedencia(Elemento * elemento) {
	/*int posicion = -1;
	char simboloGuardado;
	Operacion*expresion = static_cast<Operacion*>(elemento);
	for (int i = 0; i < expresion->expresion.size; i++) {
		char x = expresion->expresion[i];
		if (x == '+' && (simboloGuardado !='+'&& simboloGuardado != '-')) {
			posicion = i;
			simboloGuardado = x;
		}else if (x == '-' && (simboloGuardado != '+' && simboloGuardado != '-')) {
			posicion = i;
			simboloGuardado = x;
		}
		else if (x == '*' || x == '/') {
			posicion = i;
		}
	}
	return posicion;
	*/
	return 1;
}

bool ArbolBinario::isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}
bool ArbolBinario::isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
int ArbolBinario:: toDigit(char ch)
{
	return ch - '0';
}

