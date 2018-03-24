#include <stdio.h>
#include <stdlib.h>

#define LETRAS 20

int main()
{

    char nombre[LETRAS];
    char localidad[LETRAS];

    printf("Ingrese su nombre: ");
    //scanf ("%s", nombre);
    gets(nombre);
    printf("Ingrese su localidad: ");
    //scanf ("%s", localidad);
    gets(localidad);
    printf("Usted se llama %s y vive en %s\n", nombre, localidad);
    return 0;
}
