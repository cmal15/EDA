#include <stdio.h>
#include <stdlib.h>
void main(){
	
	int cont,arreglo[]={35,40,45,50,55}; 
	int variable;
	int *ptr = (int *)calloc(10,sizeof(int));
	char *ptr2 = malloc(100*sizeof(char));
	int *ptr3;
	
	//Imprimiendo direcciones de un arreglo
	for(cont=0;cont<10;cont++){
		printf("direccion arreglo[%d]=%d   valor arreglo[%d]=%d\n",cont,&arreglo[cont],cont,arreglo[cont]);
	}
	printf("\n");
	
	//Llenar valores memoria dinamica con multiplos de 3
	for(cont = 0; cont < 10; cont++){
		*(ptr+cont) = 3*(cont+1);
	}
	
	//Imprimiendo direcciones y contenido de un apuntador de memoria din�mica reservado con malloc
	for(cont=0;cont<10;cont++){
		printf("direccion=%d   *valor=%d \n",ptr+cont, *(ptr+cont));
	}
	printf("\n");

	ptr = (int *)realloc(ptr,25*sizeof(int));

	for(cont=0;cont<25;cont++){
		printf("direccion=%d   *valor=%d \n",ptr+cont, *(ptr+cont));
	}
	printf("\n");

	ptr3 = (int *)realloc(ptr,25*sizeof(int));

	for(cont=0;cont<25;cont++){
		printf("direccion=%d   *valor=%d \n",ptr3+cont, *(ptr3+cont));
	}
	printf("\n");		
	
    /* No remover estos comentarios, (por lo menos no antes de acabar la actividad1) /*/
 	//strcpy(ptr2,"hola amigo como estas");  //esto si se puede hacer 
	// //ptr2 = "Hola amigo como estas";    //nunca haga esto compa 
  	//for(cont=0;cont<100;cont++){
 	//   printf("%c",ptr2[cont]);     //no vaya a descomentar esta linea, ni cambiar el contador del for a 1000 (
 	//}
    
	free(ptr);	
	free(ptr2);
	free(ptr3);

}