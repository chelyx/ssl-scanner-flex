%%
%top{
	#include "tokens.h"
}
%option outfile="scanner.c"
%option header-file="scanner.h"
%option noinput
%option nounput
digito [0-9] 
letra [a-z][A-Z]
espacio
otros
identificador {digito}{letra}
constante_entera {digito}
%%

