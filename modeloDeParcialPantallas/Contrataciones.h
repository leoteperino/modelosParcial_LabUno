typedef struct
{
    char cuitCliente[20];
    char nombreArchivo[50];
    int isEmpty;
    int idContratacion;
    int idPantalla;
    int dias;

} eContratacion;

int con_imprimir(eContratacion* auxContratacion);
int con_imprimirArray(eContratacion* array,int limite);
int con_inicializarArray(eContratacion* array,int limite);
int con_altaArray(eContratacion* array,int limite, int indice, int* id);
int con_getEmptyIndex(eContratacion* array,int limite);
int con_buscarId(eContratacion array[], int limite, int valorBuscado);
int con_modificarArray(eContratacion* array,int limite, int indice);
int con_bajaArray(eContratacion* array,int limite, int indice);
