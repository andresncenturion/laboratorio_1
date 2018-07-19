typedef struct
{
    int id;
    char descripcion;
    int cantidad;
}eProducto;

int menu (void);
eProducto* newProducto (void);
int setId(eProducto*, int);
int setDescripcion(eProducto*, char*);
int setCantidad(eProducto*, int);
int parseArchivo(char*, ArrayList*);
int subMenu (void);
void mostrarElemento(eProducto*);
void mostrarElementos(ArrayList*);

