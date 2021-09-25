#include "Funciones.h"
#include <stdio.h>
float IngresarFlotante(char mensaje[])
{
	float numeroIngresado;
	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);

	return numeroIngresado;
}
