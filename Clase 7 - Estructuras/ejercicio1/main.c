#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    eEmpleado unEmpleado;

    unEmpleado = pedirEmpleado(unEmpleado);
    mostrarEmpleado(unEmpleado);
    return 0;
}
