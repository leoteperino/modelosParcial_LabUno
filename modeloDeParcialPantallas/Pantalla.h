#define NOMBRE_LEN 50
#define DIRE_LEN 20

typedef struct
{
    char tipo[DIRE_LEN];
    char nombre[NOMBRE_LEN];
    char direccion[DIRE_LEN];
    float precio;
    int isEmpty;
    int idPantalla;

} ePantalla;

/**
 * \brief Imprime los datos de una pantalla
 * \param auxPantalla Puntero a ePantalla que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_imprimir(ePantalla* auxPantalla);

/**
 * \brief Imprime el array de pantallas
 * \param array Array de pantallas
 * \param limite Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_imprimirArray(ePantalla* array,int limite);

/**
 * \brief Inicializa el array
 *        Pone a todas las posiciones de isEmpty como VACIAS
 * \param array Array de pantallas
 * \param limite Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_inicializarArray(ePantalla* array,int limite);

/**
 * \brief Inicializa el array de IDs
 *        Pone en todas las posiciones de id en -1
 * \param array Array de pantallas
 * \param limite Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_inicializarIDArray(ePantalla* array,int limite);

/**
 * \brief Busca primer posicion vacia
 * \param array Array de pantallas
 * \param limite Limite del array
 * \return Retorna el incice de la posicion vacia y -1 si ya no hay lugar o (ERROR)
 *
 */
int pan_getEmptyIndex(ePantalla* array,int limite);

/**
 * \brief Da de alta una pantalla
 *        Busca una posicion del array que este vacia y realiza la carga en esa posicion
 * \param array Array de pantallas
 * \param limite Limite del array
 * \param id Identificador de la pantalla a ser asignado
 * \return Retorna 0 (EXITO) -1 (ERROR)
 *
 */
int pan_altaArray(ePantalla* array,int limite, int* id);

/** \brief Busca el ID  de la pantalla en el array
* \param array Array de pantallas
* \param limite Limite del array
* \param valorBuscado Id que se quiere buscar
* \return Retorna Posicion en la que se encuentra el id o (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer]
*/
int pan_buscarId(ePantalla array[], int limite, int valorBuscado);

/**
 * \brief Actualiza los datos de una pantalla en una posicion del array
 * \param array Array de pantallas
 * \param limite Limite del array
 * \param idRecibido Id de la pantalla que se busca modificar
 * \return Retorna 0 (EXITO) -1 (ERROR) -2 Si NO EXISTE el id de la pantalla que se quiere modificar
 *
 */
int pan_modificarArray(ePantalla* array,int limite, int idRecibido);

/**
 * \brief Actualiza una posicion del array
 *        Hace una baja logica de la pantalla
 * \param array Array de pantallas
 * \param limite Limite del array
 * \param idRecibido Id de la pantalla que se busca eliminar
 * \return Retorna 0 (EXITO) y -1 (ERROR) -2 Si NO EXISTE el id de la pantalla que se quiere eliminar
 *
 */
int pan_bajaArray(ePantalla* array,int limite, int idRecibido);


/**Hardcodeo de datos**/
void hardcordeoPantallas(ePantalla arrayPantalla[], int* id);
