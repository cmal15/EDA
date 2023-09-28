#include "listaCircComputadora.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Computadora{
	char marca[10];
	char modelo[10];
	int ram;
	char procesador[10];
	int almacenamiento;
};

struct Nodo{
    Computadora* val;
    struct Nodo* next;
};

struct Lista{
	struct Nodo* head;
	int tamano;
};

Computadora* crearComputadora(){
	Computadora *nueva = (Computadora*)malloc(sizeof(Computadora));
	printf("Marca: ");
	fflush(stdin);
	scanf("%[^\n]",nueva->marca);
	printf("Modelo: ");
	fflush(stdin);
	scanf("%[^\n]",nueva->modelo);
	printf("Ram[Gb]: ");
	fflush(stdin);
	scanf("%i",&nueva->ram);
	printf("Procesador: ");
	fflush(stdin);
	scanf("%[^\n]",nueva->procesador);
	printf("Almacenamiento[Gb]: ");
	fflush(stdin);
	scanf("%i", &nueva->almacenamiento);
	return nueva;
}

void imprimirComputadora(Computadora compu){
	printf("Marca: %s\n", compu.marca);
	printf("Modelo: %s\n", compu.modelo);
	printf("Ram[Gb]: %i\n", compu.ram);
	printf("Procesador: %s\n", compu.procesador);
	printf("Almacenamiento[Gb]: %i\n", compu.almacenamiento);	
}

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	lista.tamano = 0;
	return lista;
}

void print_list(Lista lista) {
    if(lista.head==NULL || lista.tamano == 0){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
    	int tamano = lista.tamano;				//se define el tama�o
		printf("Los elementos de la lista son: \n");
    	Nodo *current = lista.head;
   		while (tamano > 0 ) {					//tamaño como condicional
			printf("Computadora %i\n",lista.tamano-tamano+1);
			imprimirComputadora(*current->val);
        	current = current->next;
        	tamano--;                           //se reduce tama�o
   	 	}
	}
}

void addFinalLista(Lista *lista, Computadora *val) {
	int posicion=lista->tamano;
	if(lista->head==NULL){
		Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
		nodo->val = val;
    	nodo->next = nodo;
    	lista->head = nodo;
	}
	else
	{
		Nodo *current = lista->head;
		while (posicion!=1) {
       		current = current->next;
       		posicion--;
 		}
		Nodo *nuevoNodo;
		nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    	current->next = nuevoNodo;
		nuevoNodo->val = val;
    	nuevoNodo->next = lista->head;
	}	
	lista->tamano++; 
}

void addPrincipioLista(Lista *lista, Computadora *val) {
	
	Nodo *node,*temp;
    node = (Nodo*)malloc(sizeof(Nodo));
    node->val = val;
    if(lista->head==NULL){
    	node->next=node;
	}
    else{
    	node->next = lista->head;
		temp = lista->head;
    	while(temp->next != lista->head){
    		temp=temp->next;
		}
		temp->next=node;
	}
	lista->head = node;
    lista->tamano++;
}

void borrarPrimero(Lista *lista) {
    if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
    	Nodo *nuevo_head = NULL;
    	Nodo *temp = lista->head;
    	nuevo_head=temp->next;
    	free(lista->head->val);
		free(lista->head);
    	lista->head = nuevo_head;
		lista->tamano--;
	}
}

void borrarUltimo(Lista *lista) {
    Nodo *temp = lista->head;
	if (lista->head == NULL) {
        printf("La lista esta vacia\n");
    }
    else{
    	if(temp->next==NULL){
			free(lista->head->val);
			free(lista->head);	
    		lista->head = NULL;
    	}else{
    		Nodo *current = lista->head;
    		Nodo *current2 =current->next;
    		while (current2->next != lista->head){
        		current = current->next;
				current2 = current2->next;
    		}
			free(current2->val);
    		free(current2);
    		current->next = lista->head;
    	}
	lista->tamano--;
	}
}

void addN_esimo(Lista *l,Computadora *valor, int pos){
	Nodo *tmp = l->head;
	if(pos == 0){
		addPrincipioLista(l,valor);
	} else{
		for(int i = 0; i < pos-1; i++){
			if(tmp->next == NULL){
				return 0;
			}
			tmp = tmp->next;
		}
		Nodo *nuevo;
		nuevo = (Nodo*)malloc(sizeof(Nodo));
		nuevo->val = valor;
		nuevo->next = tmp->next;
		tmp->next = nuevo;
		l->tamano++;
	}
}

void borrarN_esimo(Lista *l, int pos){
	if(pos == 0){
		borrarPrimero(l);
	}else{
		Nodo *tmp = l->head;
		Nodo *kill;
		for(int i = 0; i < pos-1;i++){
			if(tmp->next == NULL){
				return 0;
			}
			tmp = tmp->next;
		}
		if(tmp->next != NULL){
			kill = tmp->next;
			tmp->next = tmp->next->next;
			free(kill->val);
			free(kill);
			l->tamano--;
		}else{
			borrarUltimo(l);
		}
	}
}

void EliminarLista(Lista *l){
	while(l->tamano > 0){
		borrarPrimero(l);
	}
}

int buscar(Lista l,char marca[]){
	int pos = 0;
	Nodo *tmp = l.head;
	for(pos = 0; pos < l.tamano; pos++){
		if(strcmp(tmp->val->marca,marca) == 0){
			return pos;
		}
		tmp = tmp->next;
	}
	return -1;
}

void recorrerLista(Lista l){
	Nodo *tmp = l.head;
	int op, pos = 0;
	while(op != 2){
		pos = pos%l.tamano;
		printf("Elemento %i\n",pos);
		printf("Seleccione:\n");
		printf("0.Siguiente\t1.Mostrar informacion\n2.Salir\n");
		scanf("%i",&op);
		switch (op)
		{
		case 0:
			tmp = tmp->next;
			pos++;
			break;
		
		case 1:
			imprimirComputadora(*tmp->val);
			break;
		default:
			break;
		}
	}
}