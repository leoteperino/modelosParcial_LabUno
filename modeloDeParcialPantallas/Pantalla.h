
typedef struct
{
    char tipo[15];
    char nombre[50];
    char direccion[50];
    float precio;
    int isEmpty;
    int idPantalla;

} ePantalla;

int pan_imprimir(ePantalla* auxPantalla);
int pan_imprimirArray(ePantalla* array,int limite);
int pan_inicializarArray(ePantalla* array,int limite);
int pan_altaArray(ePantalla* array,int limite, int indice, int* id);
int pan_getEmptyIndex(ePantalla* array,int limite);
int pan_buscarId(ePantalla array[], int limite, int valorBuscado);
int pan_modificarArray(ePantalla* array,int limite, int indice);
int pan_bajaArray(ePantalla* array,int limite, int indice);
int pan_ordenarPorNombre(ePantalla* array,int limite);
