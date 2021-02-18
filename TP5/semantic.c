#include <stdio.h>
#include <string.h>
#include "semantic.h"
#include "parser.h"
#include "symbol.h"

extern int errsemantic;
const int BYTES_RESERVA = 4;
struct nodo *lista;
int cont_temp = 0;
char errmsg[200];

void iniciar(){
	printf("Load rtlib,\n");
}

void terminar() {
	printf("Exit,\n");
}

void asignar(char* id, char* unAlmacenable){
	printf("Store %s, %s\n", unAlmacenable, id);
}

void leer(char* id){
	printf("Read %s, Integer\n", id);
}

void escribir(char* id){
	printf("Write %s, Integer\n", id);
}

int declarar(char* id) {
	if(buscarIdentificador(lista, id) == 0) {
		agregarNodo(&lista, id);
		printf("Reserve %s, %d\n", id, BYTES_RESERVA);
		return 0;
	}
    	errsemantic++;
	sprintf(errmsg,"Error semántico: identificador %s ya declarado", id);
	yyerror(errmsg);
	return 1;
}

int existe_identificador(char* id){
	if(buscarIdentificador(lista, id) == 0){
		errsemantic++;
		sprintf(errmsg,"Error semántico: identificador %s NO declarado", id);
		yyerror(errmsg);
		return 1;
	}
	return 0;
}

char* generar_infijo(int op, char* id1, char* id2){
	char* tempRes = nuevo_temporal();
	switch(op) {
		case '+':
			printf("ADD %s, %s, %s\n", id1, id2, tempRes);
			break;
		case '-':
			printf("SUB %s, %s, %s\n", id1, id2, tempRes);
			break;
		case '*':
			printf("MUL %s, %s, %s\n", id1, id2, tempRes);
			break;
		case '/':
			printf("DIV %s, %s, %s\n", id1, id2, tempRes);
			break;
	}
	return tempRes;
}

char* nuevo_temporal(){
	char array[15];
	sprintf(array, "Temp#%d", ++cont_temp);
	char* temporal = strdup(array);
	declarar(temporal);
	return temporal;
}

char* generar_unario(char* id) {
	char* tempRes = nuevo_temporal();
 	printf("NEG %s,,%s\n", id, tempRes);
 	return tempRes;
}

