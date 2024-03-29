#include "btree.h"
#include <assert.h>
#include <stdlib.h>

struct _BTNodo {
  int dato;
  struct _BTNodo *left;
  struct _BTNodo *right;
};

// PILAS PILAS PILAS //
typedef struct {
    BTree *datos;
    int capacidad;
    int tope;
} Pila;

Pila *crear_pila(int capacidad) {
    Pila *pila = (Pila *)malloc(sizeof(Pila));
    pila->datos = (BTree *)malloc(capacidad * sizeof(BTree));
    pila->capacidad = capacidad;
    pila->tope = -1;
    return pila;
}

void apilar(Pila *pila, BTree nodo) {
    if (pila->tope < pila->capacidad - 1) {
        pila->datos[++pila->tope] = nodo;
    }
}

BTree desapilar(Pila *pila) {
    if (pila->tope >= 0) {
        return pila->datos[pila->tope--];
    }
    return NULL;
}

// -------------------------

// COLAS COLAS COLAS
typedef struct NodoArbol{
  BTree* dato;
  struct NodoArbol* sig;
} NodoArbol;


typedef struct {
  NodoArbol* primero;
  NodoArbol* ultimo;
} ColaArbol;

ColaArbol *nuevaCola() {
  ColaArbol* nuevaCola = (ColaArbol*)malloc(sizeof(ColaArbol));
  nuevaCola->primero = NULL;
  nuevaCola->ultimo = NULL;
  return nuevaCola;
}

void encolar_arbol(ColaArbol* cola, BTree *dato) {
  NodoArbol* nuevaCola = (NodoArbol*)malloc(sizeof(NodoArbol));
  if (nuevaCola == NULL) {
    return;
  }
  nuevaCola->dato = dato;
  nuevaCola->sig = NULL;
  if (cola->primero == NULL) {
    cola->primero = nuevaCola;
    cola->ultimo = nuevaCola;
  } else {
    cola->ultimo->sig = nuevaCola;
    cola->ultimo = nuevaCola;
  }
}

void desencolar_arbol(ColaArbol* arbol) {
  if (arbol == NULL) {
    return;
  } else {
    NodoArbol* temp = arbol->ultimo;
    BTree* dato = temp->dato;
    arbol->primero = arbol->primero->sig;
    free(temp);
  }
}

