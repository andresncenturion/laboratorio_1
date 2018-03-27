#include <stdio.h>
#include <stdlib.h>

int sumarValor (int numero);

int main()
{
    int numero;
    int numeroIncrementado;

    printf ("Ingrese un numero entero: ");
    scanf ("%d", &numero);
    numeroIncrementado = sumarValor(numero);
    printf("El valor incrementado es %d", numeroIncrementado);

    return 0;
}

int sumarValor (int numero)
{
    int retorno;

    retorno = numero + 1;
    return retorno;
}
