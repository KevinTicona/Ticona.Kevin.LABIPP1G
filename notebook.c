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


char menu()
{

    char opcion;

    system("cls");
    printf(" *** Menu de Opciones *** \n");
    printf("A- Alta Notebook.\n");
    printf("B- Modificar Notebook.\n");
    printf("C- Baja NoteBook.\n");
    printf("D- Listar Notebooks .\n");
    printf("E- Listar Marcas.\n");
    printf("F- Listar Tipos.\n");
    printf("G- Listar Servicios.\n");
    printf("H- Alta Trabajo.\n");
    printf("I- Listar Trabajos.\n");
    printf("Z- Salir.\n");
    printf("\n Eliga una de las Opciones: ");
    fflush(stdin);
    opcion = tolower(getchar());
    system("cls");

    return opcion;
}

int altaNotebook(eNotebook list[], int tam, int ID, eTipo tipo[], int tamT, eMarca marca[], int tamM)
{
    eNotebook newNotebook;
    int validIdTipo;
    int validIdMarca;
    if(list != NULL && tam > 0 && tam <= 100 && tipo != NULL && tamT > 0 && marca != NULL && tamM > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == 1)
            {
                newNotebook.isEmpty = 0;
                newNotebook.id = ID;
                //Modelo
                printf("\nIngrese el Modelo: ");
                fflush(stdin);
                gets(newNotebook.modelo);
                formatName(newNotebook.modelo);
                while(strlen(newNotebook.modelo) > 30 && strlen(newNotebook.modelo) == 0)
                {
                    printf("\nDato invalido. Ingrese marca: ");
                    fflush(stdin);
                    gets(newNotebook.modelo);
                    formatName(newNotebook.modelo);
                }
                //Marca
                mostrarMarcas(marca, tamM);
                printf("\nIngrese el ID de la Marca: ");
                fflush(stdin);
                scanf("%d", &newNotebook.idMarca);
                validIdMarca = findMarcaById(marca, tamM, newNotebook.idMarca);
                while( validIdMarca < 0)
                {
                    printf("\nDato invalido. Ingrese el ID de la Marca: ");
                    fflush(stdin);
                    scanf("%d", &newNotebook.idMarca);
                    validIdMarca = findMarcaById(marca, tamM, newNotebook.idMarca);
                }

                //Tipo
                mostrarTipos(tipo, tamT);
                printf("\nIngrese el ID del Tipo: ");
                fflush(stdin);
                scanf("%d", &newNotebook.idTipo);
                validIdTipo = findTipoById(tipo, tamT, newNotebook.idTipo);
                while( validIdTipo < 0)
                {
                    printf("\nDato invalido. Ingrese el ID del Tipo: ");
                    fflush(stdin);
                    scanf("%d", &newNotebook.idTipo);
                    validIdTipo = findTipoById(tipo, tamT, newNotebook.idTipo);
                }
                //Precio
                printf("\nIngrese el Precio: ");
                fflush(stdin);
                scanf("%f", &newNotebook.precio);

                list[i] = newNotebook;
                return 0;
            }
            else
            {
                printf("\nNo hay lugar para otra bicicleta...\n");
            }
        }
    }
    return -1;
}

void formatName(char name[])
{
    int len;
    strlwr(name);
    name[0] = toupper(name[0]);
    len = strlen(name);
    for(int i = 0; i < len; i++)
    {
        if(name[i] == ' ')
        {
            i++;
            if(name[i] >= 'a' && name[i] <= 'z')
            {
                name[i] = toupper(name[i]);
            }
        }
    }
}

int initNotebooks(eNotebook list[], int len)
{
    if(list != NULL && len > 0 && len <= 100)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        return 0;
    }

    return -1;
}


void mostrarNotebook(eNotebook note, eMarca marca[], int tamM, eTipo tipo[], int tamT)
{
    char descMarca[20];
    char descTipo[20];

    obtenerDescripcionMarca(marca, tamM, note.idMarca, descMarca);

    obtenerDescripcionTipo(tipo, tamT, note.idTipo, descTipo);


    printf("%5d   %10s         %10s          %10s                %4.2f\n",
           note.id,
           note.modelo,
           descMarca,
           descTipo,
           note.precio
          );
}

