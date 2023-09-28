#include"ColaPrioridad.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

Alumno crearAlumno(){
    Alumno Alum;
    srand(time(NULL));
    printf("Nombre: ");
    fflush(stdin);
    scanf("%s",Alum.nombre);
    printf("Apellido: ");
    fflush(stdin);
    scanf("%s",Alum.apellido);
    printf("Edad: ");
    fflush(stdin);
    scanf("%i",&Alum.edad);
    Alum.prioridad = rand()%4+1;
    printf("Prioridad: %i\n",Alum.prioridad);
    return Alum;
}

ColaP crearCola(int tam){
    ColaP c;
    c.lista = (Alumno*)calloc(tam,sizeof(Alumno));
    c.primero = 1;
    c.ultimo = 0;
    c.tamaño = tam;
    c.disponibles = tam; 
    c.priori1 = 0;
    c.priori2 = 0;
    c.priori3 = 0;
    c.priori4 = 0;
    return c;
}

int isEmpty(ColaP c){
    if(c.primero == c.ultimo+1){
        return 1;
    }
    return 0;
}

void moverAlumnos(Alumno lista[],int i){
    lista[i] = lista[i-1];
}

void copiarAlumno(Alumno *destino, Alumno *origen){
    strcpy(destino->nombre,origen->nombre);
    printf(".");    
    strcpy(destino->apellido,origen->apellido);
    printf(".");
    destino->edad = origen->edad;
    printf(".");    
    destino->prioridad = origen->prioridad;
    printf(".");
}

void adelantar(ColaP* c,int pos){
    for(int i = (c->tamaño)-1; i > pos;i--){
        //printf("\ni:%i,pos:%i\n",i,pos);
        c->lista[i] = c->lista[i-1]; 
        //copiarAlumno(&c->lista[i],&c->lista[i-1]);
    }
}

void retroceder(ColaP* c){
    for(int i = 0;i < c->tamaño-1; i++){
        c->lista[i] = c->lista[i+1];
    }
}

void encolar(ColaP* c, Alumno alum){
    if(c->disponibles == 0){
        c->lista = realloc(c->lista,_msize(c->lista)+2*sizeof(Alumno));
        c->disponibles += 2;
        c->tamaño += 2;
        limpiarAlumno(&c->lista[c->tamaño-1]);
    }
    switch(alum.prioridad){
        case 1:
            //adelantar(&c,c->priori1);
            c->lista[c->priori1] = alum;            
            c->priori1++;
            c->priori2++;
            c->priori3++;
            c->priori4++;
        break;
        case 2:
            //adelantar(&c,c->priori2);
            c->lista[c->priori2] = alum;
            c->priori2++;
            c->priori3++;
            c->priori4++;    
        break;
        case 3:
            //adelantar(&c,c->priori3);
            c->lista[c->priori3] = alum;
            c->priori3++;
            c->priori4++; 
        break;
        case 4:
           // adelantar(&c,c->priori4);
            c->lista[c->priori4] = alum;
            c->priori4++;             
        break;
    }

    c->ultimo++;
    c->disponibles--;
    //printf("\n\nIndices: %i,%i,%i,%i\n\n",c->priori1,c->priori2,c->priori3,c->priori4);
}

void limpiarAlumno(Alumno *alu){
    strcpy(alu->nombre,"");
    strcpy(alu->apellido,"");
    alu->edad = 0;
    alu->prioridad = 0;
}

Alumno desencolar(ColaP* c){
    if(isEmpty(*c) == 1){
        printf("La cola esta vacia\n");
    }else{
        Alumno alu = c->lista[0];
        c->disponibles++;
        free(&c->lista[0]);
        if(c->priori1>0){
            c->priori1--;
        }
        if(c->priori2>0){
            c->priori2--;
        }
        if(c->priori3>0){
            c->priori3--;
        }
        if(c->priori4>0){
            c->priori4--;
        }          
        retroceder(c);
        limpiarAlumno(&c->lista[c->priori4]);
        return alu;
    }
}

void mostrarCola(ColaP c){
    //printf("Tam%i dis%i\n",c.tamaño,c.disponibles);
    for(int i = 0; i < c.tamaño;i++){
        printf("%i\t",i);
        mostrarAlumno(c.lista[i]);
    }
}

void mostrarAlumno(Alumno alu){
    printf("Nombre: %s\t",alu.nombre);
    printf("Apellido: %s\t",alu.apellido);
    printf("Edad: %i\t",alu.edad);
    printf("Prioridad: %i\n", alu.prioridad);
}
