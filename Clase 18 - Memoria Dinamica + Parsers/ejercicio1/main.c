#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20

typedef struct
{
    int id;
    char marca[50];
    char modelo[50];
    char color[50];
    int anio;
    int estado;
} eAuto;

void inicializarAutos(eAuto*, int);
eAuto* newArrayAutos(int);
int buscarLibre(eAuto*, int);
int cargarAutos(eAuto*, int, char*);
void mostrarAuto(eAuto*);
void mostrarAutos(eAuto*, int);

int main()
{
    eAuto* unAuto;
    eAuto* arrayAutos;
    int cantidad;

    arrayAutos = newArrayAutos(TAM);

    if(arrayAutos == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        exit(1);
    }
    cantidad = cargarAutos(arrayAutos, TAM, "autos.csv");

    printf("Se cargaron %d autos.\n", cantidad);

    mostrarAutos(arrayAutos, TAM);

    return 0;
}

void inicializarAutos(eAuto* arrayAutos, int tam)
{

    if(arrayAutos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            (arrayAutos+i)->estado = 0;
        }
    }
}

eAuto* newArrayAutos(int tam)
{

    eAuto* array;

    if(tam > 0)
    {
        array = (eAuto*) malloc(tam * sizeof(eAuto));

        if(array != NULL)
        {
            inicializarAutos(array, tam);
        }
    }
    return array;
}

int buscarLibre(eAuto* arrayAutos, int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if((arrayAutos+i)->estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int cargarAutos(eAuto* arrayAutos, int tam, char* path)
{
    FILE* f;
    int indice;
    eAuto auto1;
    int cant;
    int total = 0;
    eAuto* arrayAux;
    int tamAux = tam;

    int id;
    char marca[50];
    char modelo[50];
    char color[50];
    char idCad[20];
    char anioCad[20];
    int anio;


    f = fopen(path, "r");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }
    while(!feof(f))
    {
        indice = buscarLibre(arrayAutos, tam);
        if(indice == -1)
        {
            tamAux += 20;
            arrayAux = realloc(arrayAutos, tamAux * sizeof(eAuto));
            if (arrayAux != NULL)
            {
                arrayAutos = arrayAux;
            }
            break;
        }
        else
        {
            cant = fscanf(f, "%[^,] , %[^,], %[^,] , %[^,], %[^\n] \n", idCad, marca, color, anioCad, modelo);

            if(cant != 5)
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

            id = atoi(idCad);
            anio = atoi(anioCad);

            auto1.id = id;
            auto1.anio = anio;
            strcpy(auto1.marca, marca);
            strcpy(auto1.modelo, modelo);
            strcpy(auto1.color, color);

            *(arrayAutos+indice) = auto1;
            total++;
            //indice = buscarLibre(empleados, tam);

        }
    }
    fclose(f);
    return total;
}

void mostrarAuto(eAuto* auto1)
{
    if(auto1 != NULL)
    {
        printf("%d  %s  %s  %s  %d\n", auto1->id, auto1->marca, auto1->modelo, auto1->color, auto1->anio);
    }
}

void mostrarAutos(eAuto* arrayAutos, int tam)
{

    if(arrayAutos != NULL && tam > 0)
    {
        for(int i=0; i< tam; i++)
        {
            if((arrayAutos + i)->estado)
            {
                mostrarAuto(arrayAutos+i);
            }
        }
    }
    else
    {
        printf("\nNo se pueden mostrar los empleados\n");
    }
}

