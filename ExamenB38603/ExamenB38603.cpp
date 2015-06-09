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
using namespace std;

Lista descomponerExpresion(char*);
bool isDigit(char ch);
bool isOperator(char ch);

int _tmain(int argc, _TCHAR* argv[])
{
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

	cout << "La lista de Operaciones es de: " << operaciones << endl;
	Elemento* x = operaciones.devolverElemento(2);
	cout << "Elemento 2 es:"<< *x << endl;
	cout << "hay " << cantOperaciones << " operaciones" << endl;

	ofstream resultados;
	resultados.open("resultados.txt");

	Operacion* prueba = static_cast<Operacion*>(x);
	char* test1 = prueba->getExpresion();
	Lista pruebaLista;
	pruebaLista = descomponerExpresion(test1);
	cout << pruebaLista << endl;

	for (int i = 0; i < cantOperaciones; i++){
		

		Elemento* x = operaciones.devolverElemento(i);
		resultados <<*x <<" = "<< i << endl; //Cambiar i por el resultados de evaluación de la expresión
	}

	resultados.close();

	system("pause");
	return 0;
}
Lista descomponerExpresion(char* s) {
	Lista l;
	bool ejecuto= false;
	bool parar = false;
	//while (s != NULL || s != nullptr || s != "\0" ||parar) {
	while (!parar) {
		ejecuto = false;
		if (isDigit(*s)) {
			l.insertarFinal(new Operando(*s-'0'));
			s++;
			ejecuto = true;
		}
		else if (isOperator(*s)) {
			if (*s == '+') {
				l.insertarFinal(new OperadorSuma());
			}
			else if (*s == '-') {
				l.insertarFinal(new OperadorResta());
			}
			else if (*s == '*') {
				l.insertarFinal(new OperadorMultiplicar());
			}
			else if (*s == '/') {
				l.insertarFinal(new OperadorDividir());
			}
			s++;
			ejecuto = true;
		}
		else if (*s == '(') {
			char* s_i = s; //posición de memoria donde encontró el parentesis
			int parentesisAbierto = 0;
			int parentesisCerrado = 0;
			do  {
				if (*s == '(') {
					parentesisAbierto++;
				}
				else if (*s == ')') {
					parentesisCerrado++;
				}
				s++;
			} while (parentesisCerrado != parentesisAbierto);
			int size = s - s_i;
			string expresion;
			//for (int i = 0; i < size; i++){
				expresion.append(s_i);
				//s_i++;
			//}
			l.insertarFinal(new Operacion(expresion));
			ejecuto = true;
		}
		if (!ejecuto){
			parar = true;

		}
	}
	return l;
}

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}
bool isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

