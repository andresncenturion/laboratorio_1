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
}eEmpleado;

int menu (void);
void inicializarEmpleados (eEmpleado[], int);
void altaEmpleado (eEmpleado[], int);
int buscarLibre (eEmpleado[], int);
int buscarEmpleado (eEmpleado[], int, int);
eEmpleado pedirEmpleado (eEmpleado);
void mostrarEmpleado (eEmpleado);
void mostrarEmpleados (eEmpleado[], int);
void bajaEmpleado (eEmpleado[], int);
void modificarEmpleado (eEmpleado[], int);
