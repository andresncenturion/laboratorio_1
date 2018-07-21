#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Productos.h"

#define PATH0 "dep0.csv"
#define PATH1 "dep1.csv"

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

char* getDescripcion(eProducto* elemento)
{
    char* descripcion = NULL;

    descripcion = (char*) malloc(sizeof(char)*20);

    if(elemento != NULL)
    {
        strcpy(descripcion, elemento->descripcion);
    }
    return descripcion;
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

int getCantidad(eProducto* elemento)
{
    int cant = -1;

    if (elemento != NULL)
    {
        cant = elemento->cantidad;
    }
    return cant;
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

int listarElementos (ArrayList* depositoCero, ArrayList* depositoUno)
{
    int status = -1;

    printf("--- LISTAR PRODUCTOS DE DEPOSITO ---\n\n");
    printf("Seleccione deposito a listar.\n\n");
    if (subMenu() == 1)
    {
        status = 0;
        mostrarElementos(depositoCero);
    }
    else
    {
        status = 1;
        mostrarElementos(depositoUno);
    }
    return status;
}


int moverElemento (ArrayList* lista0, ArrayList* lista1)
{
    int status = -1;
    int listaOrigen = -1;
    int listaDestino = -1;
    int auxId = -1;
    int i;
    int tam;
    ArrayList* auxLista;
    eProducto* auxElemento;

    if (lista0 != NULL && lista1 != NULL)
    {
        auxLista = al_newArrayList();
        auxElemento = newProducto();

        if (auxLista != NULL && auxElemento != NULL)
        {
            printf("--- MOVER PRODUCTOS A DEPOSITO ---\n");

            printf("Seleccione deposito de origen: \n");
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
            tam = auxLista->len(auxLista);
            for (i=0 ; i<tam ; i++)
            {
                auxElemento = auxLista->get(auxLista, i);
                if (auxId == getId(auxElemento))
                {
                    status = 1;
                    auxLista->remove(auxLista, i);
                    break;
                }
            }
            if (status != 1)
            {
                printf("El Id ingresado no existe.\n\n");
                exit(-1);
            }

            printf("Seleccione deposito de destino: \n");
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

    escribirArchivo(PATH0, lista0);
    escribirArchivo(PATH1, lista1);

    return status;
}

int buscarCodigo (ArrayList* lista, int Id)
{
    int index = -1;
    int tam;
    int i;
    eProducto* auxElemento;

    if (lista != NULL)
    {
        auxElemento = newProducto();
        if (auxElemento != NULL)
        {
            tam = lista->len(lista);
            for (i=0 ; i<tam ; i++)
            {
                auxElemento = lista->get(lista, i);
                if (Id == getId(auxElemento))
                {
                    index = i;
                    printf("Elemento hallado.\n");
                    break;
                }
            }
        }
    }
    return index;
}

int descontarProductos(ArrayList* lista0, ArrayList* lista1)
{
    int status = -1;
    int index = -1;
    int auxId;
    int cantidad;
    eProducto* auxElemento;
    ArrayList* auxLista;

    auxLista = al_newArrayList();
    auxElemento = newProducto();

    if (auxElemento != NULL && auxLista != NULL)
    {
        printf("--- DESCONTAR PRODUCTOS DE DEPOSITO ---\n\n");
        printf("Ingrese Id del producto a descontar: ");
        scanf("%d", &auxId);

        index = buscarCodigo (lista0, auxId);
        if (index != -1)
        {
            auxLista = lista0;
        }
        else
        {
            index = buscarCodigo(lista1, auxId);
            if (index != -1)
            {
                auxLista = lista1;
            }
            else
            {
                printf("El Id ingresado no existe en ningun deposito.\n\n");
                system("Pause");
                exit (-1);
            }
        }
        auxElemento = auxLista->get(auxLista, index);
        printf("Producto encontrado.\n\n");
        printf("ID           DESCRIPCION  CANTIDAD\n\n");
        mostrarElemento(auxElemento);
        printf("Ingrese cantidad a descontar: ");
        scanf("%d", &cantidad);
        while (cantidad > getCantidad(auxElemento))
        {
            printf("La cantidad ingresada es mayor que el stock. Intente nuevamente.\n");
            printf("Ingrese cantidad a descontar: ");
            scanf("%d", &cantidad);
        }
        if (cantidad <= getCantidad(auxElemento))
        {
            cantidad = getCantidad(auxElemento) - cantidad;
            setCantidad(auxElemento, cantidad);
            printf("Cantidad modificada exitosamente.\n\n");
        }
    }
    return status;
}

int sumarProductos(ArrayList* lista0, ArrayList* lista1)
{
    int status = -1;
    int index = -1;
    int auxId;
    int cantidad;
    eProducto* auxElemento;
    ArrayList* auxLista;

    auxLista = al_newArrayList();
    auxElemento = newProducto();

    if (auxElemento != NULL && auxLista != NULL)
    {
        printf("--- SUMAR PRODUCTOS DE DEPOSITO ---\n\n");
        printf("Ingrese Id del producto a sumar: ");
        scanf("%d", &auxId);

        index = buscarCodigo (lista0, auxId);
        if (index != -1)
        {
            auxLista = lista0;
        }
        else
        {
            index = buscarCodigo(lista1, auxId);
            if (index != -1)
            {
                auxLista = lista1;
            }
            else
            {
                printf("El Id ingresado no existe en ningun deposito.\n\n");
                system("Pause");
                exit (-1);
            }
        }
        auxElemento = auxLista->get(auxLista, index);
        printf("Producto encontrado.\n\n");
        printf("ID           DESCRIPCION  CANTIDAD\n\n");
        mostrarElemento(auxElemento);
        printf("Ingrese cantidad a sumar: ");
        scanf("%d", &cantidad);
            cantidad = getCantidad(auxElemento) - cantidad;
            setCantidad(auxElemento, cantidad);
            printf("Cantidad modificada exitosamente.\n\n");
    }
    return status;
}

int escribirArchivo(char* path, ArrayList* lista)
{
    int status = -1;
    FILE* f;
    eProducto* aux;
    int i;
    int tam;

    tam = lista->len(lista);
    if(lista != NULL)
    {
        f = fopen(path, "w");

        if(f != NULL)
        {
            status = 0;
            for(i=0 ; i<tam ; i++)
            {
                aux = lista->get(lista, i);
                fprintf(f,"%d,", getId(aux));
                fprintf(f,"%s,", getDescripcion(aux));
                fprintf(f,"%d\n", getCantidad(aux));
            }
        }
        fclose(f);
    }
    return status;
}