void cola_destruir(ColaArbol* cola) {
  if (cola == NULL) {
    return;
  } else {
  while (cola->primero != NULL) {
      NodoArbol* temp = cola->primero;
      cola->primero = cola->primero->sig;
      free(temp);
    }
  }
}
// -------------------------
/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear() { return NULL; }

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo) { return nodo == NULL; }

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right) {
  BTree nuevoNodo = malloc(sizeof(struct _BTNodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->dato = dato;
  nuevoNodo->left = left;
  nuevoNodo->right = right;
  return nuevoNodo;
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitante visit) {
  /** COMPLETAR */ 
  if (arbol != NULL) {
    if (orden == BTREE_RECORRIDO_IN) {
      btree_recorrer(arbol->left,orden,visit);
      visit(arbol->dato);
      btree_recorrer(arbol->right,orden,visit);
    } else if (orden == BTREE_RECORRIDO_PRE) {
      visit(arbol->dato);
      btree_recorrer(arbol->left,orden,visit);
      btree_recorrer(arbol->right,orden,visit);
    } else if (orden == BTREE_RECORRIDO_POST) {
      btree_recorrer(arbol->left,orden,visit);
      btree_recorrer(arbol->right,orden,visit);
      visit(arbol->dato);
    }
  }
}

int contar(void* dato) {
  int cont = 0;
  if (dato != NULL) {
    cont++;
  }
  return cont;
}

int btree_iterativo(BTree arbol) {
  int cont = 0;
  if (arbol == NULL) {
    return cont;
  } else {
    cont++;
  }
  Pila *nuevaPila = crear_pila(100);
  apilar(nuevaPila,arbol);

  while (nuevaPila->tope >= 0) {
    BTree temp = desapilar(nuevaPila);
    if (temp->right != NULL) {
      cont++;
      apilar(nuevaPila, temp->right);
    }
    if (temp->left != NULL) {
      cont++;
      apilar(nuevaPila, temp->left);
    }
  }
  free(nuevaPila->datos);
  free(nuevaPila);
  return cont;
}

int validar(int dato, int dato2) {
  return (dato == dato2) ? 1 : 0;
}

int bree_buscar(BTree arbol, int dato) {
  int res = 0;
  if (arbol->dato == dato) {
    res = 1;
  }
  Pila* pila = crear_pila(100);
  apilar(pila,arbol);
  while (pila->tope >= 0) {
    BTree temp = desapilar(pila);
    if(temp->right != NULL) {
      if (temp->right->dato == dato) {
        res = 1;
      }
      apilar(pila, temp->right);
    }
    if (temp->left != NULL) {
      if (temp->left->dato == dato) {
        res = 1;
      }
      apilar(pila, temp->left);
    }
  }
  free(pila->datos);
  free(pila);
  return res;
}

BTree btree_copiar(BTree arbol) {
  BTree copia = btree_crear();
  if (arbol == NULL) {
    return NULL;
  } else {
    Pila* pila = crear_pila(100);
    apilar(pila, arbol);
    while (pila->tope >= 0) {
      BTree temp = desapilar(pila);
      if (temp->right != NULL) {
        temp->right = copia->right;
        apilar(pila, temp->right);
      }
      if (temp->left != NULL) {
        temp->left = copia->left;
        apilar(pila, temp->left);
      }
    }
    arbol = copia;
    free(pila->datos);
    free(pila);
  }
  return copia;
}

int max(int a,int b) {
  return (a > b) ? a : b;
}

int btree_altura(BTree arbol) {
  if (arbol == NULL) {
    return 0;
  }
  int altura_izq = btree_altura(arbol->left);
  int altura_der = btree_altura(arbol->right);
  return 1+max(altura_der,altura_izq);
}

int contarNodos(BTree arbol) {
  if (arbol == NULL) {
    return 0;
  } else {
    return 1+contarNodos(arbol->right) + contarNodos(arbol->left);
  }
}

int btree_nnodos_profundidad(BTree arbol, int p) {
  int contador = 0;
  if (p == 0) {
    return 1;
  }
  int nodosizq = btree_nnodos_profundidad(arbol->left, p-1);
  int nodosder = btree_nnodos_profundidad(arbol->right, p-1);
  return nodosizq+nodosder;
  return contador;
}

int encontrarProfundidad(BTree arbol, int d, int p) {
  if (arbol == NULL) {
    return -1;
  }
  if (arbol->dato == d) {
    return p;
  }
  int pIZQ = encontrarProfundidad(arbol->left, d, p);
  int pDER = encontrarProfundidad(arbol->right, d, p);
  if (pIZQ != -1) {
    return pIZQ;
  }
  return pDER;
}

int btree_profundidad(BTree arbol, int d) {
  return encontrarProfundidad(arbol, d, 0);
}

int btree_nodos(BTree arbol) {
  if (arbol == NULL) {
    return 0;
  }
  return arbol->dato+btree_nodos(arbol->right)+btree_nodos(arbol->left);
}

void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido o, FuncionVisitanteExtra v, void *e) {
  if (arbol != NULL) {
    if (o == BTREE_RECORRIDO_IN) {
      btree_recorrer_extra(arbol->left, o,v, e);
      v(arbol->dato, e);
      btree_recorrer_extra(arbol->right,o,v,e);
    } else if (o == BTREE_RECORRIDO_PRE) {
      v(arbol->dato,e);
      btree_recorrer_extra(arbol->left, o,v,e);
      btree_recorrer_extra(arbol->right,o,v,e);
    } else if (o == BTREE_RECORRIDO_POST) {
      btree_recorrer_extra(arbol->left,o,v,e);
      btree_recorrer_extra(arbol->right,o,v,e);
      v(arbol->dato,e);
    }
  }
}

void btree_recorrer_bfs(BTree arbol, FuncionVisitante v) {
  if (arbol == NULL) {
    return;
  }
  v(arbol->dato);
  if (arbol->left != NULL) {
    v(arbol->left->dato);
  }
  if (arbol->right != NULL) {
    v(arbol->right->dato);
  }
  if (arbol->left != NULL) {
    btree_recorrer_bfs(arbol->left,v);
  }
  if (arbol->right != NULL) {
    btree_recorrer_bfs(arbol->right,v);
  }
}


