#include <stdio.h>
#include <stdlib.h>

void sumar ();

int main()
{
    sumar();

    return 0;
}

void sumar()
{
    int numero1;
    int numero2;
    int suma;

    printf ("Ingrese primer numero: ");
    scanf ("%d", &numero1);
    printf ("Ingrese segundo numero: ");
    scanf ("%d", &numero2);
    suma = numero1 + numero2;
    printf("La suma de ambos numeros es %d", suma);
}
