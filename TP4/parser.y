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
sentencia           : LEER '('identificadores')' ';' { printf("leer\n"); }
                    | ESCRIBIR '('expresiones')' ';' { printf("escribir\n"); }
                    | IDENTIFICADOR "<-" expresion ';' { printf("asignación\n"); }
                    | DECLARAR IDENTIFICADOR ';' { printf("declarar %s\n",$2); }
                    | error ';'
                    ;
identificadores     : IDENTIFICADOR
                    | identificadores ',' IDENTIFICADOR
                    ;
expresiones         : expresion
                    | expresiones ','expresion
                    ;
expresion           : expresion '+' expresion { printf("suma\n"); }
                    | expresion '-' expresion { printf("resta\n"); }
                    | expresion '*' expresion { printf("multiplicación\n"); }
                    | expresion '/' expresion { printf("división\n"); }
                    | IDENTIFICADOR
                    | CONSTANTE
                    | '-'expresion %prec NEG { printf("inversión\n"); }
                    | '('expresion')' { printf("paréntesis\n"); }
                    ;
%%
void yyerror(const char *s){
        printf("línea #%d  %s\n", yylineno, s);
        return;
}
