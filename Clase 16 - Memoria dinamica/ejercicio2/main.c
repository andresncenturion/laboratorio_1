#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vector;
    int* auxVector;
    int i;

    vector = (int*) malloc(sizeof(int*)*5);

    if (vector == (NULL))
    {
        printf("No se pudo asignar memoria.\n");
        exit(1);
    }

    for (i=0 ; i<5 ; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", vector+i);
    }

    for (i=0 ;i<5 ; i++)
    {
        printf("El numero ingresado es %d\n", *(vector+i));
    }
    printf("\n\n");

    auxVector = (int*)realloc(vector, 10*sizeof(int*));
    if (auxVector != (NULL))
    {
        vector = auxVector;
        printf("Se agrando el array con exito\n");
    }
    else
    {
        printf("No se pudo redimensionar el vector\n\n");
    }
    for (i=5 ; i<10 ; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", vector+i);
    }

    for (i=0 ;i<10 ; i++)
    {
        printf("El numero ingresado es %d\n", *(vector+i));
    }
    printf("\n\n");

    vector = (int*)realloc(vector,6*sizeof(int*));
    printf("Achico el array a 6 elementos\n");
    for (i=0 ;i<10 ; i++)
    {
        printf("El numero ingresado es %d\n", *(vector+i));
    }
    printf("\n\n");

    free(vector);

    return 0;
}
