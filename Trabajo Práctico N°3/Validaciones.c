#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"


int GetNumeroEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int ret;
	ret = 0;
	int bufferNumero;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s \n", mensaje);
		scanf("%d", &bufferNumero);

		while(bufferNumero > maximo || bufferNumero < minimo)
		{
			printf("%s \n", mensajeError);
			printf("%s \n", mensaje);
			scanf("%d", &bufferNumero);
		}
		*pResultado = bufferNumero;
		ret = 1;
	}

	return ret;
}

float GetNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int ret;
	ret = 0;
	float bufferNumero;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s \n", mensaje);
		scanf("%f", &bufferNumero);

		while(bufferNumero > maximo || bufferNumero < minimo)
		{
			printf("%s \n", mensajeError);
			printf("%s \n", mensaje);
			scanf("%f", &bufferNumero);
		}
		*pResultado = bufferNumero;
		ret = 1;
	}

	return ret;
}

void GetString(char* mensaje, char* datoString)
{
	fflush(stdin);
	printf("%s \n", mensaje);
	fflush(stdin);
	scanf("%[^\n]", datoString);
}
