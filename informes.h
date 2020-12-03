#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



int menu_Informes(eNotebook listNote[], int tam, eMarca listMarcas[], int tamM, eTipo listTipos[], int tamT, eCliente listCliente[], int tamC, eServicio listServi[], int tamS, eTrabajo listTrabajo[], int tamW);
void informes_subMenu();
int informe_noteboookPorTipoSeleccionado(eNotebook listNotes[], int tamN, eTipo listTipos[], int tamT, eMarca listMarcas[], int tamM, eCliente listClientes[], int tamC);
void menu_printEncabezado();
void menu_prinfSubEncabezado();
void menu_printEncabezadoTrabajos();
int informe_noteboookPorMarcaSeleccionado(eNotebook listNotes[], int tamN, eTipo listTipos[], int tamT, eMarca listMarcas[], int tamM, eCliente listClientes[], int tamC);
int informes_notebooksMasBaratas(eNotebook listNote[],int tam);
int informes_notebooksSeparadasPorMarca(eNotebook listNote[], int tam, eMarca listMarcas[], int tamM, int criterio);
int informes_notebooksContarPorTipoyMarca(eNotebook listNotes[], int tamN, eTipo listTipos[], int tamT, eMarca listMarcas[], int tamM, eCliente listClientes[], int tamC);
int informes_notebooksMasElegidas(eNotebook* listNotes, int tamN, eMarca* listMarcas,int tamM);
int informes_todosLosTrabajosNote(eNotebook listNotes[], int tamN, eTipo listTipos[], int tamT, eMarca listMarcas[], int tamM, eCliente listClientes[], int tamC, eServicio listServi[], int tamS, eTrabajo listTrabajo[], int tamW);
int informes_serviciosSumaPrecio(eNotebook listNotes[], int tamN, eTipo listTipos[], int tamT, eMarca listMarcas[], int tamM, eCliente listClientes[], int tamC, eServicio listServi[], int tamS, eTrabajo listTrabajo[], int tamW);
int informes_serviciosYMostrar(eNotebook listNotes[], int tamN, eTipo listTipos[], int tamT, eMarca listMarcas[], int tamM, eCliente listClientes[], int tamC, eServicio listServi[], int tamS,eTrabajo listTrabajo[],int tamW);
int informes_fechaServicios(eServicio listServi[], int tamS, eTrabajo listTrabajo[], int tamW);
#endif // INFORMES_H_INCLUDED
