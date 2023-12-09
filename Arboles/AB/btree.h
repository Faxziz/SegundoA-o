#ifndef __BTREE_H__
#define __BTREE_H__

typedef void (*FuncionVisitante)(int dato);

typedef enum {
  BTREE_RECORRIDO_IN,
  BTREE_RECORRIDO_PRE,
  BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

typedef struct _BTNodo *BTree;

typedef void (*FuncionVisitanteExtra) (int dato, void *extra);

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear();

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo);

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo);

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right);

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitante visit);

/*
 * btree_recorrer iterativo
 */
int btree_iterativo(BTree arbol);

/* 
 * retorna el numero de nodos
 */
void btree_nnodos(BTree arbol);

/*
 * btree_buscar retorna 1 si el dato esta en el arbol
 */
int bree_buscar(BTree arbol, int);

/*
 * btree_copiar retorna una copia del arbol dado
 */
BTree btree_copiar(BTree arbol);

/*
 * btree_altura retorna la altura del arbol
 */
int btree_altura(BTree arbol);

/*
 * btree_nnodos_profundidad retorna el numero de nodos a n btree_nnodos_profundidad
 */
int contarNodos(BTree arbol);
int btree_nnodos_profundidad(BTree arbol, int);

/*
 * retorna el numero de nodo del numero dado
 */
int encontrarProfundidad(BTree arbol,int d, int p);
int btree_profundidad(BTree abol, int);

/*
 * btree_sumar retorne la suma de nodos
 */
int btree_nodos(BTree arbol);

/*
 * recorre el arbol y aplica la funcion 
 */
void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden,
FuncionVisitanteExtra visit, void *extra);

/*
 * busqueda por extension
 */
void btree_recorrer_bfs(BTree arbol, FuncionVisitante visit);
#endif /* __BTREE_H__ */
