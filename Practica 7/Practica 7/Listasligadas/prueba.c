#include"listaSimple.c"
#include<stdio.h>

void main(){

    lista l = crearLista();

    //enlistarAlFinal(&l,crearNodo(1));
    for (int i = 0; i < 5; i++){
        enlistarAlFinal(&l,crearNodo(i));
        printf("%i\n",i);
    }
    
    imprimirLista(l);

    printf("Esternocleidomastoideo");
    borrarLista(&l);

}