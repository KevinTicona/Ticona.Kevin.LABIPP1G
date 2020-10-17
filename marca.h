#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eMarca;

#endif // MARCA_H_INCLUDED

int mostrarMarcas(eMarca marcas[], int len);
void mostrarMarca(eMarca marca);
int findMarcaById(eMarca list[], int len, int id);
int obtenerDescripcionMarca(eMarca lista[], int len, int ID, char descripcion[]);
