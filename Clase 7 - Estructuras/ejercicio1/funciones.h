typedef struct
{
    int day;
    int month;
    int year;
}eFechaIngreso;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFechaIngreso fecha;
}eEmpleado;

eEmpleado pedirEmpleado (eEmpleado);
void mostrarEmpleado (eEmpleado);
void mostrarEmpleados (eEmpleado[], int);
char validarSexo (char);
int validarMayorCero (int, char[]);

