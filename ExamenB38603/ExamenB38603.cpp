// ExamenB38603.cpp: define el punto de entrada de la aplicaci�n de consola.
//

#include "stdafx.h"
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

int _tmain(int argc, _TCHAR* argv[])
{
	Lista operaciones; //crearlalista de operaciones
	int cantOperaciones=0; //contar la cantidad de operaciones
	ifstream archivoOperaciones;
	archivoOperaciones.open("operaciones.txt"); //abrir el archivo de operaciones
	if (archivoOperaciones.is_open()) {
		string operacion; //guardar la operacion de la respectiva l�nea le�da
		while (getline(archivoOperaciones, operacion)) {
			operaciones.insertarFinal(new Operacion(operacion));//insertar la operaci�n en la lista de operaciones
			cantOperaciones++;
		}
	}
	archivoOperaciones.close();//cerrar archivo

	cout << "La lista de Operaciones es de: " << operaciones << endl;
	Elemento* x = operaciones.devolverElemento(2);
	cout << "Elemento 2 es:"<< *x << endl;
	cout << "hay " << cantOperaciones << " operaciones" << endl;

	ofstream resultados;
	resultados.open("resultados.txt");
	for (int i = 0; i < cantOperaciones; i++){
		

		Elemento* x = operaciones.devolverElemento(i);
		resultados <<*x <<" = "<< i << endl; //Cambiar i por el resultados de evaluaci�n de la expresi�n
	}

	resultados.close();

	system("pause");
	return 0;
}

