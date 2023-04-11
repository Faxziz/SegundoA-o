#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct 
{
	int *direccion;
	int cantidad;
} matrizbi;

typedef struct
{
	int *direccion;
	int cantidad;
} matrizuni;


matrizbi* crearMB(int);
matrizuni* crearMU(int);
void destruirMB(matrizbi* matriz);
void destruirMU(matrizuni* matriz);

#endif 
