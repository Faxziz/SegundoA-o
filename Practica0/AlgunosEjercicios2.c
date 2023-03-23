#include <stdio.h>
#include <stdlib.h>

void apply_in(void (*)(int *), int*);
void cambioSigno(int *);

int main()
{
	int a = 0, b = 1;
	void(*ptrFunc)(int *);
	ptrFunc = &cambioSigno;
	apply_in(ptrFunc, &a);
	printf("El nuevo valor de a es: %d\n", a);
	apply_in(ptrFunc, &b);
	printf("El nuevo valor de B es: %d\n", b);
	
	return 0;
}

void cambioSigno(int *v1){
	if (*v1 != 0) {
		*v1 = 1;
	}else {
		*v1 = 0;
	}
}

void apply_in(void (*ptrFunc)(int *), int *v1) {
	ptrFunc(v1);
}
