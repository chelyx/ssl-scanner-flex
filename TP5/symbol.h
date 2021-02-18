#ifndef SYMBOL_H_INCLUDED
#define SYMBOL_H_INCLUDED

struct nodo {
    char identificador[32];
    struct nodo *next;
};

void agregarNodo(struct nodo **lista, char* identificador);
int buscarIdentificador(struct nodo *lista, char *identificador);
void imprimirLista(struct nodo *lista);

#endif // SYMBOL_H_INCLUDED
