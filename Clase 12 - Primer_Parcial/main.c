#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    eProveedor proveedores[] = {{1, "arcor"}, {2, "bagley"}, {3, "nestle"}, {4, "terrabusi"}, {5, "pepsico"}};
    eProducto productos[] = {{1, "cafe", 45.00, 15, 1, 1}, {2, "chocolate", 27.00, 20, 1, 1}, {3, "galletitas", 15.00, 46, 1, 3}, {4, "alfajor", 20.00, 50, 1, 5}, {5, "bizcochitos", 12.00, 46, 1, 4}};
    int salir = 0;
    int i;

    incializarProductos(productos, 5);

    for(i=0; i< 5; i++)
    {
        productos[i].estado = 1;
    }

    do
    {
        switch (menu())
        {
        case 1:
            altaProducto(productos, 5, proveedores, 5);
            system("pause");
            break;
        case 2:
            modificarProducto(productos, 5, proveedores, 5);
            system("pause");
            break;
        case 3:
            bajaProducto(productos, 5, proveedores, 5);
            system("pause");
            break;
        case 4:
            informar(productos, 5, proveedores, 5);
            system("pause");
            break;
        case 5:
            listar(productos, 5, proveedores, 5);
            system("pause");
            break;
        case 6:
            printf("\nSalir\n\n");
            salir = 1;
            break;
        default:
            printf("\nLa opcion ingresada no es valida.\n\n");
            break;
        }
    }while (salir !=1);
    return 0;
}
