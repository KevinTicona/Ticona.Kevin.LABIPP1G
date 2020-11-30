#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED
#include "cliente.h"

typedef struct{
    int id; //autoincrementa
    char modelo[20];
    int idCliente;
    int idMarca; // validar
    int idTipo; // validar
    float precio;
    int isEmpty;
}eNotebook;

#endif // NOTEBOOK_H_INCLUDED

int altaNotebook(eNotebook list[], int tam, int ID, eTipo tipo[], int tamT, eMarca marca[], int tamM, eCliente listCliente[], int tamC);
void formatName(char name[]);
char menu();
int initNotebooks(eNotebook list[], int len);
int mostrarNotebooks(eNotebook list[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente listCliente[], int tamC);
int findNotebookById(eNotebook list[], int len,int id);
int modificarNotebook(eNotebook list[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente listCliente[], int tamC);
int bajaNotebooks(eNotebook list[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente listCliente[], int tamC);
int ordenarNotebooks(eNotebook list[], int len,eMarca marca[] );
void mostrarNotebook(eNotebook note, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente listCliente[], int tamC);
