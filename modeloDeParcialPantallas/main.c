
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ContratacionPantalla.h"
#include "inputs.h"

#define CANTIDAD_PANTALLAS 100
#define CANTIDAD_CONTRATACIONES 1000

#define ERROR -1
#define EXITO 0

int main(void)
{

    ///DECLARACION DE VARIABLES:
    ePantalla arrayPantallas[CANTIDAD_PANTALLAS];
    eContratacion arrayContrataciones[CANTIDAD_CONTRATACIONES];

    int idPantallas=0;
    int idContrataciones=0;

    int opcion;
    //int auxiliarIndiceCont;

    int auxiliarIdPant;
    //int auxiliarIdCont;

    int auxBaja;
    int auxModificacion;
    int auxAltaCont;


    ///INICIALIZACION DE ARRAYS:
    pan_inicializarIDArray(arrayPantallas,CANTIDAD_PANTALLAS);
    con_inicializarIDArray(arrayContrataciones,CANTIDAD_CONTRATACIONES);

    if(pan_inicializarArray(arrayPantallas,CANTIDAD_PANTALLAS) == EXITO &&
            con_inicializarArray(arrayContrataciones,CANTIDAD_CONTRATACIONES) == EXITO)
    {
        printf("\n\nBienvenido\n\n");
    }

    hardcordeoPantallas(arrayPantallas, &idPantallas);
    hardcordeoContrataciones(arrayContrataciones, &idContrataciones);


    ///COMIENZO DEL PROGRAMA:

    do
    {
        if(getNumber(&opcion,
                     "\n1.Cargar una pantalla"
                     "\n2.Modificar una pantalla"
                     "\n3.Eliminar una pantalla"
                     "\n4.Contratar una publicidad"
                     "\n5.Modificar condiciones de publicacion"
                     "\n6.Cancelar Contratacion"
                     "\n7.Consulta Facturacion"
                     "\n8.Imprimir contratacion"
                     "\n9.Imprimir pantalla"
                     "\n10.Informar"
                     "\n11.Salir\n"
                     "\n\n Ingrese una opcion: ",
                     "No es una opcion valida",1,11)==0)
        {

            {
                switch(opcion)
                {
                case 1:
                    if(pan_altaArray(arrayPantallas,CANTIDAD_PANTALLAS,&idPantallas) == EXITO)
                    {
                        printf("\nCarga realizada con exito\n");
                    }
                    else
                    {
                        printf("\nNO HAY MAS LUGAR\n\n");
                    }
                    break;
                case 2:
                    printf("\nQue pantalla desea modificar?\n\n");
                    pan_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);

                    if(getNumber(&auxiliarIdPant,"\nIndique el ID de la pantalla: ","\nID invalido!",0,10000) == EXITO)
                    {
                        auxModificacion = pan_modificarArray(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarIdPant);

                        if(auxModificacion == EXITO)
                        {
                            printf("\nModificacion realizada con exito\n");
                        }
                        else
                        {
                            if(auxModificacion == -2)
                                printf("\nEl id ingresado no existe\n");
                            else
                                printf("\nNo se han realizado cambios\n");
                        }
                    }
                    break;
                case 3:
                    printf("\nQue pantalla desea eliminar?\n\n");
                    pan_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);

                    if(getNumber(&auxiliarIdPant,"\nIndique el ID de la pantalla: ","\nID invalido!",0,10000) == EXITO)
                    {
                        auxBaja = pan_bajaArray(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarIdPant);
                        if(auxBaja == EXITO &&
                                con_cancelarContratacionPantalla(arrayContrataciones,CANTIDAD_CONTRATACIONES,auxiliarIdPant)== EXITO)
                        {
                            printf("\nBaja realizada con exito\n");
                        }
                        else
                        {
                            if(auxBaja == -2)
                                printf("\nEl id ingresado no existe\n");
                            else
                                printf("\nNo se ha realizado la baja\n");
                        }
                    }
                    break;
                case 4:
                    printf("\nEn que pantalla desea publicar?\n\n");
                    pan_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);

                    if(getNumber(&auxiliarIdPant,"\nIndique el ID de la pantalla: ","\nID invalido!",0,10000) == EXITO)
                    {
                        auxAltaCont = con_altaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,&idContrataciones,auxiliarIdPant);

                        if(auxAltaCont == EXITO)
                        {
                            printf("\nCarga realizada con exito\n");
                        }
                        else
                        {
                            if(auxAltaCont == -2)
                                printf("\nEl id ingresado no existe\n");
                            else
                                printf("\nNO HAY MAS LUGAR\n");
                        }
                    }
                    break;
                case 5:

                    break;

                case 6:

                    break;

                case 7:

                    break;

                case 8:
                    con_imprimirArray(arrayContrataciones,CANTIDAD_CONTRATACIONES);
                    break;
                case 9:
                    pan_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);
                    break;
                case 10:

                    break;
                case 11:
                    printf("\nHasta luego!\n");
                    break;
                }
            }
        }
    }
    while(opcion != 11);

    return 0;
}
