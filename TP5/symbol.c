#include <stdio.h>
#include <stdlib.h>
#include "symbol.h"

Nodo *crearLista() {
	Nodo *Lista;
	Lista = NULL;
	return Lista;
}

Nodo *agregarNodo(Nodo *lista, char* identificador) {
	Nodo *nuevoNodo, *current;
	nuevoNodo = malloc(sizeof(Nodo));
	nuevoNodo->identificador = identificador;
	nuevoNodo->next = NULL;
	if(lista == NULL) {
		lista = nuevoNodo;
	}else {
		current = lista;
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = nuevoNodo;
	}
	return lista;
}

Nodo* buscarNodo(Nodo *lista, char* identificador){
	Nodo *aux;
	aux = lista;
	while(aux->identificador != identificador) {
		aux = aux->next;
	}
	return aux;
}
