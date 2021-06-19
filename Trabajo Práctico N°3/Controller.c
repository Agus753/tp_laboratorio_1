#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Validaciones.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int ret;
	ret = 0;
	FILE *pFile;


	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile =fopen(path,"r");
		if(pFile != NULL)
		{
			if(parser_EmployeeFromText(pFile ,pArrayListEmployee) == 1)
			{
				printf("Empleados leídos con éxito!!\n");
				ret = 1;
			}
			else
			{
				printf("Error.\n");
			}
		}
	}
    return ret;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret;
	ret = 0;
	FILE *pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		ll_clear(pArrayListEmployee);
		pFile =fopen(path,"rb");
		if(pFile != NULL)
		{
			if(parser_EmployeeFromBinary(pFile ,pArrayListEmployee) == 1)
			{
				printf("Empleado leído con éxito!!\n");
				ret = 1;
			}
			else
			{
				printf("Error.\n");
			}
		}
	}
    return ret;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int ret;
	ret = 0;
	Employee* nuevoEmpleado = employee_new();

	int id;
	char nombre[40];
	int horasTrabajadas;
	int sueldo;

	if(pArrayListEmployee != NULL)
	{
		id = autoId(pArrayListEmployee);
		printf("Ingrese su nombre:\n");
		scanf("%s", nombre);

		GetNumeroEntero(&horasTrabajadas, "Ingrese sus horas trabajadas\n", "Error\n", 90, 200);
		GetNumeroEntero(&sueldo, "Ingrese su sueldo\n", "Error\n", 8000, 100000);

		employee_setId(nuevoEmpleado, id);
		employee_setNombre(nuevoEmpleado, nombre);
		employee_setHorasTrabajadas(nuevoEmpleado, horasTrabajadas);
		employee_setSueldo(nuevoEmpleado, sueldo);

		ll_add(pArrayListEmployee, nuevoEmpleado);
		ret = 1;
	}


    return ret;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	int ret;
	ret =0;
	int len;
	int id;
	int idAux;
	int i;
	int opcion;
	char nombre[40];
	int horasTrabajadas;
	int sueldo;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		if(pArrayListEmployee != NULL)
		{
			controller_ListEmployee(pArrayListEmployee);
			GetNumeroEntero(&idAux, "Ingrese el id a editar\n", "Error\n", 1, len);
			for(i = 0; i < len; i++)
			{
				empleado = (Employee*)ll_get(pArrayListEmployee,i);
				employee_getId(empleado, &id);
				if(idAux == id)
				{
					do
					{
						MenuEdit();
						GetNumeroEntero(&opcion, "Ingrese lo que desea cambiar\n", "Error\n", 0, 3);

						switch(opcion)
						{
						case 1:
							printf("Ingrese su nuevo nombre: \n");
							scanf("%s", nombre);
							employee_setNombre(empleado, nombre);
						break;
						case 2:
							GetNumeroEntero(&horasTrabajadas, "Ingrese su nuevo horario\n", "Error\n", 90, 200);
							employee_setHorasTrabajadas(empleado, horasTrabajadas);
						break;
						case 3:
							GetNumeroEntero(&sueldo, "Ingrese su nuevo sueldo\n", "Error\n", 8000, 100000);
							employee_setSueldo(empleado, sueldo);
						break;
						}
					}
					while(opcion != 0);
				}
			}
		}

		ret = 1;
	}

    return ret;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int ret;
	ret = 0;
	int len;
	int id;
	int i;

	controller_ListEmployee(pArrayListEmployee);

	len = ll_len(pArrayListEmployee);
	GetNumeroEntero(&id, "Ingrese el id a remover\n", "Error\n", 1, len);
	if(pArrayListEmployee != NULL)
	{
		for(i = 0; i < len; i++)
		{
			if(i == id)
			{
				ll_remove(pArrayListEmployee, i-1);
				printf("Eliminado con éxito!\n");
				ret = 1;
				break;
			}
		}
		if(ret != 1)
		{
			printf("No se encontró el empleado\n");
		}
	}
    return ret;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int ret;
	ret = 0;
	int i;
	int len;
	Employee* empleadoAux;

	len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL)
	{
		printf("Id -- Nombre -- Horas trabajadas -- Sueldo\n");
		for(i = 0; i < len; i++)
		{
			empleadoAux = (Employee*)ll_get(pArrayListEmployee, i);
			printf("%4d, %5s, %4d, %4d\n", empleadoAux->id, empleadoAux->nombre, empleadoAux->horasTrabajadas, empleadoAux->sueldo);
			ret = 1;
		}

	}
    return ret;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int ret;
	ret = 0;
	int opcion;

	if(pArrayListEmployee != NULL)
	{
		do
		{
			MenuOrdenamiento();
			GetNumeroEntero(&opcion, "Ingrese el criterio de orden\n", "Error\n", 0, 4);

			switch(opcion)
			{
				case 1:
					ll_sort(pArrayListEmployee, OrdenarPorNombre,1);
				break;
				case 2:
					ll_sort(pArrayListEmployee, OrdenarPorHorasTrabajadas,1);
				break;
				case 3:
					ll_sort(pArrayListEmployee, OrdenarPorSueldo,1);
				break;
				case 4:
					ll_sort(pArrayListEmployee, OrdenarPorId,0);
				break;
			}
		}while(opcion != 0);
		ret = 1;
	}
    return ret;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	Employee* empleado;
	int ret;
	ret = 0;
	int i;
	char nombre[40];
	int sueldo;
	int horasTrabajadas;
	int id;
	int len = ll_len(pArrayListEmployee);

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pArchivo = fopen(path, "w");
		if(pArchivo != NULL)
		{
			for(i = 0; i < len; i++)
			{
				empleado = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(empleado, &id);
				employee_getNombre(empleado, nombre);
				employee_getHorasTrabajadas(empleado, &horasTrabajadas);
				employee_getSueldo(empleado, &sueldo);
				fprintf(pArchivo, "%d, %s, %d, %d\n",id, nombre, horasTrabajadas, sueldo);
			}
			fclose(pArchivo);
			ret =1;
		}
	}
    return ret;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret;
	ret = 0;
	FILE* pArchivoBin;
	Employee* empleado;
	int len;
	int i;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		pArchivoBin = fopen(path, "wb");

		if(pArchivoBin != NULL)
		{
			for(i = 0; i < len; i++)
			{
				empleado = (Employee*)ll_get(pArrayListEmployee, i);
				fwrite(empleado, sizeof(Employee), 1, pArchivoBin);
				printf("%d\n", i);
			}
			fclose(pArchivoBin);
		}
	}
    return ret;
}

int controller_deleteLinkedList(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee != NULL)
	{
		ll_deleteLinkedList(pArrayListEmployee);
	}
	return 0;
}
