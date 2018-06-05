#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    int estado;

} eEmpleado;

void mostrarEmpleados(eEmpleado*, int);
void mostrarEmpleado(eEmpleado*);
eEmpleado* new_Empleado();
eEmpleado* new_Empleado_Param(int, char*, float);
void guardarEmpleados(eEmpleado*, int, char*);
int buscarLibre(eEmpleado*, int);
int cargarEmpleados(eEmpleado*, int, char*);
void inicializarEmpleados(eEmpleado*, int);
eEmpleado* newArrayEmpleados(int);

int main()
{
    eEmpleado* personal;
    eEmpleado* unEmpleado;
    int cantidad;

    personal = newArrayEmpleados(TAM);

    if(personal == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        exit(1);
    }

  /*  unEmpleado = new_Empleado_Param(1111, "Juan", 10000);

    *personal = *unEmpleado;

    unEmpleado = new_Empleado_Param(2222, "Ana", 25000);

    *(personal+1) = *unEmpleado;

    unEmpleado = new_Empleado_Param(3333, "Julieta", 20000);

    *(personal+2) = *unEmpleado;

    mostrarEmpleados(personal, TAM);

    guardarEmpleados(personal, TAM, "listaEmpleados.bin");*/

  cantidad = cargarEmpleados(personal, TAM, "listaEmpleados.bin");

    printf("Se cargaron %d empleados\n", cantidad);

    mostrarEmpleados(personal, TAM);



    return 0;
}


void mostrarEmpleado(eEmpleado* empleado)
{
    if(empleado != NULL)
    {
        printf("%d %s %.2f\n", empleado->legajo, empleado->nombre, empleado->sueldo);
    }
}

void mostrarEmpleados(eEmpleado* empleados, int tam)
{

    if(empleados != NULL && tam > 0)
    {
        for(int i=0; i< tam; i++)
        {

            if((empleados+ i)->estado)
            {
                mostrarEmpleado(empleados+i);
            }
        }
    }
    else
    {
        printf("\nNo se pueden mostrar los empleados\n");
    }

}

eEmpleado* new_Empleado()
{

    eEmpleado* nuevoEmpleado;

    nuevoEmpleado = (eEmpleado*)malloc(sizeof(eEmpleado));
    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->legajo = 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->sueldo = 0;
        nuevoEmpleado->estado = 0;
    }
    return nuevoEmpleado;

}



eEmpleado* new_Empleado_Param(int legajo, char* nombre, float sueldo)
{

    eEmpleado* nuevoEmpleado;

    nuevoEmpleado = new_Empleado();

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->legajo = legajo;
        strcpy(nuevoEmpleado->nombre, nombre);
        nuevoEmpleado->sueldo = sueldo;
        nuevoEmpleado->estado = 1;
    }
    return nuevoEmpleado;

}

void guardarEmpleados(eEmpleado* empleados, int tam, char* path)
{

    FILE* f;

    f = fopen(path, "wb");

    if(f != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if( (empleados + i)->estado)
            {
                fwrite( (empleados+i), sizeof(eEmpleado), 1, f);
            }
        }
        fclose(f);
    }
}

int cargarEmpleados(eEmpleado* empleados, int tam, char* path)
{

    FILE* f;
    int indice;
    eEmpleado empleadoAuxiliar;
    int cant;
    int total = 0;

    f = fopen(path, "rb");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    while(!feof(f))
    {
        indice = buscarLibre(empleados, tam);
        if(indice == -1)
        {
            printf("No hay mas lugar\n");
            break;
        }
        else
        {
            cant = fread(&empleadoAuxiliar, sizeof(eEmpleado), 1, f);

            if(cant != 1)
            {
                if(feof(f))
                {
                    break;
                }
                else
                {
                    printf("No se pudo leer el ultimo registro\n");
                    break;
                }
            }

            *(empleados+indice) = empleadoAuxiliar;
            total++;
            //indice = buscarLibre(empleados, tam);

        }
    }
    fclose(f);
    return total;
}

int buscarLibre(eEmpleado* empleados, int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if((empleados+i)->estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void inicializarEmpleados(eEmpleado* empleados, int tam)
{

    if(empleados != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            (empleados+i)->estado = 0;
        }
    }
}

eEmpleado* newArrayEmpleados(int tam)
{

    eEmpleado* array;

    if(tam > 0)
    {
        array = (eEmpleado*) malloc(tam * sizeof(eEmpleado));

        if(array != NULL)
        {
            inicializarEmpleados(array, tam);
        }
    }
    return array;
}


