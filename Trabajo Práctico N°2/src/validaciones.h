#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int GetNumeroEntero(char mensaje[], char mensajeError[], int minimo, int maximo);
/*
 *\brief Obtiene y valida un numero entero
 *
 *\param char Es un mensaje que indica qué se debe ingresar
 *\param char Es un mensaje de error que aparece cuando el valor no es válido
 *\param int el numero minimo que se puede ingresar
 *\param int el numero máximo que se puede ingresar
 *\return devuelve el numero ingresado
 */
float GetNumeroFlotante(char mensaje[], char mensajeError[], int minimo, int maximo);
/*
 *\brief Obtiene y valida un numero flotante
 *
 *\param char Es un mensaje que indica qué se debe ingresar
 *\param char Es un mensaje de error que aparece cuando el valor no es válido
 *\param int el numero minimo que se puede ingresar
 *\param int el numero máximo que se puede ingresar
 *\return devuelve el numero ingresado
 */
void GetString(char mensaje[], char datoString[]);
/*
 *\brief Obtiene un string ingresado por el usuario
 *
 *\param char Es un mensaje que indica qué se debe ingresar
 *\param char Es un mensaje de error que aparece cuando el valor no es válido
 */

#endif /* VALIDACIONES_H_ */
