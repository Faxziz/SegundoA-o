//
// Created by faxziz on 23/04/24.
//
#include <stdio.h>
#include <stdlib.h>
#include "listasSimlemente.h"

SList slist_crear() {
    return NULL;
}

void slist_destruir(SList lista) {
    SNodo *nodoAEliminar;
    while (lista != NULL) {
        nodoAEliminar = lista;
        lista = lista->sig;
        free(nodoAEliminar);
    }
}

int slist_vacia(SList lista) {
    return lista == NULL;
}

SList slist_agregar_final(SList lista, int dato) {
    SNodo *nuevoNodo = malloc(sizeof(SNodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;

    if (lista == NULL)
        return nuevoNodo;

    SList nodo = lista;
    for (;nodo->sig != NULL;nodo = nodo->sig);
    /* ahora 'nodo' apunta al ultimo elemento en la lista */

    nodo->sig = nuevoNodo;
    return lista;
}

SList slist_agregar_inicio(SList lista, int dato) {
    SNodo *nuevoNodo = malloc(sizeof(SNodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = lista;
    return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
    for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
        visit(nodo->dato);
}

int slist_longitud(SList lista) {
    int i = 0;
    if (lista == NULL) {
        return i;
    }
    for(SNodo* nodo=lista;nodo->sig != NULL;nodo = nodo->sig) {
        i++;
    }
    return i;
}

SList slist_concatenar(SList lista1,SList lista2) {
    if (lista1 == NULL && lista2 == NULL) {
        return NULL;
    } else if (lista1 == NULL) {
        return lista2;
    } else if (lista2 == NULL) {
        return lista1;
    }
    SNodo* temp = lista1;
    for(;temp->sig != NULL;temp = temp->sig);
    temp->sig = lista2;
    return lista1;
}

void slist_insertar(SList lista1, int dato, int pos) {
    // Crear un nuevo nodo con el dato proporcionado
    SNodo* nuevoNodo = malloc(sizeof(SNodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;

    // Verificar si la lista está vacía o si la posición es negativa
    if (lista1 == NULL || pos < 0) {
        printf("Error: Lista vacía o posición inválida.\n");
        free(nuevoNodo); // Liberar memoria del nuevo nodo
        return;
    }

    // Si la posición es cero, el nuevo nodo será el nuevo inicio de la lista
    if (pos == 0) {
        nuevoNodo->sig = lista1;
        return;
    }

    // Buscar el nodo en la posición anterior a la posición de inserción
    int i = 0;
    SNodo* temp = lista1;
    while (temp->sig != NULL && i < pos - 1) {
        temp = temp->sig;
        i++;
    }

    // Verificar si la posición de inserción es válida
    if (i != pos - 1) {
        printf("Error: Posición de inserción inválida.\n");
        free(nuevoNodo); // Liberar memoria del nuevo nodo
        return;
    }

    // Insertar el nuevo nodo después del nodo en la posición anterior a la posición de inserción
    nuevoNodo->sig = temp->sig;
    temp->sig = nuevoNodo;
}

void slist_liminar(SList lista, int pos) {
    // Verificar si la lista está vacía
    if (lista == NULL) {
        printf("Error: Lista vacía.\n");
        return;
    }

    // Si la posición es negativa, no se puede eliminar
    if (pos < 0) {
        printf("Error: Posición inválida.\n");
        return;
    }

    // Buscar el nodo en la posición dada
    int i = 0;
    SNodo* temp = lista;
    while (temp != NULL && i < pos) {
        temp = temp->sig;
        i++;
    }

    // Verificar si la posición es válida
    if (temp == NULL || temp->sig == NULL) {
        printf("Error: Posición inválida.\n");
        return;
    }

    // Guardar el nodo siguiente al nodo que se va a eliminar
    SNodo* nodoAEliminar = temp->sig;
    // Conectar el nodo actual con el nodo siguiente al nodo a eliminar
    temp->sig = temp->sig->sig;
    // Liberar la memoria del nodo a eliminar
    free(nodoAEliminar);
}

int slist_contiene(SList lista,int dato) {
    int res = 0;
    if (lista == NULL) {
        return res;
    }
    for(SNodo* temp = lista;temp->sig != NULL;temp = temp->sig) {
        if (temp->dato == dato) {
            res = 1;
        }
    }
    return res;
}

int slist_indice(SList lista,int dato) {
    int i=0;
    int res = 0;
    if (lista == NULL) {
        return res;
    }
    for(SNodo* temp=lista;temp->sig != NULL;temp = temp->sig) {
        if (temp->dato == dato) {
            res = i;
        }
        i++;
    }
    return res;
}

SList slist_intersecar(SList lista1,SList lista2) {
    SList aux = slist_crear();
    if (lista1 == NULL || lista2 == NULL) {
        return NULL;
    }
    for(SNodo* temp1 = lista1;temp1->sig != NULL;temp1 = temp1->sig) {
        for(SNodo* temp2 = lista2;temp2->sig != NULL;temp2 = temp2->sig) {
            if (temp1->dato == temp2->dato) {
                aux = slist_agregar_final(aux,temp1->dato);
            }
        }
    }
    return aux;
}

SList slist_intersecar_custom(SList lista1,SList lista2,FuncionComparadora c) {
    SList aux = slist_crear();
    if (lista1 == NULL && lista2 == NULL) {
        return NULL;
    }
    for(SNodo* temp1 = lista1;temp1->sig != NULL;temp1 = temp1->sig) {
        for(SNodo* temp2 = lista2;temp2->sig != NULL;temp2 = temp2->sig) {
            if (c(temp1->dato,temp2->dato)) {
                aux = slist_agregar_final(aux,temp1->dato);
            }
        }
    }
    return aux;
}

SList slist_reverso(SList list) {
    SList aux = slist_crear();
    for(SNodo* temp=list;temp->sig != NULL;temp = temp->sig) {
        aux = slist_agregar_inicio(aux,temp->dato);
    }
    return aux;
}

SList slist_intercalar(SList lista1,SList lista2) {
    SList aux = slist_crear();
    for(SNodo* temp = lista1;temp->sig != NULL;temp = temp->sig) {
        aux = slist_agregar_final(aux,temp->dato);
        for(SNodo* temp2 = lista2;temp2->sig != NULL;temp = temp->sig) {
            aux = slist_agregar_final(aux,temp2->dato);
        }
    }
    return aux;
}

int main() {

    return 0;
}
