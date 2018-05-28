#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vector;
    int i;

    vector = (int*) calloc(5, sizeof(int*));

    if (vector == (NULL))
    {
        printf("No se pudo asignar memoria.\n");
        exit(1);
    }

    for (i=0 ;i<5 ; i++)
    {
        printf("El numero ingresado es %d\n", *(vector+i));
    }
    printf("\n\n");
    free(vector);

    return 0;
}
