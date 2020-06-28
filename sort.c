#include "source.h"

void sort(char*file_names[],char*path,int l,int time)
{
    if(time)
    {
        sort_byTime(path, file_names, l);   
    }
    else
    {
        lexico_sort(file_names,  l);
    }
}

void swap_structures(t_modifiedTime **d1, t_modifiedTime **d2)
{
    t_modifiedTime* tmp = *d1;
    *d1 = *d2;
    *d2 = tmp;
}

void sort_t(t_modifiedTime* m_files[],int l)
{
    for(int i = 0;i<l;i++)
    {
        for(int j = i + 1;j<l;j++)
        {
            if(m_files[i]->timeValue < m_files[j]->timeValue)
            {
                swap_structures(&m_files[i], &m_files[j]);
            }
            else if(m_files[i]->timeValue == m_files[j]->timeValue)
            {
                if(my_strcmp(m_files[i]->name,m_files[j]->name) > 0)
                {
                     swap_structures(&m_files[i], &m_files[j]);
                }
            }
        }
    }
}

void sort_byTime(char *path, char **file_names, int l)
{
    t_modifiedTime* m_files[l];

    init_t_values(m_files,  l);
    get_name_values(m_files,path,file_names,l);
    get_time_values(m_files, l);
    sort_t(m_files,l);

    for(int i = 0;i<l;i++)
    {
        free(file_names[i]);
        file_names[i] = (char*)malloc(sizeof(char) * (my_strlen(m_files[i]->name) + 1));
        my_strcpy(file_names[i],m_files[i]->name);

        free(m_files[i]->name);
        free(m_files[i]->path);
        free(m_files[i]);
    } 
}


void swap_strings(char**a,char**b)
{   
    char*tmp = *a;
    *a = *b;
    *b = tmp;
}

void lexico_sort(char*file_names[],int l)
{
    for(int i = 0;i<l;i++)
    {
        for(int j = i + 1;j<l;j++)
        {
            if(my_strcmp(file_names[i],file_names[j]) > 0)
            {
                swap_strings(&file_names[i], &file_names[j]);
            }
        }
    }
}