#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    return 0;
}


void employee_print(Employee* this)
{
    printf("%d  %s  %s  %d\n", this->id, this->name, this->lastName, this->isEmpty);
}

void listarEmployees (ArrayList* pArrayList, int tam)
{
    int i;

    for (i=0 ; i<tam ; i++)
    {
        employee_print(pArrayList+i);
    }
    printf("\n\n");
}

Employee* employee_new(void)
{
    Employee* empleado;

    empleado = (Employee*) malloc(sizeof(Employee));

    employee_setId(empleado, 0);
    strcpy(empleado->name, "");
    strcpy(empleado->lastName, "");
    empleado->isEmpty = -1;

    return empleado;
}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{
    this->id = 0;
    return 0;
}

int employee_getId(Employee* this)
{

    return 0;

}


