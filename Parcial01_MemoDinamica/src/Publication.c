/*
 * Publication.c
 *
 *  Created on: 10 oct. 2020
 *      Author: micavazzana
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "inputs.h"
#include "Publication.h"

Publication* publi_new(void)
{
    return (Publication*)malloc(sizeof(Publication));
}

void publi_delete(Publication* pPubli)
{
    if (pPubli != NULL)
        free(pPubli);
}

/******************************** SETTERS AND GETTERS ***********************************************/

int publi_setRubro(Publication* this, int rubro)
{
    int result = ERROR;
    if (this != NULL && rubro >=0)
    {
        this->rubro = rubro;
        result = SUCCESS;
    }
    return result;
}

int publi_getRubro(Publication* this, int* rubro)
{
    int result = ERROR;
    if (this != NULL && rubro != NULL)
    {
        *rubro = this->rubro;
        result = SUCCESS;
    }
    return result;
}

int publi_setAdvTxt(Publication* this, char* advTxt)
{
    int result = ERROR;
    if(this != NULL && advTxt != NULL && isValidAlphaNumeric(advTxt,NAME_LEN))
    {
        strncpy(this->advertisementText, advTxt,(int)sizeof(this->advertisementText));
        result = SUCCESS;
    }
    return result;
}

int publi_getAdvTxt(Publication* this, char* advTxt)
{
    int result = ERROR;
    if(this != NULL && advTxt != NULL)
    {
        strncpy(advTxt, this->advertisementText, (int)sizeof(advTxt));
        result = SUCCESS;
    }
    return result;
}

int publi_setState(Publication* this, int state)
{
    int result = ERROR;
    if (this != NULL && (state == 1 || state == 0))
    {
        this->state = state;
        result = SUCCESS;
    }
    return result;
}

int publi_getState(Publication* this, int* state)
{
    int result = ERROR;
    if (this != NULL && state != NULL)
    {
        *state = this->state;
        result = SUCCESS;
    }
    return result;
}

int publi_setIdTxt(Publication* this, char* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL && isValidNumber(id, 1000))
    {
        this->idPublication = atoi(id);
        result = SUCCESS;
    }
    return result;
}

int publi_getIdTxt(Publication* this, char* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL)
    {
        sprintf(id, "%d", this->idPublication);
        result = SUCCESS;
    }
    return result;
}

int publi_setId(Publication* this, int id)
{
    int result = ERROR;
    if (this != NULL && id >= 0)
    {
        this->idPublication = id;
        result = SUCCESS;
    }
    return result;
}

int publi_getId(Publication* this, int* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL)
    {
        *id = this->idPublication;
        result = SUCCESS;
    }
    return result;
}

int publi_setIdTxtClient(Publication* this, char* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL && isValidNumber(id, 1000))
    {
        this->idClient = atoi(id);
        result = SUCCESS;
    }
    return result;
}

int publi_getIdTxtClient(Publication* this, char* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL)
    {
        sprintf(id, "%d", this->idClient);
        result = SUCCESS;
    }
    return result;
}

int publi_setIdClient(Publication* this, int id)
{
    int result = ERROR;
    if (this != NULL && id >=0)
    {
        this->idClient = id;
        result = SUCCESS;
    }
    return result;
}

int publi_getIdClient(Publication* this, int* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL)
    {
        *id = this->idClient;
        result = SUCCESS;
    }
    return result;
}

/**********************************PUBLICATIONS FUNCTIONS*****************************/

/**
 * \brief To indicate that all position in the array are empty
 * \param list Publication*[] Pointer to array of pointers of Publication type
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
    int publi_initArray(Publication* list[], int len)
{
    int result = ERROR;
    int i;

    if (list != NULL && len > 0)
    {
        for (i = 0; i < len; i++)
        {
            list[i] = NULL;
            //*(list+i)=NULL;
        }
        result = SUCCESS;
    }
    return result;
}

/**
 * \brief Searches for an empty index in the array,
 * 		  this function checks if the pointer is NULL and saves the first index found.
 * \param list Publication*[] Pointer to array of pointers of Publication type
 * \param len int Array length
 * \return int Return value of the first empty index found -
 * 			   or (-1) if Error [Invalid length, NULL pointer or if there isn't more avaible space]
 */
