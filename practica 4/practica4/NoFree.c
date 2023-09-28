#include<stdio.h>
#include<stdlib.h>

void main(){
    double *ap;
    ap = (double *)malloc(24*sizeof(double));

    printf("ap[2] con calloc: %d, %d\n", ap[2], &ap[2]);
    ap = realloc(ap, 0);
    printf("ap[2] direccion despues de realloc: %d\n",&ap[2]);
    if(ap == NULL){
        printf("Es NULL");
    } else{
        printf("No es NULL");
    }
    free(ap);
}