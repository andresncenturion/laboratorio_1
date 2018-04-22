typedef struct
{
    int day;
    int month;
    int year;
}eFechaIngreso;

typedef struct
{
    char nombre[20];
    int legajo;
    char sexo;
    float sueldo;
    eFechaIngreso fecha;
}eEmpleado;

eEmpleado pedirEmpleado (eEmpleado);
void mostrarEmpleado (eEmpleado);
void mostrarEmpleados (eEmpleado[], int);
void ordenarPorNombre(eEmpleado[], int);
void ordenarPorLegajo(eEmpleado[], int);
void ordenarPorSueldo(eEmpleado[], int);
void ordenarPorSexoYLegajo(eEmpleado[], int);
char validarSexo (char);
int validarMayorCero (int, char[]);

