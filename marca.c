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

void mostrarMarca(eMarca marca)
{
    printf("  %d    %20s\n", marca.id, marca.descripcion);
}

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
