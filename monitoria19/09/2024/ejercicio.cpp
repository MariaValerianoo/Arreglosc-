#include <iostream>
#include <string>
using namespace std;

struct alien{
    string especie;
    string color;
    string tamaño; 
    
};
int main()
{
    alien *gris;
    string especie_G, color_B;
    int tamaño_M;
    
    gris = new alien; 
    cout<< "Cual es el nombre de la especie"<<endl;
    cin>> especie_G;
    gris-> especie=especie_G;
    
    cout<< "Que color tiene la especie"<<endl;
    cin>>color_B;
    gris-> color=color_B;
    cout<<"Que tamaño tiene la especie"<<endl;
    cin>>tamaño_M;
    gris-> tamaño=tamaño_M;
    
    
    cout<<" Aqui los datos de tu alien"<<endl;
    cout<<"La especie es "<< gris->especie<<endl;
    cout<<"El color es "<< gris->color<<endl;
    cout<<"El tamaño es "<< gris->tamaño<<endl;
    
    delete gris;
    return 0;
}