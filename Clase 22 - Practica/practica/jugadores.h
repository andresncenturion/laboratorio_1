typedef struct
{
    int dorsal;
    char posicion[4];
    char nombre[20];
    char apellido[20];
    int edad;
    int altura;
    char equipo[20];
    int llega;
}eJugador;

eJugador* newJugador (void);
void setDorsal (eJugador*, int);
void setPosicion (eJugador* jugador, char* posicion);
void setNombre (eJugador* jugador, char* nombre);
void setApellido (eJugador*, char*);
void setEdad (eJugador*, int);
void setAltura (eJugador*, int);
void setEquipo (eJugador*, char*);
int parseJugadores(char*, ArrayList*);
void mostrarElemento(eJugador*);
void mostrarElementos(ArrayList*);
int ordenar (void* ,void*);
int calcularSiLlega (void*);
int generarArchivo(ArrayList*, char*);
