#include <stdio.h>
#include <stdlib.h>

void set_first(int valores[]);
void set_in(int *);
void swap(int *,int *);
char *get_new_line(void);
int cuadrado(int);
int apply(int (*)(int), int*);

int temp;

int main() {
	int a = 0,b = 2,c = 3;
	int v1 = 3, v2 = 5;
	// char xd = 'x';
	// char mensaje[] = "Hola muy buenos dias";
	int myArr[] = {3,2,1,5};
	int longitud = sizeof(myArr) / sizeof(myArr[0]);
	
	set_first(myArr);
	printf("La direccion de memoria de la variables enteras son: %p %p %p \n", &a, &b, &c);
	for(int i=0;i<longitud;i++) {
		printf(" %d - \n", myArr[i]);
	}
	
	set_in(&a);
	set_in(&b);
	set_in(&c);
	
	printf("Los nuevos valores para a,b,c, son: %d %d %d \n", a,b,c);
	
	printf("Los valores para V1, y V2 son: %d y %d respectivamente\n", v1, v2);	
	swap(&v1, &v2);
	printf("Los nuevos valores para V1, y V2, son: %d y %d respectivamente\n", v1, v2);
	
	char *palabra = get_new_line();
	printf("La linea ingresada es: %s", palabra);
	free(palabra);
	
	int(*ptrC)(int);
	ptrC = &cuadrado;
	printf("El valor al cuadrado por punteros es: %d", apply(*ptrC, &b));
	return 0;
}

void set_first(int valores[]) {
	for(int i=0;i<1;i++) {
		valores[i] = 0;
	}	
}

void set_in(int *valor) {
	if (*valor != 0) {
		*valor = 1;
	} else {
		*valor = 0;
	}
}

void swap(int *v1,int *v2) {
	temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

char *get_new_line(void) {
	char *palabra = NULL;
	int c, i=0;
	
	while((c = getchar()) != '\n' && c != EOF) {
		palabra = realloc(palabra, (i+1) * sizeof(char));
		if (palabra = NULL) {
			printf("Error al asignar memoria \n");
			exit(EXIT_FAILURE);
		}
		palabra[i++] = '\0';
	}
	return palabra;
}


int cuadrado(int v1) {
	int resultado = v1*v1;
	return resultado;
}

int apply(int (*ptrC)(int), int *valor) {
	return ptrC(*valor);
}
