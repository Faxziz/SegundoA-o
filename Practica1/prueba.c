#include <stdio.h>

float mediana(float *arreglo, int longitud);
void bubble_sort(float arreglo[], int longitud);


int main() {
	float arreglo[5] = {-1.0,2.2,2.9,3.1,3.5};	
	float arreglo2[4] = {1.0,-2.2,2.9,3.1};
	  
	int longitud = sizeof(arreglo) / sizeof(arreglo[0]);
	int longitud2 = sizeof(arreglo2) / sizeof(arreglo2[0]);
	
	printf("%d\n", longitud);
	
	bubble_sort(arreglo,longitud);
	printf("La mediana es: %lf\n", mediana(arreglo, longitud));
	
	bubble_sort(arreglo2,longitud2);
	printf("La mediana es: %lf\n", mediana(arreglo2, longitud2));
	return 0;
}

void bubble_sort(float arreglo[], int longitud) {
	for (int iter = 0 ; iter < longitud - 1 ; iter++) {
		for (int i = 0 ; i < longitud - iter - 1; i++) {
			if (arreglo[i] > arreglo[i + 1]) {
				float aux = arreglo[i];
				arreglo[i] = arreglo[i + 1];
				arreglo[i + 1] = aux;
				}
			}
		}
}

float mediana(float *arreglo, int longitud) {
	float resultado = 0;
	if (longitud%2 != 0) {
		resultado = arreglo[(longitud/2)];
	}
	else{
		int pos1= longitud/2 ;
		int pos2 = pos1-1;
		resultado = (float)(arreglo[pos1]+arreglo[pos2])/2.0;
	}
	
	return resultado;
}
		
