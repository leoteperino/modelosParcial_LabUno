
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "Contrataciones.h"

#define OCUPADO 1
#define VACIO 0

#define ERROR -1
#define EXITO 0

char cuitCliente[20];
char nombreArchivo[50];
int isEmpty;
int idContratacion;
int idPantalla;
int dias;


int con_imprimir(eContratacion* auxContratacion)
{
    int retorno = ERROR;

    if(auxContratacion != NULL && auxContratacion->isEmpty == OCUPADO)
    {
        printf("\n%5d %18s %18s %15d %8d\n",auxContratacion->idContratacion,auxContratacion->nombreArchivo,auxContratacion->cuitCliente,auxContratacion->dias,auxContratacion->idPantalla);
        retorno = EXITO;
    }

    return retorno;
}

int con_imprimirArray(eContratacion* array,int limite)
{
    int retorno = ERROR;
    int i;

    if(array != NULL && limite>0 && array->isEmpty == OCUPADO)
    {
        printf("%5s %18s %18s %15s %8s","ID","ARCHIVO","CUIT","CANT. DIAS","ID PANTALLA");

        for(i=0; i<limite; i++)
        {
            con_imprimir(&array[i]);
        }
        retorno = EXITO;
    }

    return retorno;
}

int con_inicializarArray(eContratacion* array,int limite)
{
    int retorno = ERROR;
    int i;

    if(array != NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            array[i].isEmpty = VACIO;
        }
        retorno=EXITO;
    }

    return retorno;
}

int con_altaArray(eContratacion* array,int limite, int* id, int auxIdPantalla)
{
    int retorno = ERROR;
    eContratacion aux;
    int indice;

    indice = con_getEmptyIndex(array,limite);

    if(array !=NULL && limite>0 && indice != ERROR && id !=NULL)
    {
        if( getTxtAndNum(aux.nombreArchivo,NOMBRE_LEN,"Ingrese nombre del archivo: ","Error, reingrese nombre del archivo: ") == 0 &&
                getTxtAndNum(aux.cuitCliente,CUIT_LEN,"Ingrese el CUIT sin guiones: ","Error, reingrese el CUIT: ") == 0 &&
                getNumber(&aux.dias,"Ingrese la cantidad de dias: ","Error, reingrese cantidad de dias: ",0,500) == 0)
        {
            aux.idContratacion = *id;
            aux.idPantalla = auxIdPantalla;
            aux.isEmpty = OCUPADO;
            array[indice] = aux;
            (*id)++;
            retorno = EXITO;
        }
    }
    else if(array !=NULL && limite>0 && indice == ERROR)///si es que el ID ingresado no existe
    {
        retorno = -2;
    }

    return retorno;
}


int con_getEmptyIndex(eContratacion* array,int limite)
{
    int retorno = ERROR;
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

/*int con_buscarId(eContratacion array[], int limite, int valorBuscado)
{
    int retorno = ERROR;
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

int con_modificarArray(eContratacion* array,int limite, int indice)
{
    int retorno = ERROR;
    eContratacion aux;
    int opcion;

    if(array !=NULL && limite>0 && indice >= 0 && indice < limite)
    {

        do
        {
            if(getNumber(&opcion,"\n1. Cambiar nombre de archivo"
                         "\n2. Cambiar CUIT"
                         "\n3. Cambiar Cant Dias"
                         "\n4. Volver \n",
                         "No es una opcion valida",1,4)==0)
            {
                switch(opcion)
                {
                case 1:
                    if(getTxtAndNum(aux.nombreArchivo,NOMBRE_LEN,"Ingrese nombre del archivo: ","Error, reingrese nombre del archivo: ") == 0)
                    {
                        strncpy(array[indice].nombreArchivo,aux.nombreArchivo,50);
                        retorno = EXITO;
                    }
                    break;
                case 2:
                    if(getTxtAndNum(aux.cuitCliente,CUIT_LEN,"Ingrese el CUIT sin guiones: ","Error, reingrese el CUIT: ") == 0)
                    {
                        strncpy(array[indice].cuitCliente,aux.cuitCliente,CUIT_LEN);
                        retorno = EXITO;
                    }
                    break;
                case 3:
                    if(getNumber(&aux.dias,"Ingrese la cantidad de dias: ","Error, reingrese cantidad de dias: ",0,500) == 0)
                    {
                        array[indice].dias = aux.dias;
                        retorno = EXITO;
                    }
                    break;
                }
            }
        }
        while(opcion != 4);

    }

    return retorno;
}

int con_bajaArray(eContratacion* array,int limite, int indice)
{
    int retorno = ERROR;

    if(array !=NULL && limite>0 && indice >= 0 && indice < limite && array[indice].isEmpty == OCUPADO)
    {
        array[indice].isEmpty = VACIO;
        retorno = EXITO;
    }

    return retorno;
}

*/



void hardcordeoContrataciones(eContratacion arrayContratacion[], int* id)
{
    int i;

    char cuitCliente[6][CUIT_LEN]= {"1234","2222","2525","1234","2222","2525"};
    char nombreArchivo[6][NOMBRE_LEN]= {"Archivo1.mov","Archivo2.mov","Archivo3.mov","Archivo4.mov","Archivo5.mov","Archivo6.mov"};
    int idPantalla[6]= {0,0,1,2,2,3};
    int dias[6]= {5,2,10,3,7,6};

    if(arrayContratacion !=NULL && id !=NULL)
    {
        for(i=0; i<6; i++)
        {
            strncpy(arrayContratacion[i].cuitCliente,cuitCliente[i],CUIT_LEN);
            strncpy(arrayContratacion[i].nombreArchivo,nombreArchivo[i],NOMBRE_LEN);
            arrayContratacion[i].idPantalla = idPantalla[i];
            arrayContratacion[i].dias = dias[i];
            arrayContratacion[i].idContratacion = *id;
            arrayContratacion[i].isEmpty = OCUPADO;
            (*id)++;
        }
    }
}

int con_inicializarIDArray(eContratacion* array,int limite)
{
    int retorno = ERROR;
    int i;

    if(array != NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            array[i].idContratacion = -1;
        }
        retorno=EXITO;
    }

    return retorno;
}



int con_cancelarContratacionPantalla(eContratacion* arrayContratacion,int limite,int idRecibido)
{
    int retorno = ERROR;
    int i;

    if(arrayContratacion != NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            if(arrayContratacion[i].idPantalla == idRecibido && arrayContratacion[i].isEmpty == OCUPADO)
            {
                arrayContratacion[i].isEmpty = VACIO;
            }
        }
        retorno = EXITO;
    }

    return retorno;
}
