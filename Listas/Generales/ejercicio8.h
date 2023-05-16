#ifndef EJERCICIO8
#define EJERCICIO8_H

typedef struct _GNODE {
	void* dato;
	struct _GNODE *next;
} GList;

// - TIPOS - 
typedef GList *SGList;
typedef void (*FuncionDestructora)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef int (*FuncionComparadora)(void *, void*);
typedef void (*FuncionVisitante)(void *dato);

#define TRUE 1
#define FALSE 0

// - PROTOTIPOS -
void destructura(SGList lista1);
SGList sglist_crear();
void sglist_destruir(SGList lista1, FuncionDestructora p);
int sglist_vacia(SGList);
void sglist_recorrer(SGList lista1, FuncionVisitante p);
SGList sglist_insertar(SGList, void *, FuncionCopia, FuncionComparadora) ;
#endif
