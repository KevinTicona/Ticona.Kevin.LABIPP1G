#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id; //autoincremental apartir de 5000
    char descripcion [20];
}eTipo;

#endif // TIPO_H_INCLUDED

int mostrarTipos(eTipo tipos[], int len);
void mostrarTipo(eTipo tipo);
int findTipoById(eTipo list[], int len, int id);
int obtenerDescripcionTipo(eTipo lista[], int len, int ID, char descripcion[]);
