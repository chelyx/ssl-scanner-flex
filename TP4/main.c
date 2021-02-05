#include <stdio.h>
#include "parser.h"
#include "scanner.h"
extern int yynerrs;

int main() {
	switch( yyparse() ){
	case 0:
		puts("Compilacion terminada con exito"); 
		printf("Errores sintácticos: %d - Errores léxicos: %d\n",yynerrs,errlex); 
		return 0;
	case 1:
		puts("Errores de compilación");	
		printf("Errores sintácticos: %d - Errores léxicos: %d\n",yynerrs,errlex); 
		return 1;
	case 2:
		puts("Memoria insuficiente"); 
		return 2;
	}
	return 0;
}
