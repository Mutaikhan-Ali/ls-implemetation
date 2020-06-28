#include "source.h"


void multile_output(t_opt*opt,char*arr_pathes[],int path_number)
{
    for(int i = 0;i < path_number;i++)
    {
        if(opt->ls_R)
        {
            myls_R(opt, opt->path,opt->ls_a,opt->ls_t);
        }
        
        else
        {
           

            printf("%s:\n",arr_pathes[i]);
            myls(opt->ls_err, opt->path, opt->ls_a,opt->ls_t);
        }
         if(i < path_number - 1)
        {
                printf("\n");
        }
    }
}
void print_result_for_pathes(t_opt*opt,int ac,char**av)
{

    int path_number = get_pathes(ac, av);
    char* arr_pathes[path_number];
    set_path_values(ac, av, arr_pathes);
    lexico_sort(arr_pathes, path_number);
    multile_output(opt,arr_pathes, path_number);
    free_string(arr_pathes, path_number);
    free(opt->path);
    free(opt);
}

t_opt* init_opt(int l)
{
    t_opt* opt = (t_opt*)malloc(sizeof(t_opt));
    opt->ls = 1;
    opt->ls_a = 0;
    opt->ls_R = 0;
    opt->ls_t = 0;
    opt->ls_err = 0;
    opt->path = (char*)malloc(2*sizeof(char));
    my_strcpy(opt->path,"."); // as default
    
    return opt;
}

void init_t_values(t_modifiedTime*files[],int l)
{
    for(int i = 0;i<l;i++)
    {
        files[i] = (t_modifiedTime*)malloc(sizeof(t_modifiedTime));
        files[i]->timeValue = 0;
    }
}