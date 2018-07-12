#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Empleados.h"

#define PATH "data.csv"

int main()
{
    ArrayList* listaEmpleados;

    listaEmpleados = al_newArrayList();

    if (listaEmpleados != NULL)
    {
        //1
        parseEmpleados(PATH, listaEmpleados);
        system("Pause");
        //2
        if ((listaEmpleados->isEmpty(listaEmpleados)) != 1)
        {
            listaEmpleados->sort(listaEmpleados, listarOrdenados, 0);
        }
        mostrarEmpleados(listaEmpleados);
        system("Pause");
        //3
        map(listaEmpleados, calcularSueldos);
        mostrarEmpleados(listaEmpleados);
        system("Pause");
        //4
        generarArchivo(listaEmpleados, "sueldos.csv");
    }
    else
    {
        printf("Error. No se han cargado datos.\n\n");
    }
    return 0;
}
