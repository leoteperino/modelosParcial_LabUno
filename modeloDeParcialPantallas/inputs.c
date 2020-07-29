#include "inputs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCES 0
#define ERROR -1


int getString(char* string, int len)
{
    int Return = ERROR;
    char aux[4096];

    if(string != NULL && len > 0)
    {
        fflush(stdin);
        fgets(aux,sizeof(aux),stdin);
        aux[strnlen(aux,sizeof(aux))-1]='\0';

        if(strnlen(aux,sizeof(aux)) <= len)
        {
            strncpy(string,aux,len);
            Return = SUCCES;
        }
    }

    return Return;
}

int getInt(int* integer)
{
    int Return = ERROR;
    char aux[4096];

    if(integer != NULL)
    {
        if(getString(aux,sizeof(aux))== SUCCES && validationInt(aux) == SUCCES)
        {
            *integer = atoi(aux);
            Return = SUCCES;
        }
    }
    return Return;
}

int validationInt(char num[])
{
    int Return = SUCCES;
    int i = 0;

    if(num != NULL)
    {
        if(num[0] == '-' || num[0] == '+')
        {
            i = 1;
        }

        for( ; num[i]!= '\0'; i++)
        {
            if(num[i] < '0' || num[i] > '9')
            {
                Return = ERROR;
                break;
            }
        }
    }

    return Return;
}

int getFloat(float * floating)
{
    int Return = ERROR;
    char aux[4096];

    if(floating != NULL)
    {
        if(getString(aux,sizeof(aux))== SUCCES && validationFloat(aux) == SUCCES)
        {
            *floating = atof(aux);
            Return = SUCCES;
        }
    }
    return Return;
}

int validationFloat(char num[])
{
    int Return = SUCCES;
    int i = 0;
    int counterPoints = 0;

    if(num != NULL)
    {
        if(num[0] == '-' || num[0] == '+')
        {
            i = 1;
        }

        for( ; num[i]!= '\0'; i++)
        {
            if(num[i] < '0' || num[i] > '9')
            {
                if(num[i] == '.')
                {
                    counterPoints++;
                    if(counterPoints>1)
                    {
                        Return = ERROR;
                        break;
                    }
                }
                else
                {
                    Return = ERROR;
                    break;
                }
            }
        }
    }

    return Return;
}

int getTxt(char* txt, int len)
{
    int Return = ERROR;
    char aux[4096];

    if(txt!= NULL)
    {
        if(getString(aux,sizeof(aux))== SUCCES && validationOnlyLetter(aux) == SUCCES && (strnlen(aux,sizeof(aux))<len))
        {
            strncpy(txt,aux,len);
            Return = SUCCES;
        }
    }
    return Return;
}

int validationOnlyLetter(char string[])
{
    int i ;
    int Return = SUCCES;

    for(i=0; string[i]!= '\0'; i++)
    {
        if((string[i] < 'a' || string [i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && (string[i] != ' '))
        {
            Return = ERROR;
            break;
        }
    }

    return Return;
}

int getAlphaNumeric(char* txt, int len)
{
    int Return = ERROR;
    char aux[4096];

    if(txt!= NULL)
    {
        if(getString(aux,sizeof(aux))== SUCCES && validationAlphaNumeric(aux) == SUCCES && (strnlen(aux,sizeof(aux))<len))
        {
            strncpy(txt,aux,len);
            Return = SUCCES;
        }
    }
    return Return;
}

int validationAlphaNumeric(char string[])
{
    int i ;
    int Return = SUCCES;

    for(i=0; string[i]!= '\0'; i++)
    {
        if((string[i] < 'a' || string [i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && (string[i] != ' ') && (string[i] < '0' || string[i] > '9'))
        {
            Return = ERROR;
            break;
        }
    }

    return Return;
}


int getNumber(int* number, char* message, char* errorMessage, int min, int max)
{
    int Return = ERROR;
    int auxNumber;

    if(number != NULL && message != NULL && errorMessage != NULL && min<max && max>min)
    {
        do
        {
            printf("%s",message);

            if(getInt(&auxNumber) == SUCCES && auxNumber>=min && auxNumber<=max)
            {
                Return = SUCCES;
                *number = auxNumber;
                break;
            }
            printf("%s",errorMessage);

        }while(Return == ERROR);
    }

    return Return;
}

int getFloatNumber(float* floatNumber, char* message, char* errorMessage, int min, int max)
{
    int Return = ERROR;
    float auxNumber;

    if(floatNumber != NULL && message != NULL && errorMessage != NULL && min<max && max>min)
    {
        do
        {
            printf("%s",message);

            if(getFloat(&auxNumber) == SUCCES && auxNumber>=min && auxNumber<=max)
            {
                Return = SUCCES;
                *floatNumber = auxNumber;
                break;
            }
            printf("%s",errorMessage);

        }while(Return == ERROR);
    }

    return Return;
}

int getName(char* name, int len, char* message, char* errorMessage)
{
    int Return = ERROR;
    char aux[4096];

    if(name != NULL && message != NULL && errorMessage != NULL)
    {
        do
        {
            printf("%s",message);

            if(getTxt(aux,sizeof(aux))==SUCCES && strnlen(aux,sizeof(aux))<len)
            {
                Return = SUCCES;
                strncpy(name,aux,len);
                break;
            }
            printf("%s",errorMessage);

        }while(Return == ERROR);
    }

    return Return;
}

int getTxtAndNum(char* txt, int len, char* message, char* errorMessage)
{
    int Return = ERROR;
    char aux[4096];

    if(txt != NULL && message != NULL && errorMessage != NULL)
    {
        do
        {
            printf("%s",message);

            if(getAlphaNumeric(aux,sizeof(aux))==SUCCES && strnlen(aux,sizeof(aux))<len)
            {
                Return = SUCCES;
                strncpy(txt,aux,len);
                break;
            }
            printf("%s",errorMessage);

        }while(Return == ERROR);
    }

    return Return;
}
