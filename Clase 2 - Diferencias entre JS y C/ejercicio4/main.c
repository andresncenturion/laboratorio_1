#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    float resultado;

    printf("Ingrese el primer numero: ");
    scanf("%d",&num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d",&num2);
    if (num1 == num2)
    {
        printf ("Los numeros son %d y %d", num1, num2);
    }
    else if (num1 > num2)
    {
        if (num2 != 0)
        {
        resultado = (float) num1/num2;
        printf ("El resultado es: %.2f", resultado);
        }
        else
        {
            printf("No se puede dividir por 0");
        }
    }
    else
    {
        resultado = num1 + num2;
        printf ("El resultado es: %.0f", resultado);
        if (resultado < 50)
        {
            printf ("\nLa suma es %.0f y es menor a 50", resultado);
        }
    }

    return 0;
}
