#pragma once

using namespace std;

class Elemento
{
protected:
	Elemento * hIzq, *hDer;
	Elemento * siguiente;


public:
	Elemento();
	virtual ~Elemento();
};

