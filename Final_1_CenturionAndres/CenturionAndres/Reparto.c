#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Reparto.h"

int menu(void)
{
    int opcion;

    system ("cls");
    printf("--- SELECCIONE OPCION DESEADA ---\n\n");
    printf("1- Cargar archivo\n");
    printf("2- Imprimir entregas\n");
    printf("3- Imprimir localidades\n");
    printf("4- Generar archivos de reparto\n");
    printf("5- Salir\n");
    printf("\n");

    scanf("%d",&opcion);

    return opcion;
}

eReparto* newReparto(void)
{
    eReparto* nuevoElemento;

    nuevoElemento = (eReparto*) malloc(sizeof(eReparto));

    if (nuevoElemento != NULL)
    {
        nuevoElemento->id = 0;
        strcpy(nuevoElemento->producto,"");
        strcpy(nuevoElemento->direccion,"");
        strcpy(nuevoElemento->localidad,"");
        strcpy(nuevoElemento->recibe,"");
    }
    return nuevoElemento;
}

int setId(eReparto* aux, int buffer)
{
    int status = -1;

    if (aux != NULL)
    {
        status = 1;
        aux->id = buffer;
    }
    return status;
}

int getId(eReparto* elemento)
{
    int id = -1;

    if (elemento != NULL)
    {
        id = elemento->id;
    }
    return id;
}

int setProducto(eReparto* aux, char* buffer)
{
    int status = -1;

    if (aux != NULL)
    {
        status = 1;
        strcpy(aux->producto, buffer);
    }
    return status;
}

char* getProducto(eReparto* elemento)
{
    char* producto = NULL;

    producto = (char*) malloc(sizeof(char)*20);

    if(elemento != NULL)
    {
        strcpy(producto, elemento->producto);
    }
    return producto;
}

int setDireccion(eReparto* aux, char* buffer)
{
    int status = -1;

    if (aux != NULL)
    {
        status = 1;
        strcpy(aux->direccion, buffer);
    }
    return status;
}

char* getDireccion(eReparto* elemento)
{
    char* direccion = NULL;

    direccion = (char*) malloc(sizeof(char)*20);

    if(elemento != NULL)
    {
        strcpy(direccion, elemento->direccion);
    }
    return direccion;
}

int setLocalidad(eReparto* aux, char* buffer)
{
    int status = -1;

    if (aux != NULL)
    {
        status = 1;
        strcpy(aux->localidad, buffer);
    }
    return status;
}

char* getLocalidad(eReparto* elemento)
{
    char* localidad = NULL;

    localidad = (char*) malloc(sizeof(char)*20);

    if(elemento != NULL)
    {
        strcpy(localidad, elemento->localidad);
    }
    return localidad;
}

int setRecibe(eReparto* aux, char* buffer)
{
    int status = -1;

    if (aux != NULL)
    {
        status = 1;
        strcpy(aux->recibe, buffer);
    }
    return status;
}

char* getRecibe(eReparto* elemento)
{
    char* recibe = NULL;

    recibe = (char*) malloc(sizeof(char)*20);

    if(elemento != NULL)
    {
        strcpy(recibe, elemento->recibe);
    }
    return recibe;
}

int parseArchivo(ArrayList* lista)
{
    int status = -1;
    FILE* f;
    int cant = 0;
    char path[20];
    char bufferId[4];
    char bufferProducto[20];
    char bufferDireccion[20];
    char bufferLocalidad[20];
    char bufferRecibe[20];
    eReparto* aux;

    if (lista != NULL)
    {
        printf("Ingrese el nombre del archivo a cargar: ");
        fflush(stdin);
        gets(path);

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
            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferProducto, bufferDireccion, bufferLocalidad, bufferRecibe);
            aux = newReparto();
            if (cant != 5)
            {
                if (feof(f))
                {
                    status = 1;
                    break;
                }
                else
                {
                    printf("Error al leer archivo\n");
                    system("Pause");
                    status = -3;
                }
            }
            setId(aux, atoi(bufferId));
            setProducto(aux, bufferProducto);
            setDireccion(aux, bufferDireccion);
            setLocalidad(aux, bufferLocalidad);
            setRecibe(aux, bufferRecibe);
            lista->add(lista, aux);
            }
    }
    fclose(f);
    return status;
}

