#include<iostream>
using namespace std;
int main(){
    int cant1=0;
    int suma=0;
    cout<<"por favor ingrese la cantidad de minas que quiere ingresar en esta primera casilla: "<<endl;
    cin>>cant1;
    string numeros1[cant1];
    for (int j = 0; j < cant1; j++)
    {
        cout<<"1)si y 2)no"<<endl;
        cout<<"Ingresa si quieres mina: "<<endl;
        cin>>numeros1[j];
        if(j=1){
            suma+=numeros1[j]
        }
     
    }
    for (int i = 0; i < cant1; i++)
    {
        cout<<"Las minas son: "<<suma;
    }
}
