#include<stdio.h>
#include"listaDobleCircular.h"

void main(){

    Lista list = crearLista();
    int op, valor, pos = 0;
    
    do{
        printf("Seleccione una accion\n");
        printf("1.Añadir al final\t2.Añadir al inicio\n");
        printf("3.Añadir en Iesimo\t4.Borrar del final\n");
        printf("5.Borrar del inicio\t6.Borrar del Iesimo\n");
        printf("7.Imprimir lista\t8.Recorrer lista\n");
        printf("9.Buscar valores\t10.Buscar primera coincidencia\n");
        printf("11.Salir\n");
        scanf("%i",&op);

        switch (op)
        {
        case 1:
            printf("Introduzca el valor: ");
            scanf("%i",&valor);
            addFinalLista(&list,valor);
            break;

         case 2:
            printf("Introduzca el valor: ");
            scanf("%i",&valor);
            addPrincipioLista(&list,valor);
            break;

        case 3:
            printf("Introduzca el valor: ");
            scanf("%i",&valor);
            printf("Introduzca la posicion: ");
            scanf("%i", &pos);
            addIesimoLista(&list,valor,pos);
            break;

        case 4:
            borrarPrimero(&list);
            break;

        case 5:
            borrarUltimo(&list);
            break;

        case 6:
            printf("Introduzca la posicion: ");
            scanf("%i", &pos);
            borrarIesimoLista(&list,pos);
            break;

        case 7:
            print_list(list);
            break;

        case 8:
            recorrerLista2(list);
            break;

        case 9:
            printf("Introduzca el valor a buscar: ");
            scanf("%i",&valor);
            printf("El valor aparece %i vece(s) en la lista\n", buscarApariciones(list,valor));
            break;

        case 10:
            printf("Introduzca el valor a buscar: ");
            scanf("%i",&valor);   
            pos = buscarPrimeraCoincidencia(list,valor);
            if(pos != -1){
                printf("Se encontro el valor en la %i posicion\n",pos);
            }else{
                printf("No se encontro el valor en la lista\n");
            }   
            break;

        default:
            break;
        }

    }while(op != 11);

}