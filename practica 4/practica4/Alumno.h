#include <stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct {
	char calle[20];
	int num;
	char colonia[20];
	int cPostal;
}Direccion;
typedef struct {
	int numCuenta;
	char nombre[15];
	char apellido[15];
	float promedio;
	Direccion domicilio;
}Alumno;

Alumno crearAlumno(int, char*, char*, float);
void inicializarAlumno(int *numCuenta, char *nombre[20],char *apellido[20],float *promedio);
Direccion crearDireccion();
void imprimirAlumno(Alumno);
void imprimirDomicilio(Direccion domicilio);

Alumno crearAlumno(int numeroC, char *name, char *lastname, float prom){
	Alumno alumnoCreado;
	alumnoCreado.numCuenta = numeroC;
	strcpy(alumnoCreado.nombre,name);
	strcpy(alumnoCreado.apellido,lastname);
	alumnoCreado.promedio = prom;
	alumnoCreado.domicilio = crearDireccion();
	return alumnoCreado;
}
void inicializarAlumno(int *numCuenta, char *nombre[20],char *apellido[20],float *promedio){
	printf("Nombre: ");
	fflush(stdin);
	scanf("%s", nombre);
	printf("Apellido: ");
	fflush(stdin);
	scanf("%s", apellido);
	printf("Numero de cuenta: ");
	scanf("%i", numCuenta);
	printf("Promedio: ");
	scanf("%f", promedio);	
}
Direccion crearDireccion(){
	Direccion domicilioCreado;
	printf("Dirección:\n");
	printf("Calle: ");
	fflush(stdin);
	scanf("%s", domicilioCreado.calle);
	printf("Numero: ");
	scanf("%i", &domicilioCreado.num);
	printf("Colonia: ");
	fflush(stdin);
	scanf("%s", domicilioCreado.colonia);
	printf("Codigo Postal: ");
	scanf("%i", &domicilioCreado.cPostal);	
	return domicilioCreado;
}

void imprimirDomicilio(Direccion domicilio){
	printf("Domicilio:\n");
	printf("Calle: %s\n", domicilio.calle);
	printf("Colonia: %s\n",domicilio.colonia);
	printf("Numero: %i\n",domicilio.num);
	printf("Codigo postal: %i\n", domicilio.cPostal);
}

void imprimirAlumno(Alumno alumnoPrint){

	printf("\nNumero de cuenta: %d \n",alumnoPrint.numCuenta);
	printf("Name: %s \n",alumnoPrint.nombre);
	printf("LastName : %s  \n ", alumnoPrint.apellido);
	printf("Promedio: %f\n", alumnoPrint.promedio);
	imprimirDomicilio(alumnoPrint.domicilio);
}
