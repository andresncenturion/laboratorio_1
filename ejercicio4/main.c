#include <stdio.h>
#include <stdlib.h>

int sumar ();

int main()
{
    int suma;

    suma = sumar();
    printf("La suma de ambos numeros es %d", suma);

    return 0;
}

int sumar ()
{
    int retorno;
    int numero1;
    int numero2;

    printf ("Ingrese primer numero: ");
    scanf ("%d", &numero1);
    printf ("Ingrese segundo numero: ");
    scanf ("%d", &numero2);
    retorno = numero1 + numero2;
    return retorno;
}
