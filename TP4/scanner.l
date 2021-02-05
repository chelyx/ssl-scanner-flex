%top{
	#include <stdio.h>
	#include "parser.h"
	int errlex;
	char msg[200];
	void yyerror(const char *);
}


%option outfile="scanner.c"
%option header-file="scanner.h"
%option noinput
%option nounput
%option noyywrap
%option yylineno

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
{Identificador}					{yylval = strdup(yytext); return IDENTIFICADOR;}
{Constante}						{yylval = strdup(yytext); return CONSTANTE;}
"("							return '(';
")"							return ')';
","							return ',';
"+"							return '+';
"-"							return '-';
"*"							return '*';
"/"							return '/';
";"							return ';';
{Asignacion}						return ASIGNACION;
{Letra}{Alfanum}*{Otros}+({Alfanum}|{Otros})* {sprintf(msg,"Error léxico: identificador inválido: %s",yytext);yyerror(msg);errlex++;}
{Digito}+{Letra}+{Alfanum}*                	{sprintf(msg,"Error léxico: constante inválida: %s",yytext);yyerror(msg);errlex++;}
{Espacio}+                                      |
{Comentario}                                    ;
{Otros}+                                        |
.                                             {sprintf(msg,"Error léxico: cadena desconocida: %s", yytext);yyerror(msg);errlex++;}																						;
%%