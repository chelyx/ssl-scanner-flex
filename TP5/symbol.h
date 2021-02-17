typedef struct nodo {
	char* identificador;
	struct nodo *next;
}Nodo;

Nodo *agregarNodo(Nodo *lista, char* identificador);
Nodo *crearLista(void);
Nodo *buscarNodo(Nodo *lista, char* identificador);
