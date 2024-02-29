#include<iostream>
using namespace std;

int main() {
    int cant1 = 0;
    int suma = 0;

    cout << "Por favor ingrese la cantidad de minas que quiere ingresar en esta primera casilla: " << endl;
    cin >> cant1;
    int numeros1[cant1];

    for (int j = 0; j < cant1; j++) {
        cout << "Ingrese 1 si hay mina y 0 si no hay mina: " << endl; 
        cin >> numeros1[j];
        if (numeros1[j] == 1) {
            suma++;
        }
        while (numeros1[j]!=1 && numeros1[j]!=0)
        {
            cout<<"Numero incorrecto, vuelve a intentarlo\n";
            cout << "Ingrese 1 si hay mina y 0 si no hay mina: " << endl; 
            cin >> numeros1[j];
            if (numeros1[j] == 1) {
            suma++;
            }
        }
    }
    cout << "Las minas son: ";
    for (int i = 0; i < cant1; i++) {
        cout << numeros1[i] << " ";
    }
    cout << endl;
    cout << "El total de minas es: " << suma << endl;

    return 0;
}

