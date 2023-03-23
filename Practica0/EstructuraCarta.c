#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Carta {
    int palo;
    int numero;
} carta;

typedef int (*mazo)[48];

void llenar(mazo m);
int azar(int arr[]);

int main()
{
    int m[48];
    mazo ptr = &m;
    llenar(ptr);
    return 0;
}

void llenar(mazo m) {
    srand(time(NULL));
    for(int i=0;i<48;i++) {
        carta c;
        for(int j=0;j<4;j++) {
            c.palo = j + 1;
            for(int k=0;k<13;k++){
                c.numero = k + 1;
                int n = azar(m[c.palo - 1]);
                m[c.palo - 1][n] = c.numero;
            }
        }
    }
}

int azar(int arr[]) {
    int n;
    do {
        n = rand() % 13;
    } while (arr[n] != 0);
    arr[n] = 1;
    return n;
}
