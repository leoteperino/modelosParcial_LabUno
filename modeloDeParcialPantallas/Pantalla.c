#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "Pantalla.h"

#define OCUPADO 1
#define VACIO 0

/**
 * \brief Imprime los datos de una pantalla
 * \param auxPantalla Puntero a ePantalla que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_imprimir(ePantalla* auxPantalla)
{
    int retorno = -1;

    if(auxPantalla != NULL && auxPantalla->isEmpty == OCUPADO)
    {
        printf("\n%5d %18s %18s %18s %10.2f\n",auxPantalla->idPantalla,auxPantalla->tipo,auxPantalla->nombre,auxPantalla->direccion,auxPantalla->precio);
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
int pan_imprimirArray(ePantalla* array,int limite)
{
    int retorno = -1;
    int i;

    if(array != NULL && limite>0 && array->isEmpty == OCUPADO)
    {
        printf("%5s %18s %18s %18s %10s\n","ID","TIPO","NOMBRE","DIRECCION","PRECIO");

        for(i=0; i<limite; i++)
        {
            pan_imprimir(&array[i]);
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
int pan_inicializarArray(ePantalla* array,int limite)
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
int pan_altaArray(ePantalla* array,int limite, int indice, int* id)
{
    int retorno = -1;
    ePantalla aux;

    if(array !=NULL && limite>0 && indice >= 0 && indice < limite && id !=NULL)
    {
        if( getString(aux.nombre,"Ingrese nombre: ","Error, reingrese nombre: ") == 0 &&
                getString(aux.direccion,"Ingrese direccion: ","Error, reingrese direccion: ") == 0 &&
                getFloat(&aux.precio,"Ingrese precio: ","Error, reingrese precio: ") == 0 &&
                getString(aux.tipo,"Ingrese tipo [LCD/LED]: ","Error, reingrese tipo: ") == 0)
        {
            aux.idPantalla = *id;
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
int pan_getEmptyIndex(ePantalla* array,int limite)
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
int pan_buscarId(ePantalla array[], int limite, int valorBuscado)
{
    int retorno = -1;
    int i;

    if(array != NULL && limite>0 && valorBuscado>=0)
    {
        for(i=0; i<limite; i++)
        {
            if(valorBuscado == array[i].idPantalla)
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
int pan_modificarArray(ePantalla* array,int limite, int indice)
{
    int retorno = -1;
    ePantalla aux;
    int opcion;

    if(array !=NULL && limite>0 && indice >= 0 && indice < limite)
    {

        do
        {
            printf(" 1. Cambiar nombre \n 2. Cambiar direccion \n 3. Cambiar Precio \n 4. Cambiar tipo \n 5. Volver \n");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                if(getString(aux.nombre,"Ingrese nombre: ","Error, reingrese nombre: ")==0)
                {
                    strncpy(array[indice].nombre,aux.nombre,50);
                    retorno = 0;
                }
                break;
            case 2:
                if(getString(aux.direccion,"Ingrese direccion: ","Error, reingrese direccion: ")==0)
                {
                    strncpy(array[indice].direccion,aux.direccion,50);
                    retorno = 0;
                }
                break;
            case 3:
                if(getFloat(&aux.precio,"Ingrese precio: ","Error, reingrese precio: ")==0)
                {
                    array[indice].precio = aux.precio;
                    retorno = 0;
                }
                break;
            case 4:
                if(getString(aux.tipo,"Ingrese tipo [LCD/LED]: ","Error, reingrese tipo: ")==0)
                {
                    strncpy(array[indice].tipo,aux.tipo,50);
                    retorno = 0;
                }
                break;
            case 5:
                break;
            default:
                printf("No es una opcion valida");
                break;
            }

        }
        while(opcion != 5);

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
int pan_bajaArray(ePantalla* array,int limite, int indice)
{
    int retorno = -1;

    if(array !=NULL && limite>0 && indice >= 0 && indice < limite && array[indice].isEmpty == OCUPADO)
    {
        array[indice].isEmpty = VACIO;
        retorno = 0;
    }

    return retorno;
}


int pan_ordenarPorNombre(ePantalla* array,int limite)
{
    int retorno = -1;


    return retorno;
}
