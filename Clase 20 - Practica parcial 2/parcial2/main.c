#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

typedef struct
{
    long int dni;
    int turno;
}eClient;

eClient* cl_newUrgent (void);
eClient* cl_newRegular (void);
int menu (void);
int contUrg = 2000;
int contReg = 10000;

int main()
{
    ArrayList* pUrgent;
    ArrayList* pRegular;
    ArrayList* atendidoUrgent;
    ArrayList* atendidoReg;
    char seguir = 's';
    eClient* auxCliente;


    pUrgent = al_newArrayList();
    pRegular = al_newArrayList();
    atendidoUrgent = al_newArrayList();
    atendidoReg = al_newArrayList();

    while (seguir == 's')
    {
        switch (menu())
        {
        case 1:
            pUrgent->add(pUrgent, cl_newUrgent());
            printf("Su turno es el: %d", contUrg);
            system("Pause");
            break;
        case 2:
            pRegular->add(pRegular, cl_newRegular());
            printf("Su turno es el: %d", contReg);
            system("Pause");
            break;
        case 3:
            if (pUrgent->isEmpty() != 1)
            {
                auxCliente = (eClient*) pUrgent->pop(pUrgent->pElements, 0);
                printf("--- PROXIMO TURNO ---\n\n");
                printf("Turno: %d\n", auxCliente->turno);
                printf("DNI: %ld\n\n", auxCliente->dni);
                atendidoUrgent->add(atendidoUrgent, &auxCliente);
            }
            else
            {
                auxCliente = (eClient*) pRegular->pop(pRegular->pElements, 0);
                printf("--- PROXIMO TURNO ---\n\n");
                printf("Turno: %d\n", auxCliente->turno);
                printf("DNI: %ld\n\n", auxCliente->dni);
                atendidoReg->add(atendidoReg, &auxCliente);
            }
        case 4:

            system ("Pause");
            break;
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
        newUrg->turno = contUrg;
        contUrg++;
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
        newReg->turno = contReg;
        contReg++;
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

