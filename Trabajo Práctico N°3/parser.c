#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"


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

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

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

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret;
	ret = 0;
	Employee* empleado;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{

			empleado = employee_new();

			fread(empleado, sizeof(Employee), 1, pFile);
			if(feof(pFile))
			{
				break;
			}

			if(empleado != NULL)
			{
				ll_add(pArrayListEmployee, empleado);
			}


			ret = 1;
		}
		fclose(pFile);
	}
	printf("%d", ll_len(pArrayListEmployee));
    return ret;
}
