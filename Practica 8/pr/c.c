#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int val;
    Nodo *next;
}Nodo;

typedef struct{
    int tamano;
    Nodo *head;
    Nodo *tail;
}Lista;

Lista crearLista();
void imprimirLista(Lista);
void addFinal(Lista *,int);
void addInicio(Lista *,int);
void addIesimo(Lista *,int, int);
void borrarFinal(Lista *);
void borrarInicio(Lista *);
void borrarIesimo(Lista *, int);

Lista crearLista(){
    Lista l;
    l.head = NULL;
    l.tail = NULL;
    l.tamano = 0;
}

void imprimirLista(Lista l){
    if(l.tamano == 0){
        printf("La lista esta vacia\n");
    }else{
        Nodo *tmp = l.head;
        printf("Los elementos de la lista son:\n");
        for(int i = 0; i < l.tamano; i++){
            printf("%i\n",tmp->val);
            tmp = tmp->next;
        }
    }
}

void primerNodo(Lista *l, int val){
    Nodo *nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->val = val;
    l->head = nuevo;
    l->tail = nuevo;
    nuevo->next = NULL;
    l->tamano++;
}

void addFinal(Lista *l,int val){
    if(l->tamano == 0){
        primerNodo(l,val);
    }else{
        Nodo *nuevo;
        nuevo = (Nodo*)malloc(sizeof(Nodo));
        nuevo->val = val;
        l->tail = nuevo;
        nuevo->next = NULL;
        l->tamano++;
    }
}

void addInicio(Lista *l,int val){
    if(l->tamano == 0){
        primerNodo(l,val);
    }else{
        Nodo *nuevo;
        nuevo = (Nodo*)malloc(sizeof(Nodo));
        nuevo->val = val;
        nuevo->next = l->head;
        l->head = nuevo;
        l->tamano++;
    }
}

void addIesimo(Lista *l,int val,int pos){
    if(l->tamano == 0){
        primerNodo(l,val);
    }else if(pos == 0){
        addInicio(l,val);
    }else if(pos >= l->tamano){
        addFinal(l,val);
    }else{
        Nodo *nuevo, *tmp = l->head;
        nuevo = (Nodo*)malloc(sizeof(Nodo));
        nuevo->val = val;
        for(int i = 0; i < pos-1; i++){
            tmp = tmp->next;
        }
        
    }
}

void borrarFinal(Lista *l){
    if(l->tamano == 0){
        printf("La lista esta vacia\n");
    }else{
        Nodo *tmp = l->head;
        while(tmp->next->next != NULL){
            tmp = tmp->next;
        }
        free(l->tail);
        l->tail = tmp;
        tmp->next = NULL;
        l->tamano--;
    }
}

void borrarInicio(Lista *l){
    if(l->tamano == 0){
        printf("La lista esta vacia\n");
    }else{
        Nodo *tmp = l->head->next;
        free(l->head);
        l->head = tmp;
        l->tamano--;
    }
}

void borrarIesimo(Lista *l, int){
    if(l->tamano == 0){
        printf("La lista esta vacia\n");
    }
}
