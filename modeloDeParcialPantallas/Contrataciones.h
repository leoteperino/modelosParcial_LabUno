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

int con_imprimir(eContratacion* auxContratacion);
int con_imprimirArray(eContratacion* array,int limite);
int con_inicializarArray(eContratacion* array,int limite);
int con_altaArray(eContratacion* array,int limite, int* id, int auxIdPantalla);
int con_getEmptyIndex(eContratacion* array,int limite);

int con_buscarId(eContratacion array[], int limite, int valorBuscado);
int con_modificarArray(eContratacion* array,int limite, int indice);
int con_bajaArray(eContratacion* array,int limite, int indice);

void hardcordeoContrataciones(eContratacion arrayContratacion[], int* id);
int con_inicializarIDArray(eContratacion* array,int limite);
int con_cancelarContratacionPantalla(eContratacion* arrayContratacion,int limite,int idRecibido);
