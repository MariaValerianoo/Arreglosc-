#include <iostream>
using namespace std;

struct animal {
    int tipo;
    string nombre;
    int edad;
    string nombreDueño;
};

int main() {
    animal *a;
    int tipo, edad;
    string nombre, nombreDueño;
    a = new animal;
    cout << "Bienvenido a la veterinaria Maria Luz" << endl;
    cout << "Ingresa primero qué tipo de animal es tu mascota (1 para perro, 2 para gato, etc.): ";
    cin >> tipo;
    a->tipo = tipo; 
    cout << "Ahora dinos el nombre de tu mascota: ";
    cin >> nombre;
    a->nombre = nombre; 
    cout << "¿Qué edad tiene tu mascota?: ";
    cin >> edad;
    a->edad = edad; 
    cout << "Por último, cuál es el nombre del dueño?: ";
    cin >> nombreDueño;
    a->nombreDueño = nombreDueño;
    cout << "\nDatos de la mascota registrada:" << endl;
    cout << "Tipo de animal: " << a->tipo << endl;
    cout << "Nombre: " << a->nombre << endl;
    cout << "Edad: " << a->edad << endl;
    cout << "Nombre del dueño: " << a->nombreDueño << endl;
    delete a;

    return 0;
}
