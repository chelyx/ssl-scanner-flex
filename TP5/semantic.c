#include <stdio.h>
#include <string.h>
#include "semantic.h"
#include "symbol.h"

const int BYTES_RESERVA = 4;
struct nodo *lista;
int cont_temp = 0;

void iniciar(){
	printf("Load rtlib,\n");
}

void terminar() {
	printf("Exit,\n");
}

int declarar(char* id) {
	if(buscarIdentificador(lista, id) == 0) {
         agregarNodo(&lista, id);
         printf("Reserve %s, %d\n", id, BYTES_RESERVA);
        return 0;
       }
	printf("Error Semántico: identificador %s ya declarado\n", id);
	return 1;
}

void asignar(char* id){
	char* temp = nuevo_temporal();
	printf("Store %s, %s\n", temp, id);
}

void leer(char* id){
	printf("Read %s, Integer\n", id);
}

void escribir(char* id){
	char* temp= nuevo_temporal();
	printf("Write %s, %s\n", temp, id);
}

int existe_identificador(char* id){
	if(buscarIdentificador(lista, id) == 0){
	   printf("Error Semántico: identificador %s NO declarado\n", id);
	   return 1;
	}
	return 0;
}

char* generar_infijo(int op, char* id1, char* id2){
	char* operando1 = chequear_identificadores(id1);
	char* operando2 = chequear_identificadores(id2);
	char* tempRes = nuevo_temporal();
	switch(op) {
		case '+':
			printf("ADD %s, %s, %s\n", operando1, operando2, tempRes);
			break;
		case '-':
			printf("SUB %s, %s, %s\n", operando1, operando2, tempRes);
			break;
		case '*':
			printf("MUL %s, %s, %s\n", operando1, operando2, tempRes);
			break;
		case '/':
			printf("DIV %s, %s, %s\n", operando1, operando2, tempRes);
			break;
	}
	return tempRes;
}

char* chequear_identificadores(char* id) {
	if (buscarIdentificador(lista, id) == 0) {
		return nuevo_temporal();
	} else {
		return id;
	}
}

char* nuevo_temporal(){
	char array[15];
	sprintf(array, "Temp#%d", ++cont_temp);
	char* temporal = strdup(array);
	declarar(temporal);
	return temporal;
}

void generar_unario(char* id) {
	printf("NEG %s", id);
}

