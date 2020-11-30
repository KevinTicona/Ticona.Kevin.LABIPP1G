#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct{
    int id;
    char nombre[51];
    char sexo;
    int isEmpty;
}eCliente;

/** \brief Para indicar que todas las posiciones del array estan vacias,
 * esta función pone todas las banderas (estaVacio) en TRUE
 * \param lista eCliente* puntero al array de clientes
 * \param tam int longitud del Array
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] -
 * (0) si esta todo Ok
 *
 */
int initClientes(eCliente* lista, int tam);

/** \brief Encuentra un cliente por ID retornando su indice en el array
 *
 * \param eBicicleta* lista
 * \param tam int tamaño
 * \param id int
 * \return Retorna la posicion del cliente en el array o (-1) si
 * [Longitud invalida o puntero NULL o cliente no encontrada]
 *
 */
int findClienteById(eCliente* lista, int tam, int id);

/** \brief Con una biblioteca de datos, rellena posiciones libres
 * en un array de eCliente
 *
 * \param eCliente* lista
 * \param int tam Tamaño
 * \param int numeroDeClientes cantidad de eClientes a cargar en el array
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] -
 * (int) entero que indica la cantidad de eCliente cargados si esta todo Ok
 */
int clientes_hardcodear(eCliente* lista, int tam, int numeroDeClientes);

/** \brief Imprime el contenido del array de clientes
 *
 * \param list eCliente*
 * \param int tam Tamaño
 * \return int Retorna (-1) si hay un Error [longitud invalida o puntero NULL] -
 * (0) si esta todo Ok
 *
 */
int mostrarClientes(eCliente* lista, int tam);

/** \brief Imprime 1 cliente de la lista de clientes
 *
 * \param un eCliente
 *
 */
void mostrarCliente(eCliente cliente);

/** \brief Carga en una cadena de caracteres el nombre del cliente
 *
 * \param eCliente* lista
 * \param int tam
 * \param int ID Cliente
 * \param char* nombre puntero a nombre
 * \return int Retorna (-1) si hay un error [Longitud invalida o puntero NULL] - (0) si esta todo Ok
 *
 */
int obtenerDescripcionCliente(eCliente lista[], int tam, int ID, char nombre[]);



#endif // CLIENTE_H_INCLUDED
