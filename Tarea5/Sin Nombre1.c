#include<stdio.h>

struct Producto{
    float clave;
    char nombre[20];
    float precio;
};
typedef struct Producto Producto;

struct Empleado{
    char nombre[20];
    char apellido[20];
    char rango[15];
};
typedef struct Empleado Empleado;

struct Seccion{
    struct Empleado empleado[5];
	float codigoseccion;
    char categoria[20];
    struct Producto producto[5];
};
typedef struct Seccion Seccion;

struct Gerente{
    char nombre[20];
    char apellido[20];
    float salario;
};
typedef struct Gerente Gerente;

struct Sucursal{
    Gerente gerente;
    char nombresuc [30];
    float clave;
    Seccion seccion[5];
    int numsec;
};

typedef struct Sucursal Sucursal;

void crearSucursal(Sucursal sucursal[]);
void crearSeccion(Sucursal *nuevasuc);
void crearProducto(Sucursal *nuevasuc,int cont,int cont2);
void iniciarGerente(Sucursal *nuevasuc);
void iniciarEmpleado(Sucursal *nuevasuc,int cont,int cont2);
void mostrarSucursal(Sucursal sucursal[]);
void mostrarSeccion(Sucursal sucursal[],int num,int cont);
void mostrarProductos(Sucursal sucursal[],int num,int cont,int cont2);

int numsuc=0;

int main(){
	Sucursal sucursal[10];
	
    int op,indice;
    do{
    	printf("Que quieres realizar\n1.Nueva Sucursal\n2.Mostrar datos de sucursal\n");
	    scanf("%d",&op);
	    
	    switch(op){
	    	case 1: 
	    	crearSucursal(sucursal);
	    	numsuc++;
			break;
	    	case 2:
	    		mostrarSucursal(sucursal);
                break;
		}
	}while(op!=3);	  
}

void crearSucursal(Sucursal sucursal[]){
	printf("\nDame el nombre de tu sucursal: ");
    scanf("%s", sucursal[numsuc].nombresuc);
    printf("Cual es la clave de la sucursal: ");
    scanf("%f", &sucursal[numsuc].clave);
    iniciarGerente(&sucursal[numsuc]);
    crearSeccion(&sucursal[numsuc]);    
}

void crearSeccion(Sucursal *nuevasuc){
	int numsec1,numpro,numem;
    int i,j,k;
	printf("Cuantas secciones tiene esta sucursal(3-5): ");
    scanf("%d",&numsec1);
	for(i=0;i<numsec1;i++){
        printf("Datos seccion %d",i+1);
        printf("\nCategoria de la seccion: ");
        fflush(stdin);
        scanf("%s", *nuevasuc->seccion[i].categoria);
        printf("Caul es el codigo de la seccion ");
        scanf("%f", nuevasuc->seccion[i].codigoseccion);
        printf("Cuantos productos maneja esta seccion(2-5): ");
        scanf("%d",&numpro);
        for(j=0;j<numpro;j++){
        	printf("Producto %d",j+1);
        	crearProducto(nuevasuc,i,j);
		}
		printf("Cuantos empleados tiene esta seccion(2-5): ");
		scanf("%d",&numem);
		for(j=0;j<numem;j++){
			iniciarEmpleado(nuevasuc,i,j);
		}
    }
    
}
void crearProducto(Sucursal *nuevasuc,int cont,int cont2){
	
    printf("Dame los datos del producto\n");
    printf("Cual es el nombre del producto: ");
    fflush(stdin);
    scanf("%s",*nuevasuc->seccion[cont].producto[cont2].nombre);
    printf("Cual es la clave del producto: ");
    scanf("%f",nuevasuc->seccion[cont].producto[cont2].clave);
    printf("Cual es el precio del producto: ");
    scanf("%f",nuevasuc->seccion[cont].producto[cont2].precio);
		
}

void iniciarGerente(Sucursal *nuevasuc){
	printf("Quien es el gerente a cargo\n");
    printf("Nombre: ");
    fflush(stdin);
    scanf("%s", *nuevasuc->gerente.nombre);
    printf("Apellido: ");
    fflush(stdin);
    scanf("%s", *nuevasuc->gerente.apellido);
    printf("Cual es su salario: ");
    fflush(stdin);
    scanf("%f", nuevasuc->gerente.salario);
    
}
void iniciarEmpleado(Sucursal *nuevasuc,int cont,int cont2){
    printf("Nombre: ");
    fflush(stdin);
    scanf("%s", *nuevasuc->seccion[cont].empleado[cont2].nombre);
    printf("Apellido: ");
    fflush(stdin);
    scanf("%s", *nuevasuc->seccion[cont].empleado[cont2].apellido);
    printf("Escribe en que rango esta\n1.Experto\n2.Intermedio\n3.Aprendiz");
    fflush(stdin);
    scanf("%s", *nuevasuc->seccion[cont].empleado[cont2].rango);
    
}
void mostrarSucursal(Sucursal sucursal[]){
    int i,num;
    printf("Que numero de sucursal deseas ver: ");
    scanf("%d",&num);
    fflush(stdin);
	printf("SUCURSAL %s\n\n",sucursal[num-1].nombresuc);
    printf("Clave: %.0f\n", sucursal[num-1].clave);
    printf("\nGERENTE\n");
    fflush(stdin);
    printf("Nombre: %s\n", sucursal[num-1].gerente.nombre);
    fflush(stdin);
    printf("Apellido: %s\n", sucursal[num-1].gerente.apellido);
    printf("Salario: %.2f\n", sucursal[num-1].gerente.salario);
    printf("\nSECCIONES\n");
	for(i=0;i<5;i++){
		mostrarSeccion(sucursal,num,i);
	}
}

void mostrarSeccion(Sucursal sucursal[],int num,int cont){
    int j;
    fflush(stdin);
    printf("\nCategoria: %s\n", sucursal[num-1].seccion[cont].categoria);
    printf("Codigo de seccion: %.0f\n", sucursal[num-1].seccion[cont].codigoseccion);
    printf("Productos:\n");
    for(j=0;j<5;j++);
    mostrarProductos(sucursal,num,cont,j);

    printf("Empleados:\n");
    for( j = 0; j < 5; j++) {
        fflush(stdin);
        printf("Nombre completo: %s %s \nRango: %s\n", sucursal[num-1].seccion[cont].empleado[j].nombre, sucursal[num-1].seccion[cont].empleado[j].apellido, sucursal[num-1].seccion[cont].empleado[j].rango);
    }
}	

void mostrarProductos(Sucursal sucursal[],int num,int cont,int cont2){
    fflush(stdin);
	printf("Nombre %s \n Clave: %.0f \nPrecio: %.2f\n", sucursal[num-1].seccion[cont].producto[cont2].nombre, sucursal[num-1].seccion[cont].producto[cont2].clave, sucursal[num-1].seccion[cont].producto[cont2].precio);

}

