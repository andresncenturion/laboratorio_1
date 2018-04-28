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
    int isEmpty;
    int idSector;
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

