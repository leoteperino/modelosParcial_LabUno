#define ERROR -1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0
#define FIELDNAME_LEN 51
#define DATATYPE_LEN 10
#define ENTITY_LEN 100
#include "inputs.h"

typedef struct{
    char dataType[DATATYPE_LEN];
    char fieldName[FIELDNAME_LEN];
    int isEmpty;
}EntityBuilder;

int printNew(char* entityStructName);
int printDelete(char* entityStructName);
int selectDataType(EntityBuilder* list, int len);
int setFieldName(EntityBuilder* list, int len ,char* dataType);
int initArray(EntityBuilder* list, int len);
int findEmptyIndex(EntityBuilder* list, int len);
int printOne(EntityBuilder list);
int printList(EntityBuilder *list, int len);
int printStruct(EntityBuilder *list, int len, char* structName);
void printSetterChar(char* dataType, char* fieldName, char* structName);
void printSetter(char* dataType, char* fieldName, char* structName);
int printAllSetters(EntityBuilder* list, int len, char* structName);
void printGetterChar(char* dataType, char* fieldName, char* structName);
void printGetter(char* dataType, char* fieldName, char* structName);
int printAllGetters(EntityBuilder* list, int len, char* structName);