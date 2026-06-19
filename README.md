====================================================
  SISTEMA DE GESTIÓN DE LIBROS DE DISEÑO
  CARRERA: DISEÑO DIGITAL
  INTEGRANTES: NICOLE ALVAREZ 
  README — Instrucciones de compilación y ejecución
====================================================

====================================================
      SISTEMA DE GESTIÓN DE LIBROS DE DISEÑO
====================================================

DESCRIPCIÓN
-----------
Aplicación de consola desarrollada en C++ para la gestión de
libros de diseño mediante archivos CSV.

El sistema permite:

- Registrar libros
- Mostrar libros almacenados
- Modificar registros
- Eliminar registros
- Buscar libros por ISBN
- Ordenar registros
- Intercalar archivos de libros
- Cargar datos iniciales
- Generar reportes PDF

Todos los registros son almacenados en archivos CSV utilizando
el siguiente formato:

ISBN|Titulo|Autor|Genero|Anio|Precio


====================================================
ESTRUCTURA DEL PROYECTO
====================================================

main.cpp
    Punto de entrada del programa.

Menu.cpp / Menu.h
    Menú principal y navegación del sistema.

Libro.h
    Definición de la estructura Libro.

Crud.cpp / Crud.h
    Operaciones de registro, consulta, modificación
    y eliminación de libros.

Busquedas.cpp / Busquedas.h
    Implementación de búsquedas:
      - Secuencial
      - Binaria Iterativa
      - Binaria Recursiva

Ordenamiento.cpp / Ordenamiento.h
    Ordenamiento de registros por:
      - ISBN
      - Título
      - Autor

Intercalacion.cpp / Intercalacion.h
    Fusión e intercalación de archivos de libros.

ProyectoDatos.cpp / ProyectoDatos.h
    Lectura y escritura de archivos CSV.

Utilidades.cpp / Utilidades.h
    Funciones auxiliares de validación y manejo
    de consola.

generaPDF.cpp / generaPDF.h
    Generación de reportes PDF.

pdfgen.c / pdfgen.h
    Biblioteca utilizada para la creación de PDFs.


====================================================
REQUISITOS
====================================================

- Compilador g++ con soporte para C++11 o superior.
- Sistema operativo Windows.
- Biblioteca pdfgen incluida en el proyecto.
- Consola con soporte UTF-8.

El programa utiliza:

    windows.h
    system("cls")

por lo que está orientado a Windows.


====================================================
COMPILACIÓN
====================================================

Compilar todos los archivos fuente:

g++ -std=c++11 ^
main.cpp ^
Menu.cpp ^
Crud.cpp ^
Busquedas.cpp ^
Ordenamiento.cpp ^
Intercalacion.cpp ^
ProyectoDatos.cpp ^
Utilidades.cpp ^
generaPDF.cpp ^
pdfgen.c ^
-o SistemaLibros

O en una sola línea:

g++ -std=c++11 main.cpp Menu.cpp Crud.cpp Busquedas.cpp Ordenamiento.cpp Intercalacion.cpp ProyectoDatos.cpp Utilidades.cpp generaPDF.cpp pdfgen.c -o SistemaLibros


====================================================
EJECUCIÓN
====================================================

Ejecutar:

SistemaLibros.exe

o

./SistemaLibros


====================================================
ESTRUCTURA DE LOS DATOS
====================================================

Archivo principal:

libros.csv

Formato de registro:

ISBN|Titulo|Autor|Genero|Anio|Precio

Ejemplo:

1001|Diseño UX Moderno|Alan Cooper|UX|2024|45.50


====================================================
ARCHIVOS UTILIZADOS
====================================================

libros.csv
    Base de datos principal.

librosInicial.csv
    Datos iniciales para carga masiva.

nuevosLibros.csv
    Archivo utilizado para pruebas de intercalación.

librosFusionados_1.csv
    Archivo generado por la intercalación ordenada.

Reporte_libros.pdf
    Reporte PDF generado por el sistema.


====================================================
FUNCIONALIDADES DEL MENÚ
====================================================

1. Registrar Libro
   Agrega un nuevo libro.
   El ISBN debe ser único.

2. Mostrar Libros
   Lista todos los registros almacenados.

3. Modificar Libro
   Actualiza los datos de un libro existente.

4. Eliminar Libro
   Elimina un libro mediante su ISBN.

5. Búsqueda de Libro

   5.1 Búsqueda Secuencial
       Recorre los registros uno por uno.

   5.2 Búsqueda Binaria Iterativa
       Requiere que los registros estén
       ordenados por ISBN.

   5.3 Búsqueda Binaria Recursiva
       Requiere que los registros estén
       ordenados por ISBN.

6. Ordenamiento de Registros

   - Ordenar por ISBN
   - Ordenar por Título
   - Ordenar por Autor

7. Intercalar Archivos

   Fusiona:
       libros.csv
       nuevosLibros.csv

   y genera:

       librosFusionados_1.csv

8. Cargar Libros Iniciales

   Copia los registros desde:

       librosInicial.csv

   hacia:

       libros.csv

9. Crear PDF

   Genera el archivo:

       Reporte_libros.pdf

   con todos los registros almacenados.


====================================================
VALIDACIONES IMPLEMENTADAS
====================================================

- ISBN único.
- Campos de texto obligatorios.
- Validación de enteros.
- Validación de números decimales.
- Manejo de archivos inexistentes.
- Verificación de ordenamiento para
  búsquedas binarias.


====================================================
OBSERVACIONES
====================================================

- Las búsquedas binarias solo funcionan cuando
  el archivo está ordenado por ISBN.

- El sistema almacena la información utilizando
  el carácter "|" como separador de campos.

- La generación del PDF utiliza la biblioteca
  pdfgen incluida en el proyecto.

====================================================