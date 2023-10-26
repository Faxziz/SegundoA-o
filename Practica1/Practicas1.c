//
// Created by facun on 11/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// PROTOTIPOS DE FUNCION
float mediana(float *arreglo,int);
int str_len(char* str);
void string_reverse(char* str);
int string_concat(char* str1,char* str2, int max);
//----------------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------
int main() {
    float numeros[] = {1.0,2.2,2.9,3.1,3.5};

    char palabra[] = "Perro";
    char palabra2[] = "gato";
    char longPal = str_len(palabra);
    char string1[100];
    char string2[100];

    int longg = sizeof(numeros)/sizeof(numeros[0]);
    int maxx;

    float res = mediana(numeros,longg);

    string_reverse(palabra);
    printf("El resultado de la mediana de Numeros es: %.2f\n", res);
    printf("La longitud de la palabra es: %d\n", longPal);
    printf("La palabra invertida es: %s\n", palabra);

    printf("Ingresa la primer palabra:");
    scanf("%s", string1);
    printf("Ingresa la segunda palabra: ");
    scanf("%s", string2);
    printf("Cuantos caracteres del string 2 quieres concatenar: ");
    scanf("%d",&maxx);
    string_concat(string1,string2,maxx);

    int contatenados = string_concat(string1,string2,maxx);
    printf("\nLa cantidad de letras copiadas es: %d", contatenados);
    return 0;
}

//EJERCICIO 1
float mediana(float *arreglo, int longitud) {
    bubble_sort(arreglo,longitud);
    float res;
    if (longitud%2 == 1) {
        res = arreglo[longitud/2];
    } else {
        int medio = longitud / 2.0;
        res = (arreglo[medio-1] + arreglo[medio]) / 2.0;
    }
    return res;
}

//EJERCICIO 2
int str_len(char* str) {
    int cont = 0;
    for(int i=0;str[i] != '\0';i++) {
        cont++;
    }
    return cont;
}

void string_reverse(char* str) {
    int longitud = str_len(str);
    for(int i = 0;i < longitud / 2;i++) {
        char c = str[i];
        str[i] = str[longitud - i - 1];
        str[longitud - i - 1] = c;
    }
}

int string_concat(char* str1, char* str2, int max) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, copied = 0;
    for (i = 0; i < max && i < len2; i++) {
        str1[len1 + i] = str2[i];
        copied++;
    }
    str1[len1 + i] = '\0';
    return copied;
}

