/*
 * Validaciones.h
 *
 *  Created on: 12 jun. 2021
 *      Author: Windows 7
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int GetNumeroEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);
float GetNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);
void GetString(char* mensaje, char* datoString);

#endif /* VALIDACIONES_H_ */
