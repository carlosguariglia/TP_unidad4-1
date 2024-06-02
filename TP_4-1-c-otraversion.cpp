/*
        c. Para el  Archivo del ejercicio (a) contar la cantidad de palabras que
        hay x línea, luego mostrar la cantidad total y el promedio de palabras x línea.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int contarcantidaddepalabras(ifstream &fichero);
int contadordelineas(ifstream &fichero);

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

    cantidaddelineas = contadordelineas(fichero);
    fichero.clear(); // Limpia las banderas de error del archivo
    fichero.seekg(0, ios::beg); // Mueve el puntero de lectura al inicio del archivo

    totalpalabras= contarcantidaddepalabras(fichero);

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


/*  
    Función para contar la cantidad de lineas de un archivo
    se recorre el fichero del principio al final y se cuentan las lineas
    usando getline(fichero, palabra) con esto se lee cada linea.   

    se usa 
    fichero.clear(); // Limpia las banderas de error del archivo
    fichero.seekg(0, ios::beg); // Mueve el puntero de lectura al inicio del archivo
    para "reiniciar" el archivo, para que se lea desde el principio y se puede
    recorrer de nuevo

*/

int contadordelineas(ifstream& fichero) 
{                                       
    int cantlineas = 0;                       
    string palabra;
    while (getline(fichero, palabra)) {
        cantlineas++;
        }
    
    return cantlineas;
}

/*  
    Función para contar la cantidad de palabras de una linea
    se recorre el fichero del principio al final y se cuentan las palabras
    usando fichero >> palabra con esto va leyendo cada "caracter" hasta que encuentra un espacio
    entonces se usa para contar la cantidad de palabras
*/

int contarcantidaddepalabras(ifstream& fichero) 
{                                       
    int cantpalabras = 0;                           
    string palabra;
    while (fichero >> palabra)
    {
        cantpalabras++;
    }
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