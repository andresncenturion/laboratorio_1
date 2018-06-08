#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

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
    Employee* aux;
    Employee* miEmpleado;
    Employee* otroEmpleado;

    listaEmpleados = al_newArrayList();

    miEmpleado = (Employee*) malloc(sizeof(Employee));//Esto va en el employee.c
    otroEmpleado = (Employee*) malloc(sizeof(Employee));

    //hacer lo siguiente con seters
    miEmpleado->id = 8;
    strcpy(miEmpleado->name, "Juan");
    strcpy(miEmpleado->lastName, "Gomez");
    miEmpleado->isEmpty = 1;
    int i;

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

    return 0;
}
