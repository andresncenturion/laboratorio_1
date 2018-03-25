#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#define MAX_LETRAS 20

int main()
{
    char nombre[MAX_LETRAS];
    char seguir = 's';
    char nombrePesado[MAX_LETRAS];
    float peso;
    float masPesado;
    float acumuladorPeso = 0;
    float promedioPeso;
    float bajoCeroMaximo;
    float bajoCeroMinimo;
    int temperaturasPares = 0;
    int flagPesado = 0;
    int bajoCero = 0;
    int contadorPeso = 0;
    int temperatura;
    int temperaturaPesado;
    int flagBajoCeroMax = 0;
    int flagBajoCeroMin = 0;

    while (seguir == 's')
    {
        printf("*** INGRESO DE ANIMALES AL ZOOLOGICO ***");

        printf("\nNOMBRE: ");
        fflush(stdin);
        gets(nombre);

        printf("PESO: ");
        scanf("%f", &peso);
        while (peso < 1 || peso > 1000)
        {
            printf("El dato ingresado no es valido. Intentelo nuevamente.");
            printf("\nPESO: ");
            scanf("%f", &peso);
        }
        if (flagPesado == 0 || peso > masPesado)
        {
            masPesado = peso;
            strcpy(nombrePesado, nombre);
            temperaturaPesado = temperatura;
            flagPesado = 1;
        }
        acumuladorPeso += peso;
        contadorPeso++;

        printf("TEMPERATURA DEL HABITAT: ");
        scanf("%d", &temperatura);
        while (temperatura < -30 || temperatura > 30)
        {
            printf("El dato ingresado no es valido. Intentelo nuevamente.");
            printf("\nTEMPERATURA DEL HABITAT: ");
            scanf("%d", &temperatura);
        }
        if (temperatura % 2 == 0)
        {
            temperaturasPares++;
        }
        if (temperatura < 0)
        {
            bajoCero++;
            if (flagBajoCeroMax == 0 || peso > bajoCeroMaximo)
            {
                bajoCeroMaximo = peso;
                flagBajoCeroMax = 1;
            }
            if (flagBajoCeroMin == 0 || peso < bajoCeroMinimo)
            {
                bajoCeroMinimo = peso;
                flagBajoCeroMin = 1;
            }
        }
        printf("DESEA INGRESAR OTRO ANIMAL? (s/n): ");
        fflush(stdin);
        seguir = getchar();
        seguir = tolower(seguir);
        while (seguir != 's' && seguir != 'n')
        {
            printf("El dato ingresado no es valido. Intentelo nuevamente.");
            printf("\nDESEA INGRESAR OTRO ANIMAL? (s/n): ");
            fflush(stdin);
            seguir = getchar();
            seguir = tolower(seguir);
        }
    }
    promedioPeso = acumuladorPeso / contadorPeso;
    system ("cls");
    printf("CANTIDAD DE TEMPERATURAS PARES: %d", temperaturasPares);
    printf("\nEL ANIMAL MAS PESADO ES %s Y LA TEMPERATURA DE SU HABITAT ES %d", nombrePesado, temperaturaPesado);
    printf("\nLA CANTIDAD DE ANIMALES CUYO HABITAT ESTA A TEMPERATURA BAJO CERO ES %d", bajoCero);
    printf("\nEL PROMEDIO DE PESO POR ANIMAL ES: %.3f", promedioPeso);
    printf("\nDE LOS ANIMALES CUYO HABITAT ESTA A TEMPERATURA BAJO CERO, EL PESO MAXIMO ES %.3f Y EL PESO MINIMO %.3f", bajoCeroMaximo, bajoCeroMinimo);

    return 0;
}
