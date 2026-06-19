#ifndef PROYECTODATOS_H
#define PROYECTODATOS_H

#include "Libro.h"
#include <vector>

using namespace std;


void guardarLibro(Libro ejemplar);


void cargarLibros(vector<Libro>& libros, const string& nombreArchivo);


void sobrescribirArchivo(const vector<Libro>& libros, const string& nombreArchivo);


bool existeArchivo(string& nombreArchivo);

#endif
