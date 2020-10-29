/*
 * Publication.h
 *
 *  Created on: 10 oct. 2020
 *      Author: micavazzana
 */

#ifndef PUBLICATION_H_
#define PUBLICATION_H_
#define ADV_LEN 64
#define ACTIVE 1
#define PAUSED 0
#include "Client.h"

typedef struct
{
    int idClient;
    int rubro;
    char advertisementText[ADV_LEN];
    int idPublication;
    int state;
} Publication;

Publication* publi_new(void);
void publi_delete(Publication* pPubli);

/******************************** SETTERS AND GETTERS ***********************************************/

int publi_setRubro(Publication* this, int rubro);
int publi_getRubro(Publication* this, int* rubro);
int publi_setAdvTxt(Publication* this, char* advTxt);
int publi_getAdvTxt(Publication* this, char* advTxt);
int publi_setState(Publication* this, int state);
int publi_getState(Publication* this, int* state);
int publi_setIdTxt(Publication* this, char* id);
int publi_getIdTxt(Publication* this, char* id);
int publi_setId(Publication* this, int id);
int publi_getId(Publication* this, int* id);
int publi_setIdTxtClient(Publication* this, char* id);
int publi_getIdTxtClient(Publication* this, char* id);
int publi_setIdClient(Publication* this, int id);
int publi_getIdClient(Publication* this, int* id);

/**********************************PUBLICATIONS FUNCTIONS*****************************/

int publi_initArray(Publication* list[], int len);
int publi_findEmptyIndex(Publication* list[], int len);
int publi_loadAndAddData(Publication* listPubli[], int lenPubli, Client* listClient[], int lenClient);
int publi_findByIdClient(Publication* list[], int len, int id);
int publi_findById(Publication* list[], int len, int id);
int publi_remove(Publication* list[], int len, Client* listClient[], int lenClient, int id);
int publi_printOne(Publication* listPubli);
int publi_printList(Publication* list[], int len);
int publi_printListById(Publication* list[], int len, int id);
int publi_isAnyData(Publication* list[], int len); //esto no tiene sentido
int publi_hardCodeData(Publication* list[]);
int publi_isActive(Publication* list[], int len, int id);
int publi_pauseOrActivatePublication(Publication* list[], int len, int idPubli, int choice);
int publi_qtyPublications(Publication* list[], int len, int* qtyAds, int choice);
int publi_printPublicationsByState(Publication* list[], int len, int choice);
int publi_modify(Publication* list[], int len, Client* listClient[], int lenClient);

#endif /* PUBLICATION_H_ */
