%{
#include <stdio.h>
#include "scanner.h"
%}

%code provides {
extern int errlex; 	/* Contador de Errores Léxicos */

}

%defines "parser.h"
%output "parser.c"
%start program
%define api.value.type {char *}
%define parse.error verbose

%token FDT LEER DECLARAR ESCRIBIR PROGRAMA FIN_PROG IDENTIFICADOR CONSTANTE
%token ASIGNACION "<-"

%left  '-'  '+'
%left  '*'  '/'
%precedence NEG


%%
program :  PROGRAMA bloquesentencias FIN_PROG {if (errlex+yynerrs > 0) YYABORT;else YYACCEPT;};
bloquesentencias : codigo
		    | %empty
		    ;
codigo :   sentencia codigo  
  	 | sentencia
  	 ;
sentencia : LEER '('identificadores')' {printf("leer\n");}
       | ESCRIBIR '('expresiones')'   {printf("escribir\n");}
       | IDENTIFICADOR "<-" expresion  {printf("asignación\n");}
       | DECLARAR IDENTIFICADOR {printf("declarar %s\n",$2);}
       ;
identificadores :   IDENTIFICADOR 
                  | IDENTIFICADOR ',' identificadores 
 		   ;
expresiones :    expresion 
		| expresion ',' expresiones 
		;
expresion : 	termino 
		| expresion '+' termino {printf("suma\n");}
		| expresion '-' termino {printf("resta\n");}
 		;
termino : valor 
   	| termino '*' valor {printf("multiplicacion\n");}
   	| termino '/' valor {printf("division\n");}
 	;
valor : IDENTIFICADOR  
	| CONSTANTE  
	| '-'expresion %prec NEG  {printf("inversión\n");}
	| '('expresion')'   {printf("paréntesis\n");}
	;
%%

void yyerror(const char *s){
        printf("línea #%d  %s\n", yylineno, s);
        return;
}