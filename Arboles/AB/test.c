#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

static void imprimir_entero(int data) {
  printf("%d ", data);
}

int main() {
  BTree ll = btree_unir(1, btree_crear(), btree_crear());
  BTree l = btree_unir(2, ll, btree_crear());
  BTree r = btree_unir(3, btree_crear(), btree_crear());
  BTree raiz = btree_unir(4, l, r);

  BTree izq1 = btree_unir(23, btree_crear(), btree_crear());
  BTree izq2 = btree_unir(24, izq1, btree_crear());
  BTree der1 = btree_unir(23, btree_crear(), btree_crear());
  BTree der2 = btree_unir(21, der1, btree_crear());
  BTree raiz2 = btree_unir(1, izq2, der2);

  //btree_recorrer(raiz, BTREE_RECORRIDO_POST, imprimir_entero);
  //puts("");
  //btree_destruir(raiz);
  int contador = btree_iterativo(raiz2);

  int respuesta = bree_buscar(raiz2, 23);
  int respuesta2 = bree_buscar(raiz2, 2);

  printf("%d | %d", respuesta, respuesta2);
  return 0;
}
