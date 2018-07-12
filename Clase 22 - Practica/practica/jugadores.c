#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "jugadores.h"

eJugador* newJugador (void)
{
    eJugador* nuevoJugador;

    nuevoJugador = (eJugador*) malloc(sizeof(eJugador));

    if (nuevoJugador != NULL)
    {
        nuevoJugador->dorsal = 0;
        strcpy(nuevoJugador->posicion, "");
        strcpy(nuevoJugador->nombre, "");
        strcpy(nuevoJugador->apellido, "");
        nuevoJugador->edad = 0;
        nuevoJugador->altura = 0;
        strcpy(nuevoJugador->equipo, "");
        nuevoJugador->llega = -1;
    }
    return nuevoJugador;
}

void setDorsal (eJugador* jugador, int dorsal)
{
    if (jugador != NULL)
    {
        jugador->dorsal = dorsal;
    }
}

int getDorsal (eJugador* jugador)
{
    int dorsal;

    if (jugador != NULL)
    {
        dorsal = jugador->dorsal;
    }
    return dorsal;
}

void setPosicion (eJugador* jugador, char* posicion)
{
    if (jugador != NULL)
    {
        strcpy(jugador->posicion, posicion);
    }
}

char* getPosicion (eJugador* jugador)
{
    char* posicion;

    posicion = (char*) malloc(sizeof(char));

    if (jugador != NULL && posicion != NULL)
    {
        strcpy(posicion, jugador->posicion);
    }
    return posicion;
}

void setNombre (eJugador* jugador, char* nombre)
{
    if (jugador != NULL)
    {
        strcpy(jugador->nombre, nombre);
    }
}

char* getNombre (eJugador* jugador)
{
    char* nombre;

    nombre = (char*) malloc(sizeof(char));

    if (jugador != NULL && nombre != NULL)
    {
        strcpy(nombre, jugador->nombre);
    }
    return nombre;
}

void setApellido (eJugador* jugador, char* apellido)
{
    if (jugador != NULL)
    {
        strcpy(jugador->apellido, apellido);
    }
}

char* getApellido (eJugador* jugador)
{
    char* apellido;

    apellido = (char*) malloc(sizeof(char));

    if (jugador != NULL && apellido != NULL)
    {
        strcpy(apellido, jugador->apellido);
    }
    return apellido;
}

void setEdad (eJugador* jugador, int edad)
{
    if (jugador != NULL)
    {
        jugador->edad = edad;
    }
}

int getEdad (eJugador* jugador)
{
    int edad;
    if (jugador != NULL)
    {
        edad = jugador->edad;
    }
    return edad;
}

void setAltura (eJugador* jugador, int altura)
{
    if (jugador != NULL)
    {
        jugador->altura = altura;
    }
}

int getAltura (eJugador* jugador)
{
    int altura;

    if (jugador != NULL)
    {
        altura = jugador->altura;
    }
    return altura;
}

void setEquipo (eJugador* jugador, char* equipo)
{
    if (jugador != NULL)
    {
        strcpy(jugador->equipo, equipo);
    }
}

char* getEquipo (eJugador* jugador)
{
    char* equipo;

    equipo = (char*) malloc(sizeof(char));

    if (jugador != NULL && equipo != NULL)
    {
        strcpy(equipo, jugador->equipo);
    }
    return equipo;
}

void setLlega (eJugador* jugador, int llega)
{
    if (jugador != NULL)
    {
        jugador->llega = llega;
    }
}

int parseJugadores(char* path, ArrayList* lista)
{
    int status = -1;
    FILE* f;
    int cant = 0;
    char bufferDorsal[3];
    char bufferPosicion[4];
    char bufferNombre[20];
    char bufferApellido[20];
    char bufferEdad[3];
    char bufferAltura[4];
    char bufferEquipo[20];
    char bufferLlega[3];
    eJugador* aux;

    if (lista != NULL)
    {
        f = fopen(path, "r");
        if (f == NULL)
        {
            printf("Error al abrir el archivo.");
            system("Pause");
            exit(-2);
        }
        status = 0;
        while (!feof(f))
        {
            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferDorsal, bufferPosicion, bufferNombre, bufferApellido, bufferEdad, bufferAltura, bufferEquipo, bufferLlega);
            aux = newJugador();
            if (cant != 8)
            {
                if (feof(f))
                {
                    status = 1;
                    printf("Parseo exitoso");
                    break;
                }
                else
                {
                    printf("Error al leer el archivo data.csv");
                    status = -3;
                }
            }
            setDorsal(aux, atoi(bufferDorsal));
            setPosicion(aux, bufferPosicion);
            setNombre(aux, bufferNombre);
            setApellido (aux, bufferApellido);
            setEdad(aux, atoi(bufferEdad));
            setAltura(aux, atoi(bufferAltura));
            setEquipo(aux, bufferEquipo);
            setLlega(aux, atoi(bufferLlega));
            lista->add(lista, aux);
            }
    }
    fclose(f);
    return status;
}

void mostrarElemento(eJugador* unElemento)
{
    printf("%6d  %8s  %20s  %20s  %4d  %6d  %20s", unElemento->dorsal, unElemento->posicion, unElemento->nombre, unElemento->apellido, unElemento->edad, unElemento->altura, unElemento->equipo);
    if (unElemento->llega == 1)
    {
        printf("\t LLEGA");
    }
    printf("\n");
}

void mostrarElementos(ArrayList* lista)
{
    eJugador* unElemento;
    int tam;
    int i;

    tam = lista->len(lista);
    printf("DORSAL  POSICION                NOMBRE              APELLIDO  EDAD  ALTURA                EQUIPO  LLEGA\n\n");
    for (i=0 ; i<tam ; i++)
    {
        unElemento = lista->get(lista, i);
        mostrarElemento(unElemento);
    }
}

int ordenar (void* elemento1, void* elemento2)
{
    int status = 0;

    if(((eJugador*)elemento1)->edad > ((eJugador*)elemento2)->edad)
    {
        status = 1;
    }
    if(((eJugador*)elemento1)->edad < ((eJugador*)elemento2)->edad)
    {
        status =  -1;
    }
    return status;
}

int calcularSiLlega (void* elemento)
{
    int llega = 0;
    int edad;

    edad = getEdad(elemento) + 4;

    if (edad <= 32)
    {
        llega = 1;
    }
    setLlega(elemento, llega);

    return llega;
}

int generarArchivo(ArrayList* lista, char* path)
{
    int status = -1;
    FILE* f;
    eJugador* aux;
    int i;
    int tam = al_len(lista);

    if(lista != NULL)
    {
        f = fopen(path, "w");

        if(f != NULL)
        {
            status = 0;
            for(i=0 ; i<tam ; i++)
            {
                aux = lista->get(lista, i);
                if (aux->llega == 1)
                {
                    fprintf(f,"%d,", getDorsal(aux));
                    fprintf(f,"%s,", getPosicion(aux));
                    fprintf(f,"%s,", getNombre(aux));
                    fprintf(f,"%s,", getApellido(aux));
                    fprintf(f,"%d,", getEdad(aux));
                    fprintf(f,"%d,", getAltura(aux));
                    fprintf(f,"%s\n", getEquipo(aux));
                }
            }
        }
        fclose(f);
    }
    return status;
}
