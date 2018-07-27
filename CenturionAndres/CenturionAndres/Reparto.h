typedef struct
{
    int id;
    char producto[20];
    char direccion[20];
    char localidad[20];
    char recibe[20];
}eReparto;

int menu(void);
eReparto* newReparto(void);
int setId(eReparto*, int);
int getId(eReparto*);
int setProducto(eReparto*, char*);
char* getProducto(eReparto*);
int setDireccion(eReparto*, char*);
char* getDireccion(eReparto*);
int setLocalidad(eReparto*, char*);
char* getLocalidad(eReparto*);
int setRecibe(eReparto*, char*);
char* getRecibe(eReparto*);
int parseArchivo(ArrayList* lista);
void mostrarElemento(eReparto*);
void imprimirEntregas(ArrayList*);
void imprimirLocalidades (ArrayList*, ArrayList*);
void pedirLocalidades (ArrayList*, ArrayList*);
int listarOrdenados (void*, void*);
int generarArchivo(ArrayList*, ArrayList*);
