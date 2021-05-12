#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "validaciones.h"

typedef struct
{
	int idEmpleado;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;
}eEmpleado;

void InitEmployee(eEmpleado listadoEmpleados[], int tam);
/*
 *\brief Inicializa el listado de empleados para saber si los vectores están vacíos u ocupados
 *
 *\param eTrabajo Listado de empleados para inicializar
 *\param int tamaño del listado de empleados
 */
int BuscarLibre(eEmpleado listadoEmpleados[], int tam);
/*
 *\brief Busca un espacio libre para dar de alta un nuevo empleado
 *
 *\param eEmpleado Listado de empleados para buscar el espacio libre
 *\param int tamaño del listado de empleados
 *\return Devuelve el índice del espacio libre
 */
int CargarDatos(eEmpleado listadoEmpleados[], int tam);
/*
 *\brief Inicializa el listado de empleados para saber si los vectores están vacíos u ocupados
 *
 *\param eEmpleado Listado de empleados para inicializar
 *\param int tamaño del listado de empleados
 *\return Devuelve el índice del espacio libre para cargar los datos
 */
int idAutoincremental(eEmpleado listadoEmpleados[], int tam);
/*
 * \brief Da un id automático al usuario por medio de un incremento
 *
 *\param eEmpleado listado de empleados para calcular a cuales debe darle un id
 *\param int tamaño del listado empleados
 *\return Retorna un valor de id
 */

eEmpleado AddEmployees(eEmpleado listadoEmpleados[], int tam);
/*
 *\brief Carga los datos del nuevo empleado
 *
 *\param eEmpleado listado de empleados para usar la función de idAutoincremental
 *\param int tamaño del array
 *\return Guarda los datos del nuevo trabajo
 */
int FindEmployeeById(eEmpleado listadoEmpleados[], int tam);
/*
 *\brief Obtiene el id de un empleado ya existente
 *
 *\param eEmpleado Listado de empleados para buscar el id
 *\param int tamaño del listado de empleados
 *\return Devuelve el índice del array en donde se halla el id
 */
void RemoveEmployee(eEmpleado listadoEmpleados[], int tamEmp);
/*
 *\brief Elimina el trabajo por id
 *
 *\param eEmpleado Listado de empleados para buscar y eliminar el elegido
 *\param int tamaño del listado de empleados
 */
void ModificarPorId(eEmpleado listadoEmpleados[], int tam);
/*
 *\brief Modificar nombre, apellido, salario o sector
 *
 *\param eEmpleado Listado de trabajos para buscar por id y modificar
 *\param int tamaño del listado de trabajos
 */
void PrintEmployees(eEmpleado listadoEmpleados[], int tam);
/*
 *\brief Muestra un listado con todos los empleados dados de alta
 *
 *\param eEmpleado Listado de empleados para mostrar todos los que están ocupados
 *\param int tamaño del listado de empleados
 */
void MostrarUnEmpleadoCompleto(eEmpleado empleadoParametro);
/*
 *\brief Muestra un solo trabajo del array
 *
 *\param eEmpleado Para imprimir en pantalla los valores guardados en la estructura de empleados
 */
void SortEmployeesByName(eEmpleado listadoEmpleados[], int tam);
/*
 *\brief Ordena el listado de empleados por nombre
 *
 *\param eEmpleado El listado de empleados para ordenar por el nombre
 *\param int tamaño del listado de empleados
 */
void SortEmployeesBySector(eEmpleado listadoEmpleados[], int tam);
/*
 *\brief Ordena el listado de empleados por sector
 *
 *\param eEmpleado El listado de empleados para ordenar por el sector
 *\param int tamaño del listado de empleados
 */
float AcumuladorSalario(eEmpleado listadoEmpleados[], int tam);
/*
 *\brief acumula el campo salario de los empleados dados de alta
 *
 *\param eEmpleado El listado de empleados para conseguir el valor del salario
 *\param int tamaño del listado de empleados
 */
float CalcularPromedioDelSalario(eEmpleado listadoEmpleados[], int tam);
/*
 *\brief Saca el promedio de los salarios de todos los empleados
 *
 *\param eEmpleado El listado de empleados para contar la cantidad de empleados y dividir la variable acumulador por esa cantidad
 *\param int tamaño del listado de empleados
 */
void MostrarAcumulador(eEmpleado listadoEmpleados[], int tam);
/*
 *\brief Muestra el resultado de la acumulación de todos los salarios
 *
 *\param eEmpleado El listado de empleados
 *\param int tamaño del listado de empleados
 */
void MostrarPromedio(eEmpleado listadoEmpleados[], int tam);
/*
 *\brief Muestra el resultado de la el promedio de los salarios
 *
 *\param eEmpleado El listado de empleados
 *\param int tamaño del listado de empleados
 */
void CalcularMayorAPromedio(eEmpleado listadoEmpleados[], int tam);
/*
 *\brief Muestra el los empleados con un salario mayor al promedio
 *
 *\param eEmpleado El listado de empleados para calcular si su salario es mayor al promedio
 *\param int tamaño del listado de empleados
 */
#endif /* ARRAYEMPLOYEES_H_ */
