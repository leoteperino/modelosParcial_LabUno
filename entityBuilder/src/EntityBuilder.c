#include <stdio.h>
#include <string.h>
#include "EntityBuilder.h"

int initArray(EntityBuilder* list, int len)
{
    int result = ERROR;
    int i;

    if (list != NULL && len > 0)
    {
        for (i = 0; i < len; i++)
        {
            list[i].isEmpty = TRUE;
        }
        result = SUCCESS;
    }
    return result;
}

int findEmptyIndex(EntityBuilder* list, int len)
{
    int result = ERROR;
    int i;

    if (list != NULL && len > 0)
    {
        for (i = 0; i < len; i++)
        {
            if (list[i].isEmpty == TRUE)
            {
                result = i;
                break;
            }
        }
    }
    return result;
}

int setFieldName(EntityBuilder* list, int len ,char* dataType)
{
    int result = ERROR;
    char bufferFieldName[FIELDNAME_LEN];
    char bufferDataType[DATATYPE_LEN];
    int index;
    
    if(list != NULL && dataType != NULL)
    {
        index = findEmptyIndex(list, len);
        if(index != ERROR && 
            utn_getName(bufferFieldName,FIELDNAME_LEN,"Ingrese el nombre del campo: ","Error",5)==SUCCESS)
        {
            strncpy(list[index].fieldName,bufferFieldName,FIELDNAME_LEN);
            sprintf(bufferDataType,"%s",dataType);
            strncpy(list[index].dataType,bufferDataType,DATATYPE_LEN);
            list[index].isEmpty = FALSE;
            result = SUCCESS;
        }
    }
    return result;
}

int selectDataType(EntityBuilder* list, int len)
{
    int result = ERROR;
    int dataType;

    if(list != NULL && len>0)
    {
        do {
            if(utn_getNumber(&dataType,"\nIngrese el tipo de dato que quiere generar:\n"
                                    "\n1. int"
                                    "\n2. int*"
                                    "\n3. char"
                                    "\n4. char*"
                                    "\n5. float"
                                    "\n6. float*"
                                    "\n7. long"
                                    "\n8. long*"
                                    "\n9. SALIR\n",
                                    "\nError,no es una opcion valida",1,9,5) == SUCCESS)
            {
                switch(dataType)
                {
                    case 1:
                    setFieldName(list,len,"int");
                        break;
                    case 2:
                    setFieldName(list,len,"int*");
                        break;
                    case 3:
                    setFieldName(list,len,"char");
                        break;
                    case 4:
                    setFieldName(list,len,"char*");
                        break;
                    case 5:
                    setFieldName(list,len,"float");
                        break;
                    case 6:
                    setFieldName(list,len,"float*");
                        break;
                    case 7:
                    setFieldName(list,len,"long");
                        break;
                    case 8:
                    setFieldName(list,len,"long*");
                        break;
                }
            }
            result=SUCCESS;
        }while(dataType!=9);
    }
    return result;
}

int printNew(char* entityStructName)
{
    int result = ERROR;
    if(entityStructName != NULL)
    {
        printf("\n%s* %s_new() \n{\n\treturn (%s*)malloc(sizeof(%s));\n}\n",entityStructName,entityStructName,entityStructName,entityStructName);
        result = SUCCESS;
    }
    return result;
}

int printDelete(char* entityStructName) 
{
    printf("\nvoid %s_delete(%s* this)\n{\n\tfree(this);\n}\n",entityStructName,entityStructName);
}

int printOne(EntityBuilder list)
{
	int result = ERROR;

	if (list.isEmpty == FALSE)
	{
		printf("\n\t%s %s;",
				list.dataType,
				list.fieldName);
		result = SUCCESS;
	}
	return result;
}

int printList(EntityBuilder *list, int len)
{
	int result = ERROR;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			printOne(list[i]);
		}
		result = SUCCESS;
	}
	return result;
}

int printStruct(EntityBuilder *list, int len, char* structName)
{
    int result = ERROR;
    
    if(list != NULL && len > 0 && structName != NULL)
    {
        printf("\ntypedef struct {");
        printList(list,len);
        printf("\n}%s;\n",structName);
        result = SUCCESS;
    }
    return result;
}

void printSetterChar(char* dataType, char* fieldName, char* structName)
{
    printf("\n%s %s_Set%s(%s* this, %s %s)\n{\n", dataType,
                                                  structName,
                                                  fieldName,
                                                  structName,
                                                  dataType,
                                                  fieldName);
    printf("\tint result = ERROR;\n\tif(this != NULL && %s != NULL)\n\t{\n",fieldName);
    printf("\t\tstrncpy(this->%s,%s,(int)sizeof(this->%s));\n\t\tresult = SUCCESS;\n", fieldName, fieldName, fieldName);
    printf("\t}\n\treturn result;\n}\n\n");
}

void printSetter(char* dataType, char* fieldName, char* structName)
{
    printf("\n%s %s_set%s(%s* this, %s %s)\n{\n", dataType,
                                                  structName,
                                                  fieldName,
                                                  structName,
                                                  dataType,
                                                  fieldName);
    printf("\tint result = ERROR;\n\tif(this != NULL && %s > 0)\n\t{\n",fieldName);
    printf("\t\tthis->%s = %s;\n\t\tresult = SUCCESS;\n", fieldName, fieldName);
    printf("\t}\n\t return result;\n}\n\n");
}

int printAllSetters(EntityBuilder* list, int len, char* structName)
{
    int result = ERROR;
    
    if(list != NULL && len > 0 && structName != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                if(strncmp(list[i].dataType, "char*", DATATYPE_LEN)==0
                   || strncmp(list[i].dataType, "char", DATATYPE_LEN)==0)
                {
                    printSetterChar(list[i].dataType, list[i].fieldName,structName);
                    result = 0;
                }
                else
                {
                    printSetter(list[i].dataType, list[i].fieldName,structName);
                    result = 0;
                }

            }
        }
    }
    return result;
}