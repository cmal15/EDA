#include "listaSimple.c"

void imprimirLista1(nodo h){
    printf("%i\n",h.info);
    if(h.next != NULL){
        imprimirLista1(*h.next);
    }
}

void main(){
    lista l = crearLista();
    enlistarAlFinal(&l,crearNodo(1));
    enlistarAlFinal(&l,crearNodo(2));
    enlistarAlFinal(&l,crearNodo(3));
    enlistarAlFinal(&l,crearNodo(4));
    enlistarAlFinal(&l,crearNodo(5));

    imprimirLista1(*l.head);
}