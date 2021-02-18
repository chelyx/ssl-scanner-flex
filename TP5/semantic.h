#ifndef SEMANTIC_H_INCLUDED
#define SEMANTIC_H_INCLUDED
void iniciar(void);
void terminar(void);
int declarar(char* id);
void asignar(char* id);
void leer(char* id);
void escribir(char* id);
int existe_identificador(char* id);
char* generar_infijo(int op, char* id1, char* id2);
void generar_unario(char* id);
char* chequear_identificadores(char* id);
char* nuevo_temporal(void);
#endif

