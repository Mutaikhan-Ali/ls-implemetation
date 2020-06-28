#include "source.h"

int my_strcmp(char *a, char *b)
{
    int returnValue = 0;
    int str_index = 0;

    while (returnValue == 0)
    {
        if(a[str_index] > b[str_index])
        {
            returnValue = 1;
        }
        else if(a[str_index] < b[str_index])
        {
            returnValue = -1;
        }

        if(a[str_index] == '\0')
        {
            break;
        }

        str_index++;
    }
    

    return returnValue;
}

size_t my_strlen(char*a)
{
    int len = 0;
    while(a[len] != '\0')
    {
        len++;
    }

    return len;
}

char*  my_strcat(char *dest, char *src)
{
    char* resultString = dest;

    // check if is valid
    if(dest != NULL && src != NULL)
    {
        // get the len
        while(*dest != '\0')
        {
            dest++;
        }
        // copy value
        
        while(*src != '\0')
        {
           *dest++ = *src++; 
        }
        // make null terminated
        *dest = '\0';
    }



    return resultString;
}

char* my_strcpy(char*a,char*b)
{
    char*returnString  = a;

    // cheking if strings are valid
    if(a != NULL && b != NULL)
    {
        // copy values till the null character
        while(*b != '\0')
        {   
            *a++ = *b++;
        }
        // make null terminated
        *a = '\0';
    }

    return returnString; 
}