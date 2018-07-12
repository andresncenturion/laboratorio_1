#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "jugadores.h"

#define PATH "argentina.csv"

int main()
{
    ArrayList* argentina;

    argentina = al_newArrayList();

    //1
    parseJugadores(PATH, argentina);
    mostrarElementos(argentina);
    system("Pause");
    //2
    argentina->sort(argentina, ordenar, 1);
    mostrarElementos(argentina);
    system("Pause");
    //3
    argentina->map(argentina, calcularSiLlega);
    mostrarElementos(argentina);
    system("Pause");
    //4
    generarArchivo(argentina, "losquellegan.csv");
    return 0;
}
