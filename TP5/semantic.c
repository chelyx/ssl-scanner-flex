#include <stdio.h>
#include "semantic.h"
#include "symbol.h"

const int BYTES_RESERVA = 4;
Nodo *lista;

void iniciar(){
	printf("Load rtlib,\n");
	lista = crearLista();
}

void terminar() {
	liberarLista(lista);
	printf("Exit,\n");
}

int declarar(char* id) {
	if(buscarNodo(lista, id) == NULL) {
         agregarNodo(lista, id);
         printf("Reserve %s, %d", id, BYTES_RESERVA);
        return 0;
       }
	printf("Error Semántico: identificador %s ya declarado", id);
	return 1;
}

void asignar(char* id){
	printf("Store Temp#%d, %s", 0, id);
}

void leer(char* id){
	printf("Read %s, Integer", id);
}

void escribir(char* id){
	printf("Write Temp#%d, %s", 0, id);
}

int existe_identificador(char* id){
	if(buscarNodo(lista, id) == NULL){
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

