typedef struct
{
    int id;
    char nombre[50];
    char email[50];
    int dni;
    char id_producto[50];
    char observaciones[512];
}eLlamada;

int menu(void);
int setId(eLlamada*, int);
int setNombre(eLlamada*, char*);
int setEmail(eLlamada*, char*);
int setDni(eLlamada*, int);
int setId_Producto(eLlamada*, char*);
int setObservaciones(eLlamada*, char*);
int parseArchivo(ArrayList*);
eLlamada* newLlamada(void);
void mostrarElemento(eLlamada*);
void imprimirLlamadas(ArrayList*);
int buscarDni(ArrayList*, int);
int buscarProducto(ArrayList*, char*);
void imprimirEstadistica(ArrayList*);
int filtrarDni(ArrayList*, int);
void filtrarLista (ArrayList*, ArrayList*);
int generarArchivo(ArrayList*, ArrayList*);
