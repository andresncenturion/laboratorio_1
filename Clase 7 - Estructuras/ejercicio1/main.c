#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    eEmpleado unEmpleado;
    eEmpleado plantel[4];
    int i = 0;

    //unEmpleado = pedirEmpleado(unEmpleado);
    //mostrarEmpleado(unEmpleado);
    for (i=0 ; i<4 ; i++)
    {
        plantel[i] = pedirEmpleado(unEmpleado);
    }
    mostrarEmpleados(plantel, 4);

    return 0;
}
