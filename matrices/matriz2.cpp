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
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<"Ingresa el producto y precio que ingresaras: "<< i << j<<endl;
            cin>>maquina[i][j];
            
        }
    
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<maquina[i][j];
        }
     cout<<endl;

    }


}
