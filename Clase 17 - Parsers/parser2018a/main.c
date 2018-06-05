#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char marca[50];
    char modelo[50];
    char color[50];
    int anio;
    int estado;
} eAuto;

int main()
{
    eAuto auto1;

    int cant;
    int id;
    char marca[50];
    char modelo[50];
    char color[50];
    char idCad[20];
    char anioCad[20];
    int anio;

    FILE* f;

    f = fopen("autos.csv", "r");

    if(f == NULL)
    {
        printf("Error al abrir el fichero\n");
        exit(1);
    }

    while(!feof(f))
    {
        cant = fscanf(f, "%[^,] , %[^,], %[^,] , %[^,], %[^\n] \n", idCad, marca, color, anioCad, modelo);

        if( cant != 5)
        {

            if(feof(f))
            {
                break;
            }
            else
            {
                printf("Problema para leer el archivo\n");

                break;
            }
        }
        id = atoi(idCad);
        anio = atoi(anioCad);

        auto1.id = id;
        auto1.anio = anio;
        strcpy(auto1.marca, marca);
        strcpy(auto1.modelo, modelo);
        strcpy(auto1.color, color);



        printf("n1=%d n2=%s n3=%s n=%d modelo:%s\n",  auto1.id,  auto1.marca,  auto1.color,  auto1.anio,  auto1.modelo);

    }

    printf("\n\n");

    fclose(f);


    return 0;
}
