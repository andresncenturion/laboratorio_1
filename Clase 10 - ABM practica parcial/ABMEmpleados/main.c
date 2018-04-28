#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
#define TAMSEC 6

typedef struct
{
    int id;
    char nombre[20];
} eSector;

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int idSector;
    int isEmpty;

} eEmpleado;

int menu();
void inicializarEmpleados(eEmpleado[], int);
void mostrarEmpleados(eEmpleado vec[], int tamEmp, eSector[],int);
void mostrarEmpleado(eEmpleado, eSector[], int);
int buscarLibre(eEmpleado[], int);
int buscarEmpleado(eEmpleado[], int, int);
void bajaEmpleado(eEmpleado[], int, eSector[], int);
void altaEmpleado(eEmpleado[], int, eSector[], int);
void modificacionEmpleado(eEmpleado[], int, eSector[], int);
void ordenarEmpleados(eEmpleado[], int);
float sueldoMaximo(eEmpleado[], int);
int pedirSector(eSector[], int);
void empleadosXSector(eEmpleado[], int, eSector[], int);
void CantidadEmpleadosXSector(eEmpleado[], int, eSector[], int);
void totalSueldosXSector(eEmpleado[], int, eSector[], int);
void totalSueldos(eEmpleado[], int);
void empleadosMejorPagos(eEmpleado[], int, eSector[], int);

int main()
{
    int salir = 0;
    eEmpleado gente[TAM]= {{1000, "Juan", 'm', 20000, {12, 5, 2015}, 5, 0},{2212, "Juana", 'f', 15000, {12, 5, 2010}, 3, 0},{5656, "Manuel", 'm', 18500, {12, 5, 2014}, 1, 0}, {3344, "Lucia", 'f', 23200, {2, 10, 2002}, 1, 0},{8658, "Alberto", 'm', 29500, {29, 3, 2008}, 1, 0},{5656, "Andrea", 'f', 34600, {12, 5, 2014}, 2, 0},{2121, "Gabriel", 'm', 34600, {12, 5, 2014}, 6, 0}};
    eSector sectores[]= {{1, "Ventas"}, {2,"Compras"}, {3, "Comercial"}, {4, "RRHH"}, {5, "Sistemas"}, {6, "Legales"}};
    inicializarEmpleados(gente, TAM);
    //harcodeo
    for(int i=0; i< TAMSEC; i++)
    {
        gente[i].isEmpty = 0;
    }



    do
    {
        switch(menu())
        {

        case 1:
            altaEmpleado(gente, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 2:
            bajaEmpleado(gente, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 3:
            modificacionEmpleado(gente, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 4:
            mostrarEmpleados(gente, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 5:
            ordenarEmpleados(gente, TAM);
            system("pause");
            break;
        case 6:
            totalSueldos(gente, TAM);
            break;
        case 7:
            empleadosMejorPagos(gente, TAM, sectores, TAMSEC);
            break;
        case 8:
            empleadosXSector(gente, TAM, sectores, TAMSEC);
            break;
        case 9:
            CantidadEmpleadosXSector(gente, TAM, sectores, TAMSEC);
            break;
        case 10:
            totalSueldosXSector(gente, TAM, sectores, TAMSEC);
            break;
        case 11:
            printf("\nSalir\n\n");
            salir = 1;
            break;
        default:
            printf("\nOpcion Incorrecta\n\n");
            system("pause");
        }
    }
    while(salir != 1);

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("      ---ABM Empleados---\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Ordenar\n");
    printf("6- Total sueldos\n");
    printf("7- Empleados que mas ganan\n");
    printf("8- Mostrar empleados x sector\n");
    printf("9- Informar cuantos empleados hay en cada sector\n");
    printf("10-Informar total de sueldos x Sector\n");
    printf("11-Salir\n");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i< tam; i++)
    {
        vec[i].isEmpty =1;
    }
}

void mostrarEmpleados(eEmpleado vec[], int tamEmp, eSector sectores[],int tamSec)
{
    system("cls");
    printf("      ---Lista de Empleados---\n\n");
    printf("  Legajo  Nombre   Sexo   Sueldo   Fecha de Ingreso  Sector \n\n");
    for(int i=0; i< tamEmp; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec[i], sectores, tamSec);
        }
    }
}

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tam)
{
    int indice;
    for(int i=0; i< tam; i++)
    {
        if(emp.idSector == sectores[i].id )
        {
            indice = i;
            break;
        }
    }
    printf("  %4d%12s     %c  %10.2f    %02d/%02d/%4d     %s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio, sectores[indice].nombre);
}

int buscarLibre(eEmpleado vec[], int tam)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaEmpleado(eEmpleado vec[], int tamEmp, eSector sectores[], int tamSec)
{

    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;

    system("cls");
    printf("---Alta empleado---\n\n");

    indice = buscarLibre(vec, tamEmp);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a empleados nuevos.\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tamEmp, legajo);

        if(esta != -1)
        {
            printf("\nEl legajo %d ya esta dado de alta en el sistema\n", legajo);
            mostrarEmpleado(vec[esta], sectores, tamSec);
        }
        else
        {
            nuevoEmpleado.isEmpty = 0;
            nuevoEmpleado.legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("Ingrese sueldo: ");
            scanf("%f", &nuevoEmpleado.sueldo);

            printf("Ingrese fecha de ingreso d m a: ");
            scanf("%d %d %d", &nuevoEmpleado.fechaIngreso.dia, &nuevoEmpleado.fechaIngreso.mes, &nuevoEmpleado.fechaIngreso.anio);

            nuevoEmpleado.idSector = pedirSector(sectores, tamSec);
            vec[indice] = nuevoEmpleado;

            printf("\nAlta exitosa!!!\n\n");

        }
    }

}

