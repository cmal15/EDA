#include "ColaLibro.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MaxElementosCola 50

struct Cola{
    int primero;
    int ultimo;
	int size;
    Libro lista[100];
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
void encolar(Cola *c,Libro x){
	if(c->ultimo >= c->size){
		printf("Se ha alcanzado el maximo numero de elementos en la cola\n");
	}else{
		c->lista[c->ultimo]=x;
		c->ultimo+=1;	
	}
}
	
Libro desencolar(Cola *c){
	if((isEmptyC(*c))==1)
		printf("la cola est� vac�a \n");
	else{
		Libro aux = c->lista[c->primero-1];
		c->primero++;
		if(c->primero==c->ultimo+1){
	
			*c=crearCola();
		}
		return aux;
	}
}

Libro first(Cola c){
	return c.lista[c.primero-1];
}

Libro crearLibro(){
    Libro libro;
	char aux[40];
    printf("Titulo: ");
    fflush(stdin);
    scanf("%[^\n]",aux);
	strcpy(libro.titulo,aux);
    printf("Autor: ");
    fflush(stdin);
    scanf("%[^\n]",aux);
	strcpy(libro.autor,aux);
	fflush(stdin);
    printf("Numero de paginas: ");
    scanf("%f", &libro.numPaginas);
    printf("Clave: ");
    scanf("%i", &libro.clave);
	
    return libro;
}

float minutosDeLectura(float paginas){
    float minutos = (20 * paginas)/60;
    return minutos;
}

void horasDeLectura(float minutos){
    int horas, min, segundos;
    float aux = minutos;
	segundos = (modf(aux,0)) * 60;
	aux -= modf(aux,0);
	aux = aux/60;
	horas = aux - modf(aux,0);
	min = (aux - horas)*60;
	if(segundos > 10){
		segundos++;
	}
    printf("%i horas, %i minutos y %i segundos\n\n", horas, min, segundos);
}

void imprimirLibro(Libro libro){
    printf("Titulo: %s\n", libro.titulo);
//	printf("Autor: %s\n", libro.autor);
//	printf("Clave: %i\n", libro.clave);
    printf("Tiempo de impresión: %f minutos = ",minutosDeLectura(libro.numPaginas));
    horasDeLectura(minutosDeLectura(libro.numPaginas));
}
