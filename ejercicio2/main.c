#include <stdio.h>
#include <stdlib.h>

int sumar (int numero1, int numero2);

int main()
{
    int numero1;
    int numero2;
    int suma;

    printf ("Ingrese primer numero: ");
    scanf ("%d", &numero1);
    printf ("Ingrese segundo numero: ");
    scanf ("%d", &numero2);
    suma = sumar(numero1, numero2);
    printf("La suma de ambos numeros es %d", suma);

    return 0;
}

int sumar (int numero1, int numero2)
{
    int retorno;

    retorno = numero1 + numero2;
    return retorno;
}
