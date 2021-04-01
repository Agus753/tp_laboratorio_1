/*
Trabajo Practico #1
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main(void)
{
	int unNumero;
	int otroNumero;
	int opcion;
	int suma;
	int resta;
	int division;
	int multiplicacion;
	int factorialUno;
	int factorialDos;

	setbuf(stdout, NULL);

	printf("Ingrese un numero: \n");
	scanf("%d", &unNumero);

	printf("Ingrese otro numero: \n");
	scanf("%d", &otroNumero);

	//menú
	do
	{
		printf("1. Calcular suma = %d", unNumero);
		printf(" + %d \n", otroNumero);
		printf("2. Calcular resta = %d", unNumero);
		printf(" - %d \n", otroNumero);
		printf("3. Calcular division = %d", unNumero);
		printf(" / %d \n", otroNumero);
		printf("4. Calcular multiplicación = %d", unNumero);
		printf(" * %d \n", otroNumero);
		printf("5. Calcular factorial = !%d", unNumero);
		printf(", !%d \n", otroNumero);
		printf("6. Salir \n");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				suma = CalcularSuma(unNumero, otroNumero);
				printf("El resultado de %d", unNumero);
				printf(" + %d", otroNumero);
				printf(" es: %d \n", suma);
			break;
			case 2:
				resta = CalcularResta(unNumero, otroNumero);
				printf("El resultado de %d", unNumero);
				printf(" - %d", otroNumero);
				printf(" es: %d \n", resta);
			break;
			case 3:
				division = CalcularDivision(unNumero, otroNumero);
				if(division == 0)
				{
					printf("No es posible dividir por cero \n");
				}
				else
				{
					printf("El resultado de %d", unNumero);
					printf(" / %d", otroNumero);
					printf(" es: %d \n", division);
				}
			break;
			case 4:
				multiplicacion = CalcularMultiplicacion(unNumero, otroNumero);
				printf("El resultado de %d", unNumero);
				printf(" * %d", otroNumero);
				printf(" es: %d \n", multiplicacion);
			break;
			case 5:
				factorialUno = CalcularFactorialUno(unNumero);
				printf("El factorial de %d", unNumero);
				printf(" es: %d \n", factorialUno);

				factorialDos = CalcularFactorialDos(otroNumero);
				printf("El factorial de %d", otroNumero);
				printf(" es: %d \n", factorialDos);
			break;
		}
	}
	while(opcion != 6);
	return EXIT_SUCCESS;
}
