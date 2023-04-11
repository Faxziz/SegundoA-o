#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

matrizuni* crearMU(int cantidad)
{
	matrizuni* matriz = (matrizuni*)malloc(sizeof(matrizuni));
	matriz->direccion = (int*)malloc(cantidad*sizeof(int));
	matriz->cantidad = cantidad;
	return matriz;
}

int main()
{
	
	return 0;
}

