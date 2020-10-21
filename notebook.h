#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

typedef struct{
    int id;
    char modelo[20];
    int idMarca; // validar
    int idTipo; // validar
    float precio;
    int isEmpty;
}eNotebook;

#endif // NOTEBOOK_H_INCLUDED

int altaNotebook(eNotebook list[], int tam, int ID, eTipo tipo[], int tamT, eMarca marca[], int tamM);
void formatName(char name[]);
char menu();
int initNotebooks(eNotebook list[], int len);
int mostrarNotebooks(eNotebook list[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);
int findNotebookById(eNotebook list[], int len,int id);
int modificarNotebook(eNotebook list[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT);
int bajaNotebooks(eNotebook list[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT);
int ordenarNotebooks(eNotebook list[], int len,eMarca marca[] );
