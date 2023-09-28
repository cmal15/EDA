typedef struct Nodo Nodo;
typedef struct Lista Lista;

Lista crearLista();
void print_list(Lista);
void addPrincipioLista(Lista*,int);  
void addFinalLista(Lista*,int);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
int primerElemento(Lista);
int buscar(Lista, int);
void addN_esimo(Lista*,int,int);
void borrarN_esimo(Lista*,int);
void eliminarMayores(Lista*,int);
void EliminarLista(Lista*);
