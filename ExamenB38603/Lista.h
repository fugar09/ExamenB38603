#pragma once

#include "Elemento.h"
using namespace std;

class Lista {

	friend ostream & operator<<(ostream &, Lista &);

private:
	Elemento* inicial;
	Elemento* final;
	int contador;

public:
	Lista();
	virtual ~Lista();
	bool listaVacia();
	void insertarFinal(Elemento*);
	void insertarInicio(Elemento*);
	void insertar(Elemento*, int);
	void imprimir(ostream&);

	void removerFinal();
	void removerInicio();
	void remover(int);
	Elemento* devolverElemento(int);
};

ostream & operator<<(ostream &, Lista &);