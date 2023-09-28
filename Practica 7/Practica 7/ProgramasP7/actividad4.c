#include<stdio.h>
#include "listaCircComputadora.c"

void main(){
    Lista l = crearLista();
    int op, pos;
    char marca[10];

    do{
        printf("Seleccione:\n");
        printf("1.Agregar al inicio\t2.Agregar al final\n");
        printf("3.Agregar al n-esimo\t4.Borrar primero\n");
        printf("5.Borrar ultimo\t6.Borrar n-esimo\n");
        printf("7.Buscar por marca\t8.Recorrer lista\t");
        scanf("%i",&op);

        switch (op)
        {
        case 1:
            addPrincipioLista(&l,crearComputadora());
            break;
        
        case 2:
            addFinalLista(&l,crearComputadora());
            break;

        case 3:
            printf("Introduzca posicion: ");
            scanf("%i", &pos);
            addN_esimo(&l,crearComputadora(), pos);
            break;

        case 4:
            borrarPrimero(&l);
            break;

        case 5:
            borrarUltimo(&l);
            break;
        
        case 6:
            printf("Introduzca posicion: ");
            scanf("%i", &pos);
            borrarN_esimo(&l,pos);
            break;

        case 7:
            printf("Introduzca marca a buscar: ");
            fflush(stdin);
            scanf("%[^\n]",marca);
            pos = buscar(l,marca);
            if(pos == -1){
                printf("No se encontro una computadora de esa marca\n");
            }else{
                printf("Se encontro en el elemento %i\n",pos);             
            }
            break;

        case 8:
            recorrerLista(l);
            break;
        default:
            break;
        }

    }while(op >= 1 && op <= 8);

    EliminarLista(&l);
}