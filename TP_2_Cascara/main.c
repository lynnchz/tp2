#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#define PER 3



int main()
{
    system("color A");
    ePersona personas[PER];
    inicializarEstadoPersona(personas,PER);
    int opcion = 0;
    do
    {
        int funcionMenu();
        switch(funcionMenu())
        {
        case 1:
            AgregarP(personas,PER);
            break;
        case 2:
            BorrarP(personas,PER);
            break;
        case 3:
            MPersonas(personas,PER);
            break;
        case 4:
            GraficoDB(personas, PER);
            break;
        case 'ESC':
            break;
        }
    }
    while(opcion != 27);
    return 0;
}
