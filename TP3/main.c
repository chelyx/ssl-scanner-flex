#include "scanner.h"
int main() {
	TOKEN token;
	
	do {
		token = yylex();
		
		switch(token){
			case PROGRAMA:
				printf("\nToken: Programa");
				break;
			case ESCRIBIR:
				printf("\nToken: Escribir");
				break;
			case LEER:
				printf("\nToken: Leer");
				break;
			case DECLARAR:
				printf("\nToken: Declarar");
				break;
			case IDENTIFICADOR:
				printf("\nToken: Identificador, Lexema: %s", yytext);
				break;
			case CONSTANTE:
				printf("\nToken: Constante, Lexema: %s", yytext);
				break;
			case ASIGNACION:
				printf("\nToken: Asignación");
				break;
			default:
				printf("\nToken: %s", yytext);
				break;
				
		}
	}while(token!=FDT);
	printf("Fin de Archivo");
	
	return 0;
}
