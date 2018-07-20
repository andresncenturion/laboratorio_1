typedef struct
{
    int id;
    char descripcion[20];
    int cantidad;
}eProducto;

int menu (void);
eProducto* newProducto(void);
int setId(eProducto*, int);
int getId(eProducto*);
int setDescripcion(eProducto*, char*);
int setCantidad(eProducto*, int);
int parseArchivo(char*, ArrayList*);
int subMenu (void);
void mostrarElemento(eProducto*);
void mostrarElementos(ArrayList*);
int moverElemento (ArrayList*, ArrayList*);

