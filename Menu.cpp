#include "Menu.h"

#include "Libro.h"
#include "Utilidades.h"
#include "Crud.h"
#include "Ordenamiento.h"
#include "Busquedas.h"
#include "Intercalacion.h"
#include "generaPDF.h"


#include <iostream>

using namespace std;

void menuPrincipal()
{
    int opcion;
    int opcion2;
	//SE DESPLIEGA MENU PRINCIPAL//
    do
    {
        cout << "\n===================================";
        cout << "\nGESTION DE LIBROS DE DISENO";
        cout << "\n===================================";
        cout << "\n 1. Registrar Libro";
        cout << "\n 2. Mostrar libros";
        cout << "\n 3. Modificar Libro";
        cout << "\n 4. Eliminar Libro";
        cout << "\n 5. Busqueda de Libro";
        cout << "\n 6. Ordenamiento de Registro de Libros";
        cout << "\n 7. Intercalar archivos de Libros";
        cout << "\n 8. Cargar de Libros Inicial";
        cout << "\n 9. Crear PDF Libros";
        cout << "\n 0. Salir";
        cout << "\n\nSeleccione: ";

        cin >> opcion;

        limpiarPantalla();
        
        //SE EJECUTA LA FUNCIÓN QUE CORRESPONDE A LA OPCIÓN ESCOGIDA//

        switch(opcion)
        {
            case 1:
                registrarLibro();
                break;

            case 2:
                mostrarLibros("libros.csv");
                break;

            case 3:
                modificarLibro();
                break;

            case 4:
                eliminarLibro();
                break;

            case 5:
            	
            	cout << "\n===================================";
                cout << "\nBusqueda De Libro";
                cout << "\n===================================";
                cout << "\n1. Busqueda Secuencial";
                cout << "\n2. Busqueda Binaria Iterativa";
                cout << "\n3. Busqueda Binaria Recursiva";
                cout << "\n0. Volver";
                cout << "\n\nSeleccione: ";

                cin >> opcion2;

                limpiarPantalla();
            	switch(opcion2)
                {
                   case 1:
                   int indice;
            	   int numComp;
                   buscarLibroSecuencial(indice, numComp);
                   break;
                   
				   case 2:
                   buscarLibroBinaria();
                   break;

                   case 3:
                   buscarLibroBinariaR();
                   break;
                   
            	   case 0:
                   cout << "\nVolviendo al menu...\n";
                   break;

                   default:
                   cout << "\nOpcion invalida.\n";
                   break;
                }
                break;
            case 6:
            	cout << "\n===================================";
                cout << "\nOrdenamiento de Registro de Libros";
                cout << "\n===================================";
                cout << "\n1. Por ISBN";
                cout << "\n2. Por Titulo";
                cout << "\n3. Por Autor";
                cout << "\n0. Volver";
                cout << "\n\nSeleccione: ";

                cin >> opcion2;

                limpiarPantalla();
            	switch(opcion2)
                {
                   case 1:
                   ordenarPorISBN();
                   break;
                   
				   case 2:
                   ordenarPorNombre();
                   break;

                   case 3:
                   ordenarPorAutor();
                   break;
                   
            	   case 0:
                   cout << "\nVolviendo al menu...\n";
                   break;

                   default:
                   cout << "\nOpcion invalida.\n";
                   break;
                }
                break;

            case 7:
                int opcion3;
                int numComparaciones;
            	cout << "\n===================================";
                cout << "\nIntercalacion Archivos de Libros";
                cout << "\n===================================";
                cout << "\n1. Intercalacion carga y ordenamiento";
                cout << "\n2. Intercalacion Merge";
                cout << "\n3. Comparacion Metodos";
                cout << "\n0. Volver";
                cout << "\n\nSeleccione: ";

                cin >> opcion3;

                limpiarPantalla();
            	switch(opcion3)
                {
                   case 1:
                   intercalarArchivos(numComparaciones);
                   break;

                   case 2:
                   intercalarLibrosMerge(numComparaciones);
                   break;
                   
                   case 3:
                   compararMetodos();
                   break;
                   
            	   case 0:
                   cout << "\nVolviendo al menu...\n";
                   break;

                   default:
                   cout << "\nOpcion invalida.\n";
                   break;
                }
                break;
                
            case 8:
                cargarLibrosInicial();
                break;

            case 9:
                generarPDF("libros.csv");
                break;
            
            case 0:
                cout << "\nHasta luego.\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

        if(opcion != 0)
        {
            pausar();
            limpiarPantalla();
        }

    } while(opcion != 0);
}
