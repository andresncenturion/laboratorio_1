#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

typedef struct
{
    long int dni;
    int operation;
}eClient;

eClient* cl_newUrgent (void);
eClient* cl_newRegular (void);
int menu (void);

int main()
{
    ArrayList* pUrgent;
    ArrayList* pRegular;
    char seguir = 's';
    int turno;

    pUrgent = al_newArrayList();
    pRegular = al_newArrayList();

    while (seguir == 's')
    {
        switch (menu())
        {
        case 1:
            pUrgent->add(pUrgent, cl_newUrgent());
            turno = (pUrgent->len(pUrgent))-1;
            printf("Su turno es el: %d",turno);
            system("Pause");
            break;
        case 2:
            pRegular->add(pRegular, cl_newRegular());
            turno = (pRegular->len(pRegular))-1;
            printf("Su turno es el: %d",turno);
            system("Pause");
            break;
        case 3:

        case 6:
            seguir = 'n';
            break;
        default:
            printf("La opcion ingresada no es valida. Intente nuevamente.\n\n");
            break;
        }
    }
    return 0;
}

eClient* cl_newUrgent (void)
{
    eClient* newUrg = NULL;

    newUrg = (eClient*) malloc(sizeof(eClient));
    if (newUrg != NULL)
    {
        printf("--- NUEVO TRAMITE URGENTE --- \n\n");
        printf("Ingrese DNI: ");
        scanf("%ld", &newUrg->dni);
        newUrg->operation = 1;
    }
    return newUrg;
}

eClient* cl_newRegular (void)
{
    eClient* newReg = NULL;

    newReg = (eClient*) malloc (sizeof(eClient));
    if (newReg != NULL)
    {
        printf("--- NUEVO TRAMITE REGULAR --- \n\n");
        printf("Ingrese DNI: ");
        scanf("%ld", &newReg->dni);
        newReg->operation = 2;
    }
    return newReg;
}

int menu (void)
{
    int opcion;

    system ("cls");
    printf("--- SELECCIONE LA OPCION DESEADA ---\n\n");
    printf("1. NUEVO TRAMITE URGENTE\n");
    printf("2. NUEVO TRAMITE REGULAR\n");
    printf("3. VER PROXIMO TURNO\n");
    printf("4. VER TURNOS PENDIENTES\n");
    printf("5. VER CLIENTES ATENDIDOS\n");
    printf("6. SALIR\n\n");

    scanf("%d", &opcion);

    return opcion;
}
