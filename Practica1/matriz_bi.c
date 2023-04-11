#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

matrizbi* crearMB(int cantidad)
{
	matrizbi* matriz = (matrizbi*)malloc(sizeof(matrizbi));
	matriz->direccion = (int*)malloc(cantidad*sizeof(int));
	matriz->cantidad = cantidad;
	return matriz;
}

int main()
{
	
	return 0;
}

