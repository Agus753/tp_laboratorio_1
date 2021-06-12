#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
/*
 * \brief crea un empleado nuevo
 * \return retorna el empleado creado.
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
/*
 * \brief recibe parametros string, los parsea y se los asigna al nuevo empleado
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 *
 * \return retorna el empleado con los datos parseados.
 */
void employee_delete();

int employee_setId(Employee* listadoEmpleados,int id);
/*
 * \brief setea un id a un empleado
 *
 * \param listadoEmpleados Employee*
 * \param id int
 *
 * \return retorna el empleado con el id seteado
 */
int employee_getId(Employee* listadoEmpleados,int* id);
/*
 * \brief obtiene el id de un empleado
 *
 * \param listadoEmpleados Employee*
 * \param id int*
 *
 * \return retorna el id del empleado
 */

int employee_setNombre(Employee* listadoEmpleados,char* nombre);
/*
 * \brief setea un nombre a un empleado
 *
 * \param listadoEmpleados Employee*
 * \param nombre char*
 *
 * \return retorna el empleado con el nombre seteado
 */
int employee_getNombre(Employee* listadoEmpleados,char* nombre);
/*
 * \brief obtiene el nombre de un empleado
 *
 * \param listadoEmpleados Employee*
 * \param nombre char*
 *
 * \return retorna el nombre del empleado
 */

int employee_setHorasTrabajadas(Employee* listadoEmpleados,int horasTrabajadas);
/*
 * \brief setea las horas trabajadas a un empleado
 *
 * \param listadoEmpleados Employee*
 * \param id horasTrabajadas
 *
 * \return retorna el empleado con las horas seteadas
 */
int employee_getHorasTrabajadas(Employee* listadoEmpleados,int* horasTrabajadas);
/*
 * \brief obtiene las horas trabajadas de un empleado
 *
 * \param listadoEmpleados Employee*
 * \param horas trabajadas int*
 *
 * \return retorna el id del empleado
 */

int employee_setSueldo(Employee* listadoEmpleados,int sueldo);
/*
 * \brief setea un sueldo a un empleado
 *
 * \param listadoEmpleados Employee*
 * \param sueldo int
 *
 * \return retorna el empleado con el sueldo seteado
 */
int employee_getSueldo(Employee* listadoEmpleados,int* sueldo);
/*
 * \brief obtiene el sueldo de un empleado
 *
 * \param listadoEmpleados Employee*
 * \param sueldo int*
 *
 * \return retorna el sueldo del empleado
 */

int OrdenarPorNombre(void* empleadoA, void* empleadoB);
/*
 * \brief ordena por nombre (alfabeticamente)
 *
 * \param empleadoA void*
 * \param empleadoB void*
 *
 * \return retorna la comparación entre dos nombres
 */
int OrdenarPorHorasTrabajadas(void* empleadoA, void* empleadoB);
/*
 * \brief ordena por horas trabajadas
 *
 * \param empleadoA void*
 * \param empleadoB void*
 *
 * \return retorna un valor dependiendo de si es mayor, menor o igual
 */
int OrdenarPorSueldo(void* empleadoA, void* empleadoB);
/*
 * \brief ordena por sueldo
 *
 * \param empleadoA void*
 * \param empleadoB void*
 *
 * \return retorna un valor dependiendo de si es mayor, menor o igual
 */
int OrdenarPorId(void* empleadoA, void* empleadoB);
/*
 * \brief ordena por id
 *
 * \param empleadoA void*
 * \param empleadoB void*
 *
 * \return retorna un valor dependiendo de si es mayor, menor o igual
 */

int autoId(LinkedList* listadoEmpleados);
/*
 * \brief calcula el tamaño de la lista de empleados mas 1
 *
 * \param listadoEmpleados LinkedList*
 *
 * \return retorna un numero para un nuevo id.
 */
void MenuInicio();
/*
 * \brief el menu de inicio para el ususario
 *
 * \return void
 */
void MenuOrdenamiento();
/*
 * \brief el menu de ordenamiento para el ususario
 *
 * \return void
 */
void MenuEdit();
/*
 * \brief el menu de modificar emplados para el ususario
 *
 * \return void
 */

#endif // employee_H_INCLUDED
