#include<stdio.h>
#include<math.h>

void LlenarArreglo(int *arr);
int BinarioPuro(int arr[]);

int main(){
    int arr[10], op, continuar = 1, i, aux;
    printf("Introduzca los bits del numero\n");
    LlenarArreglo(arr);
    do{
        printf("Para continuar cambiar el arreglo introduzca 1.");
        scanf("%i", &op);
        if(op == 1){
            LlenarArreglo(arr);
        }
        
        printf("\nElija la como transformar el arreglo a decimal.\n 1. Binario Puro\n2. Punto fijo(5 bit entero, y 5 bit decimal)\n3. Representación complemento a2.\n");
        printf("4. Salir\n");
        scanf("%i", &op);

        switch (op)
        {
        case 1:
        /*
            int numero = 0;
            for(i = 1; i < 10; i++){
                aux = pow(2,(9-i));
                if(arr[i] == 1){
                    numero += aux;
                }
            }
            if(arr[0] == 1){
                numero *= (-1);
            }
        */
            int numero = BinarioPuro(arr);
            printf("Numero= %i\n", numero);
            break;
        case 2:
            float num = 0, auxiliar = 0;
            for(i = 1; i < 5; i++){
                aux = pow(2,4-i);
                if(arr[i] == 1){
                    num += aux;
                }
            }
            for(i = 5; i < 10; i++){
                auxiliar = pow(2,i-4);
                if(arr[i] == 1){
                    num += 1/auxiliar;
                }
            }
            if(arr[0] == 1){
                num *= (-1);
            }
            printf("Numero= %f\n", num);
            break;
        case 3:
            int complemento[10];
            for(i = 9; i >= 0; i--){
                if(arr[i] == 1){
                    complemento[i] = arr[i];
                    break;
                } else {
                    if(arr[i] == 0){
                        complemento[i] = 0;
                    } else {
                        complemento[i] = 1;
                    }
                }
            }   
            while (i>=0)
            {
                i--;
                if(arr[i] == 0){
                    complemento[i] = 1;
                } else {
                    complemento[i] = 0;
                }
            }

            printf("El complemento a 2 en binario es:");
            for(i = 0; i < 10; i++){
                printf("%i ", complemento[i]);
            }
            printf("\nEl complenemto a2 en decimal es: %i\n", BinarioPuro(complemento));
            break;
        default:
            break;
        }

    }while(op != 4);
}

void LlenarArreglo(int *arr){
    for(int i = 0; i < 10; i++){
        printf("Bit %i: ",i+1);
        scanf("%i", &arr[i]);
    }
}

int BinarioPuro(int arr[]){
    int numero = 0, aux, i;
    for(i = 1; i < 10; i++){
        aux = pow(2,(9-i));
        if(arr[i] == 1){
            numero += aux;
        }
    }
    if(arr[0] == 1){
        numero *= (-1);
    }

    return numero;
}