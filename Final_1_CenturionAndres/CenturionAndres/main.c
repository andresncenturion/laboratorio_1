#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Reparto.h"

int main()
{
    char seguir = 's';
    ArrayList* productos;
    ArrayList* localidades;

    productos = al_newArrayList();
    localidades = al_newArrayList();

    if (productos != NULL && localidades != NULL)
    {
        while (seguir == 's')
        {
            switch (menu())
            {
            case 1:
                parseArchivo(productos);
                system("Pause");
                break;
            case 2:
                imprimirEntregas(productos);
                system("Pause");
                break;
            case 3:
                imprimirLocalidades(productos, localidades);
                system("Pause");
                break;
            case 4:
                generarArchivo(productos, localidades);
                system("Pause");
                break;
            case 5:
                seguir = 'n';
                break;
            }
        }
    }

    return 0;
}
