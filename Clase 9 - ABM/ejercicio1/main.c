#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAMEMP 50
#define TAMSEC 5

int main()
{
    int salir = 0;
    eEmpleado gente[TAMEMP] = {{1000, "Juan", 'm', 20000, {12, 5, 2015}, 5, 0},{2212, "Juana", 'f', 15000, {12, 5, 2010}, 3, 0},{5656, "Manuel", 'm', 18500, {12, 5, 2014}, 1, 0}, {3344, "Lucia", 'f', 23200, {2, 10, 2002}, 1, 0},{8658, "Alan", 'm', 29500, {29, 3, 2008}, 1, 0},{5656, "Andrea", 'f', 34600, {12, 5, 2014}, 2, 0},{2121, "Hugo", 'm', 34600, {12, 5, 2014}, 5, 0}};
    eSector sectores[] = {{1,"Ventas"},{2,"Compras"},{3,"Comercial"},{4,"RRHH"},{5,"Sistemas"}};

    inicializarEmpleados(gente, TAMEMP);

    //harcodeo
    gente[0].isEmpty = 0;
    gente[1].isEmpty = 0;
    gente[2].isEmpty = 0;
    gente[3].isEmpty = 0;
    gente[4].isEmpty = 0;
    gente[5].isEmpty = 0;
    gente[6].isEmpty = 0;


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
            break;
        case 8:
            empleadosPorSector(gente, sectores, TAMEMP, TAMSEC);
            system("pause");
            break;
        case 9:
            cantidadPorSector(gente, sectores, TAMEMP, TAMSEC);
            system("pause");
            break;
        case 10:
            sueldosPorSector(gente, sectores, TAMEMP, TAMSEC);
            system("pause");
            break;
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



