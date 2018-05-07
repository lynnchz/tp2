#define FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



typedef struct
{
    char nombre[50];
    int dni;
    int edad;
    int estado;
} ePersona;

int funcionMenu();

void AgregarP(ePersona pers[], int cant);

int EspacioLibre(ePersona pers[],int cant);

void inicializarEstadoPersona(ePersona pers[],int cant);

int BuscadorDni(ePersona pers[],int cant,int dni);

void mostrarP(ePersona pers);

void ordenarP(ePersona pers[],int PER);

void MPersonas(ePersona pers[],int cant);

int GraficoDB(ePersona pers[], int cant);




