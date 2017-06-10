#include "Nodo.h"

typedef struct {
    Nodo* ini;
    Nodo* fin;
    int tam;
} Lista;

Lista* crearLista();
void agregarNodo(Lista*, Nodo*);
void agregarNodoOrdenado(Lista*, Nodo*);

Lista* crearLista(){
    Lista* aux;
    aux = (Lista*) malloc(sizeof(Lista));
    aux->tam = 0;
    return aux;
}

void agregarNodo(Lista* l, Nodo* n){
    if(l->tam == 0){
        l->ini = l->fin = n;
    }else{
        agregarNodoOrdenado(l,n);
    }
    l->tam++;
}

void agregarNodoOrdenado(Lista *l, Nodo *n){
    Nodo *pivote = l->ini, *previo = NULL;
    int i;
    for(i = 0; i < l->tam; i++){
        if(compararNodos(pivote, n) > 0){
            n->sig = pivote;
            if(previo == NULL){
                l->ini = n;
            }else{
                previo->sig = n;
            }
            return;
        }
        previo = pivote;
        pivote = pivote->sig;
    }
    previo->sig = n;
    l->fin = n;
}

void eliminarPorCondicion(Lista* l, int (*comparar)(const Nodo*)){
    int i;
    Nodo *pivote = l->ini, *previo = NULL;
    for(i = 0; i < l->tam; i++){
        if(comparar(pivote) != 0){
            if(previo == NULL){
                l->ini = pivote->sig;
            }else{
                previo->sig = pivote->sig;
            }
            //free(pivote);
            l->tam--;
        }else{
            previo = pivote;
        }
        pivote = pivote->sig;
    }
}