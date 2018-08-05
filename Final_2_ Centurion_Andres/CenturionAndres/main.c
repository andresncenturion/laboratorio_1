#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "llamadas.h"

int main()
{
    char seguir = 's';
    ArrayList* llamadas;
    ArrayList* filtrada;

    llamadas = al_newArrayList();
    filtrada = al_newArrayList();

    if (llamadas != NULL)
    {
        while (seguir == 's')
        {
            switch (menu())
            {
            case 1:
                parseArchivo(llamadas);
                system("Pause");
                break;
            case 2:
                imprimirLlamadas(llamadas);
                system("Pause");
                break;
            case 3:
                imprimirEstadistica(llamadas);
                system("Pause");
                break;
            case 4:
                generarArchivo(llamadas, filtrada);
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
