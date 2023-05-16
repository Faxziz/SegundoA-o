#ifndef __EJERCICIO2_H
#define __EJERCICIO2_H

#include <stddef.h>

typedef struct SNodo {
	int dato;
	struct SNodo *sig;
} Nodo;

typedef Nodo *lista;

/** FUNCIONES AUXILIARES
 * */
Nodo* crear();
lista agregar_final(lista lista1, int dato);
int comparAR(int,int);
int menorIgual(int,int);
lista agregar_inicio(lista lista1, int);

 // -----------------------------------------------------------------


/**
 * Punto a) slist_longitud que devuelve la longitud de una lista
 * */
 int slist_longitud(lista lista1);


/**
 * Punto b) slist_concatenar que devuelve la concatenacion de 2 listas
 * modificando la primera
 * */
 lista slist_concatenar(lista lista1, lista lista2);
 
 /**
  * Punto c) slist_insertar que inserta un dato en una lista en una posicion arbitraria
  * */
  lista slist_insertar(lista lista1, int dato, int pos);


/** 
 * Punto d) slist_eliminar que elimina un dato en una lista en una posicion arbitraria
 * */

lista slist_eliminar(lista lista1, int pos);

/**
 * Punto e) slist_contiene que determina si un elemnto esta en una lista dada
 * */
int slist_contiene(lista lista1, int dato);

/**
 * Punto f) slist_indice que devuelve la posicion de la primera ocurrencia de un elemento
 * si el mismo esta en la lista dada, y -1 en caso que no esté
 * */
int slist_indice(lista lista1, int dato);

/**
 * Punto g) slist_intersecar que devuelve una lista con los elementos comunes.
 * De dos listas dadas por parametro. Las listas originales no se modifican.
 * */
lista slist_intersecar(lista lista1,lista lista2);

/*
 * Punto h) slist_intersecar_custom que devuelve una lista con los elementos comunes
 * de dos listas dadas por parametro y un puntero a una funcion como parametro que compara
 * los elementos.
 * */

lista slist_intersecar_custom(lista lista1, lista lista2, int(*ptrComparAR)(int,int));

/*
 * Punto i) slist_ordenar que ordena una lista de acuerdo al criterio dado por una funcion de comparacion
 * que usa los mismos valores de retorno que strcmp()) pasada por parametro
 * */
lista slist_ordenar(lista lista1, int(*ptrmenorIgual)(int,int));

/* 
 * Punto j) slist_reverso, que obtenga el reverso de la lista
 * *
 * */
lista slist_reverso(lista lista1);

/* 
 * Punto k) slist_intercalas que dadas dos listas, intercale sus elementos en la lista resultante.
 * Ejemplo: [1,2,3,4] y [5,6], debe obtener la lista [1,5,2,6,3,4]
 * */
lista slist_intercalar(lista lista1, lista lista2);

/* 
 * Punto l) slist_partir que divide una lista a la mitad- En caso de longitud impar
 * (2n+1), la primer lista tendra longitud n+1 y la segunda n. Retorna un puntero
 * al primer elemento de la segunda mitad, siempre que no sea vacia.
 * */
Nodo* slist_partir(lista lista1);










#endif
