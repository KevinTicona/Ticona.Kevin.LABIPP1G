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

/** \brief Muestra el listado de Marcas
 *
 * \param marcas[] eMarca
 * \param len int
 * \return int
 *
 */
int mostrarMarcas(eMarca marcas[], int len)
{
    int error = -1;
    if(marcas != NULL && len > 0)
    {
        printf("      Marcas de Notebooks         \n"     );
        printf("-----------------------------------------\n");
        printf("   Id               Descripcion        \n");
        printf("-----------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            mostrarMarca(marcas[i]);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

/** \brief Muestra Una Marca
 *
 * \param marca eMarca
 * \return void
 *
 */
void mostrarMarca(eMarca marca)
{
    printf("  %d    %20s\n", marca.id, marca.descripcion);
}

/** \brief Recorre el vector y buscar un ID
 *
 * \param list[] eMarca
 * \param len int
 * \param id int
 * \return int
 *
 */
int findMarcaById(eMarca list[], int len, int id)
{
    int indice = -1;

    if(list != NULL && len > 0 && len <= 100)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id)
            {
                indice = list[i].id;
                break;
            }
        }
    }
    return indice;
}

/** \brief Pide array, el tamaño y el id, y devuelve  0 si esta todo ok, y -1 si algo salio mal
 *
 * \param lista[] eMarca
 * \param len int
 * \param ID int
 * \param descripcion[] char
 * \return int
 *
 */
int obtenerDescripcionMarca(eMarca lista[], int len, int ID, char descripcion[])
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
