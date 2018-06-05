#include <stdio.h>
#include <stdlib.h>

#define PATH "miArchivo.txt"

int main()
{
    FILE* pArchivo;
    char cadena[100] = "Me fui\n";
    char cadena2[100] = "otro texto\n";

    //PARA LEER
    pArchivo = fopen(PATH, "w");
    //pArchivo = fopen(PATH, "a");
    if (pArchivo != NULL)
    {
        fprintf(pArchivo, "Hola a todos\n");
        fprintf(pArchivo, cadena);
        fprintf(pArchivo, "Aca con mascara: %s -- %d\n", cadena2, 156);
        //fprintf(pArchivo, "Bye");
        fclose(pArchivo);
    }

    else
    {
        printf("Imposible guardar en archivo\n");
    }

    //PARA ESCRIBIR
    /*pArchivo = fopen (PATH, "r");
    if (pArchivo != NULL)
    {
        while (!feof(pArchivo))
        {
            fgets(cadena, 100, pArchivo);
            printf("%s", cadena);
        }
        fclose(pArchivo);
    }*/


    return 0;
}
