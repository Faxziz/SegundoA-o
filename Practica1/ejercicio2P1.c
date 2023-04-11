#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int string_len(char*);
void string_reverse(char*);
int string_concat(char*, char*, int);
int string_compare(char*, char*);
int string_subcadena(char *,char *);
void string_unir(char* arregloStrings[],int n,char* sep,char* res);

int main()
{
	char palabra[] = "Hola Mundo";
	char str1[]="chau";
	char str2[]="hola";
	char sep[10];
	int n;
	printf("Cuantas palabras del arreglo quiere unir? ");
	scanf("%d", &n);
	char* arregloStrings[n];
	for (int i=0;i<n;i++) {
		arregloStrings[i] = (char*)malloc(sizeof(char)*50);
		printf("Ingrese una palabra: \n");
		scanf("%s", arregloStrings[i]);
	}
	
	printf("La cantidad de caracteres es: %d\n", string_len(palabra));
	string_reverse(palabra);
	printf("%s\n", palabra);
	string_concat(str1,str2,3);
	printf ("%s\n",str1);
	
	printf("Que separador quiere para unir las cadenas?");
	scanf("%s", sep);
	char res[50] ="";
	string_unir(arregloStrings,n,sep,res);
	printf("%s\n", res);
	for(int i=0;i<n;i++) {
		free(arregloStrings[i]);
	}

	
	return 0;
}

int string_len(char* str) {
	int i=0;
	int contador = 0;
	
	while (str[i] != '\0') {
		if (str[i] != ' ') {
		++contador;
	}
		i++;
	}
	return contador;
}

void swap(char* a, char* b) {
	// intercambia el valor de *a con el valor de *b
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void string_reverse(char* str) {
	int longg = strlen(str);
	
	for(int i=0;i<longg/2;i++) {
			char *b= &str[i];
			char *a=&str[longg-1-i];
			swap (a,b);
			
	}	
}

/*
 * 	int longg = strlen(str);
	char aux[longg];
	
	for(int i=0;i<longg;i++) {
		aux[longg-1-i] = str[i];
	}
	
	for(int i=0;i<longg;i++) {
		str[i] = aux[i];
	} */


int string_concat(char* str1, char* str2, int max) {
	/* que concatene no m ́as de max caracteres de la cadena str2 al final de la cadena str1. El caŕacter inicial de str2 debe sobrescribir
	 * el caracter nulo de str1. La cadena resultante debe terminar con un car ́acter nulo. Retorna el numero de caracteres copiados. */
	 
	 int longg = strlen(str1);

	 
	 for (int i=0; i<max; ++i){
		 str1[longg+i]=str2[i];
		 printf("%c\n",str2[i]);
		 printf(" --- %c\n",str1[longg+i]);
		
		 
	 }
	 str1[longg+max]='\0';
	 
	 return max;
}	

int string_compare(char* str1, char* str2) {
	int resultado;
	
	if (strcmp(str1,str2) == 1) {
		resultado = 0;
	} else {
		resultado = 0;
	}
	
	int longg1 = strlen(str1);
	int longg2 = strlen(str2);
	
	for(int i=0;i<longg1;i++) {
		for(int j=0;i<longg2;i++) {
			if (str1[i]<str2[j]) {
				resultado = -1;
			} else {
				if (str1[i]>str2[j]) {
					resultado = 1;
				}
			}
		}
	}
	return resultado;
}


/*  string_subcadena(char *str1,char *str2) {
	int longg1 = strlen(str1);
	int longg2 = strlen(str2);
	char alm = '';
	int band;
	int i,j;
	char band = 'V';
	
	while (band != 'F') {
		if (str1[i] == str2[j]) {
			band = 1;
		}
		i++; j++;
	}
} */

void string_unir(char* arregloStrings[], int n, char* sep,char* res) {;
	for(int i=0;i<n;i++) {
		strcat(res,arregloStrings[i]);
		if(i<n-1) {
			strcat(res,sep);
		}
	}
}
