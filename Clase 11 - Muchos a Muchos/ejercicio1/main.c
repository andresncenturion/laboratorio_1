#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUMNOS 20
#define MAX_MATERIAS 8
#define MAX_INSCRIPCIONES 160

typedef struct
{
    int legajo;
    char nombre[20];
} eAlumno;

typedef struct
{
    int codigo;
    char descripcion[20];
} eMateria;

typedef struct
{
    int legAlumno;
    int codMateria;
} eInscripcion;

void mostrarAlumnosConMaterias (eAlumno[], int, eMateria[], int, eInscripcion[], int);
void alumnosPorMateria (eMateria[], int, eInscripcion[], int);
int cantidadInscriptos (int, eInscripcion[], int);
void materiasMasCursadas (eMateria[], int, eInscripcion[], int);
void nombresPorMateria (eAlumno[], int, eMateria[], int, eInscripcion[], int);

int main()
{
    eAlumno alumnos[] = {{1001, "fabricio"}, {1002, "alan"}, {1003, "laura"}, {1004, "martin"}, {1005, "marina"}};
    eMateria materias[] = {{1, "programacion"}, {2, "matematica"}, {3, "spd"}, {4, "laboratorio"}};
    eInscripcion inscripciones[] = {{1001, 3}, {1002, 4}, {1001, 1}, {1003, 3}, {1005, 2}};

    mostrarAlumnosConMaterias(alumnos, 5, materias, 4, inscripciones, 5);
    alumnosPorMateria(materias, 4, inscripciones, 5);
    materiasMasCursadas(materias, 4, inscripciones, 5);
    nombresPorMateria(alumnos, 5, materias, 4, inscripciones, 5);

    system("pause");
    return 0;
}

void mostrarAlumnosConMaterias (eAlumno alumnos[], int tamAlu, eMateria materias[], int tamMat, eInscripcion inscripciones[], int tamIns)
{
    int i = 0;
    int j = 0;
    int k = 0;

    system("cls");
    printf("--- MATERIAS DE CADA ALUMNO ---\n");
    for (i=0 ; i<tamAlu ; i++)
    {
        printf("\n%s", alumnos[i].nombre);
        for (j=0 ; j<tamIns ; j++)
        {
            if (alumnos[i].legajo == inscripciones[j].legAlumno)
            {
                for (k=0 ; k<tamMat ; k++)
                {
                    if (inscripciones[j].codMateria == materias[k].codigo)
                    {
                        printf("\n\t%s", materias[k].descripcion);
                    }
                }
            }
        }
    }
    printf("\n\n");
}

void alumnosPorMateria (eMateria materias[], int tamMat, eInscripcion inscripciones[], int tamIns)
{
    int i = 0;
    int j = 0;
    int contAlumnoInscripto = 0;

    printf("--- CANTIDAD DE ALUMNOS POR MATERIA ---\n");
    for (i=0 ; i<tamMat ; i++)
    {
        printf("\n%s: ", materias[i].descripcion);
        for (j=0 ; j<tamIns ; j++)
        {
            if (materias[i].codigo == inscripciones[j].codMateria)
            {
                contAlumnoInscripto++;
            }
        }
        printf("%d", contAlumnoInscripto);
        contAlumnoInscripto = 0;
    }
    printf("\n\n");
}

int cantidadInscriptos (int codigo, eInscripcion inscripciones[], int tamIns)
{
    int inscriptos = 0;
    int i;

    for (i=0 ; i<tamIns ; i++)
    {
            if (codigo == inscripciones[i].codMateria)
            {
                inscriptos++;
            }
    }
    return inscriptos;
}

void materiasMasCursadas (eMateria materias[], int tamMat, eInscripcion inscripciones[], int tamIns)
{
    int i;
    int index;
    int inscriptos;
    int flagMaximo = 0;
    int maxInscriptos;

    printf("--- MATERIAS MAS CURSADAS ---\n");
    for (i=0 ; i<tamMat ; i++)
    {
        inscriptos = cantidadInscriptos(materias[i].codigo, inscripciones, tamIns);
        if ((inscriptos > maxInscriptos) || (flagMaximo == 0))
        {
            index = i;
            flagMaximo = 1;
            maxInscriptos = inscriptos;
        }
    }
    printf("%s: %d", materias[index].descripcion, maxInscriptos);
    printf("\n\n");
}

void nombresPorMateria (eAlumno alumnos[], int tamAlu, eMateria materias[], int tamMat, eInscripcion inscripciones[], int tamIns)
{
    int i;
    int j;
    int k;

    printf("--- INSCRIPTOS POR MATERIA ---\n");
    for (i=0 ; i<tamMat ; i++)
    {
        printf("\n%s", materias[i].descripcion);
        for (j=0 ; j<tamIns ; j++)
        {
            if (materias[i].codigo == inscripciones[j].codMateria)
            {
                for (k=0 ; k<tamAlu ; k++)
                {
                    if (inscripciones[j].legAlumno == alumnos[k].legajo)
                    {
                        printf("\n\t%s", alumnos[k].nombre);
                    }
                }
            }
        }
    }
    printf("\n\n");
}
