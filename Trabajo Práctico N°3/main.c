#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "Validaciones.h"


int main()
{
	setbuf(stdout, NULL);
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	MenuInicio();
    	printf("Ingrese un elemento de la lista\n");
    	scanf("%d", &option);

        switch(option)
        {
            case 1:
            	controller_loadFromText("data.csv",listaEmpleados);
			break;
            case 2:
				controller_loadFromBinary("data.bin",listaEmpleados);
            break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
            break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            break;
            case 8:
            	controller_saveAsText("data.csv", listaEmpleados);
            break;
            case 9:
            	controller_saveAsBinary("data.bin",listaEmpleados);
            break;
        }
    }while(option != 10);
    return 0;
}

