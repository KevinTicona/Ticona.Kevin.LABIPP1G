#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include "fecha.h"
#include "marca.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"

/** \brief Validacion de dia, mes y anio, devuelve 1 si todo salio ok
 *   y 0 si salio algo mal
 *
 * \param dia int
 * \param mes int
 * \param anio int
 * \return int
 *
 */
int valFecha( int dia, int mes, int anio)
{

// Precondición: Se han de recibir tres parámetros, todos ellos de tipo entero.
// Poscondición: Se devolverá un 0/false o un 1/true.

    int bol = 0;

    if( mes >= 1 && mes <= 12 )
    {

        switch( mes )
        {

        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if( dia >= 1 && dia <= 31 )
            {
                bol = 1;
            }
            break;


        case 4:
        case 6:
        case 9:
        case 11:
            if( dia >= 1 && dia <= 30 )
            {
                bol = 1;
            }
            break;


        case 2:
            //Si el año es bisiesto +1 día.
            if( ((anio%4 == 0)   &&   (anio%100 != 0))   ||   (anio%400 == 0) )
            {
                if( dia >= 1 && dia <= 29 )
                {
                    bol = 1;
                }
            }
            else
            {
                if( dia >= 1 && dia <= 28 )
                {
                    bol = 1;
                }
            };
            break;
        }
    }
    return bol;
}
