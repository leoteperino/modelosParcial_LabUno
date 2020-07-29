#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "Pantalla.h"

#define OCUPADO 1
#define VACIO 0
#define ERROR -1
#define EXITO 0
#define NOEXISTE -2


int pan_imprimir(ePantalla* auxPantalla)
{
    int retorno = ERROR;

    if(auxPantalla != NULL && auxPantalla->isEmpty == OCUPADO)
    {
        printf("\n%15d %18s %18s %18s %10.2f\n",auxPantalla->idPantalla,auxPantalla->tipo,auxPantalla->nombre,auxPantalla->direccion,auxPantalla->precio);
        retorno = EXITO;
    }

    return retorno;
}

int pan_imprimirArray(ePantalla* array,int limite)
{
    int retorno = ERROR;
    int i;

    if(array != NULL && limite>0)
    {
        printf("\n%15s %18s %18s %18s %10s\n","ID","TIPO","NOMBRE","DIRECCION","PRECIO");

        for(i=0; i<limite; i++)
        {
            pan_imprimir(&array[i]);
        }
        retorno = EXITO;
    }

    return retorno;
}

int pan_inicializarArray(ePantalla* array,int limite)
{
    int retorno = ERROR;
    int i;

    if(array != NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            array[i].isEmpty = VACIO;
        }
        retorno = EXITO;
    }

    return retorno;
}

int pan_inicializarIDArray(ePantalla* array,int limite)
{
    int retorno = ERROR;
    int i;

    if(array != NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            array[i].idPantalla = -1;
        }
        retorno = EXITO;
    }

    return retorno;
}

int pan_getEmptyIndex(ePantalla* array,int limite)
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

int pan_altaArray(ePantalla* array,int limite, int* id)
{
    int retorno = ERROR;
    ePantalla aux;
    int indice;

    indice = pan_getEmptyIndex(array,limite);

    if(array !=NULL && limite>0 && indice != ERROR && id !=NULL)
    {
        if( getName(aux.nombre,NOMBRE_LEN,"Ingrese nombre: ","Error, reingrese nombre: ") == 0 &&
                getTxtAndNum(aux.direccion,DIRE_LEN,"Ingrese direccion: ","Error, reingrese direccion: ") == 0 &&
                getFloatNumber(&aux.precio,"Ingrese precio: ","Error, reingrese precio: ",0,90000) == 0 &&
                getName(aux.tipo,DIRE_LEN,"Ingrese tipo [LCD/LED]: ","Error, reingrese tipo: ") == 0)
        {
            aux.idPantalla = *id;
            aux.isEmpty = OCUPADO;
            array[indice] = aux;
            (*id)++;
            retorno = EXITO;
        }
    }

    return retorno;
}

int pan_buscarId(ePantalla array[], int limite, int valorBuscado)
{
    int retorno = ERROR;
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

int pan_modificarArray(ePantalla* array,int limite, int idRecibido)
{
    int retorno = ERROR;
    ePantalla aux;
    int opcion;
    int indice;

    indice = pan_buscarId(array,limite,idRecibido);

    if(array !=NULL && limite>0 && indice != ERROR)
    {

        do
        {
            if(getNumber(&opcion,
                         "\n1. Cambiar nombre"
                         "\n2. Cambiar direccion"
                         "\n3. Cambiar Precio"
                         "\n4. Cambiar tipo"
                         "\n5. Volver \n"
                         "\n\n Ingrese una opcion: ",
                         "\n\nNo es una opcion valida\n",1,5)== EXITO)
            {

                switch(opcion)
                {
                case 1:
                    if(getName(aux.nombre,NOMBRE_LEN,"Ingrese nombre: ","Error, reingrese nombre: ")== EXITO)
                    {
                        strncpy(array[indice].nombre,aux.nombre,NOMBRE_LEN);
                        retorno = EXITO;
                    }
                    break;
                case 2:
                    if(getTxtAndNum(aux.direccion,DIRE_LEN,"Ingrese direccion: ","Error, reingrese direccion: ")== EXITO)
                    {
                        strncpy(array[indice].direccion,aux.direccion,DIRE_LEN);
                        retorno = EXITO;
                    }
                    break;
                case 3:
                    if(getFloatNumber(&aux.precio,"Ingrese precio: ","Error, reingrese precio: ",0,90000)== EXITO)
                    {
                        array[indice].precio = aux.precio;
                        retorno = EXITO;
                    }
                    break;
                case 4:
                    if(getName(aux.tipo,DIRE_LEN,"Ingrese tipo [LCD/LED]: ","Error, reingrese tipo: ")== EXITO)
                    {
                        strncpy(array[indice].tipo,aux.tipo,DIRE_LEN);
                        retorno = EXITO;
                    }
                    break;
                }
            }
        }
        while(opcion != 5);
    }
    else if(array !=NULL && limite>0 && indice == ERROR)
    {
        retorno = NOEXISTE;
    }

    return retorno;
}

int pan_bajaArray(ePantalla* array,int limite, int idRecibido)
{
    int retorno = ERROR;
    int indice;
    char respuesta[10];

    indice = pan_buscarId(array,limite,idRecibido);

    if(array !=NULL && limite>0 && indice != ERROR && array[indice].isEmpty == OCUPADO)
    {
        printf("\nSeguro que desea eliminar? [si/no]: \n\n");
        getTxt(respuesta,10);

        if(stricmp(respuesta,"si")==0)
        {
            array[indice].isEmpty = VACIO;
            retorno = EXITO;
        }
    }
    else if(array !=NULL && limite>0 && indice == ERROR)
    {
        retorno = NOEXISTE;
    }

    return retorno;
}



void hardcordeoPantallas(ePantalla arrayPantalla[], int* id)
{
    int i;

    char tipo[4][20]= {"LED","LCD","LCD","LED"};
    char nombre[4][50]= {"PantallaUno","PantallaDos","PantallaTres","PantallaCuatro"};
    char direccion[4][20]= {"Alsina 222","Suipacha 435","Belgrano 856","Mitre 700"};
    float precio[4]= {105.5, 250, 250,100};

    if(arrayPantalla !=NULL && id !=NULL)
    {
        for(i=0; i<4; i++)
        {
            strncpy(arrayPantalla[i].tipo,tipo[i],DIRE_LEN);
            strncpy(arrayPantalla[i].nombre,nombre[i],NOMBRE_LEN);
            strncpy(arrayPantalla[i].direccion,direccion[i],DIRE_LEN);
            arrayPantalla[i].precio = precio[i];
            arrayPantalla[i].idPantalla = *id;
            arrayPantalla[i].isEmpty = OCUPADO;
            (*id)++;
        }
    }
}
