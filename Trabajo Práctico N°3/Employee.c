#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "parser.h"
#include "LinkedList.h"


Employee* employee_new()
{
	Employee* listadoEmpleados;
	listadoEmpleados = (Employee*)malloc(sizeof(Employee));

	if(listadoEmpleados != NULL)
	{
		employee_setId(listadoEmpleados, 0);
		employee_setNombre(listadoEmpleados, " ");
		employee_setHorasTrabajadas(listadoEmpleados, 0);
		employee_setSueldo(listadoEmpleados, 0);
	}
	return listadoEmpleados;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* auxEmp;
	auxEmp = employee_new();

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		employee_setId(auxEmp, atoi(idStr));
		employee_setNombre(auxEmp, nombreStr);
		employee_setHorasTrabajadas(auxEmp, atoi(horasTrabajadasStr));
		employee_setSueldo(auxEmp, atof(sueldoStr));
	}
	return auxEmp;
}

int employee_setId(Employee* listadoEmpleados,int id)
{
	int ret;
	ret = 0;

	if(listadoEmpleados != NULL && id > 0)
	{
		listadoEmpleados->id = id;
		ret = 1;
	}
	return ret;
}
int employee_getId(Employee* listadoEmpleados,int* id)
{
	int ret;
	ret = 0;

	if(listadoEmpleados != NULL && id > 0)
	{
		*id = listadoEmpleados->id;
		ret = 1;
	}
	return ret;
}

int employee_setNombre(Employee* listadoEmpleados,char* nombre)
{
	int ret;
	ret = 0;

	if(listadoEmpleados != NULL)
	{
		strcpy(listadoEmpleados->nombre, nombre);
		ret = 1;
	}
	return ret;
}
int employee_getNombre(Employee* listadoEmpleados,char* nombre)
{
	int ret;
	ret = 0;

	if(listadoEmpleados != NULL)
	{
		strcpy(nombre, listadoEmpleados->nombre);
		ret = 1;
	}
	return ret;
}

int employee_setHorasTrabajadas(Employee* listadoEmpleados,int horasTrabajadas)
{
	int ret;
	ret = 0;

	if(listadoEmpleados != NULL)
	{
		listadoEmpleados->horasTrabajadas = horasTrabajadas;
		ret = 1;
	}
	return ret;
}
int employee_getHorasTrabajadas(Employee* listadoEmpleados,int* horasTrabajadas)
{
	int ret;
	ret = 0;

	if(listadoEmpleados != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = listadoEmpleados->horasTrabajadas;
		ret = 1;
	}
	return ret;
}

int employee_setSueldo(Employee* listadoEmpleados,int sueldo)
{
	int ret;
	ret = 0;

	if(listadoEmpleados != NULL)
	{
		listadoEmpleados->sueldo = sueldo;
		ret = 1;
	}
	return ret;
}
int employee_getSueldo(Employee* listadoEmpleados,int* sueldo)
{
	int ret;
	ret = 0;

	if(listadoEmpleados != NULL && sueldo != NULL)
	{
		*sueldo = listadoEmpleados->sueldo;
		ret = 1;
	}
	return ret;
}

int OrdenarPorNombre(void* empleadoA, void* empleadoB)
{
	int ret= 0;

	if(empleadoA != NULL && empleadoB != NULL)
	{
		ret = strcmp(((Employee*)empleadoA)->nombre, ((Employee*)empleadoB)->nombre);
	}

	return ret;
}

int OrdenarPorHorasTrabajadas(void* empleadoA, void* empleadoB)
{
	int ret;

	if(((Employee*)empleadoA)->horasTrabajadas < ((Employee*)empleadoB)->horasTrabajadas)
	{
		ret = 1;
	}
	else
	{
		if(((Employee*)empleadoA)->horasTrabajadas > ((Employee*)empleadoB)->horasTrabajadas)
		{
			ret = -1;
		}
		else
		{
			ret = 0;
		}
	}

	return ret;
}

int OrdenarPorSueldo(void* empleadoA, void* empleadoB)
{
	int ret;

	if(((Employee*)empleadoA)->sueldo < ((Employee*)empleadoB)->sueldo)
	{
		ret = 1;
	}
	else
	{
		if(((Employee*)empleadoA)->sueldo > ((Employee*)empleadoB)->sueldo)
		{
			ret = -1;
		}
		else
		{
			ret = 0;
		}
	}
	return ret;
}

int OrdenarPorId(void* empleadoA, void* empleadoB)
{
	int ret;

	if(((Employee*)empleadoA)->id < ((Employee*)empleadoB)->id)
	{
		ret = 1;
	}
	else
	{
		if(((Employee*)empleadoA)->id > ((Employee*)empleadoB)->id)
		{
			ret = -1;
		}
		else
		{
			ret = 0;
		}
	}
	return ret;
}

int autoId(LinkedList* listadoEmpleados)
{
	int id;
	int otroId;
	otroId = -1;

	if(listadoEmpleados != NULL)
	{
		id = ll_len(listadoEmpleados);
		otroId = id+1;
	}

	return otroId;
}

void MenuInicio()
{
     printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
     printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
     printf("3. Alta de empleado.\n");
     printf("4. Modificar datos de empleado.\n");
     printf("5. Baja de empleado.\n");
     printf("6. Listar empleados.\n");
     printf("7. Ordenar empleados.\n");
     printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
     printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
     printf("10. Salir.\n");
}

void MenuOrdenamiento()
{
	printf("1. Nombre\n");
	printf("2. Horas Trabajadas\n");
	printf("3. Sueldo\n");
	printf("4. Id\n");
	printf("0. Salir\n");
}

void MenuEdit()
{
	printf("1. Nombre\n");
	printf("2. Horas Trabajadas\n");
	printf("3. Sueldo\n");
	printf("0. Salir\n");
}
