#include "lista.h"
#include<stdio.h>
#include<stdlib.h>

struct Nodo{
    int val;
    struct Nodo* next;
};

struct Lista{
	struct Nodo* head;
};

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	return lista;
}

void print_list(Lista lista) {
    if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
    	printf("Los elementos de la lista son: \n");
    	Nodo *current = lista.head;
   		while (current != 0) {
        	printf("%d \n",current->val);
			current = current->next;
   	 	}
	}
}

void addPrincipioLista(Lista *lista, int val) {
	Nodo *new_node;
    new_node = (Nodo*)malloc(sizeof(Nodo));
    new_node->val = val;
    new_node->next = lista->head;
    lista->head = new_node;
}

void addFinalLista(Lista *lista, int val) {
	if(lista->head==NULL){
		
		Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
		nodo->val = val;
    	nodo->next = NULL;
    	lista->head = nodo;
	}	
	else
	{
		Nodo *current = lista->head;
		while (current->next != 0) {
       		current = current->next;
 		}
		Nodo *nuevoNodo;
		nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    	nuevoNodo->val = val;
    	nuevoNodo->next = NULL;
 		current->next = nuevoNodo;
	}	
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
	}
}

void borrarUltimo(Lista *lista) {
    Nodo *temp = lista->head;
	if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
    	if(temp->next==NULL){
			free(lista->head);	
    		lista->head = NULL;
    	}else{
    		Nodo *current = lista->head;
    		while (current->next->next != NULL) {
        		current = current->next;
    		}
			free(current->next);
    		current->next = NULL;
    	}
	}
}

int primerElemento(Lista lista){
	return lista.head->val;
}

int buscar(Lista l, int valor){
	Nodo *tmp = l.head;
	int pos = 0;
	if(l.head != NULL){
		do{
			if(valor == tmp->val){
				return pos;
			}
			tmp = tmp->next;
			pos++;
		}while(tmp->next != NULL);
	}else{
		printf("La lista esta vacia\n");
	}
	return -1;
}

void addN_esimo(Lista *l,int valor, int pos){
	Nodo *tmp = l->head;
	if(pos == 0){
		addPrincipioLista(l,valor);
	} else{
		for(int i = 0; i < pos-1; i++){
			if(tmp->next == NULL){
				printf("La posicion esta fuera de la lista\n");
				return;
			}
			tmp = tmp->next;
		}
		Nodo *nuevo;
		nuevo = (Nodo*)malloc(sizeof(Nodo));
		nuevo->val = valor;
		nuevo->next = tmp->next;
		tmp->next = nuevo;
	}
}

void borrarN_esimo(Lista *l, int pos){
	if(pos == 0 || l->head == NULL){
		borrarPrimero(l);
	}else{
		Nodo *tmp = l->head;
		Nodo *kill;
		for(int i = 0; i < pos-1;i++){
			if(tmp->next == NULL){
				printf("La posicion esta fuera de la lista\n");
				return;
			}
			tmp = tmp->next;
		}
		if(tmp->next != NULL){
			kill = tmp->next;
			tmp->next = tmp->next->next;
			free(kill);
		}else{
			borrarUltimo(l);
		}
	}
}

void eliminarMayores(Lista *l, int valor){
	if(l->head == NULL){
		//printf("La lista esta vacia\n");
	}else{
		Nodo *tmp = l->head, *aux;
		int eliminados = 0, pos = 0;
		do{
			aux = tmp;
			tmp = tmp->next;
			if(aux->val > valor){
				//printf("%i---\n",aux->val);
				borrarN_esimo(l,pos-eliminados);				
				eliminados++;
			}
			pos++;
		}while(aux->next != NULL);
		if(eliminados > 0){
			printf("Se eliminaron %i elementos\n", eliminados);
		}else{
			printf("No se eliminaron elementos\n");
		}
		//printf("%i - %i\n",pos,eliminados);
	}
}

void EliminarLista(Lista *l){
	while(l->head != NULL){
		borrarPrimero(l);
	}
}