#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

DList crear() {
	DList nuevaLista;
	nuevaLista.primero = NULL;
	nuevaLista.ultimo = NULL;
	return nuevaLista;
}

DList dlist_agregar_inicio(DList lista1, int dato) {
	DNodo *nuevoNodo = (DNodo*)malloc(sizeof(DNodo));
	nuevoNodo->dato = dato;
	nuevoNodo->sig = lista1.primero;
	nuevoNodo->ant = NULL;
	if (lista1.primero == NULL) {
		lista1.ultimo = nuevoNodo;
	} else {
		lista1.primero->ant = nuevoNodo;
	}
	lista1.primero = nuevoNodo;
	
	return lista1;
}

DList dlist_agregar_final(DList lista, int dato) {
	DNodo *nuevoNodo = (DNodo*)malloc(sizeof(DNodo));
	nuevoNodo->dato = dato;
	nuevoNodo->sig = NULL;
	nuevoNodo->ant = lista.ultimo;
	
	if (lista.primero == NULL) {
		lista.primero = nuevoNodo;
	} else {
		lista.ultimo->sig = nuevoNodo;
	}
	lista.ultimo = nuevoNodo;
	
	return lista;
}

void imprimirlista(DList lista, DListOrdenDeRecorrido orden) {
	if (orden == DLIST_RECORRIDO_HACIA_ADELANTE) {
		DNodo *nodoActual = lista.primero;
		while (nodoActual != NULL) 
		{
			printf("\n %d ", nodoActual->dato);
			nodoActual = nodoActual->sig;
		} 
	} else if (orden == DLIST_RECORRIDO_HACIA_ATRAS) {
		DNodo* nodoActual = lista.ultimo;
		while (nodoActual != NULL) {
			printf("\n %d ", nodoActual->dato);
			nodoActual = nodoActual->ant;
		}
	}
	
	printf("\n");
}

int DListLongitud(DList lista) {
	int contador = 0;
	for(DNodo *nodo = lista.primero;nodo != NULL;nodo = nodo->sig) {
		contador++;
	}
	return contador;
}

DList eliminar(DList lista, int pos) {
	if (lista.primero == NULL || pos < 0 || pos >= DListLongitud(lista)) {
		return lista;
	}
	
	DNodo *nodoActual = lista.primero;
	for(int i=0;i<pos;i++) {
		nodoActual = nodoActual->sig;
	}
	
	if (nodoActual == lista.primero) {
		lista.primero = nodoActual->sig;
	} else {
		nodoActual->ant->sig = nodoActual->sig;
	}
	
	if (nodoActual == lista.ultimo) {
		lista.ultimo = nodoActual->ant;
	} else {
		nodoActual->ant->sig = nodoActual->ant;
	}
	
	return lista;
		
}

int main()
{
	DList lista;
	lista = crear();
	lista = dlist_agregar_inicio(lista,1);
	lista = dlist_agregar_final(lista,5);
	printf("La longitud de la vista: %d \n ", DListLongitud(lista));

	eliminar(lista,1);
	imprimirlista(lista, DLIST_RECORRIDO_HACIA_ADELANTE);
	dlist_agregar_inicio(lista,1);
	eliminar(lista,2);
	imprimirlista(lista, DLIST_RECORRIDO_HACIA_ATRAS);
	return 0;
}

