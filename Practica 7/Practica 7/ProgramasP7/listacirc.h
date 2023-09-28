typedef struct Nodo Nodo;
typedef struct Lista Lista;

Lista crearLista();
void addPrincipioLista(Lista*,int);
void print_list(Lista);
void addFinalLista(Lista*,int);
void addN_esimo(Lista *l,int valor, int pos);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
void borrarN_esimo(Lista *l, int pos);
void EliminarLista(Lista *l);