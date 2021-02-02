int main() {
	TOKEN token;
	
	do {
		char res[50];
		token = yylex();
		switch(token){
			case PROGRAMA:
				strcpy(res, "Token: Programa");
				break;
			case ESCRIBIR:
				strcpy(res, "Token: Escribir");
				break;
			case LEER:
				strcpy(res, "Token: Leer");
				break;
			case DECLARAR:
				strcpy(res, "Token: Declarar");
				break;
		}
	}
}
