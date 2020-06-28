#include "source.h"


void output(char *file_names[], int l)
{
    for(int i = 0;i<l;i++)
    {
        printf("%s  ",file_names[i]);
    }
}

void output_error(char*opt)
{
    printf("myls:can not open '%s' : no such file or direcotry found\n",opt);
}

void search_recursievly_files(t_opt *opt, char *path, int all, int time)
{
        int l = get_numberOfSubDirs(path, all);
        char* subDir_names[l];
        set_dirNames(path, subDir_names, l,all);
        
        sort(subDir_names, path, l, time);
        
        
        for(int i = 0;i<l;i++)
        {
            char*pass_path = (char*)malloc(sizeof(char) * (my_strlen(subDir_names[i]) + my_strlen(path) + 2));
            make_path(path, pass_path, subDir_names[i]);
            printf("\n");
            myls_R(opt, pass_path, all,time);
            free(pass_path);
        }

        free_string(subDir_names,  l);
}


void free_string(char*file_names[],int l)
{
    for(int i = 0;i<l;i++)
    {
        free(file_names[i]);
    }
}

int myls(int err,char*path,int all, int time)
{
    if(err)
    {
        return -1;
    }
    
    if(is_Exist_File(path) == 1 && !is_Exist(path))
    {
        printf("%s\n",path);
        return 0;
    }

    if(is_Exist(path))
    {
        int l = get_NumberOfFiles(path,  all);
        char*file_names[l];
        
        fill_arr(path, file_names, all);
        sort(file_names,path, l, time);
        output(file_names,l);
        if(l>0)
        {
            printf("\n");
        }
        // free the memory
        free_string(file_names,  l);

        return 0;
    }

    else
    {
        output_error(path);
    }

    return -1;
}
void print_pathName(char*path)
{
        printf("%s:\n",path);
}



int myls_R(t_opt*opt,char*path,int all,int time)
{
    if(is_Exist(path))
    {
        print_pathName(path);
        myls(opt->ls_err,path,all,time);
        search_recursievly_files(opt, path,  all, time);
        return 0;
    }

    else
    {
        output_error(path);
        return -1;
    }
}

