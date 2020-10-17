#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id; //autoincremental apartir de 20000
    char descripcion [20];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

int mostrarServicios(eServicio servicios[], int len);
void mostrarServicio(eServicio servicio);
