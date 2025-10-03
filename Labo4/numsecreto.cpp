#include <iostream>
using namespace std;

int main() {
int numeroSecreto = 5;
int numingresado;

do {
cout << "Adivina el numero secreto: " << endl;
cin >> numingresado;

if (numingresado < numeroSecreto)
cout << "El numero es muy bajo. Intenta de nuevo" ;
else if (numingresado > numeroSecreto)
cout << "El numero es muy alto. Intenta de nuevo";
} while (numingresado != numeroSecreto);

cout << "Felicidades Adivinaste el numero";
return 0;
}