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

void mostrarTipo(eTipo tipo)
{
    printf("  %d    %20s\n", tipo.id, tipo.descripcion);
}


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