int publi_findEmptyIndex(Publication* list[], int len)
{
    int result = ERROR;
    int i;

    if (list != NULL && len > 0)
    {
        for (i = 0; i < len; i++)
        {
            if (list[i] == NULL)
            {
                result = i;
                break;
            }
        }
    }
    return result;
}

/**
 * \brief Generates a new id for a new publication,
 * \param void
 * \return int Return value of the new id
 */
static int generateNewId(void)
{
    static int id = 0;
    id++;
    return id;
}

/**
 * \brief Requests the user to complete the data asked and adds that data to the array.
 * \param listPubli Publication* Pointer to array of publications
 * \param lenPubli int Array length of publications
 * \param listClient Client* Pointer to array of clients
 * \param lenClient int Array length of clients
 * \return Return (-1) if Error - Invalid length or NULL pointer of the arguments or no avaible space (in publications array)
 * 				  (-2) if Error - wrong entry of the fields
 * 				  or publication index position where it was charged
 */
int publi_loadAndAddData(Publication* listPubli[], int lenPubli, Client* listClient[], int lenClient)
{
    int result = ERROR;
    Publication bufferPubli;
    int index;
    Publication* pPubli;

    if (listPubli != NULL && lenPubli > 0 && listClient != NULL && lenClient > 0)
    {
        pPubli = publi_new();
        if (pPubli != NULL)
        {
            index = publi_findEmptyIndex(listPubli, lenPubli);
            if (index != ERROR
                && cli_printList(listClient, lenClient) == SUCCESS
                && utn_getNumber(&bufferPubli.idClient, "\nIngrese el id del cliente para realizar la publicacion: ", "\nError", 0, INT_MAX, 3) == SUCCESS
                && cli_findById(listClient, lenClient, bufferPubli.idClient) != ERROR
                && utn_getNumber(&bufferPubli.rubro, "\nIngrese numero de rubro: ", "\nError", 0, INT_MAX, 3) == SUCCESS
                && utn_getAlphanumeric(bufferPubli.advertisementText, ADV_LEN, "\nIngrese el texto del aviso: \n", "\nError!", 3) == SUCCESS)
            {
                bufferPubli.state = ACTIVE;
                bufferPubli.idPublication = generateNewId();
                publi_setIdClient(pPubli,bufferPubli.idClient);
                publi_setRubro(pPubli,bufferPubli.rubro);
                publi_setAdvTxt(pPubli,bufferPubli.advertisementText);
                publi_setId(pPubli,bufferPubli.idPublication);
                publi_setState(pPubli,bufferPubli.state);
                listPubli[index] = pPubli;
                result = index; //SUCCESS;
            }
            else
            {
                result = -2;
                publi_delete(pPubli);
            }
        }
    }
    return result;
}

/**
 * \brief Searches the position in which is the client id
 * \param list Publication* Pointer to array of publications
 * \param len int Array length
 * \param id int, id searched
 * \return Return publication index position or (-1) if [Invalid length or NULL pointer received or client not found]
 */
int publi_findByIdClient(Publication* list[], int len, int id)
{
    int result = ERROR;
    int i;
    int bufferId;

    if (list != NULL && len > 0 && id > 0)
    {
        for (i = 0; i < len; i++)
        {
            publi_getIdClient(list[i],&bufferId);
            if (list[i] != NULL && bufferId == id)
            {
                result = i;
                break;
            }
        }
    }
    return result;
}

/**
 * \brief Searches a Publication by Id
 * \param list Publication* Pointer to array of publications
 * \param len int Array length
 * \param id int, id searched
 * \return Return publication index position or (-1) if [Invalid length or NULL pointer received or publication not found]
 */
