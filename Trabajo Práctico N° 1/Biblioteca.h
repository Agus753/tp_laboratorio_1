/*
 * Biblioteca.h
 *
 *  Created on: 28 mar. 2021
 *      Author: Windows 7
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/**
 * \brief Calcula la suma de dos numeros enteros ingresados por el usuario
 *
 * \param int primer valor entero para realizar la suma
 * \param int segundo valor entero ingresado para realizar la suma
 * \return el resultado de la suma
 */
int CalcularSuma(int numeroUno, int numeroDos);

/**
 * \brief Calcula la resta de dos numeros enteros ingresados por el usuario
 *
 * \param int primer valor entero para realizar la resta
 * \param int segundo valor entero ingresado para realizar la resta
 * \return el resultado de la resta
 */
int CalcularResta(int numeroUno, int numeroDos);

/**
 * \brief Calcula la division de dos numeros enteros ingresados por el usuario
 *
 * \param int primer valor entero para realizar la division
 * \param int segundo valor entero ingresado para realizar la division
 * \return el resultado de la division
 */
int CalcularDivision(int numeroUno, int numeroDos);

/**
 * \brief Calcula la multiplicacion de dos numeros enteros ingresados por el usuario
 *
 * \param int primer valor entero para realizar la multiplicacion
 * \param int segundo valor entero ingresado para realizar la multiplicacion
 * \return el producto de la multiplicacion
 */
int CalcularMultiplicacion(int numeroUno, int numeroDos);

/**
 * \brief Calcula el factorial del primer numero ingresado por el usuario
 *
 * \param int primer valor entero para calcular el factorial
 * \return el factorial del primer numero
 */
int CalcularFactorialUno(int numeroUno);

/**
 * \brief Calcula el factorial del segundo numero ingresado por el usuario
 *
 * \param int segundo valor entero para calcular el factorial
 * \return el factorial del segudo numero
 */
int CalcularFactorialDos(int numeroDos);

#endif /* BIBLIOTECA_H_ */