void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int legajo;
    int esta;
    char confirma;

    system("cls");
    printf("---Baja Empleado---\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if(esta == -1)
    {
        printf("\nEl legajo %d no se encuentra en el sistema\n\n", legajo);

    }
    else
    {

        mostrarEmpleado(vec[esta], sectores, tamSec);

        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            vec[esta].isEmpty = 1;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }

    }
}

void modificacionEmpleado(eEmpleado vec[], int tamEmp, eSector sectores[], int tamSec)
{
    int legajo;
    int esta;
    char confirma;
    float sueldo;

    system("cls");
    printf("---Modificacion Empleado---\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tamEmp, legajo);

    if(esta == -1)
    {
        printf("\nEl legajo %d no se encuentra en el sistema\n\n", legajo);

    }
    else
    {

        mostrarEmpleado(vec[esta], sectores, tamEmp);

        printf("\nIngrese nuevo sueldo: ");
        scanf("%f", &sueldo);

        printf("\nConfirma Modificacion?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            vec[esta].sueldo = sueldo;
            printf("\nSe ha modificado el sueldo\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la modificacion\n\n");
        }

    }
}

void ordenarEmpleados(eEmpleado vec[], int tam)
{

    eEmpleado auxEmpleado;

    for(int i=0; i< tam-1; i++)
    {
        for(int j=i +1; j< tam; j++)
        {
            if(vec[i].sexo > vec[j].sexo)
            {
                auxEmpleado = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmpleado;
            }
            else
            {
                if(vec[i].sexo == vec[j].sexo)
                {
                    if(strcmp(vec[i].nombre, vec[j].nombre)>0)
                    {
                        auxEmpleado = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxEmpleado;
                    }

                }

            }
        }
    }
    printf("\nSistema Ordenado\n\n");
}

float sueldoMaximo(eEmpleado vec[], int tam)
{

    float maxSueldo;
    int flag = 0 ;

    for(int i=0; i< tam; i++)
    {

        if( vec[i].sueldo > maxSueldo || flag == 0)
        {
            maxSueldo = vec[i].sueldo;
            flag = 1;
        }
    }
    return maxSueldo;
}




int pedirSector(eSector sectores[], int tam)
{

    int idSector;

    printf("\nSectores\n\n");

    for(int i=0; i< tam; i++)
    {
        printf("%d- %s\n", sectores[i].id, sectores[i].nombre );
    }
    printf("\nIndique Sector: ");
    fflush(stdin);
    scanf("%d", &idSector);

    return idSector;
}


void empleadosXSector(eEmpleado gente[], int tamEmp, eSector sectores[], int tamSec)
{

    system("cls");
    printf("---Listado Empleados por Sector---\n\n");

    for(int i=0; i< tamSec; i++)
    {
        printf("-- %s --\n\n", sectores[i].nombre);

        for(int j=0; j < tamEmp; j++)
        {
            if(gente[j].idSector == sectores[i].id)
            {
                mostrarEmpleado(gente[j], sectores, tamSec);
            }
        }
        printf("\n-----------------------------------------------------------\n");
    }

    printf("\n\n");
    system("pause");

}

void CantidadEmpleadosXSector(eEmpleado gente[], int tamEmp, eSector sectores[], int tamSec)
{

    int contador;
    system("cls");
    printf("---Listado Empleados por Sector---\n\n");

    for(int i=0; i< tamSec; i++)
    {
        printf("-- %s --\n\n", sectores[i].nombre);
        contador =0;

        for(int j=0; j < tamEmp; j++)
        {
            if(gente[j].idSector == sectores[i].id)
            {
                contador++;
            }
        }
        printf("Cantidad empleados: %d\n", contador);
        printf("\n-----------------------------------------------------------\n");
    }

    printf("\n\n");
    system("pause");

}

void totalSueldosXSector(eEmpleado gente[], int tamEmp, eSector sectores[], int tamSec)
{
    int idSector;
    float acumulador = 0;
    system("cls");
    printf("---Total Sueldos por Sector---\n\n");

    idSector = pedirSector(sectores, tamSec) - 1;


    printf("\n-- %s --\n\n", sectores[idSector].nombre);

    for(int i=0; i< tamEmp; i++)
    {

        if(gente[i].idSector == sectores[idSector].id)
        {
            acumulador += gente[i].sueldo;
        }
    }
    printf("Total sueldos $ %.2f\n\n", acumulador);
    system("pause");
}

void totalSueldos(eEmpleado gente[], int tamEmp){

float total = 0;

for(int i=0; i< tamEmp; i++){
    total += gente[i].sueldo;
}

system("cls");
printf("\nEl total de sueldos es $ %.2f\n\n", total);

system("pause");
}

void empleadosMejorPagos(eEmpleado gente[], int tamEmp, eSector sectores[], int tamSec){

    float sueldoMax;
    int flag=0;

    for(int i=0; i< tamEmp; i++){

    if(gente[i].sueldo > sueldoMax || flag == 0){
        sueldoMax = gente[i].sueldo;
        flag = 1;
    }
    }

     for(int i=0; i< tamEmp; i++){

    if(gente[i].sueldo == sueldoMax){
        mostrarEmpleado(gente[i], sectores, tamEmp);
    }

    }

    system("pause");

}





