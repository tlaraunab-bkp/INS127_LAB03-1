#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

#define BUFFER_SIZE 100

Lista* inicializaLista();
void mostrarLista(Lista*);
void borrarExtranjeros(Lista*);
int comparaExtranjero(Nodo*);
Nodo* descomponeNodo(char*);

int main(int argc, char **argv)
{
    int opcion;
    Lista* lista;
	//Menú
    do{
        printf("-------------------------------------------\n");
        printf("|  Seleccione una operación de la lista   |\n");
        printf("-------------------------------------------\n\n");
        printf("1. Inicializar Lista\n");
        printf("2. Mostrar Personas en la lista\n");
        printf("3. Borrar extranjeros\n");
        printf("4. Salir\n\n");
        printf("Indique acción a realizar: ");
        
        if(!scanf("%1d",&opcion)){
            opcion = 0;
        }
        
        switch(opcion){
            case 1: lista = inicializaLista(); break;
            case 2: mostrarLista(lista); break;
            case 3: borrarExtranjeros(lista); break;
        }
        
    }while(opcion != 4);
    
    
}

Lista* inicializaLista(){
    Lista* l_aux = crearLista();
    Nodo* n_aux;
    char ruta[] = "agenda.txt", buffer[BUFFER_SIZE];
    FILE *f = fopen(ruta, "r");
    if(f == NULL){
        fprintf(stderr, "ERROR: No se pudo abrir el archivo de agenda\n");
        exit(-5001);
    }
    
    while(1){
        if(fgets(buffer, BUFFER_SIZE, f) == NULL){
            break;
        }
        
        if(buffer[strlen(buffer)-1] == '\n'){
           buffer[strlen(buffer)-1] = '\0'; 
        }
        
        n_aux = descomponeNodo(buffer);
        agregarNodo(l_aux, n_aux);
    }
    
    fclose(f);
    return l_aux;
}

void mostrarLista(Lista* l){
    int i;
    Nodo* pivote = l->ini;
    for(i = 0; i < l->tam; i++){
        printf("Nombre: %s\nTelefono: %s\nPais: %s\n\n",pivote->nombre, pivote->telefono, pivote->pais);
        pivote = pivote->sig;
    }
}

void borrarExtranjeros(Lista* l){
    eliminarPorCondicion(l, comparaExtranjero);
}

int comparaExtranjero(Nodo* n){
    int c = strcmp(n->pais, "Chile");
    printf("%s: %d\n",n->pais,c);
    return c;
}

Nodo* descomponeNodo(char* str){
    char delim[] = "\t";
    char* n = strtok(str, delim);
    char* t = strtok(NULL, delim);
    char* p = strtok(NULL, delim);
    return crearNodo(n, t, p);
}