#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAMEMP 50
#define TAMSEC 5

void inicializarEmpleados (eEmpleado gente[], int tam)
{
    int i;

    for (i=0 ; i<tam ; i++)
    {
        gente[i].isEmpty = 1;
    }
}

int menu (void)
{
    int opcion;

    system ("cls");
    printf("***ABM EMPLEADOS***");
    printf("\n\nINGRESE LA OPCION DESEADA");
    printf("\n1. ALTA");
    printf("\n2. BAJA");
    printf("\n3. MODIFICACION");
    printf("\n4. LISTAR");
    printf("\n5. ORDENAR");
    printf("\n6. SALIR");
    printf("\n7. TOTAL SUELDOS");
    printf("\n8. LOS QUE MAS GANAN");
    printf("\n\n");
    scanf("%d",&opcion);
    return opcion;
}

void altaEmpleado (eEmpleado gente[], eSector sectores[], int tamemp, int tamsec)
{
    int index;
    int indexExiste;
    int auxLegajo;
    eEmpleado nuevoEmpleado;

    system("cls");
    index = buscarLibre(gente, tamemp);
    if (index == -1)
    {
        printf("\nNo se pueden ingresar mas empleados.");
        system("pause");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &auxLegajo);
        indexExiste = buscarEmpleado(gente, TAMEMP, auxLegajo);
        if (indexExiste != -1)
        {
            printf("\nEl legajo %d ya fue ingresado.", auxLegajo);
            mostrarEmpleado (gente[indexExiste], sectores, TAMSEC);
        }
        else
        {
            nuevoEmpleado.isEmpty = 0;

            nuevoEmpleado.legajo = auxLegajo;
            printf("NOMBRE: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("SEXO: ");
            fflush(stdin);
            nuevoEmpleado.sexo = getchar();
            printf("SUELDO: ");
            scanf("%f", &nuevoEmpleado.sueldo);
            printf("FECHA DE INGRESO (dd/mm/aa): ");
            scanf("%d %d %d", &nuevoEmpleado.fecha.day, &nuevoEmpleado.fecha.month, &nuevoEmpleado.fecha.year);
            nuevoEmpleado.idSector = pedirSector(sectores, TAMSEC);

            gente[index] = nuevoEmpleado;

            printf("\nAlta exitosa");
        }
    }
    printf("\n\n");
}

int buscarLibre (eEmpleado gente[], int tam)
{
    int i;
    int index = -1;

    for (i=0 ; i<tam ; i++)
    {
        if (gente[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarEmpleado (eEmpleado gente[], int tam, int auxLegajo)
{
    int i;
    int index = -1;

    for (i=0 ; i<tam ; i++)
    {
        if (gente[i].legajo == auxLegajo && gente[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int pedirSector (eSector sectores[], int tam)
{
    int opcionSector;
    int i;

    printf("\nSELECCIONE SECTOR: ");
    for (i=0; i<tam ; i++)
    {
        printf("%d- %s\n", sectores[i].id, sectores[i].nombre);
    }
    scanf("%d", &opcionSector);

    return opcionSector;
}

void mostrarEmpleado (eEmpleado employee, eSector sectores[], int tamsec)
{
    int i;
    int indexSector;

    for (i=0 ; i<tamsec ; i++)
    {
        if (employee.idSector == sectores[i].id)
        {
            indexSector = i;
            break;
        }
    }
    printf("%6d \t%20s \t%c \t%5.2f \t%2d/%2d/%d \t%10s", employee.legajo, employee.nombre, employee.sexo, employee.sueldo, employee.fecha.day, employee.fecha.month, employee.fecha.year, sectores[indexSector].nombre);
}

void mostrarEmpleados (eEmpleado gente[], eSector sectores[], int tamEmp, int tamSec)
{
    int i;

    system("cls");
    printf("LEGAJO \tNOMBRE \tSEXO \tSUELDO \tFECHA DE INGRESO \tSECTOR\n\n");
    for (i=0 ; i<tamEmp ; i++)
    {
        if (gente[i].isEmpty == 0)
        {
            mostrarEmpleado(gente[i], sectores, tamSec);
        }
    }
}

void bajaEmpleado (eEmpleado gente[], int tam)
{
    int legajo;
    int existeLegajo;

    system("cls");
    printf("Ingrese legajo a dar de baja: ");
    scanf("%d", &legajo);
    existeLegajo = buscarEmpleado(gente, tam, legajo);
    if (existeLegajo == -1)
    {
        printf("El legajo ingresado no existe.");
    }
    else
    {
        gente[existeLegajo].isEmpty = 1;
        printf("Baja exitosa");
    }
}

void modificarEmpleado (eEmpleado gente[], eSector sectores[], int tamemp, int tamsec)
{
    int legajo;
    int index;
    float auxSueldo;
    char confirma;

    system ("cls");
    printf("--- MODIFICACION DE EMPLEADO ---");
    printf("\nIngrese legajo a modificar: ");
    scanf("%d", &legajo);

    index = buscarEmpleado(gente, tamemp, legajo);
    if (index == -1)
    {
        printf("El legajo ingresado no existe.");
    }
    else
    {
        mostrarEmpleado(gente[index], sectores, tamsec);
        printf("\nIngrese nuevo sueldo: ");
        scanf("%f", &auxSueldo);
        printf("\nConfima cambio de sueldo?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        if (confirma == 's')
        {
            gente[index].sueldo = auxSueldo;
            printf("\nModificacion exitosa.");
        }
        else
        {
            printf("\nModificacion cancelada");
        }
    }
}
