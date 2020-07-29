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

int pan_imprimir(ePantalla* auxPantalla);
int pan_imprimirArray(ePantalla* array,int limite);
int pan_inicializarArray(ePantalla* array,int limite);
int pan_altaArray(ePantalla* array,int limite, int* id);
int pan_getEmptyIndex(ePantalla* array,int limite);
int pan_buscarId(ePantalla array[], int limite, int valorBuscado);
int pan_modificarArray(ePantalla* array,int limite, int idRecibido);
int pan_bajaArray(ePantalla* array,int limite, int idRecibido);



int pan_inicializarIDArray(ePantalla* array,int limite);
void hardcordeoPantallas(ePantalla arrayPantalla[], int* id);
