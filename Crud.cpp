#include "Crud.h"
#include "Libro.h"
#include "ProyectoDatos.h"
#include "Utilidades.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>


using namespace std;

//SE REGISTRA NUEVO Libro EN EL ARCHIVO TXT//

void registrarLibro()
{
    Libro p;

    // --- VALIDACIÓN DE ISBN ÚNICO ---
    vector<Libro> libros;
    cargarLibros(libros, "libros.csv");

    bool isbnRepetido;
    do {
        isbnRepetido = false;

        /*-- 
		cout << "\nISBN: ";
        cin >> p.isbn;
        cin.ignore();
		--*/
        
        p.isbn = leerEntero("\nISBN: ");                          // <-- validado
        cin.ignore();   // limpia el \n que dejó leerEntero, solo una vez
        
        if (p.isbn == 0)
        {
            cout << "\nRegistro Cancelado :(\n";
            return;	
		}

        for (int i = 0; i < (int)libros.size(); i++)
        {
            if (libros[i].isbn == p.isbn)
            {
                isbnRepetido = true;
                cout << "\nEse ISBN ya existe, ingrese uno diferente.\n";
                break;
            }
        }

    } while (isbnRepetido);
    
    /*--

    cout << "Nombre del ejemplar: ";
    getline(cin, p.titulo);

    cout << "Nombre del Autor: ";
    getline(cin, p.autor);

    cout << "Género: ";
    getline(cin, p.genero);

    cout << "Año de Publicación: ";
    cin >> p.anio;

    cout << "Precio: ";
    cin >> p.precio;
    --*/
    
    p.titulo     = leerTextoNoVacio("Nombre del ejemplar: "); // <-- validado
    p.autor  = leerTextoNoVacio("Nombre del Autor: "); // <-- validado
    p.genero    = leerTextoNoVacio("Género: ");             // <-- validado
    p.anio       = leerEntero("Año de Publicación: ");                       // <-- validado
    p.precio = leerDouble("Precio: ");              // <-- validado

    guardarLibro(p);

    cout << "\nLibro registrado correctamente :D.\n";
}

//SE MUESTRAN TODOS LOS LIBROS//

void mostrarLibros(const string& nombreArchivo)
{
    vector<Libro> libros;

    cargarLibros(libros, nombreArchivo);

    if (libros.empty())
    {
        cout << "\nNo existen libros. :/ \n";
        return;
    }

    cout << "\n===== LISTA DE LIBROS =====\n";

    for (int i = 0; i < (int)libros.size(); i++)
    {
        /*
		cout << libros[i].isbn        << " | "
             << libros[i].titulo    << " | "
             << libros[i].autor << " | "
             << libros[i].genero   << " | "
             << libros[i].anio      << " | "
             << libros[i].precio
             << "\n";
        
    	
    	cout << setw(4)  << left << libros[i].isbn
          << setw(26) << left << libros[i].titulo
          << setw(18) << left << libros[i].autor
          << setw(38) << left << libros[i].genero
          << setw(6)  << left << libros[i].anio
          << libros[i].precio
          << "\n";
        */
        cout << setfill('0') << setw(9)  << right << libros[i].isbn
         << setfill(' ') << "  |  " 
         << setw(anchoPadding(libros[i].titulo, 36)) << left << libros[i].titulo
         << setw(anchoPadding(libros[i].autor,  28)) << left << libros[i].autor
         << setw(anchoPadding(libros[i].genero, 22)) << left << libros[i].genero
         << setw(6)  << left << libros[i].anio
         << fixed << setprecision(2) << libros[i].precio
         << "\n";
         

    }
    cout << "\n--------------------------\n";
}

//SE MODIFICAN DATOS DE UN PROYECTO PARTICULAR//

void modificarLibro()
{
    vector<Libro> libros;

    cargarLibros(libros, "libros.csv");

    int isbnBuscar;
    bool encontrado = false;

    cout << "\nISBN a modificar: ";
    cin >> isbnBuscar;
    cin.ignore();

    for (int i = 0; i < (int)libros.size(); i++)
    {
        if (libros[i].isbn == isbnBuscar)
        {
            encontrado = true;

            /*--
			cout << "Nuevo titulo del ejemplar: ";
            getline(cin, libros[i].titulo);

            cout << "Nueva autor (UX / UI): ";
            getline(cin, libros[i].autor);

            cout << "Nuevo genero: ";
            getline(cin, libros[i].genero);

            cout << "Nuevo ano: ";
            cin >> libros[i].anio;

            cout << "Nuevo precio: ";
            cin >> libros[i].precio;
            --*/
            
            libros[i].titulo     = leerTextoNoVacio("Nombre del ejemplar: "); // <-- validado
            libros[i].autor  = leerTextoNoVacio("Nombre del Autor: "); // <-- validado
            libros[i].genero    = leerTextoNoVacio("Género: ");             // <-- validado
            libros[i].anio       = leerEntero("Año de Publicación: ");                       // <-- validado
            libros[i].precio = leerDouble("Precio: ");              // <-- validado

            break;
        }
    }

    if (encontrado)
    {
        sobrescribirArchivo(libros, "libros.csv");;
        cout << "\nLibro modificado. :D \n";
    }
    else
    {
        cout << "\nLibro no encontrado. :(( \n";
    }
}

//SE ELIMINAN DATOS DE UN PROYECTO PARTICULAR//

void eliminarLibro()
{
    vector<Libro> libros;

    cargarLibros(libros, "libros.csv");

    int isbnBuscar;

    cout << "\nISBN a eliminar: ";
    cin >> isbnBuscar;

    int posicion = -1;

    for (int i = 0; i < (int)libros.size(); i++)
    {
        if (libros[i].isbn == isbnBuscar)
        {
            posicion = i;
            break;
        }
    }

    if (posicion == -1)
    {
        cout << "\nLibro no encontrado.\n";
        return;
    }

    libros.erase(libros.begin() + posicion);

    sobrescribirArchivo(libros, "libros.csv");;

    cout << "\nLibro eliminado.\n";
}


