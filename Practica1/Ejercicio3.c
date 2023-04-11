#include <stdio.h>
#include <stdlib.h>

int CONTADOR = 0;

typedef struct {
	int* direccion;
	int capacidad;
} ArregloEnteros;

ArregloEnteros* arreglo_enteros_crear(int capacidad);
void arreglo_enteros_destruir(ArregloEnteros* arreglo);
int arreglo_entero_leer(ArregloEnteros*, int);
void arreglo_enteros_escribir(ArregloEnteros* arreglo, int, int);
int arreglo_enteros_capacidad(ArregloEnteros* arreglo);
void arreglo_enteros_imprimir(ArregloEnteros* arreglo);
void arreglo_enteros_ajustar(ArregloEnteros* arreglo,int);
void arreglo_insertar(ArregloEnteros* arreglo,int,int);
void arreglo_enteros_eliminar(ArregloEnteros* arreglo, int);
int leerContador(int);

int main()
{	
	int cant;
	
	printf("Ingrese un numero de la capacidad del arreglo: ");
	scanf("%d", &cant);
	
	ArregloEnteros* (*crear)(int);
	crear = &arreglo_enteros_crear;
	
	ArregloEnteros* arreglo1 = crear(cant);
	int valor_ingresado;
	for(int i=0;i < arreglo1->capacidad;i++) {
		printf("Ingrese el valor para la posicion %d: ", i);
		scanf("%d", &valor_ingresado);
		arreglo1->direccion[i] = valor_ingresado;
	}
	
	int booleano;
	int dato;
	int newVAL;
	printf("Quieres ingresar una posicion del arreglo para sobrescribir un dato? 1 para si | 0 para no: ");
	scanf("%d",&booleano);
	
	if (booleano == 1) {
		printf("Ingrese la posicion: ");
		scanf("%d",&dato);
		printf("Ingrese el nuevo valor: ");
		scanf("%d",&newVAL);
		arreglo_enteros_escribir(arreglo1,dato,newVAL);
		arreglo_enteros_imprimir(arreglo1);
	} else {
		printf("--------------------------------\n");
	}
	
	printf("La capacidad del arreglo es: %d\n", arreglo_enteros_capacidad(arreglo1));
	arreglo_enteros_imprimir(arreglo1);
	
	arreglo_enteros_ajustar(arreglo1, 8);
	arreglo_enteros_imprimir(arreglo1);
	
	arreglo_enteros_destruir(arreglo1);
	
	printf("Se realizaron - %d - operaciones.", leerContador(CONTADOR));
	
	return 0;
}

ArregloEnteros* arreglo_enteros_crear(int capacidad) 
{
	ArregloEnteros* arreglo = (ArregloEnteros*)malloc(sizeof(ArregloEnteros));
	if (arreglo == NULL) {
		printf("Error al asignar memoria para el arreglo.\n");
		exit(1); // sale del programa con un error
	}
	
	arreglo->direccion = (int*)malloc(capacidad*sizeof(int));
	if (arreglo->direccion == NULL) {
		printf("Error al asignar memoria para el arreglo.\n");
		exit(1); // sale del programa con un error
	}
	
	arreglo->capacidad = capacidad;
	CONTADOR++;
	return arreglo;
}

void arreglo_enteros_destruir(ArregloEnteros* arreglo) 
{
	free(arreglo);
}

int arreglo_entero_leer(ArregloEnteros* arreglo, int pos) 
{
	int i;
	int aux;
	for(i=0;i<arreglo->capacidad;i++) {
		aux = arreglo->direccion[pos];
		CONTADOR++;
	}
	return aux;
}

void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato)
{
	if (pos < 0 || pos >= arreglo->capacidad) {
		printf("Posicion ingresada fuera del rango del arreglo");
	}
	
	arreglo->direccion[pos] = dato;
	CONTADOR++;
} 


int arreglo_enteros_capacidad(ArregloEnteros* arreglo)
{
	CONTADOR++;
	return arreglo->capacidad;
}

void arreglo_enteros_imprimir(ArregloEnteros* arreglo)
{
	printf("El arreglo contiene los siguientes elementos: \n");
	for(int i=0;i < arreglo->capacidad;i++) {
		printf(" - %d", arreglo->direccion[i]);
	}
	CONTADOR++;
	printf("\n");
}

void arreglo_enteros_ajustar(ArregloEnteros* arreglo, int capacidad)
{
	arreglo->direccion = realloc(arreglo->direccion, capacidad * sizeof(int));
	
	if (arreglo->capacidad < capacidad) {
		for(int i = arreglo->capacidad; i < capacidad; i++) {
			printf("Ingrese el elemento %d: ", i + 1);
			scanf("%d", &arreglo->direccion[i]);
		}
	} else if (arreglo->capacidad > capacidad) {
		arreglo->capacidad = capacidad;
	}
			
	arreglo->capacidad = capacidad;
	CONTADOR++;
}

void arreglo_insertar(ArregloEnteros* arreglo,int pos,int dato)
{
	arreglo->capacidad = arreglo->capacidad+1;
	arreglo->direccion = realloc(arreglo->direccion, (arreglo->capacidad)*(sizeof(int)));
	
	for(int i=arreglo->capacidad;i>pos;i--) {
		arreglo->direccion[i] = arreglo->direccion[1-i];
	}
	arreglo->direccion[pos] = dato;
}

void arreglo_enteros_eliminar(ArregloEnteros* arreglo, int pos)
{
	for(int i=pos;i < arreglo->capacidad-1;i++) {
		arreglo->direccion[i] = arreglo->direccion[i+1];
	}
	
	arreglo->capacidad = arreglo->capacidad-1;
	arreglo->direccion = realloc(arreglo->direccion, (arreglo->capacidad)*(sizeof(int)));
}


int leerContador(int contador)
{
	return CONTADOR;
}
