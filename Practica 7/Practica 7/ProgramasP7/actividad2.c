#include<stdio.h>
#include "lista.c"

void main(){

    Lista l = crearLista();
    int op, pos, valor;
    do{
        printf("Eliga la accion a realizar: \n");
        printf("1.Agregar al principio\t");
        printf("2.Agregar al final\n");
        printf("3.Agregar al n-ésimo\t");
        printf("4.Eliminar al principio\n");
        printf("5.Eliminar al final\t");
        printf("6.Eliminar al n-ésimo\n");
        printf("7.Buscar por índice\t");
        printf("8.Eliminar mayores\n");
        printf("9.Imprimir lista\n");

        scanf("%i",&op);
        
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
            scanf("%i",&valor);
            printf("Indica posicion: ");
            scanf("%i", &pos);
            addN_esimo(&l,valor,pos);
            break;
        case 4:
            borrarPrimero(&l);
            break;
        case 5:
            borrarUltimo(&l);
            break;
        case 6:
            printf("Indica posicion: ");
            scanf("%i",&pos);
            borrarN_esimo(&l,pos);
            break;
        case 7:
            printf("Introduzca valor a buscar: ");
            scanf("%i", &valor);
            pos = buscar(l,valor);
            if(pos != -1){
                printf("Se encontro en la posicion: %i\n", pos);
            }else{
                printf("No se encontro el valor en la lista\n");
            }
            break;
        case 8:
            printf("Indica el mayor: ");
            scanf("%i", &valor);
            eliminarMayores(&l,valor);
            break;
        case 9:
            print_list(l);
            break;            
        default:
            break;
        }
    }while(op <= 9 && op >= 1);
    EliminarLista(&l);

}