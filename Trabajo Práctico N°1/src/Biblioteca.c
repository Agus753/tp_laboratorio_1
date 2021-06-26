/*
 * Biblioteca.c
 *
 *  Created on: 28 mar. 2021
 *      Author: Windows 7
 */
#include "Biblioteca.h"

int CalcularSuma(int numeroUno, int numeroDos)
{
	int suma;

	suma = numeroUno + numeroDos;

	return suma;
}

int CalcularResta(int numeroUno, int numeroDos)
{
	int resta;

	resta = numeroUno - numeroDos;

	return resta;
}

int CalcularDivision(int numeroUno, int numeroDos)
{
	int resultado;
	if(numeroUno == 0 || numeroDos == 0)
	{
		resultado = 0;
	}
	else
	{
		resultado = numeroUno / numeroDos;
	}

	return resultado;
}

int CalcularMultiplicacion(int numeroUno, int numeroDos)
{
	int producto;

	producto = numeroUno * numeroDos;

	return producto;
}

int CalcularFactorialUno(int numeroUno)
{
	int vueltas;
	int factorial;

	factorial = 1;

	for(vueltas = numeroUno; vueltas > 0; vueltas--)
	{
		factorial = factorial * vueltas;
	}

	return factorial;
}

int CalcularFactorialDos(int numeroDos)
{
	int vueltas;
	int factorial;

	factorial = 1;

	for(vueltas = numeroDos; vueltas > 0; vueltas--)
	{
		factorial = factorial * vueltas;
	}

	return factorial;
}


