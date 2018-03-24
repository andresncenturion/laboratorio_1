#include <stdio.h>
#include <stdlib.h>

int main()
{

    float precio, descuento, preciofinal;
    int porcentaje;

    printf("Ingrese el precio del producto: ");
    scanf ("%f",&precio);
    printf("Ingrese el porcentaje del descuento: ");
    scanf ("%d",&porcentaje);
    descuento = porcentaje * precio / 100;
    preciofinal = (precio - descuento)*1.21;

    printf("El precio del producto es %.2f. Con un descuento del %d su precio es %.2f", precio, porcentaje, preciofinal);

    return 0;
}
