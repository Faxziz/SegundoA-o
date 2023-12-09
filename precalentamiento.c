#include <stdio.h>
#include <assert.h>

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

// -----
int main() {
  int dato;
  scanf("%d", &dato);
  printf("%f", funcionexp(5.0, 2.0));
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
