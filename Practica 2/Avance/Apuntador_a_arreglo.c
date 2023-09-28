#include<stdio.h>

/*
    Este programa crea un apuntador de tipo entero
    que apunta al inicio de un arreglo
*/

int main(){
    short arr[5], *apArr;
    apArr = &arr[0];
    //Imprime la diracción de memoria del arreglo en la posición [0]
    printf("Dirección del arreglo en la primera posición: %x\n", &arr[0]);
    //Imprime la dirección de memoria del arreglo
    //(El nombre del arreglo es un apuntador)
    printf("Dirección del arreglo: %x\n", &arr);
    //Imprime la diracción de memoria del apuntador apArr
    printf("Dirección del apuntador: %x\n", apArr);

    return 0;
}