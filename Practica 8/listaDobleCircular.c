#include<stdio.h>
#include<stdlib.h>


typedef struct Nodo{
    int val;
    struct Nodo* next;
    struct Nodo* prev;
}Nodo;

typedef struct{
	int tamano;
	struct Nodo* head;
}Lista;

Lista crearLista();
void recorrerLista(Lista);
void recorrerLista2(Lista);
void print_list(Lista);
void addFinalLista(Lista*,int);
void addPrincipioLista(Lista*,int);   
void primerNodo(Lista*,int);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
void borrarIesimoLista(Lista*,int);
void addIesimoLista(Lista*,int,int);
int buscarApariciones(Lista,int);
int buscarPrimeraCoincidencia(Lista,int);
void eliminarLista(Lista*);

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	lista.tamano=0;
	return lista;
}

void recorrerLista(Lista lista){
	int var = 0;
	Nodo *temp = lista.head;
	do{
		printf("El elemento actual es %d \n",temp->val);
		printf("Mostrar Siguiente Presione 1 \n");
		printf("Salir Presione 2 \n");
		scanf("%d",&var);
		temp=temp->next;
		
	}while (var!=2);
}

void recorrerLista2(Lista lista){
	int var = 0, cont = 0;
	Nodo *temp = lista.head;
	do{
		printf("El elemento actual es %d \n",temp->val);
		printf("1. Mostrar Siguiente\n");
		printf("2. Multiplicar por 2\n");
		printf("3. Multiplicar por 3\n");
		printf("4. Salir\n");
		scanf("%d",&var);
		switch (var){
		case 1:
			temp=temp->next;
			if(temp == lista.head){
				cont++;
				printf("Se han dado %i vuelta(s) a la lista\n",cont);
			}
			break;
		case 2:
			temp->val *= 2;
			printf("El valor del elemento actual cambio a: %i\n",temp->val);
			break;
		case 3:
			temp->val *= 3;
			printf("El valor del elemento actual cambio a: %i\n",temp->val);
			break;
		default:
			break;
		}
	}while (var!=4);
}

void print_list(Lista lista) {
    int tamano = lista.tamano;
	if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
    	printf("Los elementos de la lista son: \n");
    	Nodo *current = lista.head;
   		while (tamano>0){
		   printf("%d\n",current->val) ;
		   current = current->next; 
		   tamano--;
		}	
	}
}

void addFinalLista(Lista *lista, int val) {
	if(lista->head==NULL){
		primerNodo(lista,val);
	}	
	else
	{
		Nodo *new_node, *temp;
    	new_node = (Nodo*)malloc(sizeof(Nodo));
    	new_node->val = val;
    	new_node->next = lista->head;
    	new_node->prev = lista->head->prev;
		lista->head->prev=new_node;
		temp=lista->head;
		
		while(temp->next!=lista->head)
			temp=temp->next;
    	temp->next=new_node;
	}	
	lista->tamano++;
}

void addPrincipioLista(Lista *lista, int val) {
	if(lista->head==NULL){
		primerNodo(lista,val);
	}	
	else{
		Nodo *new_node, *temp;
    	new_node = (Nodo*)malloc(sizeof(Nodo));
    	new_node->val = val;
    	new_node->next = lista->head;
    	new_node->prev = lista->head->prev;
    	lista->head->prev=new_node;
		
		temp=lista->head;
		
		while(temp->next!=lista->head)
			temp=temp->next;
    	temp->next=new_node;
		
		lista->head = new_node;
	}
	lista->tamano++;
}

void primerNodo(Lista *lista, int val){
	Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
	nodo->val = val;
    nodo->next = nodo;
    nodo->prev = nodo;
    lista->head = nodo;
}

void borrarPrimero(Lista *lista) {
    if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
    	Nodo *aux = lista->head->prev, *kill = lista->head;
		aux->next = lista->head->next;
		lista->head->next->prev = aux;
		free(kill);
		lista->head = aux->next;
		lista->tamano--;
	}
}

void borrarUltimo(Lista *lista) {
    if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
    	Nodo *tmp = lista->head->prev->prev, *kill = lista->head->prev;
		tmp->next = lista->head;
		lista->head->prev = tmp;
		free(kill);
		lista->tamano--;
	}
}

void borrarIesimoLista(Lista *lista, int pos){
	int contador;
	pos = pos%lista->tamano;
	Nodo *temp = lista->head, *kill;
	if(pos != 1){
		for(contador=1;contador<pos-1;contador++){
			temp=temp->next;
		}
		kill = temp->next;
		temp->next->next->prev = temp;
		temp->next = temp->next->next;
		lista->tamano--;
		free(kill);
	}else{
		borrarPrimero(lista);
	}
}

void addIesimoLista(Lista *lista, int val, int pos){
	int contador;
	pos = pos%lista->tamano;
	Nodo *temp = lista->head, *nuevo;
	nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo->val = val;
	if(pos != 1){
		for(contador=1;contador<pos-1;contador++){
			temp=temp->next;
		}
		nuevo->next = temp->next;
		nuevo->prev = temp;
		temp->next->prev = nuevo;
		temp->next = nuevo;
		lista->tamano++;
	}else{
		addPrincipioLista(lista,val);
	}	
}

int buscarApariciones(Lista l, int val){
	int cuenta = 0;
	if(l.head == NULL){
		printf("La lista esta vacia\n");
		return -1;
	}else{
		Nodo *tmp = l.head;
		do{
			if(val == tmp->val){
				cuenta++;
			}
			tmp = tmp->next;
		}while(tmp != l.head);
	}
	return cuenta;
}

int buscarPrimeraCoincidencia(Lista l, int val){
	int pos = 0;
	if(l.head == NULL){
		printf("La lista esta vacia\n");
	}else{
		Nodo *tmp = l.head;
		do{
			if(val = tmp->val){
				return pos;
			}
			tmp = tmp->next;
			pos++;
		}while(tmp != l.head);
		return -1;
	}
}

void eliminarLista(Lista *lista){
	while(lista->tamano > 0){
		borrarUltimo(lista);
	}
}