int publi_findById(Publication* list[], int len, int id)
{
    int result = ERROR;
    int i;
    int bufferId;

    if (list != NULL && len > 0 && id > 0)
    {
        for (i = 0; i < len; i++)
        {
            publi_getId(list[i],&bufferId);
            if (list[i] != NULL && bufferId == id)
            {
                result = i;
                break;
            }
        }
    }
    return result;
}

/**
 * \brief Remove a publication searched by Id (put isEmpty Flag in 1)
 * \param list Publication* Pointer to array of publications
 * \param len int Array publications length
 * \param listClient Client* Pointer to array of clients
 * \param lenClient Array client length
 * \param id int, id searched
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a publication with that client id] -
 * 					  (0) if Ok
 * 					  (-2) if it can't find the id client
 */
int publi_remove(Publication* list[], int len, Client* listClient[], int lenClient, int id)
{
    int result = ERROR;
    int index;

    if (list != NULL && len > 0 && listClient != NULL && lenClient > 0 && id > 0)
    {
        index = publi_findByIdClient(list, len, id);
        if (list != NULL && index != ERROR)
        {
            publi_delete(list[index]);
            list[index] = NULL;
            result = SUCCESS;
        }
        else
        {
            result = -2;
        }
    }
    return result;
}

/**
 * \brief Prints the data of only one publication
 * \param list Publication* Pointer to list
 * \return Return (-1) if Error [flag isEmpty is TRUE] - (0) if Ok
 */
int publi_printOne(Publication* listPubli)
{
    int result = ERROR;
    char state[10];
    Publication buffer;

    if (listPubli != NULL)
    {
        publi_getId(listPubli,&buffer.idPublication);
        publi_getIdClient(listPubli,&buffer.idClient);
        publi_getRubro(listPubli,&buffer.rubro);
        publi_getAdvTxt(listPubli,buffer.advertisementText);
        publi_getState(listPubli,&buffer.state);
        if (buffer.state == PAUSED)
        {
            sprintf(state, "PAUSADO");
        }
        else if (buffer.state == ACTIVE)
        {
            sprintf(state, "ACTIVO");
        }
        printf("\n%10d %15d %15d %35s %20s\n",
                buffer.idPublication,
                buffer.rubro,
                buffer.idClient,
                buffer.advertisementText,
                state);
        result = SUCCESS;
    }
    return result;
}

/**
 * \brief Print the content of publications array
 * \param list Publication* Pointer to array of publications
 * \param length int  Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int publi_printList(Publication* list[], int len)
{
    int result = ERROR;
    int i;

    if (list != NULL && len > 0)
    {
        printf("\n%10s %15s %15s %35s %20s\n", "ID PUBLI", "RUBRO", "ID CLIENTE", "TEXTO AVISO", "ESTADO");
        for (i = 0; i < len; i++)
        {
            publi_printOne(list[i]);
        }
        result = SUCCESS;
    }
    return result;
}

/**
 * \brief Print the content of publications array of the id received
 * \param list Publication* Pointer to array of publications
 * \param length int  Array length
 * \param id int, id received
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int publi_printListById(Publication* list[], int len, int id)
{
    int result = ERROR;
    int i;
    int bufferId;

    if (list != NULL && len > 0 && id > 0)
    {
        printf("\n%10s %15s %15s %35s %20s\n", "ID PUBLI", "RUBRO", "ID CLIENTE", "TEXTO AVISO", "ESTADO");
        for (i = 0; i < len; i++)
        {
            publi_getIdClient(list[i],&bufferId);
            if (bufferId == id)
            {
                publi_printOne(list[i]);
            }
        }
        result = SUCCESS;
    }
    return result;
}

/**
 * \brief Checks if there is any data in the array
 * 			this function checks the flag (isEmpty). If it is false, there is data.
 * \param list Publication* Pointer to array of publications
 * \param len int Array length
 * \return int Returns TRUE(1) if there is data, if not, returns FALSE(0)
 */
int publi_isAnyData(Publication* list[], int len)
{
    int i;
    int result = FALSE;

    if (list != NULL && len > 0)
    {
        for (i = 0; i < len; i++)
        {
            if (list[i] != NULL) //if there is data
            {
                result = TRUE;
                break;
            }
        }
    }
    return result;
}

