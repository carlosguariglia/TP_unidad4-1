/*
Para el ejercicio anterior, Abrir el archivo y mostrar las frases x pantalla,
con cada frase en una línea, con Interlineado.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void clearConsole();

int main() {
    ifstream fichero; // Crea un objeto de tipo ifstream
    string frase;
    int primerapasada = 0;
    fichero.open("frasesDeBjarme.txt"); // Abre el archivo
    if (!fichero.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int menu;
    
    do {
        clearConsole();
        cout << "****************************" << endl;
        cout << "Frases de Bjarme" << endl;
        cout << "****************************" << endl;
        cout << "1. Mostrar una frase" << endl;
        cout << "2. Mostrar todas las frases" << endl;
        cout << "3. Salir" << endl;
        cout << "Introduce una opcion: " << endl;
        cout << "****************************" << endl;
        cin >> menu;

        switch (menu) {
            case 1:
                getline(fichero, frase); // Lee una frase del archivo y la almacena en la variable frase
                if (frase== "")
                    {cout << "No hay mas frases" << endl;}
                else
                    {
                    cout << frase << endl; // Imprime la frase
                    }
                cout << "Presione ENTER para continuar" << endl;
                cin.ignore();
                cin.get(); 
                break;
            case 2:
                getline(fichero, frase);
                while (frase != "")
                {   cout << frase << endl;
                    getline(fichero, frase);
                }
                if (frase == "")
                    if (primerapasada == 0) // Si es la primera vez que se ejecuta el bucle, no hay frases
                        primerapasada=1;
                    else
                    {cout << "No hay mas frases" << endl;
                    }
                cout << "Presione ENTER para continuar" << endl;
                cin.ignore();
                cin.get();
                break; // Termina el bucle si la frase es vacía
            case 3:
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
        }
    } while (menu != 3);

fichero.close(); // Cierra el archivo
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