#include "Intercalacion.h"
#include "Libro.h"
#include "ProyectoDatos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>    // para clock()
#include <chrono>   // para mayor precision
#include <iomanip>

using namespace std;

//SE LEE LOS DATOS DE UNA VARIABLE STRING PARA ALMACENARLOS EN UNA VARIABLE DE TIPO Libro//

Libro leerLinea(string linea)
{
    Libro p;

    string campo;
    stringstream ss(linea);

    getline(ss, campo, '|');
    p.isbn = atoi(campo.c_str());

    getline(ss, p.titulo, '|');
    getline(ss, p.autor, '|');
    getline(ss, p.genero, '|');

    getline(ss, campo, '|');
    p.anio = atoi(campo.c_str());

    getline(ss, campo, '|');
    p.precio = atof(campo.c_str());

    return p;
}

//SE LEE LOS DATOS DE DOS ARCHIVOS PARA FUSIONARLOS ORDENADAMENTE EN UN ARCHIVO//

void intercalarArchivos(int& comparaciones)
{
    vector<Libro> libros;

    ifstream archivo1("libros.csv");
    ifstream archivo2("nuevosLibros.csv");

    if (!archivo1.is_open() || !archivo2.is_open())
    {
        cout << "\nNo se pudieron abrir los archivos.\n";
        return;
    }

    string linea;

    while (getline(archivo1, linea))
    {
        libros.push_back(leerLinea(linea));
    }

    while (getline(archivo2, linea))
    {
        libros.push_back(leerLinea(linea));
    }

    archivo1.close();
    archivo2.close();

    // Ordenar por ISBN (bubble sort)
    for (int i = 0; i < (int)libros.size() - 1; i++)
    {
        bool intercambio = false;

        for (int j = 0; j < (int)libros.size() - 1 - i; j++)
        {
        	comparaciones++;
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

    ofstream resultado("librosFusionados_1.csv");

    if (!resultado.is_open())
    {
        cout << "\nError al crear archivo fusionado.\n";
        return;
    }

    for (int i = 0; i < (int)libros.size(); i++)
    {
        resultado
            << libros[i].isbn << "|"
            << libros[i].titulo << "|"
            << libros[i].autor << "|"
            << libros[i].genero << "|"
            << libros[i].anio << "|"
            << libros[i].precio
            << endl;
    }

    resultado.close();

    //remove("libros.csv");

    //rename("librosFusionados.csv", "libros.csv");

    cout << "\nIntercalacion ordenada realizada correctamente." << endl;
    cout << "Total de libros en librosFusionados_1.csv : " << libros.size() << "\n";
}

void intercalarLibrosMerge(int& comparaciones)
{
    ifstream archivo1("libros.csv");
    ifstream archivo2("nuevosLibros.csv");

    if (!archivo1.is_open())
    {
        cout << "\nNo se pudo abrir libros.csv\n";
        return;
    }

    if (!archivo2.is_open())
    {
        cout << "\nNo se pudo abrir actualizacionLibros.csv\n";
        return;
    }

    ofstream resultado("librosFusionados_2.csv");

    if (!resultado.is_open())
    {
        cout << "\nError al crear librosFusionados_2.csv\n";
        return;
    }

    string linea1, linea2;
    bool hay1 = (bool)getline(archivo1, linea1);
    bool hay2 = (bool)getline(archivo2, linea2);

    int total = 0;

    // mientras ambos archivos tengan datos
    while (hay1 && hay2)
    {
        comparaciones++;
		Libro l1 = leerLinea(linea1);
        Libro l2 = leerLinea(linea2);

        if (l1.isbn < l2.isbn)
        {
            resultado << linea1 << "\n";
            hay1 = (bool)getline(archivo1, linea1);
        }
        else if (l1.isbn > l2.isbn)
        {
            resultado << linea2 << "\n";
            hay2 = (bool)getline(archivo2, linea2);
        }
        else
        {
            // ISBN duplicado: se conserva el de libros.csv
            cout << "ISBN duplicado: " << l1.isbn << " - se conserva libros.csv\n";
            resultado << linea1 << "\n";
            hay1 = (bool)getline(archivo1, linea1);
            hay2 = (bool)getline(archivo2, linea2);
        }

        total++;
    }

    // volcar lo que queda de archivo1
    while (hay1)
    {
        resultado << linea1 << "\n";
        hay1 = (bool)getline(archivo1, linea1);
        total++;
    }

    // volcar lo que queda de archivo2
    while (hay2)
    {
        resultado << linea2 << "\n";
        hay2 = (bool)getline(archivo2, linea2);
        total++;
    }

    archivo1.close();
    archivo2.close();
    resultado.close();

    cout << "\nIntercalacion completada.\n";
    cout << "Total de libros en librosFusionados_2.csv : " << total << "\n";
}

void compararMetodos()
{
    int comparacionesM1 = 0;
    int comparacionesM2 = 0;

    // ===== MÉTODO 1 =====
    auto inicio1 = chrono::high_resolution_clock::now();

    intercalarArchivos(comparacionesM1);   // pasas el contador por referencia

    auto fin1 = chrono::high_resolution_clock::now();
    auto tiempo1 = chrono::duration_cast<chrono::microseconds>(fin1 - inicio1).count();

    // ===== MÉTODO 2 =====
    auto inicio2 = chrono::high_resolution_clock::now();

    intercalarLibrosMerge(comparacionesM2);        // pasas el contador por referencia

    auto fin2 = chrono::high_resolution_clock::now();
    auto tiempo2 = chrono::duration_cast<chrono::microseconds>(fin2 - inicio2).count();

    // ===== RESULTADO =====
    cout << "\n========================================\n";
    cout << "        COMPARACION DE METODOS\n";
    cout << "========================================\n";
    cout << "                  Metodo 1    Metodo 2\n";
    cout << "               (Carga+Sort)   (Merge)\n";
    cout << "----------------------------------------\n";
    cout << "Comparaciones: "
         << setw(10) << left << comparacionesM1
         << "  "
         << setw(10) << left << comparacionesM2 << "\n";
    cout << "Tiempo (us):   "
         << setw(10) << left << tiempo1
         << "  "
         << setw(10) << left << tiempo2 << "\n";
    cout << "========================================\n";
}
