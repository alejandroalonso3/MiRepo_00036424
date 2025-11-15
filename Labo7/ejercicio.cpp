#include <iostream>

#include <fstream>

using namespace std;

void leerArchivo(int numeros[], int &cantidad) {
    ifstream archivo("datos.txt");
    int num;

    cantidad = 0;

    if (!archivo.is_open()) {
        cout << "No se pudo abrir datos.txt" << endl;
        return;
    }

    while (archivo >> num) {
        numeros[cantidad] = num;
        cantidad++;
    }

    archivo.close();
}

void clasificarNumeros(int numeros[], int cantidad) {
    ofstream pares("pares.txt");
    ofstream impares("impares.txt");

    for (int i = 0; i < cantidad; i++) {
        if (numeros[i] % 2 == 0) {
            pares << numeros[i] << endl;
        } else {
            impares << numeros[i] << endl;
        }
    }

    pares.close();
    impares.close();
}

void ordenarArchivo(char nombre[]) {
    ifstream archivo(nombre);
    int temp[200];
    int cantidad = 0;
    int x;

    while (archivo >> x) {
        temp[cantidad] = x;
        cantidad++;
    }

    archivo.close();

    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - 1 - i; j++) {
            if (temp[j] > temp[j + 1]) {
                int aux = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = aux;
            }
        }
    }

    ofstream salida(nombre);
    for (int i = 0; i < cantidad; i++) {
        salida << temp[i] << endl;
    }
    salida.close();
}

void mostrarArchivo(char nombre[]) {
    ifstream archivo(nombre);
    int n;

    cout << "Contenido de " << nombre << ":" << endl;

    while (archivo >> n) {
        cout << n << " ";
    }

    cout << endl << endl;
}

int main() {
    int numeros[200];
    int cantidadNumeros = 0;

    leerArchivo(numeros, cantidadNumeros);
    clasificarNumeros(numeros, cantidadNumeros);

    cout << "ANTES DE ORDENAR" << endl;
    mostrarArchivo((char*)"pares.txt");
    mostrarArchivo((char*)"impares.txt");

    ordenarArchivo((char*)"pares.txt");
    ordenarArchivo((char*)"impares.txt");

    cout << "DESPUES DE ORDENAR" << endl;
    mostrarArchivo((char*)"pares.txt");
    mostrarArchivo((char*)"impares.txt");

    return 0;
}
