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
#include "cliente.h"
#include "informes.h"


#define TAM_T 4
#define TAM_M 4
#define TAM_S 4

#define TAM_C 4
#define TAM_W 10
#define TAM 10

int main()
{
    char seguir = 's';
    char confirma;

    int validNewNotebook;
    int validModificacion;
    int validNewTrabajo;
    int total = 0;;
    int idNotebook = 20;
    int idTrabajo = 10000;
    int idCliente = 3000;
    int validBaja;

    eNotebook listNotebooks[TAM];
    eTrabajo listTrabajos [TAM_W];
    eCliente listClientes[TAM_C];

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
        {1003, "Hp"}
    };

    eServicio serviciosDeNotebooks[TAM_S] =
    {
        {20000, "Bateria",250},
        {20001, "Antivirus",300},
        {20002, "Actualizacion",400},
        {20003, "Fuente",600}
    };

    eCliente clientesDeNotebooks[TAM_C] =
    {
        {3000, "Florencia", 'f'},
        {3001, "Ovaldo", 'm'},
        {3002, "Pedro", 'm'},
        {3003, "Caterine", 'f'}
    };

    initNotebooks(listNotebooks,TAM);
    initTrabajos(listTrabajos,TAM_W);
    initClientes(listClientes, TAM_C);

    do
    {
        switch(menu())
        {

        case 'a':
            validNewNotebook = altaNotebook(listNotebooks,TAM,idNotebook,tiposDeNotebooks,TAM_T,marcasDeNotebooks,TAM_M, clientesDeNotebooks, TAM_C);
            if(validNewNotebook == 0)
            {
                printf("\nOperacion exitosa\n");
                idNotebook++;
                idCliente++;
                total++;
            }
            else
            {
                printf("\nHa ocurrido un problema. Intente nuevamente.\n");
            }
            mostrarNotebooks(listNotebooks,TAM,marcasDeNotebooks,TAM_M,tiposDeNotebooks,TAM_T,clientesDeNotebooks,TAM_C);
            break;
        case 'b':

            validModificacion = modificarNotebook(listNotebooks,TAM,marcasDeNotebooks,TAM_M,tiposDeNotebooks,TAM_T,clientesDeNotebooks,TAM_C);
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
            validBaja = bajaNotebooks(listNotebooks,TAM,marcasDeNotebooks,TAM_M,tiposDeNotebooks,TAM_T,clientesDeNotebooks,TAM_C);
            if(!validBaja)
            {
                printf("\nBaja exitosa.\n");
                total--;
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
            ordenarNotebooks(listNotebooks,total,marcasDeNotebooks);
            mostrarNotebooks(listNotebooks,TAM,marcasDeNotebooks,TAM_M,tiposDeNotebooks,TAM_T,clientesDeNotebooks,TAM_C);
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
            validNewTrabajo = altaTrabajo(listTrabajos,listNotebooks,TAM,idTrabajo,serviciosDeNotebooks,TAM_S,tiposDeNotebooks,TAM_T,marcasDeNotebooks,TAM_M,clientesDeNotebooks,TAM_C);
            if(validNewTrabajo == 0)
            {
                printf("\nOperacion exitosa\n");
                idTrabajo++;
            }
            else
            {
                printf("\nHa ocurrido un problema. Intente nuevamente.\n");
            }
            break;
        case 'i':
            mostrarTrabajos(listTrabajos,TAM_W,serviciosDeNotebooks,TAM_S,listNotebooks,TAM,clientesDeNotebooks,TAM_C);
            break;
        case 'j':
            menu_Informes(listNotebooks,TAM,marcasDeNotebooks,TAM_M,tiposDeNotebooks,TAM_T,clientesDeNotebooks,TAM_C,serviciosDeNotebooks, TAM_S,listTrabajos,TAM_W);
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
