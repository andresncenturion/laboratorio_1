#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    //eEmpleado unEmpleado;
    //eEmpleado plantel[4];
    eEmpleado plantel[] = {{"fabricio", 16, 'f', 16000, {12, 01, 1991}}, {"alan", 2, 'm', 20000, {13, 02, 1992}}, {"nicolas", 4, 'm', 40000, {14, 03, 1993}}, {"juan", 6, 'f', 60000, {15, 04, 1994}}};
    //int i = 0;
    int opcion;

    //unEmpleado = pedirEmpleado(unEmpleado);
    //mostrarEmpleado(unEmpleado);
    /*for (i=0 ; i<4 ; i++)
    {
        plantel[i] = pedirEmpleado(unEmpleado);
    }
    printf ("\n");*/
    mostrarEmpleados(plantel, 4);

    printf("SELECCIONE UNA OPCION DEL MENU: ");
    printf("\n1. ORDENAR ALFABETICAMENTE");
    printf("\n2. ORDENAR POR LEGAJO");
    printf("\n3. SUELDO");
    printf("\n4. SEXO Y LEGAJO");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        ordenarPorNombre(plantel, 4);
        break;
    case 2:
        ordenarPorLegajo(plantel, 4);
        break;
    case 3:
        ordenarPorSueldo(plantel, 4);
        break;
    case 4:
        ordenarPorSexoYLegajo(plantel, 4);
        break;
    }
    mostrarEmpleados(plantel, 4);
    return 0;
}
