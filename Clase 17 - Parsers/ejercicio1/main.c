#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    int cant;
    int n1;
    int n2;
    int n3;
    int n4;

    f = fopen ("archivo.txt", "r");
    if (f != NULL)
    {
        while (!feof(f))
        {
            cant = fscanf (f,"%d,%d,%d,%d\n", &n1, &n2,&n3,&n4);

            if (cant != 4)
            {
                if (feof(f))
                {
                    printf ("Final del archivo");
                    break;
                }
                else
                {
                    printf("Error al leer el archivo");
                }
            }
        printf("%d %d %d %d\n", n1, n2, n3, n4);
        }
    }
    return 0;
}
