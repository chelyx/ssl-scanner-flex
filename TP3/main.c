//////////////////////////////////////////////////////////////////////////////////////
/*
      TP3 - Grupo 7
      Araceli Soffulto
      Guillermo Kalniker
      Juan Ferro
                                                                                    */
//////////////////////////////////////////////////////////////////////////////////////
#include "scanner.h"
int main() {
	int token;
	
	do {
		token = yylex();
		
		switch(token){
			case PROGRAMA:
				printf("Token: Programa\n");
				break;
			case FIN_PROG:
				printf("Token: Fin-Prog\n");
				break;
			case DECLARAR:
				printf("Token: Declarar\n");
				break;
			case LEER:
				printf("Token: Leer\n");
				break;
			case ESCRIBIR:
				printf("Token: Escribir\n");
				break;
			case IDENTIFICADOR:
				printf("Token: Identificador, Lexema: %s\n", yytext);
				break;
			case CONSTANTE:
				printf("Token: Constante, Lexema: %s\n", yytext);
				break;
			case '(':
				printf("Token: \'(\'\n");
				break;
			case ')':
				printf("Token: \')\'\n");
				break;
			case ',':
				printf("Token: \',\'\n");
				break;
			case '+':
				printf("Token: \'+\'\n");
				break;
			case '-':
				printf("Token: \'-\'\n");
				break;
			case '*':
				printf("Token: \'*\'\n");
				break;
			case '/':
				printf("Token: \'/\'\n");
				break;
			case ';':
				printf("Token: \';\'\n");
				break;
			case ASIGNACION:
				printf("Token: Asignación\n");
				break;
			case FDT:
				printf("Token: Fin de Archivo\n");
				break;
		}
	}while(token!=FDT);
	
	return 0;
}
