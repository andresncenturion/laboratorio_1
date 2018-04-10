#include <stdio.h>
#include <stdlib.h>

void calcularPromedios (int[], int[], float[], int);
void mostrarVector (int[], int);
void mostrarVectorFloat (float[], int);

int main()
{
    int notas1[] = {10, 7, 2, 2, 4};
    int notas2[] = {9, 5, 4, 7, 5};
    float promedios[5];

    mostrarVector(notas1, 5);
    mostrarVector(notas2, 5);
    calcularPromedios(notas1, notas2, promedios, 5);
    mostrarVectorFloat(promedios, 5);

    return 0;
}

void calcularPromedios (int notas1[], int notas2[], float promedios[], int cantNotas)
{
    int i;

    for (i=0 ; i<cantNotas ; i++)
    {
        promedios[i] = (float) (notas1[i] + notas2[i]) / 2;
    }
}

void mostrarVector (int notas[], int cantNotas)
{
    int i;

    for (i=0;i<cantNotas;i++)
    {
         printf("La nota %d es: %d\n", i, notas[i]);
    }
    printf("\n\n");
}

void mostrarVectorFloat (float notas[], int cantNotas)
{
    int i;

    for (i=0;i<cantNotas;i++)
    {
         printf("La nota %d es: %.2f\n", i, notas[i]);
    }
    printf("\n\n");
}
