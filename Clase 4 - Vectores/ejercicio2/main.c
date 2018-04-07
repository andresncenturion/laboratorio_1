#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMEROS 5

int main()
{
    int numeros[MAX_NUMEROS];
    int i;

    for (i=0;i<5;i++)
    {
        printf("Ingrese numero %d: ",i+1);
        scanf("%d",&numeros[i]);
    }
    printf("\n");
    for (i=0;i<5;i++)
    {
        printf("El numero ingresado en la posicion %d es: %d\n",i,numeros[i]);
    }
    printf("\n");
    for (i=0;i<5;i++)
    {
        numeros[i] = numeros[i]*2;
        printf("El numero modificado en la posicion %d es: %d\n",i,numeros[i]);
    }

    return 0;


    return 0;
}
