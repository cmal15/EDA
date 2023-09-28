#include<stdio.h>
#include<stdlib.h>
#include"listaSimple.h"

struct nodo{
    int info;
    nodo *next;
    nodo *prev;
};

struct lista{
    nodo *head;
    nodo *tail;
    int tamaño;
};

nodo* crearNodo(int info){
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->info = info;
    nuevo->next = NULL;
    nuevo->prev = NULL;
    return nuevo;
}

lista crearLista(){
    lista listax;
    
    listax.tail = NULL;
    listax.head = NULL;
    listax.tamaño = 0;

    return listax;
}

void enlistarEnPosicion(lista* l,nodo *nuevo, int pos){
    if(l->tamaño >= pos){
    nodo *tmp;
    tmp = l->head;    
        for(int i = 0; i < pos-1; i++){
            tmp = tmp->next;
        }
        nuevo->next = tmp->next;
        tmp->next = nuevo;
        nuevo->next->prev = nuevo;
        nuevo->prev = tmp;
        l->tamaño++;
    }   
}

void enlistarAlInicio(lista* l,nodo *nuevo){
    if(l->tamaño == 0){
        l->tail = nuevo;
        l->head = nuevo;
    }
    nuevo->next = l->head;
    nuevo->prev = l->tail;
    l->tail->next = nuevo;
    l->head->prev = nuevo;
    l->head = nuevo;
    l->tamaño++;
}

void enlistarAlFinal(lista *l,nodo *nuevo){
    if(l->tamaño == 0){
        enlistarAlInicio(l,nuevo);
    }else{
        l->tail->next = nuevo;
        l->head->prev = nuevo;
        nuevo->next = l->head;
        nuevo->prev = l->tail;
        l->tail = nuevo;
        l->tamaño++;
    }
}

int desenlistarDePoscion(lista* l, int pos){
    nodo *tmp = l->head;
    if(l->tamaño > pos){
        for(int i = 0; i < pos-1; i++){
            tmp = tmp->next;
        }
        nodo *kill = tmp->next;
        tmp->next = tmp->next->next;
        tmp->next->prev = tmp;
        free(kill);
        l->tamaño--;
    }
}

int desenlistarDelInicio(lista* l){
    if(l->tamaño > 0){
        nodo *kill = l->head;
        l->head = l->head->next;
        l->head->prev = l->tail;
        l->tail->next = l->head;
        free(kill);
        l->tamaño--;
    }else{
        printf("No hay elementos en la lista");
    }    
}

int desenlistarDelFinal(lista* l){
    if(l->tamaño > 0){
        nodo *tmp = l->head;
        while(tmp->next->next != NULL){
            tmp = tmp->next;
        }
        nodo *kill = tmp->next;
        l->tail = tmp;
        tmp->next = l->head;
        l->head->prev = tmp;
        free(kill);
        l->tamaño--;
    }
}

void imprimirLista(lista l){
    nodo *tmp = l.head;
    for(int i = 0; i < l.tamaño; i++){
        printf("Posicion %i: %i\n",i,tmp->info);
        tmp = tmp->next;
    }
}

void borrarLista(lista *l){
    nodo *tmp = l->head;
    nodo *kill;
    while(l->tamaño != 0){
        kill = tmp;
        tmp = tmp->next;
        free(kill);
        l->tamaño--;
    }
    free(tmp);
}