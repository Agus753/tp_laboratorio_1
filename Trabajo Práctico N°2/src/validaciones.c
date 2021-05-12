#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int GetNumeroEntero(char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int numero;
	printf("%s \n", mensaje);
	scanf("%d", &numero);

	if(numero > maximo || numero < minimo)
	{
		printf("%s \n", mensajeError);
		printf("%s \n", mensaje);
		scanf("%d", &numero);
	}
	return numero;
}

float GetNumeroFlotante(char mensaje[], char mensajeError[], int minimo, int maximo)
{
	float numero;
	printf("%s \n", mensaje);
	scanf("%f", &numero);

	if(numero > maximo || numero < minimo)
	{
		printf("%s \n", mensajeError);
		printf("%s \n", mensaje);
		scanf("%f", &numero);
	}
	return numero;
}

void GetString(char mensaje[], char datoString[])
{
	fflush(stdin);
	printf("%s \n", mensaje);
	fflush(stdin);
	scanf("%[^\n]", datoString);
}

