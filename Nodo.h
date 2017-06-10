#include <string.h>

typedef struct Nodo{
    struct Nodo *sig;
    char* nombre;
    char* telefono;
    char* pais;
} Nodo;

Nodo* crearNodo(const char*, const char*, const char*);
int compararNodos(const Nodo*, const Nodo*);

Nodo* crearNodo(const char* n, const char* t, const char* p){
    Nodo* aux;
    aux = (Nodo*) malloc(sizeof(Nodo));
    
    aux->nombre = (char*)malloc(strlen(n)+1);
    aux->telefono = (char*)malloc(strlen(t)+1);
    aux->pais = (char*)malloc(strlen(p)+1);
    aux->sig = NULL;
    
    strcpy(aux->nombre, n);
    strcpy(aux->telefono, t);
    strcpy(aux->pais, p);
    return aux;
}

int compararNodos(const Nodo* n1, const Nodo* n2){
    return strcmp(n1->nombre, n2->nombre);
}