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



/** \brief Alta Trabajo retorna 0 si todo sale ok y -1 si algo sale mal
 *
 * \param list[] eTrabajo
 * \param listNot[] eNotebook
 * \param tam int
 * \param ID int
 * \param listServi[] eServicio
 * \param tamS int
 * \param listTipo[] eTipo
 * \param tamT int
 * \param listMarca[] eMarca
 * \param tamM int
 * \return int
 *
 */
int altaTrabajo(eTrabajo list[],eNotebook listNot[], int tam, int ID,eServicio listServi[],int tamS, eTipo listTipo[], int tamT, eMarca listMarca[], int tamM, eCliente listCliente[], int tamC)
{
    eTrabajo work;

    int validIdNote;
    int validIdServi;

    if(list != NULL && tam > 0 && tam <= 100 && listNot != NULL && listServi!= NULL && tamS > 0 && listTipo != NULL && tamT > 0 && listMarca != NULL && tamM > 0 && listCliente != NULL && tamC >0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == 1)
            {
                work.isEmpty = 0;
                work.id = ID;
                //Notebook
                mostrarNotebooks(listNot,tam,listMarca,tamM,listTipo,tamT,listCliente,tamC);
                printf("\nIngrese el ID de la Notebook: ");
                fflush(stdin);
                scanf("%d",&work.idNotebook);
                validIdNote=findNotebookById(listNot,tam,work.idNotebook);
                while(validIdNote < 0)
                {
                    printf("\nDato invalido. Ingrese el ID de la Notebook: ");
                    fflush(stdin);
                    scanf("%d",&work.idNotebook);
                    validIdNote=findNotebookById(listNot,tam,work.idNotebook);
                }

                //Servicio
                mostrarServicios(listServi,tamS);
                printf("\nIngrese el ID del servi que desea: ");
                fflush(stdin);
                scanf("%d",&work.idServicio);
                validIdServi = findServicioById(listServi,tamS,work.idServicio);
                while( validIdServi < 0)
                {
                    printf("\nDato invalido. Ingrese el ID de la Marca: ");
                    fflush(stdin);
                    scanf("%d",&work.idServicio);
                    validIdServi = findServicioById(listServi,tamS,work.idServicio);
                }
                //fecha
                printf("\nIngrese la fecha dd/mm/aaaa:");
                scanf("%d/%d/%d",&work.fecha.dia,&work.fecha.mes,&work.fecha.anio);
                while( valFecha(work.fecha.dia,work.fecha.mes,work.fecha.anio) != 1)
                {
                    printf("\nDato invalido. Ingrese la fecha dd/mm/aaaa:");
                    fflush(stdin);
                    scanf("%d/%d/%d",&work.fecha.dia,&work.fecha.mes,&work.fecha.anio);
                }
                list[i] = work;
                return 0;
            }
        }
        printf("\nNo hay lugar para otra Notebook...\n");
    }
    return -1;
}

/** \brief Inicia el array e Trabajo poniendo todos los isEmpty = 1 que estan Vacios
 *
 * \param list[] eTrabajo
 * \param len int
 * \return int
 *
 */
int initTrabajos(eTrabajo list[], int len)
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



/** \brief Muestra por pantalla un trabajo
 *
 * \param work eTrabajo
 * \param note eNotebook
 * \param servi[] eServicio
 * \param tamS int
 * \return void
 *
 */
void mostrarTrabajo( eTrabajo work,eNotebook note[],int tamN, eServicio servi[], int tamS)
{

    char descServi[20];
    char descModelo[20];

    obtenerDescripcionServi(servi,tamS,work.idServicio,descServi);
    obtenerDescripcionModelo(note, tamN, work.idNotebook, descModelo );

    printf("%7d      %10s             %10s           %2d/%2d/%4d\n",
           work.id,
           descModelo,
           descServi,
           work.fecha.dia,
           work.fecha.mes,
           work.fecha.anio
           );
}

/** \brief Muestra por pantalla el array listaTra que muestra todos los trabajos Activos
 *
 * \param listTra[] eTrabajo
 * \param listServi[] eServicio
 * \param tamS int
 * \param listNot[] eNotebook
 * \param tam int
 * \return int
 *
 */
int mostrarTrabajos(eTrabajo listTra[],int tamW, eServicio listServi[], int tamS,eNotebook listNot[], int tam, eCliente listCliente[], int tamC)
{
    if(listTra != NULL && listServi!=NULL && tamS>0  && listNot!=NULL && tam > 0 &&listCliente != NULL && tamC > 0 )
    {
        //system("cls");
        printf("\n                    *** Listado de Trabajos ***             \n");
        printf("-----------------------------------------------------------------------\n");
        printf(" IdServi            Modelo            Servicio              Fecha      \n");
        printf("------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(listTra[i].isEmpty != 1)
            {
                mostrarTrabajo(listTra[i],listNot,tam,listServi,tamS);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}
