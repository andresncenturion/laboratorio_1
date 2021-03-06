typedef struct
{
    int id;
    char nombre[20];
}eSector;

typedef struct
{
    int day;
    int month;
    int year;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fecha;
    int idSector;
    int isEmpty;
    char nombreSector[20];
}eEmpleado;

void inicializarEmpleados (eEmpleado[], int);
int menu (void);
void altaEmpleado (eEmpleado[], eSector[], int, int);
void mostrarEmpleado (eEmpleado, eSector[], int);
void mostrarEmpleados (eEmpleado[], eSector[], int, int);
int buscarLibre (eEmpleado[], int);
int buscarEmpleado (eEmpleado[], int, int);
int pedirSector (eSector[], int);
void bajaEmpleado (eEmpleado[], int);
void modificarEmpleado (eEmpleado[], eSector[],int, int);
void ordenarEmpleados (eEmpleado[], int);
void totalSueldos(eEmpleado[], int);
void salariosAltos(eEmpleado[], eSector[], int, int);//preguntar si no se puede ahorrar enviar sectores
void empleadosPorSector(eEmpleado[], eSector[], int, int);
void cantidadPorSector(eEmpleado[], eSector[], int, int);
void sueldosPorSector(eEmpleado[], eSector[], int, int);
