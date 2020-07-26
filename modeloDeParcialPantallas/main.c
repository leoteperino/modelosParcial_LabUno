
#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"
#include "Contrataciones.h"
#include "inputs.h"

#define CANTIDAD_PANTALLAS 100
#define CANTIDAD_CONTRATACIONES 1000

int main(void) {

	eContratacion arraysContrataciones[CANTIDAD_CONTRATACIONES];
	ePantalla arrayPantallas[CANTIDAD_PANTALLAS];
	int idPantallas=0;
//	int idContrataciones=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;

	if(pan_inicializarArray(arrayPantallas,CANTIDAD_PANTALLAS) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}

	if(con_inicializarArray(arraysContrataciones,CANTIDAD_CONTRATACIONES) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}

	do
	{
		printf("\n1.Cargar una pantalla \n2.Modificar una pantalla \n3.Eliminar una pantalla \n4.- \n5.Imprimir lista pantalla \n6.-\n7.Salir\n");
		scanf("%d",&opcion);

		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = pan_getEmptyIndex(arrayPantallas,CANTIDAD_PANTALLAS);
				if(auxiliarIndice >= 0)
				{
					if(pan_altaArray(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarIndice,&idPantallas) == 0)
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				pan_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);
				if(getInt(&auxiliarId,"\nIndique el ID del cliente a modificar","\nID invalido") == 0)
				{
					auxiliarIndice = pan_buscarId(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarId);
					if(	auxiliarIndice >= 0 &&
							pan_modificarArray(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				pan_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);
				if(getInt(&auxiliarId,"\nIndique el ID del cliente a eliminar","\nID invalido")==0)
				{
					auxiliarIndice = pan_buscarId(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarId);
					if(	auxiliarIndice >= 0 &&
							pan_bajaArray(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:
				pan_ordenarPorNombre(arrayPantallas,CANTIDAD_PANTALLAS);
				break;

			case 5:
				pan_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);
				break;

			case 6:
				pan_ordenarPorNombre(arrayPantallas,CANTIDAD_PANTALLAS);
				break;
            case 7:
                printf("\nHasta luego!\n");
                break;
            default:
                printf("\nNo es una opcion valida\n");
                break;
			}
		}
	}while(opcion != 7);

	return 0;
}
