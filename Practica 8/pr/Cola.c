#include "Cola.h"
#define MaxElementosCola 50

struct Cola{
    int primero;
    int ultimo;
	int size;
    int lista[100];
};

Cola crearCola(){
	Cola c;
	c.primero=1;
	c.ultimo=0;
	c.size = MaxElementosCola;
	return c;
}
int isEmptyC(Cola c){
	if(c.primero==c.ultimo+1)
		return 1;
	return 0;
}
void encolar(Cola *c,int x){
	if(c->ultimo >= c->size){
		printf("Se ha alcanzado el maximo numero de elementos en la cola\n");
	}else{
		c->lista[c->ultimo]=x;
		c->ultimo+=1;	
	}
}
	
int desencolar(Cola *c){
	if((isEmptyC(*c))==1)
		printf("la cola est� vac�a \n");
	else{
		int aux = c->lista[c->primero-1];
		c->primero++;
		if(c->primero==c->ultimo+1){
	
			*c=crearCola();
		}
		return aux;
	}
	return -1;
}

int first(Cola c){
	return c.lista[c.primero-1];
}
