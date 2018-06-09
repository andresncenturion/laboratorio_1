#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

#define PATH "data.csv"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    ArrayList* listaEmpleados;//puntero apuntando a cualquier lado
    //Employee* aux;
    //Employee* miEmpleado;
    //Employee* otroEmpleado;
    FILE* pFile;
    int opcion;
    char seguir = 's';

    listaEmpleados = al_newArrayList();
    pFile = fopen(PATH, "w");

    while (seguir == 's')
    {
        printf("Seleccione la opcion deseada: \n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            parserEmployee(pFile , listaEmpleados);
            system ("Pause");
            break;
        case 2:
            listarEmployees(listaEmpleados, sizeof(listaEmpleados));
            system("Pause");
            break;
        case 7:
            seguir = 'n';
            break;
        default:
            printf("La opcion ingresada no es valida.\n\n");
            system("Pause");
            break;
        }

        /*int i;

        al_add(listaEmpleados, miEmpleado);

        aux = (Employee*) al_get(listaEmpleados, 0);//Lo casteo con puntero a Employee

        printf("%d------%s\n", aux->id, aux->name);//tambien con seters, a veces no se ven los campos pero es normal

        printf("%d\n", al_len(listaEmpleados));


        otroEmpleado->id = 9;
        strcpy(otroEmpleado->name, "Ana");
        strcpy(otroEmpleado->lastName, "Ruiz");
        otroEmpleado->isEmpty = 1;

        al_add(listaEmpleados, otroEmpleado);

        for(i=0;i<al_len(listaEmpleados);i++)
        {
            aux = (Employee*) al_get(listaEmpleados, i);
            printf("%d------%s\n", aux->id, aux->name);

        }


        //Paso una funcion con el ordenamiento a la funcion sort mediante un puntero de funcion, eso se llama delegamiento
        */
    }

    return 0;
}
