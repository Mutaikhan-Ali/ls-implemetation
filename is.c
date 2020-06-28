#include "source.h"

int is_Exist(char *path)
{
    DIR* dir;
    
    dir = opendir(path);

    if(dir != NULL)
    {
        closedir(dir);
        return 1;
    }

    return 0;
}

int is_Exist_File(char*name)
{
    FILE* file;
    if((file = fopen(name, "r")))
    {
        fclose(file);
        return 1;
    }
    return -1;
}

int is_Command(char* arg)
{
    if(arg[0] == '-')
    {
        return 1;
    }
    return 0;
}

int is_a(char a)
{
    if(a == 'a')
    {
        return 1;
    }
    return 0;
}

int is_t(char t)
{
    if(t == 't')
    {
        return 1;
    }
    return 0;
}

int is_R(char R)
{
    if(R == 'R')
    {
        return 1;
    }
    return 0;
}


