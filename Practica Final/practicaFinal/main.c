#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Productos.h"

#define PATH0 "dep0.csv"
#define PATH1 "dep1.csv"

int main()
{
    ArrayList* depositoCero;
    ArrayList* depositoUno;
    char seguir = 's';

    depositoCero = al_newArrayList();
    depositoUno = al_newArrayList();

    if (depositoCero != NULL && depositoUno != NULL)
    {
        while (seguir == 's')
        {
            switch(menu())
            {
            case 1:
                parseArchivo(PATH0, depositoCero);
                parseArchivo(PATH1, depositoUno);
                printf("Depositos cargados.\n\n");
                system("Pause");
                break;
            case 2:
                listarElementos(depositoCero, depositoUno);
                system("Pause");
                break;
            case 3:
                moverElemento(depositoCero, depositoUno);
                break;
            case 4:
                descontarProductos(depositoCero, depositoUno);
                break;
            case 5:
                sumarProductos(depositoCero, depositoUno);
                break;
            case 6:
                seguir = 'n';
                break;
            default:
                printf("Error. La opcion ingresada no es valida. Intente nuevamente.\n\n");
                system("Pause");
                break;
            }
        }
    }
    else
    {
        printf("ERROR. No se consiguio espacio en memoria.\n\n");
    }

    return 0;
}
