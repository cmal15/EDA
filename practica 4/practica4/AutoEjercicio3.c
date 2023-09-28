#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int pistones;
    int HP;
}motor;

typedef struct{
    char *marca;
    char modelo[20];
    char placas[20];
    double kilometraje;
    motor motor1;
}automovil;

automovil crearAutomovil();
motor crearMotor();
void imprimirAutomovil(automovil coche);
void imprimirMotor(motor motor1);

void main(){
    int num;
    automovil *arrAutomoviles = (automovil *)malloc(1*sizeof(automovil));
    printf("Indica el tamaño del arreglo de automoviles: ");
    scanf("%i", &num);

    arrAutomoviles = realloc(arrAutomoviles, num*sizeof(automovil));
    printf("Introduce los datos de los automoviles:\n");
    for(int i = 0; i < num; i++){
        printf("--- Automovil %i ---\n", i+1);
        arrAutomoviles[i] = crearAutomovil();
    }

    printf("Automoviles guardados:\n");
    for(int i = 0; i < num; i++){
        printf("--- Automovil %i ---\n", i+1);
        imprimirAutomovil(arrAutomoviles[i]);
    }

    free(arrAutomoviles);
}

automovil crearAutomovil(){
    automovil coche;
    printf("Datos del automovil:\n");
    printf("Marca: ");
    fflush(stdin);
    scanf("%s", coche.marca);
    printf("Modelo: ");
    fflush(stdin);
    scanf("%s", coche.modelo);
    printf("Placas: ");
    fflush(stdin);
    scanf("%s", coche.placas);
    printf("Kilometraje: ");
    scanf("%d", &coche.kilometraje);
    coche.motor1 = crearMotor();
    return coche;
}
motor crearMotor(){
    motor motor1;
    printf("Datos del motor:\n");
    printf("Numero de pistones: ");
    scanf("%i", &motor1.pistones);
    printf("Caballos de fuerza: ");
    scanf("%i", &motor1.HP);
    return motor1;
}

void imprimirAutomovil(automovil coche){
    printf("Marca: %s\n", coche.marca);
    printf("Modelo: %s\n", coche.modelo);
    printf("Placas: %s\n", coche.placas);
    printf("Kilometraje: %d\n", coche.kilometraje);
    imprimirMotor(coche.motor1);
}
void imprimirMotor(motor motor1){
    printf("Datos del motor:\n");
    printf("Numero de pistones: %i\n", motor1.pistones);
    printf("Caballos de fuerza: %i\n", motor1.HP);
}