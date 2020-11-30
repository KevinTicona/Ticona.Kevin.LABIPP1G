#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cliente.h"
#include "validaciones.h"

int initClientes(eCliente* lista, int tam)
{
    if(lista != NULL && tam > 0 && tam <= 10000)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        return 0;
    }

    return -1;
}

int findClienteById(eCliente* lista, int tam, int id)
{
    int indiceId = -1;
    if(lista != NULL && tam > 0 && tam <= 10000)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == id && lista[i].isEmpty == 0)
            {
                indiceId = i;
                break;
            }
        }
    }
    return indiceId;
}
/*
int clientes_hardcodear(eCliente* lista, int tam, int numeroDeClientes)
{
    int returns = -1;
    if(
        lista != NULL &&
        tam > 0 &&
        numeroDeClientes > 0 &&
        numeroDeClientes < tam)
    {
        for(int i = 0; i < numeroDeClientes; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                lista[i].isEmpty = 0;
                lista[i].id = idClientes[i];
                strcpy(lista[i].nombre, clientesNombre[i]);
                lista[i].sexo = clientesGenero[i];
                returns++;
            }
        }
    }

    return returns;
}
*/
int mostrarClientes(eCliente* lista, int tam)
{
    if(lista != NULL && tam > 0 && tam <= 10000)
    {

        printf("               Listado de Clientes               \n");
        printf("-------------------------------------------------\n");
        printf("  Id               Nombre             Sexo       \n");
        printf("-------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty != 1)
            {
                mostrarCliente(lista[i]);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void mostrarCliente(eCliente cliente)
{

    printf("%5d %20s               %c\n",
           cliente.id,
           cliente.nombre,
           cliente.sexo
          );
}

int obtenerDescripcionCliente(eCliente lista[], int tam, int ID, char nombre[])
{
    int error = -1;

    if(lista != NULL && nombre != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == ID)
            {
                strcpy(nombre, lista[i].nombre);
                error = 0;
                break;
            }
        }
    }

    return error;
}


