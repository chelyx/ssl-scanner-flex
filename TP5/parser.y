%{
#include <stdio.h>
#include "scanner.h"
%}

%code provides {
void yyerror(const char *);
extern int errlex;
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
program             : PROGRAMA bloquesentencias FIN_PROG { if (errlex+yynerrs > 0) YYABORT; else YYACCEPT; }
                    ;
bloquesentencias    : codigo
                    | %empty
                    ;
codigo              : codigo sentencia
                    | sentencia
                    ;
sentencia           : LEER '('identificadores')' ';' { leer($2); }
                    | ESCRIBIR '('expresiones')' ';' { escribir($2); }
                    | identificador "<-" expresion ';' { asignar($1); }
                    | DECLARAR IDENTIFICADOR ';' { if(declarar($2)) YYERROR; }
                    | error ';'
                    ;
identificadores     : identificador
                    | identificadores ',' IDENTIFICADOR
                    ;
expresiones         : expresion
                    | expresiones ','expresion
                    ;
expresion           : expresion '+' expresion { printf("suma\n"); }
                    | expresion '-' expresion { printf("resta\n"); }
                    | expresion '*' expresion { printf("multiplicación\n"); }
                    | expresion '/' expresion { printf("división\n"); }
                    | identificador
                    | CONSTANTE
                    | '-'expresion %prec NEG { printf("inversión\n"); }
                    | '('expresion')' { $$ = $2; }
                    ;
identificador       : IDENTIFICADOR { if(existe_identificador($1)) YYERROR;}
%%
void yyerror(const char *s){
        printf("línea #%d  %s\n", yylineno, s);
        return;
}
