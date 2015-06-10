// ExamenB38603.cpp: define el punto de entrada de la aplicación de consola.
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
#include "ArbolBinario.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Bienvenido al programa de resolucion de operaciones matematicas" << endl;
	cout << endl;
	cout << "Se van a leer las operaciones del archivo (operaciones.txt)" << endl;

	Lista operaciones; //crear la lista de operaciones
	int cantOperaciones=0; //contar la cantidad de operaciones
	ifstream archivoOperaciones;
	archivoOperaciones.open("operaciones.txt"); //abrir el archivo de operaciones
	if (archivoOperaciones.is_open()) {
		string operacion; //guardar la operacion de la respectiva línea leída
		while (getline(archivoOperaciones, operacion)) {
			operaciones.insertarFinal(new Operacion(operacion));//insertar la operación en la lista de operaciones
			cantOperaciones++;
		}
	}
	archivoOperaciones.close();//cerrar archivo
	cout << " - Se han leido: " << cantOperaciones << " operaciones" << endl;
	cout << " - Se ha terminado de leer el archivo (operaciones.txt)" << endl;
	cout << endl;
	cout << "Se van a escribir los resultados en el archivo (resultados.txt)" << endl;
	ofstream resultados;
	resultados.open("resultados.txt");

	for (int i = 0; i < cantOperaciones; i++){
		
		Elemento* x = operaciones.devolverElemento(i);
		Operacion* operacion = static_cast<Operacion*>(x);
		string exp = operacion->getExpresion();
		Operacion* p = new Operacion(exp);
		ArbolBinario arbol(p);
		double t = 0.0;
		t = arbol.resolver();
		resultados <<*x <<" = "<< t << endl; //Cambiar i por el resultados de evaluación de la expresión
		cout << " - Se resolvio la operacion: " << *x << " resultado: "<< t << endl;
	}

	resultados.close();
	cout << endl;
	cout << "Se ha terminado de escribir los resultados en el archivo (resultados.txt)" << endl;
	cout << "Revise el archivo, para verificar los resultados" << endl;
	cout << endl;
	cout << "El programa ha terminado exitosamente" << endl;
	system("pause");
	return 0;
}