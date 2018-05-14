#include <stdio.h>
#include <stdlib.h>

void vectorVector (int[], int);
void vectorPuntero (int[], int);
void punteroVector (int*, int);
void punteroPuntero (int*, int);

int main()
{
    int vec[] = {10, 20, 30, 40, 50};

    vectorVector(vec, 5);
    vectorPuntero(vec, 5);
    punteroVector(vec, 5);
    punteroPuntero(vec, 5);
    /*[] - []
    [] - *
    * - []
    * - **/
    return 0;
}

void vectorVector (int vec[], int tam)
{
    int i;

    for (i=0; i<tam ; i++)
    {
        printf("\nNumero %d: %d", i, vec[i]);
    }
    printf("\n\n");
}

void vectorPuntero (int vec[], int tam)
{
    int i;

    for (i=0; i<tam ; i++)
    {
        printf("\nNumero %d: %d", i, *(vec+i));
    }
    printf("\n\n");
}

void punteroVector (int* vec, int tam)
{
    int i;

    for (i=0; i<tam ; i++)
    {
        printf("\nNumero %d: %d", i, vec[i]);
    }
    printf("\n\n");
}

void punteroPuntero (int* vec, int tam)
{
    int i;

    for (i=0; i<tam ; i++)
    {
        printf("\nNumero %d: %d", i, *(vec+i));
    }
    printf("\n\n");
}
