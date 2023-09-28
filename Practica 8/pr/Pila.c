//#include "Pila.h"
#define MaxTope 50

struct Pila{
    int tope;
    int lista[100];
	int size;
};

struct Pila crearPila(){
	struct Pila p;
	p.tope=0;
	p.size = MaxTope;
	return p;
}
int isEmptyP(struct Pila p){
	if(p.tope==0)
		return 1;
	return 0;
}
void push(struct Pila *p,int x){
	if(p->tope >= p->size){
		printf("Se ha alcanzado el tope de la pila\n");
	}else{
		p->lista[p->tope]=x;
		p->tope++;		
	}
}

int pop(struct Pila *p){
	if(isEmptyP(*p)==1){
		printf("La struct Pila ya est%c vac%ca. \n",160,161);
		return -1;
	}
	else{
		int aux = p->lista[p->tope-1];
		p->tope--;
		return aux;
	}
}

int top(struct Pila pila){
	if(isEmptyP(pila)==1){
		printf("La struct Pila ya est%c vac%ca. \n",160,161);
		return -1;
	}
	else{
		return pila.lista[pila.tope-1];
	}
}
