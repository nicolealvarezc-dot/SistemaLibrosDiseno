
extern "C" {
   #include "pdfgen.h"
}
#include <vector>
#include <string>
#include "Libro.h"
#include "ProyectoDatos.h"
#include <iostream>

using namespace std;

void generarPDF(const string& nombreArchivo)
{
    vector<Libro> libros;

    cargarLibros(libros, nombreArchivo);

    if (libros.empty())
    {
        cout << "\nNo existen libros. :/ \n";
        return;
    }

    cout << "\n===== REPORTE DE LIBROS =====\n";

    cout << "\n--------------------------\n";
    
    cout << "\nGenerando PDF\n";
    
    // 2. Inicializar el documento PDF
    struct pdf_doc *pdf = pdf_create(PDF_A4_WIDTH, PDF_A4_HEIGHT, NULL);
    if (!pdf) return;
    pdf_append_page(pdf);

    // 3. Encabezado del Reporte
    // Título principal (Coordenadas X=50, Y=780)
    pdf_add_text(pdf, NULL, "REPORTE DE LIBROS", 18, 50, 780, PDF_BLACK);
    
    // Línea divisoria debajo del título
    pdf_add_line(pdf, NULL, 50, 765, 545, 765, 1.5, PDF_BLACK);

    // 4. Encabezados de la Tabla (Y = 740)
    int y_pos = 740;
    pdf_add_text(pdf, NULL, "ISBN", 11, 50, y_pos, PDF_BLACK);
    pdf_add_text(pdf, NULL, "Titulo", 11, 120, y_pos, PDF_BLACK);
    pdf_add_text(pdf, NULL, "Autor", 11, 270, y_pos, PDF_BLACK);
    pdf_add_text(pdf, NULL, "Genero", 11, 380, y_pos, PDF_BLACK);
    pdf_add_text(pdf, NULL, "Año", 11, 480, y_pos, PDF_BLACK);
    pdf_add_text(pdf, NULL, "Precio", 11, 520, y_pos, PDF_BLACK);
    
    // Línea debajo de los encabezados de columna
    pdf_add_line(pdf, NULL, 50, y_pos - 10, 545, y_pos - 10, 1.0, PDF_BLACK);

    // 5. Recorrer el vector y renderizar las filas dinámicamente
    y_pos = 710; // Posición de la primera fila de datos
    int espacio_filas = 25; // Distancia en puntos entre cada registro

    for (size_t i = 0; i < libros.size(); i++) {
        // Convertir variables numéricas a texto plano para el PDF
        string isbn_str = to_string(libros[i].isbn);
        string anio_str = to_string(libros[i].anio);
        string precio_str = to_string(libros[i].precio);
        // Cortar decimales excedentes del string del monto
        precio_str = precio_str.substr(0, precio_str.find(".") + 3); 

        // Imprimir cada columna respetando el eje X asignado
        pdf_add_text(pdf, NULL, isbn_str.c_str(), 10, 50, y_pos, PDF_BLACK);
        pdf_add_text(pdf, NULL, libros[i].titulo.c_str(), 10, 120, y_pos, PDF_BLACK);
        pdf_add_text(pdf, NULL, libros[i].autor.c_str(), 10, 270, y_pos, PDF_BLACK);
        pdf_add_text(pdf, NULL, libros[i].genero.c_str(), 10, 380, y_pos, PDF_BLACK);
        pdf_add_text(pdf, NULL, anio_str.c_str(), 10, 480, y_pos, PDF_BLACK);
        pdf_add_text(pdf, NULL, precio_str.c_str(), 10, 520, y_pos, PDF_BLACK);

        // Línea tenue para separar los registros
        pdf_add_line(pdf, NULL, 50, y_pos - 8, 545, y_pos - 8, 0.5, PDF_BLACK);

        // Decrementar Y para que la siguiente fila se dibuje más abajo
        y_pos -= espacio_filas; 
    }

    // 6. Guardar y cerrar el documento
    pdf_save(pdf, "Reporte_libros.pdf");
    pdf_destroy(pdf);

    return;
}

