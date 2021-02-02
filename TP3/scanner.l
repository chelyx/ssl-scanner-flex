%top{
	#include "tokens.h"
	#include <stdio.h>
}

%option outfile="scanner.c"
%option header-file="scanner.h"
%option noinput
%option nounput

Digito [0-9] 
Letra [[:alpha:]]
Alfanum [[:alnum:]]
Espacio  [[:space:]]
Otros [[:punct:]]{-}[().,+\-*/;#]
Asignacion 	<-
Comentario	"##".*
Identificador {Letra}{Alfanum}*
Constante {Digito}+

%%
programa						return PROGRAMA;
fin-prog						return FIN_PROG;
declarar						return DECLARAR;
leer							return LEER;
escribir 						return ESCRIBIR;
{Identificador}					return IDENTIFICADOR;
{Constante}						return CONSTANTE;
"("							return '(';
")"							return ')';
"."							return '.';
","							return ',';
"+"							return '+';
"-"							return '-';
"*"							return '*';
"/"							return '/';
";"							return ';';
"#"							return '#';
{Asignacion}						return ASIGNACION;
{Otros}+						printf("\nError léxico: cadena desconocida: %s",yytext);
{Letra}{Alfanum}*{Otros}+({Alfanum}|{Otros})*  	printf("\nError léxico: identificador inválido: %s",yytext);
{Digito}+{Letra}+{Alfanum}*				printf("\nError léxico: constante inválida: %s",yytext);
{Espacio}+						|
{Comentario}						|
.																													;
%%
