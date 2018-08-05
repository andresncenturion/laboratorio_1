#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "llamadas.h"

int menu(void)
{
    int opcion;

    system ("cls");
    printf("--- SELECCIONE OPCION DESEADA ---\n\n");
    printf("1- Cargar archivo\n");
    printf("2- Imprimir llamadas\n");
    printf("3- Imprimir estadistica\n");
    printf("4- Generar archivos de clientes\n");
    printf("5- Salir\n");
    printf("\n");

    scanf("%d",&opcion);

    return opcion;
}

eLlamada* newLlamada(void)
{
    eLlamada* nuevoElemento;

    nuevoElemento = (eLlamada*) malloc(sizeof(eLlamada));

    if (nuevoElemento != NULL)
    {
        nuevoElemento->id = 0;
        strcpy(nuevoElemento->nombre,"");
        strcpy(nuevoElemento->email,"");
        nuevoElemento->dni = 0;
        strcpy(nuevoElemento->id_producto,"");
        strcpy(nuevoElemento->observaciones,"");
    }
    return nuevoElemento;
}

int setId(eLlamada* aux, int buffer)
{
    int status = -1;

    if (aux != NULL)
    {
        status = 1;
        aux->id = buffer;
    }
    return status;
}

int setNombre(eLlamada* aux, char* buffer)
{
    int status = -1;

    if (aux != NULL)
    {
        status = 1;
        strcpy(aux->nombre, buffer);
    }
    return status;
}

char* getNombre(eLlamada* elemento)
{
    char* nombre = NULL;

    nombre = (char*) malloc(sizeof(char)*50);

    if(elemento != NULL)
    {
        strcpy(nombre, elemento->nombre);
    }
    return nombre;
}

int setEmail(eLlamada* aux, char* buffer)
{
    int status = -1;

    if (aux != NULL)
    {
        status = 1;
        strcpy(aux->email, buffer);
    }
    return status;
}

char* getEmail (eLlamada* elemento)
{
    char* email = NULL;

    email = (char*) malloc(sizeof(char)*50);

    if(elemento != NULL)
    {
        strcpy(email, elemento->email);
    }
    return email;
}

int setDni(eLlamada* aux, int buffer)
{
    int status = -1;

    if (aux != NULL)
    {
        status = 1;
        aux->dni = buffer;
    }
    return status;
}

int getDni(eLlamada* elemento)
{
    int dni = -1;

    if (elemento != NULL)
    {
        dni = elemento->dni;
    }
    return dni;
}

int setId_Producto(eLlamada* aux, char* buffer)
{
    int status = -1;

    if (aux != NULL)
    {
        status = 1;
        strcpy(aux->id_producto, buffer);
    }
    return status;
}

char* getProducto(eLlamada* elemento)
{
    char* producto = NULL;

    producto = (char*) malloc(sizeof(char)*50);

    if(elemento != NULL)
    {
        strcpy(producto, elemento->id_producto);
    }
    return producto;
}

int setObservaciones(eLlamada* aux, char* buffer)
{
    int status = -1;

    if (aux != NULL)
    {
        status = 1;
        strcpy(aux->observaciones, buffer);
    }
    return status;
}

int parseArchivo(ArrayList* lista)
{
    int status = -1;
    FILE* f;
    int cant = 0;
    char path[20];
    char bufferId[4];
    char bufferNombre[50];
    char bufferEmail[50];
    char bufferDni[20];
    char bufferIdProducto[50];
    char bufferObservaciones[512];
    eLlamada* aux;

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
            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferEmail, bufferDni, bufferIdProducto, bufferObservaciones);
            aux = newLlamada();
            if (cant != 6)
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
            setNombre(aux, bufferNombre);
            setEmail(aux, bufferEmail);
            setDni(aux, atoi(bufferDni));
            setId_Producto (aux, bufferIdProducto);
            setObservaciones (aux, bufferObservaciones);
            lista->add(lista, aux);
            }
    }
    fclose(f);
    return status;
}

void mostrarElemento(eLlamada* unElemento)
{
    printf("%d  %s  %s  %d  %s  %s", unElemento->id, unElemento->nombre, unElemento->email, unElemento->dni, unElemento->id_producto, unElemento->observaciones);
    printf("\n");
}

void imprimirLlamadas(ArrayList* lista)
{
    eLlamada* unElemento;
    int i;

    printf("--- IMPRIMIR LLAMADAS ---\n\n");

    if (lista != NULL)
    {
        printf("ID                                              NOMBRE                                               EMAIL                                                 DNI                                         ID PRODUCTO                                       OBSERVACIONES\n\n");
        for (i=0 ; i<(lista->len(lista)) ; i++)
        {
            unElemento = lista->get(lista, i);
            mostrarElemento(unElemento);
        }
    }
}

