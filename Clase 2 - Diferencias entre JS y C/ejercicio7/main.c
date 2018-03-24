#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int nota;
    int notabaja;
    int notaedadmin;
    int edad;
    int edadmin;
    int i;
    int contnota=0;
    int acumnota=0;
    int flagnotabaja=0;
    int flagedad=0;
    int contc=0;
    int edadmujer;
    int notamujer;
    int flagmujer=0;
    char sexo;
    char sexonotabaja;
    char sexoedadmin;
    float promnota;

    for (i=0;i<5;i++)
    {
        printf("Ingrese nota (1-10): ");
        scanf("%d",&nota);
        while (nota < 1 || nota >10)
        {
            printf ("La nota ingresada no es valida. Ingrese una nota entre 1 y 10: ");
            scanf ("%d",&nota);
        }
        contnota++;
        acumnota += nota;
        printf("Ingrese edad (1-99): ");
        scanf("%d",&edad);
        while (edad < 1 || edad >99)
        {
            printf ("La edad ingresada no es valida. Ingrese una edad entre 1 y 99: ");
            scanf ("%d",&edad);
        }
        printf("Ingrese sexo (f/m): ");
        fflush(stdin);
        scanf("%c",&sexo);
        sexo = tolower(sexo);
        while (sexo != 'f' && sexo != 'm')
        {
            printf ("El sexo ingresado no es valido. Ingrese f o m: ");
            fflush(stdin);
            scanf ("%c",&sexo);
            sexo = tolower(sexo);
        }
        if (flagnotabaja == 0 || nota < notabaja)
        {
            notabaja = nota;
            flagnotabaja = 1;
            sexonotabaja = sexo;
        }
        if (sexo == 'm' && edad > 18)
        {
            if (nota >= 6 )
            {
                contc++;
            }
        }
        if (flagedad == 0 || edad < edadmin)
        {
            edadmin = edad;
            flagedad = 1;
            sexoedadmin = sexo;
            notaedadmin = nota;
        }
        if (flagmujer == 0 && sexo == 'f')
        {
            edadmujer = edad;
            notamujer = nota;
            flagmujer = 1;
        }
    }

    promnota = (float) acumnota / contnota;

    printf ("El promedio de las notas es: %.2f", promnota);
    printf ("\nLa nota mas baja es %d y su sexo es %c", notabaja, sexonotabaja);
    printf ("\nLa cantidad de varones mayores a 18 con nota mayor o igual a 6 es: %d", contc);
    printf ("\nEl sexo del mas joven es %c y su nota es %d", sexoedadmin, notaedadmin);

    if (flagmujer == 1)
    {
        printf ("\nLa edad de la primera mujer ingresada es %d y su nota es %d", edadmujer, notamujer);
    }
    else
    {
        printf ("\nNo se ingresaron datos de ninguna mujer");
    }

    return 0;
}
