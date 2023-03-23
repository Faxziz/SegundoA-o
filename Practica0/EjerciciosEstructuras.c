#include <stdio.h>

typedef struct puntosP {	
	double x;
	double y;
} Punto;

void puntoMedio(Punto *,Punto *, Punto *);
void cargar();

int main()
{
	Punto p1,p2;
	cargar(&p1);
	cargar(&p2);
	Punto resultado;
	puntoMedio(&p1,&p2,&resultado);
	
	printf("El punto medio entre el punto 1 y 2 es: (%lf, %lf)\n", resultado.x,resultado.y); 
	return 0;
}

void cargar(struct puntosP *p1) {
	printf("Ingrese una coordenada x:");
	scanf("%lf", &p1->x);
	printf("Ingrese una coordenada y:");
	scanf("%lf", &p1->y);
}

void puntoMedio(Punto *p1,Punto *p2, Punto *resultado) {
	resultado->x = (p1->x + p2->x)/2;
	resultado->y = (p1->y + p2->y)/2;
} 

