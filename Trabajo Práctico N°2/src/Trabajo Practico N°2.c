#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "validaciones.h"

#define X 5
#define OCUPADO 1
#define VACIO 0

int main(void)
{
	setbuf(stdout, NULL);

	eEmpleado miEmpleado[X];
	int opcion;
	int index;
	int contador;
	contador = 0;

	InitEmployee(miEmpleado, X);

	do
	{
		printf("Elija una opción: \n");
		printf("1. ALTA DE EMPLEADOS\n");
		printf("2. BAJA DE EMPLEADOS \n");
		printf("3. MODIFICACION \n");
		printf("4. LISTADO ORDENADO POR APELLIDO \n");
		printf("5. LISTADO ORDENADO POR SECTOR\n");
		printf("6. TOTAL DEL SALARIO Y PROMEDIO\n");
		printf("7. SALARIOS MAYORES AL PROMEDIO\n");
		printf("0. SALIR \n");

		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				index = CargarDatos(miEmpleado, X);
				contador++;
				printf("Fin de inscripcion empleado N° %d\n", index+1);
			break;
			case 2:
				if(contador > 0)
				{
					ModificarPorId(miEmpleado, X);

					break;
				}
				else
				{
					printf("Debe dar de alta antes!\n");
					break;
				}
			case 3:
				if(contador > 0)
				{
					RemoveEmployee(miEmpleado, X);
					break;
				}
				else
				{
					printf("Debe dar de alta antes!\n");
					break;
				}
			case 4:
				if(contador > 0)
				{
					SortEmployeesByName(miEmpleado, X);
					PrintEmployees(miEmpleado, X);
					break;
				}
				else
				{
					printf("Debe dar de alta antes!\n");
					break;
				}
			case 5:
				if(contador > 0)
				{
					SortEmployeesBySector(miEmpleado, X);
					PrintEmployees(miEmpleado, X);
					break;
				}
				else
				{
					printf("Debe dar de alta antes!\n");
					break;
				}
			case 6:
				MostrarAcumulador(miEmpleado, X);
				MostrarPromedio(miEmpleado, X);
			break;
			case 7:
				CalcularMayorAPromedio(miEmpleado, X);
			break;
		}

	}while(opcion != 0);

	return EXIT_SUCCESS;
}
