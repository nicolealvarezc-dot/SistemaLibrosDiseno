#include "Busquedas.h"
#include "Libro.h"
#include "ProyectoDatos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>


using namespace std;
//SE BUSCAN DATOS DE UN Libro PARTICULAR//

void buscarLibroSecuencial(int& indice, int& numComp)
{
    vector<Libro> libros;

    cargarLibros(libros, "libros.csv");

    int isbnBuscar;

    cout << "\nISBN a buscar: ";
    cin >> isbnBuscar;

    bool encontrado = false;

    for (int i = 0; i < (int)libros.size(); i++)
    {
        if (libros[i].isbn == isbnBuscar)
        {
            encontrado = true;

            cout << "\nLibro encontrado: "<<i+1<<" comparaciones\n";
            cout << "\n--------------------------";
            cout << "\nISBN: " << libros[i].isbn;
            cout << "\nNombre del ejemplar: " << libros[i].titulo;
            cout << "\nNombre del Autor: " << libros[i].autor;
            cout << "\nGénero: " << libros[i].genero;
            cout << "\nAño de Publicación: " << libros[i].anio;
            cout << "\nPrecio: " << libros[i].precio;
            cout << "\n--------------------------\n";
            
            indice = i;
            numComp = i+1;

            break;
        }
    }

    if (!encontrado)
    {
        cout << "\nNo existe.\n";
    }
}


//SE VERIFICA QUE LOS DATOS DEL VECTOR ESTEN ORDENADOS//

bool estaOrdenadoPorISBN()
{
    vector<Libro> libros;

    cargarLibros(libros, "libros.csv");

    for (int i = 0; i < (int)libros.size() - 1; i++)
    {
        if (libros[i].isbn > libros[i + 1].isbn)
        {
            return false;
        }
    }

    return true;
}


//SE BUSCA LOS DATOS DE UN Libro EN PARTICULAR POR METODO BIANRIO//

void buscarLibroBinaria()
{
    if (!estaOrdenadoPorISBN())
    {
        cout << "\nDebe ordenar por ISBN primero.\n";
        return;
    }

    vector<Libro> libros;

    cargarLibros(libros, "libros.csv");

    int buscado;

    cout << "\nISBN a buscar: ";
    cin >> buscado;

    int inicio = 0;
    int fin = (int)libros.size() - 1;
    int contador = 0;

    bool encontrado = false;

    while (inicio <= fin)
    {
        int medio = (inicio + fin) / 2;
        contador++;

        if (libros[medio].isbn == buscado)
        {
            cout << "\nLibro encontrado: "<<contador<<" paso/s\n";
            cout << "\n--------------------------";
            cout << "\nISBN: " << libros[medio].isbn;
            cout << "\nNombre del ejemplar: " << libros[medio].titulo;
            cout << "\nNombre del Autor: " << libros[medio].autor;
            cout << "\nGénero: " << libros[medio].genero;
            cout << "\nAño de Publicación: " << libros[medio].anio;
            cout << "\nPrecio: " << libros[medio].precio;
            cout << "\n--------------------------\n";

            encontrado = true;
            break;
        }

        if (buscado < libros[medio].isbn)
        {
            fin = medio - 1;
        }
        else
        {
            inicio = medio + 1;
        }
    }

    if (!encontrado)
    {
        cout << "\nNo encontrado.\n";
    }
}

void buscarBinariaRecursiva(const vector<Libro>& libros, int buscado, int inicio, int fin, int& contador)
{
    // Caso base: El elemento no existe en el vector
    if (inicio > fin) 
    {
        cout << "\nNo encontrado.\n";
        return;
    }

    int medio = inicio + (fin - inicio) / 2; // Evita desbordamiento de memoria
    contador++;

    // Caso base: Elemento encontrado
    if (libros[medio].isbn == buscado)
    {
        cout << "\nLibro encontrado: " << contador << " paso/s\n";
        cout << "\n--------------------------";
        cout << "\nISBN: " << libros[medio].isbn;
        cout << "\nNombre del ejemplar: " << libros[medio].titulo;
        cout << "\nNombre del Autor: " << libros[medio].autor;
        cout << "\nGénero: " << libros[medio].genero;
        cout << "\nAño de Publicación: " << libros[medio].anio;
        cout << "\nPrecio: " << libros[medio].precio;
        cout << "\n--------------------------\n";
        return;
    }

    // Casos recursivos
    if (buscado < libros[medio].isbn)
    {
        // Buscar en la mitad izquierda
        buscarBinariaRecursiva(libros, buscado, inicio, medio - 1, contador);
    }
    else
    {
        // Buscar en la mitad derecha
        buscarBinariaRecursiva(libros, buscado, medio + 1, fin, contador);
    }
}


void buscarLibroBinariaR()
{
    if (!estaOrdenadoPorISBN())
    {
        cout << "\nDebe ordenar por ISBN primero.\n";
        return;
    }

    vector<Libro> libros;
    cargarLibros(libros, "libros.csv"); 

    if (libros.empty()) 
    {
        cout << "\nEl archivo o vector está vacío.\n";
        return;
    }

    int buscado;
    cout << "\nISBN a buscar: ";
    cin >> buscado;

    int inicio = 0;
    int fin = (int)libros.size() - 1;
    int contador = 0;

    // Llamada inicial a la función recursiva
    buscarBinariaRecursiva(libros, buscado, inicio, fin, contador);
}

