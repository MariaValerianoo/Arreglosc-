#include <iostream>
using namespace std;

struct animal {
    int tipo_a;
    string nombre_a;
    int edad_a;
    string nombreDueño_a;
};

int main() {
    animal *a;
    int tipo, edad;
    string nombre, nombreDueño;
    a = new animal;
    cout << "Bienvenido a la veterinaria Maria Luz" << endl;
    cout << "Ingresa primero qué tipo de animal es tu mascota (1 para perro, 2 para gato, etc.): ";
    cin >> tipo;
    a->tipo_a = tipo; 
    cout << "Ahora dinos el nombre de tu mascota: ";
    cin >> nombre;
    a->nombre_a = nombre; 
    cout << "¿Qué edad tiene tu mascota?: ";
    cin >> edad;
    a->edad_a = edad; 
    cout << "Por último, cuál es el nombre del dueño?: ";
    cin >> nombreDueño;
    a->nombreDueño_a = nombreDueño;
    cout << "\nDatos de la mascota registrada:" << endl;
    cout << "Tipo de animal: " << a->tipo_a << endl;
    cout << "Nombre: " << a->nombre_a << endl;
    cout << "Edad: " << a->edad_a << endl;
    cout << "Nombre del dueño: " << a->nombreDueño_a << endl;
    delete a;

    return 0;
}
