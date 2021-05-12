#include "ArrayEmployees.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define X 5
#define OCUPADO 1
#define VACIO 0


void InitEmployee(eEmpleado listadoEmpleados[], int tam)
{
	int i;
	for(i = 0; i < tam; i++)
	{
		listadoEmpleados[i].isEmpty = VACIO;
	}
}

int BuscarLibre(eEmpleado listadoEmpleados[], int tam)
{
	int i;
	int index;
	index = -1;

	for(i = 0; i < tam; i++)
	{
		if(listadoEmpleados[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}
	return index;
}

int CargarDatos(eEmpleado listadoEmpleados[], int tam)
{
	int index;
	index = BuscarLibre(listadoEmpleados, tam);
	if(index == -1)
	{
		printf("Oops! No hay suficiente espacio \n");
	}
	else
	{
		listadoEmpleados[index] = AddEmployees(listadoEmpleados, tam);
	}
	return index;
}

int idAutoincremental(eEmpleado listadoEmpleados[], int tam)
{
	int i;
	int idValor;
	idValor = 1;

	for(i = 0; i < tam; i++)
	{
		if(listadoEmpleados[i].isEmpty == VACIO)
		{
			idValor = i;
			break;
		}
	}
	return idValor;
}

eEmpleado AddEmployees(eEmpleado listadoEmpleados[], int tam)
{
	eEmpleado misEmpleados;
	char descripcionNombre[20];
	char descripcionApellido[20];

	misEmpleados.idEmpleado = idAutoincremental(listadoEmpleados, tam);
	printf("Su id es: %d\n", misEmpleados.idEmpleado);

	GetString("Ingrese el nombre del empleado \n", descripcionNombre);
	strcpy(misEmpleados.nombre, descripcionNombre);

	GetString("Ingrese el apellido del empleado \n", descripcionApellido);
	strcpy(misEmpleados.apellido, descripcionApellido);

	misEmpleados.salario = GetNumeroFlotante("Ingrese su salario \n", "Error. \n", 8000, 50000);

	misEmpleados.sector = GetNumeroEntero("Ingrese el sector", "Error.", 1, 50);

	misEmpleados.isEmpty = OCUPADO;

	return misEmpleados;
}

int FindEmployeeById(eEmpleado listadoEmpleados[], int tam)
{
	int i;
	int id;
	int encontrado;
	encontrado = -1;

	id = GetNumeroEntero("Ingrese el id a encontrar \n", "Error, no exite el id \n", 0, 1000);
	for(i = 0; i < tam; i++)
	{
		if(listadoEmpleados[i].idEmpleado == id)
		{
			encontrado = i;
			break;
		}
	}
	return encontrado;
}

void RemoveEmployee(eEmpleado listadoEmpleados[], int tamEmp)
{
	int idIngresado;

	idIngresado = FindEmployeeById(listadoEmpleados, tamEmp);
	if(idIngresado == -1)
	{
		printf("No se ha encontrado el id. Vuelva a intentarlo.");
	}
	else
	{
		listadoEmpleados[idIngresado].isEmpty = VACIO;
		printf("Producto eliminado con éxito \n");
	}
}

void ModificarPorId(eEmpleado listadoEmpleados[], int tam)
{
	int idIngresado;
	int opcion;
	char nombreNuevo[20];
	char apellidoNuevo[20];

	idIngresado = FindEmployeeById(listadoEmpleados, tam);

	opcion = GetNumeroEntero("Ingrese lo que desea cambiar. 1. Nombre, 2.Apellido, 3. Salario, 4.Sector \n", "Error. Ingrese lo que desea cambiar \n", 1, 4);
	switch(opcion)
	{
		case 1:
			GetString("Ingrese el nuevo nombre \n", nombreNuevo);
			strcpy(listadoEmpleados[idIngresado].nombre, nombreNuevo);
			printf("Nombre modificado con éxito!! \n");
		break;
		case 2:
			GetString("Ingrese el nuevo apellido \n", apellidoNuevo);
			strcpy(listadoEmpleados[idIngresado].apellido, apellidoNuevo);
			printf("Apellido modificado con éxito!! \n");
		break;
		case 3:
			listadoEmpleados[idIngresado].salario = GetNumeroEntero("Ingrese el nuevo salario \n", "Error. \n", 8000, 50000);
			printf("Salario modificado con éxito!");
		break;
		case 4:
			listadoEmpleados[idIngresado].sector = GetNumeroEntero("Ingrese el nuevo sector \n", "Error. \n", 1, 50);
			printf("Sector modificado con éxito!");
		break;
	}
}

void PrintEmployees(eEmpleado listadoEmpleados[], int tam)
{
	int i;
	printf("----- LISTA DE TRABAJOS -----\n");
	for(i = 0; i < tam; i++)
	{
		if(listadoEmpleados[i].isEmpty == OCUPADO)
		{

			MostrarUnEmpleadoCompleto(listadoEmpleados[i]);
		}
	}
}
void MostrarUnEmpleadoCompleto(eEmpleado empleadoParametro)
{
		printf("Id: %d, Nombre: %s, Apellido: %s, Sector: %d, Salario: %.2f \n", empleadoParametro.idEmpleado,
																				 empleadoParametro.nombre,
																				 empleadoParametro.apellido,
																				 empleadoParametro.sector,
																				 empleadoParametro.salario);
}

void SortEmployeesByName(eEmpleado listadoEmpleados[], int tam)
{
	int i;
	int j;
	eEmpleado aux;

	for(i = 0; i < tam - 1; i++)
	{
		for(j = i+1; j < tam; j++)
		{
			if(strcmp(listadoEmpleados[i].nombre, listadoEmpleados[j].nombre)>0)
			{
				aux = listadoEmpleados[i];
				listadoEmpleados[i] = listadoEmpleados[j];
				listadoEmpleados[j] = aux;
			}
		}
	}
}

void SortEmployeesBySector(eEmpleado listadoEmpleados[], int tam)
{
	int i;
	int j;
	eEmpleado aux;

	for(i = 0; i < tam - 1; i++)
	{
		for(j = i+1; j < tam; j++)
		{
			if(listadoEmpleados[i].sector > listadoEmpleados[j].sector)
			{
				aux = listadoEmpleados[i];
				listadoEmpleados[i] = listadoEmpleados[j];
				listadoEmpleados[j] = aux;
			}
		}
	}
}

float AcumuladorSalario(eEmpleado listadoEmpleados[], int tam)
{
	float acumulador;
	int i;
	for(i =0; i < tam; i++)
	{
		if(listadoEmpleados[i].isEmpty != VACIO)
		{
			acumulador = acumulador + listadoEmpleados[i].salario;
		}
	}
	return acumulador;

}

float CalcularPromedioDelSalario(eEmpleado listadoEmpleados[], int tam)
{
	int contador;
	float acumulador;
	float promedio;
	int i;

	contador = 0;
	acumulador = AcumuladorSalario(listadoEmpleados, tam);
	for(i = 0; i < tam; i++)
	{
		if(listadoEmpleados[i].isEmpty != VACIO)
		{
			contador++;
			promedio = acumulador / contador;
		}
		if(contador == 0)
		{
			promedio =0;
		}
	}
	return promedio;
}

void MostrarPromedio(eEmpleado listadoEmpleados[], int tam)
{
	float promedio;

	promedio = CalcularPromedioDelSalario(listadoEmpleados, tam);
	printf("El total del promedio es: %.2f\n", promedio);
}

void MostrarAcumulador(eEmpleado listadoEmpleados[], int tam)
{
	float acumulador;

	acumulador = AcumuladorSalario(listadoEmpleados, tam);
	printf("El total del acumulador es: %.2f\n", acumulador);
}

void CalcularMayorAPromedio(eEmpleado listadoEmpleados[], int tam)
{
	int i;
	float promedio;
	promedio = (float)CalcularPromedioDelSalario(listadoEmpleados, tam);
	for(i = 0; i < tam; i++)
	{
		if(listadoEmpleados[i].salario > promedio)
		{
			MostrarUnEmpleadoCompleto(listadoEmpleados[i]);
			break;
		}
	}
}


