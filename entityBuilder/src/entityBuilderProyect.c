/*
 ============================================================================
 Name        : entityBuilder.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "EntityBuilder.h"

int main()
{
    EntityBuilder list[ENTITY_LEN];
    char structName[51];

    if (initArray(list,ENTITY_LEN) == SUCCESS)
    {
        utn_getName(structName,51,"Ingrese nombre de la estructura: ","Error",5);
        selectDataType(list,ENTITY_LEN);
        printf("\n\nARCHIVO MAGICO: \n\n");
        printf("\n#define ERROR -1\n#define SUCCESS 0\n#define TRUE 1\n#define FALSE 0\n");
        printStruct(list, ENTITY_LEN, structName);
        printNew(structName);
        printDelete(structName);
        printAllSetters(list,ENTITY_LEN,structName);
        //printAllGetters(list,ENTITY_LEN,structName);
    }
    return 0;
}
