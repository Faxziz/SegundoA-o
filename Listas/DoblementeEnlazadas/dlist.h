#ifndef __EJERCICIO4_H
#define __EJERCICIO4_H

typedef struct _DNodo {
	int dato;
	struct _DNodo* sig;
	struct _DNodo* ant;
} DNodo;

typedef struct {
	DNodo* primero;
	DNodo* ultimo;
} DList;

typedef enum {
	DLIST_RECORRIDO_HACIA_ADELANTE,
	DLIST_RECORRIDO_HACIA_ATRAS
} DListOrdenDeRecorrido;

DList crear();
int DListLongitud(DList lista1);
DList dlist_agregar_inicio(DList lista1, int dato);
DList dlist_agregar_final(DList lista, int dato);
void imprimirlista(DList lista, DListOrdenDeRecorrido orden);
DList concatenar(DList lista1, DList lista2);
DList eliminar(DList lista, int pos);

#endif
