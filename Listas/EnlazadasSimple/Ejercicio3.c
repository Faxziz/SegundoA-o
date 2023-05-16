#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _SNodo {
	int dato;
	struct _SNodo *sig;
} SNodo;


typedef struct SList {
	SNodo *primero;
	SNodo *ultimo;
} List;

List slist_crear();
List slist_agregar_inicio(List lista1, int dato);
List slist_agregar_final(List lista1, int dato);
void imprimirLista(List lista1);

int main(int argc, char **argv)
{
	
	List lista1 = slist_crear();
	lista1 = slist_agregar_inicio(lista1, 1);
	lista1 = slist_agregar_final(lista1,5);
	imprimirLista(lista1);
	
	return 0;
}

List slist_crear() {
	List nuevaLista;
	nuevaLista.primero = NULL;
	nuevaLista.ultimo = NULL;
	return nuevaLista;
}

List slist_agregar_inicio(List lista1, int dato) {
	SNodo *nuevoNodo = (SNodo*)malloc(sizeof(SNodo));
	nuevoNodo->dato = dato;
	nuevoNodo->sig = lista1.primero;
	lista1.primero = nuevoNodo;
	if (lista1.ultimo == NULL) {
		lista1.ultimo = nuevoNodo;
	}
	
	return lista1;
}

List slist_agregar_final(List lista1, int dato) {
	SNodo *nuevoNodo = (SNodo*)malloc(sizeof(SNodo));
	nuevoNodo->dato = dato;
	nuevoNodo->sig = NULL;
	
	if (lista1.ultimo != NULL) {
		lista1.ultimo->sig = nuevoNodo;
	}
	
	lista1.ultimo = nuevoNodo;
	if (lista1.primero == NULL) {
		lista1.primero = nuevoNodo;
	}
	
	return lista1;
}

void imprimirLista(List lista1) {
	SNodo *nuevoNodo = lista1.primero;
	while (nuevoNodo != NULL) {
		printf("%d\n", nuevoNodo->dato);
		nuevoNodo = nuevoNodo->sig;
	}
	printf("\n");
}
