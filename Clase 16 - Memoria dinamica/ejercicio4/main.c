#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    int estado;
}eEmpleado;

void empleadoSetLegajo (eEmpleado*, int);
int empleadoGetLegajo (eEmpleado*);
eEmpleado* new_empleado();
eEmpleado* new_empleado_Param(int, char[], float);
void mostrarEmpleado (eEmpleado*);
void mostrarEmpleados (eEmpleado*, int);
void inicializarArray (eEmpleado*, int);
eEmpleado* newArrayEmpleados (int);
int buscarLibre (eEmpleado*, int);
void guardarEmpleados (eEmpleado*, int, char*);
void cargarEmpleados (eEmpleado*, int, char*);



int main()
{
    eEmpleado* unEmpleado;
    eEmpleado* personal;
    int cantidad;

    personal = newArrayEmpleados(TAM);

    if (personal == (NULL))
    {
        printf("No se pudo reservar espacio en memoria\n\n");
        exit(1);
    }

    unEmpleado = new_empleado_Param(4521, "Daniel", 15000);
    *personal = *unEmpleado;
    unEmpleado = new_empleado_Param(222, "Marixa", 24520);
    *(personal+1) = *unEmpleado;
    unEmpleado = new_empleado_Param(3345, "Julieta", 54210);
    *(personal+2) = *unEmpleado;

    mostrarEmpleados(personal, TAM);
    guardarEmpleados(personal, TAM, "empleados");

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

eEmpleado* new_empleado()
{
    eEmpleado* nuevoEmpleado;

    nuevoEmpleado = (eEmpleado*) malloc (sizeof(eEmpleado));
    if (nuevoEmpleado != NULL)
    {
        nuevoEmpleado->legajo = 0;
        strcpy(nuevoEmpleado->nombre, "Felipe Domingo");
        nuevoEmpleado->sueldo = 0;
        nuevoEmpleado->estado = 0;
    }
    return nuevoEmpleado;
}

eEmpleado* new_empleado_Param(int legajo, char nombre[], float sueldo)
{
    eEmpleado* nuevoEmpleado;

    nuevoEmpleado = new_empleado();
    if (nuevoEmpleado != NULL)
    {
        nuevoEmpleado->legajo = legajo;
        strcpy(nuevoEmpleado->nombre, nombre);
        nuevoEmpleado->sueldo = sueldo;
        nuevoEmpleado->estado = 1;
    }
    return nuevoEmpleado;
}

void mostrarEmpleado (eEmpleado* unEmpleado)
{
    printf("%d  %s  %.2f", unEmpleado->legajo, unEmpleado->nombre, unEmpleado->sueldo);
    printf("\n");
}

void mostrarEmpleados (eEmpleado* unEmpleado, int tam)
{
    int i;

    if (unEmpleado != NULL && tam>0)
    {
        for (i=0; i<tam ; i++)
        {
            if ((unEmpleado+i)->estado == 1)
            {
                mostrarEmpleado(unEmpleado+i);
            }
        }
    }
}

void inicializarArray (eEmpleado* arrayEmpleados, int tam)
{
    int i;

    if (arrayEmpleados != NULL && tam>0)
    {
        for (i=0 ; i<tam ; i++)
        {
            (arrayEmpleados+i)->estado = 0;
        }
    }
}

eEmpleado* newArrayEmpleados (int tam)
{
    eEmpleado* arrayEmpleado;

    if (tam>0)
    {
        arrayEmpleado = (eEmpleado*) malloc(tam*sizeof(eEmpleado));
        if (arrayEmpleado != NULL)
        {
            inicializarArray(arrayEmpleado, tam);
        }
    }
    return arrayEmpleado;
}

int buscarLibre (eEmpleado* empleados, int tam)
{

}

void guardarEmpleados (eEmpleado* empleados, int tam, char* path)
{
    FILE* f;
    int i;

    f = fopen (path, "wb");

    if (f != NULL)
    {
        for (i=0 ; i<tam ; i++)
        {
            if ((empleados+i)->estado == 1)
            {
                fwrite((empleados+i), sizeof(eEmpleado), 1, f);
            }
        }
        fclose(f);
        printf("\nEmpleados guardados con exito\n\n");
    }
}

void cargarEmpleados (eEmpleado* empleados, int tam, char* path)
{
    FILE* f;
    int indice;
    eEmpleado empleadoAuxiliar;
    int cant;
    int total = 0;

    f = fopen (path, "rb");

    while (!feof(f))
    {
        indice = buscarLibre(empleados, tam);
        if (indice == -1)
        {
            printf("No hay mas lugar");
            break;
        }
        else
        {
            cant = fread(&empleadoAuxiliar, sizeof(eEmpleado), 1, f);

            if (cant != 1)
            {
                if (feof(f))
                {
                    break;
                }
                else
                {
                    printf ("No se pudo leer el ultimo registro\n");
                    break;
                }
            }
            *(empleados+indice) = *empleadoAuxiliar;
            total++;
        }
    }
    fclose(f);
    return total;
}
