%top{
	#include "tokens.h"
	#include <stdio.h>
}

%option outfile="scanner.c"
%option header-file="scanner.h"
%option noinput
%option nounput

Digito [[:digit:]] 
Letra [[:alpha:]]
Alfanum [[:alnum:]]
Espacio  [[:space:]]
Otros [[:^alnum:]]{-}[[:space:]]{-}[-+*/();,<#]
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
","							return ',';
"+"							return '+';
"-"							return '-';
"*"							return '*';
"/"							return '/';
";"							return ';';
{Asignacion}						return ASIGNACION;
{Letra}{Alfanum}*{Otros}+({Alfanum}|{Otros})*   printf("Error léxico: identificador inválido: %s\n",yytext);
{Digito}+{Letra}+{Alfanum}*                     printf("Error léxico: constante inválida: %s\n",yytext);
{Espacio}+                                      |
{Comentario}                                    ;
{Otros}+                                        |
.                                               printf("Error léxico: cadena desconocida: %s\n",yytext);																							;
%%
