#include<stdio.h>
#define tam 8
int MostrarArreglo(int *arr);

void main(){
    int arr[tam];
    int op, continuar = 1, suma = 0, producto = 1, multiplo;

    for(int i = 0; i < tam; i++){
        arr[i] = 0;
    }
    

    do{
        printf("Seleccione la operación a realizar al arreglo de 8 elementos.\n");
        printf("1)Ingresar o modificar elementos del arreglo.\n");
        printf("2)Mostrar el resultado de la suma de los elementos.\n");
        printf("3)Mostrar el resultado de la multiplicacion de los elementos.\n");
        printf("4)Realizar la suma de los elementos divisibles entre 4.\n");
        printf("5)Multiplicar cada elemento del arreglo por un número dado.\n");
        printf("6)Salir\n");
        scanf("%i", &op);
        MostrarArreglo(arr);

        switch (op)
        {
        case 1:
            printf("Indique con que modificar los valores del arreglo.\n");
            for(int i = 0; i < tam; i++){
                printf("Arreglo[%i]= ", i);
                scanf("%i", &arr[i]);
            }
            break;
        case 2:
            suma = 0;
            for(int i = 0; i < tam; i++){
                suma += arr[i];
            }
            printf("\nLa suma de todos los elementos es: %i", suma);
            break;

        case 3:
            producto = 1;
            for(int i = 0; i < tam; i++){
                producto *= arr[i];
            }
            printf("\nLa multiplicación de todos los elementos es: %i", producto);
            break;            

        case 4:
            suma = 0;
            for(int i = 0; i < tam; i++){
                if(arr[i]%4 == 0){
                    suma += arr[i];
                }
            }
            printf("\nLa suma de todos los elementos divisibles entre 4 es: %i", suma);
            break;

        case 5:
            printf("Ingrese por cuanto quiere multiplicar los elementos del arreglo: ");
            scanf("%i", &multiplo);
            for(int i = 0; i < tam; i++){
                arr[i] *= multiplo;
            }
            break;

        case 6:
            continuar = 0;
            break;

        default:
            break;
        }

        if(op != 6){
            MostrarArreglo(arr);
            printf("Para hacer algo más ingrese 1, de lo contrario cualquier otro numero.");
            scanf("%i", &continuar);
        }

    }while(continuar == 1);
}

int MostrarArreglo(int *arr){
    printf("\nArreglo actual:\n");
    for(int i = 0; i < tam; i++){
        printf("Arreglo[%i]= %i\n", i, arr[i]);
    }
}