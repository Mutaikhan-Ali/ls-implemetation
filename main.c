#include "source.h"


void free_path(t_opt*opt)
{
    free(opt->path);
}

void print_resultFOR_ONE_PATH(t_opt* opt)
{ 
        if(opt->ls_R)
        {
            myls_R(opt,opt->path,opt->ls_a,opt->ls_t);
        }
        
        else
        {
            myls(opt->ls_err, opt->path, opt->ls_a,opt->ls_t);
        }
        
        free(opt->path);
        free(opt);
}


int main(int ac, char**av)
{
    t_opt*data = get_values(ac, av);
    int path_number = get_pathes(ac, av);
    
    if(path_number > 1)
    {
        print_result_for_pathes(data,ac,av);
    }
    else
    {
        print_resultFOR_ONE_PATH(data);
    }
    
}

// gcc -g -fsanitize=address main.c set.c parse.c is.c get.c init.c sort.c string.c ls.c 
// gcc -c main.c set.c parse.c is.c get.c init.c ls.c sort.c  string.c
// gcc main.o set.o parse.o is.o get.o init.o sort.o string.o ls.o 