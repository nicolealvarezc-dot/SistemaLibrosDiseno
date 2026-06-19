#include "Utilidades.h"

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


void pausar()
{
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

void limpiarPantalla()
{
    system("cls");
}

int leerEntero(const string& mensaje)
{
    int valor;
    while (true)
    {
        cout << mensaje;
        cin >> valor;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Dato invalido, ingrese un numero entero.\n";
        }
        else
        {
            return valor;   // sin cin.ignore() aqui
        }
    }
}

double leerDouble(const string& mensaje)
{
    double valor;
    while (true)
    {
        cout << mensaje;
        cin >> valor;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Dato invalido, ingrese un numero valido.\n";
        }
        else
        {
            return valor;   // sin cin.ignore() aqui
        }
    }
}

string leerTextoNoVacio(const string& mensaje)
{
    string valor;
    while (true)
    {
        cout << mensaje;
        getline(cin, valor);

        if (valor.empty())
        {
            cout << "El campo no puede estar vacio.\n";
        }
        else
        {
            return valor;
        }
    }
}

int anchoPadding(const string& texto, int anchoDeseado)
{
    int bytesExtra = 0;
    for (int i = 0; i < (int)texto.size(); i++)
    {
        unsigned char c = (unsigned char)texto[i];
        // bytes que inician caracter de 2 bytes: 110xxxxx
        if (c >= 0xC0 && c <= 0xDF)
        {
            bytesExtra++;
        }
        // bytes que inician caracter de 3 bytes: 1110xxxx
        else if (c >= 0xE0 && c <= 0xEF)
        {
            bytesExtra += 2;
        }
    }
    return anchoDeseado + bytesExtra;
}
