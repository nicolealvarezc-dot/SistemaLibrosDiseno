#include "Ordenamiento.h"
#include "Libro.h"
#include "ProyectoDatos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;


//SE ORDENAN LOS DATOS DEL VECTOR POR ISBN//

void ordenarPorISBN()
{
    vector<Libro> libros;

    cargarLibros(libros, "libros.csv");

    bool intercambio;

    for (int i = 0; i < (int)libros.size() - 1; i++)
    {
        intercambio = false;

        for (int j = 0; j < (int)libros.size() - 1 - i; j++)
        {
            if (libros[j].isbn > libros[j + 1].isbn)
            {
                Libro aux = libros[j];
                libros[j] = libros[j + 1];
                libros[j + 1] = aux;

                intercambio = true;
            }
        }

        if (!intercambio)
        {
            break;
        }
    }

    sobrescribirArchivo(libros, "libros.csv");;

    cout << "\nOrdenado por ISBN.\n";
}

//SE ORDENAN LOS DATOS DEL VECTOR POR TITULO//

void ordenarPorNombre()
{
    vector<Libro> libros;

    cargarLibros(libros, "libros.csv");

    bool intercambio;

    for (int i = 0; i < (int)libros.size() - 1; i++)
    {
        intercambio = false;

        for (int j = 0; j < (int)libros.size() - 1 - i; j++)
        {
            if (libros[j].titulo > libros[j + 1].titulo)
            {
                Libro aux = libros[j];
                libros[j] = libros[j + 1];
                libros[j + 1] = aux;

                intercambio = true;
            }
        }

        if (!intercambio)
        {
            break;
        }
    }

    sobrescribirArchivo(libros, "libros.csv");;

    cout << "\nOrdenado por titulo.\n";
}

//SE ORDENAN LOS DATOS DEL VECTOR POR AUTOR//

void ordenarPorAutor()
{
    vector<Libro> libros;

    cargarLibros(libros, "libros.csv");

    bool intercambio;

    for (int i = 0; i < (int)libros.size() - 1; i++)
    {
        intercambio = false;

        for (int j = 0; j < (int)libros.size() - 1 - i; j++)
        {
            if (libros[j].autor > libros[j + 1].autor)
            {
                Libro aux = libros[j];
                libros[j] = libros[j + 1];
                libros[j + 1] = aux;

                intercambio = true;
            }
        }

        if (!intercambio)
        {
            break;
        }
    }

    sobrescribirArchivo(libros, "libros.csv");;

    cout << "\nOrdenado por autor.\n";
}
