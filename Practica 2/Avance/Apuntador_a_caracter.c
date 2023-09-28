#include<stdio.h>

/*
    Este programa crea un apuntador de tipo carácter.
*/

int main(){
    char *ap, c;
    c = 'x';
    ap = c;

    //Imprime el carácter de la localidad a la que apunta
    printf("Carácter: %c\n", *ap);
    //Imprime el código ASCII de la localidad a la que apunta
    printf("Código ASCII: %d\n", *ap);
    //Imprime la dirección de memoria de la localidad a la que apunta
    printf("Dirección de memoria: %d\n", ap);

    return 0;
}