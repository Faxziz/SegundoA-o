#include <stdio.h>
#include <assert.h>
#include <math.h>

// PROP

// FIBONNACI
int fibonacci(int);
int fibonacciDP(int);
int fibonacciMemo(int,int memo[]);

// EXP
double potencia(double,int,double memo[]);
double funcionexp(double,int);

// AYL
int arrayLong(int arr[], int);

// ORDENAMIENTO - PRACTICA A2
int binsearch(int a[],int,int);
void insertion(int a[],int);
void merge(int a[],int beg,int med,int end);
// -----
int main() {
  int dato;
  return 0;
}

// FIBONACCI
int fibonacci(int dato) {
  int res;
  if (dato == 0) {
    res = 0;
  } else if (dato == 1) {
    res = 1;
  } else {
    res = fibonacci(dato - 1) + fibonacci(dato - 2);
  }
  return res;
}

int fibonacciDP(int n) {
  int fib[n+1];
  fib[0] = 0;
  fib[1] = 1;
  for(int i=2;i<=n;i++) {
    fib[i] = fib[i-1] + fib[i-2];
  }
  return fib[n];
}

int fibonacciMemo(int n,int memo[]) {
  if (n <= 1)
    return n;
  if (memo[n] != -1) {
    return memo[n];
  }
  memo[n] = fibonacciMemo(n-1,memo) + fibonacciMemo(n-2,memo);
  return memo[n];
}
// ----------------
double potencia(double b,int n,double memo[]) {
  if (n == 0) {
    return 1.0;
  }
  if (memo[n] != 0.0) {
    return memo[n];
  }
  memo[n] = b * potencia(b,n-1,memo);
  return memo[n];
}

double funcionexp(double b,int n) {
  assert(n>=0);
  double memo[n+1];

  for(int i=0;i<=n;i++) {
    memo[i] = 0.0;
  }
  return potencia(b,n,memo);
}

int arrayLong(int arr[], int longg) {
  int res = 0;
  for(int i=0;i<longg;i++) {
    if (arr[i] > arr[res]) {
      res = i;
    }
  }
  return res;
}

int binsearch(int a[], int len, int v) {
    int inicio = 0;
    int fin = len - 1;
    int res = -1;

    while (inicio <= fin) {
        int med = inicio + (fin - inicio) / 2;

        if (a[med] == v) {
            res = med;
            // Continuar buscando en la mitad izquierda
            fin = med - 1;
        } else if (a[med] < v) {
            // Buscar en la mitad derecha
            inicio = med + 1;
        } else {
            // Buscar en la mitad izquierda
            fin = med - 1;
        }
    }
    return res;
}

void insertion(int a[],int len) {
    int i, key, j;
    for(i = 1;i < len;i++) {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void merge(int a[],int beg,int med,int end) {
    int i,j,k;
    int n1 = med - beg + 1;
    int n2 = end - med;

    int leftArr[n1], rightArr[n2];
    for(int i=0;i<n1;i++) {
        leftArr[i] = a[beg+1];
    }
    for(int j=0;j<n2;j++) {
        rightArr[j] = a[med+1+j];
    }
    i=0;
    j=0;
    k=beg;

    while(i<n1 && j<n2) {
        if (leftArr[i]<=rightArr[j]) {
            a[k] = leftArr[i];
            i++;
        } else {
            a[k] = rightArr[j];
            i++;
        }
        k++;
    }
    while(i<n1) {
        a[k] = leftArr[i];
        i++;
        k++;
    }
    while(j<n2) {
        a[k] = rightArr[j];
        j++;
        k++;
    }
}