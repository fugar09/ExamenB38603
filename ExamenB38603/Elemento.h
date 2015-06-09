#pragma once

using namespace std;


class Elemento
{
friend class ArbolBinario;
friend class Lista;
friend ostream & operator<<(ostream &, const Elemento &);

private:

	Elemento * hIzq, *hDer;
	Elemento * siguiente;


public:
	Elemento();
	virtual ~Elemento();
	virtual void imprimir(ostream &) const=0;
};
ostream & operator<<(ostream &, const Elemento &);

