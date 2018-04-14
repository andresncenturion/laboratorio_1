#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarNombres (char [][20], int);
void ordenarNombres (char [][20], int);

int main()
{
    int i;
    char nombre[20];
    char nombres[5][20];

    for (i = 0 ; i < 5 ; i++)
    {
        printf("Ingrese un nombre: ");
        gets(nombres[i]);
    }
    mostrarNombres(nombres, 5);
    ordenarNombres(nombres, 5);
    mostrarNombres(nombres, 5);

    return 0;
}

void ordenarNombres (char nombres [][20], int tam)
{
    int i;
    int j;
    int comparacion;
    char aux[20];

    /*for (i = 1 ; i < tam ; i++)
    {
        strcpy(aux, nombres[i]);
        j = i-1;
        while (j >= 0 && aux < nombres[j])
        {
            strcpy(nombres[j+1], nombres[j]);
            j--;
        }
        strcpy (nombres[j+1], aux);
    }*/

    for (i = 0 ; i < tam-1 ; i++)
    {
        for (j = i+1 ; j < tam ; j++)
        {
            comparacion = strcmp(nombres[i], nombres[j]);
            if (comparacion > 0)
            {
                strcpy(aux, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], aux);
            }
        }
    }

    printf ("\n\n");
}

void mostrarNombres (char nombres [][20], int tam)
{
    int i = 0;;

    for (i = 0 ; i < tam ; i++)
    {
        printf("El nombre %d es: %s\n", i, nombres[i]);
    }
    printf ("\n\n");
}
