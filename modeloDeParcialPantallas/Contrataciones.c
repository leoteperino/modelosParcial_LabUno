
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "Contrataciones.h"

#define OCUPADO 1
#define VACIO 0

    char cuitCliente[20];
    char nombreArchivo[50];
    int isEmpty;
    int idContratacion;
    int idPantalla;
    int dias;

/**
 * \brief Imprime los datos de una pantalla
 * \param auxContratacion Puntero a eContratacion que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_imprimir(eContratacion* auxContratacion)
{
    int retorno = -1;

    if(auxContratacion != NULL)
    {
        printf("%d %s %s %d",auxContratacion->idContratacion,auxContratacion->nombreArchivo,auxContratacion->cuitCliente,auxContratacion->dias);
        retorno = 0;
    }

    return retorno;
}

/**
 * \brief Imprime el array de pantallas
 * \param array Array de pantallas
 * \param limite Limite del array de pantallas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_imprimirArray(eContratacion* array,int limite)
{
    int retorno = -1;
    int i;

    if(array != NULL && limite>0 && array->isEmpty == OCUPADO)
    {
        printf("%s %s %s %s","ID","ARCHIVO","CUIT","CANT. DIAS");

        for(i=0; i<limite; i++)
        {
            con_imprimir(&array[i]);
        }
        retorno = 0;
    }

    return retorno;
}


/**
 * \brief Inicializa el array
 * \param array Array de pantallas
 * \param limite Limite del array de pantallas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_inicializarArray(eContratacion* array,int limite)
{
    int retorno = -1;
    int i;

    if(array != NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            array[i].isEmpty = VACIO;
        }
        retorno=0;
    }

    return retorno;
}


/**
 * \brief Da de alta una pantalla en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_altaArray(eContratacion* array,int limite, int indice, int* id)
{
    int retorno = -1;
    eContratacion aux;

    if(array !=NULL && limite>0 && indice >= 0 && indice < limite && id !=NULL)
    {
        if( getString(aux.nombreArchivo,"Ingrese nombre del archivo: ","Error, reingrese nombre del archivo: ") == 0 &&
                getString(aux.cuitCliente,"Ingrese el CUIT: ","Error, reingrese el CUIT: ") == 0 &&
                getInt(&aux.dias,"Ingrese la cantidad de dias: ","Error, reingrese cantidad de dias: ") == 0)
        {
            aux.idContratacion = *id;
            aux.isEmpty = OCUPADO;
            array[indice] = aux;
            (*id)++;
            retorno = 0;
        }
    }

    return retorno;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de pantallas
 * \param limite Limite del array de pantallas
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int con_getEmptyIndex(eContratacion* array,int limite)
{
    int retorno = -1;
    int i;

    if(array != NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            if(array[i].isEmpty == VACIO)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Array de pantallas
* \param limite Limite del array de pantallas
* \param posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - o Posicion en la que se encuentra el id.
*/
int con_buscarId(eContratacion array[], int limite, int valorBuscado)
{
    int retorno = -1;
    int i;

    if(array != NULL && limite>0 && valorBuscado>=0)
    {
        for(i=0; i<limite; i++)
        {
            if(valorBuscado == array[i].idContratacion)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

/**
 * \brief Actualiza los datos de una pantalla en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_modificarArray(eContratacion* array,int limite, int indice)
{
    int retorno = -1;
    eContratacion aux;
    int opcion;

    if(array !=NULL && limite>0 && indice >= 0 && indice < limite)
    {

        do
        {
            printf("1. Cambiar nombre de archivo\n 2. Cambiar CUIT \n 3. Cambiar cantidad de dias \n 4. Volver \n");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                if(getString(aux.nombreArchivo,"Ingrese nombre del archivo: ","Error, reingrese nombre del archivo: ") == 0)
                {
                    strncpy(array[indice].nombreArchivo,aux.nombreArchivo,50);
                    retorno = 0;
                }
                break;
            case 2:
                if(getString(aux.cuitCliente,"Ingrese el CUIT: ","Error, reingrese el CUIT: ") == 0)
                {
                    strncpy(array[indice].cuitCliente,aux.cuitCliente,50);
                    retorno = 0;
                }
                break;
            case 3:
                if(getInt(&aux.dias,"Ingrese la cantidad de dias: ","Error, reingrese cantidad de dias: ") == 0)
                {
                    array[indice].dias = aux.dias;
                    retorno = 0;
                }
                break;
            case 4:
                printf("Volviendo...");
                break;
            default:
                printf("No es una opcion valida");
                break;
            }

        }
        while(opcion != 4);

    }

    return retorno;
}

/**
 * \brief Actualiza una posicion del array // Hace una baja logica
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_bajaArray(eContratacion* array,int limite, int indice)
{
    int retorno = -1;

    if(array !=NULL && limite>0 && indice >= 0 && indice < limite && array[indice].isEmpty == OCUPADO)
    {
        array[indice].isEmpty = VACIO;
        retorno = 0;
    }

    return retorno;
}


int con_ordenarPorNombre(eContratacion* array,int limite)
{
    int retorno = -1;


    return retorno;
}