int buscarDni(ArrayList* llamadas, int auxDni)
{
    int cont = 0;
    int i;
    int tam;
    eLlamada* aux;

    if (llamadas != NULL)
    {
        tam = llamadas->len(llamadas);
        for (i=0 ; i<tam ; i++)
        {
            aux = llamadas->get(llamadas, i);
            if (aux->dni == auxDni)
            {
                cont++;
            }
        }
    }
    return cont;
}

int buscarProducto(ArrayList* llamadas, char* auxProducto)
{
    int cont = 0;
    int i;
    int tam;
    eLlamada* aux;

    if (llamadas != NULL)
    {
        tam = llamadas->len(llamadas);
        for (i=0 ; i<tam ; i++)
        {
            aux = llamadas->get(llamadas, i);
            if (strcmp(aux->id_producto, auxProducto) == 0)
            {
                cont++;
            }
        }
    }
    return cont;
}

void imprimirEstadistica(ArrayList* llamadas)
{
    int i;
    int tam;
    int index;
    int auxDni = -1;
    int cont = 0;
    int flagCont = 0;
    int contAux = 0;
    char* auxProducto;
    eLlamada* aux;

    if (llamadas != NULL)
    {
        aux = newLlamada();
        tam = llamadas->len(llamadas);

        for (i=0 ; i<tam ; i++)
        {
            aux = llamadas->get(llamadas, i);
            auxDni = getDni(aux);
            contAux = buscarDni(llamadas, auxDni);
            if (contAux > cont || flagCont == 0)
            {
                flagCont = 1;
                cont = contAux;
                index = i;
            }
        }
    }

    aux = llamadas->get(llamadas, index);
    printf("--- CLIENTE CON MAS LLAMADOS ---\n\n");
    printf("NOMBRE  DNI\n");
    printf("%6s  %d", getNombre(aux), getDni(aux));

    system("Pause");

    flagCont = 0;
    contAux = 0;
    cont = 0;
    index = -1;
    auxProducto = (char*) malloc(sizeof(char));
    for(i=0 ; i<tam ; i++)
    {
        aux = llamadas->get(llamadas, i);
        strcpy(auxProducto, getProducto(aux));
        contAux = buscarProducto(llamadas, auxProducto);
        if (contAux > cont || flagCont == 0)
            {
                flagCont = 1;
                cont = contAux;
                index = i;
            }
    }
    aux = llamadas->get(llamadas, index);
    printf("--- PRODUCTO MAS CONSULTADO ---\n\n");
    printf("%s", getProducto(aux));
    system("Pause");
}

int filtrarDni(ArrayList* filtrada, int auxDni)
{
    int existe = -1;
    int i;
    int tam;
    eLlamada* aux;

    if (filtrada != NULL)
    {
        existe = 0;
        tam = filtrada->len(filtrada);
        aux = newLlamada();
        for (i=0 ; i<tam ; i++)
        {
            aux = filtrada->get(filtrada, i);
            if (auxDni == getDni(aux))
            {
                existe = 1;
            }
        }
    }
    return existe;
}

void filtrarLista (ArrayList* llamadas, ArrayList* filtrada)
{
    int i;
    int tam;
    int auxDni = -1;
    int existe = -1;
    eLlamada* aux;

    if (llamadas != NULL && filtrada != NULL)
    {
        aux = newLlamada();
        tam = llamadas->len(llamadas);
        for (i=0 ; i<tam ; i++)
        {
            aux = llamadas->get(llamadas, i);
            auxDni = getDni(aux);
            existe = filtrarDni(filtrada, auxDni);
            if (existe == 0)
            {
                filtrada->add(filtrada, aux);
            }
        }
    }
}

int generarArchivo(ArrayList* llamadas, ArrayList* filtrada)
{
    int status = -1;
    int i;
    int tam;
    FILE* f;
    eLlamada* aux;

    if(llamadas != NULL && filtrada != NULL)
    {
        f = fopen("clientes.csv", "w");

        if(f != NULL)
        {
            status = 0;
            filtrada->clear(filtrada);

            filtrarLista(llamadas, filtrada);
            tam = filtrada->len(filtrada);
            for(i=0 ; i<tam ; i++)
            {
                aux = filtrada->get(filtrada, i);
                fprintf(f,"%d,", getDni(aux));
                fprintf(f,"%s,", getNombre(aux));
                fprintf(f,"%s\n", getEmail(aux));
            }
        }
        fclose(f);
    }
    return status;
}
