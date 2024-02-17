#include <iostream>
using namespace std;

int main (){

    /*string names[5] = {"Gabriela","Juan","Ivan","Laura","Samuel"};

    for (int i = 0; i < names->length(); i++){
        cout << names[i]<<endl;
    }

    string names2[5];

    for (int i = 0; i < 5; i++){
        cout<<"Digite un nombre: "<<endl; 
        cin>>names2[i];
    }

    cout<<"Mostrar nombres"<<endl;

    for (int i = 0; i < names2->length(); i++){
        cout << names2[i]<<endl;
    }*/

    int cantidad = 0;

    cout<<"Digite la cantidad de frutas que quiere registrar: "<<endl; 
    cin>>cantidad;

    string frutas[cantidad];

    for (int i = 0; i < cantidad; i++){
        cout<<"Digite el nombre de la fruta: "<<endl;
        cin>>frutas[i];
    }

    cout<<"Mostrar nombres"<<endl;

    for (int i = 0; i < frutas->length(); i++){
        cout << frutas[i]<<endl;
    }


    return 0;
