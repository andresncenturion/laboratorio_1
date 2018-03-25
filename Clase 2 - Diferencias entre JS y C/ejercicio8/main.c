#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NOMBRE 20

int main()
{
    char nombre[MAX_NOMBRE];
    char seguir = 's';
    int cantidadPaginas;;
    int cantidadVentas;
    int tema;
    int paginasPares = 0;
    int paginasImpares = 0;
    int ceroVentas = 0;
    int acumuladorVentas = 0;
    int contadorLibros = 0;
    int sumaPaginas = 0;
    float promedioVentas;

    printf("*** INGRESE LIBRO ***\n");
    while (seguir != 'n')
    {
        printf("NOMBRE: ");
        fflush(stdin);
        gets(nombre);
        printf("CANTIDAD DE PAGINAS: ");
        scanf("%d",&cantidadPaginas);
        while (cantidadPaginas < 1)
        {
            printf("El dato ingresado no es valido. Intente nuevamente.");
            printf("\nCANTIDAD DE PAGINAS: ");
            scanf("%d",&cantidadPaginas);
        }
        printf("CANTIDAD DE VENTAS: ");
        scanf("%d",&cantidadVentas);
        while (cantidadVentas < 0)
        {
            printf("El dato ingresado no es valido. Intente nuevamente.");
            printf("\nCANTIDAD DE VENTAS: ");
            scanf("%d",&cantidadVentas);
        }
        acumuladorVentas += cantidadVentas;
        printf("TEMAS POSIBLES: \n1.ROBOTICA \n2.PROGRAMACION \n3.PATRONES \n4.BASES DE DATOS \nSELECCIONE TEMA: ");
        scanf("%d",&tema);
        while (tema < 1 || tema > 4)
        {
            printf("El dato ingresado no es valido. Intente nuevamente.");
            printf("TEMAS POSIBLES: \n1.ROBOTICA \n2.PROGRAMACION \n3.PATRONES \n4.BASES DE DATOS \nSELECCIONE TEMA: ");
            scanf("%d",&tema);
        }

        if (cantidadPaginas % 2 == 0)
        {
            paginasPares++;
        }
        else
        {
            paginasImpares++;
        }
        if (cantidadVentas == 0)
        {
            ceroVentas++;
        }
        contadorLibros++;
        if (tema == 2)
        {
            sumaPaginas += cantidadPaginas;
        }

        system("cls");
        printf("LIBRO INGRESADO. DESEA INGRESAR OTRO LIBRO? (s/n): ");
        fflush(stdin);
        scanf("%c",&seguir);
        seguir = tolower(seguir);
        while (seguir != 's' && seguir != 'n')
        {
            printf("El dato ingresado no es valido. Intente nuevamente.");
            printf("\nDESEA INGRESAR OTRO LIBRO?: ");
            fflush(stdin);
            scanf("%c",&seguir);
            seguir = tolower (seguir);
        }
    }
    system("cls");
    promedioVentas = (float) acumuladorVentas / contadorLibros;

    printf("CANTIDAD DE LIBROS CON PAGINAS PARES: %d", paginasPares);
    printf("\nCANTIDAD DE LIBROS CON PAGINAS IMPARES: %d", paginasImpares);
    printf("\nCANTIDAD DE LIBROS CON CERO VENTAS: %d", ceroVentas);
    printf("\nEL PROMEDIO DE VENTAS POR LIBRO ES: %.2f", promedioVentas);

    return 0;
}
