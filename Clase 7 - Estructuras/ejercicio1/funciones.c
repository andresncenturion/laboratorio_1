#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

eEmpleado pedirEmpleado (eEmpleado employee)
{
    printf("NOMBRE: ");
    fflush(stdin);
    gets(employee.nombre);
    printf("LEGAJO: ");
    scanf("%d", &employee.legajo);
    employee.legajo = validarMayorCero(employee.legajo, "EL LEGAJO INGRESADO NO ES VALIDO. INGRESE UN NUMERO MAYOR A CERO: ");
    printf("SEXO: ");
    fflush(stdin);
    employee.sexo = getchar();
    employee.sexo = validarSexo(employee.sexo);
    printf("SUELDO: ");
    scanf("%f", &employee.sueldo);
    employee.sueldo = validarMayorCero(employee.sueldo, "EL SUELDO INGRESADO NO ES VALIDO. INGRESE UN NUMERO MAYOR A CERO: ");
    printf("FECHA DE INGRESO (dd/mm/aa): ");
    scanf("%d %d %d", &employee.fecha.day, &employee.fecha.month, &employee.fecha.year);

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
        printf("NOMBRE: %s", employees[i].nombre);
        printf("\nLEGAJO: %d", employees[i].legajo);
        printf("\nSEXO: %c", employees[i].sexo);
        printf("\nSUELDO: %.2f", employees[i].sueldo);
        printf("\nFECHA DE INGRESO: %d %d %d", employees[i].fecha.day, employees[i].fecha.month, employees[i].fecha.year);
        printf("\n");
    }
}

char validarSexo (char sexo)
{
    sexo = toupper(sexo);
    while (sexo != 'F' && sexo != 'M')
    {
        printf ("EL SEXO INGRESADO NO ES VALIDO. INGRESE F O M: ");
        fflush(stdin);
        sexo = getchar();
        sexo = toupper(sexo);
    }
    return sexo;
}

int validarMayorCero (int valor, char mensaje[])
{
    while (valor < 1)
    {
        printf(mensaje);
        scanf("%d", &valor);
    }
    return valor;
}
