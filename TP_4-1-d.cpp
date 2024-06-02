/*
Para el archivo de “frasesDeBjarme.txt” indicar cual es la palabra mas Larga.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void clearConsole();

int main() 
{   clearConsole();
    string filename="frasesDeBjarme.txt";
    ifstream fichero(filename);  // abre el archivo en modo lectura

    if (!fichero.is_open()) // comprueba si el archivo se abrio correctamente sino
    {                       //  muestra un error (retorna 1) y termina el programa
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    string linea; // variable para almacenar una linea del archivo
    string palabra; // variable para almacenar una palabra de la linea
    string palabraMasLarga = ""; // variable para almacenar la palabra mas larga
    
    fichero >> palabra;
    if (palabra!="")
    {          
        palabraMasLarga = palabra;
        while (fichero >> palabra) 
        {
        if (palabra.length() > palabraMasLarga.length())
            palabraMasLarga = palabra;
        }
    } else
    {
        cout << "No hay palabras en el archivo" << endl;
    }

    cout << "************************************************" << endl;
    cout << "De la lectura del archivo: \"" << filename << "\" " << endl;
    cout << "La palabra mas larga es: " << palabraMasLarga << endl;
    cout << "************************************************" << endl;
    cout << endl << "Presiona ENTER para continuar..." << endl;
    cin.get();
    fichero.close();
    return 0;
}

void clearConsole() {
    #ifdef __unix__
        system("clear");
    #elif __APPLE__
        system("clear");
    #elif defined(_WIN32) || defined(WIN64)
        system("cls");
    #endif
}