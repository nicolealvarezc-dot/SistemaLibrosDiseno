====================================================
  SISTEMA DE GESTIÓN DE PROYECTOS DE DISEÑO
  CARRERA: DISEÑO DIGITAL
  INTEGRANTES: NICOLE ALVAREZ / REYNA YANA  
  README — Instrucciones de compilación y ejecución
====================================================


REQUISITOS PREVIOS
------------------
- Compilador g++ con soporte C++11 o superior
- Sistema operativo Windows (el sistema usa system("cls") para limpiar pantalla)
- Tener instalado MinGW o TDM-GCC si se compila desde Windows sin IDE


ARCHIVOS FUENTE
---------------
Asegúrese de tener todos estos archivos en la misma carpeta:

  main.cpp
  Menu.h
  Menu.cpp
  Utilidades.h
  Utilidades.cpp
  Proyecto.h
  ProyectoLogica.h
  ProyectoLogica.cpp
  ProyectoDatos.h
  ProyectoDatos.cpp


COMPILACIÓN
-----------
Abra una terminal (cmd o PowerShell) en la carpeta del proyecto
y ejecute el siguiente comando:

  g++ -std=c++11 main.cpp Menu.cpp Utilidades.cpp ProyectoLogica.cpp ProyectoDatos.cpp -o SistemaGestion

Esto generará el ejecutable: SistemaGestion.exe


EJECUCIÓN
---------
Una vez compilado, ejecute el programa con:

  ./SistemaGestion

O simplemente haciendo doble clic en SistemaGestion.exe desde el explorador.


ARCHIVOS DE DATOS
-----------------
El programa trabaja con archivos de texto en la misma carpeta del ejecutable:

  proyectos.txt         — Base de datos principal. Se crea automáticamente
                          al registrar el primer proyecto.

  nuevosProyectos.txt   — Archivo necesario para usar la opción 9
                          (Intercalar archivos). Debe crearlo manualmente
                          con el mismo formato que proyectos.txt.

Formato de cada línea en los archivos de datos:
  id|nombre|categoria|cliente|anio|presupuesto

  Ejemplo:
  1|Rediseño App Bancaria|UX|Banco Nacional|2024|15000.5


NOTAS
-----
- La búsqueda binaria (opción 6) requiere que los datos estén
  ordenados por ID (opción 7) antes de usarse.

- La intercalación (opción 9) fusiona proyectos.txt con
  nuevosProyectos.txt, ordena el resultado por ID y reemplaza
  el archivo principal.

- Si proyectos.txt no existe al iniciar, algunas opciones
  mostrarán el mensaje "Error al abrir archivos". Registre
  al menos un proyecto primero (opción 1).


====================================================
