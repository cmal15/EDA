#include "listacirc.c"
#include<stdio.h>
#include<stdlib.h>

void main(){

    Lista l = crearLista();
    int op, pos, valor;
    do{
        printf("Indique la accion a realizar:\n");
        printf("1.Añadir al principio\n");
        printf("2.Añadir al final\n");
        printf("3.Añadir al n-esimo\n");
        printf("4.Eliminar al principio\n");
        printf("5.Eliminar al final\n");
        printf("6.Eliminar al n-esimo\n");
        printf("7.Imprimir lista\n");

        scanf("%i", &op);

        switch (op)
        {
        case 1:
            printf("Introduce valor: ");
            scanf("%i", &valor);
            addPrincipioLista(&l,valor);
            break;
        case 2:
            printf("Introduce valor: ");
            scanf("%i", &valor);
            addFinalLista(&l,valor);         
            break;
        case 3:
            printf("Introduce valor: ");
            scanf("%i", &valor); 
            printf("Introduce poscion: ");
            scanf("%i",&pos);
            addN_esimo(&l,valor,pos);        
            break;
        case 4:
            borrarPrimero(&l);
            break;
        case 5:
            borrarUltimo(&l);
            break;
        case 6:
            printf("Indica la poscion: ");
            scanf("%i", &pos);
            borrarN_esimo(&l,pos);
            break;
        case 7:
            print_list(l);
            break;                                    
        default:
            break;
        }

    }while(op <= 7 && op >= 1);
    EliminarLista(&l);
}