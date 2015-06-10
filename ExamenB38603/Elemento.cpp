#include "stdafx.h"
#include "Elemento.h"


Elemento::Elemento()
{
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
