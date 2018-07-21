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
char* getDescripcion(eProducto*);
int setCantidad(eProducto*, int);
int parseArchivo(char*, ArrayList*);
int subMenu (void);
void mostrarElemento(eProducto*);
void mostrarElementos(ArrayList*);
int listarElementos (ArrayList*, ArrayList*);
int moverElemento (ArrayList*, ArrayList*);
int buscarCodigo (ArrayList*, int);
int descontarProductos (ArrayList*, ArrayList*);
int sumarProductos(ArrayList*, ArrayList*);
int escribirArchivo(char*, ArrayList*);

