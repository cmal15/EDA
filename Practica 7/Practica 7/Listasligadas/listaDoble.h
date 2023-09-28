#include<stdio.h>

typedef struct lista lista;
typedef struct nodo nodo;

nodo* crearNodo();
lista crearLista();
void enlistarEnPosicion(lista* ,nodo *, int );
void enlistarAlInicio(lista* ,nodo *);
void enlistarAlFinal(lista *,nodo *);
int desenlistarDePoscion(lista*, int);
int desenlistarDelInicio(lista*);
int desenlistarDelFinal(lista*);
void imprimirLista(lista);
void borrarLista(lista*);