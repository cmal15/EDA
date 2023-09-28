#include<stdio.h>

typedef struct{
    char a;
    short aa;
}estructura1;

typedef struct{
    short bb;
    char b[2];
}estructura2;

typedef struct{
    estructura1 est1;
    estructura2 est2;
}estructura3;

void main(){
    estructura1 x;
    estructura2 y;
    estructura3 z;
    printf("%i,%i,%i,%i,%i,%i,%i,%i,%i\n",sizeof(estructura1),sizeof(x.aa),sizeof(x.a),sizeof(estructura2),sizeof(y.bb),sizeof(y.b),sizeof(estructura3),sizeof(z.est1),sizeof(z.est2));
    printf("%i,%i,%i\n", &x,&x.aa,&x.a);
    printf("%i,%i,%i\n", &y,&y.bb,&y.b);
}