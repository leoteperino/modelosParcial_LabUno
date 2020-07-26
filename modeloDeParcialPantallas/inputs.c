#include "inputs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(int* integer, char* message, char* errorMessage)
{
    int Return = -1;
    char auxNum[4000];

    if(integer != NULL && message != NULL && errorMessage != NULL)
    {
        printf("%s",message);
        fflush(stdin);
        fgets(auxNum,4000,stdin);
        auxNum[strlen(auxNum)-1]='\0';

        while(validationInt(auxNum)== -1)
        {
            printf("%s",errorMessage);
            fflush(stdin);
            fgets(auxNum,4000,stdin);
            auxNum[strlen(auxNum)-1]='\0';
        }

        *integer = atoi(auxNum);
        Return = 0;
    }

    return Return;
}


int validationInt(char num[])
{
    int Return = 0;
    int i = 0;

    if(num[0] == '-' || num[0] == '+')
    {
        i = 1;
    }

    for( ; num[i]!= '\0'; i++)
    {

        if(num[i] < '0' || num[i] > '9')
        {
            Return = -1;
            break;
        }
    }

    return Return;
}

int getFloat(float* decimal, char* message, char* errorMessage)
{
    int Return = -1;
    char auxNum[4000];

    if(decimal != NULL && message != NULL && errorMessage != NULL)
    {
        printf("%s",message);
        fflush(stdin);
        fgets(auxNum,4000,stdin);
        auxNum[strlen(auxNum)-1]='\0';

        while(validationFloat(auxNum)== -1)
        {
            printf("%s",errorMessage);
            fflush(stdin);
            fgets(auxNum,4000,stdin);
            auxNum[strlen(auxNum)-1]='\0';
        }

        *decimal = atof(auxNum);
        Return = 0;
    }

    return Return;

}

int validationFloat(char num[])
{
    int Return = 0;
    int i = 0;
    int counterPoints = 0;

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
                    Return = -1;
                    break;
                }
            }
            else
            {
                Return = -1;
                break;
            }
        }
    }

    if(num[strlen(num)-1] == '.')
    {
        Return = -1;
    }

    return Return;
}

int getString(char* string, char* message, char* errorMessage)
{
    int Return = -1;

    if(string != NULL && message != NULL && errorMessage != NULL)
    {
        printf("%s",message);
        fflush(stdin);
        fgets(string,4000,stdin);
        string[strlen(string)-1]='\0';

        while(validationOnlyLetter(string)== -1)
        {
            printf("%s",errorMessage);
            fflush(stdin);
            fgets(string,4000,stdin);
            string[strlen(string)-1]='\0';
        }

        Return = 0;
    }

    return Return;
}

int validationOnlyLetter(char string[])
{
    int i ;
    int Return = 0;

    for(i=0; string[i]!= '\0'; i++)
    {
        if((string[i] < 'a' || string [i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && (string[i] != ' '))
        {
            Return = -1;
            break;
        }
    }

    return Return;
}

//revisar esta funcion
int getChar(char* character, char* message, char* errorMessage)
{
    int Return = -1;
    char auxChar;

    if(character != NULL && message != NULL && errorMessage != NULL)
    {
        printf("%s",message);
        fflush(stdin);
        scanf("%c",&auxChar);

        while(validationOnlyLetter(character)== -1)
        {
            printf("%s",errorMessage);
            fflush(stdin);
            scanf("%c",&auxChar);
        }

        *character = auxChar;
        Return = 0;
    }

    return Return;
}


int getDni(char* string, char* message, char* errorMessage)
{
    int Return = -1;

    if(string != NULL && message != NULL && errorMessage != NULL)
    {
        printf("%s",message);
        fflush(stdin);
        fgets(string,4000,stdin);
        string[strlen(string)-1]='\0';

        while(validationDni(string)== -1)
        {
            printf("%s",errorMessage);
            fflush(stdin);
            fgets(string,4000,stdin);
            string[strlen(string)-1]='\0';
        }

        Return = 0;
    }

    return Return;
}

int validationDni(char num[])
{
    int Return = 0;
    int i;
    int counterPoints = 0;


    for(i=0; num[i]!= '\0'; i++)
    {
        if(num[i] < '0' || num[i] > '9')
        {
            if(num[i] == '.')
            {
                counterPoints++;
                if(counterPoints>2)
                {
                    Return = -1;
                    break;
                }
            }
            else
            {
                Return = -1;
                break;
            }
        }
    }

    if(num[strlen(num)-1] == '.')
    {
        Return = -1;
    }

    return Return;
}
