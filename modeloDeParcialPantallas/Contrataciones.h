#define NOMBRE_LEN 50
#define CUIT_LEN 20

typedef struct
{
    char cuitCliente[CUIT_LEN];
    char nombreArchivo[NOMBRE_LEN];
    int isEmpty;
    int idContratacion;
    int idPantalla;
    int dias;

} eContratacion;

/**
 * \brief Imprime los datos de una contratacion
 * \param auxContratacion Puntero a eContratacion que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_imprimir(eContratacion* auxContratacion);

/**
 * \brief Imprime el array de contrataciones
 * \param array Array de contrataciones
 * \param limite Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_imprimirArray(eContratacion* array,int limite);

/**
 * \brief Inicializa el array
 *        Pone a todas las posiciones de isEmpty como VACIAS
 * \param array Array de contrataciones
 * \param limite Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_inicializarArray(eContratacion* array,int limite);

/**
 * \brief Inicializa el array de IDs
 *        Pone en todas las posiciones de id en -1
 * \param array Array de contrataciones
 * \param limite Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_inicializarIDArray(eContratacion* array,int limite);

/**
 * \brief Busca primer posicion vacia
 * \param array Array de contrataciones
 * \param limite Limite del array
 * \return Retorna el incice de la posicion vacia y -1 si ya no hay lugar o (ERROR)
 *
 */
int con_getEmptyIndex(eContratacion* array,int limite);

/**
 * \brief Da de alta una contratacion
 *        Busca una posicion del array que este vacia y realiza la carga en esa posicion
 * \param array Array de contrataciones
 * \param limite Limite del array
 * \param id Identificador de la contratacion a ser asignado
 * \param auxIdPantalla Identificador de la pantalla a ser asignado en la contratacion
 * \return Retorna 0 (EXITO) -1 (ERROR) -2 Si NO EXISTE el id de la pantalla donde se asignara la contratacion
 *
 */
int con_altaArray(eContratacion* array,int limite, int* id, int auxIdPantalla);

/**
 * \brief Actualiza una posicion del array
 *        Hace una baja logica de la contratacion si se hace una baja de la pantalla que tiene asignada
 * \param array Array de contrataciones
 * \param limite Limite del array
 * \param idRecibido Id de la pantalla que se dio de baja
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_cancelarContratacionPorBajaPantalla(eContratacion* arrayContratacion,int limite,int idRecibido);

/** \brief Busca un ID  de la contratacion en el array
* \param array Array de contrataciones
* \param limite Limite del array
* \param valorBuscado Id que se quiere buscar
* \return Retorna Posicion en la que se encuentra el id o (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer]
*/
int con_buscarIdContratacion(eContratacion array[], int limite, int valorBuscado);

/**
 * \brief Actualiza los datos de una contratacion en una posicion del array
 * \param array Array de contrataciones
 * \param limite Limite del array
 * \param idRecibido Id de la contratacion que se busca modificar
 * \return Retorna 0 (EXITO) -1 (ERROR) -2 Si NO EXISTE el id de la contratacion que se quiere modificar
 *
 */
int con_modificarArray(eContratacion* array,int limite, int idRecibido);

/**
 * \brief Actualiza una posicion del array
 *        Hace una baja logica de la contratacion
 * \param array Array de contrataciones
 * \param limite Limite del array
 * \param idRecibido Id de la contratacion que se busca eliminar
 * \return Retorna 0 (EXITO) y -1 (ERROR) -2 Si NO EXISTE el id de la contratacion que se quiere eliminar
 */
int con_bajaArray(eContratacion* array,int limite, int idRecibido);

/**
 * \brief Comprueba que el cuit ingresado por el usuario exista
 * \param array Array de contrataciones
 * \param limite Limite del array
 * \param cuitRecibido Cuit buscado por el usuario
 * \return Retorna 0 (SI EXISTE) y -1 (ERROR) -2 Si NO EXISTE
 */
int con_comprobarCuitValido(eContratacion* arrayContratacion, int limiteCon, char* cuitRecibido);


/**Hardcodeo de datos**/
void hardcordeoContrataciones(eContratacion arrayContratacion[], int* id);




