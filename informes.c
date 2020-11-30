#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tipo.h"
#include "marca.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"
#include "informes.h"
#include "validaciones.h"

int menu_Informes(
    eNotebook listNote[],
    int tam,
    eMarca listMarcas[],
    int tamM,
    eTipo listTipos[],
    int tamT,
    eCliente listCliente[],
    int tamC,
    eServicio listServi[],
    int tamS,
    eTrabajo listTrabajo[],
    int tamW
)
{
    int opcionMenu;
    int opcionMenuValid;
    int error = -1;

    do
    {
        informes_subMenu();
        opcionMenu = validations_getOption(&opcionMenuValid, "\nOpcion invalida.\n", 1, 11);

        if(!opcionMenu)
        {
            switch(opcionMenuValid)
            {

            case 1:
                menu_prinfSubEncabezado();
                informe_noteboookPorTipoSeleccionado(listNote,tam,listTipos,tamT,listMarcas,tamM,listCliente,tamC);
                break;
            case 2:
                menu_prinfSubEncabezado();
                informe_noteboookPorMarcaSeleccionado(listNote,tam,listTipos,tamT,listMarcas,tamM,listCliente,tamC);
                break;
            case 3:
                menu_prinfSubEncabezado();
                informes_notebooksMasBaratas(listNote, tam);
                break;
            case 4:
                menu_prinfSubEncabezado();
                informes_notebooksSeparadasPorMarca(listNote,tam, listMarcas,tamM, 1);
                break;
            case 5:
                menu_prinfSubEncabezado();
                informes_notebooksContarPorTipoyMarca(listNote,tam,listTipos,tamT,listMarcas,tamM,listCliente,tamC);
                break;
            case 6:
                menu_prinfSubEncabezado();
                informes_notebooksMasElegidas(listNote, tam, listMarcas, tamM);
                break;
            case 7:
                menu_prinfSubEncabezado();
                informes_todosLosTrabajosNote(listNote,tam,listTipos,tamT,listMarcas,tamM,listCliente,tamC,listServi,tamS,listTrabajo,tamW);
                break;
            case 8:
                menu_prinfSubEncabezado();
                informes_serviciosSumaPrecio(listNote,tam,listTipos,tamT,listMarcas,tamM,listCliente,tamC,listServi,tamS,listTrabajo,tamW);
                break;
            case 9:
                menu_prinfSubEncabezado();
                informes_serviciosYMostrar(listNote,tam,listTipos,tamT,listMarcas,tamM,listCliente,tamC,listServi,tamS,listTrabajo,tamW);
                break;
            case 10:
                menu_prinfSubEncabezado();
                informes_fechaServicios(listServi,tamS,listTrabajo,tamW);
                break;
            case 11:
                printf("Volviendo al menu principal.");
                break;
            default:
                printf("Opcion invalida!!!\n");
                break;
            }
            error = 0;
            system("pause");
        }
    }
    while(opcionMenuValid != 11);
    return error;
}

