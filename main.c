#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tipo.h"
#include "fecha.h"
#include "marca.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"


#define TAM_T 4
#define TAM_M 4
#define TAM_S 4
#define TAM 10

int main()
{
    char seguir = 's';
    char confirma;

    int validNewNotebook;
    int validModificacion;
    int idNotebook;
    int validBaja;

    eNotebook listNotebooks[TAM];

    eTipo tiposDeNotebooks[TAM_T] =
    {
        {5000, "Gamer"},
        {5001, "Disenio"},
        {5002, "Ultrabook"},
        {5003, "Normalita"}
    };

    eMarca marcasDeNotebooks[TAM_M] =
    {
        {1000, "Compaq"},
        {1001, "Asus"},
        {1002, "Acer"},
        {1003, "HP"}
    };

    eServicio serviciosDeNotebooks[TAM_S] =
    {
        {20000, "Bateria",250},
        {20001, "Antivirus",300},
        {20002, "Actualizacion",400},
        {20003, "Fuente",600}
    };

    initNotebooks(listNotebooks,TAM);

    do
    {
        switch(menu())
        {

        case 'a':

            validNewNotebook = altaNotebook(listNotebooks,TAM,idNotebook,tiposDeNotebooks,TAM_T,marcasDeNotebooks,TAM_M);
            if(validNewNotebook == 0)
            {
                printf("\nOperacion exitosa\n");
                idNotebook++;
            }
            else
            {
                printf("\nHa ocurrido un problema. Intente nuevamente.\n");
            }
            mostrarNotebooks(listNotebooks,TAM,marcasDeNotebooks,TAM_M,tiposDeNotebooks,TAM_T);
            break;
        case 'b':

            validModificacion = modificarNotebook(listNotebooks,TAM,marcasDeNotebooks,TAM_M,tiposDeNotebooks,TAM_T);
            if(!validModificacion)
            {
                printf("\nModificacion exitosa.\n");
            }
            else if(validModificacion == 1)
            {
                printf("\nModificacion cancelada por usuario.\n");
            }
            else
            {
                printf("\nHa ocurrido un problema. Intente nuevamente.\n");
            }
            break;
        case 'c':
            validBaja = bajaNotebooks(listNotebooks,TAM,marcasDeNotebooks,TAM_M,tiposDeNotebooks,TAM_T);
            if(!validBaja)
            {
                printf("\nBaja exitosa.\n");
            }
            else if(validBaja == 1)
            {
                printf("\nBaja cancelada por usuario.\n");
            }
            else
            {
                printf("\nHa ocurrido un problema. Intente nuevamente.\n");
            }
            break;
        case 'd':

            break;
        case 'e':
            mostrarMarcas(marcasDeNotebooks,TAM_M);
            break;
        case 'f':
            mostrarTipos(tiposDeNotebooks,TAM_T);
            break;
        case 'g':
            mostrarServicios(serviciosDeNotebooks,TAM_S);
            break;
        case 'h':
            break;
        case 'i':
            break;
        case 'z':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("Opcion invalida!!!\n");
            break;
        }
        system("pause");
    }
    while( seguir == 's');

    return 0;
}
