#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    int estado;
}eEmpleado;

void empleadoSetLegajo (eEmpleado*, int);
int empleadoGetLegajo (eEmpleado*);

int main()
{
    eEmpleado* unEmpleado;

    unEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));

    if (unEmpleado == (NULL))
    {
        printf("No se pudo reservar espacio en memoria\n\n");
        exit(1);
    }

    empleadoSetLegajo(unEmpleado, 1234);
    strcpy (unEmpleado->nombre, "Juan");
    unEmpleado->sueldo = 20000;
    unEmpleado->estado = 1;

    printf("%d  %s  %.2f", unEmpleado->legajo, unEmpleado->nombre, unEmpleado->sueldo);

    free (unEmpleado);

    return 0;
}

void empleadoSetLegajo (eEmpleado* empleado, int legajo)
{
    if (empleado != NULL && legajo > 0)
    {
        empleado->legajo = legajo;
    }
}

int empleadoGetLegajo (eEmpleado* empleado)
{
    int legajo = -1;

    if (empleado != NULL)
    {
        legajo = empleado->legajo;
    }
    return legajo;
}
