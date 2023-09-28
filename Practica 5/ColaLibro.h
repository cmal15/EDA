typedef struct Cola Cola;

typedef struct{
    char titulo[40];
    char autor[40];
    float numPaginas;
    int clave;
}Libro;

Cola crearCola();
int isEmptyC(Cola);
void encolar(Cola*,Libro);
Libro desencolar(Cola*);
Libro first(Cola);
Libro crearLibro();
void imprimirLibro(Libro);
float minutosDeLectura(float);
void horasDeLectura(float minutos);