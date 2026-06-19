#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>
using namespace std;

void limpiarPantalla();

void pausar();

int leerEntero(const string& mensaje);

double leerDouble(const string& mensaje);

string leerTextoNoVacio(const string& mensaje);

int anchoPadding(const string& texto, int anchoDeseado);

#endif
