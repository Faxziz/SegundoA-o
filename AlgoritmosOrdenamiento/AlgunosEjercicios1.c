#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// - PROTOTIPOS -
int binsearch(int a[], int len, int v);
void insercion(int a[],int len, int v);
void merge(int arr[],int left[],int n_left,int right[],int n_right);
void mergeSort(int arr[], int n);
void quicksort(int arr[], int n);
int particionar(int a[], int n, int p);
int mediana(int a[],int n);
int kesimoMed(int a[], int n, int pos);
void kprimerosMed(int a[], int n, int k);

// --------------------------------

// - FUNCIONES -
int binsearch(int a[], int len, int v)
{
	int izq = 0;
	int der = len-1;
	
	while (izq <= der) {
		int mitad = round((izq+der)/2);
		int valorMedio = a[mitad];
		if (v == valorMedio) {
			return mitad;
		}
		
		if (v < valorMedio) {
			der = mitad-1;
		} else {
			izq = mitad+1;
		}
	}
	return -1;
}

void insercion(int a[], int len, int v)
{
	int i,pos,aux;
	for (i=0;i<len;i++) {
		pos = i;
		aux = a[i];
		
		while ((pos > 0) && (a[pos-1] > aux)) 
		{
			a[pos] = a[pos-1];
			pos--;
		}
		a[pos] = aux;
	}
}

void merge(int arr[], int izq[], int n_izq, int der[], int n_der) {
    int i = 0, j = 0, k = 0;
    
    while (i < n_izq && j < n_der) {
        if (izq[i] <= der[j]) {
            arr[k] = izq[i];
            i++;
        } else {
            arr[k] = der[j];
            j++;
        }
        k++;
    }

    while (i < n_izq) {
        arr[k] = izq[i];
        i++;
        k++;
    }

    while (j < n_der) {
        arr[k] = der[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int n) {
    if (n < 2) {
        return;
    }

    int mid = n / 2;
    int *izq = (int*)malloc(mid * sizeof(int));
    int *der = (int*)malloc((n - mid) * sizeof(int));
    
    for (int i = 0; i < mid; i++) {
        izq[i] = arr[i];
    }

    for (int i = mid; i < n; i++) {
        der[i - mid] = arr[i];
    }

    mergeSort(izq, mid);
    mergeSort(der, n - mid);
    merge(arr, izq, mid, der, n - mid);

    free(izq);
    free(der);
}

int particionar(int a[], int n, int p)
{
	int j = -1;
	int temp;
	for(int i=0;i<n;i++) {
		if (a[i] <= p) {
			j++;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	return j;
}

void quicksort(int arr[],int n) 
{
	int temp;
	if (n<2) return;
	int p = arr[n/2];
	int nizq = 1+ particionar(arr, n, p);
	
	temp = arr[nizq];
	arr[nizq] = arr[n-1];
	arr[n-1] = temp;
	
	quicksort(arr, nizq);
	quicksort(arr + nizq + 1,n - nizq -1);
}

int mediana(int a[], int n) 
{
	int posMedio;
	int izq = 0;
	int der = n-1;
	
	quicksort(a, n);
	
	if ((n%2) != 0) {
		posMedio = floor((izq+der)/2);
	} else {
		posMedio = n/2;
	}
	
	return a[posMedio];
}

int kesimoMed(int a[], int n, int pos) 
{
	int i = 0, res;
	
	mergeSort(a,n);
	
	for(;i<=pos;i++) 
	{
		if (i == pos) res = a[i];
	}
	
	return res;
}

void kprimerosMed(int a[], int n, int k)
{
	// k representa hasta que numero hay que buscar
	int i=0;
	int aux[k];
	
	mergeSort(a,n);
	
	while (i != k+1) 
	{
		aux[i] = a[i];
		i++;
	}
	
	int longg = sizeof(aux)/sizeof(aux[0]);
	
	for(int i=0;i<longg;i++) 
	{
		printf("\n %d - ", aux[i]);
	}
}

// --------------------------------

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	int valorABuscar;
	scanf("%d", &valorABuscar);
	int resultado = binsearch(a,len,valorABuscar);
	
	printf("%d", resultado);
	
	return 0;
}

