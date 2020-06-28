
#include <string.h>
#include "source.h"


void make_path(char*path,char*sub_path,char*entry)
{
    my_strcpy(sub_path,path);
    if(sub_path[my_strlen(sub_path) - 1] != '/')
    {
        my_strcat(sub_path,"/");
    }
    my_strcat(sub_path,entry);
    my_strcat(sub_path,"\0");
}

void fill_arr(char *path, char **file_names, int all)
{
    DIR* dir;
    struct dirent* entry;

    int i = 0;

    dir = opendir(path);

    while((entry = readdir(dir)) != NULL)
    {
        if(!all && entry->d_name[0] == '.')
        {
            continue;
        }

        file_names[i] = (char*)malloc(sizeof(char) * (my_strlen(entry->d_name) + 1));
        my_strcpy(file_names[i],entry->d_name);
        i++;
    }

    closedir(dir);
}

void fill_subDirs(char*path,char**file_names,int all)
{
    DIR* dir;
    struct dirent* entry;

    int i = 0;

    dir = opendir(path);

    while((entry = readdir(dir)) != NULL)
    {
        if(!all && entry->d_name[0] == '.')
        {
            continue;
        }

        if(entry->d_type & DT_DIR)
        {
            if(my_strcmp(entry->d_name,".")!=0 || my_strcmp(entry->d_name,"..")!=0 )
            {
                file_names[i] = (char*)malloc(sizeof(char) * (my_strlen(entry->d_name) + 1));
                my_strcpy(file_names[i],entry->d_name);
                i++;
            }
        }
        
    }

    closedir(dir);
}

void set_dirNames(char*path, char*dir_names[], int l,int all)
{
    DIR* dir;
    struct dirent* entry;

    dir = opendir(path);
    int i = 0;

    while((entry = readdir(dir))!=NULL)
    {
        if(entry->d_type & DT_DIR)
        {
            if(!all && entry->d_name[0] == '.')
            {
                continue;
            }
            
            if(my_strcmp(entry->d_name, ".") == 0 || my_strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }

            dir_names[i] = (char*)malloc(sizeof(char) * (my_strlen(entry->d_name) + 2));
            my_strcpy(dir_names[i],entry->d_name);
            i++;
        }
    }


    closedir(dir);
}

void set_flags(t_opt *opt, char *arg)
{
    if(my_strlen(arg) == 2)
    {
        set_flag(opt, arg[1]);
    }
    else
    {
        // skipt the -
        for(int i = 1;i<my_strlen(arg);i++)
        {
            set_flag(opt, arg[i]);
        }
    }
}

void set_flag(t_opt *opt, char arg)
{
    if(is_a(arg))
    {
        opt->ls_a = 1;
    }
    else if(is_R(arg))
    {
        opt->ls_R = 1;
    }
    else if(is_t(arg))
    {
        opt->ls_t = 1;
    }
    else
    {
        opt->ls_err = 1;
        printf("myls:invalid option: -%c\n",arg);
    }
}
void set_path(t_opt* opt,char* arg)
{
    // free default
    free(opt->path);
    // allocate memory
    opt->path =(char*)malloc(sizeof(char) * (my_strlen(arg) + 1));
    // copy str value
    my_strcpy(opt->path,arg);
}
void set_path_values(int ac,char**av,char*arr[])
{
    int index = 0;
  
    for(int i = 1;i<ac;i++)
    {
        if(!is_Command(av[i]))
        {
            arr[index] = (char*)malloc(sizeof(char) * (my_strlen(av[i]) + 2));
            my_strcpy(arr[index], av[i]);
            index++; 
        }
    }
}