void mostrarElemento(eReparto* unElemento)
{
    printf("%2d  %20s  %20s  %20s  %20s", unElemento->id, unElemento->producto, unElemento->direccion, unElemento->localidad, unElemento->recibe);
    printf("\n");
}

void imprimirEntregas(ArrayList* lista)
{
    eReparto* unElemento;
    int i;

    printf("--- IMPRIMIR ENTREGAS ---\n\n");

    if (lista != NULL)
    {
        printf("ID              PRODUCTO             DIRECCION             LOCALIDAD                RECIBE\n\n");
        for (i=0 ; i<(lista->len(lista)) ; i++)
        {
            unElemento = lista->get(lista, i);
            mostrarElemento(unElemento);
        }
    }
}

int existeLocalidad(ArrayList* lista, char* localidad)
{
    int existe = -1;
    int i;

    if (lista != NULL && localidad != NULL)
        {
            existe = 0;
            for (i=0 ; i<lista->len(lista) ; i++)
                {
                    if (strcmp(*(lista->pElements+i), localidad) == 0)
                        {
                            existe = 1;
                            break;
                        }
                }
        }
    return existe;
}

void buscarLocalidades(ArrayList* productos, ArrayList* localidades)
{
    int tam;
    int i;
    int existe;
    eReparto* aux;
    char* auxLocalidad;

    if (productos != NULL && localidades != NULL)
    {
        aux = newReparto();
        tam = productos->len(productos);
        for (i=0 ; i<tam ; i++)
        {
            aux = productos->get(productos, i);
            auxLocalidad = getLocalidad(aux);
            existe = existeLocalidad(localidades, auxLocalidad);
            if (existe == 0)
            {
                localidades->add(localidades, auxLocalidad);
            }
        }
    }
}

void imprimirLocalidades (ArrayList* productos, ArrayList* localidades)
{
    int tam;
    int i;
    char* aux;

    if (productos != NULL && localidades != NULL)
    {
        buscarLocalidades(productos, localidades);

        printf("--- IMPRIMIR LOCALIDADES ---\n\n");
        tam = localidades->len(localidades);
        for (i=0 ; i<tam ; i++)
        {

            strcpy(aux, localidades->get(localidades, i));
            printf("%s\n", aux);
        }
    }
}

int filtrarLocalidades (ArrayList* productos, ArrayList* localidades, char* localidad)
{
    int status = -1;
    int i;
    int tam;
    eReparto* aux;

    if (productos != NULL && localidades != NULL && localidad != NULL)
    {
        status = 0;
        aux = newReparto();
        tam = productos->len(productos);
        for (i=0 ; i<tam ; i++)
        {
            aux = productos->get(productos, i);
            if(strcmp(aux->localidad, localidad) == 0)
            {
                status = 1;
                localidades->add(localidades, aux);
            }
        }
    }
    return status;
}

int generarArchivo(ArrayList* productos, ArrayList* localidades)
{
    int status = -1;
    int i;
    int tam;
    FILE* f;
    char* localidad;
    eReparto* aux;

    if(productos != NULL && localidades != NULL)
    {
        f = fopen("entregas.csv", "w");

        if(f != NULL)
        {
            status = 0;
            localidades->clear(localidades);
            for (i=1; i<4 ; i++)
            {
                printf("Ingrese localidad %d:", i);
                fflush(stdin);
                gets(localidad);
                filtrarLocalidades(productos, localidades, localidad);
            }

            tam = localidades->len(localidades);
            for(i=0 ; i<tam ; i++)
            {
                aux = localidades->get(localidades, i);
                fprintf(f,"%d,", getId(aux));
                fprintf(f,"%s,", getProducto(aux));
                fprintf(f,"%s,", getDireccion(aux));
                fprintf(f,"%s,", getLocalidad(aux));
                fprintf(f,"%s\n", getRecibe(aux));
            }
        }
        fclose(f);
    }
    return status;
}
