#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* x;

    x = (int*) malloc(sizeof(int));

    if (x == (NULL))
        {
            printf("No se pudo asignar memoria.\n");
            exit(1);
        }

        printf("Ingrese un numero: ");
        scanf("%d", x);

        printf("El numero ingresado es %d\n", *x);

        free(x);

    return 0;
}
