#include<stdio.h>
#include<stdlib.h>

void main(){

    int *ap;
    ap = (int *)calloc(3,sizeof(int));

    for(int i = 0; i<3; i++){
        printf("%i %i\n",*(ap+i), ap[i]);
    }

    *ap = 1;
    *(ap+1) = 2;
    ap[2] = 3;

    for(int i = 0; i<3; i++){
        printf("%i %i\n",*(ap+i), ap[i]);
    }

    ap = realloc(ap, 4);
    for(int i = 0; i<4; i++){
        ap[i] = (i+1)*2;
        printf("%i %i\n",*(ap+i), ap[i]);
    }    

    free(ap);
}