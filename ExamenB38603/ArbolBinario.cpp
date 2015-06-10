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
#include "Lista.h"


using namespace std;

ArbolBinario::ArbolBinario()
{
	this->raiz = NULL;
}
ArbolBinario::ArbolBinario(Operacion* op) {
	Elemento* e;
	e = armarRec(op->getExpresion()); //armar el arbol utilizando la recursión

	raiz = e;


}

Elemento* ArbolBinario::armarRec(string exp) {
	//Metodo recursivo que arma el arbol,apartir de una expresión
	Elemento* e = NULL;

	double op = 0.0;
	if (isOnlyDouble(exp)) {//En caso de que la expresión se únicamente doubles (es decir,es un operando)
		op = convertToDouble(exp); //se convierte a double esa expresion
		return e = new Operando(op); //se retorna un elemento de tipo operando, esta es la condición de parada del metodo recursivo
	}

	int prec = buscarPrecedencia(exp); 
	if (prec == 0) {// Si la precedecia es 0, quiere decir que la expresión inicia con parentesis
		string exp_sin_parent= exp.substr(1, exp.length() - 2); // entonces se le quitan los parentesis a la expresión
		e= armarRec(exp_sin_parent); // se llamar de forma recursiva ala función armarRec, pero a la expresión sin los parentesis
		return e; // retorna el elemento producto de ese armado recursivo
	}
	else {
		//en caso de que si encuentre una precendencia en al expresión
			int size = exp.length();  //se calcula el largo de la expresión
			//se divide al expresión en tres partes
			string exp1 = exp.substr(0, prec); //una parte para el hijo Izquierdo
			string exp2 = exp.substr(prec, 1);// el centro seria el operador (+/-*)
			string exp3 = exp.substr(prec + 1, size);// la ultima parte para el hijo derecho
			
			switch (tipoExpresion(exp2)) {
				//se revisa que tipo de operador es
			case OPERADOR_SUMA:
				e = new OperadorSuma();
				break;
			case OPERADOR_RESTA:
				e = new OperadorResta();
				break;
			case OPERADOR_MULTI:
				e = new OperadorMultiplicar();
				break;
			case OPERADOR_DIV:
				e = new OperadorDividir();
				break;
			default:
				break;
			}
			//se vuelve a llamar recursivamente el metodo con los hijos como parametros, hasta que devuelva un operando
			e->hIzq= armarRec(exp1); 
			e->hDer = armarRec(exp3);
		
	}
	return e;
}




ArbolBinario::~ArbolBinario()
{
}
ostream & operator<<(ostream & out, ArbolBinario & a) {
	a.imprimir(a.raiz, out, 0);
	return out;
}
void ArbolBinario::imprimir(Elemento* nodo, ostream& out, int profundidad) {
	if (nodo->hIzq != NULL) {
		imprimir(nodo->hIzq, out, profundidad + 1);
	}
	for (int i = 0; i < profundidad; ++i) {
		cout << "\t";
	}
	out << *nodo << endl;
	if (nodo->hDer != NULL) {
		imprimir(nodo->hDer, out, profundidad + 1);
	}
}


int ArbolBinario::buscarPrecedencia(string exp) {
	//Función que retorna la posición donde esta el signo de menor precedencia en una expresión matemática

	int index = 0;
	int size = exp.length();
	for (int i = 0; i < size; i++)
	{
		if (profundidad(i,exp) == 0) {
			if (exp.at(i) == '+' || exp.at(i) == '-') {
				index = i;
				break;
			}
			else if (exp.at(i) == '*' || exp.at(i) == '/') {
				index = i;
			}
		}
	}

	return index;
}
int ArbolBinario::profundidad(int pos, string exp) {
	//Devuelve la profundidad en que se encuentra un termino dentro de la expresión
	int prof = 0;
	for (int i = 0; i <pos; i++)
	{
		if (exp.at(i) == '(') {
			prof++;
		}
		else if (exp.at(i) == ')') {
			prof--;
		}
	}
	return prof;
}

int ArbolBinario::tipoExpresion(string exp) {
	//Función que retorna que tipo de expresión se tiene
	int size = exp.length();
	int tipo = -1;
	if (isOnlyDouble(exp)) {
		tipo = OPERANDO;
	}
	else if (exp == "+") {
		tipo = OPERADOR_SUMA;
	}
	else if (exp == "-") {
		tipo = OPERADOR_RESTA;
	}
	else if (exp == "*") {
		tipo = OPERADOR_MULTI;
	}
	else if (exp == "/") {
		tipo = OPERADOR_DIV;
	}
	else {
		tipo = OPERACION;
	}
	return tipo;
}

bool ArbolBinario::isOnlyDouble(string exp)
{
	//Función que retorna si el la expresión que se revisa es solo un double, retorna si sin son solo números, sino false
	const char* str = exp.c_str();
	char* endptr = 0;
	strtod(str, &endptr);

	if (*endptr != '\0' || endptr == str)
		return false;
	return true;
}

double ArbolBinario::convertToDouble(string op) {
	//Función que devuelve el valor en double de un string
	double d;
	d = atof(op.c_str());
	return d;
}

double ArbolBinario::resolver() {
	//Metodo que devuelve el resultado de un arbol
	double total = 0.0;
	total = getValue(raiz)->get();
	return total;
}
Operando* ArbolBinario::getValue(Elemento* e) {
	/*Metodo que recorre el arbol devolviendo los diferente Operando según el nivel, utilizando la recursividad*/
	if (!isOperator(e)) {// Si el elemento que se revisa no es un operador
		Operando* opnd = static_cast<Operando*>(e); //se trata como si fuera un operando
		return opnd; //retorna el valor del operando
	}
	else {
		Operando * a = getValue(e->hIzq); // se llama recursivamente a esta misma función, hasta q devuelva al operando correspondiente
		Operando * b = getValue(e->hDer);
		Operador*op = dynamic_cast<Operador*>(e);// se trata como un operador al elemento e, que recibe como parametro la función
		return op->operar(a, b); //se realiza la operación utilizando las propiedades del polimorfismo de ese metodo
	}
	
}

bool ArbolBinario::isOperator(Elemento* e) {
	//Metodo que devuelve si el elemento revisado es un operador o no
	if (e->hIzq == NULL || e->hDer == NULL) { //en caso de que el elemento revisado tenga hijos en nulo, se sabe que es un operando, por lo cual retorna false
		return false;
	}
	else {
		return true;
	}
}
