/*
        c. Para el  Archivo del ejercicio (a) contar la cantidad de palabras que
         hay x línea, luego mostrar la cantidad total y el promedio de palabras x línea.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int contarcantidaddepalabras(string linea);


int main()
{
    ifstream fichero("frasesDeBjarme.txt");

    if (!fichero.is_open())
    {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    string linea;

    int cantidaddelineas = 0;
    int totalpalabras = 0;
    int promedio = 0;
    while (getline(fichero, linea))
    {   totalpalabras=contarcantidaddepalabras(linea) + totalpalabras;
        cantidaddelineas++;
    }
    promedio = totalpalabras / cantidaddelineas;
    cout << "cantidad de lineas: " << cantidaddelineas << endl;
    cout << "total de palabras: " << totalpalabras << endl;
    cout << "promedio de palabras por linea: " << promedio << endl;

    fichero.close();
    return 0;
}

int contarcantidaddepalabras(string linea)
{
    int cantpalabras = 0;
    cout << "longitud de la linea: " << linea.length();
    cin.get();

    for (int i = 0; i < linea.length(); i++)
    {
        if (linea[i] == ' ')
        {
            cantpalabras++;
        }
    }
    return cantpalabras;
}