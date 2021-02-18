//////////////////////////////////////////////////////////////////////////////////////
/*
      TP5 - Grupo 7
      Araceli Soffulto
      Guillermo Kalniker
      Juan Ferro
                                                                                    */
//////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include "parser.h"
#include "scanner.h"

extern int yynerrs;
int errsemantic = 0;

int main() {
	switch( yyparse() ){
	case 0:
		puts("Compilacion terminada con exito"); 
		printf("Errores sintácticos: %d - Errores léxicos: %d - Errores Semánticos: %d\n",yynerrs,errlex,errsemantic); 
		return 0;
	case 1:
		puts("Errores de compilación");	
		printf("Errores sintácticos: %d - Errores léxicos: %d - Errores Semánticos: %d\n",yynerrs,errlex,errsemantic); 
		return 1;
	case 2:
		puts("Memoria insuficiente"); 
		return 2;
	}
	return 0;
}
