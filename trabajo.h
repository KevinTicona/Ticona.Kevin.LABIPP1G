#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
typedef struct{
    int id; //autoincremental
    int idNotebook; //validar
    int idServicio; // validar
    eFecha fecha; //validar dia mes y anio
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

int altaTrabajo(eTrabajo list[],eNotebook listNot[], int tam, int ID,eServicio listServi[],int tamS, eTipo listTipo[], int tamT, eMarca listMarca[], int tamM, eCliente listCliente[], int tamC);
int initTrabajos(eTrabajo list[], int len);
int mostrarTrabajos(eTrabajo listTra[],int tamW, eServicio listServi[], int tamS,eNotebook listNot[], int tam, eCliente listCliente[], int tamC);
void mostrarTrabajo( eTrabajo work,eNotebook note[],int tamN, eServicio servi[], int tamS);
