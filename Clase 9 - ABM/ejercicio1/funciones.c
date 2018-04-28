#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 50

int menu ()
{
    int opcion;

    system ("cls");
    printf("**ABM EMPLEADOS**\n");
    printf("\nINGRESE LA OPCION DESEADA\n");
    printf("1. ALTA");
    printf("\n2. BAJA");
    printf("\n3. MODIFICACION");
    printf("\n4. LISTAR");
    printf("\n5. ORDENAR");
    printf("\n6. SALIR");
    printf("\n7. TOTAL SUELDOS");
    printf("\n8. LOS QUE MAS GANAN");
    scanf("%d",&opcion);
    return opcion;
}

void inicializarEmpleados (eEmpleado gente[], int tam)
{
    int i;

    for (i=0 ; i<tam ; i++)
    {
        gente[i].isEmpty = 1;
    }
}

void altaEmpleado (eEmpleado gente[], int tam)
{
    int index;
    int indexEmpleado;
    int legajo;
    eEmpleado nuevoEmpleado;

    index = buscarLibre(gente, tam);
    if (index == -1)
    {
        printf("\nNo se pueden ingresar mas empleados.");
        system("pause");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        indexEmpleado = buscarEmpleado(gente, TAM, legajo);
        if (indexEmpleado != -1)
        {
            printf("\nEl legajo %d ya fue ingresado.", legajo);
            mostrarEmpleado (gente[indexEmpleado]);
        }
        else
        {
            gente[index] = pedirEmpleado(nuevoEmpleado);
            gente[index].isEmpty = 0;
            printf("\nAlta exitosa");
        }
    }
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

int buscarEmpleado (eEmpleado gente[], int tam, int legajo)
{
    int i;
    int index = -1;

    for (i=0 ; i<tam ; i++)
    {
        if (gente[i].legajo == legajo && gente[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

eEmpleado pedirEmpleado (eEmpleado employee)
{
    printf("NOMBRE: ");
    fflush(stdin);
    gets(employee.nombre);
    printf("SEXO: ");
    fflush(stdin);
    employee.sexo = getchar();
    printf("SUELDO: ");
    scanf("%f", &employee.sueldo);
    printf("FECHA DE INGRESO (dd/mm/aa): ");
    scanf("%d %d %d", &employee.fecha.day, &employee.fecha.month, &employee.fecha.year);
    printf("ID SECTOR: ");
    employee.idSector = mostrarSectores();

    return employee;
}

void mostrarEmpleado (eEmpleado employee)
{
    printf("NOMBRE: %s", employee.nombre);
    printf("\nLEGAJO: %d", employee.legajo);
    printf("\nSEXO: %c", employee.sexo);
    printf("\nSUELDO: %.2f", employee.sueldo);
    printf("\nFECHA DE INGRESO: %d %d %d", employee.fecha.day, employee.fecha.month, employee.fecha.year);
}

void mostrarEmpleados (eEmpleado employees[], int tam)
{
    int i;
    for (i=0 ; i<tam ; i++)
    {
        if (employees[i].isEmpty == 0)
        {
            printf("NOMBRE: %s", employees[i].nombre);
            printf("\nLEGAJO: %d", employees[i].legajo);
            printf("\nSEXO: %c", employees[i].sexo);
            printf("\nSUELDO: %.2f", employees[i].sueldo);
            printf("\nFECHA DE INGRESO: %d %d %d", employees[i].fecha.day, employees[i].fecha.month, employees[i].fecha.year);
            printf("\n");
        }
    }
}

void bajaEmpleado (eEmpleado gente[], int tam)
{
    int legajo;
    int existeLegajo;

    printf("\nIngrese legajo a dar de baja: ");
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

int mostrarSectores (void)
{
    int opcionSector;

    printf("\n1. VENTAS");
    printf("\n2. COMPRAS");
    printf("\n3. COMERCIAL");
    printf("\n4. RRHH");
    printf("\n5. SISTEMAS");
    scanf("%d", &opcionSector);

    return opcionSector;
}
