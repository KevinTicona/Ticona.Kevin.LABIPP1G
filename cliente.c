#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cliente.h"
#include "validaciones.h"

/** \brief retorna 0 si esta todo ok, si algo sale mal -1
 *
 * \param lista eCliente*
 * \param tam int
 * \return int
 *
 */
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

/** \brief si algo sale mal retorna -1, si todo sale Ok retorna el id buscando en eCliente
 *
 * \param lista eCliente*
 * \param tam int
 * \param id int
 * \return int
 *
 */
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
/** \brief Muestra el contenido en eCliente
 *
 * \param lista eCliente*
 * \param tam int
 * \return int
 *
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

/** \brief Muestra un Cliente
 *
 * \param cliente eCliente
 * \return void
 *
 */
void mostrarCliente(eCliente cliente)
{

    printf("%5d %20s               %c\n",
           cliente.id,
           cliente.nombre,
           cliente.sexo
          );
}

/** \brief si sale todo Ok devuelve 0, si algo salio mal -1
 *
 * \param lista[] eCliente
 * \param tam int
 * \param ID int
 * \param nombre[] char
 * \return int
 *
 */
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


