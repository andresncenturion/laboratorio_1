#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 50

int main()
{
    int salir = 0;
    eEmpleado gente[TAM];

    inicializarEmpleados(gente, TAM);
    do
    {
        switch (menu())
        {
        case 1:
            altaEmpleado(gente, TAM);
            system("pause");
            break;
        case 2:
            bajaEmpleado(gente, TAM);
            system("pause");
            break;
        case 3:
            printf("Modificacion\n");
            system("pause");
            break;
        case 4:
            mostrarEmpleados(gente, TAM);
            system("pause");
            break;
        case 5:
            printf("Ordenar\n");
            system("pause");
            break;
        case 6:
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