/**
 * \brief Forces data into the array of publications
 * \param list Publication* Pointer to array of publications
 * \return Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int publi_hardCodeData(Publication* list[])
{
    int result = ERROR;
    int idClient[] = {1, 2, 3, 4, 8, 2, 7, 5, 2, 10, 9, 6, 6};
    int rubro[] = {11, 11, 22, 11, 22, 33, 55, 33, 44, 44, 55, 66, 22};
    char advertisementText[][ADV_LEN] = {"Telefonos baratos", "Eliminacion de monstruos", "Se busca radio con antena",
                                         "Carpas de Will, la mejor proteccion", "Buenas vibras spa", "La buena rula", "Comida casera", "Jardineria, corto su pasto",
                                         "Compra luces de todos los colores", "Nos comunicamos con el otro lado", "Foto pro, la mejor foto de tu boda", "Defensa de su hogar", "Cuidado de niños"};
    int i;
    int bufferId;
    Publication* pPubli;

    if (list != NULL)
    {
        for (i = 0; i < 13; i++)
        {
            pPubli = publi_new();
            if (pPubli != NULL)
            {
                publi_setIdClient(pPubli,idClient[i]);
                bufferId=generateNewId();
                publi_setId(pPubli,bufferId);
                publi_setRubro(pPubli,rubro[i]);
                publi_setAdvTxt(pPubli,advertisementText[i]);
                publi_setState(pPubli,ACTIVE);
                list[i] = pPubli;
            }
        }
        result = SUCCESS;
    }
    return result;
}

/**
 * \brief Checks if the publication is alredy in active state
 * \param list Publication* Pointer to array of publications
 * \param len int Array length
 * \param id int, id searched
 * \return int Returns TRUE(1) if is active, if not, returns FALSE(0)
 */
int publi_isActive(Publication* list[], int len, int id)
{
    int i;
    int result = FALSE;
    int bufferId;
    int bufferState;

    if (list != NULL && len > 0 && id > 0)
    {
        for (i = 0; i < len; i++)
        {
            publi_getId(list[i],&bufferId);
            publi_getState(list[i],&bufferState);
            if (bufferState == ACTIVE && id == bufferId) //if that publication it's active
            {
                result = TRUE;
                break;
            }
        }
    }
    return result;
}

/**
 * \brief Pause or Activates a publication searched by Id (put state Flag in 0 or 1)
 * \param list Publication* Pointer to array of publications
 * \param len int Array length
 * \param id int, id searched
 * \param choice int, indicates the state ACTIVE or PAUSED
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a publication] - (0) if Ok
 */
int publi_pauseOrActivatePublication(Publication* list[], int len, int idPubli, int choice)
{
    int result = ERROR;
    int index;

    if (list != NULL && len > 0 && idPubli > 0 && (choice == PAUSED || choice == ACTIVE))
    {
        index = publi_findById(list, len, idPubli);
        if (list[index] != NULL && index != ERROR)
        {
            if (choice == ACTIVE)
            {
                publi_setState(list[index],ACTIVE);
                result = SUCCESS;
            }
            else
            {
                publi_setState(list[index],PAUSED);
                result = SUCCESS;
            }
        }
    }
    return result;
}

