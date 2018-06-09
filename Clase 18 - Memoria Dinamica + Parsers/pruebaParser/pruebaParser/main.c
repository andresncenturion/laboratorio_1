#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    int isEmpty;
} eEmpleado;

int main()
{
    eEmpleado empleado;

    int cant;
    int id;
    int isEmpty;
    char idCad[20];
    char nombre[50];
    char apellido[50];
    char isEmptyCad[20];
    int compare;

    FILE* f;

    f = fopen("data.csv", "r");

    if(f == NULL)
    {
        printf("Error al abrir el fichero\n");
        exit(1);
    }

    while(!feof(f))
    {
        cant = fscanf(f, "%[^,] , %[^,] , %[^,] , %[^\n] \n", idCad, nombre, apellido, isEmptyCad);

        if( cant != 4)
        {
            if(feof(f))
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

        empleado.id = id;
        strcpy(empleado.nombre, nombre);
        strcpy(empleado.apellido, apellido);
        empleado.isEmpty = isEmpty;


        printf("%d %s %s %d \n",  empleado.id, empleado.nombre, empleado.apellido, empleado.isEmpty);

    }

    printf("\n\n");

    fclose(f);

    return 0;
}
