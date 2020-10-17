#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include "fecha.h"
#include "marca.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"


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

void mostrarServicio(eServicio servicio)
{
    printf("  %d    %20s          %7f  \n", servicio.id, servicio.descripcion, servicio.precio);
}
