#include <stdio.h>
#include <stdbool.h>
#include "semantic.h"
#include "symbol.c"

const int BYTES_RESERVA = 4;
Nodo *lista;

void iniciar(){
	printf("Load rtlib,\n");
	lista = crearLista();
}

void terminar() {
	printf("Exit,\n");
}

int declarar(char* id) {
	if(!contiene_nodo(id)) {
         agregarNodo(lista, id);
         printf("Reserve %s, %i", id, BYTES_RESERVA);
        return 0;
       }
	printf("Error Semántico: identificador %s ya declarado", id);
	return 1;
}

void asignar(char* id){
	printf("Store Temp#%i, %s", 0, id);
}

void leer(char* id){
	printf("Read %s, Integer", id);
}

void escribir(char* id){
	printf("Write Temp#%i, %s", 0, id);
}

int existe_identificador(char* id){
	if(!contiene_nodo(id)){
	   printf("Error Semántico: identificador %s NO declarado", id);
	   return 1;
	}
	return 0;
}

void generar_infijo(int op, char* id1, char* id2){
	switch(op) {
		case '+':
			printf("ADD ");
			break;
		case '-':
			printf("SUB ");
			break;
		case '*':
			printf("MUL ");
			break;
		case '/':
			printf("DIV ");
			break;
	}
}

void generar_unario(char* id) {
	printf("NEG %s", id);
}

bool contiene_nodo(char* id) {
	return buscarNodo(lista, id) != NULL;
}
