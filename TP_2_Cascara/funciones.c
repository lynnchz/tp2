#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"




void inicializarEstadoPersona(ePersona pers[],int PER)
{
    for(int i=0; i<PER; i++)
    {
        pers[i].estado = 0;
    }
}
int funcionMenu()
{
    system("color A");
    int opcion;
    system("cls");
    printf("\tREGISTRO DE PERSONAS \n\n");
    printf("1-Agregar una persona\n");
    printf("2-Borrar una persona\n");
    printf("3-Imprimir lista ordenada por nombre\n");
    printf("4-Grafico\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
int obtEspacioLibre(ePersona pers[],int PER)
{
    int indice=-1;
    for(int i=0; i<PER; i++)
    {
        if(pers[i].estado == 0)
        {
            indice =i;
            break;
        }
    }
    return indice;
}
int buscarDni(ePersona pers[],int PER,int dni)
{
    int esta = -1;
    for(int i=0; i<PER; i++)
    {
        if(pers[i].estado == 1 && pers[i].dni == dni)
        {
            esta = i;
            break;
        }
    }
    return esta;
}
void AgregarP(ePersona pers[], int PER)
{
    system("cls");

    int esta;
    int dni;
    int espacioLibre = obtEspacioLibre(pers,PER);

    if(espacioLibre <0)
    {
        printf("Lamento ser yo quien le informe esto, pero el sistema se encuentra lleno.\n");
        system("pause");
    }
    else
    {
        printf("\tAGREGAR PERSONA\n\n");
        printf("\nIngrese DNI, sin puntos ni espacios: ");
        scanf("%d",&dni);

        esta = buscarDni(pers,PER,dni);

        if(esta == -1)
        {
            pers[espacioLibre].dni = dni;
            printf("\nNombre: ");
            fflush(stdin);
            scanf("%s", pers[espacioLibre].nombre);
            printf("\nEdad: ");
            fflush(stdin);
            scanf("%d", &pers[espacioLibre].edad);
            pers[espacioLibre].estado = 1;
            system("cls");
            printf("Se agrego a la persona con exito!\n");
            printf("Nombre\t\tedad\t\tDNI\n\n");
            mostrarP(pers[espacioLibre]);
            system("pause");


        }
        else
        {
            system("cls");
            printf("ERROR! \n");
            printf("El dni: %d corresponde a:  \n",dni);
            printf("Nombre\t\tedad\tDNI\n\n");
            mostrarP(pers[esta]);
            system("pause");
            system("cls");
        }
    }
}
void mostrarP(ePersona pers)
{
    pers.nombre[0]= toupper(pers.nombre[0]);
    printf("%s\t%d\t%d\n",pers.nombre,pers.edad, pers.dni);
}
void MPersonas(ePersona pers[],int PER)
{
    system("cls");
    ordenarP(pers,PER);
    printf("MOSTRAR PERSONAS\n");
    printf("Nombre\t\tedad\tDNI\n");
    for(int i=0; i<PER; i++)
    {
        if(pers[i].estado==1)
        {
            mostrarP(pers[i]);
        }
    }
    system("pause");
}
void BorrarP(ePersona pers[],int PER)
{
    system("cls");
    int dni;
    char opcion;
    int esta;

    printf("\t BORRAR PERSONAS \n\n");
    printf("Ingrese el DNI de la persona que quiere borrar: ");
    scanf("%d",&dni);

    esta=buscarDni(pers,PER,dni);

    if(esta >= 0)
    {
        printf("Persona encontrada: \n");
        printf("Nombre\tedad\tDNI\n");
        mostrarP(pers[esta]);
        printf("¿Seguro que desea borrar a esta persona del sistema? s/n: ");
        fflush(stdin);
        scanf("%c",&opcion);
        if(opcion == 'n')
        {
            printf("Se ha cancelado la eliminacion\n");
            system("pause");

        }
        else
        {
            system("cls");
            printf("\nSe ha eliminado con exito!\n");
            printf("%s fue borrado del sistema...\n",pers[esta].nombre);
            pers[esta].estado = 0;
            system("pause");
        }
    }
    else
    {
        printf("ERROR! el dni: %d ingresado no esta en el sistema, porfavor ingrese un dni valido!\n\n",dni);
        system("pause");
    }
}
void ordenarP(ePersona pers[],int PER)
{

    ePersona aux;
    for(int i=0; i<PER-1; i++)
    {
        for(int j=i+1; j<PER; j++)
        {
            if(strcmp(pers[i].nombre,pers[j].nombre)>0)
            {
                aux = pers[i];
                pers[i] = pers[j];
                pers[j] = aux;
            }
            else
            {
                if(strcmp(pers[i].nombre,pers[j].nombre)==0)
                {
                    if(pers[i].dni < pers[j].dni)
                    {
                        aux = pers[i];
                        pers[i] = pers[j];
                        pers[j] = aux;
                    }
                }
            }
        }
    }
}
int GraficoDB(ePersona pers[], int PER)
{
    int rango1=0;
    int rango2=0;
    int rango3=0;
    int i=0;
    int mayor;
    int band=0;

    for (int e; e<PER; e++)
    {
        if (pers[e].edad > 0 && pers[e].edad <=18&&pers[e].estado==1)
        {
            rango1++;
        }
        if (pers[e].edad>=19&&pers[e].edad <=35&&pers[e].estado==1)
        {
            rango2++;
        }

        if(pers[e].edad>35&&pers[e].estado==1)
        {
            rango3++;
        }
    }
    if (rango1>=rango2&& rango1>=rango3)
    {
        mayor = rango1;
    }

    else
    {
        if (rango2>=rango1 &&rango2 >=rango3)
        {
            mayor=rango2;
        }
        else
            mayor = rango3;

    }
    for (i=mayor; i>0; i--)
    {
        if(i<=rango1)
        {
            printf("*");
        }
        if (i<=rango2)
        {
            band=1;
            printf("\t*");
        }
        if(i<=rango3)
        {
            if (band==0)
            {
                printf("\t\t*");
            }
            if (band==1)
            {
                printf("\t*");
            }
        }
        printf("\n");
    }
    printf("<18\t19-35\t>35\n");
    system("pause");
    return 0;
}
