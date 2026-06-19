#include "ProyectoDatos.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

//VERIFICA SI EXISTE UN ARCHIVO

bool existeArchivo(string& nombreArchivo)
{
    //ifstream archivo("libros.csv");
    
    ifstream archivo(nombreArchivo.c_str());
    bool existe = archivo.good();
    archivo.close();
    return existe;
}


//SE GUARDA Ejemplar de Libro en Archivo

void guardarLibro(Libro ejemplar)
{
    ofstream archivo("libros.csv", ios::app);

    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    archivo
        << ejemplar.isbn << "|"
        << ejemplar.titulo << "|"
        << ejemplar.autor << "|"
        << ejemplar.genero << "|"
        << ejemplar.anio << "|"
        << ejemplar.precio
        << endl;

    archivo.close();
}


//SE LEEN LOS REGISTROS DESDE UN ARCHIVO HACIA UN ARREGLO

void cargarLibros(vector<Libro>& libros, const string& nombreArchivo)
{
    libros.clear();

    //ifstream archivo("libros.csv");
    
    ifstream archivo(nombreArchivo.c_str());
    
    if (!archivo.is_open())
    {
        cout << "Error al abrir archivos\n";
        return;
    }

    string linea;

    while (getline(archivo, linea))
    {
        Libro ejemplar;

        stringstream ss(linea);
        string isbnStr, anioStr, precioStr;

        getline(ss, isbnStr, '|');
        getline(ss, ejemplar.titulo, '|');
        getline(ss, ejemplar.autor, '|');
        getline(ss, ejemplar.genero, '|');
        getline(ss, anioStr, '|');
        getline(ss, precioStr, '|');

        stringstream conversionId(isbnStr);
        conversionId >> ejemplar.isbn;

        stringstream conversionAnio(anioStr);
        conversionAnio >> ejemplar.anio;

        stringstream conversionPresupuesto(precioStr);
        conversionPresupuesto >> ejemplar.precio;

        libros.push_back(ejemplar);
    }

    archivo.close();
}

//SE GUARDAN LOS DATOS DE UN ARREGLO HACIA UN ARCHIVO//

void sobrescribirArchivo(const vector<Libro>& libros, const string& nombreArchivo)
{
    ofstream archivo(nombreArchivo.c_str(), ios::trunc);

    if (!archivo.is_open())
    {
        cout << "Error al abrir archivo." << endl;
        return;
    }

    for (int i = 0; i < (int)libros.size(); i++)
    {
        archivo
            << libros[i].isbn << "|"
            << libros[i].titulo << "|"
            << libros[i].autor << "|"
            << libros[i].genero << "|"
            << libros[i].anio << "|"
            << libros[i].precio
            << endl;
    }

    archivo.close();
}



void cargarLibrosInicial()
{
	vector<Libro> libros;
	cargarLibros(libros, "librosInicial.csv");
	sobrescribirArchivo(libros, "libros.csv");
	cout << "\nLibros cargados.\n";
}
