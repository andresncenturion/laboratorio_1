#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define MAX_PROD 10
#define MAX_PROV 5

void incializarProductos(eProducto productos[], int tam)
{
    int i;

    for (i=0 ; i<tam ; i++)
    {
        productos[i].estado = 0;
    }
}

int menu ()
{
    int opcion;

    system("cls");
    printf("      ---ABM Productos---\n\n");
    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informar\n");
    printf("5- Listar\n");
    printf("6-Salir\n");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void altaProducto(eProducto productos[], int tamProd, eProveedor proveedores[], int tamProv)
{
    int index;

    system ("cls");
    printf("--- Alta de producto ---\n\n");

    index = buscarLibre(productos, tamProd);

    if(index == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a productos nuevos.\n\n");
    }
    else
    {
        productos[index].codigo = index+1;
        printf("Ingrese descripcion: ");
        fflush(stdin);
        gets(productos[index].descripcion);
        printf("Ingrese importe: ");
        scanf ("%f", &productos[index].importe);
        printf("Ingrese cantidad: ");
        scanf("%d", &productos[index].cantidad);
        printf("Ingrese proveedor: ");
        productos[index].idProveedor = pedirProveedor(proveedores, tamProv);

        printf("\nAlta exitosa!!!\n\n");
    }
}

int buscarLibre(eProducto productos[], int tam)
{
    int i;
    int indice = -1;

    for(i=0; i<tam; i++)
    {
        if(productos[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int pedirProveedor(eProveedor proveedores[], int tam)
{
    int codProveedor;
    int i;

    for(i=0; i<tam; i++)
    {
        printf("%d- %s\n", proveedores[i].codigo, proveedores[i].descripcion);
    }
    printf("\nSeleccione proveedor: ");
    fflush(stdin);
    scanf("%d", &codProveedor);

    return codProveedor;
}

void modificarProducto(eProducto productos[], int tamProd, eProveedor proveedores[], int tamProv)
{
    int auxCodigo;
    int existe;

    system("cls");
    printf("---Modificacion de producto---\n\n");

    printf("Ingrese codigo: ");
    scanf("%d", &auxCodigo);

    existe = buscarProducto(productos, tamProd, auxCodigo);

    if(existe == -1)
    {
        printf("\nEl codigo de producto %d no se encuentra en el sistema\n\n", auxCodigo);

    }
    else
    {
        mostrarProducto(productos[existe], proveedores, tamProd);

        printf("\nIngrese nueva descripcion: ");
        fflush(stdin);
        gets(productos[existe].descripcion);

        printf("\nIngrese nuevo importe: ");
        scanf("%f", &productos[existe].importe);

        printf("\nIngrese nueva cantidad: ");
        scanf("%d", &productos[existe].cantidad);
    }
}

int buscarProducto(eProducto productos[], int tamProd, int auxCodigo)
{
    int indice = -1;
    int i;

    for(i=0; i < tamProd; i++)
    {
        if(productos[i].estado == 1 && productos[i].codigo == auxCodigo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarProducto(eProducto producto, eProveedor proveedores[], int tam)
{
    int indice;
    int i;

    for(i=0; i< tam; i++)
    {
        if(producto.idProveedor == proveedores[i].codigo)
        {
            indice = i;
            break;
        }
    }
    printf("\n%d \t%s \t%.2f \t%d \t%s", producto.codigo, producto.descripcion, producto.importe, producto.cantidad, proveedores[indice].descripcion);
}

void bajaProducto(eProducto productos[], int tamProd, eProveedor proveedores[], int tamProv)
{
    int auxCodigo;
    int existe;
    char confirma;

    system("cls");
    printf("---Baja de Producto---\n\n");

    printf("Ingrese codigo: ");
    scanf("%d", &auxCodigo);

    existe = buscarProducto(productos, MAX_PROD, auxCodigo);

    if(existe == -1)
    {
        printf("\nEl codigo de producto %d no se encuentra en el sistema\n\n", auxCodigo);
    }
    else
    {

        mostrarProducto(productos[existe], proveedores, tamProv);

        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            productos[existe].estado = 0;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }
    }
}

void mostrarProductos(eProducto productos[], int tamProd, eProveedor proveedores[],int tamProv)
{
    int i;
    printf("      ---Lista de productos---\n\n");

    for(i=0; i< tamProd; i++)
    {
        if(productos[i].estado == 1)
        {
            mostrarProducto(productos[i], proveedores, tamProv);
        }
    }
    printf("\n\n");
}

void informar(eProducto productos[], int tamProd, eProveedor proveedores[],int tamProv)
{
    float promedio;
    int superaCantidad;
    int noSuperaCantidad;

    printf("\n--- INFORMAR PRODUCTOS ---\n\n");
    printf("\nA. TOTAL Y PROMEDIO DE LOS IMPORTES Y CUANTOS SUPERAN\n\n");
    promedio = totalPromedio(productos, tamProd);
    superaPromedio (productos, tamProd, promedio);
    printf("\nB. TOTAL Y PROMEDIO DE LOS IMPORTES Y CUANTOS NO SUPERAN\n\n");
    promedio = totalPromedio(productos, tamProd);
    noSuperaPromedio (productos, tamProd, promedio);
    superaCantidad = superaStock(productos, tamProd);
    noSuperaCantidad = noSuperaStock(productos, tamProd);
    printf("\nC. CANTIDAD DE PRODUCTOS CUYO STOCK ES MENOR O IGUAL A 10: %d", noSuperaCantidad);
    printf("\nD. CANTIDAD DE PRODUCTOS CUYO STOCK ES MAYOR A 10: %d", superaCantidad);
}

void listar(eProducto productos[], int tamProd, eProveedor proveedores[], int tamProv)
{
    printf("\n--- LISTAR PRODUCTOS ---\n\n");
    printf("A. LISTADO ORDENADO:\n");
    ordenarProductos(productos, tamProd, proveedores, tamProv);
    mostrarProductos(productos, tamProd, proveedores, tamProv);
    printf("B. PRODUCTOS CANT <= 10:\n");
    productosMenorDiez(productos, tamProd, proveedores, tamProv);
    printf("C. PRODUCTOS CANT > 10:\n");
    productosMayorDiez(productos, tamProd, proveedores, tamProv);
    printf("D. IMPORTE > PROMEDIO:\n");
    productosMayorPromedio(productos, tamProd, proveedores, tamProv);
    printf("E. IMPORTE < PROMEDIO:\n");
    productosMenorPromedio(productos, tamProd, proveedores, tamProv);
}

float totalPromedio(eProducto productos[], int tamProd)
{
    int i;
    float total = 0;
    float promedio;
    int contador=0;

    for (i=0; i<tamProd ; i++)
    {
        total = total + productos[i].importe;
        contador++;
    }
    promedio = total / contador;

    printf("\nTotal de importes: %.2f", total);
    printf("\nPromedio de importes: %.2f", promedio);
    printf("\n\n");

    return promedio;
}

void superaPromedio (eProducto productos[], int tamProd, int promedio)
{
    int i;
    int cont = 0;

    for (i=0 ; i<tamProd ; i++)
    {
        if (productos[i].importe > promedio)
        {
            cont++;
        }
    }
    printf("\nProductos que superan el promedio: %d", cont);
}

void noSuperaPromedio (eProducto productos[], int tamProd, int promedio)
{
    int i;
    int cont = 0;

    for (i=0 ; i<tamProd ; i++)
    {
        if (productos[i].importe < promedio)
        {
            cont++;
        }
    }
    printf("\nProductos que no superan el promedio: %d", cont);
}

int superaStock(eProducto productos[], int tamProd)
{
    int i;
    int cont = 0;

    for (i=0; i<tamProd ; i++)
    {
        if ((productos[i].estado == 1) && (productos[i].cantidad > 10))
        {
            cont++;
        }
    }
    return cont;
}

int noSuperaStock(eProducto productos[], int tamProd)
{
    int i;
    int cont = 0;

    for (i=0 ; i<tamProd ; i++)
    {
        if ((productos[i].estado == 1) && (productos[i].cantidad <= 10))
        {
            cont++;
        }
    }
    return cont;
}

void ordenarProductos(eProducto productos[], int tamProd, eProveedor proveedores[], int tamProv)
{
    int i;
    int j;
    eProducto auxProducto;

    for(i=0; i<tamProd-1; i++)
    {
        for(j=i+1; j<tamProd; j++)
        {
            if(productos[i].importe < productos[j].importe)
            {
                auxProducto = productos[i];
                productos[i] = productos[j];
                productos[j] = auxProducto;
            }
            else
            {
                if(productos[i].importe == productos[j].importe)
                {
                    if(strcmp(productos[i].descripcion, productos[j].descripcion)>0)
                    {
                        auxProducto = productos[i];
                        productos[i] = productos[j];
                        productos[j] = auxProducto;
                    }

                }

            }
        }
    }
    printf("\nSistema Ordenado\n\n");
}

void productosMenorDiez(eProducto productos[], int tamProd, eProveedor proveedores[], int tamProv)
{
    int i=0;

    for(i=0; i<tamProd ; i++)
    {
        if (productos[i].cantidad <=10)
        {
            mostrarProducto(productos[i], proveedores, tamProv);
        }
    }
    printf("\n\n");
}

void productosMayorDiez(eProducto productos[], int tamProd, eProveedor proveedores[], int tamProv)
{
    int i=0;

    for(i=0; i<tamProd ; i++)
    {
        if (productos[i].cantidad > 10)
        {
            mostrarProducto(productos[i], proveedores, tamProv);
        }
    }
    printf("\n\n");
}

void productosMayorPromedio(eProducto productos[], int tamProd, eProveedor proveedores[], int tamProv)
{
    int i;
    float promedio;

    promedio = totalPromedio(productos, tamProd);
    for (i=0 ; i<tamProd ; i++)
    {
        if (productos[i].importe > promedio)
        {
            mostrarProducto(productos[i], proveedores, tamProv);
        }
    }
    printf("\n\n");
}

void productosMenorPromedio(eProducto productos[], int tamProd, eProveedor proveedores[], int tamProv)
{
    int i;
    float promedio;

    promedio = totalPromedio(productos, tamProd);
    for (i=0 ; i<tamProd ; i++)
    {
        if (productos[i].importe < promedio)
        {
            mostrarProducto(productos[i], proveedores, tamProv);
        }
    }
    printf("\n\n");
}