int mostrarNotebooks(eNotebook list[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{
    if(list != NULL && tam > 0 && tam <= 100 && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0)
    {
        //system("cls");
        printf("\n                             *** Listado de Notebooks ***                         \n");
        printf("----------------------------------------------------------------------------------------\n");
        printf("  ID          Modelo              Marca              Tipo                Precio      \n");
        printf("----------------------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(list[i].isEmpty != 1)
            {
                mostrarNotebook(list[i], marcas, tamM, tipos, tamT);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}



int modificarNotebook(eNotebook list[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT)
{
    eNotebook newNotebook;
    int error = -1;
    int id;
    int indice;
    int opcion;
    int validIdTipo;
    char confirmar;

    if(list != NULL && tam > 0 && tam <= 100 && marca != NULL && tipo != NULL && tamM > 0 && tamT > 0)
    {
        system("cls");
        printf("                    Modificar Notebooks                     \n");
        printf("---------------------------------------------------------------------------------");
        mostrarNotebooks(list,tam,marca,tamM,tipo,tamT);
        printf("\nIngrese ID de la Notebook que desea modificar: ");
        fflush(stdin);
        scanf("%d", &id);
        indice = findNotebookById(list, tam, id);
        if(indice == -1)
        {
            system("cls");
            printf("\nLo sentimos. No hay bicicletas con ese ID...\n");
        }
        else
        {
            system("cls");
            printf("                                     Notebooks      \n");
            printf("--------------------------------------------------------------------------------\n");
            printf("  ID          Modelo              Marca            Tipo               Precio      \n");
            printf("--------------------------------------------------------------------------------\n");
            mostrarNotebook(list[indice], marca, tamM, tipo, tamT);
            printf("\nMODIFICAR:\n");
            printf("1. Precio\n");
            printf("2. Tipo\n");
            printf("Ingrese el numero la opcionq que desea Modificar: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                //Pedir tipo
                printf("\nIngrese el nuevo Precio: ");
                fflush(stdin);
                scanf("%f", &newNotebook.precio);
                //pedir confirmacion
                printf("Desea Modificarlo? s o n\n");
                fflush(stdin);
                scanf("%c", &confirmar);
                confirmar = tolower(confirmar);
                while(confirmar != 's' && confirmar != 'n')
                {
                    printf("\nDato invalida. \nDesea Modificarlo? s o n\n");
                    fflush(stdin);
                    scanf("%c", &confirmar);
                    confirmar = tolower(confirmar);
                }
                if(confirmar == 's')
                {
                    list[indice].precio = newNotebook.precio;
                    error = 0;
                }
                else
                {
                    error = 1;
                }
                break;
            case 2:
                    mostrarTipos(tipo, tamT);
                    printf("\nIngrese el ID del tipo que desea modificar: ");
                    fflush(stdin);
                    scanf("%d", &newNotebook.idTipo);
                    validIdTipo = findTipoById(tipo, tamT, newNotebook.idTipo);
                    while( validIdTipo < 0)
                    {
                        printf("\nDato invalido. Ingrese el ID del tipo que desea modificar: ");
                        fflush(stdin);
                        scanf("%d", &newNotebook.idTipo);
                        validIdTipo = findTipoById(tipo, tamT, newNotebook.idTipo);
                    }
                    printf("Desea Modificarlo? s-si n-no\n");
                    fflush(stdin);
                    scanf("%c", &confirmar);
                    confirmar = tolower(confirmar);
                    while(confirmar != 's' && confirmar != 'n')
                    {
                        printf("\nDato invalida. \nDesea Modificarlo? s o n\n");
                        fflush(stdin);
                        scanf("%c", &confirmar);
                        confirmar = tolower(confirmar);
                    }
                    if(confirmar == 's')
                    {
                        list[indice].idTipo = newNotebook.idTipo;
                        error = 0;
                    }
                    else
                    {
                        error = 1;
                    }
                break;
            default:
                printf("Opcion invalida");
                break;
            }
        }
    }
    return error;
}

int findNotebookById(eNotebook list[], int len,int id)
{
    int indice = -1;
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id && list[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int bajaNotebooks(eNotebook list[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT)
{
    int error = -1;
    int id;
    int indice;
    char confirmation;
    //La funci�n podr�a devolver 3 enteros (0 - ok, -1 error, 1 ok pero no borr� a nadie
    if(list != NULL && tam > 0 && tam <= 100 && marca != NULL && tamM > 0 && tipo != NULL && tamT > 0)
    {
        mostrarNotebooks(list,tam,marca,tamM,tipo,tamT);
        printf("\nIngrese ID de la bicicleta a eliminar: ");
        fflush(stdin);
        scanf("%d", &id);
        indice = findNotebookById(list, tam, id);
        if(indice == -1)
        {
            printf("No hay bicicletas con ese ID\n");
        }
        else
        {
            printf("-------------------------------------------------------------------------------------------\n");
            printf("  ID            Modelo                 Marca               Tipo               Precio      \n");
            printf("-------------------------------------------------------------------------------------------\n");
            mostrarNotebook(list[indice],marca,tamM,tipo,tamT);
            printf("Confirmar baja? s - si; n - no\n");
            fflush(stdin);
            scanf("%c", &confirmation);
            confirmation = tolower(confirmation);
            while(confirmation != 's' && confirmation != 'n')
            {
                printf("Opci�n invalida. s - si; n - no\n");
                fflush(stdin);
                scanf("%c", &confirmation);
                confirmation = tolower(confirmation);
            }

            if(confirmation == 's')
            {
                list[indice].isEmpty = 1;
                error = 0;
            }
            else if(confirmation == 'n')
            {
                error = 1;
            }
        }

    }

    return error;
}