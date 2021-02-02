%%
%top{
	#include "tokens.h"
}
%option outfile="scanner.c"
%option header-file="scanner.h"
%option noinput
%option nounput
Digito 			[0-9] 
Letra 			[[:alpha:]]
Identificador 		[[:alnum:]]
Espacio  		[[:space:]]
Otros 			[[:punct:]]{-}[().,+\-*/]
OperadorAsignacion 	<-
Comentario		"//".*
%%
programa						return PROGRAMA;
fin							return FIN_PROG;
declarar						return DECLARAR;
leer							return LEER;
escribir 						return ESCRIBIR;
{Letra}{LetraDigito}*					return IDENTIFICADOR;
{Digito}+						return CONSTANTE;
"("							return '(';
")"							return ')';
"."							return '.';
","							return ',';
"+"							return '+';
"-"							return '-';
"*"							return '*';
"/"							return '/';
{OperadorAsignacion}					return ASIGNACION;
{Otros}+						printf("Error léxico: cadena desconocida: %s\n",yytext);
{Letra}{LetraDigito}*{Otros}+({LetraDigito}|{Otros})*   printf("Error léxico: identificador inválido: %s\n",yytext);
{Digito}+{Letra}+{LetraDigito}*				printf("Error léxico: constante inválida: %s\n",yytext);
{Espacio}+						|
{Comentario}						|
.																													;
%%
