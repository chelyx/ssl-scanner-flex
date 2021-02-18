#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

void agregarNodo(struct nodo **lista, char* identificador) {
	struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
	struct nodo *current;
	strcpy(nuevoNodo->identificador, identificador);
	nuevoNodo->next = NULL;
	if(*lista == NULL) {
		*lista = nuevoNodo;
	} else {
		current = *lista;
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = nuevoNodo;
	}
}

int buscarIdentificador(struct nodo *lista, char *identificador) {
    struct nodo *aux = lista;
    while(aux != NULL && strcmp(aux->identificador, identificador)) {
        aux = aux->next;
    }
    if(aux == NULL){
        return 0; //no se encontró símbolo
    }
    return 1; //se encontró símbolo
}

