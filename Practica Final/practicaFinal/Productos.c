#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

eProducto* newProducto(void)
{
    eProducto* nuevoElemento;

    nuevoElemento = (eProducto*) malloc(sizeof(eProducto));

    if (nuevoElemento != NULL)
    {
        nuevoElemento->id = 0;
        strcpy(nuevoElemento->descripcion,"");
        nuevoElemento->cantidad = 0;
    }
    return nuevoElemento;
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

int getId(eProducto* elemento)
{
    int id = -1;

    if (elemento != NULL)
    {
        id = elemento->id;
    }
    return id;
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

int moverElemento (ArrayList* lista0, ArrayList* lista1)
{
    int status = -1;
    int listaOrigen = -1;
    int listaDestino = -1;
    int auxId = -1;
    int i;
    ArrayList* auxLista;
    eProducto* auxElemento;

    if (lista0 != NULL && lista1 != NULL)
    {
        auxLista = al_newArrayList();
        auxElemento = newProducto();

        if (auxLista != NULL && auxElemento != NULL)
        {
            printf("--- MOVER PRODUCTOS A DEPOSITO ---\n");

            printf("Seleccione deposito de origen: ");
            listaOrigen = subMenu();

            if (listaOrigen == 1)
            {
                auxLista = lista0;
            }
            else
            {
                auxLista = lista1;
            }
            mostrarElementos(auxLista);
            printf("Ingrese Id del elemento a mover: ");
            scanf("%d", &auxId);
            for (i=0 ; i<(auxLista->len(auxLista)) ; i++)
            {
                if (auxId == getId(auxLista))
                {
                    auxElemento = auxLista->get(auxLista, i);
                    auxLista->remove(auxLista, i);
                    break;
                }
                else
                {
                    printf("El elemento ingresado no existe.\n\n");
                    system("Pause");
                    exit(-2);
                }
            }

            printf("Seleccione deposito de destino: ");
            listaDestino = subMenu();
            if (listaDestino == 1)
            {
                auxLista = lista0;
            }
            else
            {
                auxLista = lista1;
            }
            auxLista->add(auxLista, auxElemento);
        }
    }
    else
    {
        printf("Error al mover elemento.\n\n");
        system ("Pause");
    }
    return status;
}
