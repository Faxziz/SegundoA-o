 #include "ejercicio2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

Nodo* crear() {
	return NULL;
}

lista agregar_final(lista lista1, int dato) {
  Nodo *nuevoNodo = malloc(sizeof(Nodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista1 == NULL)
    return nuevoNodo;

  lista nodo = lista1;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista1;
}

lista agregar_inicio(lista lista1, int dato) {
  Nodo *nuevoNodo = malloc(sizeof(Nodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista1;
  return nuevoNodo;
}

int slist_longitud(lista lista1) {
    int contador = 0;
    for (Nodo *nodo = lista1; nodo != NULL; nodo = nodo->sig) {
        contador++;
    }
    return contador;
}

lista slist_concatenar(lista lista1, lista lista2) {
	if (lista1 == NULL) {
		return lista2;
	}
	
	Nodo *nodo=lista1;
	for(; nodo->sig != NULL; nodo = nodo->sig);
	// nodo->sig apunta al ultimo elemento de la lista1;
	nodo = nodo->sig;
	
	//Unimos los datos
	nodo->sig = lista2;
	
	return lista1;
}

lista slist_insertar(lista lista1, int dato, int pos) {
	Nodo *nuevoNodo = malloc(sizeof(Nodo));
	nuevoNodo->dato = dato;
	nuevoNodo->sig = NULL;
	
	if (pos == 0) {
		nuevoNodo->sig = lista1;
		lista1 = nuevoNodo;
	} else {
		Nodo *nodoAnterior = lista1;
		for(int i=0;i < pos-1 && nodoAnterior->sig != NULL; i++) {
			nodoAnterior = nodoAnterior->sig;
		}
		nuevoNodo->sig = nodoAnterior->sig;
		nodoAnterior->sig = nuevoNodo;
	}
	
	return lista1;
}

lista slist_eliminar(lista lista1, int pos) {
	
	if (pos == 0) {
		Nodo *nodo_eliminar = lista1;
		lista1 = lista1->sig;
		free(nodo_eliminar);
	} else {
		Nodo *nodo = lista1;
		for(int i=0;i <= pos-1 && nodo->sig != NULL;i++) {
			nodo = nodo->sig;
		}
		Nodo *nodo_eliminar = nodo->sig;
		nodo->sig = nodo_eliminar->sig;
		free(nodo_eliminar);
	}
	return lista1;
}

int slist_contiene(lista lista1,int dato) {
	int pos = 0;
	int band = 0;
	Nodo *nodoNuevo = lista1;
	
	while(nodoNuevo != NULL) {
		if(nodoNuevo->dato == dato) {
			band = 1;
		}
		nodoNuevo = nodoNuevo->sig;
		pos++;
	}
	return band;
}

int slist_indice(lista lista1, int dato) {
	Nodo *nodoNuevo = lista1;
	int pos = 0;
	
	while (nodoNuevo != NULL) {
		if (nodoNuevo->dato == dato) {
			return pos;
		}
		nodoNuevo = nodoNuevo->sig;
		pos++;
	}
	return -1;
}


lista slist_intersecar(lista lista1,lista lista2) {
	if (lista1 == NULL || lista2 == NULL) {
		return 0;
	}
	
	lista nodoTotal = crear();
	Nodo *nodoNuevo1 = lista1;
	Nodo *nodoNuevo2 = lista2;
	
	while(nodoNuevo1 != NULL) {
		while(nodoNuevo2 != NULL) {
			if (nodoNuevo1->dato == nodoNuevo2->dato) {
				agregar_final(nodoTotal, nodoNuevo1->dato);
				break;
				}
				nodoNuevo2 = nodoNuevo2->sig;
			}
		nodoNuevo2 = lista1;
		nodoNuevo1 = nodoNuevo1->sig;
	}
	return nodoTotal;
}

int comparAR(int n1, int n2) {
	int band;
	
	if (n1 == n2) {
		band = 1;
	} else {
		band = 0;
	}
	return band;
}

lista slist_intersecar_custom(lista lista1, lista lista2, int(*ptrComparAR)(int,int)) {
	if (lista1 == NULL || lista2 == NULL) {
		return 0;
	}
	
	lista nodoTotal = crear();
	Nodo *nodoNuevo1 = lista1;
	Nodo *nodoNuevo2 = lista2;
	
	int booleano = ptrComparAR(nodoNuevo1->dato, nodoNuevo2->dato);
	
	while (nodoNuevo1 != NULL) {
		while (nodoNuevo2 != NULL) {
			if (booleano == 1) {
				agregar_final(nodoTotal, nodoNuevo1->dato);
				break;
			}
			nodoNuevo2 = nodoNuevo2->sig;
		}
		nodoNuevo2 = lista1;
		nodoNuevo1 = nodoNuevo1->sig;
	}
	
	return nodoTotal;
}

int menorIgual(int n1,int n2) {
	int resultado;
	if (n1 <= n2) {
		resultado = n1;
	} else {
		resultado = n2;
	}
	return resultado;
}

lista slist_ordenar(lista lista1, int(*ptrmenorIgual)(int,int)) {
	Nodo *actual = NULL, *siguiente = NULL;
	int temp = 0;
	int longitud = slist_longitud(lista1);
	
	for(int i=0;i<longitud;i++) {
		actual = lista1;
		siguiente = actual->sig;
		for(int j=0;j<longitud-1;j++) {
			if (ptrmenorIgual(actual->dato,siguiente->dato) > 0) {
				temp = actual->dato;
				actual->dato = siguiente->dato;
				siguiente->dato = temp;
			}
			actual = siguiente;
			siguiente = siguiente->sig;
		}
	}
	
	return lista1;
}

lista slist_reverso(lista lista1) {
	Nodo *nodoNuevo = lista1;
	Nodo *previo = NULL;
	Nodo *siguiente;
	lista reversed = NULL;
	
	while (nodoNuevo != NULL) {
		siguiente = nodoNuevo->sig;
		nodoNuevo->sig = previo;
		previo = nodoNuevo;
		nodoNuevo = siguiente;
	}
	
	reversed = previo;
	return reversed;
}

lista slist_intercalar(lista lista1, lista lista2) {
	if (lista1 == NULL) {
		return lista2;
	}
	if (lista2 == NULL) {
		return lista1;
	}
	
	Nodo *listaAUX = crear();
	Nodo *actual = lista1;
	Nodo *prev = lista2;

	while((lista1 != NULL) && (lista2 != NULL)) {
		agregar_final(listaAUX, actual->dato);
		agregar_final(listaAUX, prev->dato);
		
		actual = actual->sig;
		prev = prev->sig;
		
		if (actual != NULL) {
			agregar_final(listaAUX, actual->dato);
			actual = actual->sig;
		}
		
		if (prev != NULL) {
			agregar_final(listaAUX, prev->dato);
			prev = prev->sig;
		}
	}
	return listaAUX;
}

Nodo* slist_partir(lista lista1) {
	int longitud = slist_longitud(lista1);
	Nodo *listaAux = crear();
	Nodo* Prev = lista1;
	
	if (((longitud%2) == 0) && (lista1 != NULL)) {
		int mitad = longitud/2;
		for(int i=mitad;i<longitud;i++) {
			agregar_inicio(listaAux, Prev->dato);
			Prev = Prev->sig;
		}
	} else {
		if (((longitud%2) != 0) && (lista1 != NULL)) {
			int mitad = (longitud+1)/2;
			for(int i=mitad;i<longitud;i++) {
				agregar_inicio(listaAux, Prev->dato);
				Prev = Prev->sig;
			}
		}
	}
	return Prev->sig;
}


