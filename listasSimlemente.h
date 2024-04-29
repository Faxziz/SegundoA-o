//
// Created by faxziz on 23/04/24.
//

#ifndef PRACTICALISTAS_LISTASSIMLEMENTE_H
#define PRACTICALISTAS_LISTASSIMLEMENTE_H

typedef void (*FuncionVisitante) (int dato);
typedef int (*FuncionComparadora) (int dato1,int dato2);

typedef struct _SNodo {
    int dato;
    struct _SNodo *sig;
} SNodo;

typedef SNodo *SList;

/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList lista);

/**
 * Determina si la lista es vacía.
 */
int slist_vacia(SList lista);

/**
 * Agrega un elemento al final de la lista.
 */
SList slist_agregar_final(SList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
SList slist_agregar_inicio(SList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

int slist_longitud(SList lista);
SList slist_concatenar(SList lista1,SList lista2);
void slist_insertar(SList lista1,int dato,int pos);
void slist_liminar(SList list,int);
int slist_contiene(SList list,int);
int slist_indice(SList list,int);
SList slist_intersecar(SList list,SList list2);
SList slist_intersecar_custom(SList list,SList list2, FuncionComparadora c);
void slist_ordenar(SList list);
SList slist_reverso(SList list);
SList slist_intercalar(SList list1, SList list2);
SNodo slist_partir(SList list);


#endif //PRACTICALISTAS_LISTASSIMLEMENTE_H
