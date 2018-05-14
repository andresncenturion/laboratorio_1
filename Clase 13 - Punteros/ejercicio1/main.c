#include <stdio.h>
#include <stdlib.h>

void pedirNumeros (int*);
void mostrarNumeros (int*);

int main()
{
    int vec[5];

    pedirNumeros(vec);
    mostrarNumeros(vec);

    return 0;
}

void pedirNumeros (int* vec)
{
    int i;

    for (i=0; i<5 ; i++)
    {
        printf("Ingrese numero %d: ", i);
        scanf("%d",(vec+i));
    }
}

void mostrarNumeros (int* vec)
{
    int i;

    for (i=0 ; i<5 ; i++)
    {
        printf("\nNumero %d: %d", i, *(vec+i));
    }
}
