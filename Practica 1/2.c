#include<stdio.h>
#define C 10
void main(){
    int lista[C]={8,33,196,74,85,73,251,77,12,66};
    int valor=0, i=0;
    do{
        printf("\n %d",lista[i]);
        if(lista[i]%4==0){
            valor+=lista[i];
        }
        i++;
    }while(i<C);
    printf("\n El valor es: %d \n", valor);
}