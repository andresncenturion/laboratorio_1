#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    int edad;
    long int dni;
    int estado;
}EPersona;

void agregarPersona(EPersona*, EPersona*, int);
void mostrarPlantel(EPersona*, int);

int main()
{
    EPersona nuevaPersona;
    EPersona plantel[5];

    agregarPersona(&plantel, &nuevaPersona, 5);
    mostrarPlantel(&plantel,5);

    return 0;
}

void agregarPersona(EPersona* pPlantel, EPersona* pPersona, int 5)
{
    pPersona->estado = 1;
    printf("Nombre: ");
    scanf("%s", pPersona->nombre);
    printf("Edad: ");
    scanf("%d", pPersona->edad);
    printf("DNI: ");
    scanf("%ld", pPersona->dni);

    pPlantel[0] = pPersona;
}

void mostrarPlantel(EPersona* pPlantel, int 5)
{
    int i;

    for (i=0 ; i<5 ; i++)
    {
        printf("%d  %s  %d  %ld", (pPlantel+i)->estado, (pPlantel+i)->nombre, (pPlantel+i)->edad, (pPlantel+i)->dni);
    }
}

