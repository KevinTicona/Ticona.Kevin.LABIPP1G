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

/** \brief Muestra el array de Tipos
 *
 * \param tipos[] eTipo
 * \param len int
 * \return int
 *
 */
int mostrarTipos(eTipo tipos[], int len)
{
    int error = -1;
    if(tipos != NULL && len > 0)
    {
        printf("          Tipos de Notebooks.       \n"     );
        printf("-----------------------------------------\n");
        printf("   Id               Descripcion        \n");
        printf("-----------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            mostrarTipo(tipos[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

/** \brief Muestra un Tipo
 *
 * \param tipo eTipo
 * \return void
 *
 */
void mostrarTipo(eTipo tipo)
{
    printf("  %d    %20s\n", tipo.id, tipo.descripcion);
}

// recorre el vector en busca de un ID
int findTipoById(eTipo list[], int len, int id)
{
    int indiceId = -1;
    if(list != NULL && len > 0 && len <= 100)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id)
            {
                indiceId = list[i].id;
                break;
            }
        }
    }
    return indiceId;
}


/** \brief Pide el array eTipo, tamaño y id, busca en el array eTipo el id
 *    y guarda la descripcion en el char descripcion
 *
 * \param lista[] eTipo
 * \param len int
 * \param ID int
 * \param descripcion[] char
 * \return int
 *
 */
int obtenerDescripcionTipo(eTipo lista[], int len, int ID, char descripcion[])
{
    int error = -1;

    if(lista != NULL && descripcion != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(lista[i].id == ID)
            {
                strcpy(descripcion, lista[i].descripcion);
                error = 0;
                break;
            }
        }
    }

    return error;
}
