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

}


ArbolBinario::~ArbolBinario()
{
}

void ArbolBinario::construirArbol() {

	
}
int ArbolBinario::buscarMenorPrecedencia() {
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
double ArbolBinario:: toDigit(char ch)
{
	return ch - '0';
}


