#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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
		printf("Ingrese sus horas trabajadas:\n");
		scanf("%d", &horasTrabajadas);
		printf("Ingrese su sueldo:\n");
		scanf("%d", &sueldo);

		employee_setId(nuevoEmpleado, id);
		employee_setNombre(nuevoEmpleado, nombre);
		employee_setHorasTrabajadas(nuevoEmpleado, horasTrabajadas);
		employee_setSueldo(nuevoEmpleado, sueldo);

		ll_add(pArrayListEmployee, nuevoEmpleado);
		ret = 1;
	}


    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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

	controller_ListEmployee(pArrayListEmployee);

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		if(pArrayListEmployee != NULL)
		{
			printf("Ingrese el id para editar el empleado:\n");
			scanf("%d", &idAux);
			for(i = 0; i < len; i++)
			{
				empleado = (Employee*)ll_get(pArrayListEmployee,i);
				employee_getId(empleado, &id);
				if(idAux == id)
				{
					do
					{
						MenuEdit();
						printf("Elija lo que desea cambiar:\n");
						scanf("%d", &opcion);

						switch(opcion)
						{
						case 1:
							printf("Ingrese su nuevo nombre: \n");
							scanf("%s", nombre);
							employee_setNombre(empleado, nombre);
						break;
						case 2:
							printf("Ingrese su nuevo horario: \n");
							scanf("%d", &horasTrabajadas);
							employee_setHorasTrabajadas(empleado, horasTrabajadas);
						break;
						case 3:
							printf("Ingrese su nuevo sueldo: \n");
							scanf("%d", &sueldo);
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

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int ret;
	ret = 0;
	int len;
	int id;
	int i;

	controller_ListEmployee(pArrayListEmployee);

	printf("Ingrese el id a encontrar:\n");
	scanf("%d", &id);
	len = ll_len(pArrayListEmployee);
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

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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
			printf("Elija el criterio de orden:\n");
			scanf("%d", &opcion);

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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret;
	ret = 0;
	FILE* pArchivoBin;
	Employee* empleado;
	int len;
	len = ll_len(pArrayListEmployee);
	int i;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pArchivoBin = fopen(path, "wb");

		if(pArchivoBin != NULL)
		{
			for(i = 0; i < len; i++)
			{
				empleado = (Employee*)ll_get(pArrayListEmployee, i);
				fwrite(empleado, sizeof(Employee), 1, pArchivoBin);
			}
			fclose(pArchivoBin);
		}
	}
    return ret;
}

