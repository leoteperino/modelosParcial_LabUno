#include "Informar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR -1
#define EXITO 0
#define NOEXISTE -2
#define OCUPADO 1
#define VACIO 0

int info_imprimirArray(ePantalla* arrayPantalla,int limitePan, eContratacion* arrayContratacion, int limiteCon, char* cuitRecibido)
{
    int retorno = ERROR;
    int i;
    int idPantalla;
    int indicePantalla;

    if(arrayPantalla != NULL && arrayContratacion != NULL && cuitRecibido != NULL && limitePan>0 && limiteCon>0)
    {
        for(i=0; i<limiteCon; i++)
        {
            if(strncmp(arrayContratacion[i].cuitCliente,cuitRecibido,CUIT_LEN)==0 && arrayContratacion[i].isEmpty == OCUPADO)
            {
                idPantalla = arrayContratacion[i].idPantalla;
                indicePantalla = pan_buscarId(arrayPantalla,limitePan,idPantalla);

                printf("\n\n\n%15s %18s %18s %18s %10s\n","ID PANTALLA","TIPO","NOMBRE","DIRECCION","PRECIO");
                pan_imprimir(&arrayPantalla[indicePantalla]);
                printf("\n%15s %18s %18s %15s %15s\n","ID CONTRATACION","ARCHIVO","CUIT","CANT. DIAS","ID PANTALLA");
                con_imprimir(&arrayContratacion[i]);
                retorno = EXITO;
            }
        }
    }

    return retorno;
}

int info_listarContrataciones(ePantalla* arrayPantalla,int limitePan, eContratacion* arrayContratacion, int limiteCon)
{
    int retorno = ERROR;
    int i;
    int idPantalla;
    int indicePantalla;

    if(arrayPantalla != NULL && arrayContratacion != NULL && limitePan>0 && limiteCon>0)
    {
        printf("\n%15s %18s %18s %18s\n",
               "NOMBRE PANTALLA",
               "NOMBRE ARCHIVO",
               "DIAS",
               "CUIT CLIENTE");

        for(i=0; i<limiteCon; i++)
        {
            if(arrayContratacion[i].isEmpty == OCUPADO)
            {
                idPantalla = arrayContratacion[i].idPantalla;
                indicePantalla = pan_buscarId(arrayPantalla,limitePan,idPantalla);

                printf("\n%15s %18s %18d %18s\n",
                       arrayPantalla[indicePantalla].nombre,
                       arrayContratacion[i].nombreArchivo,
                       arrayContratacion[i].dias,
                       arrayContratacion[i].cuitCliente);
                retorno = EXITO;
            }
        }
    }

    return retorno;
}

/**Consulta facturación: Se deberá ingresar el cuit del cliente y se deberá listar el importe
                    a pagar por cada contratación.*/

int info_facturacion(ePantalla* arrayPantalla,int limitePan, eContratacion* arrayContratacion, int limiteCon, char* cuitRecibido)
{
    int retorno = ERROR;
    int i;
    int idPantalla;
    int indicePantalla;
    float importeFinal[limiteCon];

    if(arrayPantalla != NULL && arrayContratacion != NULL && cuitRecibido != NULL && limitePan>0 && limiteCon>0)
    {
        printf("\n%15s %15s %15s %15s\n",
               "CUIT CLIENTE",
               "PRECIO PANTALLA",
               "DIAS",
               "IMPORTE FINAL");

        for(i=0; i<limiteCon; i++)
        {
            if(strncmp(arrayContratacion[i].cuitCliente,cuitRecibido,CUIT_LEN)==0 && arrayContratacion[i].isEmpty == OCUPADO)
            {
                retorno = EXITO;
                idPantalla = arrayContratacion[i].idPantalla;
                indicePantalla = pan_buscarId(arrayPantalla,limitePan,idPantalla);

                importeFinal[i] = arrayPantalla[indicePantalla].precio * arrayContratacion[i].dias;

                printf("\n%15s %15.2f %15d %15.2f\n",
                       arrayContratacion[i].cuitCliente,
                       arrayPantalla[indicePantalla].precio,
                       arrayContratacion[i].dias,
                       importeFinal[i]);
            }
        }
    }

    return retorno;
}
