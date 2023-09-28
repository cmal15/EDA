typedef struct Nodo Nodo;
typedef struct Lista Lista;
typedef struct Computadora Computadora;

Computadora* crearComputadora();
void imprimirComputadora(Computadora);
Lista crearLista();
void addFinalLista(Lista*,Computadora*);
void addPrincipioLista(Lista*,Computadora*);
void addN_esimo(Lista*,Computadora*,int);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
void borrarN_esimo(Lista*, int);
void print_list(Lista);
void EliminarLista(Lista*);
int buscar(Lista,char[]);
void recorrerLista(Lista);