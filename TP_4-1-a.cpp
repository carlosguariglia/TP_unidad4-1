/*
Crea un programa que lea un archivo "frasesDeBjarme.txt" que contiene varias frases
y las guarde en una variable. El programa leera las frases que el usuario teclea y
 terminará cuando la frase introducida sea "fin" (esa frase no 
deberá guardarse en el fichero) y
las guarde en la variable junto con las frases ya leidas. 
al terminar se guardara en un archivo fichero llamado “frasesDeBjarme.txt”.

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    ifstream ficheroEntrada("frasesDeBjarme.txt"); // Abre el archivo en modo lectura
    ofstream ficheroSalida; // Se usará para escribir en el archivo
    string frases; // Variable para almacenar todas las frases
    string frase;

    // Verifica si el archivo se abrió correctamente
    if (!ficheroEntrada.is_open()) 
    {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    // Lee todas las frases del archivo y las concatena en la variable 'frases'
    while (getline(ficheroEntrada, frase)) 
    {
        frases += frase + "\n";
    }

    // Cierra el archivo de entrada
    ficheroEntrada.close();

    // Solicita al usuario que ingrese nuevas frases
    cout << "Introduce una frase (escribe 'fin' para terminar): ";
    getline(cin, frase);

    while (frase != "fin") 
    {
        frases += frase + "\n";
        cout << "Introduce una frase (escribe 'fin' para terminar): ";
        getline(cin, frase);
    }

    // Abre el archivo en modo escritura (se sobreescribirá el contenido)
    ficheroSalida.open("frasesDeBjarme.txt");

    // Verifica si el archivo se abrió correctamente
    if (!ficheroSalida.is_open()) 
    {
        cerr << "Error al abrir el archivo para escribir." << endl;
        return 1;
    }

    // Escribe todas las frases concatenadas en el archivo
    ficheroSalida << frases;

    // Cierra el archivo de salida
    ficheroSalida.close();

    return 0;
}
