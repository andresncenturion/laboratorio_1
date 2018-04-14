#include <stdio.h>
#include <stdlib.h>

void mostrarNumeros (int[], int);
int buscarMaximo (int[], int);
int buscarMinimo (int[], int);
int buscarElemento (int[], int, int);
void ordenarVector (int[], int);

int main()
{
    int numeros[] = {140, 12, 23, 184, 99};
    int maximo;
    int minimo;
    int index;

    mostrarNumeros (numeros, 5);
    maximo = buscarMaximo (numeros, 5);
    minimo = buscarMinimo(numeros, 5);
    index = buscarElemento(numeros, 5, 10);
    printf("El maximo es: %d", maximo);
    printf("\nEl minimo es: %d", minimo);
    printf("\nEl elemento esta en la posicion: %d", index);
    ordenarVector(numeros, 5);
    mostrarNumeros(numeros, 5);

    return 0;
}

void mostrarNumeros(int numeros[], int cantNumeros)
{
    int i;

    for (i=0;i<cantNumeros;i++)
    {
         printf("El numero %d es: %d\n", i, numeros[i]);
    }
    printf("\n\n");
}

int buscarMaximo(int numeros[], int cantNumeros)
{
    int i;
    int maximo;
    int flagMaximo = 0;

    for (i=0;i<cantNumeros;i++)
    {
        if (flagMaximo == 0 || numeros[i] > maximo)
        {
            maximo = numeros[i];
            flagMaximo = 1;
        }
    }
    return maximo;
}

int buscarMinimo(int numeros[], int cantNumeros)
{
    int i;
    int minimo;
    int flagMinimo = 0;

    for (i=0;i<cantNumeros;i++)
    {
        if (flagMinimo == 0 || numeros[i] < minimo)
        {
            minimo = numeros[i];
            flagMinimo = 1;
        }
    }
    return minimo;
}

int buscarElemento (int numeros[], int cantNumeros, int elemento)
{
    int i;
    int index = -1;

    for (i=0;i<cantNumeros;i++)
    {
        if (numeros[i] == elemento)
        {
            index = i;
            break;
        }
    }
    return index;
}

void ordenarVector (int numeros[], int tam)
{
    int i;
    int j;
    int aux;

    for (i=0 ; i<tam-1 ; i++)
    {
        for (j=i+1 ; j<tam ; j++)
        {
            if (numeros[i] > numeros[j])
            {
                aux = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = aux;
            }
        }
    }
}



