typedef struct
{
    int codigo;
    char descripcion[50];
}eProveedor;

typedef struct
{
    int codigo;
    char descripcion[50];
    float importe;
    int cantidad;
    int estado;
    int idProveedor;
}eProducto;

void incializarProductos(eProducto[], int);
int menu(void);
void altaProducto(eProducto[], int, eProveedor[], int);
int buscarLibre(eProducto[], int);
int pedirProveedor(eProveedor[], int);
void modificarProducto(eProducto[], int, eProveedor[], int);
int buscarProducto(eProducto[], int, int);
void mostrarProducto(eProducto, eProveedor[], int);
void bajaProducto(eProducto[], int, eProveedor[], int);
void mostrarProductos(eProducto[], int, eProveedor[],int);
void informar(eProducto[], int, eProveedor[], int);
void listar(eProducto[], int, eProveedor[], int);
float totalPromedio(eProducto[], int);
void superaPromedio (eProducto[], int, int);
void noSuperaPromedio (eProducto[], int, int);
int superaStock(eProducto[], int);
int noSuperaStock(eProducto[], int);
void ordenarProductos(eProducto[], int, eProveedor[], int);
void productosMenorDiez(eProducto[], int, eProveedor[], int);
void productosMayorDiez(eProducto[], int, eProveedor[], int);
void productosMayorPromedio(eProducto[], int, eProveedor[], int);
void productosMenorPromedio(eProducto[], int, eProveedor[], int);
