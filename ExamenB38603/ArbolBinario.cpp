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
	int posicion = buscarMenorPrecedencia(elemento);
	if (posicion!=-1) {
		Operacion*expresion = static_cast<Operacion*>(elemento);
		string parteIzquierda = expresion->expresion.substr(0, posicion);
		//asignar *hIzq -> parteIzquierda
		string operador= expresion->expresion.substr(posicion, posicion+1);
		if (operador == "*") {
			//nodoActual = new Operador();
		}
		//asignar *nodoActual -> operador
		string parteDerecha= expresion->expresion.substr(posicion+1, expresion->expresion.length);
		//asignar *hDer-> parteDerecha
	}
	
}
int ArbolBinario::buscarMenorPrecedencia(Elemento * elemento) {
	int posicion = -1;
	char simboloGuardado;
	bool ignorar = false;
	Operacion*expresion = static_cast<Operacion*>(elemento);
	for (int i = 0; i < expresion->expresion.length; i++) {
		char x = expresion->expresion[i];
		if (x == '(') {
			ignorar = true;
		}
		else if (x == ')') {
			ignorar = false;
		}
		if (!ignorar) {
			if (x == '+' && (simboloGuardado != '+'&& simboloGuardado != '-')) {
				posicion = i;
				simboloGuardado = x;
			}
			else if (x == '-' && (simboloGuardado != '+' && simboloGuardado != '-')) {
				posicion = i;
				simboloGuardado = x;
			}
			else if (x == '*' || x == '/') {
				posicion = i;
			}
		}
	}
	return posicion;

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

