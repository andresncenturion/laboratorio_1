#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int idTipo;
    char descripcion[20];
}eTipo;

typedef struct
{
    int estado;
    int id;
    char nombre[20];
    int edad;
    eTipo tipo;
}eMascota;

void mostrarMascota(eMascota*);
void mostrarMascotas (eMascota*, int);
void modificarEdad(eMascota*, int);
int cargarMascota (eMascota*);

int main()
{
    eMascota nuevaMascota;
    eMascota zoo[] = {{1,101, "Perry", 4, {4000, "Ornitorrinco"}}, {1,102, "Zaboomafoo", 2, {7001, "Chango"}}, {1,103, "Mauri", 56, {666, "Fondo Buitre"}}};

    cargarMascota(&nuevaMascota);
    mostrarMascota(&nuevaMascota);
    printf("\n\n");
    system("pause");
    modificarEdad(&nuevaMascota, 17);
    printf("\n\n");
    mostrarMascota(&nuevaMascota);
    printf("\n\n");
    system("pause");
    mostrarMascotas(zoo, 3);
    printf("\n\n");
    system("pause");


    return 0;
}

void mostrarMascota(eMascota* nuevaMascota)
{
    printf("%d  %s  %d  %d  %s", nuevaMascota->id, nuevaMascota->nombre, nuevaMascota->edad, nuevaMascota->tipo.idTipo, nuevaMascota->tipo.descripcion);
}

void mostrarMascotas (eMascota* zoo, int tam)
{
    int i;

    for (i=0; i<tam ; i++)
    {
        if ((zoo+i)->estado == 1)
        {
            mostrarMascota(zoo+i);
            printf("\n");
        }
    }
}

void modificarEdad(eMascota* nuevaMascota, int edad)
{
    int nuevaEdad;

    nuevaEdad = edad;
    nuevaMascota->edad = nuevaEdad;
}

int cargarMascota (eMascota* nuevaMascota)
{
    int retorno = -1;

    printf("--- NUEVA MASCOTA ---\n\n");

    printf("Id: ");
    scanf("%d", &nuevaMascota->id);

    printf("Nombre: ");
    fflush(stdin);
    scanf("%s", &nuevaMascota->nombre);

    printf("Edad: ");
    scanf("%d", &nuevaMascota->edad);

    /*nuevaMascota->tipo.idTipo = 445;
    nuevaMascota->tipo.descripcion = "Velociraptor";*/

    return retorno;
}
