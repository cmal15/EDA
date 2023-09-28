#include<stdio.h>

typedef struct{
    int entero;
    float flotante;
    double doble;
    char cadena[10];
}estructura;

typedef struct{
    char car;
    short jjj;
}car;

void main(){
    estructura x;
    car a;
//    printf("%i,%i,%i,%i,%i,%i,%i\n",sizeof(estructura), sizeof(x),sizeof(x.entero),sizeof(x.flotante),sizeof(x.doble),sizeof(x.cadena));

//    printf("\n");
//    printf("x: %d  int: %d  ", &x, &x.entero);
//    printf("float: %d  doble: %d  ",&x.flotante,&x.doble);
//    printf("string: %d\n",&x.cadena);
    printf("%i,%i,%i\n",sizeof(a), sizeof(a.jjj));
    printf("car: %d, char: %i, int: %i\n", &a,&a.car,&a.jjj);

}