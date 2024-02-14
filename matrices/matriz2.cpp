#include<iostream>

using namespace std;

int main(){
    int col=0;
    int filas=0;
    cout<<"Ingresa de cuantas columnas quieres tu maquina: "<<endl;
    cin>>col;
    cout<<"Ingresa la cantidad de filas que quieres: "<<endl;
    cin>>filas;
    string maquina[filas][col];
    for (int j = 0; j < col; j++)
    {
        cout<<"Ingresa de cuantas columnas quieres tu maquina "<<j<<endl;
        cin>>maquina[j];
        
     
    }
    for (int i = 0; i < filas; i++)
    {
        cout<<"Ingresa de cuantas columnas quieres tu maquina "<<i<<endl;
        cin>>maquina[i];
        
     
    }
    
}