/**
 * \brief It counts the quantity of paused or active publications
 * \param list Publication* Pointer to array of publications
 * \param len int Array length
 * \param qtyAds *int Pointer to the space where it will save the quantity of publications counted
 * \param choice int, indicates the state ACTIVE or PAUSED
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int publi_qtyPublications(Publication* list[], int len, int *qtyAds, int choice)
{
    int result = ERROR;
    int i;
    int counter = 0;
    int bufferState;

    if (list != NULL && len > 0 && qtyAds != NULL && (choice == PAUSED || choice == ACTIVE))
    {
        for (i = 0; i < len; i++)
        {
            publi_getState(list[i],&bufferState);
            if (list[i] != NULL && bufferState == choice)
            {
                counter++;
            }
        }
        *qtyAds = counter;

        result = SUCCESS;
    }
    return result;
}

/**
 * \brief Prints the list of publications by the chosen state
 * \param list Publication* Pointer to array of publications
 * \param len int Array length
 * \param choice int, indicates the state ACTIVE or PAUSED
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int publi_printPublicationsByState(Publication* list[], int len, int choice)
{
    int result = ERROR;
    int i;
    int bufferState;

    if (list != NULL && len > 0 && (choice == PAUSED || choice == ACTIVE))
    {
        printf("\n\n%10s %15s %15s %35s %20s\n", "ID PUBLI", "RUBRO", "ID CLIENTE", "TEXTO AVISO", "ESTADO");
        for (i = 0; i < len; i++)
        {
            publi_getState(list[i],&bufferState);
            if (list[i] != NULL && bufferState == choice)
            {
                publi_printOne(list[i]);
            }
        }
        result = SUCCESS;
    }
    return result;
}

/**
 * \brief Modifys data from publications. Allows the user to decide which field to change.
 * \param list Publication* Pointer to array of publications
 * \param len int Array publications length
 * \param listClient Client* Pointer to array of clients
 * \param lenClient int Array clients length
 * \return Return (-1) Error - if Invalid length or NULL pointer or if can't find a publication
 * 				  (-2) Error - if Id Client could not be changed
 * 				  (-3) Error - if rubro could not be changed
 * 				  (-4) Error - if advertisement Text could not be changed
 * 				  (0) if Ok
 */
int publi_modify(Publication* list[], int len, Client* listClient[], int lenClient)
{
    int result = ERROR;
    int index;
    Publication bufferPubli;
    int option;

    if (list != NULL && len > 0)
    {
    	if (publi_printList(list,len) == SUCCESS
    		&& utn_getNumber(&bufferPubli.idPublication,"\nIngrese el id de la publicacion que quiere modificar: ","\nError!",0,INT_MAX,5) == SUCCESS
    		&& publi_findById(list, len, bufferPubli.idPublication)!= ERROR)
    	{
    		index = publi_findById(list, len, bufferPubli.idPublication);
    		if(list[index]!=NULL)
    		{
    			do {
    				if (utn_getNumber(&option,
    						"\n\nIngrese una opcion: "
    						"\n1.Modificar Id Cliente "
    						"\n2.Modificar Rubro "
    						"\n3.Modificar Texto del Aviso "
    						"\n4.Volver al menu principal\n",
    						"Error, elija una opcion valida\n", 1, 4, 3) == SUCCESS)
    				{
    					switch (option)
    					{
    					case 1:
    						if (cli_printList(listClient,lenClient) == SUCCESS
    								&& utn_getNumber(&bufferPubli.idClient,"Ingrese un nuevo id de cliente a quien asignar la publicacion: ","\nError!",0,INT_MAX, 3) == SUCCESS) {
    							publi_setIdClient(list[index],bufferPubli.idClient);
    							result = SUCCESS;
    						} else {
    							result = -2;
    						}
    						break;
    					case 2:
    						if (utn_getNumber(&bufferPubli.rubro,"Ingrese un nuevo rubro: ","\nError!",0,INT_MAX, 3) == SUCCESS) {
    							publi_setRubro(list[index],bufferPubli.rubro);
    							result = SUCCESS;
    						} else {
    							result = -3;
    						}
    						break;
    					case 3:
    						if (utn_getAlphanumeric(bufferPubli.advertisementText,ADV_LEN,"\nIngrese un nuevo texto para el aviso: \n","\nError!",3) == SUCCESS) {
    							publi_setAdvTxt(list[index],bufferPubli.advertisementText);
    							result = SUCCESS;
    						} else {
    							result = -4;
    						}
    						break;
    					}//fin switch
    				} else {
    					printf("Se acabaron sus reintentos, vuelva a ingresar");
    				}
    				if(result<0)
    				{
    					break;
    				}
    			} while (option != 4);
    		}
    	}
    }
    return result;
}
