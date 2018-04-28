#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAMEMP 50
#define TAMSEC 5

int main()
{
    int salir = 0;
    eEmpleado gente[TAMEMP];
    eSector sectores[] = {{1,"Ventas"},{2,"Compras"},{3,"Comercial"},{4,"RRHH"},{5,"Sistemas"}};

    inicializarEmpleados(gente, TAMEMP);
    do
    {
        switch (menu())
        {
        case 1:
            altaEmpleado(gente, sectores, TAMEMP, TAMSEC);
            system("pause");
            break;
        case 2:
            bajaEmpleado(gente, TAMEMP);
            system("pause");
            break;
        case 3:
            modificarEmpleado(gente, sectores, TAMEMP, TAMSEC);
            system("pause");
            break;
        case 4:
            mostrarEmpleados(gente, sectores, TAMEMP, TAMSEC);
            system("pause");
            break;
        case 5:
            ordenarEmpleados(gente, TAMEMP);
            system("pause");
            break;
        case 6:
            totalSueldos(gente, TAMEMP);
            system("pause");
            break;
        case 7:
            salariosAltos(gente, sectores, TAMEMP, TAMSEC);
            system("pause");
        case 8:
            empleadosPorSector(gente, sectores, TAMEMP, TAMSEC);
            system("pause");
        case 11:
            salir = 1;
            break;
        default:
            printf("Opcion Incorrecta. Intente nuevamente.\n");
            system("pause");
            break;
        }
    }while (salir != 1);

    return 0;
}



