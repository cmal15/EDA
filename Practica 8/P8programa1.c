#include<stdio.h>
#include<stdlib.h>
#include "listaDobleCircular.h"

main(){
	printf("Bienvenido al programa \n");
 	
	int opcion,elemento = 0;
	Lista miLista =crearLista();
	addFinalLista(&miLista,10);
	addFinalLista(&miLista,20);
	addFinalLista(&miLista,30);
	addFinalLista(&miLista,40);
	recorrerLista2(miLista);
	print_list(miLista)	;

}

