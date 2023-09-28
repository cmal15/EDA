#include "listacirc.h"
#include<stdio.h>
#include<stdlib.h>

struct Nodo{
    int val;
    struct Nodo* next;
};

struct Lista{
	struct Nodo* head;
	int tamano;
};

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
        	printf("%d \n", current->val);
        	current = current->next;
        	tamano--;                           //se reduce tama�o
   	 	}
	}
}

void addFinalLista(Lista *lista, int val) {
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

void addPrincipioLista(Lista *lista, int val) {
	
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
    	if(temp->next == temp){
			free(lista->head);	
    		lista->head = NULL;
    	}else{
    		Nodo *current = lista->head;
    		Nodo *current2 =current->next;
    		while (current2->next != lista->head){
        		current = current->next;
				current2 = current2->next;
    		}
    		free(current2);
    		current->next = lista->head;
    	}
	lista->tamano--;
	}
}

void addN_esimo(Lista *l,int valor, int pos){
	Nodo *tmp = l->head;
	if(pos == 0 || l->head == NULL){
		addPrincipioLista(l,valor);
	} else{
		for(int i = 0; i < pos-1; i++){
			/*if(l->head == NULL){
				printf("La lista esta vacia\n");
				return ;
			}*/
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
	if(l->head != NULL){
		if(pos == 0){
			borrarPrimero(l);
		}else{
			Nodo *tmp = l->head;
			Nodo *kill;
			for(int i = 0; i < pos-1;i++){
				/*if(l->head == NULL){
					return;
				}*/
				tmp = tmp->next;
			}
			kill = tmp->next;
			tmp->next = tmp->next->next;
			free(kill);
			l->tamano--;
		}
	}else{
		printf("La lista esta vacia\n");
	}
}

void EliminarLista(Lista *l){
	while(l->head != NULL){
		borrarPrimero(l);
	}
}