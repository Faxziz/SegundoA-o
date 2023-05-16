#include <stdio.h>
#include <stdlib.h>
#include "ejercicio8.h"

// FUNCIONES
SGList sglist_crear() {
	return NULL;
}

// aux
void destructura(SGList lista1) {
	free(lista1->dato);
	free(lista1->next);
}

void visitante(SGList lista1) {
	GList *nodo = lista1;
	printf("%p \n", nodo->dato);
	nodo = nodo->next;
}

//
void sglist_destruir(SGList lista1, FuncionDestructora p) {
	GList *newNodo;
	while (lista1 != NULL) {
		newNodo = lista1;
		lista1 = lista1->next;
		p(newNodo->dato);
		free(newNodo);
	}
}

int sglist_vacia(SGList lista1) {
	int band;
	if (lista1->dato == NULL) {
		band = 1;
	} else {
		band = 0;
	}
	return band;
}

void sglist_recorrer(SGList lista1, FuncionVisitante p) {
	GList *newNodo = malloc(sizeof(GList));
	newNodo = lista1;
	
	for(int i=0;newNodo != NULL;i++) {
		p(newNodo->dato);
	}
	newNodo = newNodo->next;
}
// --------------------------------
int main()
{
	
	return 0;
}

