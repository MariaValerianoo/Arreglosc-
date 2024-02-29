#include<iostream>

using namespace std;
/*Dadas las siguientes definiciones y 
asignaciones, ilustra cómo quedaría la 
memoria después de ejecutarlas. */
int main(){
    int A = 1, B = 2, C = 3, *P1, *P2; 
    P1 = &A; 
    P2 = &C; 
    *P1 = (*P2)++; //P1 toma el valor de *P2, luego incrementara el valor de *P2 en 1, despues *p1=3 y *p2=4
    P1 = P2; //ahora p1 esta en direccion a C
    P2 = &B; //ahora p1 esta en direccion a C
    *P1 -= *P2; //a *p1 le restamos p2
    ++*P2; //Incrementa el valor apuntado por p2 en 1
    *P1 *= *P2; //Multiplica el valor apuntado por p1 por el valor apuntado por p2 .
    A = ++*P2 * *P1; //Incrementa el valor apuntado por p2 en 1, despues asigna a A el resultado de multiplicar el valor apuntado por p2  por el valor apuntado por p1.
    P1 = &A; //ahora apunta a la dirección de A
    *P2 = *P1 /= *P2; //Divide el valor apuntado por p1 por el valor apuntado por P2 y asigna el resultado a *p2 .

}