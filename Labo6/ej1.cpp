#include <iostream>

using namespace std;

struct Direccion {
    string calle;
    int numero;
    string ciudad;
};

struct Estudiante {
    string nombre;
    int edad;
    float notas[5];
    Direccion dire;
};

void ingresarEstudiantes(Estudiante* lista, int cant) {
    for (int i = 0; i < cant; i++) {
        cout << "Nombre del estudiante: ";
        getline(cin, lista[i].nombre);
        if(lista[i].nombre=="") getline(cin, lista[i].nombre);
        cout << "Edad: ";
        cin >> lista[i].edad;
        cout << "Ingrese 5 notas: ";
        for (int j = 0; j < 5; j++) {
            cin >> lista[i].notas[j];
        }
        cout << "Calle: ";
        getline(cin, lista[i].dire.calle);
        if(lista[i].dire.calle=="") getline(cin, lista[i].dire.calle);
        cout << "Numero: ";
        cin >> lista[i].dire.numero;
        cout << "Ciudad: ";
        getline(cin, lista[i].dire.ciudad);
        if(lista[i].dire.ciudad=="") getline(cin, lista[i].dire.ciudad);
    }
}

void mostrarEstudiantes(Estudiante* lista, int cant) {
    for (int i = 0; i < cant; i++) {
        cout << endl << "Nombre: " << lista[i].nombre << endl;
        cout << "Edad: " << lista[i].edad << endl;
        cout << "Notas: ";
        for (int j = 0; j < 5; j++) cout << lista[i].notas[j] << " ";
        cout << endl;
        cout << "Direccion: " << lista[i].dire.calle << " " << lista[i].dire.numero << ", " << lista[i].dire.ciudad << endl;
    }
}

int buscarEstudiante(Estudiante* lista, int cant, string n) {
    for (int i = 0; i < cant; i++) {
        if (lista[i].nombre == n) {
            return i;
        }
    }
    return -1;
}

void modificarEstudiante(Estudiante* lista, int cant) {
    string n;
    cout << "Nombre del estudiante a modificar: ";
    getline(cin, n);
    if(n=="") getline(cin, n);
    int pos = buscarEstudiante(lista, cant, n);
    if (pos == -1) {
        cout << "No se encontro." << endl;
    } else {
        cout << "Nuevo nombre: ";
        getline(cin, lista[pos].nombre);
        if(lista[pos].nombre=="") getline(cin, lista[pos].nombre);
        cout << "Nueva edad: ";
        cin >> lista[pos].edad;
        cout << "Nuevas notas: ";
        for (int j = 0; j < 5; j++) cin >> lista[pos].notas[j];
        cout << "Nueva calle: ";
        getline(cin, lista[pos].dire.calle);
        if(lista[pos].dire.calle=="") getline(cin, lista[pos].dire.calle);
        cout << "Nuevo numero: ";
        cin >> lista[pos].dire.numero;
        cout << "Nueva ciudad: ";
        getline(cin, lista[pos].dire.ciudad);
        if(lista[pos].dire.ciudad=="") getline(cin, lista[pos].dire.ciudad);
    }
}

int main() {
    int cant;
    cout << "Cuantos estudiantes: ";
    cin >> cant;
    Estudiante* lista = new Estudiante[cant];
    int op;
    do {
        cout << endl;
        cout << "1. Ingresar" << endl;
        cout << "2. Mostrar" << endl;
        cout << "3. Buscar" << endl;
        cout << "4. Modificar" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> op;
        if (op == 1) {
            cin.ignore();
            ingresarEstudiantes(lista, cant);
        } else if (op == 2) {
            mostrarEstudiantes(lista, cant);
        } else if (op == 3) {
            string n;
            cout << "Nombre a buscar: ";
            getline(cin, n);
            if(n=="") getline(cin, n);
            int pos = buscarEstudiante(lista, cant, n);
            if (pos != -1) {
                cout << "Nombre: " << lista[pos].nombre << endl;
                cout << "Edad: " << lista[pos].edad << endl;
                cout << "Notas: ";
                for (int j = 0; j < 5; j++) cout << lista[pos].notas[j] << " ";
                cout << endl;
                cout << "Direccion: " << lista[pos].dire.calle << " " << lista[pos].dire.numero << ", " << lista[pos].dire.ciudad << endl;
            } else {
                cout << "No encontrado." << endl;
            }
        } else if (op == 4) {
            modificarEstudiante(lista, cant);
        } else if (op == 5) {
            cout << "Fin del programa." << endl;
        } else {
            cout << "Opcion invalida." << endl;
        }
    } while (op != 5);
    delete[] lista;
    return 0;
}
