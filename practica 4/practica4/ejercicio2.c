#include "Alumno.h"

void main(){
	int j;
	printf("Tama�o de objeto Alumno = %d \n",sizeof(Alumno));
	Alumno *din1,*din2,*din3;
	int numCuenta, num, cPostal;
	float promedio;
	char calle[20], colonia[20], nombre[20], apellido[20];
	din1 = malloc(5*sizeof(Alumno));
	din2 = calloc(5,sizeof(Alumno));
	/*
	printf("Primer apuntador: \n");
	for(j=0;j<5;j++){
		printf("Direccion[%d]=%d \n",j,din1+j);
	}
	printf("\n");
	
	printf("Segundo apuntador \n");
	for(j=0;j<5;j++){
		printf("Direccion[%d]=%d \n",j,din2+j);
	}
	printf("\n");
	*/
	//printf("Con realloc: \n");
	din3 = realloc(din2,10);
	
	/*for(j=0;j<10;j++){
		printf("&din3[%d]=%d \n",j,din3+j);
	}*/
	
	for(int i = 0; i<5;i++){
		printf("din1[%i]\n",i);
		inicializarAlumno(&numCuenta,&nombre,&apellido, &promedio);
		din1[i] = crearAlumno(numCuenta,nombre,apellido, promedio);
		imprimirAlumno(din1[i]);
	}
	for(int i = 0; i<10;i++){
		printf("din3[%i]\n",i);		
		inicializarAlumno(&numCuenta,&nombre,&apellido, &promedio);
		din3[i] = crearAlumno(numCuenta,nombre,apellido, promedio);
	}	

	free(din1);
	free(din2);
	free(din3);
	system("PAUSE");
}