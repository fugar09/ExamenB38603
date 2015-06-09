#include "stdafx.h"
#include "Elemento.h"


Elemento::Elemento()
{
	//Constructor que hace que un elemento sea un tipo numero
	hIzq = NULL;
	hDer = NULL;
	siguiente = NULL;
}



Elemento::~Elemento()
{
	if (hIzq != NULL) {
		delete hIzq;
	}
	if (hDer != NULL) {
		delete hDer;
	}
}

ostream & operator<<(ostream & out, const Elemento & e) {
	e.imprimir(out);
	return out;
}
