#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id; //autoincremental
    int idNotebook; //validar
    int idServicio; // validar
    eFecha fecha; //validar dia mes y anio
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

int altaTrabajo(eTrabajo list[],eNotebook listNot[], int tam, int ID,eServicio listServi[],int tamS , eTipo listTipo[], int tamT, eMarca listMarca[], int tamM);
int initTrabajos(eTrabajo list[], int len);
void mostrarTrabajo( eTrabajo work,eNotebook note, eServicio servi[], int tamS);
int mostrarTrabajos(eTrabajo listTra[],eServicio listServi[], int tamS,eNotebook listNot[], int tam);
