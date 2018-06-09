#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    Employee empleado;

    char idString;
    char name[51];
    char lastName[51];
    char stringIsEmpty;
    int cant;
    int id;
    int isEmpty = 0;

    pFile = fopen("data.csv", "r");

    if (pFile == NULL)
        {
            printf("Error al abrir el archivo.\n\n");
            exit(1);
        }
    while (!feof(pFile))
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n] \n", idString, name, lastName, stringIsEmpty);
        if (cant != 4)
        {
            if (feof(pFile))
            {
                printf ("Parseo exitoso.\n\n");
                break;
            }
            else
            {
                printf("Problema al leer el archivo.\n\n");
                break;
            }

        }

        id = atoi(idString);
        if (strcmp(stringIsEmpty, "true"))
        {
            isEmpty = 1;
        }


        empleado.id = id;
        empleado.name = name;
        empleado.lastName = lastName;
        empleado.isEmpty = isEmpty;

        printf("%d  %s  %s  %d", empleado.id, empleado.name, empleado.lastName, empleado.isEmpty);
    }

    return 0;
}