void informes_subMenu()
{
    system("cls");

    printf(" *** Menu de Informes *** \n");
    printf("1. Mostrar las notebooks del tipo seleccionado por el usuario.\n");
    printf("2. Mostrar notebooks de una marca seleccionada.\n");
    printf("3. Informar la o las notebooks más baratas.\n");
    printf("4. Mostrar un listado de las notebooks separadas por marca.\n");
    printf("5. Elegir un tipo y una marca y contar cuantas notebooks hay de ese tipo y esa marca.\n");
    printf("6. Mostrar la o las marcas más elegidas por los clientes.\n");
    printf("7. Pedir una notebook y mostrar todos los trabajos que se le hicieron a la misma.\n");
    printf("8. Pedir un notebook e informar la suma de los importes de los services se le hicieron a la misma\n");
    printf("9. Pedir un servicio y mostrar las notebooks a las que se realizó ese servicio y la fecha.\n");
    printf("10. Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
    printf("11. Volver al menu principal.\n");
}

int informe_noteboookPorTipoSeleccionado(eNotebook listNotes[], int tamN, eTipo listTipos[], int tamT, eMarca listMarcas[], int tamM, eCliente listClientes[], int tamC)
{
    int error = -1;
    int validIdTipo;

    if(listNotes !=  NULL && tamN > 0 && listTipos != NULL && tamT > 0 && listMarcas != NULL && tamM > 0 && listClientes != NULL && tamC > 0 )
    {
        mostrarTipos(listTipos, tamT);
        printf("\nIngrese el ID del Tipo:");
        fflush(stdin);
        scanf("%d", & validIdTipo);
        validIdTipo = findTipoById(listTipos,tamT,validIdTipo);
        while(findTipoById < 0)
        {
            printf("\nDato invalido. Ingrese el ID del Tipo:");
            fflush(stdin);
            scanf("%d", & validIdTipo);
            validIdTipo = findTipoById(listTipos,tamT,validIdTipo);
        }
        menu_printEncabezado();
        for(int i = 0; i < tamN; i++)
        {
            if(listNotes[i].idTipo == validIdTipo)
            {
                mostrarNotebook(listNotes[i], listMarcas, tamM, listTipos, tamT, listClientes, tamC);
            }
        }
        error = 0;
    }
    return error;
}

void menu_printEncabezado()
{
    system("cls");
    printf("\n                                    *** Listado de Notebooks ***                                      \n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf(" ID           Modelo              Marca              Tipo                Precio            Cliente      \n");
    printf("--------------------------------------------------------------------------------------------------------\n");
}

void menu_prinfSubEncabezado()
{
    printf("\n                                           *** Notebooks ***                                         \n");
    printf("--------------------------------------------------------------------------------------------------------\n");
}

void menu_printEncabezadoTrabajos()
{
    system("cls");
    printf("\n                                    *** Listado de Trabajos ***                         \n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf(" IdServi       Modelo          Servicio          Precio del Servicio     Cliente           Fecha      \n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
}


int informe_noteboookPorMarcaSeleccionado(eNotebook listNotes[], int tamN, eTipo listTipos[], int tamT, eMarca listMarcas[], int tamM, eCliente listClientes[], int tamC)
{
    int error = -1;
    int validIdMarca;

    if(listNotes !=  NULL && tamN > 0 && listTipos != NULL && tamT > 0 && listMarcas != NULL && tamM > 0 && listClientes != NULL && tamC > 0 )
    {
        mostrarMarcas(listMarcas, tamM);
        printf("\nIngrese el ID del Marca:");
        fflush(stdin);
        scanf("%d", & validIdMarca);
        validIdMarca = findMarcaById(listMarcas,tamM,validIdMarca);
        while(findMarcaById < 0)
        {
            printf("\nDato invalido. Ingrese el ID del Marca:");
            fflush(stdin);
            scanf("%d", & validIdMarca);
            validIdMarca = findMarcaById(listMarcas,tamM,validIdMarca);
        }
        menu_printEncabezado();
        for(int i = 0; i < tamN; i++)
        {
            if(listNotes[i].idMarca == validIdMarca)
            {
                mostrarNotebook(listNotes[i], listMarcas, tamM, listTipos, tamT, listClientes, tamC);
            }
        }
        error = 0;
    }
    return error;
}

int informes_notebooksMasBaratas(eNotebook listNote[],int tam)
{
    int error = -1;
    eNotebook auxBici;

    if(listNote != NULL && tam > 0)
    {
        for(int i = 0; i < tam-1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(listNote[i].precio > listNote[j].precio)
                {
                    auxBici = listNote[i];
                    listNote[i] = listNote[j];
                    listNote[j] = auxBici;
                }
            }
        }
        error = 0;
    }

    return error;
}

int informes_notebooksSeparadasPorMarca(eNotebook listNote[], int tam, eMarca listMarcas[], int tamM, int criterio)
{
    int error = -1;
    char auxMarcaI[20];
    char auxMarcaJ[20];

    eNotebook auxNote;

    if(listNote != NULL && tam > 0 && listMarcas != NULL && tamM > 0 && criterio >= 0 && criterio <= 1)
    {
        for(int i = 0; i < tam-1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                obtenerDescripcionMarca(listMarcas,tam, listNote[i].idMarca,auxMarcaI);
                obtenerDescripcionMarca(listMarcas,tam, listNote[j].idMarca,auxMarcaJ);
                if(((strcmp(auxMarcaI,auxMarcaJ) < 0) && criterio) || ((strcmp(auxMarcaI,auxMarcaJ) > 0) && !criterio ))
                {
                    auxNote = listNote[i];
                    listNote[i] = listNote[j];
                    listNote[j] = auxNote;
                }
            }
        }
        error = 0;
    }

    return error;
}

int informes_notebooksContarPorTipoyMarca(eNotebook listNotes[], int tamN, eTipo listTipos[], int tamT, eMarca listMarcas[], int tamM, eCliente listClientes[], int tamC)
{
    int error = -1;

    int validIdMarca;
    int validIdTipo;

    int marcaValida;
    int tipoValido;

    int contador = 0;

    if(listNotes != NULL && tamN > 0 && listTipos != NULL && tamT > 0 && listMarcas != NULL && tamM > 0 && listClientes != NULL && tamC > 0 )
    {
        //pedir Tipo
        system("cls");
        mostrarTipos(listTipos, tamT);
        printf("\nIngrese el ID del Tipo:\n");
        fflush(stdin);
        scanf("%d", &tipoValido);

        validIdTipo = findTipoById(listTipos, tamT, tipoValido);
        while(validIdTipo < 0)
        {
            printf("\nDato invalido. Ingrese ID tipo: ");
            fflush(stdin);
            scanf("%d", &tipoValido);
            validIdTipo = findTipoById(listTipos, tamT, tipoValido);
        }
        //pedir Marca
        system("cls");
        mostrarMarcas(listMarcas, tamM);
        printf("\nIngrese el Id de la Marca:\n");
        fflush(stdin);
        scanf("%d", &marcaValida);
        validIdMarca = findMarcaById(listMarcas, tamM, marcaValida);
        while(validIdMarca < 0)
        {
            printf("\n Dato invalido. Ingrese el Id de la Marca: ");
            fflush(stdin);
            scanf("%d", &marcaValida);
            validIdMarca = findMarcaById(listMarcas, tamM, marcaValida);
        }
        //mostrar por tipo y color, sino no hay bicicletas con esas caracteristicas
        menu_printEncabezado();
        for(int i = 0; i < tamN; i++)
        {
            if(listNotes[i].idTipo == tipoValido && listNotes[i].idMarca == marcaValida)
            {
                mostrarNotebook(listNotes[i], listMarcas, tamM, listTipos, tamT, listClientes,tamC);
                contador++;
            }
        }
        if(contador == 0)
        {
            printf("\nNo hay Notebooks con esas caracteristicas\n");
        }
        else
        {
            printf("\nHay %d Notebook/s con esas caracteristicas\n", contador);
        }

        error = 0;
    }

    return error;
}

int informes_notebooksMasElegidas(eNotebook* listNotes, int tamN, eMarca* listMarcas,int tamM)
{
    int error = -1;
    int contadorCompaq = 0;
    int contadorAsus = 0;
    int contadorAcer = 0;
    int contadorHp = 0;
    char descMarca[20];

    if(listNotes != NULL && tamN > 0 && listMarcas != NULL && tamM > 0)
    {
        for(int i = 0; i < tamN; i++)
        {
            switch(listNotes[i].idMarca)
            {
            case 1000:
                contadorCompaq++;
                break;
            case 1001:
                contadorAsus++;
                break;
            case 1002:
                contadorAcer++;
                break;
            case 1003:
                contadorHp++;
                break;
            }
        }
        //Obtener el mayor contador
        system("cls");
        if(contadorCompaq > contadorAsus && contadorCompaq > contadorAcer && contadorCompaq > contadorHp)
        {
            obtenerDescripcionMarca(listMarcas,tamM, 1000, descMarca);
            printf("\nEl tipo mas elegido es %s\n", descMarca);
        }
        else if(contadorAsus >= contadorCompaq && contadorAsus > contadorAcer && contadorAsus > contadorHp)
        {
            obtenerDescripcionMarca(listMarcas,tamM, 1001, descMarca);
            printf("\nEl tipo mas elegido es %s\n", descMarca);
        }
        else if(contadorAcer >= contadorAsus && contadorAcer > contadorCompaq && contadorAcer > contadorHp)
        {
            obtenerDescripcionMarca(listMarcas,tamM, 1002, descMarca);
            printf("\nEl tipo mas elegido es %s\n", descMarca);
        }
        else if(contadorHp >= contadorAcer && contadorHp > contadorCompaq && contadorHp > contadorAsus)
        {
            obtenerDescripcionMarca(listMarcas,tamM, 1003, descMarca);
            printf("\nEl tipo mas elegido es %s\n", descMarca);
        }

        error = 0;
    }

    return error;
}


int informes_todosLosTrabajosNote(
    eNotebook listNotes[],
    int tamN,
    eTipo listTipos[],
    int tamT,
    eMarca listMarcas[],
    int tamM,
    eCliente listClientes[],
    int tamC,
    eServicio listServi[],
    int tamS,
    eTrabajo listTrabajo[],
    int tamW
)
{
    int error = -1;
    int noteValido;
    int ValidNoteById;

    if(
        listNotes != NULL &&
        tamN > 0 &&
        listTipos != NULL &&
        tamT > 0 &&
        listMarcas != NULL &&
        tamM > 0 &&
        listClientes != NULL &&
        tamC > 0 &&
        listTrabajo != NULL &&
        tamW > 0 &&
        listServi != NULL &&
        tamS > 0
    )
    {
        //Pedir bici
        system("cls");
        printf("\n Ingrese ID bicicleta\n");
        mostrarNotebooks(
            listNotes,
            tamN,
            listMarcas,
            tamM,
            listTipos,
            tamT,
            listClientes,
            tamC
        );
        printf("\nIngrese ID: ");
        fflush(stdin);
        scanf("%d", &noteValido);
        ValidNoteById = findNotebookById(
                            listNotes,
                            tamN,
                            noteValido
                        );
        while(ValidNoteById < 0)
        {
            printf("\n Dato invalido. Ingrese el ID de la Notebook: ");
            fflush(stdin);
            scanf("%d", &noteValido);
            ValidNoteById = findNotebookById(
                                listNotes,
                                tamN,
                                noteValido
                            );
        }

        //listar trabajos que se le hicieron a esa bicicleta
        menu_printEncabezadoTrabajos();

        for(int i = 0; i < tamW; i++)
        {
            if(listTrabajo[i].idNotebook == noteValido)
            {
                mostrarTrabajo(listTrabajo[i],listNotes,listServi,tamS,listClientes,tamC);
            }
        }
        error = 0;
    }
    return error;
}

int informes_serviciosSumaPrecio(
    eNotebook listNotes[],
    int tamN,
    eTipo listTipos[],
    int tamT,
    eMarca listMarcas[],
    int tamM,
    eCliente listClientes[],
    int tamC,
    eServicio listServi[],
    int tamS,
    eTrabajo listTrabajo[],
    int tamW
)
{
    int error = -1;
    int noteValida;
    int validNoteById;
    int idServicioActual;
    float acumPrecio = 0;

    if(
        listNotes != NULL &&
        tamN > 0 &&
        listTipos != NULL &&
        tamT > 0 &&
        listMarcas != NULL &&
        tamM > 0 &&
        listClientes != NULL &&
        tamC > 0 &&
        listTrabajo != NULL &&
        tamW > 0 &&
        listServi != NULL &&
        tamS > 0
    )
    {
        //Pedir Notebook
        system("cls");
        mostrarNotebooks(
            listNotes,
            tamN,
            listMarcas,
            tamM,
            listTipos,
            tamT,
            listClientes,
            tamC
        );
        printf("\nIngrese el Id de la Notebook: ");
        fflush(stdin);
        scanf("%d", &noteValida);
        validNoteById = findNotebookById(
                            listNotes,
                            tamN,
                            noteValida
                        );
        while(validNoteById < 0)
        {
            printf("\n Dato invalido. Ingrese el Id de la Notebook: ");
            fflush(stdin);
            scanf("%d", &noteValida);
            validNoteById = findNotebookById(
                                listNotes,
                                tamN,
                                noteValida
                            );
        }

        //listar trabajos que se le hicieron a esa Notebook
        menu_printEncabezadoTrabajos();

        for(int i = 0; i < tamW; i++)
        {
            if(listTrabajo[i].idNotebook == noteValida)
            {
                idServicioActual = listTrabajo[i].idServicio;
                for(int j = 0; j < tamS; j++)
                {
                    if(listServi[j].id == idServicioActual)
                    {
                        acumPrecio += listServi[j].precio;
                    }
                }
            }

        }

        printf("\nTotal trabajos realizados a la Notebook seleccionada es de: $ %.2f\n", acumPrecio);
        error = 0;
    }
    return error;
}

int informes_serviciosYMostrar(
    eNotebook listNotes[],
    int tamN,
    eTipo listTipos[],
    int tamT,
    eMarca listMarcas[],
    int tamM,
    eCliente listClientes[],
    int tamC,
    eServicio listServi[],
    int tamS,
    eTrabajo listTrabajo[],
    int tamW
)
{
    int error = -1;
    int servicioValido;
    int validServiById;
    int idTrabajoActual;

    if(
        listNotes != NULL &&
        tamN > 0 &&
        listServi != NULL &&
        tamS > 0 &&
        listTrabajo != NULL &&
        tamW > 0 &&
        listTipos != NULL &&
        tamT > 0 &&
        listMarcas!= NULL &&
        tamM > 0 &&
        listClientes!= NULL &&
        tamC > 0)
    {

        //pedir un servicio
        system("cls");
        mostrarServicios(
            listServi,
            tamS
        );
        printf("\nIngrese Id: ");
        fflush(stdin);
        scanf("%d", &servicioValido);
        validServiById = findServicioById(
                             listServi,
                             tamS,
                             servicioValido
                         );
        while(validServiById < 0)
        {
            printf("\nDato invalido. Ingrese ID: ");
            fflush(stdin);
            scanf("%d", &servicioValido);
            validServiById = findServicioById(
                                 listServi,
                                 tamS,
                                 servicioValido
                             );
        }

        menu_printEncabezado();
        for(int i = 0; i < tamW; i++)
        {
            if(listTrabajo[i].idServicio == servicioValido)
            {
                idTrabajoActual = listTrabajo[i].idNotebook;
                for(int j = 0; j < tamN; j++)
                {
                    if(listNotes[j].id == idTrabajoActual)
                    {
                        mostrarNotebook(
                            listNotes[i],
                            listMarcas,
                            tamM,
                            listTipos,
                            tamT,
                            listClientes,
                            tamC
                        );
                    }
                }
            }

        }

        error = 0;
    }

    return error;
}

int informes_fechaServicios(eServicio listServi[], int tamS, eTrabajo listTrabajo[], int tamW)
{
    int error = -1;
    int servicioActualId;
    eFecha auxFecha;

    if(listServi != NULL && tamS > 0 && listTrabajo != NULL && tamW > 0)
    {

        //pedir y validar fecha
        printf("\nIngrese la fecha dd/mm/aaaa:");
        scanf("%d/%d/%d",&auxFecha.dia,&auxFecha.mes,&auxFecha.anio);
        while( valFecha(auxFecha.dia,auxFecha.mes,auxFecha.anio) != 1)
        {
            printf("\nDato invalido. Ingrese la fecha dd/mm/aaaa:");
            fflush(stdin);
            scanf("%d/%d/%d",&auxFecha.dia,&auxFecha.mes,&auxFecha.anio);
        }

        //listar servicios
        for(int i = 0; i < tamW; i++)
        {
            if(
                auxFecha.dia == listTrabajo[i].fecha.dia &&
                auxFecha.mes == listTrabajo[i].fecha.mes &&
                auxFecha.anio == listTrabajo[i].fecha.anio)
            {
                servicioActualId = listTrabajo[i].idServicio;
                for(int j = 0; j < tamS; j++)
                {
                    if(servicioActualId == listServi[j].id)
                    {
                        mostrarServicio(listServi[j]);
                    }
                }
            }
        }

        error = 0;
    }

    return error;
}
