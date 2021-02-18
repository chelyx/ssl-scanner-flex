%{
#include <stdio.h>
#include "scanner.h"
#include "semantic.h"
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
program             : PROGRAMA sentenciasfin { iniciar(); }
                    ;
sentenciasfin       : bloquesentencias fin { if (errlex+yynerrs > 0) YYABORT; else YYACCEPT;}
                    ;
fin                 : FIN_PROG { terminar(); }
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
                    | identificadores ',' identificador
                    ;
expresiones         : expresion
                    | expresiones ','expresion
                    ;
expresion           : expresion '+' expresion { $$ = generar_infijo('+', $1, $3); }
                    | expresion '-' expresion { $$ = generar_infijo('-', $1, $3); }
                    | expresion '*' expresion { $$ = generar_infijo('*', $1, $3); }
                    | expresion '/' expresion { $$ = generar_infijo('/', $1, $3); }
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
