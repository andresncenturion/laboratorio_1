#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Empleados.h"

#define PATH "data.csv"

eEmpleado* newEmpleado (void)
{
    eEmpleado* nuevoEmpleado;

    nuevoEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));

    if (nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre,"");
        strcpy(nuevoEmpleado->direccion,"");
        nuevoEmpleado->horas = 0;
        nuevoEmpleado->sueldo = 0;
    }
    return nuevoEmpleado;
}

int setId(eEmpleado* auxEmpleado, int bufferId)
{
    int status = -1;

    if (auxEmpleado != NULL)
    {
        status = 1;
        auxEmpleado->id = bufferId;
    }
    return status;
}

int setNombre(eEmpleado* auxEmpleado, char* bufferNombre)
{
    int status = -1;

    if (auxEmpleado != NULL)
    {
        status = 1;
        strcpy(auxEmpleado->nombre, bufferNombre);
    }
    return status;
}

int setDireccion(eEmpleado* auxEmpleado, char* bufferDireccion)
{
    int status = -1;

    if (auxEmpleado != NULL)
    {
        status = 1;
        strcpy(auxEmpleado->direccion, bufferDireccion);
    }
    return status;
}

int setSueldo(eEmpleado* auxEmpleado, float sueldo)
{
    int status = -1;

    if (auxEmpleado != NULL)
    {
        status = 1;
        auxEmpleado->sueldo = sueldo;
    }
    return status;
}

int setHoras(eEmpleado* auxEmpleado, int bufferHoras)
{
    int status = -1;

    if (auxEmpleado != NULL)
    {
        status = 1;
        auxEmpleado->horas = bufferHoras;
    }
    return status;
}

int getId(eEmpleado* empleado)
{
    int id = -1;

    if (empleado != NULL)
    {
        id = empleado->id;
    }
    return id;
}

char* getNombre(eEmpleado* empleado)
{
    char* nombre = NULL;

    nombre = (char*) malloc(sizeof(char)*20);

    if (empleado != NULL)
    {
        strcpy(nombre, empleado->nombre);
    }
    return nombre;
}

char* getDireccion(eEmpleado* empleado)
{
    char* direccion = NULL;

    direccion = (char*) malloc(sizeof(char)*20);

    if(empleado != NULL)
    {
        strcpy(direccion, empleado->direccion);
    }
    return direccion;
}

int getHoras(eEmpleado* empleado)
{
    int horas = -1;

    if (empleado != NULL)
    {
        horas = empleado->horas;
    }
    return horas;
}

float getSueldo(eEmpleado* empleado)
{
    float sueldo;

    if (empleado != NULL)
    {
        sueldo = empleado->sueldo;
    }
    return sueldo;
}

int parseEmpleados(char* path, ArrayList* listaEmpleados)
{
    int status = -1;
    FILE* f;
    int cant = 0;
    char bufferId[10];
    char bufferNombre[20];
    char bufferDireccion[20];
    char bufferHoras[20];
    eEmpleado* auxEmpleado;

    if (listaEmpleados != NULL)
    {
        f = fopen(path, "r");
        if (f == NULL)
        {
            printf("Error al abrir el archivo data.csv");
            system("Pause");
            exit(-2);
        }
        status = 0;
        while (!feof(f))
        {
            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferDireccion, bufferHoras);
            auxEmpleado = newEmpleado();
            if (cant != 4)
            {
                if (feof(f))
                {
                    status = 1;
                    printf("Parseo exitoso");
                    break;
                }
                else
                {
                    printf("Error al leer el archivo data.csv");
                    status = -3;
                }
            }
            setId(auxEmpleado, atoi(bufferId));
            setNombre(auxEmpleado, bufferNombre);
            setDireccion(auxEmpleado, bufferDireccion);
            setHoras(auxEmpleado, atoi(bufferHoras))    ;
            listaEmpleados->add(listaEmpleados, auxEmpleado);
            }
    }
    fclose(f);
    return status;
}

void mostrarEmpleado(eEmpleado* unEmpleado)
{
    printf("%d\t%s\t%s\t%d\n", unEmpleado->id, unEmpleado->nombre, unEmpleado->direccion, unEmpleado->horas);
}

void mostrarEmpleados(ArrayList* listaEmpleados)
{
    eEmpleado* unEmpleado;
    int tam;
    int i;

    tam = listaEmpleados->len(listaEmpleados);
    printf("ID\tNOMBRE\tDIRECCION\tHORAS\n\n");
    for (i=0 ; i<tam ; i++)
    {
        unEmpleado = listaEmpleados->get(listaEmpleados, i);
        mostrarEmpleado(unEmpleado);
    }
}

int listarOrdenados (void* empleado1, void* empleado2)
{
    int status = 0;

    if(strcmp(((eEmpleado*)empleado1)->nombre, ((eEmpleado*)empleado2)->nombre) < 0)
    {
        status = 1;
    }
    if(strcmp(((eEmpleado*)empleado1)->nombre, ((eEmpleado*)empleado2)->nombre) > 0)
    {
        status =  -1;
    }
    return status;
}

int calcularSueldos (void* empleado)
{
    int status = -1;
    int horas;
    float sueldo;

    horas = getHoras(empleado);

    if (horas > 0 && horas <= 240)
    {
        status = 0;
        if (horas <= 120)
        {
            sueldo = horas*180;
        }
        else if (horas <= 160)
        {
            sueldo = (horas-120)*240+120*180;
        }
        else
        {
            sueldo = (horas-160)*350+120*180+40*240;
        }
        setSueldo(empleado, sueldo);
    }
    return status;
}

int filtrarSueldos (void* elemento)
{
    int status = -1;
    int horas;

    horas = getHoras(elemento);
    if (horas >= 120)
    {
        status = 1;
    }
    return status;
}

int generarArchivo(ArrayList* listaEmpleados, char* path)
{
    int status = -1;
    FILE* f;
    eEmpleado* auxEmpleado;
    int i;
    int tam = al_len(listaEmpleados);

    if(listaEmpleados != NULL)
    {
        f = fopen(path, "w");

        if(f != NULL)
        {
            status = 0;
            for(i=0 ; i<tam ; i++)
            {
                auxEmpleado = listaEmpleados->get(listaEmpleados, i);
                fprintf(f,"%d,", getId(auxEmpleado));
                fprintf(f,"%s,", getNombre(auxEmpleado));
                fprintf(f,"%s,", getDireccion(auxEmpleado));
                fprintf(f,"%d,", getHoras(auxEmpleado));
                fprintf(f,"%f\n", getSueldo(auxEmpleado));
            }
        }
        fclose(f);
    }
    return status;
}
