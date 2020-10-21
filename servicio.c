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


/** \brief Muestras el array de Servicios devuelve 0 si todo sale ok,
 *         y -1 si algo salio mal
 * \param servicios[] eServicio
 * \param len int
 * \return int
 *
 */
int mostrarServicios(eServicio servicios[], int len)
{
    int error = -1;
    if(servicios != NULL && len > 0)
    {
        printf("               Servicios de Notebooks         \n"     );
        printf("-------------------------------------------------\n");
        printf("   Id               Descripcion           Precio    \n");
        printf("-------------------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            mostrarServicio(servicios[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

/** \brief Muestra un Servicio
 *
 * \param servicio eServicio
 * \return void
 *
 */
void mostrarServicio(eServicio servicio)
{
    printf("  %d    %20s          %7.2f  \n", servicio.id, servicio.descripcion, servicio.precio);
}

int findServicioById(eServicio list[], int len, int id)
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

/** \brief Pide el array eServicio, tamaño y id, busca en el array eServicio el id
 *    y guarda la descripcion en el char descripcion
 *
 * \param lista[] eServicio
 * \param len int
 * \param ID int
 * \param descripcion[] char
 * \return int
 *
 */
int obtenerDescripcionServi(eServicio lista[], int len, int ID, char descripcion[])
{
    int error = -1;

    if(lista != NULL && descripcion != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(lista[i].id == ID)
            {
                strcpy(descripcion,lista[i].descripcion);
                error = 0;
                break;
            }
        }
    }

    return error;
}
