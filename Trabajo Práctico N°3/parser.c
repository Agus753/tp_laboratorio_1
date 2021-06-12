#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret;
	ret = 0;
	Employee* lectura;
	lectura = NULL;
	char id[50];
	char nombre[50];
	char horasTrabajadas[50];
	char sueldo[50];

	ll_clear(pArrayListEmployee);
	//pFile = fopen("data.csv", "r");

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
		//printf("%s -- %s -- %s -- %s\n", id, nombre, horasTrabajadas, sueldo);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
			lectura = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

			ll_add(pArrayListEmployee, lectura);
			ret = 1;
		}
		fclose(pFile);
		ret = 1;
	}
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret;
	ret = 0;
	Employee* empleado;
	int id;
	char nombre[40];
	int sueldo;
	int hrsTrabajadas;

	//pFile = fopen("data.bin", "rb");

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			empleado = employee_new();
			fread(empleado, sizeof(Employee*), 1, pFile);

			employee_getId(empleado, &id);
			employee_getNombre(empleado, nombre);
			employee_getHorasTrabajadas(empleado, &hrsTrabajadas);
			employee_getSueldo(empleado, &sueldo);

			if(id != 0 && sueldo != 0 && hrsTrabajadas != 0 && nombre != NULL)
			{
				ll_add(pArrayListEmployee, empleado);
			}

			printf("%d,%s,%d,%d\n",empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);

			ret = 1;
		}
		fclose(pFile);
	}
    return ret;
}
