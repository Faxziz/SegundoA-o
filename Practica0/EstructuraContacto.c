#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contacto {
	int edad;
	char tel[15];
	char nombre[20];
} cont;

typedef struct Agenda {
	int cantidad;
	cont** contactos;
	int max_cantidad;
} Agenda;

cont crear_contacto(cont *m);
void actualizar_edad(cont *);
void alta_contacto(Agenda *);
void modificar_edad(Agenda *);

int main()
{
	cont m;
	crear_contacto(&m);
	return 0;
}

cont crear_contacto(cont *m) {
	printf("Ingrese su nombre: ");
	scanf("%s", m->nombre);
	printf("Ingrese su numero de telefono entre '': ");
	scanf("%s", m->tel);
	printf("Ingrese su edad: ");
	scanf("%d", &m->edad);
	
	return *m;
}

void actualizar_edad(cont *m) {
	printf("Ingrese una nueva edad por favor: ");
	scanf("%d", &m->edad);
}

void alta_contacto(Agenda *a) {
	int f;
	printf("Cuantos contactos va a agregar a su agenda? ");
	scanf("%d", &f);
	
	for(int i=0;i < f;i++) {
		cont* nuevo_contacto = malloc(sizeof(cont));
		a->contactos[a->cantidad] = nuevo_contacto;
		a->cantidad++;
	}
}

void modificar_edad(Agenda *a) {
	char nomb[50];
	printf("Ingrese el nombre que quiere buscar: ");
	scanf("%s", nomb);
	
	for (int i = 0; i < a->cantidad; i++) {
        if (strcmp(a->contactos[i]->nombre, nomb) == 0) {
            cont* m = a->contactos[i];
            actualizar_edad(m);
            break;
        }
    }
}
