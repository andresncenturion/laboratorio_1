#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Productos.h"

int menu(void)
{
    int opcion;

    system ("cls");
    printf("--- SELECCIONE OPCION DESEADA ---\n\n");
    printf("1- Cargar depositos\n");
    printf("2- Listar productos de deposito\n");
    printf("3- Mover productos a deposito\n");
    printf("4- Descontar productos de deposito\n");
    printf("5- Agregar productos a deposito\n");
    printf("6- Salir\n");
    printf("\n");

    scanf("%d",&opcion);

    return opcion;
}

eProducto* newProducto (void)
{
    eProducto* nuevoProducto;

    nuevoProducto = (eProducto*) malloc(sizeof(eProducto));

    if (nuevoProducto != NULL)
    {
        nuevoProducto->id = 0;
        strcpy(nuevoProducto->descripcion, "");
        nuevoProducto->cantidad = 0;
    }
    return nuevoProducto;
}

int setId(eProducto* aux, int buffer)
{
    int status = -1;

    if (aux != NULL)
    {
        status = 1;
        aux->id = buffer;
    }
    return status;
}

int setDescripcion(eProducto* aux, char* buffer)
{
    int status = -1;

    if (aux != NULL)
    {
        status = 1;
        strcpy(aux->descripcion, buffer);
    }
    return status;
}

int setCantidad(eProducto* aux, int buffer)
{
    int status = -1;

    if (aux != NULL)
    {
        status = 1;
        aux->cantidad = buffer;
    }
    return status;
}

int parseArchivo(char* path, ArrayList* lista)
{
    int status = -1;
    FILE* f;
    int cant = 0;
    char bufferId[3];
    char bufferDescripcion[20];
    char bufferCantidad[4];
    eProducto* auxProducto;

    if (lista != NULL)
    {
        f = fopen(path, "r");
        if (f == NULL)
        {
            printf("Error al abrir archivo");
            system("Pause");
            exit(-2);
        }
        status = 0;
        while (!feof(f))
        {
            cant = fscanf(f, "%[^,],%[^,],%[^\n]\n", bufferId, bufferDescripcion, bufferCantidad);
            auxProducto = newProducto();
            if (cant != 3)
            {
                if (feof(f))
                {
                    status = 1;
                    printf("Parseo exitoso");
                    system("Pause");
                    break;
                }
                else
                {
                    printf("Error al leer archivo");
                    system("Pause");
                    status = -3;
                }
            }
            setId(auxProducto, atoi(bufferId));
            setDescripcion(auxProducto, bufferDescripcion);
            setCantidad(auxProducto, atoi(bufferCantidad));
            lista->add(lista, auxProducto);
            }
    }
    fclose(f);
    return status;
}

int subMenu (void)
{
    int opcion;

    printf("--- SELECCIONE DEPOSITO ---\n\n");
    printf("1. Deposito 1\n");
    printf("2. Deposito 2\n");
    printf("\n");
    scanf("%d", &opcion);
    while (opcion != 1 && opcion != 2)
    {
        printf("La opcion seleccionada no es valida. Intente nuevamente.\n\n");
        scanf("%d", &opcion);
    }
    return opcion;
}

void mostrarElemento(eProducto* unElemento)
{
    printf("%2d  %20s  %3d", unElemento->id, unElemento->descripcion, unElemento->cantidad);
    printf("\n");
}

void mostrarElementos(ArrayList* lista)
{
    eProducto* unElemento;
    int i;

    if (lista != NULL)
    {
        printf("ID           DESCRIPCION  CANTIDAD\n\n");
        for (i=0 ; i<(lista->len(lista)) ; i++)
        {
            unElemento = lista->get(lista, i);
            mostrarElemento(unElemento);
        }
    }
}

int moverElemento (ArrayList* lista0, ArrayList* lista1)
{
    int status = -1;
    int listaOrigen = -1;
    int listaDestino = -1;
    int auxId = -1;

    if (lista0 != NULL && lista1 != NULL)
    {
        printf("--- MOVER PRODUCTOS A DEPOSITO ---\n");
        printf("Seleccione deposito de origen: ");
        listaOrigen = subMenu();
        if (listaOrigen == 1)
        {
            mostrarElementos(lista0);
        }
        else
        {
            mostrarElementos(lista1);
        }
        printf("Ingrese Id del elemento a mover: ");
        scanf("%d", &auxId);

        printf("Seleccione deposito de destino: ");
        listaDestino = subMenu();

    }
    else
    {
        printf("Error al mover elemento.\n\n");
        system ("Pause");
    }
    return 0;
}
