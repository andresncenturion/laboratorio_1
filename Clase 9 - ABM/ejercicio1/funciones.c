#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf("\n 1. ALTA");
    printf("\n 2. BAJA");
    printf("\n 3. MODIFICACION");
    printf("\n 4. LISTAR");
    printf("\n 5. ORDENAR");
    printf("\n 6. INFORMAR TOTAL SUELDOS");
    printf("\n 7. INFORMAR SALARIOS MAS ALTOS");
    printf("\n 8. INFORMAR EMPLEADOS POR SECTOR");
    printf("\n 9. INFORMAR CANTIDAD DE EMPLEADOS POR SECTOR");
    printf("\n10. INFORMAR TOTAL DE SUELDOS POR SECTOR");
    printf("\n11. SALIR");
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
        printf("No se pueden ingresar mas empleados.\n\n");
        system("pause");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &auxLegajo);
        indexExiste = buscarEmpleado(gente, TAMEMP, auxLegajo);
        if (indexExiste != -1)
        {
            printf("\nEl legajo %d ya fue ingresado.\n", auxLegajo);
            printf("LEGAJO \tNOMBRE \tSEXO \tSUELDO \tFECHA DE INGRESO \tSECTOR\n\n");
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

    printf("\nSELECCIONE SECTOR: \n");
    for (i=0; i<tam ; i++)
    {
        printf("%d- %s\n", sectores[i].id, sectores[i].nombre);
    }
    scanf("\n\n%d", &opcionSector);

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
    printf("%d \t%s \t%c \t%.2f \t%d/%d/%d \t%s\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo, employee.fecha.day, employee.fecha.month, employee.fecha.year, sectores[indexSector].nombre);
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
        printf("El legajo ingresado no existe.\n\n");
    }
    else
    {
        gente[existeLegajo].isEmpty = 1;
        printf("Baja exitosa\n\n");
    }
}

void modificarEmpleado (eEmpleado gente[], eSector sectores[], int tamemp, int tamsec)
{
    int legajo;
    int index;
    float auxSueldo;
    char confirma;

    system ("cls");
    printf("--- MODIFICACION DE EMPLEADO ---\n\n");
    printf("Ingrese legajo a modificar: ");
    scanf("%d", &legajo);

    index = buscarEmpleado(gente, tamemp, legajo);
    if (index == -1)
    {
        printf("El legajo ingresado no existe.\n\n");
    }
    else
    {
        mostrarEmpleado(gente[index], sectores, tamsec);
        printf("Ingrese nuevo sueldo: ");
        scanf("%f", &auxSueldo);
        printf("\nConfima cambio de sueldo?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        if (confirma == 's')
        {
            gente[index].sueldo = auxSueldo;
            printf("Modificacion exitosa.\n\n");
        }
        else
        {
            printf("Modificacion cancelada.\n\n");
        }
    }
}

void ordenarEmpleados (eEmpleado gente[], int tam)
{
    int i;
    int j;
    eEmpleado auxEmpleado;

    for (i=0 ; i<tam-1 ; i++)
    {
        for (j=i+1 ; j<tam ; j++)
        {
            if (gente[i].sexo > gente[j].sexo)
            {
                auxEmpleado = gente[i];
                gente[i] = gente[j];
                gente[j] = auxEmpleado;
            }
            else if (gente[j].sexo == gente[i].sexo)
            {
                if (strcmp(gente[i].nombre, gente[j].nombre) > 0)
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
            }
        }
    }
    printf("\nOrdenamiento exitoso.\n\n");
}

void totalSueldos(eEmpleado gente[], int tamEmp)
{
    int i;
    float acumSueldos = 0;

    system("cls");
    for (i=0 ; i<tamEmp ; i++)
    {
        acumSueldos += gente[i].sueldo;
    }
    printf("Total de sueldos: %.2f\n\n", acumSueldos);
}

void salariosAltos(eEmpleado gente[], eSector sectores[], int tam, int tamSec)
{
    int i;
    int flagMaximo = 0;
    float sueldoMaximo;

    system("cls");
    printf("--- SALARIOS MAS ALTOS ---\n\n");
    for (i=0 ; i<tam ; i++)
    {
        if (gente[i].sueldo>sueldoMaximo || flagMaximo == 0)
        {
            flagMaximo = 1;
            sueldoMaximo = gente[i].sueldo;
        }
    }
    for (i=0 ; i<tam ; i++)
    {
        if (gente[i].sueldo == sueldoMaximo)
        {
            mostrarEmpleado(gente[i], sectores, tam);
        }
    }
}

void empleadosPorSector(eEmpleado gente[], eSector sectores[], int tamEmp, int tamSec)
{
    int i;
    int j;

    system("cls");
    printf("--- LISTADO DE EMPLEADOS POR SECTOR ---\n\n");
    for (i=0 ; i<tamSec ; i++)
    {
        printf("--- %s ---\n\n", sectores[i].nombre);
        for (j=0 ; j<tamEmp ; j++)
        {
            if (gente[j].isEmpty == 0 && gente[j].idSector == sectores[i].id)
            {
                mostrarEmpleado(gente[j], sectores, tamSec);
            }
        }
    }
}

void cantidadPorSector(eEmpleado gente[], eSector sectores[], int tamEmp, int tamSec)
{
    int i;
    int j;
    int contadorSector = 0;

    system("cls");
    printf("--- CANTIDAD DE EMPLEADOS POR SECTOR ---\n\n");
    for (i=0 ; i<tamSec ; i++)
    {
        printf("%s: ", sectores[i].nombre);
        for (j=0 ; j<tamEmp ; j++)
        {
            if (gente[j].isEmpty == 0 && gente[j].idSector == sectores[i].id)
            {
                contadorSector++;
            }
        }
        printf("%d\n", contadorSector);
    }
}

void sueldosPorSector(eEmpleado gente[], eSector sectores[], int tamEmp, int tamSec)
{
    int i;
    int idSector;
    float acumSueldo = 0;

    system("cls");
    printf("--- SUELDOS POR SECTOR ---\n");
    idSector = pedirSector(sectores, tamSec);
    printf("%s: ", sectores[idSector-1].nombre);
    for (i=0 ; i<tamEmp ; i++)
    {
        if(gente[i].idSector == idSector)
        {
            acumSueldo += gente[i].sueldo;
        }
    }
    printf("%.2f\n", acumSueldo);
}
