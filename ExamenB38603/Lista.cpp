#include "stdafx.h"
#include "Lista.h"
#include "Elemento.h"


#define NULO 0

Lista::Lista()
{
	this->inicial = NULO;
	this->final = NULO;
	contador = 0;
}

bool Lista::listaVacia(){
	return this->final == NULO && this->inicial == NULO;
}

void Lista::insertarFinal(Elemento* elemento){
	if (listaVacia()){
		this->inicial = elemento;
		this->final = elemento;
	}
	else{
		this->final->siguiente = elemento;
		this->final = elemento;
	}
	contador++;
}

void Lista::insertarInicio(Elemento* elemento){
	if (listaVacia()){
		this->inicial = elemento;
		this->final = elemento;
	}
	else{
		elemento->siguiente = this->inicial;
		this->inicial = elemento;

	}
}

void Lista::insertar(Elemento* elemento, int posicion){
	if (posicion == 0){
		insertarInicio(elemento);
	}else if (posicion == contador){
		insertarFinal(elemento);
	}else{
		Elemento* temp1 = this->inicial;
		while (--posicion){
			temp1 = temp1->siguiente;
		}
		Elemento* temp2 = temp1->siguiente;
		temp1->siguiente = elemento;
		elemento->siguiente = temp2;
	}
}

void Lista::removerFinal(){
	Elemento* prev = this->inicial;
	Elemento* temp = this->inicial->siguiente;
	while (temp->siguiente != NULO){
		temp = temp->siguiente;
		prev = prev->siguiente;
	}
	prev->siguiente = NULO;
	delete temp;
	this->final = prev;
}
void Lista::removerInicio(){
	Elemento* temp = this->inicial;
	this->inicial = this->inicial->siguiente;
	delete temp;
}

ostream & operator<<(ostream & out, Lista & l) {
	l.imprimir(out);

	return out;
}

void Lista::imprimir(ostream& out){
	Elemento* actual = this->inicial;
	while (actual != NULO){
		out << *actual<<" ";
		actual = actual->siguiente;
	};
}
void Lista::remover(int posicion){
	Elemento* actual = this->inicial;
	while (--posicion != 0){
		actual = actual->siguiente;
	}
	Elemento* borrar = actual->siguiente;
	actual->siguiente = actual->siguiente->siguiente;
	delete borrar;
}
Elemento* Lista::devolverElemento(int posicion) {
	Elemento *elementoActual;
	Elemento *anteriorAlActual;
	elementoActual = this->inicial;
	for (int i = 0; i < posicion; i++) {
		if (elementoActual->siguiente) {
			elementoActual = elementoActual->siguiente;
		}
		else {
			return NULL;
		}
	}

	anteriorAlActual = this->inicial;
	while (elementoActual->siguiente) {
		elementoActual = elementoActual->siguiente;
		anteriorAlActual = anteriorAlActual->siguiente;
	}

	return anteriorAlActual;
}

Lista::~Lista()
{
}
