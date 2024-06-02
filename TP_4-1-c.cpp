/*
        c. Para el  Archivo del ejercicio (a) contar la cantidad de palabras que
        hay x línea, luego mostrar la cantidad total y el promedio de palabras x línea.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int contarcantidaddepalabras(string linea);
void clearConsole();

int main()
{   clearConsole();   
    string filename = "frasesDeBjarme.txt";
    ifstream fichero(filename);  // abre el archivo en modo lectura

    if (!fichero.is_open()) // comprueba si el archivo se abrio correctamente sino
    {                       //  muestra un error (retorna 1) y termina el programa
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    string linea; // variable para almacenar una linea del archivo
    
    int cantidaddelineas = 0; // variable para contar la cantidad de lineas
    int totalpalabras = 0;    // variable para contar la cantidad de palabras
    int promedio = 0;         // variable para mostrar el promedio de palabras por linea

    while (getline(fichero, linea))  // lee una linea del archivo la pone en la variable linea
    {   totalpalabras=contarcantidaddepalabras(linea) + totalpalabras; 
        cantidaddelineas++;
    }

    promedio = totalpalabras / cantidaddelineas;
    
    cout << "************************************************" << endl;
    cout << "De la lectura del archivo: \"" << filename << "\" " << endl;
    cout << "La cantidad de lineas es: " << cantidaddelineas << endl;
    cout << "El total de palabras es: " << totalpalabras << endl;
    cout << "El promedio de palabras por linea es: " << promedio << endl;
    cout << "************************************************" << endl;
    
    fichero.close();   // cierra el archivo
    cout << "Presione ENTER para terminar..." << endl;
    cin.get();
    return 0;
}

/*  cuenta la cantidad de palabras de una linea, el for lo hace es contar los espacios
    entre palabras por eso al final se revisa con un if si el ultimo elemento no es un espacio
    significa que hay una palabra mas. 
    "En este ejemplo" al recorrer el string contaria 2 palabras (espacios entre palabras)
    entonces al revisar que el string no termina con un espacio, contaria 3 palabras.
*/

int contarcantidaddepalabras(string linea) 
{                                       
    int cantpalabras = 0;                       
    for (int i = 0; i < linea.length(); i++)
    {
        if (linea[i] == ' ')
            cantpalabras++;
    }
    if (linea[linea.length() - 1] != ' ') //si al final no hay un espacio cuenta la ultima palabra
        cantpalabras++;
    return cantpalabras;
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