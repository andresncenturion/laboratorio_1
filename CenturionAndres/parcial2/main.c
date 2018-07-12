#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Empleados.h"

#define PATH "data.csv"

int main()
{
    ArrayList* listaEmpleados;
    ArrayList* listaFiltrada;

    listaEmpleados = al_newArrayList();
    listaFiltrada = al_newArrayList();

    if (listaEmpleados != NULL)
    {
        //1
        parseEmpleados(PATH, listaEmpleados);
        mostrarEmpleados(listaEmpleados);
        system("Pause");
        //2
        if ((listaEmpleados->isEmpty(listaEmpleados)) != 1)
        {
            listaEmpleados->sort(listaEmpleados, listarOrdenados, 0);
        }
        mostrarEmpleados(listaEmpleados);
        system("Pause");
        //3
        listaEmpleados->map(listaEmpleados, calcularSueldos);
        mostrarEmpleados(listaEmpleados);
        system("Pause");
        //4
        listaFiltrada = listaEmpleados->filter(listaEmpleados, filtrarSueldos);
        //5
        generarArchivo(listaFiltrada, "datosCalculados.csv");
    }
    else
    {
        printf("Error. No se han cargado datos.\n\n");
    }
    return 0;
}
