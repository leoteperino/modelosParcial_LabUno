/*
 * Client.h
 *
 *  Created on: 10 oct. 2020
 *      Author: micavazzana
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#define ERROR -1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0
#define NAME_LEN 51
#define CUIT_LEN 20

typedef struct
{
    char name[NAME_LEN];
    char lastName[NAME_LEN];
    char cuit[CUIT_LEN];
    int idClient;
    //int isEmpty;
} Client;


Client* cli_newParametres(char* name, char* lastName, char* cuit, int idClient);
Client* cli_new(void);
void cli_delete(Client* pc);

int cli_setName(Client* this, char* name);
int cli_getName(Client* this, char* name);
int cli_setLastName(Client* this, char* lastName);
int cli_getLastName(Client* this, char* lastName);
int cli_setCuit(Client* this, char* cuit);
int cli_getCuit(Client* this, char* cuit);
int cli_setIdTxt(Client* this, char* id);
int cli_getIdTxt(Client* this, char* id);

/*********************************************************************/

int cli_initArray(Client *list[], int len);
int cli_findEmptyIndex(Client *list[], int len);
int cli_loadAndAddData(Client *list[], int len);
int cli_loadAndAddDataConstructorParametres(Client *list[], int len);
int cli_findById(Client* list[], int len, int id);
int cli_modify(Client* list[], int len);
int cli_remove(Client* list[], int len, int id);
int cli_printOne(Client* pClient);
int cli_printList(Client* list[], int len);
int cli_isAnyData(Client* list[], int len);//esto no tiene sentido
int cli_hardCodeData(Client* list[]);

int cli_sort(Client* list, int len, int order);

#endif /* CLIENT_H_ */
