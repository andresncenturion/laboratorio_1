typedef struct
{
    int id;
    char nombre[20];
    char direccion[20];
    int horas;
    float sueldo;
}eEmpleado;

eEmpleado* newEmpleado (void);
int setId(eEmpleado*, int);
int setNombre(eEmpleado*, char*);
int setDireccion(eEmpleado*, char*);
int setHoras(eEmpleado*, int);
int setSueldo(eEmpleado*, float);
int getId(eEmpleado*);
char* getNombre(eEmpleado*);
char* getDireccion(eEmpleado*);
int getHoras(eEmpleado*);
float getSueldo(eEmpleado*);
int parseEmpleados(char*, ArrayList*);
void mostrarEmpleado (eEmpleado*);
void mostrarEmpleados (ArrayList*);
int listarOrdenados(void*, void*);
int calcularSueldos(void*);
int filtrarSueldos(void*);
int generarArchivo(ArrayList*, char*);
