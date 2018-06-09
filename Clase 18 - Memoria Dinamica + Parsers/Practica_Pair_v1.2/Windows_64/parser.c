#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    Employee* empleado;

    int index = 0;
    int cant;
    int id;
    int isEmpty;
    char idCad[20];
    char nombre[50];
    char apellido[50];
    char isEmptyCad[20];
    int compare;

    if (pFile != NULL)
    {
        pFile = fopen("data.csv", "r");
        empleado = employee_new();

        if(pFile == NULL)
        {
            printf("Error al abrir el fichero\n");
            exit(1);
        }

        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,] , %[^,] , %[^,] , %[^\n] \n", idCad, nombre, apellido, isEmptyCad);

            if( cant != 4)
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    printf("Problema para leer el archivo\n");

                    break;
                }
            }
            id = atoi(idCad);
            compare = strcmp(isEmptyCad, "false");
            if(compare == 0)
            {
                isEmpty = 0;
            }
            else
            {
                isEmpty = 1;
            }

            empleado->id = id;
            strcpy(empleado->name, nombre);
            strcpy(empleado->lastName, apellido);
            empleado->isEmpty = isEmpty;
            al_add(pArrayListEmployee,empleado);
            index++;
        }
    }
    printf("Parseo exitoso.\n\n");
    fclose(pFile);

    return 0;
}
